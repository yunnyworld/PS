#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
using namespace std;

/*
reference: https://lem0nad3.tistory.com/130?category=1076804
*/
bool cmp(pll a, pll b) // CCW order in [-90, 270) degrees
{
	if ((a.X < 0) != (b.X < 0)) return a.X > b.X; // split half-planes by y-axis (right first)
	if (a.X == 0 && b.X == 0) return a.Y < b.Y; // both on y-axis
	return a.Y * b.X < b.Y * a.X; // compare slopes (same half-plane)
}
