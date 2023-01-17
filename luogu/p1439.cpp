#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

template<typename T>
LL lcs(T a,T b)
{
    LL lena = a.size(), lenb = b.size();
    vector<vector<LL>> dp(2, vector<LL>(lenb + 1, 0));
    for (LL i = 0; i < a.size();i++)
    {
        for (LL j = 0; j < b.size();j++)
        {
            if(a[i]==b[j])
            {
                dp[i & 1][j + 1] = dp[(i + 1) & 1][j] + 1;
            }
            else
            {
                dp[i & 1][j + 1] = max(dp[i & 1][j], dp[(i + 1) & 1][j + 1]);
            }
        }
    }
    return dp[(lena + 1) & 1][lenb];
}
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   vector<LL> a(n), b(n);
   for (LL i = 0; i < n;i++)
   {
        cin >> a[i];
   }
   for (LL i = 0; i < n;i++)
   {
        cin >> b[i];
   }
   cout << lcs(a, b);
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
