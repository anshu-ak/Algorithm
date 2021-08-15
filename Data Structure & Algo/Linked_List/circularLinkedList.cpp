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
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    //base case,i.e,head = NULL means it will show error during while loop runs which causes(infinte loop)
    if(head==NULL){
        n->next=n;//coz, n is first node. so it is a startiing  node as well as ending node.that's why uske end mein wo khud aa jayege
        head=n;

    }else{

    
   
        node* temp=head;
        //using traverse method , move temp to last node
        while(temp->next!=head){
            temp=temp->next;
        }
        //finally , temp reaches to last node
        temp->next=n;
        n->next=head;
        head=n;//head becomes new node
    }
}
void insertAtTail(node* &head,int val){
    //Base case:- if there is no node in linked list. i.e head==NULL
    if(head==NULL){
        insertAtHead(head,val);
    }else{
        node* n=new node(val);
        node* temp=head;
        while(temp->next!=head){//here, it is circular linked list.so,  when temp reaches to last node
            temp=temp->next;
        }
        // we reaches to last node
        temp->next=n;
        //since it is circular linked list. so,
        n->next=head;

    }
}   
void deleteAtHead(node* &head){
    node* temp=head;
    //using traverse method, temp reach to last node
    while(temp->next!=head){
        temp=temp->next;

    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next; 
    delete todelete;
}
void  deletion(node* &head, int pos){//at which position , we want to delete
    //base case: to delete at head
    if(pos==1){
        deleteAtHead(head);
    }else{
        node* temp=head;

        int count=1;
        while(count!=pos-1){
            temp=temp->next;
            count++;

        }
        // make a new node (name: todelete)
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
}
void display(node* &head){
    node* temp=head;
    //Here , we have to take care of some point .i.e,
    // (1) if we apply while loop and giving condition(temp->next!=head),then it can't access last node of linkedList.so we can't use this
    // (2) if condition is ( temp!=head) then loop will not run .coz, initially , temp initializes with head.hence , it can't print the node
    // (3) To avoid these mistakes, we apply (do-while loop) 
    do{
        cout<<temp->data<<" ";
        temp=temp->next;//now , temp !=head.hence , loop will run
 
    }while(temp!=head);
    //temp reaches to head;
    cout<<endl;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4};
    for(int i=0;i<4;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,5);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}