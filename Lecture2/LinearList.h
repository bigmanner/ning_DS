#ifndef LINEARLIST_H
#define LINEARLIST_H


//线性表以数组的形式实现方法
//最好不要重复包含头文件

//常量定义
#define MAXSIZE 100                 //定义最大容量为100

//类型定义
typedef int ElementType;            //定义元素类型为int
typedef struct LNode *List;         //在本例中形参传递的是指针

//1.顺序表静态分配内存数据结构定义
struct LNode 
{
    ElementType Data[MAXSIZE];      //用于数据存储
    int last;                       //定义数组最后指向的指针
};

//操作集

//1.初始化（建立空的顺序表）
List MakeEmpty();

//2.查
int Find(ElementType X,List ptrL);

//3.增（第i(1<=i<=n+1)个位置上插入一个值为x的新元素）
void Insert(ElementType x,int i,List ptrl);

//4.删（删除表的第i(1<=i<=n)个位置上的元素）
void Delete(int index,List ptrL);//删除第index位置的元素

//5.打印列表
void Print(List ptrL);

#endif