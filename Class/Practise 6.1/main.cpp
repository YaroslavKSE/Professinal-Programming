#include "MessageDispatcher.hpp"
#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <print>

void messageGenerator() {
    auto& dispatcher = MessageDispatcher::getInstance();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    while (true) {
        int msgType = dist(gen);
        switch (msgType) {
            case 0: {
                GreenMessage msg{"GreenMessage", dist(gen)};
                dispatcher.publish(msg);
                break;
            }
            case 1: {
                BlueMessage msg{dist(gen) * 1.0, dist(gen) * 2.0};
                dispatcher.publish(msg);
                break;
            }
            case 2: {
                OrangeMessage msg{"Orange1", "Orange2", dist(gen), dist(gen) * 3.0};
                dispatcher.publish(msg);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    auto& dispatcher = MessageDispatcher::getInstance();
    
    dispatcher.subscribe([](const GreenMessage& msg) {
        std::println("Received GreenMessage: text = {}, counter = {}", msg.text, msg.counter);
    });

    dispatcher.subscribe([](const BlueMessage& msg) {
        std::println("Received BlueMessage: value1 = {}, value2 = {}", msg.value1, msg.value2);
    });

    dispatcher.subscribe([](const OrangeMessage& msg) {
        std::println("Received OrangeMessage: text1 = {}, text2 = {}, number = {}, value = {}", msg.text1, msg.text2, msg.number, msg.value);
    });

    dispatcher.start();

    std::thread generator1(messageGenerator);
    std::thread generator2(messageGenerator);

    generator1.join();
    generator2.join();

    dispatcher.stop();

    return 0;
}
