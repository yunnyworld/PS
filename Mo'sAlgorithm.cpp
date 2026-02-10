#include <bits/stdc++.h>
using namespace std;

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator < (Query& x) {
        if (s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
        return e < x.e;
    }
};

void Plus() {

}
void Minus() {

}
