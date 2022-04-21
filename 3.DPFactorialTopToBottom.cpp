//DP3.Factorial (Top to bottom approach) 
#include<iostream>
using namespace std;
const int N = 10000;
int f[N];

int fact(int n){
	if(n == 0) return 1;
	if(f[n] != 0) return f[n];
	f[n] = fact(n-1)*n;
	return f[n];
}

int main(){
	int n = 6;
    printf("%d",fact(n));
}
