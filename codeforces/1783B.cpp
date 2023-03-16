#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


inline void solve()
{
   LL n;
   cin >> n;
   vector<vector<LL> > a(n, vector<LL>(n));
   LL l = 1, r = n * n, flag = 1;
   for (LL i = 0; i < n;i++)
   {
      for (LL j = 0; j < n;j++)
      {
         a[i][j] = flag ? l++ : r--;
         flag ^= 1;
      }
      if(i&1)
      {
         reverse(all(a[i]));
      }
   }
   for (LL i = 0; i < n;i++)
   {
      for (LL j = 0; j < n;j++)
      {
         cout << a[i][j] << " \n"[j == n - 1];
      }
   }
   return;
}


int main()
{
   LOCAL();


   LL t;
   cin >> t;
   while(t--)
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