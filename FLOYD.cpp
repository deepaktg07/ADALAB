#include <iostream>
using namespace std;
int min(int a, int b) {
    return (a < b) ? a : b;
}
void floyds(int p[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i != j)
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int main() {
    int p[10][10], w, n, e, u, v, i, j;
    cout << "\nEnter the number of vertices:";
    cin >> n;
    cout << "\nEnter the number of edges:\n";
    cin >> e;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i == j)
                p[i][j] = 0;
            else
                p[i][j] = 999;
    for (i = 1; i <= e; i++) {
        cout << "\nEnter the end vertices of edge " << i << " with its weight:\n";
        cin >> u >> v >> w;
        p[u][v] = w;
    }
    cout << "\nMatrix of input data:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
    floyds(p, n);
    cout << "\nTransitive closure:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
    cout << "\nThe shortest paths are:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                cout << "<" << i << "," << j << ">=" << p[i][j] << "\n";
    return 0;
}
