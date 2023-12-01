function findBitonicShortestPaths(graph, s):
    pathsIncreasing = dijkstra(graph, s, isIncreasing=True)
    pathsDecreasing = dijkstra(graph, s, isIncreasing=False)
    bitonicPaths = findBitonicPaths(graph, s, pathsIncreasing, pathsDecreasing)

    return bitonicPaths

function dijkstra(graph, s, isIncreasing):

function findBitonicPaths(graph, s, pathsIncreasing, pathsDecreasing):
    bitonicPaths = {}

    for each vertex in graph.vertices:
        bitonicPath = findBitonicPath(graph, s, vertex, pathsIncreasing, pathsDecreasing)
        bitonicPaths[vertex] = bitonicPath

    return bitonicPaths

function findBitonicPath(graph, s, vertex, pathsIncreasing, pathsDecreasing):
    bitonicPath = []

    for each intermediateVertex in graph.vertices:
        totalLength = pathsIncreasing[s][intermediateVertex] + pathsDecreasing[vertex][intermediateVertex]
        if bitonicPath is empty or totalLength < length(bitonicPath):
            bitonicPath = combinePaths(pathsIncreasing[s][intermediateVertex], pathsDecreasing[vertex][intermediateVertex])

    return bitonicPath

function combinePaths(path1, path2):
    return path1 + path2
