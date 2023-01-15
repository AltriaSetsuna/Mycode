#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

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

int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   tree = vector<LL>(n + 1, 0);
   for (LL i = 1; i <= n;i++)
   {
        LL x;
        cin >> x;
        add(i, x);
   }
   for (LL i = 0; i < m;i++)
   {
        LL op, x, k;
        cin >> op >> x >> k;
        if(op==1)
        {
            add(x, k);
        }
        else if(op==2)
        {
            cout << sum(k) - sum(x - 1) << endl;
        }
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