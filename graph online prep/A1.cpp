#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<vector<int>> adj(26);
//     int parentCount[26] = {0};
//     int childCount[26] = {0};

//     for(int i = 0; i < N; i++) {
//         char a,b,ch;
//         cin >> ch >> a >> ch >> b >> ch; // [A,B]

//         int p = a - 'A';
//         int c = b - 'A';

//         adj[p].push_back(c);
//         parentCount[c]++;
//         childCount[p]++;
//     }

//     int root;
//     for(int i = 0; i < 26; i++) {
//         if(childCount[i] > 0 && parentCount[i] == 0) {
//             root = i;
//             break;
//         }
//     }

//     queue<int> q;
//     int gen[26] = {0};

//     gen[root] = 1;
//     q.push(root);

//     while(!q.empty()) {
//         int node = q.front();
//         q.pop();

//         for(int child : adj[node]) {
//             gen[child] = gen[node] + 1;
//             q.push(child);
//         }
//     }

//     vector<pair<char,int>> res;

//     for(int i = 0; i < 26; i++) {
//         if(adj[i].size() == 1) {
//             int child = adj[i][0];
//             res.push_back({char(child+'A'), gen[child]});
//         }
//     }

//     cout << res.size() << endl;
//     for(auto x : res) {
//         cout << x.first << " " << x.second << endl;
//     }
// }
int main(){
    int N;
    cin>>N;
    vector<vector<int>> adj(26);
    vector<bool> hasParent(26,false);
    int child[26]={0};
    for(int i=0;i<N;i++){
        char ch,a,b;
        cin>>ch>>a>>ch>>b>>ch;
        int p=a-'A';
        int c=b-'A';
        adj[p].push_back(c);
        hasParent[c]=true;
        child[p]++;
    }
    int root=-1;
    for(int i=0;i<26;i++){
        if( !hasParent[i] && child[i]>0){
            root=i;
            break;
        }
    }
    queue<int> q;
    int gen[26]={0};
    gen[root]=1;
    q.push(root);
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(int children:adj[node]){
            gen[children]=gen[node]+1;
            q.push(children);
        }
    }

    vector<pair<char,int>> res;
    for(int i=0;i<26;i++){
        if(child[i]==1){
            int children=adj[i][0];
            res.push_back({char(children+'A'),gen[children]});
        }
    }
    if(res.empty()){
        cout<<"0"<<endl;
    }
    else {
        cout<<res.size()<<endl;
        for(auto &p: res){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;



}
