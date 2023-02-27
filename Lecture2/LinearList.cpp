//说是叫做线性表，其实应该是顺序表
//包含系统头文件
#include<iostream>
#include<stdio.h>
using namespace std;

//包含自制头文件
#include"LinearList.h"

//1.初始化（建立空的顺序表）
List MakeEmpty()
{
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));        //malloc函数返回的是void *类型，要进行强制类型转换
    PtrL->last=-1;
    return PtrL;
}

//2.查找
int Find(ElementType x,List ptrL)
{
     for(int i=0;i<=ptrL->last;i++) //将所有的元素都要进行遍历
     {
        if(ptrL->Data[i]==x)
        {
            return i;
        }
     }
     return -1;
}

//3.插入操作实现（1<=i<=n+1），现在要对插入操作进行实现
void Insert(ElementType x,int index,List ptrL)
{
    if((ptrL->last+1)==MAXSIZE)//说明列表已经满了
    {
        printf("顺序表已满！\n");
        return;
    }
    if(index<1||index>ptrL->last+2)
    {
        printf("位置不合法\n");
        return;
    }
    for(int i=ptrL->last+1;i>=index;i--)
    {
        ptrL->Data[i]=ptrL->Data[i-1];
    }
    ptrL->Data[index-1]=x;
    ptrL->last++;
    printf("元素%d已经添加于第%d位置\n",x,index);
    return;
}

//删除（删除表的第i（1<=i<=n）个位置上的元素）
void Delete(int index,List ptrL)
{
    if(index<1||index>ptrL->last+1)//这个地方一开始处理的不好
    {
        printf("位置不合法\n");
        return;
    }
    for(int i=index;i<=ptrL->last;i++)
    {
        ptrL->Data[i-1]=ptrL->Data[i];
    }
    ptrL->last--;
    printf("元素删除成功!\n");
    return;
}

//打印列表
void Print(List ptrL)
{
    if(ptrL->last==0)
        printf("列表为空\n");
    for(int i=0;i<=ptrL->last;i++)
        printf("%d\t",ptrL->Data[i]);
    printf("\n");
    return;
}

int main()
{
    List L;
    L=MakeEmpty();
    for(int i=1;i<=10;i++)
    {
        Insert(i,1,L);
    }
    Print(L);
    Delete(1,L);
    Print(L);
    return 0;
}