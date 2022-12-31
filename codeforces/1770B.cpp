#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL n, k;
    cin >> n >> k;
    if(k==1)
    {
        for (LL i = 1; i <= n;i++)
        {
            cout << i << ' ';
        }
    }
    else 
    {
        LL l = 1, r = n, t = 1;
       while(l<=r)
       {
            cout << ((t ^= 1) ? l++ : r-- )<< ' ';
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