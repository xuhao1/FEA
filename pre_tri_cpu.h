#ifndef __PRE_TRI_CPU_H__
#define __PRE_TRI_CPU_H__
#include"stdio.h"
#include<vector>
#include"vector2f.h"
#include"site.h"
#include<math.h>
#define CLOSE_DIS1 1e-5
#define CLOSE_DIS2 1e-10
#define CLOSE_DIS3 1e-15
//这个类用于德莱尼三角形剖分的生存
//也就是预处理中颇为重要的一个部分
//考虑到未来动态生成计算网格的可能性，
//这个类的数据直接参与GPU运算
//预处理需要“递归式”的并行解决方案
//即是多层运行的队列模型。
class FEA_TRI_Site :public site//用于FEA计算的三角形网格点
{
public:
	double T;
	FEA_TRI_Site(site a):
		site(a.loc)
	{
	}

};
class TRI_Edge
{
public:
	FEA_TRI_Site*l,*r;
	double length();
};
class Triangle//用于FEA/FVM计算的通用三角形模块
{
public:
	Triangle();
	Triangle(site**);
	Triangle(site*);
	Triangle(FEA_TRI_Site**);
	~Triangle()
	{
		delete a;
		delete b;
		delete c;

		delete A;
		delete B;
		delete C;
	}
	TRI_Edge *a,*b,*c;//对边
	FEA_TRI_Site *A,*B,*C;
	Triangle* Divide_By_Point(FEA_TRI_Site p);
	bool inTriangle(site);
	bool onEdge(site);
	bool onPoint(site);
};
class Tri_Tree
{
	class node
	{
		public:
			Triangle *ro;
			Triangle*leaf[3];
			int num;
			//num ==0 ,则此三角形为三角剖分中的三角形
		node()
		{
		}
		~node()
		{}
	};
public:
	Tri_Tree();
	~Tri_Tree();
	
};
class pre_tri_cpu
{
	//Delaunay Triangulation
	//First Input Points and Program will give out the mesh
	//by Delaunay
public:
	pre_tri_cpu(std::vector<vector2f> sites);
	~pre_tri_cpu();
private:
	void LegalizeEdge(FEA_TRI_Site p,TRI_Edge l);
	Triangle* find_Point_in_Triangle(vector2f s);
};
#endif
