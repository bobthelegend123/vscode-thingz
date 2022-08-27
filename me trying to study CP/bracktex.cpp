#include<bits/stdc++.h>
using namespace std;

int main(){
	deque<char>brackets;
	int L,j;
	cin>>L;
	char a;
	for (int i=0;i<L;i++){
		cin>>a;
		brackets.push_back(a);
	}
	
	
	for (j=1;j<L;j+=2){
		if ((brackets[0]=='('&&brackets[j]==')')||(brackets[0]=='{'&&brackets[j]=='}')||(brackets[0]=='['&&brackets[j]==']')){
			brackets.pop_front();
			brackets.erase (brackets.begin()+j-1);
			
			for (int i = 0; i < brackets.size(); i++) {
	        	cout << brackets[i] <<  " ";
	    	}
	    	cout <<endl;
		}
		else{
			
		}
	}
	
	if (brackets.empty()){
		cout << "Valid";
	}
	else{
		cout<<"Invalid";
	}
	
	return 0;
}
