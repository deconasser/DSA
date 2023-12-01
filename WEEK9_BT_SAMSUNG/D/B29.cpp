function AcceleratedDijkstra(graph, start):
    geometricStructure = createGeometricStructure(graph.vertices)
    resultTable = initializeResultTable(graph, start)
    priorityQueue = createPriorityQueueWithStart(start, resultTable)
    while priorityQueue is not empty:
        currentVertex, currentDistance = priorityQueue.extractMin()
        for each outgoingEdge in graph.outgoingEdges(currentVertex):
            neighbor = outgoingEdge.end
            newDistance = currentDistance + outgoingEdge.weight
            if newDistance < resultTable[neighbor].distance:
                resultTable[neighbor].distance = newDistance
                resultTable[neighbor].path = resultTable[currentVertex].path + [neighbor]
                priorityQueue.decreaseKey(neighbor, newDistance)
    return resultTable

function createGeometricStructure(vertices):
    geometricStructure = buildGeometricStructure(vertices)
    return geometricStructure

function buildGeometricStructure(vertices):
function createPriorityQueueWithStart(start, resultTable):
    priorityQueue = createPriorityQueue()
    priorityQueue.insert(start, resultTable[start].distance)
    return priorityQueue
