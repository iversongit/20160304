 ///
 /// @file    nestedclass.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 03:24:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Line{
	public:
		class Point{
			public:
				Point(int x = 0,int y = 0)
				:_x(x)
				,_y(y)
				{
					cout<<"Point(int,int)"<<endl;
				}

				~Point(){
					cout<<"~Point()"<<endl;
				}

				void print(){
					cout<<"("<<_x<<" , "<<_y<<")"<<endl;
				}
			private:
				int _x;
				int _y;
		};

	public:
		Line(int x1,int y1,int x2,int y2)
		:_p1(x1,y1)
		,_p2(x2,y2)
		{
			cout<<"Line(int,int,int,int)"<<endl;
		}

		~Line(){
			cout<<"~Line()"<<endl;
		}

		void print(){
			_p1.print();
			cout<<"TO"<<endl;
			_p2.print();
		}

	private:
		Point _p1;
		Point _p2;
};

int main(void){
	Line line(1,2,3,4);
	line.print();
	cout<<"-------------"<<endl;
	Line::Point p(8,8);
	p.print();
	return 0;
}
