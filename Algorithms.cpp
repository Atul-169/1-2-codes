==== prims ====
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int to, weight;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // ignore invalid vertex
        if (u < 1 || u > n || v < 1 || v > n)
            continue;

        // self-loop does not help in MST
        if (u == v)
            continue;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, 1e9);

    // মিন-হিপ: {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    long long totalCost = 0;
    vector<pair<pair<int, int>, int>> mstEdges;

    // disconnected graph handle করার জন্য সব component এ Prim চালাব
    for (int start = 1; start <= n; start++)
    {
        if (visited[start])
            continue;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            totalCost += w;

            if (parent[u] != -1)
                mstEdges.push_back({{parent[u], u}, w});

            for (auto edge : adj[u])
            {
                int v = edge.to;
                int cost = edge.weight;

                if (!visited[v] && cost < key[v])
                {
                    key[v] = cost;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == -1)
            components++;
    }

    if (components > 1)
        cout << "Graph is disconnected. Minimum Spanning Forest:\n";
    else
        cout << "Minimum Spanning Tree:\n";

    for (auto e : mstEdges)
    {
        cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
    }

    cout << "Total Cost = " << totalCost << "\n";

    return 0;
}

/*
Key Notes:

1. Prim's algorithm grows MST from a starting node.
2. It always picks minimum edge from visited -> unvisited node.
3. Priority queue is used for minimum edge selection.
4. Self-loops are ignored.
5. Negative weights work fine.
6. Parallel edges also work fine; smaller useful one will be chosen.
7. If graph is disconnected, this code gives Minimum Spanning Forest.
8. Time Complexity: O(E log V)
*/


=== kruskal = ==


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
private:
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findSet(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent[x]); // path compression
    }

    bool unionSet(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);

        if (a == b)
            return false;

        // union by size
        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // ignore invalid vertex
        if (u < 1 || u > n || v < 1 || v > n)
            continue;

        // self-loop never helps in MST
        if (u == v)
            continue;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    long long totalCost = 0;
    vector<vector<int>> mstEdges;

    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (dsu.unionSet(u, v))
        {
            mstEdges.push_back({u, v, w});
            totalCost += w;
        }
    }

    if ((int)mstEdges.size() == n - 1)
        cout << "Minimum Spanning Tree:\n";
    else
        cout << "Graph is disconnected. Minimum Spanning Forest:\n";

    for (auto e : mstEdges)
    {
        cout << e[0] << " " << e[1] << " " << e[2] << "\n";
    }

    cout << "Total Cost = " << totalCost << "\n";

    return 0;
}

/*
Key Notes:

1. Kruskal's algorithm sorts all edges by weight.
2. It picks the smallest edge that does not form a cycle.
3. DSU is used to check whether two vertices are already in same component.
4. findSet(x) returns the representative/root of x.
5. unionSet(a, b) merges two sets if they are different.
6. Path compression makes find faster.
7. Union by size keeps tree shallow.
8. Self-loops are ignored.
9. Negative weights work fine.
10. Parallel edges also work fine; smaller valid edge may be chosen first.
11. If graph is disconnected, this code gives Minimum Spanning Forest.
12. Time Complexity: O(E log E)
*/


= = = dsu == =
#include <iostream>
#include <vector>
using namespace std;

class DSU
{
private:
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findSet(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent[x]); // path compression
    }

    bool unionSet(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool sameSet(int a, int b)
    {
        return findSet(a) == findSet(b);
    }

    int sizeOfSet(int x)
    {
        return sz[findSet(x)];
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (a < 1 || a > n || b < 1 || b > n)
        {
            cout << "Invalid vertex\n";
            continue;
        }

        if (type == 1)
        {
            dsu.unionSet(a, b);
        }
        else if (type == 2)
        {
            if (dsu.sameSet(a, b))
                cout << "Same Set\n";
            else
                cout << "Different Set\n";
        }
        else
        {
            cout << "Invalid query type\n";
        }
    }

  return 0;
}

/*
Key Notes:

1. DSU keeps track of connected components.
2. Initially every node is its own parent.
3. findSet(x) finds root of x.
4. unionSet(a, b) joins two components.
5. sameSet(a, b) checks whether a and b are in same component.
6. Path compression + union by size makes DSU very efficient.
7. Amortized time per operation is almost O(1).
*/

  ==== Dijkstras ===
    #include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;

    // adjacency list:
    // adj[u] stores {v, weight}
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // invalid vertex ignore
        if (u < 1 || u > n || v < 1 || v > n)
            continue;

        // Dijkstra does NOT support negative weight
        if (w < 0)
            continue;

        // directed graph edge: u -> v with weight w
        // for undirected graph, also add adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    int source;
    cin >> source;

    if (source < 1 || source > n)
    {
        cout << "Invalid source\n";
        return 0;
    }

    // dist[i] = currently known shortest distance from source to i
    vector<long long> dist(n + 1, INF);

    // parent[i] = previous node in shortest path
    vector<int> parent(n + 1, -1);

    // min-heap:
    // {distance, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // source to itself = 0
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // if this is an old larger distance entry, ignore it
        if (d != dist[u])
            continue;

        // visit all neighbors of u
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            // RELAXATION:
            // if going from source -> u -> v is better than current known dist[v],
            // then update dist[v]
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " = ";

        if (dist[i] == INF)
            cout << "INF\n"; // unreachable node
        else
            cout << dist[i] << "\n";
    }

    return 0;
}

/*
Key Notes:

1. Dijkstra finds shortest path from one source to all nodes.
2. It works only when all edge weights are non-negative.
3. priority_queue is used to always take the node with smallest distance.
4. dist[u] = currently best known shortest distance from source to u.
5. parent[v] stores from which node we came to v.
6. Main idea of Dijkstra is RELAXATION:
   if (dist[u] + w < dist[v]) then update dist[v].
7. If a node cannot be reached, its distance remains INF.
8. This code is for directed graph.
9. For undirected graph, add reverse edge too.
10. Time Complexity: O((V + E) log V)
*/



