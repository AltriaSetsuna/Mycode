#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    string s;
    cin >> s;
    bool l = 0, r = 0;
    LL maxL = 0, minR = LLONG_MAX;
    LL ans;
    for (LL i = 0; i < n;i++)
    {
        if(s[i]=='L')
        {
            l = 1;
            maxL = max(maxL, i);
        }
        else
        {
            minR = min(minR, i);
            r = 1;
        }
    }
    for (LL i = 1; i < n;i++)
    {
        if(s[i]!=s[i-1])
        {
            ans = i;
        }
    }
    if (l == 0 || r == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        if (maxL > minR)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
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