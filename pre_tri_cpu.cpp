#include"pre_tri_cpu.h"
#include<iostream>
using namespace std;
bool Triangle::inTriangle(site p)
{
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;

	if (onEdge(p))
		return false;
	if( (pa%pb)*(pb%pc)/((pa+pb+pc).abs())>CLOSE_DIS2 )
		return true;
	else
		return false;
}
bool Triangle::onEdge(site p)
{
	if(onPoint(p))
		return 1;
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;
	double a=pa%pb,b=pb%pc,c=pc%pa;
	double d=pa.abs()*pb.abs()*pc.abs();
	if(fabs(a*b*c)/d<CLOSE_DIS2)
		return true;
	return false;
}
bool Triangle::onPoint(site p)
{
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;
	double a=pa.abs(),b=pb.abs(),c=pc.abs();
	if(fabs(a*b*c/(a+b+c))<CLOSE_DIS2)
		return true;
	return false;
}
Triangle::Triangle(site**p)
{
	A=new FEA_TRI_Site(*p[0]);
	B=new FEA_TRI_Site(*p[1]);
	C=new FEA_TRI_Site(*p[2]);
}
int main()
{
	site **xin=new site*[3];
	xin[0]=new site(0,0);
	xin[1]=new site(0.01,0);
	xin[2]=new site(0,1);
	site yang(0.001,0.01);
	Triangle Qi(xin);
	cout<<"inTri:"<<Qi.inTriangle(yang)<<endl;
	cout<<"onEdge:"<<Qi.onEdge(yang)<<endl;
	cout<<"onPoint:"<<Qi.onPoint(yang)<<endl;


}
