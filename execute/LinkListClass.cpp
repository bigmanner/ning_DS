//单链表的带头节点和不带头节点的类实现文件
//Created by SunNing,2023.03.03

//包含自制头文件
#include"LinkListClass.h"

//包含系统头文件
#include<iostream>
using namespace std;

//LNode成员函数实现

//1.默认构造函数
LNode::LNode()
{
    m_data=0;
    m_next=NULL;
}

//2.赋值构造函数
LNode::LNode(ElementTypeWithNode i_e)
{
    m_data=i_e;
    m_next=NULL;
}


//LinkListWNode成员函数实现

//1.构造函数
LinkListWNode::LinkListWNode()
{
    //1.将单链表的长度初始化为0
    m_length=0;
    //2.为头节点开辟内存空间，并令指针指向这块内存空间
    m_headNode=(LNode *)malloc(sizeof(LNode));
    if(m_headNode==NULL)
    {
        cout<<"头节点内存空间申请失败"<<endl;
    }
    m_headNode->m_next=NULL;//将申请节点的指针设置为NULL
}

//1'.多值初始化
//i_mode值为0为头插法，值为1为尾插法
LinkListWNode::LinkListWNode(int i_mode,ElementTypeWithNode i_data[],int i_length)
{
    //0.尝试直接调用默认构造函数,开辟一个头节点
    LinkListWNode();
    //1.头插法,最后整个链表是一个逆序
    if(i_mode==0)
    {
        //逆向建立单链表
        for(int i=0;i<i_length;i++)
        {
            LNodePtr ptr=(LNode *)malloc(sizeof(LNode));
            if(ptr==NULL)
            {
                cout<<"申请第"<<i<<"链表块内存错误"<<endl;
                return;
            }
            //将开辟的链表块直接插入到链表最开头即可
            ptr->m_data=i_data[i];                 //给新开辟的内存空间赋值一定不能忘
            ptr->m_next=m_headNode->m_next;
            m_headNode->m_next=ptr;
        }
    }
    //2.尾插法，最后整个链表是正序
    else if(i_mode==1)
    {
        //正向建立单链表
        //链表块指针指向首结点
        LNodePtr s=m_headNode;
        for(int i=0;i<i_length;i++)
        {
            LNodePtr ptr=(LNode *)malloc(sizeof(LNode));
            if(ptr==NULL)
            {
                cout<<"申请第"<<i<<"链表块内存错误"<<endl;
                return;
            }
            ptr->m_data=i_data[i];
            ptr->m_next=NULL;                    //给每一个开辟的链表块的next的值都设置为NULL
            s->m_next=ptr;
            s=s->m_next;
        }
        s->m_next=NULL;
    }
}

//1'''.析构函数
//todo，析构函数还是有问题
//为什么这里调用了两次析构函数
LinkListWNode::~LinkListWNode()
{
    //1.将长度计数器归零
    m_length=0;
    LNodePtr ptr=m_headNode;            //让ptr指向头结点
    
    if(m_headNode!=NULL)
        cout<<"m_headNode已经被释放完毕了"<<endl;
    //free(m_headNode);
//     //2.将单链表占用的全部内存全部释放
//     while(ptr!=NULL)
//     {
//         free(ptr);
//         m_headNode=m_headNode->m_next;
//         ptr=m_headNode;
//     }
 }

//2.增（O(n)型）
bool LinkListWNode::ListInsert(ElementTypeWithNode i_e,int i_index)
{
    //1.先验证插入位置的有效性
    //(链表的插入位置判定无法直接得知),插入位置的上限合法性需要由指针是否为NULL决定
    if(i_index<1)
    {
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    LNodePtr p=m_headNode;              //定义节点指针，让p指向单链表头节点
    int kount=0;                        //指示目前p指针指向单链表的第几个节点
    
    //找到单链表第i-1个节点
    while(p!=NULL&&kount<i_index-1)
    {
        p=p->m_next;
        kount++;
    }
    //p为空，则说明插入的位置超过了合法上限
    if(p==NULL)
    {
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    //为新的链表块申请内存空间
    LNodePtr q=(LNode *)malloc(sizeof(LNode));
    if(q==NULL)
        {  
            cout<<"为插入数据申请链表块空间失败"<<endl;
            return false;
        }
    //实现插入操作
    q->m_data=i_e;
    q->m_next=p->m_next;
    p->m_next=q;
    //不要忘记让链表的长度+1
    m_length++;
    return true;
}

//2'.增（O(1)型）
//需要将i_insertLNode插入到i_targetLNode之后
//为保证程序的健壮性，必须确保插入到的节点指针为非空指针
bool LinkListWNode::ListInsertByPtr(ElementTypeWithNode i_e,LNodePtr i_targetLNode,LNodePtr i_insertLNode)
{
    //判定插入处的指针是否为非空
    if(i_targetLNode==NULL)
    {
        return false;
    }
    //将i_insertLNode指向的块放到i_targetLNode指针后面
    i_insertLNode->m_next=i_targetLNode->m_next;
    i_targetLNode->m_next=i_insertLNode;
    //交换两个链表块的数据,即可实现将i_insertLNode的数据插入到i_targetLNode前面
    i_insertLNode->m_data=i_e;
    int temp=0;
    temp=i_insertLNode->m_data;
    i_insertLNode->m_data=i_targetLNode->m_data;
    i_targetLNode->m_data=temp;
    return true;
}

//6.打印链表
void LinkListWNode::ListPrint()
{
    LNodePtr p=NULL;
    p=m_headNode->m_next;           //p指向单链表的头节点
    cout<<"打印链表元素："<<endl;
    while(p!=NULL)
    {
        cout<<p->m_data<<" ";
        p=p->m_next;
    }
    cout<<endl;
}

//测试代码
int main()
{
    // LinkListWNode list;

    // //1.测试ListInsert()成员函数
    // for(int i=1;i<4;i++)
    // {
    //     list.ListInsert(i,1);
    // }
    // list.ListPrint();
    // list.ListInsert(5,1);
    // list.ListPrint();

    // //2.测试ListInsertByPtr()成员函数
    // LNodePtr ptr=list.m_headNode->m_next;
    // ptr=ptr->m_next;
    // LNodePtr ptr2=(LNode *)malloc(sizeof(LNode));
    // if(ptr2==NULL)
    // {
    //     cout<<"申请内存空间失败"<<endl;
    //     return 0;
    // }
    // list.ListInsertByPtr(100,ptr,ptr2);
    // list.ListPrint();

    // //3.测试链表头插法
    // int a[10];
    // for(int i=0;i<10;i++)
    // {
    //     a[i]=i;
    // }
    // LinkListWNode list2(0,a,10);
    // list2.ListPrint();
    // return 0;

    //3'.测试链表尾插法以及析构函数
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=i;
    }
    LinkListWNode list3(1,a,10);
    list3.ListPrint();
    return 0;
}