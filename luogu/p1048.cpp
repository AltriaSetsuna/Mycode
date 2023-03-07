#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   vector<LL> ans(n + 1, 0);
   for (int i = 0; i < m;i++)
   {
       LL v, w;
       cin >> w >> v;
       for (LL i = int(ans.size()) - 1; i>=w;i--)
       {
           ans[i] = max(ans[i], ans[i - w] + v);
       }
   }
   cout << ans[n];
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
