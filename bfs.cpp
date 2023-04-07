/*
  create a queue Q:
  mark a vertex V as visited and put v in the queue
  while Q is not empty:
    remove the head vertex of the queue
    mark that vertex as visited by adding it into the visited list and add its unvisited adjacent vertices to the end of the queue

  Because some parts of the graph may be broken off, we can run BFS on all vertices of the graph.  
*/

#include <iostream>
#include <list>

class Graph {
  int numVertices;
  std::list<int>* adjLists;
  bool* visited;

  public:

  Graph(int vertices){
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
  }

  void addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src); //comment out if the graph is directed
  }

  void BFS(int startVertex) {
    visited = new bool[numVertices]{false};

    std::list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    std::list<int>::iterator itr;
    
    while (!queue.empty()) {
      int currVertex = queue.front();

      std::cout<<"Visited "<< currVertex << '\n';
      queue.pop_front();

      for (itr = adjLists[currVertex].begin(); itr!=adjLists[currVertex].end(); itr++) { 
        int adjVertex = *itr;
        if (!visited[adjVertex]) {
          visited[adjVertex] = true;
          queue.push_back(adjVertex);
        }
      }
    }
  }
};


int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(0);

  return 0;
}