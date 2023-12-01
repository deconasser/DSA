#include<bits/stdc++.h>


using Graph = std::unordered_map<std::string, std::unordered_map<std::string, int>>;

std::tuple<std::unordered_map<std::string, int>, std::unordered_map<std::string, std::string>> dijkstra(const Graph& graph, const std::string& source) {
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;

    for (const auto& vertex : graph) {
        distances[vertex.first] = std::numeric_limits<int>::max();
        previous[vertex.first] = "";
    }

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        for (const auto& [neighbor, weight] : graph.at(currentNode)) {
            int distance = distances[currentNode] + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = currentNode;
                pq.push({distance, neighbor});
            }
        }

        visualize(graph, previous, source, currentNode);
    }

    return {distances, previous};
}

void visualize(const Graph& graph, const std::unordered_map<std::string, std::string>& previous, const std::string& source, const std::string& currentNode) {
    std::cout << "Dijkstra's Algorithm - Current Node: " << currentNode << std::endl;
    for (const auto& node : graph) {
        std::cout << "Shortest Path from " << source << " to " << node.first << ": " << previous.at(node.first) << ", Path: " << getShortestPath(previous, source, node.first) << std::endl;
    }
    std::cout << std::endl;
}

std::string getShortestPath(const std::unordered_map<std::string, std::string>& previous, const std::string& source, const std::string& destination) {
    std::string path = destination;
    std::string current = destination;

    while (previous.at(current) != "") {
        current = previous.at(current);
        path = current + " -> " + path;
    }

    return path;
}

int main() {
    // Example usage
    Graph graph = {
        {"A", {{"B", 1}, {"D", 3}}},
        {"B", {{"A", 1}, {"C", 2}, {"D", 4}}},
        {"C", {{"B", 2}, {"D", 5}}},
        {"D", {{"A", 3}, {"B", 4}, {"C", 5}}}
    };

    std::string sourceNode = "A";
    auto [distances, previousNodes] = dijkstra(graph, sourceNode);

    for (const auto& node : graph) {
        std::cout << "Shortest Path from " << sourceNode << " to " << node.first << ": " << distances.at(node.first) << ", Path: " << getShortestPath(previousNodes, sourceNode, node.first) << std::endl;
    }

    return 0;
}
