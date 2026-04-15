#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int node,
			 const vector<vector<pair<int, int>>> &adj,
			 vector<int> &visited,
			 stack<int> &st) {
	visited[node] = 1;

	for (const auto &edge : adj[node]) {
		int neighbor = edge.first;
		if (!visited[neighbor]) {
			dfsTopo(neighbor, adj, visited, st);
		}
	}

	st.push(node);
}

vector<long long> shortestPathDAG(int n,
								  const vector<vector<pair<int, int>>> &adj,
								  int source) {
	vector<int> visited(n, 0);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfsTopo(i, adj, visited, st);
		}
	}

	const long long INF = (long long)4e18;
	vector<long long> dist(n, INF);
	dist[source] = 0;

	while (!st.empty()) {
		int node = st.top();
		st.pop();

		if (dist[node] == INF) {
			continue;
		}

		for (const auto &edge : adj[node]) {
			int neighbor = edge.first;
			int weight = edge.second;
			dist[neighbor] = min(dist[neighbor], dist[node] + weight);
		}
	}

	return dist;
}

int main() {
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

	vector<long long> dist = shortestPathDAG(n, adj, source);

	for (int i = 0; i < n; i++) {
		if (dist[i] >= (long long)4e18 / 2) {
			cout << "INF";
		} else {
			cout << dist[i];
		}

		if (i + 1 < n) {
			cout << ' ';
		}
	}
	cout << '\n';

	return 0;
}