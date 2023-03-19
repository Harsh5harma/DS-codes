#include <iostream>

int main(){
  int m, n;
  std::cin>>n>>m;
  //graph representation
  int adj[n+1][m+1];
  for (int i{0};i<m;i++){
    int u, v;
    std::cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
  }
  return 0;
}