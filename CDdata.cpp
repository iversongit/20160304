 ///
 /// @file    CDdata.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 00:10:51
 ///
 
/*指针运算符->的重载*/
#include <iostream>
using std::cout;
using std::endl;

class CData{
	public:
		int getLen(){
			return 5;
		}
};

class CDataPtr{
	public:
		CDataPtr();
		~CDataPtr();
		CData * operator ->();
	private:
		CData *_ptr;
};

CDataPtr::CDataPtr()
:_ptr(new CData)
{
	cout<<"CDataPtr()"<<endl;
}

CDataPtr::~CDataPtr(){
	cout<<"~CDataPtr()"<<endl;
	delete _ptr;
}

CData * CDataPtr::operator ->(){
	cout<<"operator ->()"<<endl;
	return _ptr;
}

int main(void){
	CDataPtr cd;
	cout<<cd->getLen()<<endl;
	cout<<(cd.operator ->())->getLen()<<endl;
	return 0;
}
