#include <iostream>
#include <stack>
using namespace std;

int n, i, j, visited[10];
int adj[10][10];

void dfs(int v) {
    stack<int> st;
    st.push(v); // Push the starting vertex onto the stack

    while (!st.empty()) {
        v = st.top(); // Get the top element from the stack
        st.pop();     // Pop the top element

        if (!visited[v]) {
            cout << v << " "; // Print the current vertex
            visited[v] = 1;   // Mark the current vertex as visited

            // Push unvisited adjacent vertices onto the stack
            for (int i = n; i >= 1; i--) {
                if (adj[v][i] && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
}
int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0; // Initialize visited array
    }
    cout << "Enter graph data in matrix form:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j]; // Input adjacency matrix
        }
    }
    cout << "Enter the starting vertex for DFS: ";
    cin >> v;
    cout << "DFS traversal starting from vertex " << v << " is: ";
    dfs(v); // Call DFS function
    return 0;
}
