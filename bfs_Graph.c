#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50
 
// This struct represents a directed graph using
// adjacency list representation
struct Graph {
 
    // No. of vertices
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
}*g;
 
// Constructor
struct Graph * Graph_create(int V)
{
    struct Graph* g = malloc(sizeof(struct Graph));
    g->V = V;
 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
 
    return g;
}
 
// Destructor
void Graph_destroy(struct Graph* g) { free(g); }
 
// Function to add an edge to graph
void Graph_addMatrix(struct Graph* g, int v, int w)
{
    // Add w to v’s     list.
    printf("\nenter the adjacency matrix of [%d][%d]\n",v,w);
    for (int i = 0; i < v; i++)
    {   
        for (int j = 0; j < w; j++)
        {   
            scanf("%d",g->adj[i][j]);
        }
        
    }
    
}
 
// Prints BFS traversal from a given source s
void Graph_BFS(struct Graph* g, int s)
{
    // Mark all the vertices as not visited
    int visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }
 
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    // Mark the current node as visited and enqueue it
    visited[s] = 1;
    queue[rear++] = s;
 
    while (front != rear) {
 
        // Dequeue a vertex from queue and print it
        s = queue[front++];
        printf("%d ", s);
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V; adjacent++) {
            if (g->adj[s][adjacent]==1 && visited[adjacent]==0) {
                visited[adjacent] = 1;
                queue[rear++] = adjacent;
            }
        }
    }
}
 
// Driver code
int main()
{
    // Create a graph
    int a[2][2]={{1,2},{2,3}};
    
 
    printf("Following is Breadth First Traversal "
        "(starting from vertex 2) \n");
    Graph_addMatrix(g,3,3);
    Graph_BFS(g, 2);
    Graph_destroy(g);
 
    return 0;
}