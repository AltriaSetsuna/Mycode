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
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> a[i];
   }
   vector<vector<LL>> ans(n, vector<LL>(n));
   for (LL i = 0; i < n;i++)
   {
       ans[i][i] = 1;
       for (LL j = i + 1; j < n; j++)
       {
           ans[i][j] = LLONG_MAX;
           ans[j][i] = 1;
       }
   }
   LL step = 0;
   while(++step<n)
   {
       for (LL i = 0, j = i + step; j < n;i++,j++)
       {
        if(a[i]==a[j])
            ans[i][j] = ans[i + 1][j - 1];
        else
            for (LL k = i; k < j;k++)
            {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k + 1][j]);
            }
       }
   }
   cout << ans[0][n - 1];
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
