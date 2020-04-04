#include<bits/stdc++.h>
using namespace std;
int main()
{
    int _case,b;
    cin >>_case;
    cin >> b;
    while(_case--)
    {
      char ch,r;
      string _s = "";
      for(int j=0;j<10;j++)
      _s+='0';
      for(int i=1;i<=10;i++)
      {
          cout<<i<<"\n";
          cout.flush();
          cin >>ch;
          _s[i-1]=ch;
      }
      cout<<_s<<"\n";
      cout.flush();
      cin >>r;
      if(r=='Y')
          continue;
      else
          return 0;
    }
    return 0;
}
