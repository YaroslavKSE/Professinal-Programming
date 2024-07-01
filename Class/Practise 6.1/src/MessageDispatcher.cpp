#include "MessageDispatcher.hpp"
#include <iostream>
#include <random>
#include <chrono>

MessageDispatcher& MessageDispatcher::getInstance() {
    static MessageDispatcher instance;
    return instance;
}

MessageDispatcher::MessageDispatcher() : running_(false) {}

MessageDispatcher::~MessageDispatcher() {
    stop();
}

void MessageDispatcher::start() {
    running_ = true;
    dispatcherThread_ = std::thread(&MessageDispatcher::dispatcherLoop, this);
}

void MessageDispatcher::stop() {
    {
        std::lock_guard<std::mutex> lock(mtx_);
        running_ = false;
    }
    cv_.notify_all();
    if (dispatcherThread_.joinable()) {
        dispatcherThread_.join();
    }
}

void MessageDispatcher::publish(const GreenMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mtx_);
        messageQueue_.emplace(message);
    }
    cv_.notify_all();
}

void MessageDispatcher::publish(const BlueMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mtx_);
        messageQueue_.emplace(message);
    }
    cv_.notify_all();
}

void MessageDispatcher::publish(const OrangeMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mtx_);
        messageQueue_.emplace(message);
    }
    cv_.notify_all();
}

void MessageDispatcher::subscribe(GreenMessageCallback subscriber) {
    std::lock_guard<std::mutex> lock(mtx_);
    subscribers_[typeid(GreenMessage).hash_code()].emplace_back([subscriber](const Message& message) {
        if (std::holds_alternative<GreenMessage>(message)) {
            subscriber(std::get<GreenMessage>(message));
        }
    });
}

void MessageDispatcher::subscribe(BlueMessageCallback subscriber) {
    std::lock_guard<std::mutex> lock(mtx_);
    subscribers_[typeid(BlueMessage).hash_code()].emplace_back([subscriber](const Message& message) {
        if (std::holds_alternative<BlueMessage>(message)) {
            subscriber(std::get<BlueMessage>(message));
        }
    });
}

void MessageDispatcher::subscribe(OrangeMessageCallback subscriber) {
    std::lock_guard<std::mutex> lock(mtx_);
    subscribers_[typeid(OrangeMessage).hash_code()].emplace_back([subscriber](const Message& message) {
        if (std::holds_alternative<OrangeMessage>(message)) {
            subscriber(std::get<OrangeMessage>(message));
        }
    });
}

void MessageDispatcher::dispatcherLoop() {
    while (running_) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return !messageQueue_.empty() || !running_; });
        while (!messageQueue_.empty()) {
            auto message = std::move(messageQueue_.front());
            messageQueue_.pop();
            lock.unlock();

            std::visit([this](auto&& arg) {
                notifySubscribers(arg);
            }, message);

            lock.lock();
        }
    }
}

template <typename T>
void MessageDispatcher::notifySubscribers(const T& message) {
    auto it = subscribers_.find(typeid(T).hash_code());
    if (it != subscribers_.end()) {
        for (const auto& subscriber : it->second) {
            subscriber(message);
        }
    }
}

