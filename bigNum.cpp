#include<iostream>
#include<string>
using namespace std;
struct Node{
    int num;
    struct Node* nxt;
};
void printBigNumSerially(struct Node* head){
    if(head==NULL){return;}
    printBigNumSerially(head->nxt);
    cout<<head->num;
    return;
}
struct Node* addSmallerToBiggerBigNum(struct Node* num1,int n1,struct Node* num2,int n2){
    struct Node*ans=NULL;
    struct Node*smaller=NULL;
    if(n1>=n2){
        ans=num1;
        smaller=num2;
    }else{
        ans=num2;
        smaller=num1;
    }
    struct Node*head=ans;
    int c=0;
    while(smaller!=NULL){
        ans->num+= smaller->num +c ;
        c=(ans->num)/10;
        ans->num=(ans->num)%10;
        ans=ans->nxt;
        smaller=smaller->nxt;
    }
    while(ans!=NULL){
        ans->num+= c ;
        c=(ans->num)/10;
        ans->num=(ans->num)%10;
        ans=ans->nxt;
    }
    if(c){
        struct Node*newNode=new Node;
        newNode->num=c;
        if(n1>=n2){
            ans=num1;
        }else{
            ans=num2;
        }
        while(ans->nxt!=NULL){ans=ans->nxt;}
        ans->nxt=newNode;
    }
    return head;
}
void inputBigNum(struct Node* head,int n,string s){
        struct Node*temp=head;
    for(int i=n-2;i>=0;i--){
        struct Node*newNode=new Node;
        newNode->num=int(s[i])-48;
        newNode->nxt=NULL;
        temp->nxt=newNode;
        temp=temp->nxt;
    }

}
int main(){
    string s1;
    cout<<"Enter The Num1 :";
    cin>>s1;
    int n1=s1.length();
    struct Node*head1=new Node;
    head1->num=int(s1[n1-1])-48;
    head1->nxt=NULL;
    inputBigNum(head1,n1,s1);
    
    
    string s2;
    cout<<"Enter The Num2 :";
    cin>>s2;
    int n2=s2.length();
    struct Node*head2=new Node;
    head2->num=int(s2[n2-1])-48;
    head2->nxt=NULL;
    inputBigNum(head2,n2,s2);

    addSmallerToBiggerBigNum(head1,n1,head2,n2);
    if(n1>=n2){
        printBigNumSerially(head1);
    }else{
        printBigNumSerially(head2);
    }
    cout<<endl;
    return 0;
}