#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;



vector<vector<pair<LL, LL>>> G;
vector<bool> vis;
vector<LL> dis;
void add(LL from,LL to, LL weight)//from->to的边,边权为weight
{
    G[from].emplace_back(make_pair(to, weight));
    return;
}
void dijkstra(LL source,LL n)//从source出发,共n个顶点
{
   dis = vector<LL>(n + 1, LLONG_MAX);
   dis[source] = 0;
   vis = vector<bool>(n + 1, false);
   priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> q;
   q.emplace(make_pair(0, source));
   while(q.size())
   {
       LL now = q.top().second;
       q.pop();
       if(vis[now]==true)
       {
           continue;
       }
       vis[now] = true;
       for (LL i = 0; i < G[now].size();i++)
       {
           LL son = G[now][i].first, cost = G[now][i].second;
           LL temp = dis[now] + cost;
           if(dis[son]>temp)
           {
               dis[son] = temp;
               q.emplace(make_pair(dis[son], son));
           }
       }
   }
   return;
}
//G是要自己初始化的,dis储存距离
//G = vector<vector<pair<LL, LL>>>(n + 1),n为节点数
//可调用add函数加边


int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   G = vector<vector<pair<LL, LL>>>(2 * n + 1);
   for (LL i = 0; i < m;i++)
   {
       LL u, v, w;
       cin >> u >> v >> w;
       add(u, v, w);
       add(v + n, u + n, w);
   }
   dijkstra(1, n);
   LL ans1= accumulate(dis.begin() + 1LL, dis.end(), 0LL);
   dijkstra(n + 1, 2 * n);
   LL ans2 = accumulate(dis.begin() + n + 1, dis.end(), 0LL);
   cout << ans1 + ans2;
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
