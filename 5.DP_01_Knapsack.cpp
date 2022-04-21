//5.DP 0/1 Knapsack
#include<bits/stdc++.h>
using namespace std;
const int n = 4;
const int m = 15;
int v[] = {10,10,12,18};
int w[] = {2,4,6,9};
int T[n+1][m+1];

void fun(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(w[i-1] <= j && temp > T[i-1][j])
                T[i][j] = temp;
            else T[i][j] = T[i-1][j];
        }
    }
}
void knapsack(){
    for(int i=0 ; i<=n; i++) T[i][0] = 0;
    for(int j=0 ; j<=m; j++)T[0][j] = 0;
    fun();
}

void print(){
    printf("%3c",' ');
    for(int j = 0; j<=m; j++)
        printf("%3d",j);
    cout<<"\n";

    for(int i = 0; i<=n; i++){
        printf("%3d",i);
        for(int j = 0; j<=m; j++)
            printf("%3d",T[i][j]);
        cout<<"\n";
    }
}
int main()
{
    knapsack();
    print();
}
