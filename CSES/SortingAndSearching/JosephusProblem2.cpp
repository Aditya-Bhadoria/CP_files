#include<stdio.h>
typedef struct Node{
    int val;
    struct Node* next;
}node;
void create(int value,node* tail){
    node* new=(node*)malloc(sizeof(node));
    new->val=value;
    tail->next=new;
    new->next=NULL;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    node* head=(node*)malloc(sizeof(node));
    head->val=1;
    head->next=NULL;
    node* tail=head;
    for(int i=2;i<=n;i++){
        create(i,tail);
        tail=tail->next;
    }
    
    
    
    
    tail->next=head;
    
    
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k;j++){
            tail=tail->next;
        }
        printf("%d ",tail->next->val);
        tail->next=tail->next->next;
    }
    printf("%d",tail->val);
    return 0;
}