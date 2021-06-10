/*
	This problem actually the counting connected components problem

	A connected component is a subgraph in which each pair of nodes is connected with each other via a path or a set of nodes forms a connected component if any node from the set of nodes can reach any other node by traversing edges. The main point here is reachability.

	After counting connected components, we sort every connected components's size
	then the answer is two most largest size of every connected components
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, i, c;
vector<int> adj[100001], o;
bool dd[100001];

void dfs(int x) {
	int j, y;
	dd[x] = true;
	++c;
	for(j = 0; j < adj[x].size(); ++j) {
		y = adj[x][j];
		if(!dd[y]) dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i = 1; i <= n; ++i)
		if(!dd[i]) {
			c = 0;
			dfs(i);
			o.push_back(c);
		}
	sort(o.begin(),o.end(),greater<int>());
	//push 0 here when the it only have 1 connected component, we can call o[1] but won't get error
	o.push_back(0);
	cout << o[0] + o[1];

	return 0;
}