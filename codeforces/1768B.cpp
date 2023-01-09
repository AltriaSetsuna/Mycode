#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


inline void solve()
{
    LL n, k;
    cin >> n >> k;
    LL right = 1;
    for (LL i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        if(x==right)
        {
            right++;
        }
    }
    cout << ceil_LL(n - right + 1LL, k) << endl;
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