#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
void PrimeFactorization(int n)
{
    for(int p=2;p*p<=100000;p++)
        while(n%p==0) n/=p;
}
