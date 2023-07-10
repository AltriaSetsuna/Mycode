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
void LOCAL();
using namespace std;


inline void solve()
{
    LL n, k, x;
    cin >> n >> k >> x;
    if(x!=1)
    {
        YES();
        cout << n << endl;
        for (LL i = 0; i < n;i++)
        {
            cout << 1 << " \n"[i + 1 == n];
        }
    }
    
    else
    {
        YES();
        cout << n / 2 << endl;
        for (LL i = 3; i < n;i+=2)
        {
            cout << 2 << ' ';
        }
        cout << (n % 2 == 1 ? 3 : 2) << endl;
    }
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
