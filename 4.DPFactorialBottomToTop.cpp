//DP4.Factorial (Bottom to top approach) 
#include<iostream>
using namespace std;
const int N = 1000;
int f[N];

void fact(){
	for(int i = 2; i<N; i++){
		f[i] = f[i-1]*i;
	}
}

int main(){
	f[1] = 1;
	fact();
	int n = 3;
	printf("%d",f[n]);
}