#ifndef __VECTOR_2F__
#define __VECTOR_2F__
#include<math>
//对于二维坐标的基本定义与重载
//后期加入GPU计算部分
struct vector2f
{
	double x,y;
	vector2f()
	{
		x=0;
		y=0;
	}
	vector2f(double _x,double _y):
		x(_x),y(_y)
	{
	}
	double abs()
	{
		return sqrt(x*x+y*y); 
	}
};

double operator +(vector2f a,vector2f b)
{
	vector2f res(a.x+b.x,a.y+b.y);
	return res;
}
double operator *(vector2f a,vector2f b)//dot 
{
	vector2f res(a.x*b.x,a.y*b.y);
	return res;
}

double operator *(vector2f a,double b)//times
{
	vector2f res(a.x*b,a.y*b);
	return res;
}
double operator/(vector2f a,double b)//div
{
	vector2f res(a.x/b,a./b);
	return res;
}
double operator %(vector2f a,vector2f b)//cross 
{
	vector2f res(a.x*b.y,-a.y*b.x);
	return res;
}
#endif
