#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL n, m;
inline bool check(LL mid,vector<vector<LL>>& a)
{
  vector<vector<LL>> pre(n + 1, vector<LL>(m + 1, 0));
  for (LL i = 0; i < n;i++)
  {
    for (LL j = 0; j < m;j++)
    {
      if(a[i][j]>=mid)
      {
        pre[i + 1][j + 1] = 1;
      }
      else 
      {
        pre[i + 1][j + 1] = 0;
      }
      pre[i + 1][j + 1] += pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
    }
  }
  LL ans = mid * mid;
  for (LL i = mid; i <= n ;i++)
  {
    for (LL j = mid; j <= m; j++)
    {
      if(pre[i][j]-pre[i-mid][j]-pre[i][j-mid]+pre[i-mid][j-mid]==ans)
      {
        return true;
      }
    }
  }
  return false;
}
inline void solve()
{
  cin >> n >> m;
  LL r = min(n, m), l = 0, ans;
  vector<vector<LL>> a(n, vector<LL>(m));
  for (LL i = 0; i < n;i++)
  {
    for (LL j = 0; j < m;j++)
    {
      cin >> a[i][j];
    }
  }
  while (l <= r)
  {
    LL mid = l + r >> 1;
    if (check(mid, a))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return;
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    
    
    LL t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
} 