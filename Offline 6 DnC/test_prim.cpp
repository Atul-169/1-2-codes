#include<bits/stdc++.h>
using namespace std;
class Points{
    public:

    int ID;
    double x;
    double y;
    Points(int id,double a,double b){
        ID=id;
        x=a;
        y=b;
    }

};
class Edge{
    public:
    int u,v;
    double cost;
    Edge(int a,int b,double c){
        u=a;
        v=b;
        cost=c;
    }

};
class City{
    public:
    vector<Edge> result;
    double total_cost=0;
    vector<vector<int>> adj;


    int N,M;
    vector<Points> points;
    City(int n,int m){
        N=n;
        M=m;
        adj.resize(N+1);
        vector<bool> taken(N+1,false);
        for(int i=0;i<N;i++){
            int id,x,y;
            cin>>id>>x>>y;
            if(id<1 || id>N || taken[id]){
                throw invalid_argument("Invalid ID");
            }
            taken[id]=true;
            points.push_back(Points(id,x,y));
            
        }
    }
    double get_cost(Points &a,Points &b){
        return sqrt((a.x-b.x)*(a.x-b.x) +
                (a.y-b.y)*(a.y-b.y));
    }
    bool is_Connected(int start,int target){
        //using BFS
        vector<bool> visited(adj.size(),false);
        queue<int> q;

        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            int top=q.front();
            q.pop();

            if(top==target){
                return true;
            }

            for(int i=0;i<adj[top].size();i++){
                int adjacent=adj[top][i];
                if(!visited[adjacent]){
                    visited[adjacent]=true;
                    q.push(adjacent);
                }

            }
        }
        return false;
    }

    static bool compareCost(Edge &a,Edge &b){
        return a.cost<b.cost;
    }

     void solve(int left,int right){

        if(left>=right) return;

        int size = right-left+1;

        // ---------------- BASE CASE USING PRIM ----------------
        if(size <= M){

            vector<bool> visited(size,false);
            vector<double> minDist(size,1e18);
            vector<int> parent(size,-1);

            minDist[0] = 0;

            for(int i=0;i<size;i++){

                int u=-1;
                double best=1e18;

                
                for(int j=0;j<size;j++){
                    if(!visited[j] && minDist[j] < best){
                        best = minDist[j];
                        u=j;
                    }
                }

                visited[u]=true;

                
                if(parent[u] != -1){

                    Points &A=points[left+u];
                    Points &B=points[left+parent[u]];

                    double cost=get_cost(A,B);

                    result.push_back(Edge(A.ID,B.ID,cost));
                    total_cost +=cost;

                    adj[A.ID].push_back(B.ID);
                    adj[B.ID].push_back(A.ID);
                }
                for(int v=0; v<size; v++){
                    if(!visited[v]){
                        double cost=get_cost(points[left+u],points[left+v]);
                        if(cost < minDist[v]){
                            minDist[v]=cost;
                            parent[v]=u;
                        }
                    }
                }
            }
            return;
        }

        int mid=(left+right)/2;

        solve(left,mid);
        solve(mid+1,right);

        double best_cost=INFINITY;
        int u=-1,v=-1;

        int left_max=max(left,mid-M+1);
        int right_min=min(right,mid+M);

        for(int i=left_max;i<=mid;i++){
            for(int j=mid+1;j<=right_min;j++){
                double cost=get_cost(points[i],points[j]);
                if(cost < best_cost){
                    best_cost=cost;
                    u=points[i].ID;
                    v=points[j].ID;
                }
            }
        }

        if(u==-1 || v==-1)
            throw runtime_error("No valid edge found");

        result.push_back(Edge(u,v,best_cost));
        total_cost+=best_cost;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(){
        cout<<"Total cost: ";
        printf("%.2lf\n",total_cost);
        cout<<"Edges:"<<endl;
        for(int i=0;i<result.size();i++){
            cout<<result[i].u<<" "<<result[i].v;
            if(i!=result.size()-1){
                cout<<endl;
            }
            
        }
    }
    static bool compareX(Points &a,Points &b){
        if(a.x==b.x){
            return a.y<b.y;
        }
        return a.x<b.x;
    }
    void network(){
        sort(points.begin(),points.end(),compareX);
        solve(0,N-1);
    }



};


int main(){
    int N,M;
    cin>>N>>M;
    if(N<4){
        throw invalid_argument("N must be at least 4");

    }
    if(M<2 || M>50){
        throw invalid_argument("M must be between 2 and 50");
    }
    City city(N,M);

    city.network();
    city.print();

    

}

