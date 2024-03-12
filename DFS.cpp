#include <iostream>
#include <stack>
using namespace std;

int n, adj[10][10], visited[10];

void dfs(int v) {
    stack<int> st;
    st.push(v);
    visited[v] = 1;

    while (!st.empty()) {
        int currentVertex = st.top();
        st.pop();
        cout << currentVertex << " ";

        for (int i = 1; i <= n; ++i) {
            if (adj[currentVertex][i] && !visited[i]) {
                st.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix: \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    cout << "Enter the starting vertex for DFS: ";
    cin >> v;

    cout << "DFS traversal starting from vertex " << v << " is: ";
    dfs(v);
    cout << endl;

    return 0;
}
