#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct treeNode{//建立一棵二叉树
 struct treeNode *leftPtr;
 long data;
 long dup;
 struct treeNode *rightPtr;
};
typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;
void print(long,long);
void insertNode(TREENODEPTR *,long);//插入结点
int inOrder(TREENODEPTR);//中根遍历
main()
{
 long n,i,num,k;
 int j,flag=0;
 char a[100];
 char b[10];
 TREENODEPTR rootPtr=NULL;
    //freopen("1002.in","r",stdin);
 
 scanf("%ld",&n);
 for(k=0;k<n;k++)
 {
  scanf("%s",a);
  for(i=0,j=0;j<7;i++)
  {
   if(a[i]=='-') continue;
   else if(isdigit(a[i])) {b[j]=a[i];j++;}
   else if(isalpha(a[i])) {
    switch(a[i]){
    case 'A':case 'B':case 'C':b[j]='2';j++;break;
    case 'D':case 'E':case 'F':b[j]='3';j++;break;
    case 'G':case 'H':case 'I':b[j]='4';j++;break;
    case 'J':case 'K':case 'L':b[j]='5';j++;break;
    case 'M':case 'N':case 'O':b[j]='6';j++;break;
    case 'P':case 'R':case 'S':b[j]='7';j++;break;
    case 'T':case 'U':case 'V':b[j]='8';j++;break;
    case 'W':case 'X':case 'Y':b[j]='9';j++;break;
    default:break;
    } 
   }
  }
  num=atol(b);
  insertNode(&rootPtr,num);  
 }
 flag=inOrder(rootPtr);
 if(flag==0) printf("No duplicates.");//无重复数据则输出No duplicates.
}
void insertNode(TREENODEPTR *treePtr,long value)//构造二叉树，重复则dup++
{
 if(*treePtr==NULL){
  *treePtr=malloc(sizeof(TREENODE));
  
  if(*treePtr!=NULL){
   (*treePtr)->data=value;
   (*treePtr)->dup=1;
   (*treePtr)->leftPtr=NULL;
   (*treePtr)->rightPtr=NULL;
  }
  //print((*treePtr)->data,(*treePtr)->dup);
 }
 else if(value<(*treePtr)->data)
  insertNode(&((*treePtr)->leftPtr),value);
 else if(value>(*treePtr)->data)
  insertNode(&((*treePtr)->rightPtr),value);
 else {(*treePtr)->dup++;//重复判定
 }
}
int inOrder(TREENODEPTR treePtr)//中根遍历,设标记f,若有重复数据则置1，否则为0
{
 int f=0;
 if(treePtr!=NULL){
  inOrder(treePtr->leftPtr);
  if(treePtr->dup>1)
  {
   print(treePtr->data,treePtr->dup);
   f=1;
  }
  inOrder(treePtr->rightPtr);
 }
 return f;
}
void print(long l,long d)
{//输出需要printf的0判定，例如要输出000-0001
 int a,b;
 a=l/10000;
 b=l000;
 if(a<100)
  if(a<10)
   printf("00");
  else printf("0");
 printf("%d-",a);
 if(b<1000)
  if(b<100)
  {if(b<10)
    printf("000");
   else printf("00");
  }
  else printf("0");
 printf("%d %ld\n",b,d);
}