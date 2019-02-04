#include <algorithm>
#include <sstream>
#include <string.h>
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

void read_command_line_parameters(int argc, char** argv, weighted_graph<int, float>& graph)
{
  for (int i = 1; i < argc; i+=2)
  {
    if (!strcmp(argv[i], "-g")) {
      graph = read_graph_from_file(argv[i + 1]);
    }
  }
}