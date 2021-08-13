#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;

    }

};
void insertattail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
    }else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=n;
    }
}
//To find the length of linked list
int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;

    }
    return l;
}
//create kappend function
node* kappend(node* &head,int k ){
    int l=length(head);
    node* newtail;
    node* newhead;
    node* tail=head;
    //sometimes, k>l in this case , we take a mod..
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        count++;
        tail=tail->next;
    }
    newtail->next=NULL;
    tail->next=head;
    head=newhead;
    return head;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertattail(head,arr[i]);
    }
    display(head);
    kappend(head,3);
    display(head);
    return 0;
}