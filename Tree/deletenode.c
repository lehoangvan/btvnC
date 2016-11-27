KeyType DeleteMin (TreeType* Root){  //find and delete most left node
  KeyType k;
  if((*Root)->left==NULL){
    k=(*Root)->key;
    (*Root)=(*Root)->right;
    return k;
  }
  else return DeleteMin(&(*Root)->left);
}

void DeleteNode(key X, TreeType *Root) // delete a node from BST
{
  if(*Root!=NULL)
    if (x <(*Root)->Key) DeleteNode(x,&(*Root)->left);
    else if(x>(*Root)->Key){ DeleteNode(x,&(*Root)->right); *Root=NULL;}
    else if((*Root)->left==NULL) *Root=(*Root)-right;
    else if((*Root)->right==NULL) *Root=(*Root)->left;
    else (*Root)->Key=DeleteMin(&(*Root)->right);
}

