//https://www.geeksforgeeks.org/problems/check-if-subtree/1
bool isSame(Node* t, Node* s){
        if(t==NULL && s==NULL) return true;
        if(t==NULL || s==NULL) return false;
        if(t->data!=s->data) return false;
        return isSame(t->left,s->left) && isSame(t->right,s->right);
}
bool isSubTree(Node* T, Node* S) {
        if(S==NULL) return true;
        if(T==NULL) return false;
        if(isSame(T,S)) return true;
        return isSubTree(T->left,S) ||isSubTree(T->right,S);
}
