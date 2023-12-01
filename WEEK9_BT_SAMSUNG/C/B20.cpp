#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

struct Edge {
    char start;
    char end;
    int weight;

    Edge(char s, char e, int w) : start(s), end(e), weight(w) {}
};

class GraphVisualizer {
public:
    GraphVisualizer(std::vector<Edge>& edges) : edges(edges) {
        initializeGraph();
        buildMinimumSpanningTree();
    }

    void run() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Minimum Spanning Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            drawGraph(window);
            window.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause for 500 milliseconds
        }
    }

private:
    std::vector<Edge> edges;
    std::vector<char> vertices;
    std::vector<Edge> minimumSpanningTree;

    void initializeGraph() {
        for (const auto& edge : edges) {
            if (std::find(vertices.begin(), vertices.end(), edge.start) == vertices.end()) {
                vertices.push_back(edge.start);
            }
            if (std::find(vertices.begin(), vertices.end(), edge.end) == vertices.end()) {
                vertices.push_back(edge.end);
            }
        }
    }

    void buildMinimumSpanningTree() {
        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        std::vector<int> parent(vertices.size());
        std::iota(parent.begin(), parent.end(), 0);

        for (const auto& edge : edges) {
            int startIdx = std::find(vertices.begin(), vertices.end(), edge.start) - vertices.begin();
            int endIdx = std::find(vertices.begin(), vertices.end(), edge.end) - vertices.begin();

            int rootStart = find(parent, startIdx);
            int rootEnd = find(parent, endIdx);

            if (rootStart != rootEnd) {
                minimumSpanningTree.push_back(edge);
                parent[rootStart] = rootEnd;
            }
        }
    }

    int find(const std::vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void drawGraph(sf::RenderWindow& window) {
        // Draw vertices
        for (const auto& vertex : vertices) {
            sf::CircleShape circle(20);
            circle.setFillColor(sf::Color::Blue);
            circle.setPosition(100 + vertex - 'A' * 50, 300);
            window.draw(circle);

            sf::Text text;
            text.setString(vertex);
            text.setFont(font);
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::White);
            text.setPosition(110 + vertex - 'A' * 50, 310);
            window.draw(text);
        }

        // Draw edges
        for (const auto& edge : edges) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(110 + edge.start - 'A' * 50, 320)),
                sf::Vertex(sf::Vector2f(110 + edge.end - 'A' * 50, 320))
            };
            window.draw(line, 2);
        }

        // Highlight minimum spanning tree edges
        for (const auto& edge : minimumSpanningTree) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(110 + edge.start - 'A' * 50, 320), sf::Color::Green),
                sf::Vertex(sf::Vector2f(110 + edge.end - 'A' * 50, 320), sf::Color::Green)
            };
            window.draw(line, 2);
        }
    }

    sf::Font font;
};

int main() {
    std::vector<Edge> edges = {
        {'A', 'B', 2},
        {'A', 'C', 3},
        {'B', 'C', 1},
        {'B', 'D', 4},
        {'C', 'D', 5},
        {'C', 'E', 6},
        {'D', 'E', 2},
        {'E', 'A', 7}
    };

    GraphVisualizer graphVisualizer(edges);
    graphVisualizer.run();

    return 0;
}
