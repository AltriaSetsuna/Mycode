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
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
      cin >> a[i];
   }
   if(a[0]==a[n-1])
   {
      yesno(0);
   }
   else 
   {
      yesno(1);
      reverse(a.begin() + 1, a.end());
      for (LL i = 0; i < n;i++)
      {
         cout << a[i] << " \n"[i == n - 1];
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