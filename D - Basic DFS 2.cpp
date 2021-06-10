/*
	It's the problem A but n <= 10^5

	So you need an adjective list to store edges instead
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, i;
vector<int> adj[100001];
bool dd[100001];

void dfs(int x) {
	int j, y;
	dd[x] = true;
	cout << x << "\n";
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
	for(i = 1; i <= n; ++i) sort(adj[i].begin(),adj[i].end());
	dfs(1);

	return 0;
}