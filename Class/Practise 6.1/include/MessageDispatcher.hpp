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

using Message = std::variant<GreenMessage, BlueMessage, OrangeMessage>;

using GreenMessageCallback = std::function<void(const GreenMessage&)>;
using BlueMessageCallback = std::function<void(const BlueMessage&)>;
using OrangeMessageCallback = std::function<void(const OrangeMessage&)>;

class MessageDispatcher {
public:
    // Singleton instance
    static MessageDispatcher& getInstance();

    // Publish methods
    void publish(const GreenMessage& message);
    void publish(const BlueMessage& message);
    void publish(const OrangeMessage& message);

    // Subscription methods
    void subscribe(GreenMessageCallback subscriber);
    void subscribe(BlueMessageCallback subscriber);
    void subscribe(OrangeMessageCallback subscriber);

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
