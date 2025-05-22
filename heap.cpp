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
vdata.push_back(value);
    int i = vdata.size() - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (vdata[i] < vdata[parent]) {
            swap(vdata[i], vdata[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
   if (vdata.empty()) {
        throw std::out_of_range("Heap is empty");
    }

    vdata[0] = vdata.back();
    vdata.pop_back();

    int i = 0;
    int size = vdata.size();

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && vdata[left] < vdata[smallest]) {
            smallest = left;
        }
        if (right < size && vdata[right] < vdata[smallest]) {
            smallest = right;
        }
        if (smallest == i) break;

        swap(vdata[i], vdata[smallest]);
        i = smallest;
    }
}


// Returns the minimum element in the heap
int Heap::top(){
    if (vdata.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    