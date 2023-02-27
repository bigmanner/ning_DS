//线性表的链式存储实现
//最好不要重复包含头文件

//常量定义

//类型定义
typedef int ElementType;
typedef struct LNode *List;     //可以在LNode定义之前使用typedef来定义新的类型
typedef struct LNode *Position; //该指针链表节点处     

//数据结构定义
struct LNode                    //链表的每个节点定义所示
{
    ElementType Data;
    List Next;
};

//操作集

//0.初始化(让指针指向一个头节点)
List MakeEmpty();
//1.增（假设我们不知道链表的长度，0<=index<=n）
void Insert(ElementType x,int index,List ptrL);
//2.删(可以借助按序号查找函数进行实现)
void Delete(int index,List ptrL);
//3.改(改的位置只能是1<=index<=n)
void Modify(ElementType x,int index,List ptrL);
//4.按序号查找
List FindKth(int k,List ptrL);

//4‘.按值查找（返回第一个下标）
List Find(ElementType x,List ptrL);

//5.打印列表
void Print(List ptrL);
//6.求表长(存在首节点的求法)
int Length(List ptrL);

//7.合并两个升序表为降序表
List MergeAscendingToDescending(List A,List B);