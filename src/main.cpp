#include <iostream>
#include "file_layer.cpp"
#include "dijsktra.h"
using namespace std;

void show_paths(weighted_digraph<int, float> graph, int from, singly_linked_list<int> to)
{
  dijkstra dijkstra(graph, from);

  for (forward_iterator<int> it = to.begin(); it != to.end(); ++it)
  {
    if (from != *it && dijkstra.has_path_to(*it))
    {
      singly_linked_list<weighted_directed_edge<int, float> > path = dijkstra.path_to(*it);

      cout << "Path from " << from << " to " << *it << " with weight " << dijkstra.distance_to(*it) << endl;
      for (forward_iterator<weighted_directed_edge<int, float> > it = path.begin(); it != path.end(); ++it)
      { 
        cout << (*it).to_string() << endl;
      }
    }
  }
}

int main(int argc, char** argv) 
{
  weighted_digraph<int, float> graph;

  read_command_line_parameters(argc, argv, graph);

  singly_linked_list<int> vertices = graph.vertices();
  for (forward_iterator<int> it = vertices.begin(); it != vertices.end(); ++it)
  {
    show_paths(graph, *it, vertices);
  }
}