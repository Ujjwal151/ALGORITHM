//DP1.Fibonacci (Top to bottom approach) 
#include<iostream>
#include<cstring>
using namespace std;
const int N = 10;
int f[N];

int fib(int n){
	if(f[n] != -1) return f[n];	
	if(n == 1) return 0;
	if(n == 2) return 1;
	return (f[n] = fib(n-2) + fib(n-1));
}

int main(){
	memset(f, -1, sizeof(f));
	int n = 6;
    printf("%d\n",fib(n));
}