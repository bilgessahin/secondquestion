#ifndef QUEUE_H
#define QUEUE_H

#include <mutex>

template <typename T>
class SafeQueue {
public:
    SafeQueue();

    void push(const T& val);
    T pop();
    int size() const;
    bool empty() const;

private:
struct Node {
    T val;
    Node* next;
    Node(const T& val) : val{val}, next{nullptr} {}
};

Node* head;
std::mutex mutex;
};

#endif //QUEUE_H