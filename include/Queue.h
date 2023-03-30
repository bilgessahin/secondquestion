#ifndef QUEUE_H
#define QUEUE_H

#include <mutex>

template <typename T>
class Queue {
public:

    Queue() : head(nullptr) {

    }

    Queue(const T& value) : head(new Node{value, nullptr}) {
    }


    void push(const T value){

        std::lock_guard<std::mutex> lock(mutex);
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }
    
    
    T pop(){

        std::lock_guard<std::mutex> lock(mutex);
        if (head == nullptr) {
            throw std::runtime_error("Bos Queue");
        }
        T value = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        return value;
    }


    int size() const {
        std::lock_guard<std::mutex> lock(mutex);
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex);
        return head == nullptr;
    }

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