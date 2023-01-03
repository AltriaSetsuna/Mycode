#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define YESNO(x) puts(x?"YES":"NO")
void LOCAL();
using namespace std;

inline void solve()
{
  LL n;
  cin >> n;
  vector<LL> a(n), b(n + 1);
  for (LL i = 0; i < n;i++)
  {
    cin >> a[i];
  }
  for (LL i = 0; i < n;i++)
  {
    cin >> b[i];
  }
  b[n] = b[0];
  bool flag = 0;
  for (LL i = 0; i < n;i++)
  {
    if(flag)
    {
      continue;
    }
    flag = (a[i] > b[i]) || (b[i] > b[i + 1] + 1 && a[i] != b[i]) ? 1 : 0;
  }
  YESNO(!flag);
  return;
}

int main() 
{
  LOCAL();

  LL t;
  cin >> t;
  while (t--)
  {
    solve();
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