#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dest, weight;
};
struct Graph {
	int V, E;
	struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}
void printArr(int dist[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	for (int i = 1; i < V ; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; 
		}
	}
	printArr(dist, V);
	return;
}
int main()
{
	int V, E, src, dest, weight;
    cin >> V >> E;
	struct Graph* graph = createGraph(V, E);
    for(int i = 0; i<E; i++){
        cin >> src >> dest >> weight;
        graph->edge[i].src = src;
	    graph->edge[i].dest = dest;
	    graph->edge[i].weight = weight;
    }
	BellmanFord(graph, 0);
	return 0;
}
