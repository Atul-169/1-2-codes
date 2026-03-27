#include<bits/stdc++.h>
using namespace std;

int main(){
    int I,D,R; //cost for insertion,deletion,replace
    cin>>I>>D>>R;
    string S,T;
    cin>>S;
    cin>>T; 
    int n=S.size();
    int m=T.size();
    int dp[n][m];
    
    
    for(int i=0;i<n;i++){
        dp[i][0]=i*D;     //target empty. delete all of source
    }
    for(int j=0;j<m;j++){
        dp[0][j]=j*I;     //source empty. insert all of target
    }


    for(int i=1;i<n;i++){

        for(int j=1;j<m;j++){
            
            if(S[i-1]==T[j-1]){

                dp[i][j]=dp[i-1][j-1];

            }
            else {

                dp[i][j]=min({dp[i][j-1]+I,dp[i-1][j]+D,dp[i-1][j-1]+R});

            }
        }
    }
    cout<<"Minimum Cost: "<<dp[n-1][m-1]<<endl;
    cout<<"Operations: "<<endl;
    

    vector<string> operations;
    int i=n,j=m;
    while(i>0 || j>0){
        if(i>0 && j>0 && S[i-1]==T[j-1] && dp[i][j]==dp[i-1][j-1]){
            operations.push_back("Match "+string(1,S[i-1]));
            i--;
            j--;
        }
        else if(i>0 && j>0 && dp[i][j]==(dp[i-1][j-1]+R)){
            operations.push_back("Replace "+string(1,S[i-1])+" with "+string(1,T[j-1]));
            i--;
            j--;
        }
        else if(j>0 && dp[i][j]==dp[i][j-1]+I){
            operations.push_back("Insert "+string(1,T[j-1]));
            j--;
        }
        else if(i>0 && dp[i][j]==dp[i-1][j]+D){
            operations.push_back("Delete "+string(1,S[i-1]));
            i--;
        }
    }
    reverse(operations.begin(),operations.end());
    for(const string& op: operations){
        cout<<op<<endl;
    }
    return 0;

    




}

