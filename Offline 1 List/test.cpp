#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int element;
    node* next;
    node* prev;
} node;

typedef struct 
{
    // declare head, tail, cur and other variables you need
    node* head;
    node* current;
    node* tail;
    
} linkedList;

void init(linkedList* list)

{
    // implement initialization
    list->head=nullptr;
    list->tail=nullptr;
    list->current=nullptr;

}

void free_list(linkedList* list)
{
    // implement destruction of list
    list->current =list->head;
    while(list->current!=nullptr){
        node* temp=list->current;
        list->current=list->current->next;
        delete temp;
    }
    list->current=nullptr;
    list->head=nullptr;
    list->tail=nullptr;
}

void print(linkedList* list)
{
    // implement list printing
    list->current=list->head;
    while (list->current!=nullptr)
    {
        cout<<list->current->element<<" ";
        list->current=list->current->next;
    }
    cout<<"\n";
    

}

void insert_cur(int item, linkedList* list)
{
    // implement insert function
    if(list->current==nullptr){
        append(item,list);
        return;
    }
    
    node* newNode=new node;
    newNode->element=item;
    
    if(list->current==list->head){
        newNode->prev=nullptr;
        newNode->next=list->head;
        list->head->next=newNode;
        list->head=newNode;
        return;
    }
    newNode->next=list->current;
    newNode->prev=list->current->prev;
    list->current->prev->next = newNode;
    list->current->prev = newNode;

}

int delete_cur(linkedList* list)
{
    // implement deletion of current index function
}

void append(int item, linkedList* list)
{
    // implement append function
    node* newNode= new node;
    newNode->element=item;
    newNode->prev=nullptr;
    newNode->next=nullptr;

    if(list->head==nullptr){
        list->current=newNode;
        list->head=newNode;
        list->tail=newNode;
        return;
    }
    newNode->prev=list->tail;
    list->tail->next=newNode;
    list->tail=newNode;
    
}

int size(linkedList* list)
{
    // implement size function
    int count;
    list->current=list->head;
    while(list->current!=nullptr){
        count++;
        list->current=list->current->next;
    }
}

void prev(int n, linkedList* list)
{
    // implement prev function

}

void next(int n, linkedList* list)
{
    // implement next function
}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
}

void clear(linkedList* list)
{
    // implement list clearing function
}

int delete_item(int item, linkedList* list)
{
    // implement item deletion function
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
}


int search(int item, linkedList* list)
{
    // implement search function
}

int find(int ind, linkedList* list)
{
    // implement find function
}

int update(int ind, int value, linkedList* list)
{
    // implement update function at metioned index position
}

int trim(linkedList* list)
{
    // implement trim function
}

void reverse(linkedList* list)
{
    // implement reverse function

}



// you can define helper functions you need