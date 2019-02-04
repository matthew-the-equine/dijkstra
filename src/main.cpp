#include <iostream>
#include "weighted_graph.h"
using namespace std;

int main() {
  singly_linked_list<int> list = singly_linked_list<int>();
  list.push(1);
  list.push(30);
  list.push(-1);
  list.iterate([](int i) -> void { cout << i << endl; });

  weighted_graph<int, float> graph = weighted_graph<int, float>();
  graph.add_edge(weighted_edge<int, float>(1, 2, 5.6f));
  graph.adjacent(2).iterate([](weighted_edge<int, float> edge) -> void { cout << edge.from << '-' << edge.to << ':' << edge.weight << endl; });
}