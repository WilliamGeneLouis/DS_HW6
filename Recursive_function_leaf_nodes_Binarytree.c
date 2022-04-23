/******************************************************
 * Created by David Song in 2016-5-11
 *
 * Note:
 *   1. Link implementation of binary tree
 *   2. use a header node to simplifing implementation
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


/*TODO
 * 先是逐个定义每一个结点，特别是申明最后几次定义的结点的值
 * 通过最后定义的值进行叶子结点的查找。
 * Given a binary tree, we have to count number of leaf nodes in tree.
 * A node is a leaf node, if it's left children and right children are NULL.
 * Here, we will use recursion approach to count leaf nodes.
 * We will traverse the binary tree using pre Order traversal and find the leaf nodes in left and right sub tree recursively.
 * */

/*
 返回叶子结点的数目
 * */
int countLeafNodes(TreeNode *bt){

    /* 判断这个树是不是空树*/
    if(bt == NULL)
        return 0;

    // 检查该树的左右孩子结点
    if(bt->leftChild == NULL && bt->rightChild == NULL){
        return 1;
    }

    // 对于内部结点，返回该结点的右子树和左子树,意味着如果该结点至少有一个位置已经插入了一个结点
    return countLeafNodes(bt->leftChild) + countLeafNodes(bt->rightChild);
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

  TreeNode *ppp; //定义存放第一次插入D的子结点暂时存储值
  TreeNode *pppp;//定义存放第一次插入F的子结点暂时存储值

  Initiate(&root);
  p = InsertLeftNode(root, 'A');
  p = InsertLeftNode(p, 'B');

  ppp = p; //此时的ppp指向B结点，便于后续插入右孩子结点

  p = InsertRightNode(p, 'E');
  p = InsertLeftNode(p, 'H');
  p = InsertLeftNode(ppp, 'D');//此时的ppp指向B结点，在这里插入B的右孩子结点D
  p = InsertRightNode(root->leftChild, 'C');

  pp = p; //此时的pp指向C结点，便于后续插入右孩子结点

  p = InsertLeftNode(p, 'F'); //把传完的值赋值给p，此时就可以把p传给pppp进行下一个结点的插入

  InsertRightNode(pp, 'G'); //此时不能把传递后的值赋值给p，会将下一个结点直接传向

  pppp=p; //此时的pppp指向F结点，便于后续插入右孩子结点

  InsertRightNode(pppp, 'I'); //实际上没有必要定义pppp进行赋值，因为此时p已经指向了F结点，可以直接插入I结点
  //InsertRightNode(p, 'I'); //该结果同样是成立的，可以正常给F结点插入I结点，进行插入的操作
  InsertLeftNode(pppp, 'Z'); //此时进行了插入 Z 结点，测试叶子结点数目输出是否正确

  //printf("Number of leaf Nodes : %d \n \n", countLeafNodes(root)); //打印叶子结点的个数,上次作业补全后的二叉树一共有四个叶子结点
  printf("该二叉树的叶子结点一共有: %d个\n \n", countLeafNodes(root)); //打印叶子结点的个数,上次作业补全后的二叉树一共有四个叶子结点

  PrintBiTree(root->leftChild, 1);
  return 0;

}
