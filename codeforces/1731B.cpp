#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod=1e9+7;
void solve()
{
    LL n;
    cin>>n;
    LL ans=n*(n+1)%mod*(2*n+1)%mod*674%mod-n*(n+1)%mod*1011%mod;
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
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
