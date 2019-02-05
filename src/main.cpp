#include <iostream>
#include "file_layer.cpp"
#include "dijsktra.h"
using namespace std;

int main(int argc, char** argv) 
{
  weighted_digraph<int, float> graph;

  read_command_line_parameters(argc, argv, graph);

  dijkstra dijkstra(graph, 2);
  singly_linked_list<weighted_directed_edge<int, float> > path = dijkstra.path_to(12);

  for (forward_iterator<weighted_directed_edge<int, float> > it = path.begin(); it != path.end(); ++it)
  {
    cout << (*it).to_string() << endl;
  }
}