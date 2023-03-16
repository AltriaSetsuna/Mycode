#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    vector<vector<LL>> a(n);
    map<LL, LL> m;
    for (LL i = 0; i < n;i++)
    {
        LL k;
        cin >> k;
        a[i] = vector<LL>(k);
        for (LL j = 0; j < k;j++)
        {
            cin >> a[i][j];
            m[a[i][j]]++;
        }
    }
    for (LL i = 0; i < n; i++)
    {
        bool flag = false;
        for (auto&x:a[i])
        {
            if(m[x]==1)
            {
                flag = true;
                break;
            }
        }
        if(flag==false)
        {
            return void(yesno(1));
        }
    }
    return void(yesno(0));
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