#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> adj[1001];
bool visited[1001];
int n, m;
void dfs(int s) {
	visited[s] = true;
	for(auto v : adj[s]) {
		if(!visited[v]) dfs(v);
	}
	ans.push_back(s);
}
int main()
{
	ifstream inFile("jobs.txt");
	ofstream outFile("jobs.out");
	inFile >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y; inFile >> x >> y;
		adj[x].push_back(y); // Coi cạnh có hướng
	}
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			dfs(i);
		}
	}
	reverse(begin(ans), end(ans));
	for(auto it : ans) {
		outFile << it << " ";
	}
	return 0;
}