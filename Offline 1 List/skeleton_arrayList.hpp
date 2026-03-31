#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
    int *array;
    int capacity;
    int size;
    int cur_index;
    // declare variables you need
} arrayList;

void init(arrayList* list)
{
    // implement initialization
    list->capacity=2;
    list->size=0;
    list->cur_index=0;
    list->array=(int*)malloc(list->capacity*sizeof(int));
}

void free_list(arrayList* list)
{
    // implement destruction of list
    free(list->array);
}

void increase_capacity(arrayList* list)
{
    // implement capacity increase 
    cout<<"capacity increased from "<<list->capacity<<" to "<<list->capacity*2<<endl;
    list->capacity *= 2;
    list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    
}

void decrease_capacity(arrayList* list)
{
    // implement capacity decrease
    if(list->capacity<=2) return;
    if(list->capacity<=list->size*4) return;
    int old=list->capacity;
    list->capacity=list->capacity/2;
    if(list->capacity<2) list->capacity=2;
    
   
    list->array=(int*)realloc(list->array, list->capacity*sizeof(int));
    printf("capacity decreased from %d to %d\n",old,list->capacity);
}

void print(arrayList* list)
{
    // implement list printing
   
    if(list->size==0){
        printf("[.]\n");
        return;
    }
    cout<<"[";
    for(int i=0;i<list->size;i++){
        if(i==list->cur_index-1){
            printf("%d| ", list->array[i]);
        }
        else{
            printf("%d ", list->array[i]);
        }
    }
    cout<<"]\n";
    
    
}
void insert_cur(int item, arrayList* list)
{
  //  implement insert function
    if(list->size >= list->capacity / 2){
        increase_capacity(list);
    }

    if(list->size==0 || list->cur_index==-1){
        list->array[0]=item;
        list->cur_index=0;
    }
    else{
        int fg=list->cur_index;
        if(fg>list->size) fg=list->size;
        for(int i=list->size;i>fg;i--){
            list->array[i]=list->array[i-1];
        }
        list->array[fg]=item;
        list->cur_index=fg;
    }
    list->size++;
    list->cur_index++;
    
    


    

}

int delete_cur(arrayList* list)
{
    // implement deletion of element at current index position
    if(list->size==0){
        return -1; // List is empty
    }
    int deleted=list->array[list->cur_index-1];
    for(int i=list->cur_index-1;i<list->size-1;i++){
        list->array[i]=list->array[i+1];
    }
    list->size--;
    if(list->size==0){
        list->cur_index=0;
    }
    else if(list->cur_index>=list->size){
        list->cur_index=list->size;
    }
    if(list->size < list->capacity / 4 && list->capacity > 2){
        decrease_capacity(list);
    }
    return deleted;
}

void append(int item, arrayList* list)
{
    // implement append function
    if(list->size >= list->capacity / 2){
        increase_capacity(list);
    }
    list->array[list->size]=item;
    list->size++;
    if(list->size==1) list->cur_index=1;
    
}

int size(arrayList* list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList* list)
{
    // implement prev function
    
    list->cur_index-=n;
    
    if(list->cur_index<=0){
        list->cur_index=0;
    }

}

void next(int n, arrayList* list)
{
    // implement next function
    if(list->cur_index + n >= list->size){
        list->cur_index=list->size;
    }
    else{
        list->cur_index+=n;
    }
}


int is_present(int n, arrayList* list)
{
    // implement presence checking function
    if(list->size==0) return 0;
    
    for(int i=0;i<list->size;i++){
        if(list->array[i]==n) return 1;
    }
    return 0;
}

void clear(arrayList* list)
{
    // implement list clearing function
    free(list->array);
    init(list);

}

int delete_item(int item, arrayList* list)
{
    // implement item deletion function
    int found=-1;
    if(item==list->array[list->cur_index-1]) {
        delete_cur(list);
        return 1;
    }
    for(int i=0;i<list->size;i++){
        if(list->array[i]==item) found=i;

    }
    if(found==-1) return -1; //item not found
    for(int i=found;i<list->size-1;i++){
        list->array[i]=list->array[i+1];

    }
    list->size--;
    if(list->size==0){
        list->cur_index=-1;
    }
    else if(found < list->cur_index){
        list->cur_index=found+1;
    }
    return 1;
}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    // implement swap function at metioned index position
    if(ind1<0 || ind1>=list->size || ind2<0 || ind2>=list->size) return;
    int temp=list->array[ind1];
    list->array[ind1]=list->array[ind2];
    list->array[ind2]=temp;

}

int search(int item, arrayList* list)
{
    // implement search function
    if(list->size==0) return -1;
    for(int i=0;i<list->size;i++){
        if(list->array[i]==item) {
            list->cur_index=i+1;
            return i;
        }
    }
    return -1;
}

int find(int ind, arrayList* list)
{
    // implement find function
    if(ind<0 || ind>=list->size) return -1;
    list->cur_index=ind+1;
    return list->array[ind];
}

int update(int ind, int value, arrayList* list)
{
    // implement update function at metioned index position
    if(ind<0 || ind>=list->size) return -1;
    list->cur_index=ind;
    int old=list->array[ind];
    list->array[ind]=value;
    return old;
    

}

int trim(arrayList* list)
{
    // implement trim function
    if(list->size==0) {
        list->cur_index=0;
        return -1;
    }
    
    int old=list->array[list->size-1];
    list->size--;

    if(list->cur_index >= list->size){
        if(list->size==0)
         {  
               list->cur_index=0;
         }
        else{
            list->cur_index=list->size ;
        }
    }

    if (list->size < list->capacity / 4 && list->capacity > 2){
        decrease_capacity(list);
    }
    return old;
}

void reverse(arrayList* list)
{
    // implement reverse function
    int oldidx=list->cur_index;
    int left=0;
    int right=list->size-1;
    while(left<right){
        int temp=list->array[left];
        list->array[left]=list->array[right];
        list->array[right]=temp;
        left++;
        right--;
    }
    list->cur_index=oldidx;

}

// you can define helper functions you need