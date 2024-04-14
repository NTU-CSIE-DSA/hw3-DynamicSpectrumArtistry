#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100001

typedef struct LinkListNode{
    int value;
    struct LinkListNode *next;
}LLN;

typedef struct GraphNode{
    int color;
    LLN *head;
    LLN *tail;
}GN;

GN Graph[MAX_VERTICES];         // index = vertex number
GN ReverseGraph[MAX_VERTICES];  // index = vertex number
GN SCCGraph[MAX_VERTICES];      // index = color
bool visited[MAX_VERTICES] = {0};
LLN *stack = NULL;
LLN *new_stack = NULL;
int current_color = 0;

void InitGraph(){
    for(int i = 1; i <= MAX_VERTICES; i++){
        Graph[i].color = -1;
        Graph[i].head = NULL;
        Graph[i].tail = NULL;
        ReverseGraph[i].color = -1;
        ReverseGraph[i].head = NULL;
        ReverseGraph[i].tail = NULL;
        SCCGraph[i].color = i;
        SCCGraph[i].head = NULL;
        SCCGraph[i].tail = NULL;
    }
    return;
}

LLN *InitNode(int value, LLN *next){
    LLN *tmp_node = (LLN *)malloc(sizeof(LLN));
    tmp_node->value = value;
    tmp_node->next = next;
    return tmp_node;
}

void AddEdge(int start, int end, GN *graph){
    // Add edge in Graph
    LLN *tmp_node = InitNode(end, NULL);
    if(graph[start].head == NULL){
        graph[start].head = tmp_node;
        graph[start].tail = tmp_node;
    }
    else{
        graph[start].tail->next = tmp_node;
        graph[start].tail = tmp_node;
    }
    return;
}

LLN *PushStack(int n, LLN *stack){
    LLN *tmp_node = InitNode(n, NULL);
    if(stack == NULL) stack = tmp_node;
    else{
        tmp_node->next = stack;
        stack = tmp_node;
    }
    return stack;
}

void DFS1(int n, GN *graph){
    visited[n] = 1;
    LLN *curr = graph[n].head;
    while(curr != NULL){
        if(visited[curr->value] == 0) DFS1(curr->value, graph);
        curr = curr->next;
    }
    stack = PushStack(n, stack);
    return;
}

void DFS2(int n){
    visited[n] = 1;
    Graph[n].color = current_color;
    LLN * curr = ReverseGraph[n].head;
    while(curr != NULL){
        if(visited[curr->value] == 0) DFS2(curr->value);
        curr = curr->next;
    }
    return;
}

int main(){
    int V, E, mode;
    scanf("%d%d%d", &V, &E, &mode);
    // Intialize Graph and ReverseGraph
    InitGraph();
    // Read edge and add into graph and reverse graph
    int start, end;
    for(int i = 0; i < E; i++){
        scanf("%d%d", &start, &end);
        AddEdge(start, end, Graph);
        AddEdge(end, start, ReverseGraph);
    }
    // First Traversal (forward)
    for(int i = 1; i <= V; i++){
        if(visited[i] == 0) DFS1(i, Graph);
    }
    memset(visited, 0, sizeof(visited));
    // Second Traversal (backward)
    LLN *curr = stack;
    while(curr != NULL){
        int n = curr->value;
        if(visited[n] == 0){
            DFS2(n);
            current_color += 1;
        }
        curr = curr->next;
    }
    /* Debug for checking color of each node
    for(int i = 1; i <= V; i++){
        printf("The color of %d is %d\n", i, Graph[i].color);
    }
    */

    if(mode == 1) printf("%d\n", current_color);
    else printf("%d\n0\n", current_color);
    return 0;
}
