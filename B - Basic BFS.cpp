/*
	Learn BFS concept here: https://youtu.be/oDqjPvD54Ss

	The problem has n <= 10^3 so we can use adjective matrix to store edges

	Adjective matrix is 2D array (Let call it 'adj') if adj[x][y] is true
	mean that there is a edge between vertex x and vertex y

	Because we start doing bfs at vertex 1 and spreading to lowest vertex possible
	so we only put vertex 1 to queue and always run next vertex from 1 up to n
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, i;
bool adj[1001][1001], dd[1001];
deque<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x][y] = adj[y][x] = true;
	}
	st.push_back(1);
	dd[1] = true;
	while(!st.empty()) {
		x = st.front();
		st.pop_front();
		cout << x << "\n";
		for(i = 1; i <= n; ++i)
			if(!dd[i] && adj[x][i]) {
				st.push_back(i);
				dd[i] = true;
			}
	}

	return 0;
}