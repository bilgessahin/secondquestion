#include <mutex>
#include "Queue.h"


template <typename T>
SafeQueue::SafeQueue() : head{nullptr} {

}

template <typename T>
void SafeQueue::push(const T& value){

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

template <typename T>
T SafeQueue::pop(){

    std::lock_guard<std::mutex> lock(mutex);
    if (head == nullptr) {
        throw std::runtime_error("Bos Queue");
    }
    T value = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

template <typename T>
template <typename T>
int SafeQueue<T>::size() const {
    std::lock_guard<std::mutex> lock(mutex);
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
bool SafeQueue<T>::empty() const {
    std::lock_guard<std::mutex> lock(mutex);
    return head == nullptr;
}


