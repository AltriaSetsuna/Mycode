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

LL ans = 0, m;
vector<vector<LL>> G;
vector<bool> cat;
void dfs(LL now,LL fa,LL catnum)
{
    if(catnum>m)
        return;
    if(G[now].size()==1&&now!=1)
        ans++;
    for (LL i = 0; i < G[now].size();i++)
    {
        LL son = G[now][i];
        if(son==fa)
            continue;
        dfs(son, now, cat[son] ? catnum + 1 : 0);
    }
    return;
}
int main()
{
   LOCAL();

   LL n;
   cin >> n >> m;
   G = vector<vector<LL>>(n + 1);
   cat = vector<bool>(n + 1);
   for (LL i = 1; i <= n;i++)
   {
       LL t;
       cin >> t;
       cat[i] = t;
   }
   for (LL i = 1; i < n;i++)
   {
       LL x, y;
       cin >> x >> y;
       G[x].emplace_back(y);
       G[y].emplace_back(x);
   }
   dfs(1, 0, cat[1]);
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
