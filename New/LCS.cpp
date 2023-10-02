#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,s1;
  cout<<"Enter string 1 :";
  cin>>s;
  cout<<"Enter string 2 :";
  cin>>s1;
  int n=s.length();
  int m= s1.length();

  int a[n+1][m+1];
    for(int i=0; i<=n; i++){
      for(int j=0; j<=m; j++){
         if(i==0|j==0){
            a[i][j]=0;
           }
         else if(s[i-1]==s1[j-1]){
                a[i][j]=a[i-1][j-1]+1;
              }
         else{
                a[i][j]=max(a[i][j-1],a[i-1][j]);
            }
        }
    }
   cout<<"LCM length is:"<<a[n][m]<<endl;

  return 0;
}
