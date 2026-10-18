#include "garden.h"
#include <cstdio>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <cstdlib>

using namespace std;

static int N, M;
static int query_count = 0;
static int MAX_QUERIES = 4000;

static vector<tuple<int, int, int, int>> edges;
static vector<int> parent;

static int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

int askInw(string S){
    if(++query_count > MAX_QUERIES){
        printf("-1\n");
        exit(-1);
    }
    if((int)S.size() != M){
        printf("-1\n");
        exit(-1);
    }
    iota(parent.begin(), parent.end(), 0);
    int total_weight = 0;
    for(auto [w, u, v, i] : edges){
        if (S[i] != '1') continue;
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv) continue;
        total_weight += w;
        parent[pu] = pv;
    }
    return total_weight;
}

static int validate_mst(){
    iota(parent.begin(), parent.end(), 0);
    int total_weight = 0;
    for(auto [w, u, v, i] : edges){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv) continue;
        total_weight += w;
        parent[pu] = pv;
    }
    return total_weight;
}

int main() {
    if(scanf("%d %d", &N, &M) != 2 || N <= 0){
        printf("-1\n");
        exit(-1);
    }

    parent.resize(N);

    for(int i = 0; i < M; ++i){
        int u, v, w;
        if(scanf("%d %d %d", &u, &v, &w) != 3 || u < 0 || u >= N || v < 0 || v >= N || w < 0){
            printf("-1\n");
            exit(-1);
        }
        edges.emplace_back(w, u, v, i);
    }

    sort(edges.begin(), edges.end(), greater<>());

    if(N<=100)MAX_QUERIES=2000;
    
    int result = findMinimumTime(N, M);

    reverse(edges.begin(), edges.end());
    int expected = validate_mst();

    if(result == expected){
        printf("%d", query_count);
    }
    else{
        printf("-1\n");
    }
    printf("SKIBIDI_aoiqrjgoihdgva");
    return 0;
}
