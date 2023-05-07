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
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    for (LL liar = 0; liar < n; liar++)
    {
        LL act = 0;
        for (LL i = 0; i < n; i++)
        {
            act += a[i] > liar;
        }
        if (act == liar)
        {
            cout << act << endl;
            return;
        }
    }
    cout << -1 << endl;
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
