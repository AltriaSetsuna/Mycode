#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

bool cmp(const LL& x, const LL& y)
{
    return abs(x) > abs(y);
}

inline void solve()
{
    LL n, ma = LLONG_MIN;
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    sort(all(a), cmp);
    if(ma<=0)
    {
        cout << a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5] << endl;
        return;
    }
    LL ans = a[0] * a[1] * a[2] * a[3] * a[4];
    for (LL i = 5; i < n;i++)
    {
        for (LL j = 0; j < 5;j++)
        {
            LL temp = 1;
            for (LL k = 0; k < 5;k++)
            {
                if(k==j)
                {
                    continue;
                }
                temp *= a[k];
            }
            ans = max(ans, temp * a[i]);
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
