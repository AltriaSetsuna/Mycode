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
    vector<bool> in_queue = vector<bool>(n + 1, false);
    dis = vector<LL>(n + 1, LLONG_MAX);
    queue<LL> q;
    dis[source] = 0;
    q.emplace(source);
    in_queue[source] = true;
    while(q.size())
    {
        LL now = q.front();
        q.pop();
        in_queue[now] = false;
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
                if(in_queue[son]==false)
                {
                    in_queue[son] = true;
                    q.emplace(son);
                }
            }
        }
    }
    return true;
}
//G = vector<vector<pair<LL, LL>>>(n + 1),n为节点数
//超级源点也算节点
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   G = vector<vector<pair<LL, LL>>>(n + 2);
   for (LL i = 0; i < m;i++)
   {
       LL op;
       cin >> op;
       if(op==1)
       {
            LL a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
       }
       else if(op==2)
       {
            LL a, b, c;
            cin >> a >> b >> c;
            add(b, a, c);
       }
       else
       {
            LL a, b;
            cin >> a >> b;
            add(a, b, 0);
            add(b, a, 0);
       }
   }
   for (LL i = 1; i <= n;i++)
   {
       add(0, i, 0);
   }
   if(spfa(0,n+1))
   {
       cout << "Yes";
   }
   else
   {
       cout << "No";
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
