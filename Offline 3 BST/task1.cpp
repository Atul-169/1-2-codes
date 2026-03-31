#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"

// g++ task1.cpp -o task1
// .\task1 in_task1.txt
using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c;
    string str;
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        if(c=='I'){
            in_file>>val;
            if(bst->insert(val,val)==true){
                cout<<"Key "<<val<<" inserted into BST, ";
                bst->print('D');
                cout<<endl;
            }
            else{
                cout<<"Insertion Failed! Key "<<val<<" already exists in BST, ";
                bst->print('D');
                cout<<endl;

            }
        
        }
        else if(c=='F'){
            in_file>>val;
            if(bst->find(val)==true){
                cout<<"key "<<val<<" found in BST"<<endl;

            }
            else {
                cout<<"key "<<val<<" not found in BST"<<endl;
            }

        }
        else if(c=='E'){
            if(bst->empty()==true){
                cout<<"Empty"<<endl;
            }
            else {
                cout<<"BST is not empty"<<endl;
            }

        }
        else if(c=='S'){
            cout<<"Size: "<<bst->size()<<endl;
        }
        else if(c=='D'){
            in_file>>val;
            if(bst->remove(val)==true){
                cout<<"key "<<val<<" removed from BST, ";
                bst->print('D');
                cout<<endl;
            }
            else{
                cerr<<"Removal failed! Key "<<val<<" not found in BST, ";
                bst->print('D');
                cout<<endl;

            }

        }
        else if(c=='T'){
            in_file>>str;
            if(str=="In"){
                cout<<"BST (In-order): ";
                bst->print('I');
                cout<<endl;
            }
            else if(str=="Pre"){
                cout<<"BST (Pre-order): ";
                bst->print('P');
                cout<<endl;

            }
            else if(str=="Post"){
                cout<<"BST (Post-order): ";
                bst->print('O');
                cout<<endl;
            }
            else if(str=="Lev"){
                cout<<" BST (level order)";
                bst->print('L');
                cout<<endl;
            }
            else {
                cerr<<"error: invalid"<<endl;
            }
             
        }
        else if(c=='M'){
            in_file>>str;
            if(str=="Min"){
                int min=bst->find_min();
                cout<<"Minimum value: "<<min<<endl;
            }
            else if(str=="Max"){
                int max=bst->find_max();
                cout<<"Maximum value: "<<max<<endl;
            }
            else {
                cerr<<"invalid command"<<endl;
            }
        }
        else if(c=='H'){
            int h=bst->getHeight();
            cout<<"Height of BST: "<<h<<endl;
            
        }
        

        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}
