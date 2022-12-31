#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL n;
    cin >> n;
    LL a[2] = {0};
    cin >> a[0];
    LL l = 0, r = LLONG_MAX;
    for (LL i = 1; i < n;i++)
    {
        cin >> a[i & 1];
        if(a[i&1]>a[(i-1)&1])
        {
            r = min(r, a[i & 1] + a[(i - 1) & 1]  >> 1);
        }
        else if(a[i&1]<a[(i-1)&1])
        {
            l = max(l, a[i & 1] + a[(i - 1) & 1] + 1LL >> 1);
        }
    }
    cout << (l <= r ? l : -1) << endl;
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
