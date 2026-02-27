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
    vector<Points> points; //array of cities

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
        int size=right-left+1;
        if(left>=right){
            return;
        }
        if(size<=M){

            vector<Edge> edges;
            //making complete graph
            for(int i=left;i<=right;i++){
                for(int j=i+1;j<=right;j++){
                    double cost=get_cost(points[i],points[j]);
                    edges.push_back(Edge(points[i].ID,points[j].ID,cost));
                }
            }
            

            sort(edges.begin(),edges.end(),compareCost);
            
            
            //applying kruskals algo
            int mst_edges=0;
            for(int i=0;i<edges.size();i++){
                int u=edges[i].u;
                int v=edges[i].v;
                double cost=edges[i].cost;

                if(is_Connected(u,v)){
                    continue;
                }
                else{
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    result.push_back(edges[i]);
                    total_cost+=cost;
                    mst_edges++;
                    if(mst_edges==size-1){
                        break;
                    }
                }

            }
            return;

        }
        int mid=(left+right)/2;
        solve(left,mid);
        solve(mid+1,right);

        double best_cost=INFINITY;
        int u=-1;
        int v=-1;
        int left_idx=max(left,mid-M+1);
        int right_idx=min(right,mid+M);
        for(int i=left_idx;i<=mid;i++){
            for(int j=mid+1;j<=right_idx;j++){
                double check_cost=get_cost(points[i],points[j]);
                if(check_cost<best_cost){
                    best_cost=check_cost;
                    u=points[i].ID;
                    v=points[j].ID;
                }
            }
        }
        if(u==-1 || v==-1){
            throw runtime_error("No valid edge found");
        }
        result.push_back(Edge(u,v,best_cost));
        total_cost=total_cost+best_cost;

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

