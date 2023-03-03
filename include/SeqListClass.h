//顺序表静态分配和动态分配类的头文件
//Created by SunNing,2023.02.19

#ifndef SEQLISTCLASS_H
#define SEQLISTCLASS_H
//包含自定义头文件
#include<base.h>

//线性表的顺序实现-顺序表
//1.静态分配顺序表
//2.动态分配顺序表

//静态分配顺序表全局变量
#define MAXSIZE 100
#define ElementTypeS int
typedef class SeqListStatic SList;//定义类型，可用引用的方式进行传参

//动态分配顺序表全局变量
#define INITSIZE 100
#define ElementTypeD int
//typedef SeqListDynamic DList;//定义类型，可用引用的方式处理传参

//1.静态顺序表  
class SeqListStatic
{
    public:
    //定义成员变量，成员变量全部设置为private; 
    ElementTypeS data[MAXSIZE];//存储数据的数组
    int length;                //顺序表的长度
    
    public:
    //定义成员函数

    //1.构造函数
    SeqListStatic();
    //1'.多值初始化构造函数
    SeqListStatic(ElementTypeS i_data[],int i_length);
    //2.增(在第i(1<=i<=n+1)个元素上插入一个值为x的新元素)
    bool Insert(ElementTypeS i_e,int i_index);
    //3.删(在第i(1<=i<=n)个元素删除,要用o_e进行返回)
    bool Delete(ElementTypeS &o_e,int i_index);
    //4.改(将第i(1<=i<=n)个元素的值进行修改,e为需要改变为的值)
    bool Update(ElementTypeS i_e,int i_index);
    //5.查(按值查,返回位序)
    bool GetElem(ElementTypeS i_e,int &o_index);
    //6.查(按位序查(1<=i<=n)，返回值)
    bool LocateElem(ElementTypeS &o_e,int i_index);
    //7.打印顺序表
    void PrintList();
};
#endif