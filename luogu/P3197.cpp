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

LL qpow(LL x,LL n,LL mod)//x^n%mod
{
   LL ans = 1;
   while(n)
   {
       if(n&1LL)
       {
           ans = ans * x % mod;
       }
       x = x * x % mod;
       n /= 2LL;
   }
   return ans;
}

inline void solve()
{
    LL n, m;
    cin >> m >> n;
    const LL mod = 100003;
    LL temp = (qpow(m, n, mod) - (m % mod) * qpow(m - 1, n - 1, mod)) % mod;
    cout << (temp + mod) % mod;
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
