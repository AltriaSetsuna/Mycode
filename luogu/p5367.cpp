
#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 998244353;
vector<LL> tree;//tree需要自己初始化
LL lowbit(LL x)
{
   return x & -x;
}
void add(LL index,LL addend)//将第index个数加上addend
{
   while(index<tree.size())
   {
       tree[index] += addend;
       index += lowbit(index);
   }
   return;
}
LL sum(LL index)//求1-index的和
{
   LL ans = 0;
   while(index)
   {
       ans += tree[index];
       index -= lowbit(index);
   }
   return ans;
}
//不要忘记初始化tree
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   tree = vector<LL>(n + 1, 0);
   vector<LL> a(n + 1);
   vector<LL> fac(n + 1);
   fac[0] = 1;
   for (LL i = 1; i <= n;i++)
   {
       cin >> a[i];
       add(i, 1);
       fac[i] = i * fac[i - 1] % mod;
   }
   LL ans = 1;
   for (LL i = 1; i <= n;i++)
   {
       add(a[i], -1);
       ans += fac[n - i] * sum(a[i]) % mod;
   }
   cout << ans % mod;
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
