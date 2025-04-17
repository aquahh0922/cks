#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include"general.h"

#define MAX_V 208
#define MAX_EDGES 4   

typedef struct Edge {
    int dest;
    int weight;
} Edge;

typedef struct AdjList {
    Edge edges[MAX_EDGES];
    int size;
} AdjList;

typedef struct Graph {
    int V;
    AdjList adj[MAX_V];
} Graph;

typedef struct HeapNode {
    int vertex;
    int distance;
} HeapNode;

void initGraph(Graph* graph, int V) ;
void addEdge(Graph* graph, int u, int v, int weight) ;
void heapInsert(HeapNode heap[], int* heapSize, int vertex, int distance) ;
HeapNode heapExtractMin(HeapNode heap[], int* heapSize) ;
int dijkstra(Graph* graph, int start, int end, int* prev) ;
#endif // _DIJKSTRA_H_