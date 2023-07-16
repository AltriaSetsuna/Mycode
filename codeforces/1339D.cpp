#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) ((x) + (k) - 1) / (k)
#define continue(x) if(x){continue;}
#define break(x) if(x){break;}
void LOCAL();
using namespace std;

typedef struct edge
{
    LL to, weight, next;
    edge(LL to,LL weight,LL next)
    {
        this->to = to, this->weight = weight, this->next = next;
    }
} edge;
vector<edge> edges;
vector<LL> head;
void addedge(LL from,LL to,LL weight)
{
    edges.emplace_back(edge(to, weight, head[from]));
    head[from] = (LL)edges.size() - 1LL;
}
vector<LL> de;
bool odd = false;
void dfs(LL now,LL fa,LL sta)
{
    if(de[now]==1 && sta==1)
    {
        odd = true;
    }
    for (LL i = head[now]; ~i;i=edges[i].next)
    {
        continue(edges[i].to == fa);
        dfs(edges[i].to, now, sta ^ 1);
    }
}
inline void solve()
{
    LL n;
    cin >> n;
    head = vector<LL>(n + 1, -1);
    de = vector<LL>(n + 1, 0);
    for (LL i = 1; i < n;i++)
    {
        LL a, b;
        cin >> a >> b;
        addedge(a, b, 0);
        addedge(b, a, 0);
        de[a]++, de[b]++;
    }
    for (LL i = 1; i <= n;i++)
    {
        if(de[i]==1)
        {
            dfs(i, 0, 0);
            break;
        }
    }
    LL mi = odd ? 3 : 1;
    LL ma = n - 1;
    for (LL i = 1; i <= n;i++)
    {
        LL sum = 0;
        for (LL j = head[i]; ~j;j=edges[j].next)
        {
            sum += de[edges[j].to] == 1;
        }
        ma -= max(0LL, sum - 1);
    }
    cout << mi << ' ' << ma;
    return;
}


int main()
{
   LOCAL();
   solve();
   return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("\\Mycode\\build\\in.txt","r",stdin);freopen("\\Mycode\\build\\out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
