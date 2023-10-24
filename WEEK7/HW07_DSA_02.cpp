#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
struct edge {
	int x, y, w;
};
vector<edge> canh;
vector<edge> ans;
int totalCost = 0;
vector<pi> adj[1001];
int par[1001];
int siz[1001];
int n, m;
void init() {
	ifstream inFile("connection.txt");
	inFile >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y, w; inFile >> x >> y >> w;
		canh.push_back({x,y,w});
	}

	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		siz[i] = 1;
	}
}
int find(int u) {
	if(u == par[u]) return u;
	else return par[u] = find(par[u]);
}
bool Union(int a, int b) {
	int u = find(a);
	int v = find(b);
	if(u == v) return false;
	if(siz[u] > siz[v]) {
		par[b] = par[a];
		siz[a] += siz[b];
	}
	else {
		par[a] = par[b];
		siz[b] += siz[a];
	}
	return true;
}
void kruskal() {
	ofstream outFile("connection.out");
	sort(canh.begin(), canh.end(), [](edge a, edge b)->bool{
		return a.w < b.w;
	});

	for(int i = 0; i < m; ++i) {
		if(ans.size() == n-1) break;
		if(!Union(canh[i].x, canh[i].y)) {
			continue;
		} else {
			totalCost += canh[i].w;
			ans.push_back(canh[i]);
		}
	}
	if(ans.size() < n - 1) {
		outFile << "Không phải là cây" << endl;
	} else {
		outFile << totalCost << endl;
		for(auto it : ans) {
			outFile << it.x << " " << it.y << " " << it.w << endl;
		}
	}

}

int main()
{
	init();
	kruskal();

	return 0;
}