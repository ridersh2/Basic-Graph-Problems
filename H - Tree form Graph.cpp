/*
	m is the number of edges of the graph
	Tree only has n - 1 edges (n is number of vertices/nodes)
	so we reduce the number of edges down to n - 1 (m = n - 1)
	but must include all n nodes

	To do that, we can do normal bfs like problem E
	instead of printing the order of nodes we print the edges
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, i;
vector<int> adj[100001];
deque<int> st;
bool dd[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	st.push_back(1);
	dd[1] = true;
	while(!st.empty()) {
		x = st.front();
		st.pop_front();
		for(i = 0; i < adj[x].size(); ++i) {
			y = adj[x][i];
			if(!dd[y]) {
				st.push_back(y);
				dd[y] = true;
				cout << x << " " << y << "\n";
			}
		}
	}

	return 0;
}