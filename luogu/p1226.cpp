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
       if(n&1)
       {
           ans = ans * x % mod;
       }
       x = x * x % mod;
       n /= 2;
   }
   return ans;
}

inline void solve()
{
    LL a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << qpow(a, b, p) << endl;
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
