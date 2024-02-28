#include <iostream>
using namespace std;

 int main(){
  int n,sum=0,r;
  cout<<"Nhap mot so nguyen: ";
  cin>>n;
  int t=n;
  while(t!=0){
    r=t%10;
    sum=sum*10+r;
    t=t/10;
  }
  if(n==sum){
    cout<<"So do la so doi xung:"<<endl;
  }else{
    cout<<"so do khong phai la so doi xung"<<endl;
  }
  return 0;
 }