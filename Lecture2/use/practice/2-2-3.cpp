
//王道数据结构2.2.3综合应用题全部题目

//包含自制文件(知乎再做修改)
#include"SeqListClass.h"

//包含系统文件
#include<iostream>
using namespace std;

void DeleteAllX1(ElementTypeS x,SList &i_list)
{
	int indexForNoX=0;
	for(int i=0;i<i_list.length;i++)
	{
		if(i_list.data[i]!=x)
		{
			i_list.data[indexForNoX++]=i_list.data[i];
		}
	}
	i_list.length=indexForNoX;
}

int main()
{
	int a[5]={1,2,3,5,5};
	int n=5;
	SList list(a,n);
	list.PrintList();
	DeleteAllX1(3,list);
	list.PrintList();
	return 0;
}
