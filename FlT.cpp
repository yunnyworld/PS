#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Fermat's little Theorem (FlT, 페르마 소정리)

페르마 소정리: p가 소수이고 a, p가 서로소일 때 a^(p-1) = 1 (mod p)
- a^(p-1) = 1 (mod p) 
- a * a^(p-2) = 1 (mod p) 
- a^(-1) = a^(p-2) (mod p) : a^(p-2)는 a의 곱셈 역원이다 

주의사항: 조건을 정확히 충족하는지 확인하고 사용하자.
1. p가 소수
2. a, p가 서로소

보통 분할 정복을 이용한 거듭제곱을 이용해 구현한다.
시간복잡도: O(logp)

추천 문제: boj.kr/20296 (폰친구)
*/
ll f[1000005];

ll pow(ll a, ll n) {
    if (n == 0) return 1ll;
    ll ret = pow(a, n / 2);
    ret = ret * ret % MOD;
    if (n % 2) ret = ret * a % MOD;
    return ret;
}

ll inv(ll a) { 
    return pow(a, MOD - 2); // a^(-1) (mod MOD)
}

ll C(ll n, ll r) {
    ll ret = f[n];
    ret = ret * inv(f[r]) % MOD;
    ret = ret * inv(f[n - r]) % MOD;
    return ret;
}

// 중복조합: 서로 다른 n개에서 순서를 고려하지 않고, 중복을 허용하여 r개를 택하는 경우의 수
ll H(ll n, ll r) {
    return C(n + r - 1, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    f[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        f[i] = f[i - 1] * i % MOD;

    // do something...

    return 0;
}
