/*
  DFS(G, u)
    u.visited = true
    for each vertex in Graph's adjacency list for the vertex u:
      if vertex v is not visited:
        Do dfs on v

  init(){
    for each vertex in the graph:
      mark each vertex as unvisited
    for each vertex in graph:
      perform DFS on the vertex.
  }
*/

#include <iostream>
#include <list>

class Graph {
  private:
  int numVertices;
  std::list<int>* adjLists;
  bool* visited;
  
  public:
  Graph(int numVertices){
    this->numVertices = numVertices;
    this->adjLists = new std::list<int>[numVertices];
    this->visited = new bool[numVertices];
  }

  void addEdge(int src, int dest) {
    //if graph is directed
    adjLists[src].push_front(dest);

    // uncomment out if graph is undirected
    // adjLists[dest].push_front(src);
  }

  void DFS(int vertex) {
    visited[vertex] = true;

    std::list<int> adjList = adjLists[vertex];

    std::list<int>::iterator itr;
    
    for (itr = adjList.begin(); itr!= adjList.end(); itr++){
      if (!visited[*itr]) {
        DFS(*itr);
      }
    }
    std::cout<<vertex<<' ';
  }
};


int main() {
  Graph g = Graph(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.DFS(1);
}