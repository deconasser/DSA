#include<bits/stdc++.h>

using namespace std;
static int rowNbr[] = {-1, 0, 0, 1};
static int colNbr[] = {0, -1, 1, 0};

bool isSafe(int x, int y, int targetColor, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    int m = matrix.size();
    int n = matrix[0].size();
    return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && matrix[x][y] == targetColor);
}


void floodFillDFS(int x, int y, int targetColor, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        if (isSafe(x + rowNbr[k], y + colNbr[k], targetColor, matrix, visited)) {
            floodFillDFS(x + rowNbr[k], y + colNbr[k], targetColor, matrix, visited);
        }
    }
}

void findSameColorRegions(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int startX = 0;
    int startY = 0;
    int targetColor = matrix[startX][startY];

    floodFillDFS(startX, startY, targetColor, matrix, visited);

    // Mảng vector lưu trữ các phần từ kể nhau cùng màu sắc 
    // Ví dụ như ở đây tìm các phần tử cùng màu 1.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 2, 2},
        {1, 1, 1, 1},
        {1, 2, 3, 1},
        {2, 2, 3, 3}
    };

    findSameColorRegions(matrix);

    return 0;
}
