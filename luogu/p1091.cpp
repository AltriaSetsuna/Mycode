#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


int main()
{
   LOCAL();

   LL n;
   cin >> n;
   vector<LL> a(n);
   vector<LL> f(n, 0), g(n, 0);
   for (LL i = 0; i < n;i++)
   {
       cin >> a[i];
       for (LL j = 0; j < i;j++)
       {
        if(a[j]<a[i])
        {
            f[i] = max(f[i], f[j] + 1LL);
        }
       }
   }    
   for (LL i = n - 1; i >= 0;i--)
   {
       for (LL j = n - 1; j > i;j--)
       {
        if(a[j]<a[i])
        {
            g[i] = max(g[i], g[j] + 1);
        }
       }
   }
   LL ans = 0;
   for (LL i = 0; i < n;i++)
   {
       ans = max(ans, f[i] + g[i] + 1LL);
   }
   cout << n - ans;
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
