#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack <char> brackets;
    int L;
    char a;
    cin>>L;
    for (int i=0;i<L;i++){
    	cin>>a;
    	brackets.push(a);
    	if (a==']'||a==')'||a==')'&& brackets.top()==a){
    		brackets.pop();
		}
	}
	if (brackets.size()!=L/2){
		cout<<"Invalid";
	}
	else{
		cout<<"Valid";
	}
    return 0;
}
