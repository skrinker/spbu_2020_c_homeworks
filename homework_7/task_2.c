#include "../library/IO/io.h"
#include "../library/graph/graph.h"
#include "../library/list/list.h"
#include <stdio.h>

const int INT_MAX = 2147483647;

void printResults(List* agglomeration, int numberOfCapitals)
{
    ListElement* current = head(agglomeration);
    printf("capital: %d, cities: ", getValue(current) + 1);
    for (int i = 0; i < getSize(agglomeration) - 2; i++) {
        printf("%d, ", getValue(getNext(current)) + 1);
        current = getNext(current);
    }
    printf("%d;\n", getValue(getNext(current)) + 1);
}

void destroyEdgesArray(Edge** edges, int size)
{
    for (int i = 0; i < size; ++i) {
        free(edges[i]);
    }
    free(edges);
}

bool addCityToAgglomeration(List* agglomeration, Graph* graph, bool* used)
{
    int minimumLength = INT_MAX;
    int currentLength = 0;
    int addedCity = -1;
    int currentCity = 0;

    for (int j = 0; j < getSize(agglomeration); ++j) {
        currentCity = retrieve(j, agglomeration);
        addedCity = getNeighbour(graph, currentCity);
        if (addedCity == -1 || used[addedCity])
            continue;
        currentLength = getWeight(graph, currentCity, addedCity);
        if (currentLength < minimumLength)
            minimumLength = currentLength;
    }

    if (addedCity != -1 && used[addedCity]) {
        deleteEdge(graph, currentCity, addedCity, false);
    }

    if (addedCity != -1 && !used[addedCity]) {
        deleteEdge(graph, currentCity, addedCity, false);
        push(agglomeration, addedCity);
        used[addedCity] = true;
    }

    return (minimumLength == INT_MAX) ? false : true;
}

int main()
{
    int numberOfCities = 0;
    int numberOfRoads = 0;

    FILE* inputFile = fopen("./homework_7/input.txt", "re");

    if (inputFile == NULL) {
        printf("Input error");
    }

    numberOfCities = readNumberFromFile((FILE*)inputFile);
    numberOfRoads = readNumberFromFile((FILE*)inputFile);

    Edge** edges = malloc(sizeof(Edge*) * numberOfRoads);

    for (int k = 0; k < numberOfRoads; ++k) {
        int i = 0;
        int j = 0;
        int length = 0;

        i = readNumberFromFile((FILE*)inputFile);
        j = readNumberFromFile((FILE*)inputFile);
        length = readNumberFromFile((FILE*)inputFile);

        edges[k] = createEdge(i - 1, j - 1, length, false);
    }

    Graph* graph = createGraph(numberOfRoads, numberOfCities, edges);

    int numberOfCapitals = 0;
    numberOfCapitals = readNumberFromFile((FILE*)inputFile);

    List** agglomerations = (List**)malloc(sizeof(List*) * numberOfCapitals);
    for (int i = 0; i < numberOfCapitals; ++i) {
        agglomerations[i] = createList();
    }

    bool* used = (bool*)malloc(sizeof(bool) * numberOfCities);
    memset(used, false, sizeof(bool) * numberOfCities);

    for (int i = 0; i < numberOfCapitals; ++i) {
        int numberOfCapital = 0;
        numberOfCapital = readNumberFromFile((FILE*)inputFile);
        push(agglomerations[i], numberOfCapital - 1);
        used[numberOfCapital - 1] = true;
    }

    int usedCities = numberOfCapitals;

    while (usedCities < numberOfCities) {
        for (int i = 0; i < numberOfCapitals; ++i) {
            if (addCityToAgglomeration(agglomerations[i], graph, used)) {
                ++usedCities;
            }
        }
    }

    for (int i = 0; i < numberOfCapitals; ++i) {
        printf("agglomeration: %d, ", i + 1);
        printResults(agglomerations[i], numberOfCapitals);
        deleteList(agglomerations[i]);
    }

    free(agglomerations);
    free(used);
    destroyGraph(graph);
    destroyEdgesArray(edges, numberOfRoads);
    fclose(inputFile);

    return 0;
}