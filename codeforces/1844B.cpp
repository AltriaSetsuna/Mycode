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
    LL n;
    cin >> n;
    vector<LL> a(n, 0);
    if(n<=2)
    {
        for (LL i = 1; i <= n;i++)
        {
            cout << i << " \n"[i == n];
        }
        return;
    }
    a[n / 2] = 1;
    a[0] = 2;
    a[n - 1] = 3;
    LL sum = 4;
    for (LL i = 0; i < n;i++)
    {
        if(a[i]==0)
        {
            a[i] = sum++;
        }
    }
    for (LL i = 0; i < n;i++)
    {
        cout << a[i] << " \n"[i + 1 == n];
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
