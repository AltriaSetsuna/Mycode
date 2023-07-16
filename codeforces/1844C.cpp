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
    LL ma = LLONG_MIN;
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    if(ma<=0)
    {
        cout << ma << endl;
    }
    else
    {
        LL sum[2] = {0};
        for (LL i = 0; i < n;i++)
        {
            sum[i & 1] += max(a[i], 0LL);
        }
        cout << max(sum[0], sum[1]) << endl;
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
