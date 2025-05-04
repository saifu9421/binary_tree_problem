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
 
vector<int> left_vew(Node *root){
       bool frq [3005] = {false};
     vector<int>v;
      if(root == NULL) return v;
        queue<pair<Node *,int>> q;
          if(root)  q.push({root,1});
          while (!q.empty())
           {  
               pair<Node*,int> p = q.front();
                q.pop();
                 Node *node = p.first;
                  int  level =  p.second;
                    if(frq[level] == false){
                         v.push_back(node->val);
                         frq[level] =  true;
                    };
                    if(node->left) q.push({node->left,level+1});
                       if(node->right) q.push({node->right,level+1});
            /* code */
          }
            return v;

}

 int main(){
        Node *root = input_tree();
         vector<int> vew_data = left_vew(root);
         vector<int> ::  iterator it;
           for(it = vew_data.begin(); it != vew_data.end() ; it++){
                cout<<*it<<" ";
           }
     return 0;
 }