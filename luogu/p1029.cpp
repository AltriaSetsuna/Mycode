#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL get(LL n)
{
    LL ans = 1;
    for (LL i = 2; i * i <= n;i++)
    {
        while(n%i==0)
        {
            ans++;
            n /= i;
        }
    }
    if(n>1)
    {
        ans++; 
    }
    return ans;
}
int main()
{
   LOCAL();

   LL x, y;
   cin >> x >> y;
   cout << (y % x == 0 ? get(y / x) : 0);

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
