#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL k, n;
    cin >> k >> n;
    LL step = 0, cnt = 1;
    for (LL i = 1;cnt<=k;i+=step,cnt++)
    {
        cout << i << ' ';
        if(n-i-step>k-cnt-1LL)
        {
            step++;
        }
        else 
        {
            step = 1;
        }
    }
    cout << endl;
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