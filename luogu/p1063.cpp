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

   LL n;
   cin >> n;
   vector<LL> a(n * 2 + 1);
   for (LL i = 0; i < n;i++)
   {
       cin >> a[i];
       a[i + n] = a[i];
   }
   vector<vector<LL>> ans(2 * n + 1, vector<LL>(2 * n + 1, 0));
   LL step = 1;
   while(step<n)
   {
       for (LL i = 1, j = i + step; j <= (n << 1); i++, j = i + step)
       {
           for (LL k = i; k < j;k++)
           {
               ans[i][j] = max(ans[i][k] + ans[k + 1][j] + a[i - 1] * a[k] * a[j], ans[i][j]);
           }
       }
       step++;
   }
   LL res = 0;
   for (LL i = 1; i <= n;i++)
   {
       res = max(res, ans[i][i + n - 1]);
   }
   cout << res;
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
