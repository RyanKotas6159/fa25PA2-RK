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
        upheap(size-1, data);
    }

    // remove and return smallest index
    // Replace root with last element, then call downheap()
    int pop(int weightArr[]) {

        int retunred = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0,data);

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
    // swap parent downward while larger than any child
    void downheap(int pos, int weightArr[]) {

        int child=pos*2+1;
        int child2=pos*2+2;
        if (size<=0||pos>size||pos<0||child>size||child2>size)
        {
            cout<<"Heap Error at DownHeap";
            return;
        }
        while (child<size-1 )
        {
            if (weightArr[pos] > weightArr[child] || weightArr[pos] > weightArr[child2])
            {
                if (weightArr[child] > weightArr[child2])
                {
                    swap(pos, child2);
                    pos=child;
                }else
                {
                    swap(pos, child);
                    pos=child;
                }
            }else
            {
                return;
            }
            child=pos*2+1;
            child2=pos*2+2;
        }
    }
};

#endif