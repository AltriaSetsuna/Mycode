#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const LL maxn = 1e5 + 1;
const LL mod = 998244353;
LL fa[maxn], cnt_e[maxn], cnt_v[maxn] ,vis[maxn];
bool self_loop[maxn];
void init(LL n)
{
    iota(fa + 1, fa + n + 1, 1);
    fill(cnt_e, cnt_e + n + 1, 0);
    fill(cnt_v, cnt_v + n + 1, 1);
    fill(vis, vis + n + 1, 0);
    fill(self_loop, self_loop + n + 1, 0);
}
LL getfa(LL x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void merge(LL x,LL y)
{
    x = getfa(x), y = getfa(y);
    cnt_v[x] += cnt_v[y];
    cnt_e[x] += cnt_e[y];
    self_loop[x] |= self_loop[y];
    fa[y] = x;
}
inline void solve()
{
    LL n;
    cin >> n;
    init(n);
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    for (LL i = 0; i < n;i++)
    {
        LL b;
        cin >> b;
        if(getfa(a[i])!=getfa(b))
        {
            merge(a[i], b);
        }
        cnt_e[getfa(a[i])]++;
        if(a[i]==b)
        {
            self_loop[getfa(b)] = 1;
        }
    }
    LL ans = 1;
    for (LL i = 1; i <= n;i++)
    {
        LL now = getfa(i);
        if(!vis[now])
        {
            vis[now] = 1;
            if(!ans)
            {
                continue;
            }
            if(cnt_v[now]!=cnt_e[now])
            {
                ans=0;
            }
            else 
            {
                ans *= (self_loop[now] ? n : 2);
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return;
}

int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    LL t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
} 