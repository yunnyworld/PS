#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct seg{
    int n;
    vector<ll> tree; // 1-based
    seg(int n): n(n), tree(4*(n+1), 0) {}
    void update(int x, int s, int e, int idx, ll val){
        if(e<idx || s>idx) return;
        if(s==e) tree[x]=val;
        else{
            update(x*2, s, (s+e)/2, idx, val);
            update(x*2+1, (s+e)/2+1, e, idx, val);
            tree[x]=tree[x*2]+tree[x*2+1];
        }
    }
    ll query(int x, int s, int e, int l, int r){
        if(s>r || e<l) return 0ll;
        if(l<=s && e<=r) return tree[x];
        ll L=query(x*2, s, (s+e)/2, l, r);
        ll R=query(x*2+1, (s+e)/2+1, e, l, r);
        return L+R;
    }
};
