#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<bool, bool> pbb;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define enum(i, j, k) for(int i = j; i <= k; i ++)
#define open(i, j, k)  for(int i = j; i <  k; i ++)
#define dec(i, j, k)  for(int i = j; i >= k; i --)
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
template <class T> bool chkmin(T &x, T y)
{ return y < x ? x = y , true : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? x = y , true : false; }
void __init()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(16);
    srand(time(0) ^ ui(ul(new char)));
}
/* default code ends here */