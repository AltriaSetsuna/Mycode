#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    LL n, c;
    map<LL, LL> m;
    cin >> n >> c;
    for (int i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        m[x]++;
    }
    LL ans = 0;
    for(auto&x:m)
    {
        ans += min(x.second, c);
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