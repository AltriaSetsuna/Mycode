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

inline void solve()
{
    LL n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<LL> left(m), right(m);
    for (LL i = 0, j = 0; i < m; i++)
    {
        while(s[j++]!=t[i]);
        left[i] = j - 1;
    }
    for (LL i = m - 1, j = n - 1; i >= 0; i--)
    {
        while(s[j--]!=t[i]);
        right[i] = j + 1;
    }
    LL ans = 0;
    for (LL i = 1; i < m;i++)
    {
        ans = max(ans, right[i] - left[i - 1]);
    }
    cout << ans;
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
