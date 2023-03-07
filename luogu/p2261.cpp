#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


int main()
{
   LOCAL();

   LL n, k;
   cin >> n >> k;
   LL ans = n * k;
   for (LL l = 1,r; l <= n;l=r+1)
   {
      LL t = k / l;
      if(t==0)
      {
         r = n;
      }
      else
      {
         r = min(k / t, n);
      }
      ans -= t * (r - l + 1) * (l + r) / 2LL;
   }
   cout << ans;
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