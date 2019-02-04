#include <iostream>
#include "file_layer.cpp"
#include "dijsktra.h"
using namespace std;

void display_edge(weighted_edge<int, float> edge)
{
  cout << edge.from << " -> " << edge.to << " : " << edge.weight << endl;
}

int main(int argc, char** argv) 
{
  weighted_graph<int, float> graph;

  read_command_line_parameters(argc, argv, graph);

  graph.adjacent(12).iterate(&display_edge);
  graph.adjacent(3).iterate(&display_edge);

  //dijkstra dijkstra(graph, 3);
}