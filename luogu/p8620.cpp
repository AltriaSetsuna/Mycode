#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 998244353;

int main()
{
   LOCAL();
   LL n;
   cin >> n;
   vector<LL> s(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> s[i];
   }
   vector<LL> fac(s.size() + 1, 1);
   for (LL i = 2; i <= s.size();i++)
   {
       fac[i] = i * fac[i - 1] % mod;
   }
   LL ans = 1;
   for (LL i = 0; i < s.size();i++)
   {
       LL less = 0;
       for (LL j = i + 1; j < s.size();j++)
       {
           less += (s[j] < s[i]);
       }
       ans += less * fac[s.size() - i - 1] % mod;
       ans %= mod;
   }
   cout << ans;
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