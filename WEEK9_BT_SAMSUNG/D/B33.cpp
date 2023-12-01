function shortestPath(matrix):
    N = matrix.rows 
    dp = initializeDPMatrix(N)
    for i from 1 to N-1:
        dp[0][i] = dp[0][i-1] + matrix[0][i]
        dp[i][0] = dp[i-1][0] + matrix[i][0]
    for i from 1 to N-1:
        for j from 1 to N-1:
            dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1])

    return dp[N-1][N-1]

function initializeDPMatrix(N):
    dp = new Matrix(N, N)
    return dp
