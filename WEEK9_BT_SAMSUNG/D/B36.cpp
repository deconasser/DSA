function findEdgeToMaximizeShortestPath(graph, s, t):
    initialShortestPathLength = dijkstra(graph, s, t)
    maxIncrease = 0
    edgeToMaximize = null

    for each edge in graph.edges:
        increasedLength = computeIncreasedLength(graph, s, t, edge)
        if increasedLength > maxIncrease:
            maxIncrease = increasedLength
            edgeToMaximize = edge

    return edgeToMaximize

function computeIncreasedLength(graph, s, t, edgeToRemove):
    updatedShortestPathLength = dijkstra(graph, s, t, edgeToRemove)
    return updatedShortestPathLength - initialShortestPathLength
