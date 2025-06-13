bool startsWith(string prefix) {
       Node* temp = root ; //
       for(int i = 0 ; i<prefix.size() ;i++)
       {
        if(temp->children.count(prefix[i]) == 1)
        {
            temp = temp->children[prefix[i]];
        }
        else
        {
            return false;
        }
       }
       return true;
    }