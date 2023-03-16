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

const LL maxn = 1e5 + 1;
LL cnt[maxn] = {0}, ans[maxn] = {0};
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   for (LL i = 0; i < n;i++)
   {
       LL t;
       cin >> t;
       cnt[t]++;
   }
   ans[1] = cnt[1];
   for (LL i = 1; i < maxn;i++)
   {
       ans[i] = max(ans[i - 1], ans[i - 2] + cnt[i] * i);
   }
   cout << ans[maxn - 1];
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
