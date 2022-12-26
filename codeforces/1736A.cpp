#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    LL ans = 0, sum = 0;
    for(auto& x:a)
    {
        cin >> x;
        sum += x;
    }
    for(auto& x:b)
    {
        cin >> x;
        sum -= x;
    }
    for (int i = 0; i < n;i++)
    {
        ans += (a[i] ^ b[i]);
    }
    cout << min(ans, 1 + abs(sum)) << endl;
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
} 