#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H
//包含自定义头文件

//包含系统头文件

//宏定义

//类实现
class ComFunction
{
    //定义了常用函数
    public:
    //1.逆转int型数组的从i_from到i_to的所有元素
    bool ArrayReverse(int i_targetArray[],int i_from,int i_to);
    //2.输出int型数组的所有元素
    void ArrayPrint(int i_targetArray[],int i_n);
    //3.二分查找数组中i_searchElement的位置，若无该x元素则返回-1(传统老方，二分查找)
    int ArrayBinarySearch(int i_targetArray[],int i_length,int i_searchElement);
};











#endif