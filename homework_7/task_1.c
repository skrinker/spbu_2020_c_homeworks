#include "../library/graph/graph.h"
#include <stdio.h>
#include <string.h>

void destroyEdgesArray(Edge** edges, int size)
{
    for (int i = 0; i < size; ++i) {
        free(edges[i]);
    }
    free(edges);
}

void printResults(Graph* graph)
{
    printf("results: <studentNumber> <originalWork>: \n");
    for (int i = 0; i < 3; ++i) {
        int* used = malloc(sizeof(int) * getCountVertex(graph));
        memset(used, 0, sizeof(int) * getCountVertex(graph));
        depthFirstSearch(graph, i, used);
        for (int j = 0; j < getCountVertex(graph); ++j) {
            if (used[j] == 2) {
                printf("%d \t %d \n", j + 1, i + 1);
            }
        }
        free(used);
    }
}

void inputResults(Edge** edges, int numberOfStudents, int* nonEmptyWorks)
{
    printf("input %d times: <studentNumber> <plagiarizedWork> \n", numberOfStudents);
    for (int i = 0; i < numberOfStudents; ++i) {
        int studentNumber = 0;
        int plagiarizedWork = 0;
        scanf("%d %d", &studentNumber, &plagiarizedWork);
        if (plagiarizedWork != -1) {
            edges[i] = createEdge(plagiarizedWork - 1, studentNumber - 1, 1, true);
            ++(*nonEmptyWorks);
        }
    }
}

int inputNumberOfStudents()
{
    printf("Input number of students: ");
    int numberOfStudents = 0;
    scanf("%d", &numberOfStudents);

    while (numberOfStudents < 3) {
        printf("Error, value should be more than 3 \n");
        printf("Input number of students: ");
        scanf("%d", &numberOfStudents);
    }
    return numberOfStudents;
}

int main()
{
    int numberOfStudents = inputNumberOfStudents();
    int nonEmptyWorks = 0;
    Edge** edges = malloc(sizeof(Edge*) * numberOfStudents);
    inputResults(edges, numberOfStudents, &nonEmptyWorks);

    Graph* graph = createGraph(nonEmptyWorks, nonEmptyWorks, edges);
    printResults(graph);

    destroyGraph(graph);
    destroyEdgesArray(edges, numberOfStudents);

    return 0;
}