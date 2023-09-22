#include<bits/stdc++.h>
using namespace std;

int knapsek(int benifit[],int weight[],int n,int k){
 int a[n+1][k+1];
 for(int i=0; i<=n;i++){
    for(int j=0; j<=k; j++){
        if(i==0 || j==0) a[i][j]=0;
        else if(weight[i]<=j) a[i][j]=max((benifit[i]+a[i-1][j-weight[i]]),a[i-1][j]);
        else a[i][j]=a[i-1][j];
    }
 }
 return a[n][k];
}

int main(){
 int benifit[50],weight[50],k,n;
 cin>>n;
 for(int i=0; i<n; i++){
    cin>>benifit[i]>>weight[i];
 }
 cin>>k;
 int result = knapsek(benifit,weight,n,k);
 cout<<result<<endl;

return 0;
}
