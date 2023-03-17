#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


inline void solve()
{
    LL n, x;
    cin >> n >> x;
    bool zero = true, one = false;
    LL sum = 0;
    for (LL i = 0; i < n;i++)
    {
        LL t;
        cin >> t;
        sum += t - x;
        if(t!=x)
            zero = false;
        if(t==x)
            one = true;
    }
    if(zero)
        cout << 0 << endl;
    else if(sum==0||one)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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
