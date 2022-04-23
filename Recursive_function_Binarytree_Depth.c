/******************************************************
 * Created by 廿Gene in 2022-04-23
 *
 * Note:
 *  maxheight()
    1. If tree is empty then return -1
    2. Else
         (a) Get the max depth of left subtree recursively
            call maxDepth( root->LeftChild)
         (b) Get the max depth of right subtree recursively
            call maxDepth(  root->RightChild)
         (c) Get the max of max depths of left and right
            subtrees and add 1 to it for the current node.
            max_depth = max(max dept of Left_Child, max depth of Right_Child) + 1
         (d) Return max_depth
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


int maxheight(TreeNode *bt){
    if(bt == NULL) return -1; // 如果该结点为NULL直接返回错误
    else{
        int Left_Height= maxheight(bt->leftChild); // 将当前结点的左子树进行运算后的值赋给Left_Depth
        int Right_Height= maxheight(bt->rightChild); // 将当前结点的右子树进行运算后的值赋给Right_Depth
        if(Left_Height> Right_Height){
            return Left_Height+ 1; // 如果此时左结点的高度高于右结点，就让左结点的高度+1
        }
        else return Right_Height+ 1;
    }
}


/*
This function returns below
            A
           / \
         B    C
        / \  / \
       D  E F  G
         /   \
        H     I
*/
int main() {

  TreeNode *root, *p, *pp;

  TreeNode *ppp; //定义存放第一次插入 D 的子结点暂时存储值
  TreeNode *pppp;//定义存放第一次插入 F 的子结点暂时存储值

  Initiate(&root);
  p = InsertLeftNode(root, 'A');
  p = InsertLeftNode(p, 'B');

  ppp = p; //此时的ppp指向 B 结点，便于后续插入右孩子结点

  p = InsertRightNode(p, 'E');
  p = InsertLeftNode(p, 'H');
  p = InsertLeftNode(ppp, 'D');//此时的 ppp 指向 B 结点，在这里插入 B 的右孩子结点 D
  p = InsertRightNode(root->leftChild, 'C');

  pp = p; //此时的pp指向 C 结点，便于后续插入右孩子结点

  p = InsertLeftNode(p, 'F'); //把传完的值赋值给 p，此时就可以把 p 传给 pppp 进行下一个结点的插入

  InsertRightNode(pp, 'G'); //此时不能把传递后的值赋值给 p ，会将下一个结点直接传向

  pppp=p; //此时的pppp指向 F 结点，便于后续插入右孩子结点

  InsertRightNode(pppp, 'I'); //实际上没有必要定义 pppp 进行赋值，因为此时 p 已经指向了 F 结点，可以直接插入 I 结点
  //InsertRightNode(p, 'I'); //该结果同样是成立的，可以正常给 F 结点插入 I 结点，进行插入的操作
  InsertLeftNode(pppp, 'Z'); //此时进行了插入 Z 结点，测试叶子结点数目输出是否正确
  InsertLeftNode(p, 'X'); // 这里插入 X 结点进行输出函数的判断

  //printf("Number of leaf Nodes : %d \n \n", countLeafNodes(root)); //打印叶子结点的个数,上次作业补全后的二叉树一共有四个叶子结点
  //printf("该二叉树的叶子结点一共有: %d个\n \n", countLeafNodes(root)); //打印叶子结点的个数,上次作业补全后的二叉树一共有四个叶子结点

  printf("该二叉树的高度是: %d \n \n",maxheight(root)); //进行二叉树高度的输出

  PrintBiTree(root->leftChild, 1);
  return 0;
}
