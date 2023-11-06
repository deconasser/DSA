#include <bits/stdc++.h>
using namespace std;

int lcs(const vector<int>& a, const vector<int>& b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<char>> direction(m + 1, vector<char>(n + 1, ' ')); // Ma trận hướng đi

    // Xây dựng bảng dp theo cách bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = '\\'; // Điagonal, giữ lại phần tử này
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    direction[i][j] = '|'; // Lên
                } else {
                    dp[i][j] = dp[i][j - 1];
                    direction[i][j] = '-'; // Trái
                }
            }
        }
    }

    // Truy vết để tìm LCS
    int lcs_length = dp[m][n];
    vector<int> lcs_elements(lcs_length);
    int i = m, j = n, index = lcs_length - 1;
    while (i > 0 && j > 0) {
        if (direction[i][j] == '\\') {
            lcs_elements[index] = a[i - 1];
            i--;
            j--;
            index--;
        } else if (direction[i][j] == '|') {
            i--;
        } else {
            j--;
        }
    }

    // In ra LCS
    cout << "LCS: ";
    for (int elem : lcs_elements) {
        cout << elem << " ";
    }
    cout << endl;

    return dp[m][n];
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 4, 5, 8, 10};

    cout << "Do dai day con chung dai nhat la: " << lcs(a, b) << endl;
    return 0;
}
