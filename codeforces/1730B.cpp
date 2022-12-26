#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
  LL n;
  cin >> n;
  vector<LL> x(n),t(n),a;
  for (auto&i:x)
  {
    cin >> i;
  }
  LL m[2] = {LLONG_MIN, LLONG_MAX};
  for (int i = 0; i < n;i++)
  {
    LL t;
    cin >> t;
    m[0] = max(m[0], x[i] + t);
    m[1] = min(m[1], x[i] - t);
  }
    cout << (m[0] + m[1]) / 2;
  if((m[0]+m[1])&1)
  {
    cout << ".5";
  }
  cout << endl;
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