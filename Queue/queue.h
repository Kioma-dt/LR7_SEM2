#ifndef QUEUE_H
#define QUEUE_H

#include <MyLibVector/include/vector.h>

template <typename T, typename Container = Vector<int>>
class Queue {
   public:
    Queue() : Queue(Container()) {}
    explicit Queue(const Container& cont) : container_(cont) {}
    explicit Queue(Container&& cont) : container_(cont) {}
    Queue(const Queue& other) : container_(other.container_) {}
    Queue(Queue&& other) : container_(std::move(other.container_)) {}
    template <typename InputIt>
    Queue(InputIt first, InputIt last) : container_(first, last) {}

    T& front() { return container_.front(); }
    const T& front() const { return container_.front(); }

    T& back() { return container_.back(); }
    const T& back() const { return container_.back(); }

    bool empty() const { return container_.empty(); }

    size_t size() const { return container_.size(); }

    void clear() { container_.clear(); }

    void push(const T& value) { container_.push_back(value); }

    void pop() {
        if (!container_.empty()) {
            container_.erase(container_.begin());
        }
    }

    void swap(Queue& other) { container_.swap(other.container_); }

   private:
    Container container_;
};

#endif	// QUEUE_H
