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
   vector<LL> sum(n * 2 + 1, 0);
   vector<vector<LL>> ans1(n * 2 + 1, vector<LL>(n * 2 + 1, 0)), ans2(n * 2 + 1, vector<LL>(n * 2 + 1, 0));
   for (LL i = 1; i <= n;i++)
   {
       cin >> sum[i];
       sum[i + n] = sum[i];
       sum[i] += sum[i - 1];
   }
   for (LL i = n + 1; i <= (n << 1);i++)
   {
       sum[i] += sum[i - 1];
   }

   for (LL step = 1; step < n;step++)
   {
       for (LL i = 1, j = i + step; i <= (n << 1) && j <= (n << 1); i++, j = i + step)
       {
           ans2[i][j] = LLONG_MAX;
           for (LL k = i; k < j; k++)
           {
               ans1[i][j] = max(ans1[i][k] + ans1[k + 1][j] + sum[j] - sum[i - 1], ans1[i][j]);
               ans2[i][j] = min(ans2[i][k] + ans2[k + 1][j] + sum[j] - sum[i - 1], ans2[i][j]);
            }
       }
   }
   LL ma = 0, mi = LLONG_MAX;
   for (LL i = 1; i <= n;i++)
   {
       ma = max(ma, ans1[i][i + n - 1]);
       mi = min(mi, ans2[i][i + n - 1]);
   }
   cout << mi << endl << ma;
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
