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
void insertAtTail(node* &head, int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;

    }else{
        node* temp=head;
        while(temp->next!=NULL){//move the temp node to the last node
            temp=temp->next;


        }
        temp->next=n;
    }
}
void  evenAfterOdd(node* &head){
    //we will create 3 new node 
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            //similiarly
            even->next=odd->next;
            even=even->next;

    }

    odd->next=evenstart;
    //rare case
    if(odd->next==NULL){
        even->next=NULL;

    }
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;

    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5};
    for(int i=0; i<5;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    
    evenAfterOdd(head);
    display(head);
    return 0;
}
