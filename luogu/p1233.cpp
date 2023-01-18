#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

bool cmp(pair<LL,LL>a ,pair<LL,LL> b)
{
    if(a.first==b.first)
    {
        return a.second > b.second;
    }
    return a.first > b.first;
}
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   vector<pair<LL, LL>> a(n);
   for (LL i = 0; i < n;i++)
   {
       cin >> a[i].first >> a[i].second;
   }
   sort(all(a),cmp);
   vector<LL> ans;
   ans.emplace_back(a[0].second);
   for (LL i = 1; i < n;i++)
   {
    if(a[i].second>ans.back())
    {
        ans.emplace_back(a[i].second);
    }
    else
    {
        *lower_bound(all(ans), a[i].second) = a[i].second;
    }
   }
   cout << ans.size();
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
