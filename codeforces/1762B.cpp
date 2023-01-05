#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

LL f(LL x)
{
    LL cur = 1;
    while(cur<=x)
    {
        cur *= 2;
    }
    return cur;
}
inline void solve()
{
    LL n;
    cin >> n;
    cout << n << endl;
    for (LL i = 1; i <= n;i++)
    {
        LL x;
        cin >> x;
        cout << i << ' ' << f(x) - x << endl;
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