 ///
 /// @file    Line.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 03:46:30
 ///
#ifndef __LINE_H__
#define __LINE_H__

//#include <iostream>
class Line{
	class Lineimpl;
	public:
		Line(int,int,int,int);
		~Line();
		void print();
	private:
		Lineimpl *_impl;
};

#endif
