function findMonotonicShortestPaths(graph, s):
    edgesAscending = sortEdgesAscending(graph.edges)
    pathsAscending = findPaths(graph, s, edgesAscending)
    edgesDescending = sortEdgesDescending(graph.edges)
    pathsDescending = findPaths(graph, s, edgesDescending)
    finalPaths = compareAndSelectPaths(pathsAscending, pathsDescending)

    return finalPaths

function sortEdgesAscending(edges):
    return sort(edges, ascendingOrder)

function sortEdgesDescending(edges):
    return sort(edges, descendingOrder)

function findPaths(graph, s, sortedEdges):
    paths = {}
    for each edge in sortedEdges:
        addEdgeToPriorityQueue(edge)
        currentPath = search(graph, s)
        paths[edge] = currentPath

    return paths

function addEdgeToPriorityQueue(edge):

function search(graph, s):

function compareAndSelectPaths(pathsAscending, pathsDescending):
    return shortestPaths
