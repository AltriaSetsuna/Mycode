#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<LL> ten(13, 1), dp(13, 0);
void solve(LL n,vector<LL>& ans)
{
   vector<LL> a;
   LL temp = n;
   while(n)
   {
      a.emplace_back(n % 10LL);
      n /= 10LL;
   }
   for (LL len = a.size(); len >= 1; len--)
   {
      for (LL i = 0; i < 10;i++)
      {
         ans[i] += a[len - 1] * dp[len - 1];
      }
      for (LL i = 0; i < a[len - 1];i++)
      {
         ans[i] += ten[len - 1];
      }
      ans[0] -= ten[len - 1];
      temp -= a[len - 1] * ten[len - 1];
      ans[a[len - 1]] += temp + 1;
   }
   return;
}
int main()
{
   LOCAL();

   for (LL i = 1; i <= 12;i++)
   {
      dp[i] = 10LL * dp[i - 1] + ten[i - 1];
      ten[i] = 10LL * ten[i - 1];
   }
   LL l, r;
   cin >> l >> r;
   vector<LL> ans1(10, 0), ans2(10, 0);
   solve(r, ans1), solve(l - 1, ans2);
   for (LL i = 0; i < 10;i++)
   {
      cout << ans1[i] - ans2[i] << ' ';
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
