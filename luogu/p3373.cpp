#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


class segment_tree
{
private:
    typedef struct node
    {
        LL data;
        LL add = 0, mul = 1;
        LL l, r;
    }node;
    vector<node> tree;
    LL mod = LLONG_MAX;
    LL right_son(LL p)
    {
        return (p << 1) | 1;
    }
    LL left_son(LL p)
    {
        return p << 1;
    }
    void build(LL pos,LL l,LL r,vector<LL>&a)
    {
        tree[pos].l = l,tree[pos].r = r;
        if(l==r)
        {
            tree[pos].data = a[l - 1] % mod;
            return;
        }
        LL mid = (l + r) >> 1LL;
        build(left_son(pos), l, mid, a);
        build(right_son(pos), mid + 1, r, a);
        tree[pos].data = (tree[left_son(pos)].data + tree[right_son(pos)].data) % mod;
        return;
    }
    void spread(LL pos)
    {
        if(tree[pos].add!=0LL||tree[pos].mul!=1LL)
        {
            LL rson = right_son(pos), lson = left_son(pos);
            tree[rson].data = (tree[rson].data * tree[pos].mul + tree[pos].add * (tree[rson].r - tree[rson].l + 1LL)) % mod;
            tree[lson].data = (tree[lson].data * tree[pos].mul + tree[pos].add * (tree[lson].r - tree[lson].l + 1LL)) % mod;
            tree[rson].mul = tree[rson].mul * tree[pos].mul % mod;
            tree[rson].add = (tree[rson].add * tree[pos].mul + tree[pos].add) % mod;
            tree[lson].mul = tree[lson].mul * tree[pos].mul % mod;
            tree[lson].add = (tree[lson].add * tree[pos].mul + tree[pos].add) % mod;
            tree[pos].add = 0LL, tree[pos].mul = 1LL;
        }
        return;
    }
    void add(LL pos,LL l,LL r,LL addend)
    {
         if(tree[pos].l>=l&&tree[pos].r<=r)
         {
            tree[pos].add = (tree[pos].add + addend) % mod;
            tree[pos].data = (tree[pos].data + addend * (tree[pos].r - tree[pos].l + 1)) % mod;
            return;
         }
         spread(pos);
         LL mid = (tree[pos].l + tree[pos].r) >> 1LL;
         if(mid>=l)
         {
            add(left_son(pos), l, r, addend);
         }
         if(mid<r)
         {
            add(right_son(pos), l, r, addend);
         }
         tree[pos].data = (tree[left_son(pos)].data + tree[right_son(pos)].data) % mod;
         return;
    }
    void multiply(LL pos,LL l,LL r,LL multiplier)
    {
        if(tree[pos].l>=l&&tree[pos].r<=r)
        {
            tree[pos].add = tree[pos].add * multiplier % mod;
            tree[pos].mul = tree[pos].mul * multiplier % mod;
            tree[pos].data = tree[pos].data *multiplier % mod;
            return;
        }
        spread(pos);
        LL mid = (tree[pos].l + tree[pos].r) >> 1LL;
        if(mid>=l)
        {
            multiply(left_son(pos), l, r, multiplier);
        }
        if(mid<r)
        {
            multiply(right_son(pos), l, r, multiplier);
        }
        tree[pos].data = (tree[left_son(pos)].data + tree[right_son(pos)].data) % mod;
        return;
    }
    LL query(LL pos,LL l,LL r)
    {
        if(tree[pos].l>=l&&tree[pos].r<=r)
        {
            return tree[pos].data;
        }
        spread(pos);
        LL ans = 0;
        LL mid = (tree[pos].l + tree[pos].r) >> 1LL;
        if(mid>=l)
        {
            ans = (ans + query(left_son(pos), l, r)) % mod;
        }
        if(mid<r)
        {
            ans = (ans + query(right_son(pos), l, r)) % mod;
        }
        return ans;
    }
public:
    segment_tree(vector<LL>&a,LL mod)
    {
        this->mod = mod;
        tree = vector<node>(a.size() * 4 + 2);
        build(1, 1, a.size(), a);
        return;
    }
    segment_tree(vector<LL>&a)
    {
        tree = vector<node>(a.size() * 4 + 2);
        build(1, 1, a.size(), a);
        return;
    }
    LL query(LL l,LL r)
    {
        return query(1, l, r);
    }
    void add(LL l,LL r,LL addend)
    {
        add(1, l, r, addend);
        return;
    }
    void multiply(LL l,LL r,LL multiplier)
    {
        multiply(1, l, r, multiplier);
        return;
    }
};
//segment_tree t(vector<LL> a(n),LL mod)
//a从0开始记录数据
int main()
{
   LOCAL();
   LL n, m, p;
   cin >> n >> m >> p;
   vector<LL> a(n);
   for (LL i = 0; i < n;i++)
   {
        cin >> a[i];
   }
   segment_tree t(a, p);
   for (LL i = 0; i < m;i++)
   {
        LL op;
        cin >> op;
        if(op==1)
        {
            LL x, y, k;
            cin >> x >> y >> k;
            t.multiply(x, y, k);
        }
        else if(op==2)
        {
            LL x, y, k;
            cin >> x >> y >> k;
            t.add(x, y, k);
        }
        else
        {
            LL x, y;
            cin >> x >> y;
            cout << t.query(x, y) << endl;
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
