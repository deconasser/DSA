function optimizedDijkstra(graph, source, C):
    distances = array of size C + 1, initialized to infinity
    distances[0] = 0;
    for each vertex in graph.vertices:
        currentDistance = distances[min(graph.getWeight(source, vertex), C)]
        if currentDistance != infinity:
            for each neighbor in graph.neighbors(vertex):
                weight = graph.getWeight(vertex, neighbor)
                if weight <= C:
                    newDistance = currentDistance + weight
                    distances[min(newDistance, C)] = min(distances[min(newDistance, C)], newDistance)

    return distances
