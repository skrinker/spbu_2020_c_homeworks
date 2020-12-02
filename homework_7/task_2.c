#include "../library/IO/io.h"
#include "../library/graph/graph.h"
#include "../library/list/list.h"
#include <stdio.h>

void getRoadsFromFile(FILE* inputFile, Edge** edges, int numberOfRoads)
{
    for (int k = 0; k < numberOfRoads; ++k) {
        int i = 0;
        int j = 0;
        int length = 0;

        i = readNumberFromFile((FILE*)inputFile);
        j = readNumberFromFile((FILE*)inputFile);
        length = readNumberFromFile((FILE*)inputFile);

        edges[k] = createEdge(i - 1, j - 1, length, false);
    }
}

void getCapitalsFromFile(FILE* inputFile, List** agglomerations, int numberOfCapitals, bool* used)
{
    for (int i = 0; i < numberOfCapitals; ++i) {
        int numberOfCapital = 0;
        numberOfCapital = readNumberFromFile((FILE*)inputFile);
        push(agglomerations[i], numberOfCapital - 1);
        used[numberOfCapital - 1] = true;
    }
}

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

void printAgglomerationsInformation(List** agglomerations, int numberOfCapitals)
{
    for (int i = 0; i < numberOfCapitals; ++i) {
        printf("agglomeration: %d, ", i + 1);
        printResults(agglomerations[i], numberOfCapitals);
        deleteList(agglomerations[i]);
    }
}

bool addCityToAgglomeration(List* agglomeration, Graph* graph, bool* used)
{
    int minimumLength = -1;
    int currentLength = 0;
    int addedCity = -1;
    int currentCity = 0;

    for (int j = 0; j < getSize(agglomeration); ++j) {
        currentCity = retrieve(j, agglomeration);
        addedCity = getNeighbour(graph, currentCity);
        if (addedCity == -1 || used[addedCity])
            continue;
        currentLength = getWeight(graph, currentCity, addedCity);
        if (currentLength < minimumLength || minimumLength == -1)
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

    return (minimumLength == -1) ? false : true;
}

void addCitiesToAgglomerations(int usedCities, int numberOfCapitals, int numberOfCities, List** agglomerations, bool* used, Graph* graph)
{
    while (usedCities < numberOfCities) {
        for (int i = 0; i < numberOfCapitals; ++i) {
            if (addCityToAgglomeration(agglomerations[i], graph, used)) {
                ++usedCities;
            }
        }
    }
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
    getRoadsFromFile(inputFile, edges, numberOfRoads);

    Graph* graph = createGraph(numberOfRoads, numberOfCities, edges);

    int numberOfCapitals = 0;
    numberOfCapitals = readNumberFromFile((FILE*)inputFile);

    List** agglomerations = (List**)malloc(sizeof(List*) * numberOfCapitals);
    for (int i = 0; i < numberOfCapitals; ++i) {
        agglomerations[i] = createList();
    }

    bool* used = (bool*)malloc(sizeof(bool) * numberOfCities);
    memset(used, false, sizeof(bool) * numberOfCities);

    getCapitalsFromFile(inputFile, agglomerations, numberOfCapitals, used);

    int usedCities = numberOfCapitals;

    addCitiesToAgglomerations(usedCities, numberOfCapitals, numberOfCities, agglomerations, used, graph);

    printAgglomerationsInformation(agglomerations, numberOfCapitals);

    free(agglomerations);
    free(used);
    destroyGraph(graph);
    destroyEdgesArray(edges, numberOfRoads);
    fclose(inputFile);

    return 0;
}