
//王道数据结构2.2.3综合应用题全部题目

//包含自制文件
#include"LinearList.h"

#include<iostream>
using namespace std;

//01.删除具有最小值的元素并由函数返回被删除元素的值(假设最小值唯一)
bool function01(List L,ElementType &e)
{
	if(L->last==-1)	//说明此时顺序表是空的
	{
		cout<<"此顺序表为空，无法继续删除"<<endl;
		return false;
	}
	ElementType minElem=L->Data[0];//让最小值初始化为第一个元素
	int minIndex=-1;	       //用于记录最小值的位置
	for(int i=0;i<=L->last;i++)
	{
		if(minElem>L->Data[i])
		{
			//说明还存在其他更小的元素
			minElem=L->Data[i];
			minIndex=i;
		}
	}	
	L->Data[minIndex]=L->Data[L->last];//用最后一个元素填充被删除元素的位置
	//要注意，删除之后要进行last--,因为最后一个元素已经保存在被删除的位置了
	L->last--;
	return true;
}

int main()
{
	// //测试函数
	// //1.创建顺序表
	// List list=nullptr;
	// //2.初始化顺序表
	// list=MakeEmpty();
	// //3.插入顺序表的值
	// Insert(3,1,list);
	// Insert(4,1,list);
	// Insert(5,1,list);
	// Print(list);
	// ElementType temp=0;
	// function01(list,temp);
	// Print(list);
	// printf("被删除元素为%d\n",temp);
	// return 0;

	//测试部分
	List list=nullptr;
	list=MakeEmpty();
	return 0;
}
