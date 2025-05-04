#include<bits/stdc++.h>
using namespace std;
    class Node{
           public:
             int val;
              Node *left;
               Node *right;
                Node(int val){
                    this->val = val;
                     this->left = NULL;
                      this->right = NULL;
                };
       };
        Node *inputTree(){
                  int val; cin>>val;
                   Node *root;
                    if(val == -1) root = NULL;
                     else root = new Node(val);
                     queue<Node *> q;
                      if(root) q.push(root);
                       while (!q.empty())
                       {   Node *p = q.front();
                         q.pop();
                          int l,r; cin>>l>>r;
                          Node *left;
                          Node *right;
                           if(l == -1) left = NULL;
                           else left = new Node(l);
                           if(r == -1) right = NULL;
                           else right = new Node(r);
                       p->left = left;
                       p->right = right;
                       if(p->left) q.push(p->left);
                       if(p->right) q.push(p->right);
                           /* code */
                       };
       
                       return root;
             };
              
             vector<int> reverse_tree(Node *root){
                   vector<int>v;
                  if(root== NULL) return v;
                   queue<Node*>q;
                     if(root != NULL) q.push(root);
                     while (!q.empty())
                     {
                          Node *p = q.front();
                           q.pop();
                              v.push_back(p->val);
                                if(p->left) q.push(p->left);
                                 if(p->right) q.push(p->right);
                        /* code */
                     };
                      reverse(v.begin(),v.end());
                       return v;                                                      
             }
 int main(){
   Node *root =  inputTree();
   vector<int> v = reverse_tree(root);
    vector<int> :: iterator  it;
    for(it =  v.begin(); it != v.end();it++){
         cout<<*it<<" ";
    };
    
     return 0;
 }