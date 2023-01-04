#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
   LL n;
   cin >> n;
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
      LL x;
      cin >> x;
      a[x] = i;
   }
   LL l, r, ans = 1;
   l = r = a[0];
   for (LL i = 2; i <= n;i++)
   {
      LL u = i - 1 >> 1;
      l = min(l, a[u]), r = max(r, a[u]);
      LL mins = max(0LL,r-i+1), maxs = min(l,n-i);
      ans += max(0LL, maxs - mins + 1);
   }
   cout << ans << endl;
   return;
}


int main()
{
   LOCAL();


   LL t;
   cin >> t;
   while(t--)
   {
       solve();
   }
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