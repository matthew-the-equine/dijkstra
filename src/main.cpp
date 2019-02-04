#include <iostream>
#include "file_layer.cpp"
#include "dijsktra.h"
using namespace std;

int main(int argc, char** argv) 
{
  weighted_graph<int, float> graph;

  read_command_line_parameters(argc, argv, graph);

  singly_linked_list<weighted_edge<int, float> > adj12 = graph.adjacent(12);
  singly_linked_list<weighted_edge<int, float> > adj3 = graph.adjacent(3);

  for (forward_iterator<weighted_edge<int, float> > it = adj12.begin(); it != adj12.end(); ++it)
  {
    cout << (*it).to_string() << endl;
  }

  for (forward_iterator<weighted_edge<int, float> > it = adj3.begin(); it != adj3.end(); ++it)
  {
    cout << (*it).to_string() << endl;
  }

  dijkstra dijkstra(graph, 3);
  singly_linked_list<weighted_edge<int, float> > path = dijkstra.path_to(5);

  cout << "dijkstra" << endl;
  for (forward_iterator<weighted_edge<int, float> > it = path.begin(); it != path.end(); ++it)
  {
    cout << (*it).to_string() << endl;
  }
}