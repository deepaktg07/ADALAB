#include <iostream>
using namespace std;
int n, i, j, visited[10], stack[10], top = -1;
int adj[10][10]; 
void dfs(int v){
    visited[v] = 1;
    cout << v << "\t";
    for (i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}
int main(){
    int v; 
    cout << "Enter the number of vertices: ";
    cin >> n; 
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    cout << "Enter graph data in matrix form:    \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    cout << "Enter the starting vertex for DFS: ";
    cin >> v;
    cout << "DFS traversal starting from vertex " << v << " is: ";
    dfs(v);
    return 0;
}
