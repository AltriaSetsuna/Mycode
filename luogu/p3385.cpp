#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<vector<pair<LL, LL>>> G;
vector<LL> dis;
void add(LL from,LL to,LL weight)
{
{    G[from].emplace_back(make_pair(to, weight));}
    return;
}
bool spfa(LL source,LL n)//返回false有负环
{
    vector<LL> edge_cnt = vector<LL>(n + 1, 0);
    vector<bool> in_deque = vector<bool>(n + 1, false);
    dis = vector<LL>(n + 1, LLONG_MAX);
    queue<LL> q;
    dis[source] = 0;
    q.emplace(source);
    in_deque[source] = true;
    while(q.size())
    {
        LL now = q.front();
        q.pop();
        in_deque[now] = false;
        for (LL i = 0; i < G[now].size();i++)
        {
            LL son = G[now][i].first, weight = G[now][i].second;
            if(dis[son]>dis[now]+weight)
            {
                dis[son] = dis[now] + weight;
                edge_cnt[son] = edge_cnt[now] + 1;
                if(edge_cnt[son]>=n)//存在负环
                {
                    return false;
                }
                if(in_deque[son]==false)
                {
                    in_deque[son] = true;
                    q.emplace(son);
                }
            }
        }
    }
    return true;
}
//G = vector<vector<pair<LL, LL>>>(n + 1),n为节点数
inline void solve()
{
    LL n, m;
    cin >> n >> m;
    G = vector<vector<pair<LL, LL>>>(n + 1);
    for (LL i = 0; i < m;i++)
    {
        LL u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        if(w>=0)
        {
            add(v, u, w);
        }
    }
    yesno(!spfa(1, n));
    return;
}


int main()
{
   LOCAL();


   LL t;
   cin >> t;
   while(t--)
   {
       solve();
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
