#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int element;
    node* next;
    node* prev;
};

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
    node* temp=list->head;
    while (temp!=nullptr)
    {
        cout<<temp->element<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    

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
        list->head->prev=newNode;
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



int size(linkedList* list)
{
    // implement size function
    int count=0;
    node* temp=list->head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

void prev(int n, linkedList* list)
{
    // implement prev function
    if(list->current==nullptr) return;
    for(int i=0;i<n;i++){
        if(list->current->prev==nullptr) break;
    
         list->current=list->current->prev;

    }

}

void next(int n, linkedList* list)
{
    // implement next function
    if(list->current==nullptr) return;
    for(int i=0;i<n;i++){
        if(list->current->next==nullptr) break;
        list->current=list->current->next;
    }
}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
    node* temp=list->head;
    while(temp!=nullptr){
        if(temp->element==n) return 1;
        temp=temp->next;
    }
    return 0;
}

void clear(linkedList* list)
{
    // implement list clearing function
    list->current=nullptr;
    list->head=nullptr;
    list->tail=nullptr;
    free_list(list);
}

int delete_item(int item, linkedList* list)
{
    // implement item deletion function
    node* temp=list->head;
    while(temp!=nullptr){
        if(item==temp->element) {
            list->current=temp;
            delete_cur(list);
        }
        temp=temp->next;
    }
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
    if(ind1==ind2) return;
    node* n1=getNodeAt(ind1,list);
    node* n2=getNodeAt(ind2,list);
    if(n1==nullptr || n2==nullptr) return;

    node* n1_prev = n1->prev;
    node* n1_next = n1->next;
    node* n2_prev = n2->prev;
    node* n2_next = n2->next;

    if(n1_prev) n1_prev->next = n2;
    if(n1_next) n1_next->prev = n2;
    if(n2_prev) n2_prev->next = n1;
    if(n2_next) n2_next->prev = n1;

     n1->prev = n2_prev;
    n1->next = n2_next;
    n2->prev = n1_prev;
    n2->next = n1_next;

    if(list->head == n1) list->head = n2;
    else if(list->head == n2) list->head = n1;
    if(list->tail == n1) list->tail = n2;
    else if(list->tail == n2) list->tail = n1;


}


int search(int item, linkedList* list)
{
    // implement search function
    int idx=0;
    node* temp;
    temp=list->head;
    while(temp!=nullptr){
        if(item==temp->element) return idx;
        idx++;
        temp=temp->next;
    }
    return -1;

}

int find(int ind, linkedList* list)
{
    // implement find function
    int idx=0;
    node* temp=list->head;
    while (temp!=nullptr)
    {
        if(idx==ind) return temp->element;
        idx++;
        temp=temp->next;
    }
    return -1;
    
}

int update(int ind, int value, linkedList* list)
{
    // implement update function at metioned index position
    int idx=0,found=0;
    node* temp=list->head;
    while(temp!=nullptr){
        if(idx==ind) {
            found=temp->element;
            temp->element=value;
            break;
        }
        idx++;
        temp=temp->next;
    }
    return found;
}

int trim(linkedList* list)
{
    // implement trim function
    if(list->head==nullptr) return 0;

    int elem=list->tail->element;
    node* temp=list->tail;
    
    if(list->head==list->tail){
        
        list->tail=nullptr;
        list->head=nullptr;
        list->current=nullptr;
        
    }
    else{
        list->tail=list->tail->prev;
        list->tail->next=nullptr;
        if(list->current==temp){
            list->current=list->tail;
        }
    }
    delete temp;
    return elem;
}

void reverse(linkedList* list)
{
    // implement reverse function
    if(list->head==nullptr) return;
    node* temp=list->head;
    node* swap=nullptr;
    while(temp!=nullptr){
        swap=temp->prev;
        temp->prev=temp->next;
        temp->next=swap;


        temp=temp->next;
    }
    swap=list->head;
    list->head=list->tail;
    list->tail=swap;

}
node* getNodeAt(int index,linkedList* list){
    node* temp=list->head;
    int idx=0;
    while(temp!=nullptr){
        if(idx==index) return temp;
        idx++;
        temp=temp->next;
    }
    return nullptr;
}



// you can define helper functions you need
