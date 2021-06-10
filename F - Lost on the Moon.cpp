/*
	Lets run bfs on this (number 1 is where we start):
	1..
	...
	...
	after first spreading:
	12.
	2..
	...
	after second spreading:
	123
	23.
	3..
	after third spreading:
	123
	234
	34.
	last spreading and end bfs:
	123
	234
	345

	We can see that "how many step" of any node you track while doing bfs is also the shortest
	path from the starting node to that node, this works for every node you start to every node
	you end and alse works on map have 'X' (big stone, you can't bfs to) as well

	So we just start bfs at node 'A', keep tracking "how many step" while bfs
	finish bfs, we can output the "how many step" at node 'B'
*/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int n, x, y, xx, yy, i, j, dd[1001][1001], dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
string s;
char a[1001][1001];
deque<pair<int,int> > st;

void add(int x, int y, int z) {
	if(x > 0 && x <= n && y > 0 && y <= n && !dd[x][y] && a[x][y] != 'X') {
		st.push_back(make_pair(x,y));
		dd[x][y] = z + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for(j = 1; j <= n; ++j) {
		cin >> s;
		for(i = 1; i <= n; ++i) {
			a[i][j] = s[i - 1];
			if(a[i][j] == 'A') {
				st.push_back(make_pair(i,j));
				dd[i][j] = 1;
			} else if(a[i][j] == 'B') {
				xx = i;
				yy = j;
			}
		}
	}
	while(!st.empty()) {
		x = st.front().fi;
		y = st.front().se;
		st.pop_front();
		for(i = 0; i < 4; ++i) add(x + dx[i],y + dy[i],dd[x][y]);
	}
	cout << dd[xx][yy] - 1;

	return 0;
}