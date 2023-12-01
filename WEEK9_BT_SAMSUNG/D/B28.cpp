function ShortestPathBetweenSets(graph, S, T):
    resultTable = initializeResultTable(graph, S)
    priorityQueue = createPriorityQueueWithSources(S, resultTable)
    while priorityQueue is not empty:
        currentVertex, currentDistance = priorityQueue.extractMin()
        if currentVertex in T:
            return resultTable[currentVertex]
        for each outgoingEdge in graph.outgoingEdges(currentVertex):
            neighbor = outgoingEdge.end
            newDistance = currentDistance + outgoingEdge.weight
            if newDistance < resultTable[neighbor].distance:
                resultTable[neighbor].distance = newDistance
                resultTable[neighbor].path = resultTable[currentVertex].path + [neighbor]
                priorityQueue.decreaseKey(neighbor, newDistance)
    return "No path found"

function initializeResultTable(graph, S):
    resultTable = {}
    for each vertex in graph.vertices:
        resultTable[vertex] = { distance: INFINITY, path: [] }
    for each source in S:
        resultTable[source].distance = 0

    return resultTable

function createPriorityQueueWithSources(S, resultTable):
    priorityQueue = createPriorityQueue()
    for each source in S:
        priorityQueue.insert(source, resultTable[source].distance)
    return priorityQueue
