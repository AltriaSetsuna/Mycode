#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<vector<LL>> dis;
void releax(LL now)
{
    LL n = dis.size();
    for (LL i = 0; i < n;i++)
    {
        for (LL j = 0; j < n;j++)
        {
            LL temp = (dis[i][now] == LLONG_MAX || dis[now][j] == LLONG_MAX) ? LLONG_MAX : dis[i][now] + dis[now][j];
            if(temp<dis[i][j])
            {
                dis[i][j] = temp;
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
   dis = vector<vector<LL>>(n, vector<LL>(n, LLONG_MAX));
   for (LL i = 0; i < n;i++)
   {
        dis[i][i] = 0;
   }
        vector<LL> time(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> time[i];
   }
   for (LL i = 0; i < m;i++)
   {
       LL u, v, w;
       cin >> u >> v >> w;
       dis[u][v] = w;
       dis[v][u] = w;
   }
   LL q;
   cin >> q;
   LL now = 0;
   while(q--)
   {
       LL x, y, t;
       cin >> x >> y >> t;
       while(time[now]<=t&&now<n)
       {
            releax(now);
            now++;
       }
       cout << ((dis[x][y] == LLONG_MAX || now <= y || now < x) ? -1 : dis[x][y]) << endl;
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
