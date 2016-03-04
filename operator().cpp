 ///
 /// @file    operator().cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 20:49:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo{
	public:
		/*重载函数调用符（）*/
		int operator ()(int,int);
		int operator ()(int,int,int);
	private:

};

int Demo::operator ()(int a,int b){
	return a > b ? a : b;
}

int Demo::operator ()(int a,int b,int c){
	return (a + b) * c;
}

int main(void){
	Demo demo; //函数对象
	cout<<demo(2,3)<<endl;
	cout<<demo(3,4,5)<<endl;
	return 0;
}
