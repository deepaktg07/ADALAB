#include <iostream>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
void warshall(int p[10][10], int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
            }
        }
    }
}
int main() {
    int p[10][10] = {0};
    int n, e, u, v, i, j;
    cout << "Enter the number of Vertices:\n";
    cin >> n;
    cout << "Enter the number of edges:\n";
    cin >> e;
    for (i = 1; i <= e; i++) {
        cout << "Enter the end vertices of edges " << i << ":";
        cin >> u >> v;
        p[u][v] = 1;
    }
    cout << "Matrix input data: \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << p[i][j] << "\t";
        }
        cout << "\n";
    }
    warshall(p, n);
    cout << "Transitive Closure: \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << p[i][j] << "\t";
        }
    }
    return 0;
}
