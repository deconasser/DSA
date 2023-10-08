#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool visited[1001];
int n, m;
int ans = 1;
void dfs(int u) {
	visited[u] = true;
	for(int k : ke[u]) {
		if(!visited[k]) {
			dfs(k);
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= m; i++) {
		if(!visited[i]) {
			dfs(i);
			++ans;
		}
	}
	cout << ans;
	return 0;
}