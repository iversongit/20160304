 ///
 /// @file    otherTOself.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 00:40:59
 ///
 
/*类型转换：由其他类型向定义类的转换*/
#include <iostream>
using std::cout;
using std::endl;

class Point;
class AnotherPoint{
	friend class Point;
	public:
		AnotherPoint(double,double);
		~AnotherPoint();
		void print();
	private:
		double _dx;
		double _dy;
};

AnotherPoint::AnotherPoint(double dx=0.0,double dy=0.0)
:_dx(dx)
,_dy(dy)
{
	cout<<"AnotherPoint(double,double)"<<endl;
}

AnotherPoint::~AnotherPoint(){
	cout<<"~AnotherPoint()"<<endl;
}

void AnotherPoint::print(){
	cout<<"("<<_dx<<" , "<<_dy<<")"<<endl;
}

class Point{
	public:
		Point(int,int);
		Point(AnotherPoint ap);
		~Point();
		void print();
	private:
		int _ix;
		int _iy;
};
//explicit
Point::Point(int ix=0,int iy=0)
:_ix(ix)
,_iy(iy)
{
	cout<<"Point(int,int)"<<endl;
}

Point::Point(AnotherPoint ap){
	_ix = ap._dx;
	_iy = ap._dy;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_ix<<" , "<<_iy<<")"<<endl;
}

int main(void){
	Point p = 5;
	p.print();
	cout<<"-------------"<<endl;
	double d = 4.0;
	p = d;
	p.print();
	cout<<"-------------"<<endl;
	AnotherPoint ap(12.34,56.78);
	ap.print();
	p = ap;
	p.print();
	return 0;
}
