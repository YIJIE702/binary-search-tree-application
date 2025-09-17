#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode* FindMin(treeNode *node)
{
    if(node==NULL)
    {
        // There is no element in the tree
        cout<<"There is no element in tree";
        return NULL;
    }
    if(node->left) // Go to the left sub tree to find the min element
        return FindMin(node->left);
    else
        return node;
}

treeNode* FindMax(treeNode *node)
{
    if(node==NULL)
    {
        // There is no element in the tree
        cout<<"There is no element in tree";
        return NULL;
    }
    if(node->right) // Go to the right sub tree to find the max element
        return(FindMax(node->right));
    else
        return node;
}

treeNode *Insert(treeNode *node, int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        //temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    // Else there is nothing to do as the data is already in the tree.
    else
    {
        cout<<"The element been existed!";
    }
    return node;
}

treeNode * Delete(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        {
            // Here we will replace with minimum element in the right sub tree
            temp = FindMin(node->right);
            node -> data = temp->data;
            // As we replaced it with some other node, we have to delete that node
            node -> right = Delete(node->right,temp->data);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); // temp is longer required
        }
    }
    return node;
}

//Search Function
treeNode * Find(treeNode *node, int data)
{
    if(node==NULL)
    {
        // Element is not found
        return NULL;
    }
    if(data > node->data)
    {
        // Search in the right sub tree.
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
        // Search in the left sub tree.
        return Find(node->left,data);
    }
    else
    {
        // Element Found
        return node;
    }
}

void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

void Preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    treeNode *root = NULL,*temp;
    int ch;
    char ans = 'N';
    //clrscr();
    while(1)
    {   cout<<"\n\n****** Binary Search Tree MENU ********";
        cout<<"\n1.Create a BST\n2.Insert Element\n3.Delete Element\n4.Display - Traversals\n";
        cout<<"5.FindMin\n6.FindMax\n7.Search\n8.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
             do{
            cout<<"\nPlease enter the element to be insert:";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"\nWant to insert more elements?(y/n)";
            ans = getch();
            } while (ans == 'y');
            cout<<"\nInsert complete!";
            break;
        case 2:
            cout<<"\nPlease enter the element to be insert:";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"Insert complete!";
            break;
        case 3:
            cout<<"\nPlease enter the element to be delete:";
            cin>>ch;
            root = Delete(root,ch);
            cout<<"\nAfter deletion, the elements in BST are:";
            Inorder(root);
            break;
        case 4:
            cout<<"\nInorder Traversals is:";
            Inorder(root);
            cout<<"\nPreorder Traversals is:";
            Preorder(root);
            cout<<"\nPostorder Traversals is:";
            Postorder(root);
            break;
        case 5:
            temp = FindMin(root);
            cout<<"\nMinimum element is :"<<temp->data;
            break;
        case 6:
            temp = FindMax(root);
            cout<<"\nMaximum element is :"<<temp->data;
            break;
        case 7:
            cout<<"\nPlease enter the element to be search:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element is not found";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;
        case 8:
            exit(0);
            break;
        default:
            cout<<"Wrong input!\nPlease try again.";
            break;
        }
    }
    return 0;
}
