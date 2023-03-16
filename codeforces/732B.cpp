#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


int main()
{
   LOCAL();

   LL n, k;
   cin >> n >> k;
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> a[i];
   }
   LL ans = 0;
   for (LL i = 1; i < n;i++)
   {
       ans += max(0LL, k - a[i] - a[i - 1]);
       a[i] = max(a[i], k - a[i - 1]);
   }
   cout << ans << endl;
   for (LL i = 0; i < n;i++)
   {
       cout << a[i] << ' ';
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
