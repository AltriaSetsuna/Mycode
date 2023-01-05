#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    LL ans = 0;
    LL odd_num = 0, odd_to_even = LLONG_MAX, even_to_odd = LLONG_MAX;
    for (LL i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        if(x%2)
        {
            odd_num++;
            LL t = 0;
            while(x%2)
            {
                t++;
                x /= 2;
            }
            odd_to_even = min(odd_to_even, t);
        }
        else
        {
            LL t = 0;
            while(x%2==0)
            {
                t++;
                x /= 2;
            }
            even_to_odd = min(even_to_odd, t);
        }
    }
    ans += odd_num % 2 ? min(odd_to_even, even_to_odd) : 0;
    cout << ans << endl;
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