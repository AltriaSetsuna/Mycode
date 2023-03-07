#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


int main()
{
   LOCAL();

   string s;
   cin >> s;
   vector<vector<LL>> ans(s.size(), vector<LL>(s.size()));
   for (LL i = 0;i<s.size();i++)
   {
      ans[i][i] = 1;
      for (LL j = i + 1; j < s.size();j++)
      {
         ans[i][j] = LLONG_MAX;
      }
   }
      LL step = 0;
   while(++step<s.size())
   {
       for (LL i = 0, j = i + step; j < s.size();i++,j++)
       {
           if(s[i]==s[j])
               ans[i][j] = min(ans[i][j - 1], ans[i + 1][j]);
            else
               for (LL k = i; k < j;k++)
               {
                  ans[i][j] = min(ans[i][j], ans[i][k] + ans[k + 1][j]);
               }
       }
   }
   cout << ans[0][s.size() - 1];
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
