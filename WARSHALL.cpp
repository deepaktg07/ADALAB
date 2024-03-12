#include<iostream>
using namespace std;

void warshall(int p[10][10], int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}
int main(){
    int p[10][10]={0};
    int n,e,u,v;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>e;
    for(int i=1;i<=e;i++){
        cout<<"Enter the end verties of edge "<<i<<": "<<endl;
        cin>>u>>v;
        p[u][v]=1;
    }
    cout << "Matrix input data: \n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << p[i][j] << "\t";
        }
        cout << "\n";
    }
    warshall(p, n);
    cout << "Transitive Closure: \n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << p[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
