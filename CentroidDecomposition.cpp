#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[200005];
int sz[200005];
bool exclude[200005];

int get_sz(int x, int p){
    sz[x]=1;
    for(auto [y, c]:g[x]){
        if(y!=p && !exclude[y]){
            sz[x]+=get_sz(y, x);
        }
    }
    return sz[x];
}

int centroid(int x, int p, int lim){ // lim = |tree| / 2
    for(auto [y, c]:g[x]){
        if(y!=p && sz[y]>lim && !exclude[y]){
            return centroid(y, x, lim);
        }
    }
    return x;
}

void dnc(int x){ // 현재 x번 노드를 포함하는 서브트리에서 문제를 해결
    // (1) x에 '현재 서브트리의 centroid를 구해서 대입
    int tot=get_sz(x, -1);
    x=centroid(x, -1, tot/2);
    
    // (2) x를 지나는 모든 경로에 대해 계산

    // (3) x를 트리에서 제거, x와 인접한 모든 노드 y에 대해서 dnc(y) 호출
    exclude[x]=true;
    for(auto [y, c]:g[x]){
        if(!exclude[y]){
            dnc(y);
        }
    }
}
