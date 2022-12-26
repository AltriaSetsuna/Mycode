#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void solve()
{
    LL n;
    cin >> n;
    map<LL, LL> m;
    LL ma = LLONG_MIN, mi = LLONG_MAX;
    for (int i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        ma = max(ma, x);
        mi = min(mi, x);
        m[x]++;
    }
    if(ma==mi)
        cout << n * (n - 1) << endl;
    else
        cout << m[ma] * m[mi] * 2LL << endl;
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