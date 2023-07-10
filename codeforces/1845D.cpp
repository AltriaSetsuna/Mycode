#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) ((x) + (k) - 1) / (k)
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n + 1), pre(n + 1), suf(n + 2);
    for (LL i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    pre[0] = 0;
    for (LL i = 1; i <= n;i++)
    {
        pre[i] = a[i] + pre[i - 1];
    }
    suf[n + 1] = 0;
    for (LL i = n; i >= 1;i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }
    for (LL i = n; i >= 1;i--)
    {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    LL ans=0, ma = 0;
    for (LL i = 0; i <= n;i++)
    {
        if(pre[i]+suf[i+1]>ma)
        {
            ma = pre[i] + suf[i + 1];
            ans = pre[i];
        }
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
