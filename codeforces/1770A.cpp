#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
  LL n, m;
  cin >> n >> m;
  vector<LL> a(n+m);
  LL sum = 0;
  for (LL i = 0; i < n + m;i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end() - 1, greater<LL>());
  for (LL i = 0; i + 1 < n; i++)
  {
    sum += a[i];
  }
  sum += a[n + m - 1];
  cout << sum << endl;
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