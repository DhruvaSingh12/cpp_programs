#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source;
    cin >> source;

    const long long INF = (long long)4e18;
    vector<long long> dist(n, INF);
    dist[source] = 0;

    priority_queue<pair<long long, int>, 
                        vector<pair<long long, int>>, 
                        greater<pair<long long, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        if (currDist > dist[node]) {
            continue;
        }

        for (const auto &edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

// not applicable in graphs with negative cycles, but works fine for graphs with non-negative weights.
// priority queue time for insertion deletion worst case is log(n) and for n nodes and m edges, the overall time complexity is O((n + m) log n).

// time complexity (Dijkstra's algorithm): O((n + m) log m) where n is the number of vertices and m is the number of edges. 
// This is because each vertex and edge is processed at most once, and the priority queue operations take O(log n) time.