#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

class Dinic
{
private:
    typedef struct edge
    {
        LL to, weight, next;
        edge (LL to,LL weight,LL next)
        {
            this->to = to, this->weight = weight, this->next = next;
        }
    } edge;
    vector<edge> edges;
    vector<LL> head,deep;
    LL vertex_num, source, sink;

    LL dfs(LL now,LL flow,vector<LL>&cur)
    {
        if(now==sink)
        {
            return flow;
        }

        for (LL i = cur[now]; i != -1&& flow!=0;i=edges[i].next)
        {
            cur[now] = i;
            LL son = edges[i].to, val = edges[i].weight;
            if(val&&deep[son]==deep[now]+1LL)
            {
                LL cost = dfs(son, min(flow, val),cur);
                if(cost==0)
                {
                    deep[son] = 0;
                    continue;
                }
                edges[i].weight -= cost;
                edges[i ^ 1].weight += cost;
                return cost;
            }
        }
        return 0;
    }
    bool bfs()
    {
        deep = vector<LL>(vertex_num + 1LL, 0LL);
        queue<LL> q;
        q.push(source);
        deep[source] = 1;
        while(q.size())
        {
            LL now = q.front();
            q.pop();
            for (LL i = head[now]; i != -1;i=edges[i].next)
            {
                LL son = edges[i].to, val = edges[i].weight;
                if(val>0&&deep[son]==0)
                {
                    q.push(son);
                    deep[son] = deep[now] + 1LL;
                }
            }
        }
       if(deep[sink]==0)
       {
           return false;
       }
       return true;
    }
public:
    Dinic(LL vertex_num,LL source,LL sink)
    {
        this->vertex_num = vertex_num;
        this->source = source;
        this->sink = sink;
        head = vector<LL>(vertex_num + 1LL, -1);
    }
    void addedge(LL from,LL to,LL weight)
    {
        edges.emplace_back(edge(to, weight, head[from]));
        head[from] = LL(edges.size()) - 1LL;
        edges.emplace_back(edge(from, 0LL, head[to]));
        head[to] = LL(edges.size()) - 1LL;
    }
    LL dinic()
    {
        LL ans = 0;
        while(bfs())
        {
            vector<LL> cur = head;
            LL flow;
            while(flow=dfs(source,LLONG_MAX,cur))
            {
               ans += flow;
            }
        }
        return ans;
     }
};

int main()
{
   LOCAL();

   LL n, m, e;
   cin >> n >> m >> e;
   LL source = 0, sink = n + m + 1;
   Dinic G(n + m + 2, source, sink);
   set<pair<LL, LL>> q;
   while(e--)
   {
        LL u, v;
        cin >> u >> v;
        if(q.count(make_pair(u,v)))
        {
            continue;
        }
        q.emplace(make_pair(u, v));
        G.addedge(u, v + n, 1);
   }
   for (LL i = 1; i <= n;i++)
   {
        G.addedge(source, i, 1);
   }
   for (LL i = 1; i <= m;i++)
   {
        G.addedge(i + n, sink, 1);
   }
   cout << G.dinic();
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
