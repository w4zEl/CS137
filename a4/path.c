static int checkPath(int i, int j, int m, int n, int a[m][n]) {
    return i == m - 1 && j == n - 1 || 
        i + 1 < m && a[i + 1][j] && checkPath(i + 1, j, m, n, a) || j + 1 < n && a[i][j + 1] && checkPath(i, j + 1, m, n, a);
}
int monotonePath(int m, int n, int a[m][n]) {
    return checkPath(0, 0, m, n, a);
}