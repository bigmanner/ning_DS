//共有三种使用方式
//1.先定义共用体，再定义变量
//2.共用体和变量同事定义
//3.不定义共用体名，直接定义变量

//包含文件
#include<stdio.h>

int main()
{
	union data1
	{
		int n;
		char ch;
		double f;
	};
	union data1 a1,b1,c1;

	union data2
	{
		int n;
		char ch;
		double f;
	} a2,b2,c2;

	union 
	{
		int n;
		char ch;
		double f;		
	}a3,b3,c3;
	
	union data
	{
		int n;
		char ch;
		short m;
	};
	union data a;//定义一个共同体
	printf("%d,%d\n",sizeof(a),sizeof(data));
	
	a.n=0x40;
	printf("%X,%c,%hX\n",a.n,a.ch,a.m);
	a.ch='9';
	printf("%X,%c,%hX\n",a.n,a.ch,a.m);
	a.m=0x2059;
	printf("%X,%c,%hX\n",a.n,a.ch,a.m);
	a.n=0x3E25AD54;
	printf("%X,%c,%hX\n",a.n,a.ch,a.m);
	//对ch赋值修改是前一个字节
	//对m赋值修改是前两个字节
	//对n赋值修改是全部字节
	//取决于机器对大端存储和小端存储
	return 0;
}
