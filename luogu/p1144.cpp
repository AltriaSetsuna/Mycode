#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 100003;
vector<vector<LL>> G;
vector<LL> ans;
vector<LL> deep;
void bfs(LL source,LL n)
{
   vector<bool> vis(n + 1, false);
   ans[source] = 1;
   queue<LL> q;
   q.emplace(source);
   vis[source] = true;
   while(q.size())
   {
      LL now = q.front();
      q.pop();
      for (LL i = 0; i < G[now].size();i++)
      {
         LL son = G[now][i];
         if(vis[son]==false)
         {
            deep[son] = deep[now] + 1;
            vis[son] = true;
            q.emplace(son);
         }
        
         if(deep[son]==deep[now]+1)
         {
            ans[son] += ans[now];
            ans[son] %= mod;
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
   G = vector<vector<LL>>(n + 1);
   ans = vector<LL>(n + 1, 0);
   deep = vector<LL>(n + 1, 0);
   for (LL i = 0; i < m;i++)
   {
      LL x, y;
      cin >> x >> y;
      G[x].emplace_back(y);
      G[y].emplace_back(x);
   }
   bfs(1, n);
   for (LL i = 1; i <= n;i++)
   {
      cout << ans[i] << endl;
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
