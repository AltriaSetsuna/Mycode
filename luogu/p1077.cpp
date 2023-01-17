#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 1e6 + 7;

int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   vector<LL> a(n + 1);
   vector<LL> f(m + 1, 0);
   vector<LL> sum(m + 1, 1);
   f[0] = 1;
   for (LL i = 1; i <= n;i++)
   {
       cin >> a[i];
   }
   for (LL i = 1; i <= n;i++)
   {
       for (LL j = m; j >= 1;j--)
       {
           LL t = j - min(a[i], j) - 1;
           f[j] = (f[j] + sum[j - 1] - (t >= 0 ? sum[t] : 0) + mod) % mod;
       }
       for (LL j = 1; j <= m;j++)
       {
           sum[j] = (sum[j - 1] + f[j]) % mod;
       }
   }
   cout << f[m];
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