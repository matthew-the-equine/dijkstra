#include "index_min_priority_queue.h"
#include <map>
#include <iostream>
using namespace std;

class dijkstra
{
private:
  map<int, weighted_directed_edge<int, float> > edge_to;
  map<int, float> dist_to;
  index_min_priority_queue<float> pq;

  void relax(weighted_digraph<int, float>, int);

public:
  dijkstra(weighted_digraph<int, float>, int);

  bool has_path_to(int);
  singly_linked_list<weighted_directed_edge<int, float> > path_to(int);
  float distance_to(int);
};

dijkstra::dijkstra(weighted_digraph<int, float> graph, int source) :
  edge_to(map<int, weighted_directed_edge<int, float> >()),
  dist_to(map<int, float>()),
  pq(1000) // hack -> it should be limited to V but vertices are not consecutive numbers, but it will work here as there is changeKey method
{
  singly_linked_list<int> vertices = graph.vertices();
  for (forward_iterator<int> it = vertices.begin(); it != vertices.end(); ++it)
  {
    edge_to[*it];
    dist_to[*it] = __FLT_MAX__;
  }

  dist_to[source] = 0.0f;
  pq.insert(source, 0.0f);

  while(!pq.is_empty())
  {
    relax(graph, pq.del_min());
  }
}

void dijkstra::relax(weighted_digraph<int, float> graph, int from)
{ 
  singly_linked_list<weighted_directed_edge<int, float> > adj = graph.adjacent(from);

  for (forward_iterator<weighted_directed_edge<int, float> > it = adj.begin(); it != adj.end(); ++it)
  {
    weighted_directed_edge<int, float> edge = (*it);
    int to = edge.to;

    if (dist_to[to] > dist_to[from] + edge.weight)
    {
      dist_to[to] = dist_to[from] + edge.weight;
      edge_to[to] = edge;

      if (pq.contains(to))
      {
        pq.changeKey(to, dist_to[to]);
      }
      else
      {
        pq.insert(to, dist_to[to]);
      }
    }
  }
}

bool dijkstra::has_path_to(int vertex)
{
  return dist_to[vertex] < __FLT_MAX__;
}

singly_linked_list<weighted_directed_edge<int, float> > dijkstra::path_to(int vertex)
{
  singly_linked_list<weighted_directed_edge<int, float> > edges = singly_linked_list<weighted_directed_edge<int, float> >();
  for (weighted_directed_edge<int, float> edge = edge_to[vertex]; edge_to.count(edge.from); edge = edge_to[edge.from])
  {
    edges.push(edge);
  }
  return edges;
}

float dijkstra::distance_to(int vertex)
{
  return dist_to[vertex];
}