#ifndef HASHTABLEOA_H
#define HASHTABLEOA_H

#include <MyLibVector/include/vector.h>

template <typename T>
size_t hash(const T& key);

size_t hash<int>(const int& key) {
    size_t prime = 2654435761;
    return static_cast<size_t>(key) * prime;
}

template <typename Key, typename Value>
class HashTableOA {
   private:
    const size_t default_capacity_ = 16;
    const int c_1 = 1;
    const int c_2 = 3;
    size_t capacity_;
    size_t size_;
    Vector<Pair<Key, Value>> table_;
    size_t hashKey(const Key& key, int i = 0) const {
        return (hash<Key>(key) + c_1 * i + c_2 * i * i) % capacity_;
    }
    Vector<bool> ocupied_;
    Vector<bool> deleted_;

   public:
    HashTableOA(size_t capacity = default_capacity_)
        : capacity_(capacity),
          size_(0),
          table_(capacity),
          ocupied_(capacity),
          deleted_(capacity) {}

    void insert(Key key, Value value) {
        size_t index = hashKey(key);

        int i = 0;
        while (ocupied_[index] && table_[index].first != key) {
            index = hashKey(key, ++i);

            if (i == capacity_) {
                throw std::runtime_error("Table Overflow");
            }
        }

        table_[index].first = key;
        table_[index].second = value;
        ocupied_[index] = true;
        deleted_[index] = false;
        size_++;
    }

    Value value(Key key) {
        size_t index = hashKey(key);

        for (int i = 1; i < capacity_; i++) {
            if (!ocupied_[index] && !deleted_[index]) {
                return NULL;
            }

            if (!deleted_[index] && table_[index].first == key) {
                return table_[index].second;
            }

            index = hashKey(key, i);
        }

        return NULL;
    }

    void remove(Key key) {
        size_t index = hashKey(key);

        for (int i = 1; i < capacity_; i++) {
            if (!ocupied_[index] && !deleted_[index]) {
                return;
            }

            if (!deleted_[index] && table_[index].first == key) {
                table_[index].first = NULL;
                table_[index].second = NULL;
                ocupied_[index] = false;
                deleted_[index] = true;
                size_--;
            }

            index = hashKey(key, i);
        }
    }

    bool contains(Key key) {
        size_t index = hashKey(key);

        for (int i = 1; i < capacity_; i++) {
            if (!ocupied_[index] && !deleted_[index]) {
                return false;
            }

            if (!deleted_[index] && table_[index].first == key) {
                return true;
            }

            index = hashKey(key, i);
        }

        return false;
    }

    size_t size() const { return size_; }

    size_t capacity() const { return capacity_; }

    bool empty() { return size_ == 0; }
};

#endif	// HASHTABLEOA_H
