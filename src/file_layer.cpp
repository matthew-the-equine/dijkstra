#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include "weighted_graph.h"
using namespace std;

weighted_graph<int, float> read_graph_from_file(const char *file_name)
{
  weighted_graph<int, float> graph = weighted_graph<int, float>();

  ifstream file(file_name);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      replace(line.begin(), line.end(), '-', ' ');
      replace(line.begin(), line.end(), '>', ' ');
      replace(line.begin(), line.end(), ':', ' ');
      istringstream iss(line);

      int from, to;
      float weight;
      iss >> from >> to >> weight;
      graph.add_edge(weighted_edge<int, float>(from, to, weight));
    }
  }

  return graph;
}