#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
  LL n, k;
  cin >> n >> k;
  vector<pair<LL, LL>> m(n);
  for(auto& x:m)
  {
    cin >> x.second;
  }
  for(auto&x:m)
  {
    cin >> x.first;
  }
  sort(m.begin(), m.end());
  LL attack = k;
  for(auto&x:m)
  {
    if(x.second<=attack)
    {
      continue;
    }
    else 
    {
      while(attack<x.second)
      {
         k -= x.first;
         attack += k;
          if(k<=0)
          {
            cout << "NO" << endl;
            return;
          }
      }
    }
  }
  cout << "YES" << endl;
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
