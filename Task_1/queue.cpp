// #include "queue.h"

// template <typename T, typename Container>
// Queue<T, Container>::Queue() : Queue(Container()) {}

// template <typename T, typename Container>
// Queue<T, Container>::Queue(const Container& cont) : container_(cont) {}

// template <typename T, typename Container>
// Queue<T, Container>::Queue(Container&& cont) : container_(cont) {}

// template <typename T, typename Container>
// Queue<T, Container>::Queue(const Queue& other) : container_(other.container_) {}

// template <typename T, typename Container>
// Queue<T, Container>::Queue(Queue&& other)
//     : container_(std::move(other.container_)) {}

// template <typename T, typename Container>
// T& Queue<T, Container>::front() {
//     return container_.front();
// }

// template <typename T, typename Container>
// const T& Queue<T, Container>::front() const {
//     return container_.front();
// }

// template <typename T, typename Container>
// T& Queue<T, Container>::back() {
//     return container_.back();
// }

// template <typename T, typename Container>
// const T& Queue<T, Container>::back() const {
//     return container_.back();
// }

// template <typename T, typename Container>
// bool Queue<T, Container>::empty() const {
//     return container_.empty();
// }

// template <typename T, typename Container>
// size_t Queue<T, Container>::size() const {
//     return container_.size();
// }

// template <typename T, typename Container>
// void Queue<T, Container>::push(const T* value) {
//     container_.push_back(value);
// }

// template <typename T, typename Container>
// void Queue<T, Container>::pop() {
//     if (!container_.empty()) {
//         container_.erase(container_.begin());
//     }
// }

// template <typename T, typename Container>
// void Queue<T, Container>::swap(Queue& other) {
//     container_.swap(other.container_);
// }

// template <typename T, typename Container>
// template <typename InputIt>
// Queue<T, Container>::Queue(InputIt first, InputIt last)
//     : container_(first, last) {}
