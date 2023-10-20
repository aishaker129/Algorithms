#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n, int val[], int we[]){
    int a[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i== 0 || j==0){
                a[i][j]= 0;
            }
            else if(we[i-1]<=j){
                a[i][j]= max((val[i-1]+a[i-1][j-we[i-1]]),a[i-1][j]);
            }
            else{
                a[i][j] = a[i-1][j];
            }
        }
    }
    return a[n][m];
}

int main(){
    int k; cin>>k;
    int n; cin>>n;
    int profit[n],weight[n];
    for(int i=0; i<n; i++){
        cin>>profit[i];
    }
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }

    int result = solve(k,n,profit,weight);
    cout<<result<<endl;
    return 0;
}
