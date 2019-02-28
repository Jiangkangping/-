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
#define mod 998244353
#define maxn 400100
ll fpow(ll x, ll a)
{
    ll ret = 1;
    for( ; a; a >>= 1, x = x * x % mod)
        if(a & 1)
            ret = ret * x % mod;
    return ret;
}
ll ni(ll x)
{
    return fpow(x, mod - 2);
}
struct fft_t
{
    int n;
    ll r[maxn], rt[2][maxn];
    void init(int _n)
    {
        n = 1;
        while(n <= _n)
            n <<= 1;
        for(int i = 1; i < n; i <<= 1)
            for(int j = 0; j < i; j ++)
                r[i + j] = r[j] + n / i / 2;
        for(int i = 1; i < n; i <<= 1)
        {
            rt[0][i] = fpow(3, mod / i / 2);
            rt[1][i] = ni(rt[0][i]);
        }
    }
    void work(ll a[], bool tp)
    {
        open(i, 0, n)
            if(r[i] > i)
                swap(a[i], a[r[i]]);
        for(int i = 1; i < n; i <<= 1)
        {
            ll ns = rt[tp][i];
            for(int j = 0; j < n; j += i << 1)
            {
                ll n1 = 1;
                for(int k = 0; k < i; k ++)
                {
                    ll u = a[j + k], t = a[i + j + k] * n1 % mod;
                    a[j + k] = (u + t) % mod;
                    a[i + j + k] = (u - t + mod) % mod;
                    n1 = n1 * ns % mod;
                }
            }
        }
        if(tp)
        {
            ll nn = ni(n);
            open(i, 0, n)
                a[i] = a[i] * nn % mod;
        }
    }
} fft;
int n, m;
ll a[maxn], b[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    __init();
    cin >> n >> m;
    enum(i, 0, n)
        cin >> a[i];
    enum(i, 0, m)
        cin >> b[i];
    m = n + m + 1;
    fft.init(m);
    n = fft.n;
    fft.work(a, 0);
    fft.work(b, 0);
    open(i, 0, n)
        a[i] = a[i] * b[i] % mod;
    fft.work(a, 1);
    open(i, 0, m)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
