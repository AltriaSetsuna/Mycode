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

inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n + 2), end(n + 2), start(n + 2);
    a[n + 1] = LLONG_MAX;
    for (LL i = 1; i <= n;i++)
    {
        cin >> a[i];
        if(a[i]>a[i-1])
            end[i] = end[i - 1] + 1;
        else
            end[i] = 1;
    }
    for (LL i = n; i;i--)
    {
        if(a[i]<a[i+1])
            start[i] = start[i + 1] + 1;
        else
            start[i] = 1;
    }
    LL ans = 0;
    for (LL i = 1; i < n;i++)
    {
        ans = max(max(ans, start[i]), max(end[i], a[i - 1] < a[i + 1] ? end[i - 1] + start[i + 1] : 1));
    }
    cout << ans;
    return;
}


int main()
{
   LOCAL();
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
