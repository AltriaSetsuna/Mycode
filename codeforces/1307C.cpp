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
    string s;
    cin >> s;
    vector<LL> one(26, 0);
    vector<vector<LL>> two(26, vector<LL>(26, 0));
    for (LL i = 0; i < s.size();i++)
    {
        LL c = s[i] - 'a';
        for (LL i = 0; i < 26;i++)
        {
            two[i][c] += one[i];
        }
        one[c]++;
    }
    LL ans = 0;
    for (LL i = 0; i < 26;i++)
    {
        ans = max(ans, one[i]);
        for (LL j = 0; j < 26;j++)
        {
            ans = max(ans, two[i][j]);
        }
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
