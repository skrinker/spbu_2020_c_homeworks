#include "../library/graph/graph.h"
#include <stdio.h>

void destroyIncidenceMatrix(int** incidenceMatrix, int numberOfEdges, int numberOfVertex)
{
    for (int i = 0; i < numberOfVertex; ++i) {
        free(incidenceMatrix[i]);
    }
    free(incidenceMatrix);
}

void destroyEdgesArray(Edge** edges, int size)
{
    for (int i = 0; i < size; ++i) {
        free(edges[i]);
    }
    free(edges);
}

void incidenceMatrixToEdgesArray(Edge** edges, int** incedenceMatrix, int numberOfEdges, int numberOfVetrex)
{
    int start = -1;
    int end = 1;
    for (int i = 0; i < numberOfEdges; ++i) {
        for (int j = 0; j < numberOfVetrex; ++j) {
            if (incedenceMatrix[j][i] == -1)
                end = j;
            if (incedenceMatrix[j][i] == 1)
                start = j;
        }
        edges[i] = createEdge(start, end, 1, true);
    }
}

int main()
{
    int numberOfEdges = 0;
    int numberOfVertex = 0;

    printf("Number of edges: ");
    scanf("%d", &numberOfEdges);

    printf("Number of vertex: ");
    scanf("%d", &numberOfVertex);

    int** incidenceMatrix = malloc(sizeof(int*) * numberOfVertex);
    for (int i = 0; i < numberOfVertex; ++i) {
        incidenceMatrix[i] = malloc(sizeof(int) * numberOfEdges);
        memset(incidenceMatrix[i], 0, sizeof(int) * numberOfEdges);
    }

    printf("Input incidence matrix pf graph: \n");
    for (int i = 0; i < numberOfVertex; ++i) {
        for (int j = 0; j < numberOfEdges; ++j) {
            scanf("%d", &incidenceMatrix[i][j]);
        }
    }

    Edge** edges = malloc(sizeof(Edge*) * numberOfEdges);

    incidenceMatrixToEdgesArray(edges, incidenceMatrix, numberOfEdges, numberOfVertex);

    Graph* graph = createGraph(numberOfEdges, numberOfVertex, edges);

    for (int i = 0; i < numberOfVertex; ++i) {
        printf("From vertex %d unavailable: \n", i);
        int* used = malloc(sizeof(int) * getCountVertex(graph));
        memset(used, 0, sizeof(int) * getCountVertex(graph));
        depthFirstSearch(graph, i, used);
        for (int j = 0; j < getCountVertex(graph); ++j) {
            if (used[j] != 2 && j != i) {
                printf("%d ", j);
            }
        }
        printf("\n");
        free(used);
    }

    destroyGraph(graph);
    destroyEdgesArray(edges, numberOfEdges);
    destroyIncidenceMatrix(incidenceMatrix, numberOfEdges, numberOfVertex);

    return 0;
}
