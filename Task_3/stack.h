#ifndef STACK_H
#define STACK_H

#include <MyLibVector/include/vector.h>

template <typename T, typename Container = Vector<int>>
class Stack {

   public:
    Stack() : Stack(Container()) {}
    explicit Stack(const Container& cont) : container_(cont) {}
    explicit Stack(Container&& cont) : container_(cont) {}
    Stack(const Stack& other) : container_(other.container_) {}
    Stack(Stack&& other) : container_(std::move(other.container_)) {}
    template <typename InputIt>
    Stack(InputIt first, InputIt last) : container_(first, last) {}

    void push(const T& value) { container_.push_back(value); }

    void pop() {
        if (!container_.empty()) {
            container_.pop_back();
        }
    }


    T& top() { return container_.back(); }
    const T& top() const { return container_.back(); }


    bool empty() const { return container_.empty(); }

    size_t size() const { return container_.size(); }

    void clear() { container_.clear(); }

    void swap(Stack& other) { container_.swap(other.container_); }

   private:
    Container container_;
};

#endif	// STACK_H
