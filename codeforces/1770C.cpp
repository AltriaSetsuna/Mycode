#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline bool check(vector<LL> &a,LL& mod)
{
  return *(min_element(a.begin(), a.begin()+mod)) >= 2;
}
inline void solve()
{
  LL n;
  cin >> n;
  vector<LL> a(n), cnt((n + 1) >> 1, 0);
  LL mod = 2;
  for (LL i = 0; i < n;i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (LL i = 1; i < n;i++)
  {
    if(a[i]==a[i-1])
    {
      cout << "NO" << endl;
      return;
    }
  }
    for (LL mod = 2; mod <= (n >> 1); (mod & 1 ? mod += 2 : mod++))
    {
      fill(cnt.begin(), cnt.begin() + mod, 0);
      for (LL i = 0; i < n; i++)
      {
        cnt[a[i] % mod]++;
      }
      if (check(cnt,mod))
      {
        cout << "NO" << endl;
        return;
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