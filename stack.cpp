#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int a){
        value=a;
        next=nullptr;
    }
};
class Stack{
    private:
    Node* top;
    int count;
    public:
    Stack(){
        top=nullptr;
        count=0;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
    bool isEmpty(){
        return top==nullptr;
    }
    void push(int val){
        Node* newNode= new Node(val);
        newNode->next=top;
        top=newNode;
        count++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"error"<<endl;
            return -1;
        }
        Node* temp=top;
        int val=top->value;
        top=top->next;
        delete temp;
        count--;
        return val;
    }
    int peek(){
        if(isEmpty()){
            cout<<"empty stack"<<endl;
            return -1;
        }
        return top->value;
    }
    int size(){
        return count;
    }
    void print(){
        if(isEmpty()){
            cout<<"empty stack"<<endl;
            return ;
        }
        Node* temp=top;
        while(temp!=nullptr){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }

};


int main(){
 Stack stck;
 stck.push(10);
 stck.push(15);
 stck.push(18);

 
 stck.push(20);
 stck.push(25);
 stck.print();
 cout<<"size "<<stck.size()<<endl;
 cout<<"top "<<stck.peek()<<endl;
 stck.pop();
 stck.print();
 return 0;
}