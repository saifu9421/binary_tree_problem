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
 
 void output(Node *root){
       if(root == NULL)  return;
        queue<Node*> q;
        if(root) q.push(root);
         while (!q.empty())
         { 
             Node *p =  q.front();
               q.pop();
                cout<<p->val<<" ";
                 if(p->left) q.push(p->left);
                  if(p->right) q.push(p->right);
         };
 };
  
 vector<int>value_spacefic_level(Node*root,int level){
    vector<int>v;
          queue<pair<Node*,int>> q; 
          if(root)  q.push({root,1});
           while(!q.empty()){
             pair<Node*,int> p = q.front();
              q.pop();
              Node *node = p.first;
              int le = p.second;
               if(level == le){
                 v.push_back(node->val);
               };
                if(node->left) q.push({node->left,le+1});
                if(node->right) q.push({node->right,le+1});  
           };
           return v;
 };

 int main(){
        Node *root = input_tree();
       vector<int> vv =  value_spacefic_level(root,3);
       vector<int> :: iterator it;
       for(it =  vv.begin(); it!= vv.end();it++){
            cout<<*it<<" ";
       }
     return 0;
 }