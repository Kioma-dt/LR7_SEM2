#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <MyLibVector/include/vector.h>
#include "stack.h"

template <typename T>
size_t hash(const T& key);

size_t hash<int>(const int& key) {
    size_t prime = 2654435761;
    return static_cast<size_t>(key) * prime;
}

template <typename Key, typename Value>
class HashTable {
   private:
    const size_t default_capacity_ = 16;
    size_t capacity_;
    size_t size_;
    Vector<Stack<Pair<Key, Value>>> table_;
    size_t hashKey(const Key& key) const { return hash<Key>(key) % capacity_; }

    void reHash(size_t new_capcity) {
        Vector<Stack<Pair<Key, Value>>> new_table(new_capcity);

        for (size_t i = 0; i < table_.size(); i++) {
            while (!table_[i].empty()) {
                auto temp_pair = table_[i].top();
                table_[i].pop();

                size_t new_hash = hashKey(temp_pair.first) % new_capcity;
                new_table[new_hash].push(temp_pair);
            }
        }

        table_ = std::move(new_table);
        capacity_ = new_capcity;
    }

   public:
    HashTable(size_t capacity = default_capacity_)
        : capacity_(capacity), size_(0), table_(capacity_) {}

    void insert(const Key& key, const Value& value) {
        size_t index = hashKey(key);

        bool updated = false;

        Stack<Pair<Key, Value>> temp_stack;

        while (!table_[index].empty()) {
            if (table_[index].top().first == key) {
                table_[index].top().second = value;
                updated = true;
            }
            temp_stack.push(table_[index].top());
            table_[index].pop();
        }

        while (!temp_stack.empty()) {
            table_[index].push(temp_stack.top());
            temp_stack.pop();
        }

        if (!updated) {
            size_++;
            if (size_ > 0.75 * capacity_) {
                reHash(capacity_ * 2);
            }
            table_[index].push(make_pair(key, value));
        }
    }

    Value value(const Key& key) const {
        size_t index = hashKey(key);

        Stack<Pair<Key, Value>> temp_stack = table_[index];

        while (!temp_stack.empty()) {
            if (temp_stack.top().first == key) {
                return temp_stack.top().second;
            }
            temp_stack.pop();
        }

        return NULL;
    }

    void remove(const Key& key) {
        size_t index = hashKey(key);

        Stack<Pair<Key, Value>> temp_stack;

        while (!table_[index].empty()) {
            if (table_[index].top().first != key) {
                temp_stack.push(table_[index].top());
            }
            table_[index].pop();
        }

        while (!temp_stack.empty()) {
            table_[index].push(temp_stack.top());
            temp_stack.pop();
        }
    }

    bool contains(const Key& key) const {
        size_t index = hashKey(key);

        Stack<Pair<Key, Value>> temp_stack = table_[index];

        while (!temp_stack.empty()) {
            if (temp_stack.top().first == key) {
                return true;
            }
            temp_stack.pop();
        }

        return false;
    }

    size_t size() const { return size_; }

    size_t capacity() const { return capacity_; }

    bool empty() { return size_ == 0; }
}

#endif	// HASHTABLE_H
