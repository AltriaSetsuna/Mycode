#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<vector<LL>> G;
vector<LL> weight;
vector<LL> dfn, low;
set<LL> new_vertax;
LL dfncnt = 0;
void tarjan(LL now)
{
    dfn[now] = low[now] = ++dfncnt;
    for (LL i = 0; i < G[now].size();i++)
    {
        LL son = G[now][i];
        if(dfn[son]==0)
        {
            tarjan(son);
            low[now] = min(low[now], low[son]);
        }
        else
        {
            low[now] = min(low[now], dfn[son]);
        }
    }
    if(dfn[now]==low[now])
    {
        new_vertax.emplace(now);
    }
    return;
}
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   G = vector<vector<LL>>(n + 1);
   weight = vector<LL>(n + 1);
   dfn = vector<LL>(n + 1, 0);
   low = vector<LL>(n + 1);
//    for (LL i = 1; i <= n;i++)
//    {
//        cin >> weight[i];
//    }
   for (LL i = 0; i < n;i++)
   {
       LL u, v;
       cin >> u >> v;
       G[u].emplace_back(v);
   }
   for (LL i = 1; i <= n;i++)
   {
    if(dfn[i]==0)
    {
        tarjan(i);
    }
   }
   cout << new_vertax.size();
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
