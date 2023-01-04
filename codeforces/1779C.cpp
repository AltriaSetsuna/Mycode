#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

inline LL get(vector<LL>& a)
{
   priority_queue<LL,vector<LL>,greater<LL> > q;
   LL sum = 0;
   LL ret = 0;
   for (LL i = 0; i < a.size();i++)
   {
      sum += a[i];
      q.emplace(a[i] * 2);
      while(sum<0)
      {
         sum += -q.top();
         q.pop();
         ret++;
      }
   }
   return ret;
}
inline void solve()
{
   LL n, m;
   cin >> n >> m;
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
      cin >> a[i];
   }
   vector<LL> b, c;
   for (LL i = m - 1; i > 0;i--)
   {
      b.emplace_back(-a[i]);
   }
   for (LL i = m; i < n;i++)
   {
      c.emplace_back(a[i]);
   }
   cout << get(b) + get(c) << endl;
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