//Q:给定一个三元组（a,b,c），给定一个三元组的集合，计算这个集合当中满足距离
//最小条件的三元组并输出

//包含自定义头文件

//包含系统头文件
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//宏定义

//类型定义
struct Coordinate
{
    int i=-1;
    int j=-1;
    int k=-1;
};
//全局变量

//三元组分量
int a[3]={-1,0,9};
int b[4]={-25,-10,10,11};
int c[5]={2,9,17,30,41};

//三元组长度
int l=3;
int m=4;
int n=5;

//1.利用枚举法,T(n)=O(n^3)
int findShortestCoord(struct Coordinate &coordinate)
{
    int m=abs(a[0]-b[0])+abs(a[0]-c[0])+abs(b[0]-c[0]);
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                int temp=abs(a[i]-b[j])+abs(a[i]-c[k])+abs(b[j]-c[k]);
                if(m>temp)
                    {
                        m=temp;
                        coordinate.i=i;
                        coordinate.j=j;
                        coordinate.k=k;
                    }
            }
        }
    }
    return m;
}

//找到三个数当中最小的元素
int findMinElement(int i,int j,int k)
{
    if(i<=j&&i<=k)
        return 0;
    if(j<=i&&j<=k)
        return 1;
    if(k<=i&&k<=j)
        return 2;
}


//王道答案的标准方法，T(n)=O(n),S(n)=O(1)
//但是具体的推算原理我还没有搞清楚，还没有办法验证该方法的正确性
int findShortestCoord2(Coordinate &coordinate)
{
    int dMin=abs(a[0]-b[0])+abs(a[0]-c[0])+abs(b[0]-c[0]);
    coordinate.i=0;
    coordinate.j=0;
    coordinate.k=0;
    int kount[3];
    memset(kount,0,sizeof(kount));      //将数组进行初始化
    while(kount[0]<l&&kount[1]<m&&kount[2]<n&&dMin>0)
    {
        int d=abs(a[kount[0]]-b[kount[1]])+abs(a[kount[0]]-c[kount[2]])+abs(b[kount[1]-c[kount[2]]]);       //计算此时的临时值 
        if(dMin>d)
        {
            dMin=d;
            coordinate.i=kount[0];
            coordinate.j=kount[1];
            coordinate.k=kount[2];
        }
        int minArray=findMinElement(a[kount[0]],b[kount[1]],c[kount[2]]);                                    //找到最小的那个值
        kount[minArray]++;
    }
    return dMin;
}

int main()
{
    Coordinate coordinate;
    int minLength=findShortestCoord2(coordinate);
    cout<<"三元组为（"<<a[coordinate.i]<<","<<b[coordinate.j]<<","<<c[coordinate.k]<<")"<<endl;
    cout<<"最小距离为"<<minLength<<endl;
    return 0;
}