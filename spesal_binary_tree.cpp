#include<bits/stdc++.h>
using namespace std;
  class Node{
     public:
       int val; 
        Node *left;
        Node *right;
          Node(int val){
           this->val =  val;
             this->left = NULL;
              this->right = NULL;         
          };   
  };
   
   
  Node *input_tree(){
        int val; cin>>val;
         Node *root;
           if(val == -1){
                root =  NULL;
           }else{
               root =  new Node(val);
           };
           queue<Node*> q;
             if(root!=NULL)q.push(root);
             while (!q.empty())
             {
                Node*p =  q.front();
                  q.pop();

                   int l,r;
                    cin>>l>>r;
                     Node *left;
                      Node *right;
                         if(l == -1){
                             left =  NULL;
                         }else{
                             left = new Node(l);
                         };
                          if(r == -1){
                              right = NULL;
                          }else{
                             right =  new Node(r);
                          };
                           p->left =  left;
                            p->right =  right;
                            if(p->left != NULL){
                                  q.push(p->left);
                            };
                            if(p->right != NULL){
                                 q.push(p->right);
                            };
                        };
                         return root;  
  };

//   bool special_binary_tree(Node *root){
//        if(root == NULL)  return false;
//              bool flag =  false;
//              queue<Node*>q ;
//              if(root != NULL) q.push(root);
//             while (!q.empty())
//             {
//                   Node *p = q.front();
//                    q.pop();
//                       if(p->left != NULL && p->right != NULL){
//                                 flag =  true;
//                       }else if(p->left == NULL && p->right == NULL){
//                          flag = true;
//                       }else if(p->left == NULL && p->right != NULL){
//                           return false;
//                       }else if(p->left != NULL && p->right == NULL){
//                             return  false;
//                       };

//                       if(p->left)q.push(p->left);
//                       if(p->right) q.push(p->right);
//                 /* code */
//             };
//             return flag;
                   
//   };
   
 

bool special_binary_tree(Node *root){
    if(root == NULL)  return false;
        
          queue<Node*>q ;
          if(root != NULL) q.push(root);
         while (!q.empty())
         {
               Node *p = q.front();
                q.pop();
                   
                    if(p->left == NULL && p->right != NULL){
                       return false;
                   }else if(p->left != NULL && p->right == NULL){
                         return  false;
                   };

                   if(p->left)q.push(p->left);
                   if(p->right) q.push(p->right);
             /* code */
         };
         return true;
                
};

 int main(){
    
      Node *root =  input_tree();
          if(special_binary_tree(root) ==  true){
               cout<<"true"<<endl;
          }else{
             cout<<"false"<<endl;
          }
     return 0;
 }