 ///
 /// @file    operator[].cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 21:05:47
 ///
#include <string.h> 
#include <iostream>

using std::cout;
using std::endl;

class CharSz{
	public:
		CharSz(int);
		~CharSz();
		/*以成员函数的形式重载下标运算符*/
		char & operator[](int);
		int getLen();
	private:
		int _len;
		char *_pstr;
};

CharSz::CharSz(int len)
:_len(len)
,_pstr(new char[_len + 1])
{
	cout<<"CharSz(int)"<<endl;
}

CharSz::~CharSz(){
	cout<<"~CharSz()"<<endl;
	delete[] _pstr;
}

char & CharSz::operator [](int i){
/*用于返回空字符时，由于返回类型为char &，不能直接
 * return '\0';
 */
	static char szNull = '\0';
	if(i>=0 && i<_len){
		return _pstr[i];
	}else{
		cout<<"下标越界"<<endl;
		return szNull;
	}
}

int CharSz::getLen(){
	return _len;
}

int main(void){
	char *p = "how are you";
/*对象sz中申请的动态内存大小为n，可存放n-1个有效字符（'\0'除外）*/
	CharSz sz(strlen(p)+1);
	for(int i=0; i<(strlen(p)+1); ++i){
		sz[i] = p[i];
	}

	for(int j=0; j<sz.getLen(); j++){
		cout<<sz[j]<<" ";
	}
	cout<<endl;
	return 0;
}
