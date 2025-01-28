#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 200000

typedef struct {
    int first, second;
} ii;

typedef struct {
    ii *edges;
    int size, capacity;
} vii;

vii g[MAX + 1];
int visitado[MAX + 1];
int n, m;

void init_vii(vii *v) {
    v->size = 0;
    v->capacity = 10;
    v->edges = (ii *)malloc(v->capacity * sizeof(ii));
}

void push_back(vii *v, int first, int second) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->edges = (ii *)realloc(v->edges, v->capacity * sizeof(ii));
    }
    v->edges[v->size].first = first;
    v->edges[v->size].second = second;
    v->size++;
}

void clear_vii(vii *v) {
    v->size = 0;
}

int compare(const void *a, const void *b) {
    return ((ii *)a)->first - ((ii *)b)->first;
}

long long prim(int s) {
    long long cost = 0;
    for (int i = 0; i <= n; i++) visitado[i] = 0;

    int heap[MAX], h_size = 0;
    ii dist[MAX];
    for (int i = 0; i < MAX; i++) dist[i].first = INT_MAX, dist[i].second = -1;

    for (int i = 0; i < g[s].size; i++) {
        dist[g[s].edges[i].first] = g[s].edges[i];
        heap[h_size++] = g[s].edges[i].first;
    }
    visitado[s] = 1;
    
    while (h_size) {
        qsort(heap, h_size, sizeof(int), compare);
        int u = heap[0];
        heap[0] = heap[--h_size];
        
        if (!visitado[dist[u].second]) {
            cost += dist[u].first;
            visitado[dist[u].second] = 1;
            for (int i = 0; i < g[dist[u].second].size; i++) {
                if (!visitado[g[dist[u].second].edges[i].first]) {
                    heap[h_size++] = g[dist[u].second].edges[i].first;
                    dist[g[dist[u].second].edges[i].first] = g[dist[u].second].edges[i];
                }
            }
        }
    }
    return cost;
}

int main() {
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        for (int i = 0; i <= m; i++) {
            clear_vii(&g[i]);
        }
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            push_back(&g[x], y, z);
            push_back(&g[y], x, z);
            total += z;
        }
        printf("%lld\n", total - prim(0));
    }
    return 0;
}
