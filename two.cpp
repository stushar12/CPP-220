void inOrder(Node* root,vector<int> &v)
{
    if(root==NULL)
     return;
   
    inOrder(root->left,v);
   
    v.push_back(root->data);
   
    inOrder(root->right,v);
}

void traverse(Node* root,map<vector<int>,int> &mp)
{
    if(root==NULL)
      return;
    
    vector<int> v;
    inOrder(root,v);
    mp[v]++;
    
    traverse(root->left,mp);
    
    traverse(root->right,mp);
    
}

bool dupSub(Node* root)
{
    map<vector<int>,int> mp;
    traverse(root,mp);
    int flag=0;
    for(auto i:mp)
    {
         if(i.second>1 and i.first.size()>=2)
         {
            return 1;
            flag=1;
            break;
         }
    }
    return 0;
