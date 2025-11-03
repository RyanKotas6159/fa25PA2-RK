//
// Created by Manju Muralidharan on 10/19/25.
//Ryan Kotas
// heap stucture
//
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //insert index at end of heap, restore order using upheap()
    void push(int idx, int weightArr[]) {
        if (size >= 64)
        {
            cout<<"Array full Overflow Warning"<<endl;
            return;
        }
        data[size] = weightArr[idx];
        size++;
        upheap(size, data);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        int retunred = data[0];
        data[0] = data[size-1];
        downheap(0,data);

        size--;
        return retunred; // placeholder
    }

    //swap child upward while smaller than parent
    void upheap(int pos, int weightArr[])
    {
        int parent=pos;
        int child=pos;
        while (parent!=0) {
            parent=(parent-1)/2;
            if (weightArr[parent] > weightArr[child])
            {
                swap(child, parent);
            }
            child=parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif