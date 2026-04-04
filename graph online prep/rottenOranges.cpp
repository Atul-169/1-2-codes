#include <bits/stdc++.h>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &mat,int i,int j,int time)
{   int n=mat.size();
    int m=mat[0].size();
    mat[i][j]=time;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    for(auto d: dir){
        int x=i+d[0];
        int y= j+d[1];

        if(i >= 0 && i < n && j >= 0 && j < m && 
            (mat[x][y]==1 || mat[x][y]>time+1) ){
                dfs(mat,x,y,time+1);
            }
    }
}
int orangesRot(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int timeCnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==2){
                dfs(mat,i,j,2);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                return -1;
            }
            timeCnt=max(timeCnt,mat[i][j]-2);
            
        }
    }
}
