/*
	Learn about tree structure here: https://youtu.be/QFQlxtz7f6g

	After knowing what is tree, you can do this problem by using dfs
	Dfs in tree is very special because in tree a node only has ONE parent
	so you don't need a boolean array to store visited nodes
	while dfs you just check if the next node you spread to is the parent
	if it's not then you can dfs to that node

	While dfs you also need to store the answer of very node too
	q0 is query 0
	q1 is query 1
	query1 can compute by taking parent's query1 plus 1 (parent's depth level move down one more level)
	query0 can compute after you have what depth level of every node (while dfs or outside)
*/

#include <bits/stdc++.h>
using namespace std;

int n, q, x, y, i, q0[10001], q1[10001], d;
vector<int> adj[10001];

void dfs(int x , int tr) {
	int j, y;
	//query 1
	q1[x] = q1[tr] + 1;
	//query 0      query 1 is also the depth level of that node so you can compute while dfs
	++q0[q1[x]];
	for(j = 0; j < adj[x].size(); ++j) {
		y = adj[x][j];
		//the next node must not the parent
		if(y != tr) dfs(y,x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> q;
	for(i = 1; i < n; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	q1[0] = -1;
	dfs(1,0);
	//answer query
	while(q--) {
		cin >> x >> y;
		if(!x) {
			if(q0[y]) cout << q0[y] << "\n";
			else cout << "-1\n";
		} else cout << q1[y] << "\n";
	}

	return 0;
}
