#include<iostream>
using namespace std;
#include<string>

  
string reverse_string(string s)
{
    int n=s.length();
    for(int i=0,j=n-1;i<n/2,j>=n/2;i++,j--)
    {
        swap(s[i],s[j]);
    }
    return s;
}   

int main()
{
    cout<<"ENTER A STRING TO REVERSE:"<<endl;
    string str;
    cin>>str;

    cout<<"ORIGINAL STRING: "<<str<<endl;
    str=reverse_string(str);
    cout<<"REVERSED STRING: "<<str<<endl;
    return 0;
}
