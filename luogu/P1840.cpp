#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<LL> fa;
LL find(LL x)
{
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}
inline void solve()
{
    LL n, m;
    cin >> n >> m;
    fa = vector<LL>(n + 2);
    iota(all(fa), 0);
    LL res = n;
    while(m--)
    {
        LL l, r;
         cin >> l >> r;
        LL lfa = find(l);
        while(lfa<=r)
        {
            fa[lfa] = find(fa[lfa + 1]);
            lfa = find(lfa);
            res--;
        }
        cout << res << endl;
    }

    return;
}


int main()
{
     LOCAL();
     solve();
     return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
