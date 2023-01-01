#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline void solve()
{
    LL n, k, r, c;
    cin >> n >> k >> r >> c;
    LL target = (r + c) % k;
    for (LL i = 1; i <= n;i++)
    {
        for (LL j = 1; j <= n;j++)
        {
            if((i+j)%k==target)
            {
                puts("X");
            }
            else 
            {
                putchar('.');
            }
        }
        putchar('\n');
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