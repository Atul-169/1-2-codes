#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    
    // TODO: Allocate memory for the array with the specified initial capacity
    if(initial_capacity<2) initial_capacity=2;
    capacity=initial_capacity;
    data=new int[initial_capacity];
    front_idx=0;
    rear_idx=0;

}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete []data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    if((size()+1)==capacity){
        resize(2*capacity);
    }
    data[rear_idx]=item;
    rear_idx=(rear_idx+1)%capacity; //circular indexing



}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    if(empty()){
        cout<<"queue is empty\n";
        return -1;
    }
    int val=data[front_idx];
    front_idx=(front_idx+1)%capacity;
    
    int current_size=(rear_idx-front_idx+capacity)%capacity;
    
    if(current_size*4<=(capacity-1) && capacity>2){
        resize(capacity/2);
    }
    return val;

}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    capacity=2;
    front_idx=0;
    rear_idx=0;
    delete[] data;
    data=new int[capacity];

}


// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    int size=(rear_idx-front_idx+capacity)%capacity;

    return size;
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if(empty()){
        cout<<"queue is empty\n";
        return -1;
    }
    int val=data[front_idx];
    return val;
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if(empty()){
        cout<<"queue is empty\n";
        return -1;
    }
    int val=data[(rear_idx-1+capacity)%capacity];
    return val;
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return front_idx==rear_idx;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    
    string converted="<";
    for(int i=0;i<size();i++){
        converted=converted+to_string(data[(front_idx+i)%capacity])+", ";
        
    }
    converted=converted+">";
    return converted;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    int old_size=size();
    if(new_capacity<2) new_capacity=2;
    int* temp=new int[new_capacity];

    for(int i=0;i<size();i++){
        temp[i]=data[(front_idx+i)%capacity];
    }
    delete []data;
    data=temp;
    capacity=new_capacity;
    front_idx=0;
    rear_idx=old_size;
    
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return this->capacity;
}