#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 998244353;
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   LL ma = LLONG_MIN, mi = LLONG_MAX;
   vector<LL> h(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> h[i];
       ma = max(ma, h[i]);
       mi = min(mi, h[i]);
   }
   LL hash = ma - mi;
   LL maxn = hash * 2 + 1;
   LL ans = 0;
   vector<vector<LL>> dp(n, vector<LL>(maxn, 0));
   for (LL i = 0; i < n;i++)
   {
       for (LL j = 0; j < i;j++)
       {
           LL d = h[i] - h[j] + hash;
           dp[i][d] = (dp[i][d] + dp[j][d] + 1) % mod;
           ans = (ans + dp[j][d] + 1) % mod;
       }
   }
   cout << (ans + n) % mod;
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