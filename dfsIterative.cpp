#include <iostream>
#include <list>
#include <stack>

class Graph {
  private:
  int vertices;
  std::list<int>* adjLists;
  bool* visited;
  public:
  Graph(int vertices) {
    this->vertices = vertices;
    this->adjLists = new std::list<int>[vertices];
    this->visited =  new bool[vertices]{false};
  }

  void addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src); // comment out if graph is directed
  }

  void DFS(int src){

    std::stack<int> stack;
    stack.push(src);

    while(!stack.empty()) {
      int s = stack.top();
      stack.pop();

      if (!visited[s]) {
        std::cout<<s<<' ';
        visited[s] = true;
      }

      for (auto itr = adjLists[s].begin(); itr!= adjLists[s].end(); ++itr){
        if (!visited[*itr]) {
          stack.push(*itr);
        }
      }
    }
  }
};

int main() {
  Graph g = Graph(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.DFS(4);
}