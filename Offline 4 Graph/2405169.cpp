#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    class Edge{
        public:
        int vertex;
        Edge *next;
        Edge *prev;
        
        Edge(int v,Edge *p,Edge *n){
            vertex=v;
            prev=p;
            next=n;
        }

    };
    Edge **nodes;
    int *nodeValues;
    int edgeNum;
    int nodeNum;
    
    Graph(int N){
        nodeNum=N;
        nodes=new Edge*[N];
        for(int i=0;i<N;i++){
            nodes[i]= new Edge(-1,nullptr,nullptr);
        }
        nodeValues=new int[N];

    }
    ~Graph() {
    for (int i = 0; i < nodeNum; i++) {
        Edge *cur = nodes[i];
        while (cur) {
            Edge *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    delete[] nodes;
    delete[] nodeValues;
    }

    Edge* findEdge(int u,int v){
        Edge *cur=nodes[u];
        while(cur->next && cur->next->vertex<v){
            cur=cur->next;

        } 
        return cur;
    }
    void addEdge(int u,int v){
        Edge *cur=findEdge(u,v);
        if(cur->next && cur->next->vertex==v){
            return ;
        }
        cur->next=new Edge(v,cur,cur->next);
        if(cur->next->next){
            cur->next->next->prev=cur->next;

        }

    }
    bool hasEdge(int u,int v){
        Edge *cur=findEdge(u,v);
        bool ans=cur->next && cur->next->vertex==v;
        return ans;
    }
    void DFS(int start,vector<bool> &visited, vector<int> &vertices){
        stack<int> stk;
        stk.push(start);
        visited[start]=true;
        while(!stk.empty()){
            int v=stk.top();
            stk.pop();
            vertices.push_back(v);
            for(Edge *e=nodes[v]->next;e!=nullptr;e=e->next){
                int u=e->vertex;
                if(!visited[u]){
                    visited[u]=true;
                    stk.push(u);
                }
            }
        }

    }
};
int main() {
    int n;
    cin >> n;

    Graph g(n);

    int a, b;
    while (cin >> a >> b) {
    g.addEdge(a, b);
    g.addEdge(b, a);
    }


    vector<bool> visited(n, false);
    vector<vector<int>> groups;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            g.DFS(i, visited, comp);
            groups.push_back(comp);
        }
    }

    cout << groups.size() << "\n";

    int gid = 1;
    for (auto &grp : groups) {
        sort(grp.begin(), grp.end());

        cout << "Group " << gid++ << ": {";
        for (int i = 0; i < grp.size(); i++) {
            cout << grp[i];
            if (i + 1 < grp.size()) cout << ", ";
        }
        cout << "} | ";

        bool missing = false;
        for (int i = 0; i < grp.size(); i++) {
            for (int j = i + 1; j < grp.size(); j++) {
                if (!g.hasEdge(grp[i], grp[j])) {
                    if (missing) cout << ", ";
                    cout << "[" << grp[i] << ", " << grp[j] << "]";
                    missing = true;
                }
            }
        }

        if (!missing) cout << "none";
        cout << "\n";
    }

    return 0;
}
// g++ 2405169.cpp -o 2405169
// .\2405169 < input.txt
