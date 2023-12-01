#include<bits/stdc++.h>
using namespace std;
class VyssotskyAlgorithm {
public:
    VyssotskyAlgorithm(int n, const std::vector<std::tuple<int, int, int>>& edges) : n(n), edges(edges) {
        parent.resize(n);
        rank.resize(n, 0);
        initialize();
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    std::vector<std::tuple<int, int, int>> vyssotskyMST() {
        std::sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return std::get<2>(a) < std::get<2>(b);
        });

        std::vector<std::tuple<int, int, int>> mstEdges;

        for (const auto& edge : edges) {
            int u, v, weight;
            std::tie(u, v, weight) = edge;

            if (find(u) != find(v)) {
                mstEdges.push_back(edge);
                unionSets(u, v);
            } else {
                // Chu trình phát sinh, xóa cạnh có trọng số lớn nhất trong chu trình
                std::vector<std::tuple<int, int, int>> cycleEdges = {edge};
                while (find(u) == find(v) && !cycleEdges.empty()) {
                    cycleEdges.pop_back();
                    std::tie(u, v, std::ignore) = cycleEdges.back();
                }

                if (!cycleEdges.empty()) {
                    auto maxEdge = std::max_element(cycleEdges.begin(), cycleEdges.end(),
                        [](const auto& a, const auto& b) {
                            return std::get<2>(a) < std::get<2>(b);
                        });

                    mstEdges.erase(std::remove(mstEdges.begin(), mstEdges.end(), *maxEdge), mstEdges.end());
                }
            }
        }

        return mstEdges;
    }

private:
    int n;
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<std::tuple<int, int, int>> edges;

    void initialize() {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
};

int main() {
    std::vector<std::tuple<int, int, int>> edges = {
        {0, 1, 1}, {0, 2, 2}, {1, 2, 3}, {1, 3, 4}, {2, 3, 5}, {3, 4, 6}, {4, 0, 7}
    };

    VyssotskyAlgorithm vyssotskyAlgorithm(5, edges);
    auto resultMST = vyssotskyAlgorithm.vyssotskyMST();

    std::cout << "Minimum Spanning Tree (MST):" << std::endl;
    for (const auto& edge : resultMST) {
        int u, v, weight;
        std::tie(u, v, weight) = edge;
        std::cout << u << " - " << v << " : " << weight << std::endl;
    }

    return 0;
}
