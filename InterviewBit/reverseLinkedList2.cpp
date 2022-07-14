#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(B==C) return A;
    ListNode *p=A;
    int i=1;
    ListNode* prev1=NULL;
    while(p){
        if(i==B){
            // cout<<p->val<<'\n';
            ListNode* temp=prev1; 
            ListNode *prev=NULL;
            ListNode *curr=p;  //curr-2
            ListNode *next=curr->next;  //next-3
            while(i<C and next){
                curr->next=prev;
                prev=curr;
                curr=next;
                next=next->next;
                i++;
            }
            // cout<<"curr"<<curr->val<<'\n';
            // cout<<"prev"<<prev->val<<'\n';
            curr->next=prev;
            prev=curr;
            curr=next;
            // cout<<"here"<<'\n';
            if(temp!=NULL){
                ListNode *temp2=temp->next;
                // cout<<"temp2 "<<temp2->val<<'\n';
                temp->next=prev;
                temp2->next=curr;
                return A;
            }
            else{
                // cout<<"here2"<<'\n';
                A->next=curr;
                return prev;
            }
            
        }
        i++;
        prev1=p;
        p=p->next;
    }
}
ListNode *insert(ListNode *end, int key){
    ListNode *ptr=new ListNode(key);
    end->next=ptr;
    return ptr;
}
int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    ListNode *head=new ListNode(temp);

    ListNode *end=head;

    for(int i=1;i<n;i++){
        cin>>temp;
        end=insert(end,temp);
    }

    int b,c;cin>>b>>c;

    ListNode *ans=reverseBetween(head,b,c);

    while(ans){
        cout<<ans->val<<' ';
        ans=ans->next;
    }

    return 0;


}
