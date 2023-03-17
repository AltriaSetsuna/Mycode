#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL gcd(LL a, LL b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}

pair<LL,LL> simplify(pair<LL,LL> a)
{
    LL g = gcd(a.first, a.second);
    a.first /= g, a.second /= g;
    return a;
}
inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    map<pair<LL,LL>, LL> m;
    LL ans = 0, all = 0;
    for (LL i = 0; i < n;i++)
    {
        LL b;
        cin >> b;

        if(b==0&&a[i]==0)
        {
            all++;
            continue;
        }
        else if(a[i]==0)
        {
            continue;
        }
        ans = max(ans, ++m[simplify(make_pair(a[i], b))]);
    }
    cout << ans + all;

    return;
}


int main()
{
   LOCAL();
   solve();
   return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
