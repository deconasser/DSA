#include<bits/stdc++.h>
using namespace std;
int n, m, X, Y;
vector<int> ke[1001];
bool visited[1001];
int ans = 0;
queue<int> q;
void bfs(int tmp) {
	q.push(tmp);
	visited[tmp] = true;
	while(!q.empty()) {
		int v = q.front();
		if(v == Y) {
			cout << ans - 1;
			return;
		}
		++ans;
		q.pop();
		for(int k : ke[v]) {
			if(!visited[k]) {
				q.push(k);
				visited[k] = true;
			}	
		}
	}
}
int main() {
	cin >> n >> m >> X >> Y;
	for(int i = 1; i <= m ; ++i) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	bfs(X);

	return 0;
}