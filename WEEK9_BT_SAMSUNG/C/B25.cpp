function LimitedMemoryPrim(graph):
    source = getRandomVertex(graph)
    visitedVertices = {source}
    selectedEdges = []

    while len(visitedVertices) < totalVertices(graph):
        sortedEdges = sortEdges(graph.edges)
        selectedEdgesSubset = sortedEdges[:V]
        for edge in selectedEdgesSubset:
            if edge.start in visitedVertices and edge.end not in visitedVertices:
                visitedVertices.add(edge.end)
                selectedEdges.append(edge)

    return selectedEdges
