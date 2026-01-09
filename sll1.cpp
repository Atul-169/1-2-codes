#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    
    Node(int a){
        this->value=a;
        this->next=nullptr;
    }
    Node(){

    }
};
Node* insert(int arr[]){
    Node* head=new Node(arr[0]);
    Node* current=head;
    for(int i=1;i<5;i++){
      current->next=new Node(arr[i]);
        current=current->next;
    }
    return head;
}
void print(Node* n){
    Node* temp=n;
    while(temp!=nullptr){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}
int main(){
    int arr[5]={12,343,545,1,123};
    Node *ob;
    ob=insert(arr);
    print(ob);  
}