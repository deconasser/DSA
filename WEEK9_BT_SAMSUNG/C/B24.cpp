function BoruvkaMST(graph):
    forest = createForest(graph.vertices) 

    while forest has more than one tree:
        minWeightEdgeForEachTree = initializeEmptyMap()
        for each edge (u, v, weight) in graph.edges:
            rootU = findRoot(forest, u)
            rootV = findRoot(forest, v)
            if rootU != rootV and (weight < minWeightEdgeForEachTree[rootU] or minWeightEdgeForEachTree[rootU] is null):
                minWeightEdgeForEachTree[rootU] = weight
        for each tree in forest:
            if minWeightEdgeForEachTree[tree] is not null:
                minEdge = minWeightEdgeForEachTree[tree]
                mergeTrees(forest, minEdge.start, minEdge.end)
                addEdgeToMST(minEdge)

    return MST
