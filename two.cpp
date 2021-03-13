string preorder(Node* root,unordered_map<string,int> &mp)
{
    string s;
    if(root==NULL)
        return "$";
    if(root->left==NULL && root->right==NULL)
    {
        s+=to_string(root->data);
        return s;
    }
    
    s+=to_string(root->data);
    s+=preorder(root->left,mp);
    s+=preorder(root->right,mp);   
    mp[s]++;
    return s;
}

bool dupSub(Node *root)
{
    unordered_map<string,int> mp;
    preorder(root,mp);
    for(auto x:mp)
    {
    if(x.second>=2)
    return true;
    }
  return false;
}