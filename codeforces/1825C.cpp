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
    LL n, m;
    cin >> n >> m;
    vector<LL> seat(m + 2, 0);
    map<LL, LL> p;
    LL ans = 0;
    for (LL i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        if(x<0)
        {
            p[x]++;
        }
        else
        {
            if(seat[x]==0)
            {
                ans++;
                seat[x] = 1;
            }
        }
    }
    seat[0] = seat[m + 1] = 1;
    vector<LL> sumzero(m + 2, 0);
    for (LL i = 1; i <= m + 1;i++)
    {
        sumzero[i] += sumzero[i - 1] + (seat[i] == 0);
    }
    LL t = 0, left = m - ans;
    for (LL i = 0; i <= m + 1;i++)
    {
        if(seat[i]==1)
        {
            LL k = i == 0 ? 0 : sumzero[i - 1];
            LL tleft = min(p[-1], k) + min(p[-2], sumzero[m + 1] - sumzero[i]);
            t = max(t, min(tleft, left));
        }
    }
    cout << ans + t << endl;
    return;
}


int main()
{
     LOCAL();
     LL t;
     cin >> t;
     while(t--)
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
