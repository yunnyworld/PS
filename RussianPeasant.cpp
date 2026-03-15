#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mul(ll a, ll b, ll MOD) {
    ll ret = 0;
    while (a) {
        if (a % 2) ret = (ret + b) % MOD;
        a = a / 2;
        b = b * 2 % MOD;
    }
    return ret;
}
/*
러시아 농부 알고리즘
- 큰 수 곱셈을 overflow가 안나게 할 수 있다.
*/
