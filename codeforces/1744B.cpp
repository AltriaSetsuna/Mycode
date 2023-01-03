#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
   LL n, q;
   cin >> n >> q;
   LL cnt[2] = {0}, sum = 0;
   while(n--)
   {
      LL x;
      cin >> x;
      cnt[x & 1]++;
      sum += x;
   }
   while(q--)
   {
      LL t, x;
      cin >> t >> x;
      sum += x * cnt[t & 1];
      if(t&&x&1)
      {
         cnt[0] += cnt[1];
         cnt[1] = 0;
      }
      else if(x&1)
      {
         cnt[1] += cnt[0];
         cnt[0] = 0;
      }
      cout << sum << endl;
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