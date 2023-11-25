#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adjList; 

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    bool hasHamiltonPath() {
        vector<int> inDegree(V, 0);
        vector<int> outDegree(V, 0);

        for (int i = 0; i < V; ++i) {
            for (int j : adjList[i]) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }

        int startCount = 0, endCount = 0;
        int startVertex = -1, endVertex = -1;

        for (int i = 0; i < V; ++i) {
            int diff = outDegree[i] - inDegree[i];

            if (diff > 1 || diff < -1) {
                return false; 
            }

            if (diff == 1) {
                startCount++;
                startVertex = i;
            } else if (diff == -1) {
                endCount++;
                endVertex = i;
            }
        }

        if ((startCount == 0 && endCount == 0) || (startCount == 1 && endCount == 1)) {
            stack<int> s;
            vector<bool> visited(V, false);

            s.push((startCount == 1) ? startVertex : 0);

            while (!s.empty()) {
                int u = s.top();
                s.pop();

                if (!visited[u]) {
                    visited[u] = true;

                    for (int v : adjList[u]) {
                        s.push(v);
                    }
                }
            }

            return count(visited.begin(), visited.end(), true) == V;
        }

        return false; 
    }
};
void inp() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
}
void solve() {
    if (g.hasHamiltonPath()) {
        cout << "Có thứ tự tô pô duy nhất.\n";
    } else {
        cout << "Không có thứ tự tô pô duy nhất.\n";
    }
}
int main() {
    inp();
    solve();
    return 0;
}