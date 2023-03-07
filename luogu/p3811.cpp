#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
#define endl '\n'
void LOCAL();
using namespace std;

vector<LL> get_inv(LL n,LL mod)//线性时间内得到1-n对mod的逆元
{
    vector<LL> inv(n + 1);
    inv[1] = 1;
    for (LL i = 2; i <= n;i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    return inv;
}

int main()
{
   LOCAL();
    
    
    LL n, p;
    cin >> n >> p;
    vector<LL> inv = get_inv(n, p);
    for (LL i = 1; i <= n;i++)
    {
        cout << inv[i] << endl;
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
