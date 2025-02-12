#include <stdio.h>
#include <stdlib.h>

#define ll long long int

typedef struct {
    ll u, v, w;
} Edge;

ll *id, *sz;

ll find(ll x) {
    if (id[x] == x) return x;
    return id[x] = find(id[x]);
}

void unionn(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (sz[x] > sz[y]) {
        ll temp = x;
        x = y;
        y = temp;
    }
    id[x] = y;
    sz[y] += sz[x];
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    ll m, n;
    while (1) {
        scanf("%lld %lld", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }
        
        id = (ll*)malloc((m+1) * sizeof(ll));
        sz = (ll*)malloc((m+1) * sizeof(ll));
        for (ll i = 0; i <= m; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        
        Edge *grafo = (Edge*)malloc(n * sizeof(Edge));
        ll soma = 0;
        for (ll i = 0; i < n; i++) {
            scanf("%lld %lld %lld", &grafo[i].u, &grafo[i].v, &grafo[i].w);
            soma += grafo[i].w;
        }
        
        qsort(grafo, n, sizeof(Edge), cmp);
        
        ll c = 0;
        for (ll i = 0; i < n; i++) {
            if (find(grafo[i].u) != find(grafo[i].v)) {
                unionn(grafo[i].u, grafo[i].v);
                c += grafo[i].w;
            }
        }
        
        printf("%lld\n", soma - c);
        
        free(id);
        free(sz);
        free(grafo);
    }
    return 0;
}
