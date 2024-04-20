#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn (int)1e5+10

typedef struct Vector{
    int size, *arr, arr_size;
}vector;
void init(vector* v){
    v->arr = (int*) malloc(sizeof(int));
    v->arr_size = 1;
    v->size = 0;
}
void push(vector* v, int x){
    v->arr[v->size++] = x;
    if (v->size == v->arr_size){
        v->arr_size *= 2;
        int *tmp = (int*) malloc(sizeof(int) * v->arr_size);
        for (int i=0;i<v->size;++i) tmp[i] = v->arr[i];
        free(v->arr);
        v->arr = tmp;
    }
}

vector adj[maxn], inv[maxn], sadj[maxn];
int order[maxn], cnt = 0, bl[maxn], scccnt = 0, indeg[maxn], dis[maxn];
bool vis[maxn];
void dfs1(int x){
    vis[x] = true;
    for (int i=0;i<adj[x].size;++i){
        if (!vis[adj[x].arr[i]]){
            dfs1(adj[x].arr[i]);
        }
    }
    order[++cnt] = x;
}
void dfs2(int x){
    bl[x] = scccnt;
    for (int i=0;i<inv[x].size;++i){
        if (!bl[inv[x].arr[i]]){
            dfs2(inv[x].arr[i]);
        }
    }
}

int main(){
    int n, m, mode;

    scanf("%d%d%d", &n, &m, &mode);
    for (int i=1;i<=n;++i){
        init(adj+i);
        init(inv+i);
    }
    while (m--){
        int u, v;
        scanf("%d%d", &u, &v);
        push(adj+u, v);
        push(inv+v, u);
    }
    for (int i=1;i<=n;++i) if (!vis[i]) dfs1(i);
    for (int i=n;i;--i) if (!bl[order[i]]){
        ++scccnt;
        dfs2(order[i]);
    }
    printf("%d\n", scccnt);

    if (mode == 1) return 0;

    for (int i=1;i<=scccnt;++i) {init(sadj+i); vis[i] = false;}
    for (int i=1;i<=n;++i) for (int j=0;j<adj[i].size;++j) if (bl[i] != bl[adj[i].arr[j]]){
        push(sadj + bl[i], bl[adj[i].arr[j]]);
        ++indeg[bl[adj[i].arr[j]]];
    }
    vector queue;
    init(&queue);
    for (int i=1;i<=scccnt;++i) if (!indeg[i]) {push(&queue, i); dis[i] = 1;}
    int id = 0;
    while (id <= queue.size){
        int x = queue.arr[id++];
        if (dis[x] == scccnt){
            printf("1\n");
            return 0;
        }
        
        for (int i=0;i<sadj[x].size;++i){
            if (!--indeg[sadj[x].arr[i]]) push(&queue, sadj[x].arr[i]);
            dis[sadj[x].arr[i]] = dis[x] >= dis[sadj[x].arr[i]] ? dis[x] + 1 : dis[sadj[x].arr[i]];
        }
    }
    printf("0\n");
}
