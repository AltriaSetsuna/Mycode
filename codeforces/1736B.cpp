#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL gcd(LL a, LL b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}

LL lcm(LL a,LL b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n + 2), b(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        b[i - 1] = lcm(a[i - 1], a[i]);
    }
    a[n + 1] = 1;
    b[n] = lcm(a[n + 1], a[n]);
    for (int i = 1; i <= n;i++)
    {
        if(gcd(b[i],b[i-1])!=a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;

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