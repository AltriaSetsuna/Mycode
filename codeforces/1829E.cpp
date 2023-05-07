#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;

vector<vector<LL>> G;
vector<vector<bool>> vis;
LL ans, n, m;
bool bound(LL x,LL y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}
LL dx[] = {0, 0, 1, -1};
LL dy[] = {1, -1, 0, 0};
LL value;
void dfs(LL x,LL y)
{
    vis[x][y] = true;
    value += G[x][y];
    ans = max(ans, value);
    for (LL i = 0; i < 4;i++)
    {
        LL xx = x + dx[i], yy = y + dy[i];
        if(bound(xx,yy)&&G[xx][yy]&&vis[xx][yy]==false)
        {
            dfs(xx, yy);
        }
    }
}
inline void solve()
{
    
    cin >> n >> m;
    ans = 0;
    G = vector<vector<LL>>(n, vector<LL>(m));
    vis=vector<vector<bool>>(n, vector<bool>(m,false));
    for (LL i = 0; i < n;i++)
    {
        for (LL j = 0; j < m;j++)
        {
            cin >> G[i][j];
        }
    }
    for (LL i = 0; i < n;i++)
    {
        for (LL j = 0; j < m;j++)
        {
            if(vis[i][j]==false && G[i][j])
            {
                value = 0;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    G.clear();
    vis.clear();
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
