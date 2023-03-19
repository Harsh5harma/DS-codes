//Strongly connected components can be found only in directed graphs.
//a single node gets counted as an SCC too.
//Either find the number of SCCs or print them all.

//reversal of SCCs stops you from visiting other SCCs but it doesn't turn a SCC into a non-SCC

//1) Sort all the edges according to finish time
//2) Reverse the graph
//3) Do a dfs
#include <iostream>
#include <vector>


int kosaraju(int V, std::vector<int> adj[]){
  std::vector<int> &vis(V,0);
}