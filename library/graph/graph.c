#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int start;
    int end;
    int weight;
    bool oriented;
};

struct Graph {
    int** matrix;
    int countVertex;
    int countEdges;
};

void printGraphMatrix(Graph* graph)
{
    printf("\n");
    for (int i = 0; i < graph->countVertex; ++i) {
        for (int j = 0; j < graph->countVertex; ++j) {
            printf("%d   ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int getWeight(Graph* graph, int start, int end)
{
    return graph->matrix[start][end];
}

int getNeighbour(Graph* graph, int vertex)
{
    int minimum = -1;
    int minimumIndex = -1;
    for (int i = 0; i < graph->countVertex; ++i) {
        if (graph->matrix[vertex][i] != 0) {
            minimum = graph->matrix[vertex][i];
            minimumIndex = i;
            break;
        }
    }
    for (int i = 0; i < graph->countVertex; ++i) {
        if (graph->matrix[vertex][i] < minimum && graph->matrix[vertex][i] != 0) {
            minimum = graph->matrix[vertex][i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

void deleteEdge(Graph* graph, int start, int end, bool oriented)
{
    graph->matrix[start][end] = 0;
    if (!oriented)
        graph->matrix[end][start] = 0;
}

Edge* createEdge(int start, int end, int weight, bool oriented)
{
    Edge* edge = malloc(sizeof(Edge));
    edge->start = start;
    edge->end = end;
    edge->weight = weight;
    edge->oriented = oriented;
    return edge;
}

Graph* createGraph(int countEdges, int countVertex, Edge** edges)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->countVertex = countVertex;
    graph->countEdges = countEdges;
    graph->matrix = (int**)malloc(countVertex * sizeof(int*));
    for (int i = 0; i < countVertex; ++i) {
        graph->matrix[i] = (int*)malloc(countVertex * sizeof(int));
        memset(graph->matrix[i], 0, countVertex * sizeof(int));
    }
    for (int i = 0; i < countEdges; ++i) {
        if (edges[i] == NULL)
            continue;
        graph->matrix[edges[i]->start][edges[i]->end] = edges[i]->weight;
        if (!edges[i]->oriented) {
            graph->matrix[edges[i]->end][edges[i]->start] = edges[i]->weight;
        }
    }
    return graph;
}

bool isConnected(int fromVertex, int toVertex, Graph* graph)
{
    int* vertexState = (int*)malloc(graph->countVertex * sizeof(int));
    memset(vertexState, 0, graph->countVertex * sizeof(int));
    depthFirstSearch(graph, fromVertex, vertexState);
    return vertexState[toVertex] > 0;
}

bool depthFirstSearch(Graph* graph, int currentVertex, int* vertexState)
{
    vertexState[currentVertex] = 1;
    for (int i = 0; i < graph->countVertex; i++) {
        if (graph->matrix[currentVertex][i] != 0 && i != currentVertex) {
            if (vertexState[i] == 1) {
                return true;
            }
            if (vertexState[i] == 0) {
                if (depthFirstSearch(graph, i, vertexState)) {
                    return true;
                }
            }
        }
    }
    vertexState[currentVertex] = 2;
    return false;
}

bool isCycled(Graph* graph)
{
    int* vertexState = (int*)malloc(graph->countVertex * sizeof(int));
    memset(vertexState, 0, graph->countVertex * sizeof(int));
    for (int i = 0; i < graph->countVertex; ++i) {
        if (vertexState[i] == 0) {
            if (depthFirstSearch(graph, i, vertexState)) {
                return true;
            }
        }
    }
    return false;
}

int getCountVertex(Graph* graph)
{
    return graph->countVertex;
}

void destroyGraph(Graph* graph)
{
    for (int i = 0; i < graph->countVertex; ++i) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}