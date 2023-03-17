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

inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n + 1), pre(n + 1), suf(n + 2);
    pre[0] = suf[n + 1] = LLONG_MAX;
    for (LL i = 1; i <= n;i++)
    {
       cin >> a[i];
       pre[i] = pre[i - 1] & ~a[i];
    }
    for (LL i = n; i; i--)
    {
       suf[i] = suf[i + 1] & ~a[i];
    }
    LL ans = -1, pos = 0;
    for (LL i = 1; i <= n;i++)
    {
       LL temp = pre[i - 1] & suf[i + 1] & a[i];
       if (temp> ans)
       {
          ans = temp;
          pos = i;
      }
    }
    cout << a[pos] << ' ';
    for (LL i = 1; i <= n;i++)
    {
      if(i==pos)
          continue;
      cout << a[i] << ' ';
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
