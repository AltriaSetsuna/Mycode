#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<int> q_de,q_in;
    int t;
    cin >> t;
    q_de.push_back(t);
    q_in.push_back(t);
    while (cin >> t)
    {
    
        if(t<=q_de[q_de.size()-1])
        {
            q_de.push_back(t);
        }
        else
        {
            auto it = upper_bound(q_de.begin(), q_de.end(), t,greater<LL>());
            *it = t;
        }    
        if (t > q_in[q_in.size() - 1])
         {
            q_in.push_back(t);
         }
         else 
         {
            auto it = lower_bound(q_in.begin(), q_in.end(), t);
           if(it!=q_in.end())
               *it = t;
         }
    }
    cout << q_de.size() << endl << q_in.size();

    return 0;
}
