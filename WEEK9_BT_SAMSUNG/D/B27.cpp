function DijkstraMultiSourceShortestPaths(graph, sources):
    virtualSource = createVirtualSource(graph, sources)
    priorityQueue = createPriorityQueueWithSources(virtualSource, sources)
    resultTable = initializeResultTable(graph, virtualSource)
    while priorityQueue is not empty:
        currentVertex = priorityQueue.extractMin()
        for each outgoingEdge in graph.outgoingEdges(currentVertex):
            neighbor = outgoingEdge.end
            newDistance = resultTable[currentVertex].distance + outgoingEdge.weight
            if newDistance < resultTable[neighbor].distance:
                resultTable[neighbor].distance = newDistance
                resultTable[neighbor].path = resultTable[currentVertex].path + [neighbor]
                priorityQueue.decreaseKey(neighbor, newDistance)

    return resultTable

function createVirtualSource(graph, sources):
    virtualSource = createNewVertex()
    for each source in sources:
        edgeToSource = createNewEdge(virtualSource, source, 0)
        graph.addEdge(edgeToSource)
    return virtualSource

function createPriorityQueueWithSources(virtualSource, sources):
    priorityQueue = createPriorityQueue()
    priorityQueue.insert(virtualSource, 0)
    for each source in sources:
        priorityQueue.insert(source, 0)
    return priorityQueue

function initializeResultTable(graph, virtualSource):
    resultTable = {}
    for each vertex in graph.vertices:
        resultTable[vertex] = { distance: INFINITY, path: [] }
    resultTable[virtualSource] = { distance: 0, path: [virtualSource] }
    return resultTable
