#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int _case,_size,k,r,c;
   cin >> _case;
   for(int h=1;h<=_case;h++)
   {
        k=0;
        cin >> _size;
        int a[_size][_size];
        set <int> s;
        r=0,c=0;
        for(int i=0;i<_size;i++)
        {
            for(int j=0;j<_size;j++)
            {
                cin >>a[i][j];
                s.insert(a[i][j]);
                if(i==j)
                {
                    k = k + a[i][j];
                }
            }
            if(s.size()<_size)r++;
            s.clear();
        }
        for(int j=0;j<_size;j++)
        {
            for(int i=0;i<_size;i++)
            {
                s.insert(a[i][j]);
            }
            if(s.size()<_size)c++;
            s.clear();
        }
       cout<<"Case #"<<h<<": "<<k<<" "<<r<<" "<<c<<endl;
   }
}
