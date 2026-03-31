#ifndef MINHEAP_H
#define MINHEAP_H
using namespace std;
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <climits>

#define MAX_CAPACITY 1000  // Defines the maximum capacity of the heap

class MinHeap
{
private:
    int heap[MAX_CAPACITY];  // Array to store heap elements
    int size;                // Current number of elements in the heap

    /**
     * Sifts up the node at index i to maintain heap property.
     */
    void siftUp(int i)
    {
        int parent = (i-1)/2;
        while(i>0 && heap[parent]>heap[i]){
            swap(i,parent);
            i=parent;
            parent=(i-1)/2;
        }
    }

    /**
     * Sifts down the node at index i to maintain heap property.
     */
    void siftDown(int i)
    {
        int left=2*i+1;
        int right=2*i+2;
        int smallest=i;
        while(left<size){
            if(heap[left]<heap[smallest]){
                smallest=left;
            }
            if(right<size && heap[right]<heap[smallest]){
                smallest=right;
            }
            if(smallest==i){
                break;
            }
            swap(i,smallest);
            i=smallest;
            left=2*i+1;
            right=2*i+2;
        }
    
    }

public:
    // Constructor initializes an empty heap
    MinHeap() : size(0) {}

    /**
     * Inserts a new element x into the heap.
     */
    void insert(int x)
    {
        /**Write your code here**/
        if(size == MAX_CAPACITY){
            throw runtime_error("Overflow: could not insertKey\n");

        }
        size++;
        int i=size-1;
        heap[i]=x;

        siftUp(i);
    }

    /**
     * Returns the minimum element without removing it.
     */
    int findMin()
    {
        if(size==0){
            throw runtime_error("Empty Heap");
        }
        int ans=heap[0];
        return ans;
    }

    /**
     * Removes and returns the minimum element from the heap.
     */
    int extractMin()
    {
        if(size==0){
            throw runtime_error("Empty Heap");
        }
        int ans=heap[0];
        heap[0]=heap[size-1];
        size--;
        siftDown(0);
        return ans;

       
    }

    /**
     * Returns the number of elements in the heap.
     */
    int getSize()
    {
        return size;
    }

    /**
     * Checks if the heap is empty.
     * Returns true if empty, false otherwise.
     */
    bool isEmpty()
    {
        return size==0;
    }

    /**
     * Decreases the value of the element at index i to newValue.
     */
    void decreaseKey(int i, int newValue)
    {
        if(i<0 || i>=size) {
            throw runtime_error("invalid index");
        }
        heap[i]=newValue;
        siftUp(i);
    }

    /**
     * Deletes the element at index i.
     */
    void deleteKey(int i)
    {
        if(i<0 || i>=size) {
            throw runtime_error("invalid index");
        }
        heap[i]=INT_MIN;
        siftUp(i);
        extractMin();
    }

    /**
     * Prints the heap's content to the output file.
     * Format: "elem1 elem2 elem3 ..." (space-separated)
     */
    void printHeap(std::ofstream &outfile)
    {   
        int i;
        for(i=0;i<size-1;i++){
            outfile<<heap[i]<<" ";
        }
        outfile<<heap[i];
        outfile<<endl; 
        
    }

    /**
     * Checks whether the Min Heap property is preserved.
     * Returns true if valid, false otherwise.
     */
    bool isValidMinHeap()
    {
        for(int i=0;i<size/2;i++){
            int left=2*i+1;
            int right=2*i+2;
            if(left<size && heap[i]>heap[left]) return false;
            if(right<size && heap[i]>heap[right]) return false;

        }
        return true;
    }

    /**
     * Builds a heap from an unsorted array using bottom-up heapify.
     */
    void heapify(int arr[], int n)
    {
        size=n;
        for(int i=0;i<n;i++){
            heap[i]=arr[i];
        }
        for(int i=n/2-1;i>=0;i--){
            siftDown(i);
        }
   

    }

    /**
     * Returns all elements in sorted (ascending) order.
     * The original heap should remain UNCHANGED after this operation.
     */
    void heapSort(std::ofstream &outfile)

    {
        int *temp=new int[size];
        int n=size;
        for(int i=0;i<size;i++){
            temp[i]=heap[i];
        }
        while(!isEmpty()){
            outfile<<extractMin();
            if(!isEmpty()) outfile<<" ";
        }
        outfile<<endl;
        size=n;
        for(int i=0;i<size;i++){
            heap[i]=temp[i];
        }
            delete[] temp;
        
    }

    /**
     * Replaces the minimum element with a new value x in a single operation.
     * Returns the old minimum value.
     */
    int replaceMin(int x)
    {
        if(size==0){
            throw runtime_error("empty heap");
        }
        int ans=heap[0];
        heap[0]=x;
        siftDown(0);
        return ans;
        
    } 
    void swap(int i, int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}

    
};

#endif // MINHEAP_H
