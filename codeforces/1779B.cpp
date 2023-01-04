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
   }
   else
   {
      yesno(1);
      
      if((n&1)==0)
      {
         n >>= 1;
         for (LL i = 0; i < n;i++)
         {
            cout << 1 << ' ' << -1 << ' ';
         }
      }
      else
      {

         LL odd= n - 2 >> 1;
         LL even = (odd+ 1)*-1;
         n >>= 1;
         for (LL i = 0; i < n;i++)
         {
            cout << odd << ' ' << even << ' ';
         }
         cout << odd;
      }
      cout << endl;
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