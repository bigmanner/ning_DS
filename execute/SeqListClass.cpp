//顺序表静态分配和动态分配类的实现文件
//Created by SunNing,2023.02.19

//包含自制头文件
#include"SeqListClass.h"

//包含系统头文件
#include<iostream>
using namespace std;

//类内成员函数实现

//1.构造函数
SeqListStatic::SeqListStatic()
{
    length=0;
}

//1'.多值初始化构造函数
SeqListStatic::SeqListStatic(ElementTypeS i_data[],int i_length)
{
    if(i_length>MAXSIZE)
    {
        cout<<"初始化数据长度大于预设值"<<endl;
        return;
    }
    for(int i=0;i<i_length;i++)
    {
        data[i]=i_data[i];//逐个进行复制即可
    }
    length=i_length;
}

//2.增
bool SeqListStatic::Insert(ElementTypeS i_e,int i_index)
{
    //1.检查插入位序
    if(i_index<1||i_index>length+1)
    {
        cout<<"插入位序不正确"<<endl;
        return false;
    }

    //2.检查静态分配顺序表是否已满
    if(length==MAXSIZE)
    {
        cout<<"顺序表已满"<<endl;
        return false;
    }

    //3.正常执行插入操作(从后往前进行插入)
    for(int i=length-1;i>=i_index-1;i--)
    {
        //这样进行插入即可
        data[i+1]=data[i];//这样就把元素往后移动即可
    }
    data[i_index]=i_e;         //在次序i_index的元素上把i_e写入数组
    length++;                  //这样长度自加1即可
    return true;                        
}

//3.删
bool SeqListStatic::Delete(ElementTypeS &o_e,int i_index)
{
    if(i_index<1||i_index>length)
    {
        cout<<"删除位序不正确\n";
        return false;
    }
    o_e=data[i_index-1];        //把值返回出去
    cout<<"被删除的元素为"<<i_index<<"位序的"<<o_e<<endl;
    for(int i=i_index-1;i<=length-2;i++)
    {
        data[i]=data[i+1];
    }
    length--;                   //length的值一定要自减，这一点非常重要
    return true;
}

//4.改
bool SeqListStatic::Update(ElementTypeS i_e,int i_index)
{
    //1.先判定位序是否合法
    if(i_index<1||i_index>length)
    {
        cout<<"改位序不合法"<<endl;
        return false;
    }
    
    //2.合法直接修改元素即可
    data[i_index]=i_e;
    return true;
}

//5.按值查找
bool SeqListStatic::GetElem(ElementTypeS i_e,int &o_index)
{
    for(int i=0;i<length;i++)
    {
        if(data[i]==i_e)
        {//说明两个元素的值相等
            o_index=i+1;
            return true;
        }
    }
    o_index=-1;
    return false;
}

//6.按位序查找
bool SeqListStatic::LocateElem(ElementTypeS &o_e,int i_index)
{
    //1.判定位序合法性
    if(i_index<1||i_index>length)
    {
        cout<<"查找位序不合法\n";
        return false;
    }

    //2.若合法
    o_e=data[i_index-1];
    return true;

}

//7.打印顺序表
void SeqListStatic::PrintList()
{
    //输出全部的元素
    for(int i=0;i<length;i++)
    {
        cout<<data[i]<<"\t";
    }
    cout<<"\n";
}


/*
//测试时放开

int main()
{
    //类成员变量成员函数测试

    //1.初始化测试
    int n=10;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    SList l(a,n);
    l.PrintList();

    //2.插入测试
    l.Insert(109,2);
    l.PrintList();
    
    //3.删除测试
    int deleteIndex=-1;
    l.Delete(deleteIndex,3);
    l.PrintList();

    //4.按值查找测试
    int getElemIndex=-1;
    l.GetElem(10,getElemIndex);
    cout<<"按值查找位置为"<<getElemIndex<<endl;
    //l.PrintList();

    //5.按序查找测试
    int LocateElem=0;
    l.LocateElem(LocateElem,4);
    cout<<"按序查找值为"<<LocateElem<<endl;
    //l.PrintList();
    return 0;
}

*/