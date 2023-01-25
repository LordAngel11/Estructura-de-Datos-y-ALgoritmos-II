#include <bits/stdc++.h>

template <typename T>
class UpdatableHeap {
public:
    // comparison function to maintain min heap
    struct Compare {
        bool operator()(const T& a, const T& b) const {
            return a > b;
        }
    };

    // vector to store the heap elements
    std::vector<T> heap;
    Compare comp;

    // function to push an element into the heap
    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // function to pop the top element from the heap
    T pop() {
        T top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return top;
    }

    // function to update an element in the heap
    void update(int index, T value) {
        T old_value = heap[index];
        heap[index] = value;
        if (comp(value, old_value))
            siftUp(index);
        else
            siftDown(index);
    }

private:
    // helper function to move an element up the heap
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (comp(heap[index], heap[parent])) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // helper function to move an element down the heap
    void siftDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int size = heap.size();
        int largest = index;
        if (left < size && comp(heap[left], heap[index]))
            largest = left;
        if (right < size && comp(heap[right], heap[largest]))
            largest = right;
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            siftDown(largest);
        }
    }
};