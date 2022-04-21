//DP2.Fibonacci (Bottom to top approach) 
#include<iostream>
using namespace std;
const int N = 1000;
int f[N];

void fib(){
	for(int i = 3; i<N; i++){
		f[i] = f[i-1]+f[i-2];
	}
}

int main(){
	f[1] = 0;
	f[2] = 1;
	fib();
	int n = 5;
	cout<<f[n+1];
}