#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout<<(x?"YES":"NO")<<endl
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
   LL n;
   cin >> n;
   if(n==3)
   {
      yesno(0);
      return;
   }
   yesno(1);
   if(n%2==1)
   {
      LL even = n / 2, odd = -even + 1;
      for (LL i = 1; i <= n;i++)
      {
         cout << (i % 2 == 1 ? odd : even) << " \n"[i == n];
      }
   }
   else 
   {
      for (LL i = 0; i < n;i++)
      {
         cout<<(i%2==0?1:-1)<<" \n"[i==n-1];
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