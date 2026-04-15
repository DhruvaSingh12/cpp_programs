#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int node, const vector<vector<int>> &adj, vector<int> &visited, stack<int> &st) {
	visited[node] = 1;

	for (int neighbor : adj[node]) {
		if (!visited[neighbor]) {
			dfsTopo(neighbor, adj, visited, st);
		}
	}
	st.push(node);
}

vector<int> topologicalSortDfs(int n, const vector<vector<int>> &adj) {
	vector<int> visited(n, 0);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfsTopo(i, adj, visited, st);
		}
	}

	vector<int> order;
	while (!st.empty()) {
		order.push_back(st.top());
		st.pop();
	}
	return order;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> order = topologicalSortDfs(n, adj);

	for (int node : order) {
		cout << node << ' ';
	}
	cout << '\n';

	return 0;
}

// dfs approach using stack
// only in directed acyclic graph
// time complexity: O(n^2)
// space complexity: O(n) for visited and stack