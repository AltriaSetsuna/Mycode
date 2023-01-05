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
   vector<LL> pos(n);
   for (LL i = 0; i < n;i++)
   {
      LL t;
      cin >> t;
      pos[t] = i;
   }
   LL l = pos[0], r = pos[0], ans = 1;
   for (LL len = 2; len <= n;len++)
   {
      LL mex = (len + 1) / 2;
      l = min(l, pos[mex - 1]);
      r = max(r, pos[mex - 1]);
      LL minR = max(r, len - 1);
      LL maxR = min(l + len - 1, n - 1);
      ans += max(0LL, maxR - minR + 1);
      // LL minL = max(0LL, r - len + 1);
      // LL maxL = min(n - len, l);
      // ans += max(0LL, maxL - minL + 1);
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