#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,X;
    cin >> N;
    stack <int> A;
    for (int i=0; i<N; i++){
        cin >> X;
        while (A.size() > 0 && X>=A.top()) A.pop();
        A.push(X);
    }
    while(!A.empty()){
        cout << A.top()<<'\n';
        A.pop();
    }
}