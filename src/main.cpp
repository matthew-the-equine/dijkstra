#include <iostream>
#include "weighted_graph.h"
using namespace std;

int main() {
  singly_linked_list<int> a = singly_linked_list<int>();
  a.push(1);
  a.push(30);
  a.push(-1);
  a.display();

  weighted_graph<int, int> graph = weighted_graph<int, int>();
  graph.add_vertex(1);
  graph.display();
}