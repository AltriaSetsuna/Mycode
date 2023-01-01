#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL n;
    cin >> n;
    LL ans = n + n / 2 * 2 + n / 3 * 2;
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