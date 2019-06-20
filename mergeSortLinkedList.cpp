#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x){
        val=x;
        next=NULL;
    }
};


void print(Node *head){
    Node *p=head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

Node* pushnode(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)
        head=temp;
    else{
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    return head;
}

Node* middle(Node *head){
    Node *p=head,*q=head,*prev;
    while(q!=NULL && q->next!=NULL){
        prev=p;
        p=p->next;
        q=q->next->next;
    }
    prev->next=NULL;
    return p;
}

Node* merge(Node *p,Node *q){
    Node *h1=p,*h2=q,*m=NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->val < h2->val){
            m=pushnode(m,h1->val);
            h1=h1->next;
        }
        else{
            m=pushnode(m,h2->val);
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        m=pushnode(m,h1->val);
        h1=h1->next;
    }
    while(h2!=NULL){
        m=pushnode(m,h2->val);
        h2=h2->next;
    }
    return m;
}

Node* mergeSort(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
        
    Node *first=head;
    Node *second=middle(head);
    //print(first);
    //print(second);
    
    first=mergeSort(first);
    second=mergeSort(second);
    
    Node *mergeHead=merge(first,second);
    return mergeHead;
}

int main(){
    int n;
    cin>>n;
    Node *head=NULL;
    while(n--){
        int x;
        cin>>x;
        head=pushnode(head,x);
    }
    print(head);
    head=mergeSort(head);
    print(head);
    return 0;
}
