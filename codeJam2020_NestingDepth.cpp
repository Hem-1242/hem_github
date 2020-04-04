#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int _case;
    cin >> _case;
    for(int h=1; h <= _case; h++)
    {
        string s,_s;
        cin >> s;
        long int z=0;
        char arr[s.length()+1];
        strcpy(arr, s.c_str());
        for(int i=0;i<s.length();i++)
        {
            if(z<((int)(arr[i])-48))
            {
                for(int j=0;j<(((int)(arr[i])-48)-z);j++)
                {
                    _s += '(';
                }
                z+=(((int)(arr[i])-48)-z);
                _s +=arr[i];
            }
            else if(z>((int)(arr[i])-48))
            {
                for(int j=0;j<(z-((int)(arr[i])-48));j++)
                {
                    _s += ')';
                }
                z-=(z-((int)(arr[i])-48));
                _s += arr[i];
            }
            else
            {
                _s += arr[i];
            }
        }
        for(int x=0; x<z; x++)
        {
            _s+=')';
        }
        cout << "Case #" << h << ": "<< _s << endl;
    }
    return 0;
}
