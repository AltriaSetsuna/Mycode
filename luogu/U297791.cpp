#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;

vector<LL> ans;
inline void solve()
{
    LL n, d;
    cin >> n >> d;
    LL a = 0, b = 0, c = 0;
    vector<vector<LL>> ans(n + 1,vector<LL>(d + 1, 0));
    ans[0][0] = 1;
    for (LL i = 1; i <= n;i++)
    {
        for (LL j = 1; j <= d;j++)
        {
            if(j>=1)
            {
                ans[i][j] += ans[i - 1][j - 1];
            }
            if(j>=2)
            {
                ans[i][j] += ans[i - 1][j - 2];
            }
            if(j>=3)
            {
                ans[i][j] += ans[i - 1][j - 3];
            }
            ans[i][j] += ans[i - 1][j];
        }
    }
    cout << ans[n][d];
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
