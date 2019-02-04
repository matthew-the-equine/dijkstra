#include "weighted_graph.h"
#include "index_min_priority_queue.h"
#include <map>
using namespace std;

class dijkstra
{
private:
  map<weighted_edge<int, float>, weighted_edge<int, float>> edge_to;
  map<weighted_edge<int, float>, float> dist_to;
  MinIndexedPQ pq;

  void iterate_edges(int);
  void relax(weighted_graph<int, float>, int);

public:
  dijkstra(weighted_graph<int, float>, int);
};

dijkstra::dijkstra(weighted_graph<int, float> graph, int vertex)
{
  //relax(graph, vertex);
}

void dijkstra::relax(weighted_graph<int, float> graph, int vertex)
{ 
  graph.adjacent(vertex).iterate([](weighted_edge<int, float> edge) -> void {
    // int to = edge.to;
    // if (dist_to[to] > dist_to[vertex] + edge.weight)
    // {
    //   dist_to[to] = dist_to[vertex] + edge.weight
    //   edge_to[to] = edge;

    //   if (pq.contains(to))
    //   {
    //     pq.changeKey(to, dist_to[to]);
    //   }
    //   else
    //   {
    //     pq.increaseKey(to, dist_to[to]);
    //   }
    // }
  });
}