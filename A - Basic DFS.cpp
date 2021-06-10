/*
	Learn DFS concept here: https://youtu.be/7fujbpJ0LB4

	The problem has n <= 10^3 so we can use adjective matrix to store edges

	Adjective matrix is 2D array (Let call it 'adj') if adj[x][y] is true
	mean that there is a edge between vertex x and vertex y

	Because we start doing dfs at vertex 1 and spreading to lowest vertex possible
	so we only call dfs at vertex 1 and always run next vertex from 1 up to n
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
bool adj[1001][1001], dd[1001];

void dfs(int x) {
	int j;
	dd[x] = true;
	cout << x << "\n";
	for(j = 1; j <= n; ++j)
		if(!dd[j] && adj[x][j]) dfs(j);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x][y] = adj[y][x] = true;
	}
	dfs(1);

	return 0;
}