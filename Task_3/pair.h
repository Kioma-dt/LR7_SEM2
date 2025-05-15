#ifndef PAIR_H
#define PAIR_H
#include <utility>

template <typename T1, typename T2>
class Pair {
   public:
    T1 first;
    T2 second;

    Pair() = default;
    Pair(T1 fir, T2 sec) : first(fir), second(sec) {}
    Pair(const Pair<T1, T2>& other)
        : first(other.first), second(other.second) {}
    Pair(Pair<T1, T2>&& other) noexcept
        : first(std::move(other.first)), second(std::move(other.second)) {}

    template <typename U1, typename U2>
    Pair(const Pair<U1, U2>& other)
        : first(other.first), second(other.second) {}
    template <typename U1, typename U2>
    Pair(Pair<U1, U2>&& other)
        : first(std::move(other.first)), second(std::move(other.second)) {}
    template <typename U1, typename U2>
    Pair(U1&& fir, U2&& sec)
        : first(std::forward<U1>(fir)), second(std::forward<U2>(sec)) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }

        return *this;
    }
    Pair& operator=(Pair&& other) {
        if (this != &other) {
            first = std::move(other.first);
            second = std::move(other.second);
        }

        return *this;
    }
};
#endif
