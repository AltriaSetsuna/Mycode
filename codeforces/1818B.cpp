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
    LL n;
    cin >> n;
    if(n==1)
    {
        cout << 1 << endl;
    }
    else 
    {
        if(n&1)
        {
            cout << -1 << endl;
        }
        else
        {
            LL l = 2, r = 1;
            for (LL i = 1; i * 2 <= n;i++)
            {
                cout << l << ' ' << r <<" \n"[i*2==n];
                l += 2, r += 2;
            }
        }
    }
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
