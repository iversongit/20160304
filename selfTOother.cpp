 ///
 /// @file    otherTOself.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 00:40:59
 ///
 
/*类型转换：由定义类向其他类型的转换*/
#include <iostream>
using std::cout;
using std::endl;

class Point;
class AnotherPoint{
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
		~Point();
		void print();
		operator int();
		operator double();
		operator AnotherPoint();
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

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_ix<<" , "<<_iy<<")"<<endl;
}

Point::operator int(){
	return _ix * 2;
}

Point::operator double(){
	return _ix * _iy;
}

Point::operator AnotherPoint(){
	AnotherPoint ap(_ix,_iy);
	return ap;
}

int main(void){
	Point p(3,4);
	p.print();
	int x = p;
	cout<< x <<endl;
	cout<<"-------------"<<endl;
	double y = p;
	cout<< y <<endl;
	cout<<"-------------"<<endl;
	AnotherPoint ap;
	ap = p;
	ap.print();
	return 0;
}
