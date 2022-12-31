#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL x[4];
    LL ma = LLONG_MIN, mi = LLONG_MAX;
    for (LL i = 0; i < 4;i++)
    {
        cin >> x[i];
        ma = max(ma, x[i]);
        mi = min(mi, x[i]);
    }
    if((ma==x[0]&&mi==x[3])||(ma==x[3]&&mi==x[0])||(ma==x[1]&&mi==x[2])||(ma==x[2]&&mi==x[1]))
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }
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
