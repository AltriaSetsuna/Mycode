#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

const LL mod = 998244353;
inline void solve()
{
    LL n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 1, cur = 1;
    for (LL i = 1; i < n;i++)
    {
        if(s[i]==s[i-1])
        {
            cur = cur * 2 % mod;
        }
        else 
        {
            cur = 1;
        }
        ans = (ans + cur) % mod;
    }
    cout << ans << endl;
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