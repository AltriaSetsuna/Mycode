#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    LL n;
    cin >> n;
    LL dp[2] = {0};

    LL ans = 0;
    for (int i = 1; i <= n;i++)
    {
        LL a;
        cin >> a;
        dp[i & 1] = min(dp[(i - 1) & 1] + 1, a);
        ans += dp[i & 1];
    }
    cout << ans << endl;
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    LL t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
} 