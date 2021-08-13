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
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;

}
void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp; 
        }
        temp=temp->next;
        count++;

    }
    temp->next=startnode;
}
void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(slow!=fast){
        
        slow=slow->next;
        fast=fast->next->next;

    
    }
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    display(head);
    cout<<detectcycle(head)<<endl;
    int pos=3;
    makecycle(head,3);
    removeCycle(head);
    display(head);
    cout<<detectcycle(head)<<endl;
    
    return 0;

}