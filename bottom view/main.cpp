 vector <int> bottomView(Node *root) {
        vector<int> result;
        if(!root) return result;
        map<int,int>m;
        queue<std::pair<Node*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>ele=q.front();
            q.pop();
            Node* node=ele.first;
            int dis=ele.second;
            m[dis]=node->data;
            if(node->left!=NULL){
                q.push({root->left, dis-1});
            }
            if(node->right!=NULL){
                q.push({root->right, dis+1});
            }
        }
        for(const auto ele: m){
            result.push_back(ele.second);
        }
    }