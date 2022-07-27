
#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left=NULL;
    TreeNode*right=NULL;
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class ListNode{
    public:
    int val;
    ListNode*next=NULL;
    ListNode(int data){
        val=data;
        next=NULL;
    }
};

TreeNode*insertNode(TreeNode*root,int data){
    if(root==NULL){
        root=new TreeNode(data);
        return root;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*temp=q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        else{
            temp->left=new TreeNode(data);
            return root;
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        else{
            temp->right=new TreeNode(data);
            return root;
        }
        
    }
}
void inorder(TreeNode*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

ListNode*insertListNode(ListNode*head,int data){
    if(head==NULL){
        head=new ListNode(data);
        return head;
    }
    ListNode*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new ListNode(data);
    
    return head;
}

void PrintList(ListNode* head){
    ListNode*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
}

int main()
{
    int n;
    cin>>n;
    
    TreeNode*root=NULL;
    
    for(auto i=0;i<n;i++){
       int data;
       cin>>data;
       root=insertNode(root,data);
    }
    
    inorder(root);

    cout<<endl;
     
    ListNode*head=NULL;
    for(auto i=0;i<n;i++){
        int data;
        cin>>data;
        head=insertListNode(head,data);
    }
    
    PrintList(head);
    return 0;
}
