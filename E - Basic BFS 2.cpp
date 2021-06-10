/*
	It's the problem B but n <= 10^5

	So you need an adjective list to store edges instead
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, i;
deque<int> st;
vector<int> adj[100001];
bool dd[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i = 1; i <= n; ++i) sort(adj[i].begin(),adj[i].end());
	st.push_back(1);
	dd[1] = true;
	while(!st.empty()) {
		x = st.front();
		st.pop_front();
		cout << x << "\n";
		for(i = 0; i < adj[x].size(); ++i) {
			y = adj[x][i];
			if(!dd[y]) {
				st.push_back(y);
				dd[y] = true;
			}
		}
	}

	return 0;
}