#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct lazySeg{
    int n;
    vector<ll> tree, lazy; // 1-based
    lazySeg(int n): n(n), tree(4*(n+1), 0), lazy(4*(n+1), 0) {}
    void propagate(int x, int s, int e){
        if(lazy[x]!=0){
            tree[x]+=lazy[x]*(e-s+1);
            if(s!=e){
                lazy[x*2]+=lazy[x];
                lazy[x*2+1]+=lazy[x];
            }
            lazy[x]=0;
        }
    }
    void update(int x, int s, int e, int l, int r, ll val){
        propagate(x, s, e);
        if(e<l || s>r) return;
        if(l<=s && e<=r){
            lazy[x]+=val;
            propagate(x, s, e);
        }
        else{
            update(x*2, s, (s+e)/2, l, r, val);
            update(x*2+1, (s+e)/2+1, e, l, r, val);
            tree[x]=tree[x*2]+tree[x*2+1];
        }
    }
    ll query(int x, int s, int e, int l, int r){
        propagate(x, s, e);
        if(s>r || e<l) return 0ll;
        if(l<=s && e<=r) return tree[x];
        ll L=query(x*2, s, (s+e)/2, l, r);
        ll R=query(x*2+1, (s+e)/2+1, e, l, r);
        return L+R;
    }
};
