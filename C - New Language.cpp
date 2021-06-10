/*
	Learn vector of vector concept here: https://youtu.be/RA911727_Q0

	I made this problem for everyone who doesn't know about adjective list
	can learn this thing

	With adjective list, you can store edges with bigger vertex number

	There are several ways to make an adjective list, you can use array of vector
	or you can use vector of vector like the video or maybe some thing else
*/

#include <bits/stdc++.h>
using namespace std;

int n, x, y, m, i, j;
vector<int> adj[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i = 1; i <= n; ++i) {
		sort(adj[i].begin(),adj[i].end());
		cout << adj[i].size() << " ";
		for(j = 0; j < adj[i].size(); ++j) cout << adj[i][j] << " ";
		cout << "\n";
	}

	return 0;
}