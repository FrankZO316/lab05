// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using std::cout;
using std::swap;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
data.push_back(value);
    int index = data.size() - 1;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (data[index] < data[parent]) {
            swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
if (data.empty()) return;

    data[0] = data.back(); 
    data.pop_back();

    int index = 0;
    int size = data.size();

    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && data[left] < data[smallest]) {
            smallest = left;
        }
        if (right < size && data[right] < data[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(data[index], data[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}


// Returns the minimum element in the heap
int Heap::top(){
  if (data.empty()) {
        throw std::out_of_range("Heap is empty.");
    }
    return data[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return data.empty();
}
    