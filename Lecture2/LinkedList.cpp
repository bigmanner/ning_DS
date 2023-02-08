//包含系统头文件
#include<iostream>
#include<stdio.h>
using namespace std;

//包含自制头文件
#include"LinkedList.h"

//0.初始化（让指针指向一个头节点）
List MakeEmpty()
{
    List ptrL;
    ptrL=(List)malloc(sizeof(LNode));//动态开辟内存空间
    ptrL->Data=0;//头节点的Data域可以用来存储链表的长度
    ptrL->Next=nullptr;
    return ptrL;
}

//1.增（假设我们不知道链表的长度，0<=index<=n+1）
void Insert(ElementType x,int index,List ptrL)
{
    //1.验证index合法性

    if(index<=0)
    {
        printf("插入位置不合法\n");
        return;
    }

    //2.寻找index前的一个块

    int kount=0;//让计数器一开始为0,和ptrNode指向位置同步
    Position ptrNode=nullptr;
    ptrNode=ptrL;//让指针指向首节点
    while(ptrNode!=nullptr&&kount<index-1)
    {
        ptrNode=ptrNode->Next;//让指针继续往下指
        kount++;//和指针保持同步运行
    }

    //2'.验证index合法性
    if(ptrNode==nullptr)
    {//说明根本无法插入到后面
        printf("插入位置不合法\n");
        return;
    }

    //3.开辟动态内存空间
    Position ptrNew=(List)malloc(sizeof(LNode));
    ptrNew->Data=x;

    //4.将新的块插入到链表里面
    ptrNew->Next=ptrNode->Next;
    ptrNode->Next=ptrNew;
    ptrL->Data++;//记录链表大小处进行自加
    return;
}
//2.删(1<=index<=n)
void Delete(int index,List ptrL)
{
    printf("到这里了吗\n");
    //1.验证位置的合法性
    if(index<1||index>Length(ptrL))
    {
        printf("删除位置不合法\n");
        return;
    }
    //printf("到这里了吗\n");
    Position ptrNode=nullptr;
    Position ptrPreNode=nullptr;
    Position ptrToDelete=nullptr;
    //printf("到这里了吗\n");
    //进行删除操作
    if(index==1)
    {
        ptrNode=FindKth(1,ptrL);
        ptrL->Next= ptrNode->Next;
        free(ptrNode);//释放内存
        ptrNode=nullptr;
        ptrL->Data--;//链表长度减1
        return;
    }
    printf("到这里了吗\n");
    ptrPreNode=FindKth(index-1,ptrL);//找到前面的块
    ptrToDelete=FindKth(index,ptrL);//找到需要删除的块
    ptrPreNode->Next=ptrToDelete->Next;
    free(ptrToDelete);
    ptrToDelete=nullptr;
    ptrL->Data--;//链表长度减1
    return;
}
//3.改
void Modify(ElementType x,int index,List ptrL)
{
    //1.合法性检测
    if(index<1||index>Length(ptrL))
    {
        printf("删除位置不合法\n");
        return;
    }
    //2.找到需要修改的链表块
    Position ptrNode=nullptr;
    ptrNode=FindKth(index,ptrL);//找到需要修改的链表块
    int originData=ptrNode->Data;
    ptrNode->Data=x;
    int newData=ptrNode->Data;
    printf("修改原始值%d改为%d\n",originData,newData);
    return;
}
//4.按照序号查找（1<=index<=n）
Position FindKth(int index,List ptrL)
{
    //1.判定下标合法性
    if(index<1||index>ptrL->Data)
    {
        return nullptr;
    }
    
    //2.执行循环遍历
    int kounter=0;
    Position ptrNode=nullptr;
    ptrNode=ptrL;//指向首节点
    for(int i=0;i<index;i++)
    {
        ptrNode=ptrNode->Next;
    }
    return ptrNode;
}

//4‘.这个按值查找需要实现
List Find(ElementType x,List ptrL)
{
     Position ptrNode=nullptr;
     ptrNode=ptrL->Next;//块指针指向第一个块或者nullptr
    while(ptrNode!=nullptr)
    {
        if(x==ptrNode->Data)
            return ptrNode;
        ptrNode=ptrNode->Next;
    }
    return nullptr; 
}

//5.打印列表
void Print(List ptrL)
{
    Position ptrNode=nullptr;
    ptrNode=ptrL->Next;//指向第一个节点
    if(ptrNode==nullptr)
        {
            printf("链表为空\n");
            return;
        }

    printf("链表长度为:%d\n",Length(ptrL));

    while(ptrNode!=nullptr)
    {
        printf("%d\t",ptrNode->Data);
        ptrNode=ptrNode->Next;
    }
    printf("\n");
    return;
}

//6.求表长(存在首节点的求法)
int Length(List ptrL)
{
    int kounter=0;//计数器
    Position ptrNode=nullptr;
    ptrNode=ptrL->Next;
    while(ptrNode!=nullptr)
    {
        kounter++;                  //数量的个数自加
        ptrNode=ptrNode->Next;         //指针继续往后指
    }
    return kounter;
}

int main()
{
    //测试
    List myList=MakeEmpty();//这就是我的中国梦
    Print(myList);//打印链表
    for(int i=0;i<10;i++)
    {
        Insert(i,1,myList);//循环进行数据的添加
    }
    Print(myList);

    //长度函数功能测试
    printf("长度测试：");
    int length=Length(myList);
    printf("length is %d\n",length);

    //按序查找功能测试
    List ptrOrderSearch=FindKth(2,myList);
    printf("按序查找第二个块的Data为%d\n",ptrOrderSearch->Data);
    
    //按值查找功能测试
    List ptrValueSearch=Find(7,myList);
    printf("按值查找7: %d",ptrValueSearch->Data);

    //删除功能测试
    Delete(3,myList);
    Print(myList);

    //修改功能测试
    Modify(8,6,myList);
    Print(myList);
    return 0;
}
