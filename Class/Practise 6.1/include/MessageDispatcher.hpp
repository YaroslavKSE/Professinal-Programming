#pragma once

#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <variant>
#include <thread>
#include <print>

// Define message types
struct GreenMessage {
    std::string text;
    int counter;
};

struct BlueMessage {
    double value1;
    double value2;
};

struct OrangeMessage {
    std::string text1;
    std::string text2;
    int number;
    double value;
};

// Define the message variant type
using Message = std::variant<GreenMessage, BlueMessage, OrangeMessage>;

// Dispatcher class
class MessageDispatcher {
public:
    // Singleton instance
    static MessageDispatcher& getInstance();

    // Publish methods
    void publish(const GreenMessage& message);
    void publish(const BlueMessage& message);
    void publish(const OrangeMessage& message);

    // Subscription methods
    void subscribe(const std::function<void(const GreenMessage&)>& subscriber);
    void subscribe(const std::function<void(const BlueMessage&)>& subscriber);
    void subscribe(const std::function<void(const OrangeMessage&)>& subscriber);

    // Start and stop the dispatcher
    void start();
    void stop();

private:
    MessageDispatcher();
    ~MessageDispatcher();

    // Dispatching logic
    void dispatcherLoop();

    // Helper methods
    template <typename T>
    void notifySubscribers(const T& message);

    std::unordered_map<size_t, std::vector<std::function<void(const Message&)>>> subscribers_;
    std::queue<Message> messageQueue_;
    std::mutex mtx_;
    std::condition_variable cv_;
    bool running_;
    std::thread dispatcherThread_;
};
