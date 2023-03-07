#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL maxn = 1e3;
int main()
{
   LOCAL();

   LL n, m; 
   cin >> n >> m;
   bitset<maxn+1> a[m];

   for (LL i = 0; i < m;i++)
   {
      for (LL j = 0; j <= n;j++)
      {
         LL t;
         scanf("%1lld", &t);
         a[i][j] = t;
      }
   }
   LL ans = 0;
   for (LL i = 0; i < n;i++)
   {
      LL pos = i;
      while(pos<m&&a[pos][i]==0)
         pos++;
      if(pos==m)
      {
         printf("Cannot Determine");
         return 0;
      }
      ans = max(ans, pos);
      swap(a[pos], a[i]);
      for (LL j = 0; j < m;j++)
      {
         if(i==j||a[j][i]==0)
            continue;
         a[j] ^= a[i];
      }
   }
   cout << ans + 1 << endl;
   for (LL i = 0; i < n;i++)
   {
      if(a[i][n])
         cout << "?y7M#" << endl;
      else
         cout << "Earth" << endl;
   }
      return 0;
}


void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   // ios::sync_with_stdio(false);
   // cin.tie(0);cout.tie(0);
}
