#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;

// g++ task2.cpp -o task2
// .\task2 in_task2.txt


int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each id
    // You need to track: total bids, successful bids, rejected bids for each id
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    BST<string,int>* total =new ListBST<string,int>();
    BST<string,int>* successful=new ListBST<string,int>();
    BST<string,int>* rejected=new ListBST<string,int>();
    BST<string,int>* price=new ListBST<string,int>();
    
    int totalBids,totalSucc,totalReject;
    totalBids=totalReject=totalSucc=0;
    string ids[25];
    int id_cnt=0;
    



    // End your code here

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i) {
        // TODO: Implement the logic to read initial ids and their starting bids
        // Initialize statistics tracking for each id
        // Start your code here
        string id;
        int val;
        in_file>>id>>val;
        price->insert(id,val);
        total->insert(id,0);
        successful->insert(id,0);
        rejected->insert(id,0);
        ids[id_cnt++]=id;

        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout<<"Initial Auction Items:\nBST (In-order): ";
    price->print('I');
    

    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation) {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified id
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        if(operation=="BID"){
            string id;
            int bid;
            in_file>>id>>bid;
            
            if(!price->find(id)){
                cout<<"Item "<<id<<" doesnt exist\n";

            }
            else {
                totalBids++;
                total->update(id,total->get(id)+1);
                int curr=price->get(id);
                if(bid>curr){
                    price->update(id,bid);
                    successful->update(id,successful->get(id)+1);
                    totalSucc++;
                    cout<<"Bid of "<<bid<<" on "<<id<<" accepted.Current bid: "<<price->get(id)<<endl;
                }
                else {
                    rejected->update(id,rejected->get(id)+1);
                    totalReject++;
                    cout<<"Bid of "<<bid<<" on "<<id<<" rejected.Current bid: "<<price->get(id)<<endl;
                }
            }
            cout<<"BST (In-order): ";
            price->print('I');
            cout<<endl;


            }

            else if(operation=="CHECK"){
                string id;
                in_file>>id;
                if(price->find(id))
                cout<<"Current bid for "<<id<<": "<<price->get(id)<<endl;
                else cout<<"Item doesnt exist";

                cout<<"BST (In-order): ";
                price->print('I');
                cout<<endl;


            }
            else if(operation=="ADD"){
                string id;
                int bid;
                in_file>>id>>bid;
                if(price->find(id)){
                    if(bid>price->get(id)){
                        price->update(id,bid);
                        cout<<"item "<<id<<" updated with new bid"<<bid<<endl;
                        
                    }
                    else{
                        cout<<"item "<<id<<" already exists with higher bid "<<endl;
                    }
                    

                }
                else{
                    price->insert(id,bid);
                    total->insert(id,0);
                    successful->insert(id,0);
                    rejected->insert(id,0);
                    ids[id_cnt++]=id;
                    cout<<"Item "<<id<<" added with starting bid "<<bid<<endl;
                }
                cout<<"BST (In-order): ";
                price->print('I');
                cout<<endl;


            }
            else if(operation=="STATS"){
                string id;
                in_file>>id;
                if(!price->find(id)){
                cout<<"Item "<<id<<" doesnt exist\n";

            }
            else{
                 cout<<"Statistics for "<<id<<":\n";
            cout<<" Current highest bid: "<<price->get(id)<<endl;
            cout<<" Total bids placed: "<<total->get(id)<<endl;
            cout<<" Successful bids: "<<successful->get(id)<<endl;
            cout<<" Rejected bids: "<<rejected->get(id)<<endl;
            }
        }
            else if (operation == "REPORT") {
            cout<<"Auction Report:\n";
            cout<<"Total items: "<<price->size()<<endl;
            cout<<"Total bids placed: "<<totalBids<<endl;
            cout<<"Total Successful bids: "<<totalSucc<<endl;
            cout<<"Total Rejected bids: "<<totalReject<<endl;

            
            for(int i=0;i<id_cnt-1;i++){
                for(int j=0;j<id_cnt-1-i;j++){
                    if(ids[j] > ids[j+1]){   
                        string temp=ids[j];
                        ids[j]=ids[j+1];
                        ids[j+1]=temp;
                    }
                }
            }

        
            cout<<"Item statistics: \n";
            for(int i=0;i<id_cnt;i++){
                string id=ids[i];
                cout<<id<<": Current Bid: "<<price->get(id);
                cout<<", Total bids: "<<total->get(id);
                cout<<", Successful: "<<successful->get(id);
                cout<<", Rejected: "<<rejected->get(id)<<endl;
                

            }
            }
            cout<<"==============================\n";
        }
    
        // End your code here
        // cout << "==============================\n";
    

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete price;
    delete total;
    delete successful;
    delete rejected;
    

    // End your code here
    return 0;
}
