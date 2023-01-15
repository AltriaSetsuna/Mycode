#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const int maxn = 1e5 + 1;
set<pair<int,int>> cut;
vector<int> G[maxn];
int dfn[maxn] = {0}, low[maxn];
int dfncnt = 0;
void dfs(int now,int fa)
{
    dfn[now] = low[now] = ++dfncnt;
    int childcnt = 0;
    for (int i = 0; i < G[now].size();i++)
    {
        int son = G[now][i];
        if(dfn[son]==0)//
        {
            dfs(son,now);
            low[now] = min(low[now], low[son]);
            if(low[son]>dfn[now])
            {
                cut.insert(make_pair(now, son));
            }
        }
        else if(dfn[son]<dfn[now] && son!=fa)
        {
            low[now] = min(low[now], dfn[son]);
        }
    }
    return;
}
void get_cut_edge(int n)//set<pair<int,int>> cut±£´æ¸î±ß
{
    for (int i = 1; i <= n;i++)
    {
        if(dfn[i]==0)
        {
            dfs(i,i);
        }
    }
    return;
}

int main()
{
   LOCAL();

   int n, m;
   cin >> n >> m;
   for (LL i = 0; i < m;i++)
   {
       int x, y;
       cin >> x >> y;
       G[x].push_back(y);
       G[y].push_back(x);
   }
   get_cut_edge(n);
   cout << cut.size() << endl;
   for(auto&x:cut)
   {
       cout << x.first << ' ' << x.second << endl;
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