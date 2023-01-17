#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<LL> pw, f;

vector<vector<pair<LL, LL>>> G;
vector<bool> vis;
vector<LL> dis;
void add(LL from,LL to, LL weight)//from->to的边,边权为weight
{
    G[from].emplace_back(make_pair(to, weight));
    return;
}
void dijkstra(LL source,LL n,LL mid)//从source出发,共n个顶点
{
   dis = vector<LL>(n + 1, LLONG_MAX);
   dis[source] = 0;
   vis = vector<bool>(n + 1, false);
   priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> q;
   q.emplace(make_pair(0, source));
   if(pw[source]>mid)
   {
       return;
   }
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
           if(dis[son]>temp&&pw[son]<=mid)
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

   LL n, m, b;
   cin >> n >> m >> b;
   G = vector<vector<pair<LL, LL>>>(n + 1);
   pw = vector<LL>(n + 1);
   f = vector<LL>(n + 1);

   for (LL i = 1; i <= n;i++)
   {
       cin >> pw[i];
       f[i] = pw[i];
   }
   sort(f.begin() + 1, f.end());
   for (LL i = 0; i < m;i++)
   {
       LL a, b, c;
       cin >> a >> b >> c;
       add(a, b, c);
       add(b, a, c);
   }
   dijkstra(1, n, f[n]);
   if(dis[n]>b)
   {
       cout << "AFK";
   }
   else
   {
       LL l = 1, r = n;
       LL ans;
       while(l<=r)
       {
           LL mid = (l + r) / 2;
           dijkstra(1, n, f[mid]);
           if(dis[n]<=b)
           {
               ans = f[mid];
               r = mid - 1;
           }
           else
           {
               l = mid + 1;
           }
       }
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