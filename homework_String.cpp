 ///
 /// @file    homework_String.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 04:21:19
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String{
	public:
		String();
		String(const char *);
		String(const String&);
		~String();
		String &operator =(const String &);
		String &operator =(const char *);

		String &operator +=(const String &);
		String &operator +=(const char *);

		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;

		std::size_t size() const;
		const char * c_str() const;

		friend bool operator ==(const String &, const String &);
		friend bool operator !=(const String &, const String &);
		friend bool operator <(const String &, const String &);
		friend bool operator >(const String &, const String &);
		friend bool operator <=(const String &, const String &);
		friend bool operator >=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &os,const String &s);
		friend std::istream &operator>>(std::istream &is,String &s);

		friend String operator +(const String &, const String &);
		friend String operator +(const String &, const char *);
		friend String operator +(const char *,const String &);
	private:
		char *pstr_;
};

String String::operator +(const String &lhs, const String &rhs){
	String str;
	str.pstr_ = new char(strlen(lhs.pstr_) + strlen(rhs.pstr_) + 1);
	strcpy(str.pstr_,lhs.pstr_);
	strcat(str.pstr_,rhs.pstr_);
	return str;
}

String String::operator +(const String &lhs, const char *pstr){
	String str;
	str.pstr_ = new char(strlen(lhs.pstr_) + strlen(pstr) + 1);
	strcpy(str.pstr_,lhs.pstr_);
	strcat(str.pstr_,pstr);
	return str;

}

String String::operator +(const char *pstr,const String &rhs){
	String str;
	str.pstr_ = new char(strlen(pstr) + strlen(rhs.pstr_) + 1);
	strcpy(str.pstr_,pstr);
	strcat(str.pstr_,rhs.pstr_);
	return str;
}

String::String(){
	cout<<"String()"<<endl;
	int len = strlen("Default");
	pstr_ = new char[len + 1];
	strcpy(pstr_,"Default");
}

String::String(const char * pstr){
	cout<<"String(const char *)"<<endl;
	int len = strlen(pstr);
	pstr_ = new char[len + 1];
	strcpy(pstr_,pstr);
}
	
String::String(const String &rhs){
	cout<<"String(const String &)"<<endl;
	int len = strlen(rhs.pstr_);
	pstr_ = new char[len + 1];
	strcpy(pstr_,rhs.pstr_);
}

String::~String(){
	cout<<"~String()"<<endl;
	delete[] pstr_;
}

String & String::operator =(const String &rhs){
	if(&rhs == this){
		return *this;
	}
	cout<<"operator =(const String &rhs)"<<endl;
	delete[] pstr_;
	int len = strlen(rhs.pstr_);
	pstr_ = new char[len + 1];
	strcpy(pstr_,rhs.pstr_);
	return *this;

}

String & String::operator =(const char * pstr){
	cout<<"operator =(const char *)"<<endl;
	delete[] pstr_;
	int len = strlen(pstr);
	pstr_ = new char[len + 1];
	strcpy(pstr_,pstr);
	return *this;
}

String & String::operator +=(const String &rhs){
	cout<<"operator +=(const String &)"<<endl;
	strcat(this->pstr_,rhs.pstr_);
	return *this;
}

String & String::operator +=(const char * pstr){
	cout<<"operator +=(const char *)"<<endl;
	strcat(this->pstr_,pstr);
	return *this;
}

char & String::operator[](std::size_t index){
	cout<<"operator[](std::size_t)"<<endl;
	static char nullchar = '\0';
	if(index>=0 && index<(strlen(pstr_)+1)){
		return pstr_[index];
	}else{
		cout<<"下标越界"<<endl;
		return nullchar;
	}
}

const char & String::operator[](std::size_t index) const{
	cout<<"operator[](std::size_t) const"<<endl;
	static char nullchar = '\0';
	if(index>=0 && index<(strlen(pstr_)+1)){
		return pstr_[index];
	}else{
		cout<<"下标越界"<<endl;
		return nullchar;
	}
}


std::ostream & String::operator<<(std::ostream &os,const String &s){
	os<<s.pstr_<<endl;
	return os;
}

std::istream & String::operator>>(std::istream &is,String &s){
	is>>s.pstr_;
	return is;
}


bool String::operator ==(const String &lhs, const String &rhs){
	if(strcmp(lhs.pstr_,rhs.pstr_) == 0){
		return true;
	}else{
		return false;
	}
}

bool String::operator !=(const String &lhs, const String &rhs){
	if(strcmp(lhs.pstr_,rhs.pstr_) != 0){
		return true;
	}else{
		return false;
	}
}

bool String::operator <(const String &lhs, const String &rhs){	
	if(strcmp(lhs.pstr_,rhs.pstr_) < 0){
		return true;
	}else{
		return false;
	}
}

bool String::operator >(const String &lhs,const String &rhs){
	if(strcmp(lhs.pstr_,rhs.pstr_) > 0){
		return true;
	}else{
		return false;
	}
}

bool String::operator <=(const String &lhs,const String &rhs){
	if(strcmp(lhs.pstr_,rhs.pstr_) <= 0){
		return true;
	}else{
		return false;
	}
}

bool String::operator >=(const String &lhs, const String &rhs){
	if(strcmp(lhs.pstr_,rhs.pstr_) >= 0){
		return true;
	}else{
		return false;
	}
}


std::size_t String::size() const{
	return strlen(this->pstr_);
}

const char *String::c_str() const{
	return this->pstr_;
}
