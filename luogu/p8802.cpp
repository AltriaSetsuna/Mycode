#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL maxn = 1e3 + 1;
vector<pair<LL, LL>> G[maxn];
vector<bool> vis;
vector<LL> dis;
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
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   vector<LL> time(n + 1);
   for (LL i = 1; i <= n;i++)
   {
       cin >> time[i];
   }
   time[1] = 0, time[n] = 0;
   for (LL i = 0; i < m;i++)
   {
       LL x, y, w;
       cin >> x >> y >> w;
       G[x].emplace_back(make_pair(y, time[y] + w));
       G[y].emplace_back(make_pair(x, time[x] + w));
   }
   dijkstra(1, n);
   cout << dis[n];
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