#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
      int val; 
       Node*left;
        Node*right;
         Node(int val){
         this->val = val;
          this->left = NULL;
          this->right = NULL;
         };
         
};
  
Node *input_tree(){
    int val;
     cin>>val;
       Node *root;
        if(val == -1){
                root = NULL;
        }else{
             root = new Node(val);
        };
        queue<Node*> q;
        if(root)q.push(root);
        while (!q.empty())
        {
              Node*p = q.front();
              q.pop();
               int l,r;
               Node*left;
                Node*right;
                cin>>l>>r;
                 if(l == -1){
                     left = NULL;
                 }else{
                     left =  new Node(l);
                 };
                  if(r == -1){
                     right = NULL;
                  }else{ 
                     right = new Node(r);
                  };
                  p->left = left;
                  p->right = right;
                if(p->left) q.push(p->left);
                 if(p->right) q.push(p->right);
            /* code */
        };
         return root;
};
 
int height(Node*root){
       if(root == NULL)  return 0;
         int l =  height(root->left);
          int r =  height(root->right);
          return max(l,r)+1;     
};
int diameter(Node*root){
    if(root == NULL) return 0;
     int l = height(root->left);
      int r =  height(root->right);
      
       int subl = diameter(root->left);
         int subr = diameter(root->right);
           return  max({l+r+1,subl,subr});
}; 
 int main(){
        Node *root = input_tree();
        cout<<diameter(root)<<" ";
            
     return 0;
 }