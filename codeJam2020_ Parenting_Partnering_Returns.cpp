#include <bits/stdc++.h>
#include <functional>
#include <stdio.h>
using namespace std;
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb          push_back
#define all(a)      (a).begin(),(a).end()
#define x         first
#define y         second
#include <functional>
#include <stdio.h>
using namespace std;
const int N = 200006;

int gcd(int x, int y) 
{  
    if (x == 0)  
        return y; 
    return gcd(y % x, x); 
}

signed main()
{
    tezz;
    int _case,k;
    cin >> _case;
    for(int k=0;k<_case;k++)
    {
        string _s;
        int i,n;
        cin>>n;
        vector<pair<int,pair<int,int> > >v;
        int s[n],e[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i]>>e[i];
            v.pb({s[i],{e[i],i}});
            _s+='C';
        }

        sort(all(v));
        int c=0,j=0,flag=0;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].x>=c)
            {
                _s[v[i].y.y]='C';
                c=v[i].y.x;
            }

            else if(v[i].x>=j)
            {
                _s[v[i].y.y]='J';
                j=v[i].y.x;
            }

            else{
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            cout<<"Case #"<<k+1<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"Case #"<<k+1<<": "<<_s<<endl;
    }
    return 0;
}
