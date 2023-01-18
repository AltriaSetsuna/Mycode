#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<vector<pair<LL, LL>>> G;
void add(LL from,LL to,LL weight)
{
    G[from].emplace_back(make_pair(to, weight));
    return;
}
LL prim(LL n)
{
    vector<bool> st(n + 1, false);
    LL ans = 0;
    LL vertex_cnt = 0;
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> q;
    q.emplace(make_pair(0, 1));
    while(q.size())
    {
        LL now = q.top().second, w = q.top().first;
        q.pop();
        if(st[now]==true)
        {
            continue;
        }
        st[now] = true;
        ans += w;
        vertex_cnt++;
        for (LL i = 0; i < G[now].size();i++)
        {
            LL son = G[now][i].first, weight = G[now][i].second;
            if(st[son]==false)
            {
                q.emplace(make_pair(weight, son));
            }
        }
    }
    return vertex_cnt == n ? ans : -1;
}
//返回-1说明图不连通
//G = vector<vector<pair<LL, LL>>>(n + 1);add(u,v,w)加边
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   G = vector<vector<pair<LL, LL>>>(n + 1);
   for (LL i = 0; i < m;i++)
   {
       LL u, v, w;
       cin >> u >> v >> w;
       add(u, v, w);
       add(v, u, w);
   }
   LL ans = prim(n);
   if(ans==-1)
   {
       cout << "orz";
   }
   else
   {
       cout << ans;
   }
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
