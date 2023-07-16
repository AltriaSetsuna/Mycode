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


inline void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<pair<LL, LL>> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    LL ans = 1;
    for (LL i = 0; i + 1 < n;i++)
    {
        ans += a[i].second + 1 != a[i + 1].second;
    }
    YESNO(ans <= k);
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
