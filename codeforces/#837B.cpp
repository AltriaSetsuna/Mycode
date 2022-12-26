#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    LL n, m;
    cin >> n >> m;
    set<pair<LL, LL>> q;
    vector<LL> dp(n + 1, n);
    LL ans = 0;
    for (int i = 0; i < m;i++)
    {
        LL x, y;
        cin >> x >> y;
        if(x>y)
            swap(x, y);
        dp[x] = min(dp[x], y - 1);
    }
    for (int i = n-1; i > 0;i--)
    {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i] - i + 1;
    }
    cout << ans << endl;
    return;
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    
    
    LL t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
} 