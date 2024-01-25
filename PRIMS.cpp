#include <iostream>
using namespace std;
const int MAX = 20;
int n, c[MAX][MAX], i, j, visited[MAX];
void prim();
int main() {
    cout << "Enter number of vertices" << endl;
    cin >> n;
    cout << "Enter the cost matrix" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin >> c[i][j];
        visited[i] = 0;
    }
    prim();
    return 0;
}
void prim() {
    int min, a, b, k, count = 0, cost = 0;
    visited[1] = 1;
    while (count < n - 1) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && min > c[i][j]) {
                        min = c[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (min == 999) {
            cout << "Graph is not connected." << endl;
            return;
        }
        cout << a << "--->" << b << " = " << min << endl;
        cost += min;
        visited[b] = 1;
        count++;
    }
    cout << "Total cost of Spanning tree is " << cost << endl;
}
