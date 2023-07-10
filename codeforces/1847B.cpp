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
    vector<LL> a(n);
    LL ans = 0, sum = LLONG_MAX;
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
        sum &= a[i];
    }
    if(sum==0)
    {
        sum = LLONG_MAX;
        for (LL i = 0; i < n;i++)
        {
            sum &= a[i];
            if(sum==0)
            {
                sum = LLONG_MAX;
                ans++;
            }
        }
    }
    else
    {
        ans = 1;
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
