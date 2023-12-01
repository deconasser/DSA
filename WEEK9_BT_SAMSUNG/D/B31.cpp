#include<bits/stdc++.h>
using namespace std;


#define pi pair<int, int> 
int n, m;
int d[1001];
struct edge{
	int x, y, w;
};
vector<edge> dscanh;

void inp() {
	for(int i = 1; i <= m; ++i) {
		int x, y, w; cin >> x >> y >> w;
		dscanh.push_back({x,y,w});
	}
}

void BellmanFord(int s) {
	for(int i = 1; i <= n; ++i) d[i] = 1e9;
	d[s] = 0;
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < m; j++)
			if(d[dscanh[j].x] < 1e9) 
			d[dscanh[j].y] = min(d[dscanh[j].y], d[dscanh[j].x] + dscanh[j].w);
	}
	for(int i = 1; i <= n; ++i) {
		cout << d[i] << " ";
	}
}
int main()
{  
 	cin >> n >> m;
 	inp();
 	BellmanFord(1);

	return 0;
}