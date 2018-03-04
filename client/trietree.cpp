#include <queue>  
#include <iostream>  
using namespace std;  
  
const int size = 26;  
  
struct TrieTreeNode  
{  
    char val;  
    bool isEnd;  
    int childCnt;  
    int prefixCnt;  
    TrieTreeNode *child[size];  
    TrieTreeNode(char _val)  
        :val(_val),isEnd(false),childCnt(0),prefixCnt(0)  
    {  
        memset(child,NULL,sizeof(child));//not 26!!  
    }  
};  
  
void Insert(TrieTreeNode *&root, const char *word)  
{  
    TrieTreeNode *p = root;  
    for (int i = 0; i < strlen(word); i++)  
    {  
        if(p->child[word[i]-'a'] == NULL)  
        {  
            p->child[word[i]-'a'] = new TrieTreeNode(word[i]);  
            p->childCnt++;  
        }  
        //notice!!this line need to be optimized to handle with duplicated insertion  
        p->child[word[i]-'a']->prefixCnt++;  
  
        p = p->child[word[i]-'a'];  
    }  
    p->isEnd = true;  
}  
  
bool Find(TrieTreeNode *root, const char *word)  
{  
    TrieTreeNode *p = root;  
    for (int i = 0; i < strlen(word); i++)  
    {  
        if (p->child[word[i]-'a'] == NULL)  
            return false;  
        p = p->child[word[i]-'a'];  
    }  
    return p->isEnd;  
}  
  
void LevelOrderTraverse(TrieTreeNode *root)  
{  
    if(root == NULL)  
        return;  
    queue<TrieTreeNode *> Q;  
    Q.push(root);  
    while (!Q.empty())  
    {  
        TrieTreeNode *p = Q.front();  
        cout << p->val << "(" << p->childCnt << ") ";  
        for (int i = 0; i < size; i++)  
        {  
            if(p->child[i] != NULL)  
                Q.push(p->child[i]);  
        }  
        Q.pop();  
    }  
    cout << "\n";  
}  
  
void PreOrderTraverse(TrieTreeNode *treeNode)  
{  
    if (treeNode != NULL)  
    {  
        cout << treeNode->val << "(" << treeNode->childCnt << ") ";  
        for (int i = 0; i < size; i++)  
        {  
            PreOrderTraverse(treeNode->child[i]);  
        }  
    }  
}  
  
void PostOrderTraverse(TrieTreeNode *treeNode)  
{  
    if (treeNode != NULL)  
    {  
        for (int i = 0; i < size; i++)  
        {  
            PostOrderTraverse(treeNode->child[i]);  
        }  
        cout << treeNode->val << "(" << treeNode->childCnt << ") ";  
    }  
}  
  
void MakeEmpty(TrieTreeNode *&treeNode)  
{  
    if (treeNode != NULL)  
    {  
        for (int i = 0; i < size; i++)  
        {  
            MakeEmpty(treeNode->child[i]);  
        }  
        delete treeNode;  
    }  
    treeNode = NULL;  
}  
  
void BuildTrieTree(TrieTreeNode *&root,const char *words[], int n)  
{  
    for (int i = 0; i < n; i++)  
    {  
        Insert(root,words[i]);  
    }  
}  
  
bool Remove(TrieTreeNode *&treeNode, const char *word,int pos, int n)   
{  
    if (pos == n)  
    {  
        treeNode->isEnd = false;//set the node not to be an end  
        //if the last node contains the last char is a leaf,return true to delete it  
        return treeNode->childCnt == 0;  
    }  
  
    //not found, not delete this node  
    if (treeNode->child[word[pos]-'a'] == NULL)   
        return false;  
  
    //if true, the child is a leaf, delete the child  
    if ( Remove( treeNode->child[word[pos]-'a'], word, pos+1, n))  
    {   
        delete treeNode->child[word[pos]-'a'];  
        treeNode->child[word[pos]-'a'] = NULL;  
  
        treeNode->prefixCnt--;  
        //if the node becomes a leaf and is not an end,return true to delete it  
        if (--treeNode->childCnt == 0 && treeNode->isEnd == false)  
            return true;  
    }  
  
    //other not delete  
    return false;  
}  
  
//Count the number of words which contain the specific prefix  
int CountWordsWithPrefix(TrieTreeNode *root, const char *prefix)  
{  
    TrieTreeNode *p = root;  
    for (int i = 0; i < strlen(prefix); i++)  
    {  
        if(p->child[prefix[i]-'a'] == NULL)  
            return 0;  
          
        p = p->child[prefix[i]-'a'];  
    }  
    return p->prefixCnt;  
}  
/*
int main()  
{  
    TrieTreeNode *root = new TrieTreeNode('\0');  
    //const char *words[] = {"b","abc","abd","bcd","abcd","efg","hii"}; //test insert  
    //cout << sizeof(words) << "\n";//(4*7=28)  
    //cout << sizeof(words[0]) << "\n";//4(is a pointer)  
  
    const char *words[] = {"abc","ad","ef"};//test remove  
    BuildTrieTree(root,words,sizeof(words)/sizeof(words[0]));  
    LevelOrderTraverse(root);  
    PreOrderTraverse(root);  
    cout << '\n';  
    PostOrderTraverse(root);  
    cout << "\n";  
  
    if (Find(root,"ef"))  
        cout << "ef found" << endl;  
    else cout << "ef not found" <<endl;  
  
    Insert(root,"e");  
    //after this insertion.the node 'e' becomes a end but it's not a leaf,  
    //so it can not be deleted unless its leaf(leaves) is deleted  
    LevelOrderTraverse(root);  
  
    Remove(root,"ef",0,strlen("ef"));  
    LevelOrderTraverse(root);  
  
    Remove(root,"e",0,strlen("e"));  
    LevelOrderTraverse(root);  
  
    cout << CountWordsWithPrefix(root,"a")<<endl;  
    Remove(root,"ad",0,strlen("ad"));  
    cout << CountWordsWithPrefix(root,"a")<<endl;  
  
    MakeEmpty(root);  
      
    return 0;  
} 
*/