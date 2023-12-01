function preprocessGraph(graph):
    dist = initializeDistanceMatrix(graph)
    for each vertex in graph.vertices:
        for each u, v in pairs(graph.vertices):
            dist[u][v] = min(dist[u][v], dist[u][vertex] + dist[vertex][v])
    return dist

function initializeDistanceMatrix(graph):
    dist = {}
    for each vertex in graph.vertices:
        dist[vertex] = {}
        for each otherVertex in graph.vertices:
            dist[vertex][otherVertex] = INFINITY
    for each edge in graph.edges:
        u, v, weight = edge
        dist[u][v] = dist[v][u] = weight

    return dist
function queryDistance(dist, u, v):
    return dist[u][v]
