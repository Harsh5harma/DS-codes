#include <iostream>
#include <vector>
using namespace std;

int main(){
  int m, n;
  cin>>n>>m;
  vector<int> adjList[n+1]; //for unweighted graphs
  //std::pair<int, int> graph[m+1][n+1]; //comment out if you have weighted graph (vertex, weight associated)
  for (int i{0};i<n;i++){
    int u, v;
    cin>>v>>u;
    //for an undirected graph
    adjList[v].push_back(u);
    adjList[u].push_back(v);
  
    //for a directed graph
    //u--->v 
    /*
    adjList[u].push_back(v);
    */

  }
}
