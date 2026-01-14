#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;
    cout<<"Enter The Num :";
    cin>>s;
    int n=s.length();
    vector<int> num;
    for(int i=0;i<n;i++){
        num.push_back(int(s[i])-48);
    }
    num.shrink_to_fit();
    for(int i=0;i<n;i++){
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}