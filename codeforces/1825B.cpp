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


inline void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n * m);
    for (LL i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    LL mi = a[0], semi = a[1], ma = a[a.size() - 1], sema = a[a.size() - 2];
    LL ans1 = min(m - 1, n - 1) * (ma - semi) + (n * m - 1 - min(n - 1, m - 1)) * (ma - mi);
    LL ans2 = min(n - 1, m - 1) * (sema - mi) + (n * m - 1 - min(n - 1, m - 1)) * (ma - mi);
    cout << max(ans1, ans2) << endl;
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
