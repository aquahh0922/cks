#include "dijkstra.h"

void initGraph(Graph* graph, int V) 
{
    int i;
    graph->V = V;
    for ( i = 0; i < V; i++) {
        graph->adj[i].size = 0;
    }
}

void addEdge(Graph* graph, int u, int v, int weight) 
{
    Edge e1;
    Edge e2;
    e1.dest = v;
    e1.weight = weight;
    e2.dest = u;
    e2.weight = weight;
    graph->adj[u].edges[graph->adj[u].size++] = e1;
    graph->adj[v].edges[graph->adj[v].size++] = e2;

}
void heapInsert(HeapNode heap[], int* heapSize, int vertex, int distance) {
    int i = (*heapSize)++;
    heap[i].vertex = vertex;
    heap[i].distance = distance;
    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        HeapNode temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

HeapNode heapExtractMin(HeapNode heap[], int* heapSize) {
    HeapNode min = heap[0],temp;
    int i = 0,left,right, smallest;
    heap[0] = heap[--(*heapSize)];
    while (1) {
        left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < *heapSize && heap[left].distance < heap[smallest].distance)
            smallest = left;
        if (right < *heapSize && heap[right].distance < heap[smallest].distance)
            smallest = right;
        if (smallest == i) break;
        temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
    return min;
}

int dijkstra(Graph* graph, int start, int end, int* prev) {
    int V = graph->V;
    int dist[MAX_V];
    int i,heapSize,u,v;
    HeapNode heap[MAX_V * 2];
    unsigned char count=0;
    for ( i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[start] = 0;

    
    heapSize = 0;
    heapInsert(heap, &heapSize, start, 0);

    while (heapSize > 0) {
        HeapNode node = heapExtractMin(heap, &heapSize);
        u = node.vertex;

        if (u == end) break;
        if (node.distance > dist[u]) continue;

        for ( i = 0; i < graph->adj[u].size; i++) {
            Edge e = graph->adj[u].edges[i];
            v = e.dest;
            if (dist[u] != INT_MAX && dist[u] + e.weight < dist[v]) {
                dist[v] = dist[u] + e.weight;
                prev[v] = u;
                heapInsert(heap, &heapSize, v, dist[v]);
            }
        }
    }

    return dist[end];
}