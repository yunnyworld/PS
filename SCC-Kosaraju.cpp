#include <bits/stdc++.h>
using namespace std;

struct Kosaraju {
    int n, scc_cnt=0;
    vector<vector<int>> g, g_rev, comp;
    vector<int> visit, order, scc;
    Kosaraju(int n) : n(n), g(n+1), g_rev(n+1), visit(n+1, 0), scc(n+1, 0) {}
    void add_edge(int u, int v){ // vertices: 1..n
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }
    void dfs(int x){
        visit[x]=1;
        for(auto y:g[x])
            if(!visit[y]) dfs(y);
        order.push_back(x);
    }
    void dfs_rev(int x, int c){
        scc[x]=c;
        for(auto y:g_rev[x])
            if(!scc[y]) dfs_rev(y, c);
    }
    // scc[x] = x가 속한 SCC 번호 [1, scc_cnt]
    // 번호는 위상 순서: 모든 간선 u->v에 대해 scc[u] <= scc[v]
    // comp[c] = c번 SCC의 정점 목록
    void get_scc(){
        for(int x=1;x<=n;x++) 
            if(!visit[x]) dfs(x);
        reverse(order.begin(), order.end());
        for(auto x:order) 
            if(!scc[x]) dfs_rev(x, ++scc_cnt);

        comp.assign(scc_cnt+1, {});
        for(int x=1;x<=n;x++)
            comp[scc[x]].push_back(x);
    }
};
