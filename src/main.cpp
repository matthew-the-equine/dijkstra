#include <iostream>
#include "file_layer.cpp"
using namespace std;

void display_edge(weighted_edge<int, float> edge)
{
  cout << edge.from << " -> " << edge.to << " : " << edge.weight << endl;
}

int main() {
  weighted_graph<int, float> graph = read_graph_from_file("notes/graf.txt");

  graph.adjacent(12).iterate(&display_edge);
  graph.adjacent(3).iterate(&display_edge);
}