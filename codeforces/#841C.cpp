#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    LL n;
    cin >> n;
    LL cnt = 0, cur = 0, ma = n << 1LL;
    vector<LL> m(ma, 0);
    m[0]++;
    while(n--)
    {
        LL x;
        cin >> x;
        cur ^= x;
        for (LL i = 0; ;i++)
        {
            LL now = i * i;
            if(now>=ma)
            {
                break;
            }
            if((cur^now)<ma)
            {
                cnt += m[cur ^ now];
            }
        }
        m[cur]++;
    }
    n = ma >> 1;
    cout << n * (n + 1) / 2 - cnt << endl;
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