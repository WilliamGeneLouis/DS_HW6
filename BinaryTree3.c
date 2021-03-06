/******************************************************
 * Created by 廿Gene in 2022-04-23
 *
 * Note:
 * TODO：二叉树创建函数(输入带有空指针标记'$'的先序遍历序列，输出不带头节点的 二叉树)
 *  通过字符串(用户键盘输入)创建二叉树的函数
 *
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct treenode {
  DataType data;
  struct treenode * leftChild;
  struct treenode * rightChild;
}TreeNode;


void Initiate(TreeNode **root) {
  *root = (TreeNode *)malloc(sizeof(TreeNode));
  (*root)->leftChild = NULL;
  (*root)->rightChild = NULL;
}


/* curr指针所指结点的左孩子处插入新结点，以前的左孩子变成新节点的左孩子 */
TreeNode *InsertLeftNode(TreeNode *curr, DataType x) {
  TreeNode *s, *t;
  if (curr == NULL)  // 当前指针为空，没有指向有效结点
    return NULL;
  t = curr->leftChild;
  s = (TreeNode *)malloc(sizeof(TreeNode));
  s->data = x;
  s->leftChild = t;
  s->rightChild = NULL;
  curr->leftChild = s;
  return curr->leftChild;
}


/* curr指针所指结点的右孩子处插入新结点，以前的右孩子变成新节点的右孩子 */
TreeNode *InsertRightNode(TreeNode *curr, DataType x) {
  // 在此处添加函数代码
  if (curr== NULL)
    return NULL;
  TreeNode * newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = x;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  curr->rightChild = newNode;
  return curr->rightChild;
}


void PrintBiTree(TreeNode *bt, int n) {
  int i;
  if (bt == NULL) return;
  PrintBiTree(bt->rightChild, n+1);
  for (i = 0; i < n-1; i++) printf("   ");
  if (n > 0) {
    printf("---");
    printf("%c\n", bt->data);
  }
  PrintBiTree(bt->leftChild, n+1);
}

void MakeCharTree(TreeNode **bt) { // 该函数从键盘输入二叉树并且创建一个二叉树
    char ch;
    ch = getchar(); //每次从键盘输入的字符串中取一个字符进行运算
    if(ch == '$') *bt = NULL;
    else{
        *bt = (TreeNode*)malloc(sizeof(TreeNode));
        (*bt)->data = ch;
        MakeCharTree((&(*bt)->leftChild)); //进行递归运算
        MakeCharTree((&(*bt)->rightChild));
    }
}

int main(){
  TreeNode *root;
  Initiate(&root);
  MakeCharTree(&root);
  PrintBiTree(root,1);
}
