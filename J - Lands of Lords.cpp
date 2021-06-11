/*
	Lets reducing the problem to a normal graph and you know all adjective lands of
	a land of a lord. We can simply use bfs to find the shortest path on unweighted
	graph by tracking "how many step" or the depth level of bfs while doing bfs.

	How can we make a matrix graph into a normal graph?

	We just check every element in the matrix if the adjective element is different
	then we push it into adjective list to store that edge
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int n, i, j, l, a[N][N], x, y, m, ans[N * N];
vector<int> adj[N * N];
deque<int> st;

void creatAdjList() {
	for(j = 1; j <= n; ++j) for(i = 1; i <= n; ++i)
		for(l = 0; l < 4; ++l) {
			x = i + dx[l];
			y = j + dy[l];
			if(x > 0 && x <= n && y > 0 && y <= n && a[i][j] != a[x][y])
				adj[a[i][j]].push_back(a[x][y]);
		}
}

void bfs() {
	cin >> y >> x;
	st.push_back(a[x][y]);
	ans[a[x][y]] = 1;
	while(!st.empty()) {
		x = st.front();
		st.pop_front();
		for(j = 0; j < adj[x].size(); ++j) {
			y = adj[x][j];
			if(!ans[y]) {
				st.push_back(y);
				ans[y] = ans[x] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for(j = 1; j <= n; ++j) for(i = 1; i <= n; ++i) {
		cin >> a[i][j];
		m = max(m,a[i][j]);
	}
	creatAdjList();
	bfs();
	cin >> y >> x;
	cout << ans[a[x][y]] - 1;

	return 0;
}