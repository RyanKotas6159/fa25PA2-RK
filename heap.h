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
        upheap(idx, weightArr);
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
        int child=size-1;
        int parent=size-1;
        while (parent!=0) {
            parent=(child-1)/2;
            if (weightArr[data[child]] < weightArr[data[parent]])
            {
                swap(data[child], data[parent]);
            }
            child=parent;
        }
    }
    // swap parent downward while larger than any child
    void downheap(int pos, int weightArr[]) {

        int child=pos*2+1;
        int child2=pos*2+2;
        if (size<=0||pos>size||pos<0)
        {
            cout<<"Heap Error at DownHeap";
            return;
        }
        if (child>size||child2>size)
        {
            return;
        }
        while (child<size-1)
        {
            if (weightArr[data[pos]] > weightArr[data[child]] || weightArr[data[pos]] > weightArr[data[child2]])
            {
                if (weightArr[data[child]] > weightArr[data[child2]])
                {
                    swap(data[pos], data[child2]);
                    pos=child;
                }else
                {
                    swap(data[pos], data[child]);
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