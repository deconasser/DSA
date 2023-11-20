#include<bits/stdc++.h>
using namespace std;

int countParallelEdges(const vector<pair<int, int>>& edges) {
    map<pair<int, int>, int> edgeCount;
    int parallelEdges = 0;

    for (const auto& edge : edges) {
        // Chuẩn hóa cạnh (đảm bảo đỉnh nhỏ hơn đứng trước)
        pair<int, int> normalizedEdge = edge.first < edge.second 
                                             ? make_pair(edge.first, edge.second) 
                                             : make_pair(edge.second, edge.first);

        edgeCount[normalizedEdge]++;
    }


    for (const auto& pair : edgeCount) {
        if (pair.second > 1) {
            parallelEdges += pair.second - 1;
        }
    }

    return parallelEdges;
}

int main() {
    // Test với danh sách cạnh
    vector<std::pair<int, int>> edges = {{1, 2}, {2, 1}, {2, 3}, {3, 2}, {4, 5}};
    cout << "Số cạnh song song: " << countParallelEdges(edges) << std::endl;

    return 0;
}
