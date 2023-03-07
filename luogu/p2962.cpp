#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL target,ans=LLONG_MAX;
vector<LL> st;
map<LL, LL> m;
void dfs(LL pos,LL end,LL state,LL cost)
{
    if(m[state]||state==0)
        m[state] = min(m[state], cost);
    else
        m[state] = cost;

    if(m[state^target]||state==target)
    {
        ans = min(ans, m[state ^ target] + cost);
    }
    if(pos<=end)
    {
        dfs(pos + 1, end, state, cost);
        dfs(pos + 1, end, state ^ st[pos], cost + 1);
    }
    return;
}
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   st = vector<LL>(n + 1, 0);
   target = (1LL << n) - 1LL;
   for (LL i = 0; i < m;i++)
   {
       LL x, y;
       cin >> x >> y;
       st[x] |= 1LL << y - 1LL;
       st[y] |= 1LL << x - 1LL;
   }
   for (LL i = 1; i <= n;i++)
   {
       st[i] |= 1 << i - 1;
   }
   dfs(1, n / 2, 0, 0);
   dfs(n / 2 + 1, n, 0, 0);
   cout << ans;
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
