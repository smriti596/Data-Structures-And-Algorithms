#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,i;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n>>s;
	    int o=0,z=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='1')
	            o++;
	        else
	            z++;
	    }
	    if(o==z)
	        cout<<o+z<<endl;
	    else if(o==0 || z==0)
	        cout<<1<<endl;
	   else
	    cout<<(2*(min(o,z)))+1<<endl;
	}
	return 0;
}
