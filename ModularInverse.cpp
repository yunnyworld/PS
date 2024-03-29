#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MOD = 998244353;
/*
Modular Inverse(모듈러 역원)
Reference: https://seastar105.tistory.com/65
*/
/*
1. 확장 유클리드 알고리즘 이용

a의 M에 대한 모듈러 곱셈 역원 a^(-1) (mod M)을 구해보자

ax = 1 (mod M)
ax = Mk + 1
ax + My = 1 (y = -k)
단, gcd(a, M) = 1인 경우에만, 확장 유클리드 알고리즘을 사용 가능하다.
a^(-1) = x
	   = get<ext_gcd(a, M)>(1);
*/
ll mod(ll a, ll b)
{
	return (a % b >= 0 ? a : a + b);
}

tuple<ll, ll, ll> ext_gcd(ll a, ll b)
{
	if (b == 0) return { a, 1LL, 0LL };
	auto [g, x, y] = ext_gcd(b, a % b);
	return { g, y, x - a / b * y };
}

ll modInv(ll a) // 보장된 것이 아니니 조심해서 사용하자
{
	return mod(get<1>(ext_gcd(a, MOD)), MOD);
}

/*
2. 페르마 소정리 이용

a의 M에 대한 모듈러 곱셈 역원 a^(-1) (mod M)을 구해보자

1 = a^M (mod M)
a = a^(M-1) (mod M)
a^(-1) = a^(M-2) (mod M)
단, 페르마 소정리는 M이 소수인 경우에만 사용 가능하다.
*/

ll pow(ll a, ll x)
{
	if (x == 0) return 1ll;
	ll ret = pow(a, x / 2);
	ret = ret * ret % MOD;
	if (x % 2) ret = ret * a % MOD;
	return ret;
}

ll modInv2(ll a)
{
	return pow(a, MOD-2);
}
