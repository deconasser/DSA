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
        adjList[v].push_back(u); 
    }


    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& s) {
        visited[v] = true;

        for (int i : adjList[v]) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, s);
            }
        }

        s.push(v);
    }

    stack<int> topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, s);
            }
        }

        return s;
    }

    bool hasHamiltonCycle() {
        stack<int> s = topologicalSort();

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (!s.empty()) {
                int v = s.top();

                bool hasEdge = false;
                for (int i : adjList[u]) {
                    if (i == v) {
                        hasEdge = true;
                        break;
                    }
                }

                if (!hasEdge) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(4, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 0);

    if (g.hasHamiltonCycle()) {
        cout << "Tồn tại chu trình Hamilton.\n";
    } else {
        cout << "Không tồn tại chu trình Hamilton.\n";
    }

    return 0;
}