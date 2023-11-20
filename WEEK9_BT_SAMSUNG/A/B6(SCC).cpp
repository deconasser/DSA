#include<bits/stdc++.h>
using namespace std; 
bool visited[1001];
vector<int> adj[1001], r_adj[1001];
stack<int> st;
int n, m;
int ans = 0;
void dfs1(int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			dfs1(v);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	visited[u] = true;
	for(int v : r_adj[u]) {
		if(!visited[v]) {
			dfs2(v);
		}
	}
}
void SCC() {
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			dfs1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	while(!st.empty()) {
		int tmp = st.top();
		if(!visited[tmp]) {
			dfs2(tmp);
			++ans;
		}
		st.pop();
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
	SCC();
	cout << ans;

}