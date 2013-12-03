#include"stdio.h"
#include<vector>


#include"vector2f.h"
#include"site.h"
//这个类用于德莱尼三角形剖分的生存
//也就是预处理中颇为重要的一个部分
//考虑到未来动态生成计算网格的可能性，
//这个类的数据直接参与GPU运算
//预处理需要“递归式”的并行解决方案
//即是多层运行的队列模型。
class FEA_TRI_Site :site//用于FEA计算的三角形网格点
{
	
};
class Triangle//用于FEA/FVM计算的通用三角形模块
{
};
class TRI_Edge
{
};
class pre_tri_cpu
{
	//Delaunay Triangulation
	//First Input Points and Program will give out the mesh
	//by Delaunay
public:
	pre_tru_cpu(std::vector<vector2f> sites)
	{
		for(vector2f si:sites)
		{
			Triangle pt=find_Point_in_Triangle(si);
			add_Site(si);

		}
	};
	~pre_tru_cpu();
private:
	void LegalizeEdge(FEA_TRI_Site p,TRI_Edge l);
	Triangle* find_Point_in_Triangle(vector2f s);
};
