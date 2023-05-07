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


LL qpow(LL x,LL n)//x^n
{
   LL ans = 1;
   while(n)
   {
       if(n&1LL)
       {
           ans = ans * x;
       }
       x = x * x;
       n /= 2LL;
   }
   return ans;
}

inline void solve()
{
    LL n, m;
    cin >> n >> m;
    LL cnt = 0;
    while(n%3==0)
    {
        n /= 3;
        cnt++;
    }
    for (LL i = cnt; i >= 0;i--)
    {
        LL t = n * qpow(3, i);
        for (LL j = 0; j <= cnt - i;j++)
        {
            if(t*qpow(2,j)==m)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
