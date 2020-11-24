#include <stdbool.h>
#include <stdlib.h>

#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct Graph Graph;
typedef struct Edge Edge;

Graph* createGraph(int countEdges, int countVertex, Edge** edges);
bool depthFirstSearch(Graph* graph, int currentVertex, int* vertexState);
bool isConnected(int fromVertex, int toVertex, Graph* graph);
Edge* createEdge(int start, int end, int weight, bool oriented);
bool isCycled(Graph* graph);
int getCountVertex(Graph* graph);
void destroyGraph(Graph* graph);
int getNeighbour(Graph* graph, int vertex);
void printGraphMatrix(Graph* graph);
void deleteEdge(Graph* graph, int start, int end, bool oriented);

#endif