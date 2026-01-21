#include<iostream>
#include<string>
#include <cmath>
using namespace std;
int inputNum(int* arr){
    string num;
    cout<<"Enter 50 digit num : ";
    cin>>num;
    cout<<"Len : "<<num.length()<<endl;
    int s=0,e=num.length()-1;
    while(s<e){
        swap(num[s++],num[e--]);
    }
    int j=0;
    for(int i=0;i<num.length()/5;i++){
        arr[j++]=((int)num[5*i+0]-48)*10000+((int)num[5*i+1]-48)*1000+((int)num[5*i+2]-48)*100+((int)num[5*i+3]-48)*10+((int)num[5*i+4]-48);
    }
    int extra=num.length()%5;
    if(extra){
        for(int i=5*(num.length()/5);i<num.length();i++){
            arr[j]+=((int)num[i]-48)*pow(10,--extra);
        }
    }
    for(int i=0;i<num.length()/5;i++){
        cout<<arr[i]<<" ";
    }
    if(num.length()%5){
        cout<<arr[j];
    }
    cout<<endl;
    return num.length();
}
int main(){
    int n=50;
    int*arr1=new int[n/5];
    int n1=inputNum(arr1);
    int*arr2=new int[n/5];
    int n2=inputNum(arr2);

    //add
    int size,smallersize,*bigger;
    if(n1>n2){
        size=n1/5;
        size+= n1%5 ? 1:0;
        smallersize=n2/5;
        smallersize+= n2%5 ? 1:0;
        bigger=arr1;
    }else{
        size=n2/5;
        size+= n2%5 ? 1:0;
        smallersize=n1/5;
        smallersize+= n1%5 ? 1:0;
        bigger=arr2;
    }
    int*ans=new int[size+1];
    int c=0,i=0;
    while(smallersize--){
        int n=arr1[i]+arr2[i]+c;
        ans[i++]=n%100000;
        c=n/100000;
    }
    while(i<size){
        int n=bigger[i]+c;
        ans[i++]=n%100000;
        c=n/100000;
    }
    if(c){
        ans[i]=1;
        size++;
    }
    int s=0,e=size-1;
    while(s<e){
        swap(ans[s++],ans[e--]);
    }
    for(int k=0;k<size;k++){
        cout<<ans[k]<<" ";
    }

    cout<<"\n\n\n\n";
    return 0;
}
