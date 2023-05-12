#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;

inline void solve()
{
   LL n, d;
   cin >> n >> d;
   LL ans = 0;
   for (LL a = 0; a <= n;a++)
   {
      for (LL b = 0; b <= n;b++)
      {
         LL left = d - a * 1LL - b * 2LL;
         if(left>=0&&left%3==0&& left/3<=n)
         {
            ans++;
         }
      }
   }
   cout << ans;
   return;
}


int main()
{
     LOCAL();
     solve();
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
