#include "index_min_priority_queue.h"
#include <map>
#include <iostream>
using namespace std;

class dijkstra
{
private:
  map<int, weighted_edge<int, float> > edge_to;
  map<int, float> dist_to;
  index_min_priority_queue<float> pq;

  void relax(weighted_graph<int, float>, int);

public:
  dijkstra(weighted_graph<int, float>, int);

  singly_linked_list<weighted_edge<int, float> > path_to(int);
};

dijkstra::dijkstra(weighted_graph<int, float> graph, int source) :
  edge_to(map<int, weighted_edge<int, float> >()),
  dist_to(map<int, float>()),
  pq(index_min_priority_queue<float>(graph.vertices().size)) 
{
  singly_linked_list<int> vertices = graph.vertices();
  for (forward_iterator<int> it = vertices.begin(); it != vertices.end(); ++it)
  {
    dist_to[*it] = __FLT_MAX__;
  }

  dist_to[source] = 0.0f;
  pq.insert(source, 0.0f);

  while(!pq.is_empty())
  {
    relax(graph, pq.del_min());
  }
}

void dijkstra::relax(weighted_graph<int, float> graph, int vertex)
{ 
  singly_linked_list<weighted_edge<int, float> > adj = graph.adjacent(vertex);

  for (forward_iterator<weighted_edge<int, float> > it = adj.begin(); it != adj.end(); ++it)
  {
    weighted_edge<int, float> edge = (*it);
    int to = edge.to;

    if (dist_to[to] > dist_to[vertex] + edge.weight)
    {
      dist_to[to] = dist_to[vertex] + edge.weight;
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

singly_linked_list<weighted_edge<int, float> > dijkstra::path_to(int)
{
  singly_linked_list<weighted_edge<int, float> > edges = singly_linked_list<weighted_edge<int, float> >();
  for (typename map<int, weighted_edge<int, float> >::iterator it = edge_to.begin(); it != edge_to.end(); ++it)
  {
    edges.push(it->second);
  }
  return edges;
}