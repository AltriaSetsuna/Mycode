#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    LL n;
    cin >> n;
    LL ans=0;
    if(n==1)
    {
        cin >> ans;
    }
    else if(n==2)
    {
        LL x[2];  
        cin >> x[0] >> x[1];
        ans = max(x[0] + x[1], 2 * abs(x[0] - x[1]));
    }
    else if(n==3)
    {
        LL x[3];
        cin >> x[0] >> x[1] >> x[2];
        LL y[] = {3 * max(x[0], x[2]), x[0] + x[1] + x[2], x[0] + 2 * abs(x[1] - x[2]), x[2] + 2 * abs(x[0] - x[1]), 3 * abs(x[0] - x[1]), 3 * abs(x[2] - x[1])};
        ans = *max_element(y, y + sizeof(y) / sizeof(y[0])); 
    }
    else 
    {
        for (int i = 0; i < n;i++)
        {
            LL t;
            cin >> t;
            ans = max(ans, t);
        }
        ans *= n;
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