#include<bits/stdc++.h>
using namespace std;

bool is_connected(vector<vector<int>> &G) {
  int n = G.size();
  vector<bool> visited(n, false);
  int count = 0;
  stack<int> stack;
  stack.push(0);
  while (!stack.empty()) {
    int u = stack.top();
    stack.pop();
    if (!visited[u]) {
      visited[u] = true;
      count++;
      for (int v : G[u]) {
        if (!visited[v]) {
          stack.push(v);
        }
      }
    }
  }
  return count == n;
}

bool hasEulerCyc(vector<vector<int>> &G) {
  int n = G.size();
  vector<int> in_degree(n, 0);
  vector<int> out_degree(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G[i][j] > 0) {
        out_degree[i]++;
        in_degree[j]++;
      }
    }
  }
  if (!is_connected(G)) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    if (in_degree[i] != out_degree[i]) {
      return false;
    }
  }
  return true;
}