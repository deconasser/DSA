function LongestPathInDAG(graph):
    topologicalOrder = TopologicalSort(graph)
    resultTable = initializeResultTable(graph, topologicalOrder)
    for each vertex in topologicalOrder:
        for each outgoingEdge in graph.outgoingEdges(vertex):
            neighbor = outgoingEdge.end
            newLength = resultTable[vertex] + outgoingEdge.weight
            if newLength > resultTable[neighbor]:
                resultTable[neighbor] = newLength
    longestPathLength = max(resultTable.values())
    longestPath = reconstructLongestPath(graph, resultTable, longestPathLength)

    return longestPath

function TopologicalSort(graph):
    topologicalOrder = []
    visited = set()

    function DFS(vertex):
        visited.add(vertex)
        for each neighbor in graph.outgoingEdges(vertex):
            if neighbor.end not in visited:
                DFS(neighbor.end)
        topologicalOrder.insert(0, vertex)

    for each vertex in graph.vertices:
        if vertex not in visited:
            DFS(vertex)

    return topologicalOrder

function initializeResultTable(graph, topologicalOrder):
    resultTable = {}
    for each vertex in graph.vertices:
        resultTable[vertex] = float('-inf')
    resultTable[topologicalOrder[0]] = 0

    return resultTable

function reconstructLongestPath(graph, resultTable, longestPathLength):
    endVertex = findEndVertex(resultTable, longestPathLength)
    longestPath = []
    currentVertex = endVertex

    while currentVertex is not None:
        longestPath.insert(0, currentVertex)
        currentVertex = findPredecessor(graph, resultTable, currentVertex)

    return longestPath

function findEndVertex(resultTable, longestPathLength):
    for vertex, length in resultTable.items():
        if length == longestPathLength:
            return vertex

function findPredecessor(graph, resultTable, vertex):
    predecessor = None
    maxPredecessorLength = float('-inf')

    for incomingEdge in graph.incomingEdges(vertex):
        neighbor = incomingEdge.start
        if resultTable[neighbor] > maxPredecessorLength:
            maxPredecessorLength = resultTable[neighbor]
            predecessor = neighbor

    return predecessor
