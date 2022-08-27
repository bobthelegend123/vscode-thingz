#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,K,a,b;
	cin>>N>>K;
	vector <int> T;
	int A[N];
	
	for (int i=0;i<N;i++){
		cin>>a;
		T.push_back(a);
	}
	
	int sum=0;
	for (int i=0;i<N;i++){
		T.erase(max_element(T.begin(), T.begin()+K-1)+1);
		b=*max_element(T.begin(), T.begin()+K-1);
		cout<<"Number removed"<< b<<endl;
		sum+=b;
		A[i]=sum;
		for (vector<int>::iterator it = T.begin(); it != T.end(); it++){
			cout<<*it <<" ";
		}
	}
	
	for (int i=0;i<N;i++){
		cout<<A[i]<<" "<<endl;
	}
		
//    cout<<*max_element(T.begin(), T.begin()+K-1);

}
