//单链表的带头节点和不带头节点的类头文件
//Created by SunNing,2023.03.03

#ifndef LINKLISTCLASS_H
#define LINKLISTCLASS_H
//包含自定义头文件
#include"base.h"

//线性表的链式实现-单链表
//1.带头节点单链表
//2.不带头节点单链表

//公共全局变量

//带头节点全局变量
#define ElementTypeWithNode int         //定义带头节点的单链表的数据类型
typedef class LNode *LNodePtr;           //定义节点的指针

//不带头节点全局变量
#define ElementTypeWithoutNode int      //定义不带头节点的单链表额数据类型

//1.定义单链表节点

class LNode
{
    public:
    ElementTypeWithNode m_data;           //定义节点的数据
    LNode *m_next;                        //定义指向下个链表节点的指针

    public:                      
    //1.默认构造函数
    LNode();

    //2.赋值构造函数
    LNode(ElementTypeWithNode i_e);
};

//2.带头节点单链表
class LinkListWNode
{
    public:
    //定义成员变量
    LNodePtr m_headNode;                   //定义带头节点单链表的头节点指针
    int m_length;                         //定义单链表的长度

    public:
    //定义成员函数
    //1.构造函数
    LinkListWNode();
    //1'.多值初始化(i_mode为0则为头插法,i_mode为1则为尾插法)，此为链表的初始化而非链表块的初始化
    LinkListWNode(int i_mode,ElementTypeWithNode i_data[],int i_length);
    //1''.析构函数,要将整个链表需要释放的所有内存单元全部释放
    ~LinkListWNode();
    //2.增（O(n)型）
    bool ListInsert(ElementTypeWithNode i_e,int i_index);
    //2'.增（O(1)型）,需要将i_insertLNode插入到i_targetLNode之后
    bool ListInsertByPtr(ElementTypeWithNode i_e,LNodePtr i_targetLNode,LNodePtr i_insertLNode);
    //3.删（O(n)型），并用o_e返回删除的值
    //删除第i（1<=i<=n）个元素
    bool ListDelete(ElementTypeWithNode &o_e,int i_index);
    //3'.删（O(1)型），并用o_e返回删除的值
    //删除第i（1<=i<=n）个元素,利用exchange法
    bool ListDeleteExchange(ElementTypeWithNode &o_e,int i_index);
    //4.改(将第i(1<=i<=n)个元素的值进行修改,e为需要改变为的值)
    bool ListUpdate(ElementTypeWithNode &i_e,int i_index);
    //5.查（按值查找，返回块地址）
    bool ListGetElem(ElementTypeWithNode i_e,int &o_index);
    //5'.查（按位序查找，返回值）
    bool ListLocateElem(ElementTypeWithNode &o_e,int i_index);
    //6.打印链表
    void ListPrint();
};

#endif