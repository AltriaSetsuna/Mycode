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


inline void solve()
{
    string s = "codeforces";
    string t;
    cin >> t;
    LL ans = 0;
    for (LL i = 0; i < 10;i++)
    {
        ans += s[i] != t[i];
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
