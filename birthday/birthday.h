#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    //	无参构造函数
    Date(){
        year = 2000;
        month = 1;
        day = 1;
    }

	//	带参构造函数
    Date(int yea, int mont, int da){
        year = yea;
        month = mont;
        day = da;
    }
    
	// 请在 Person 类的打印信息函数中使用 Date 的 show() 方法
    void show()
    {
      cout << year <<"年" << month << "月" << day << "日" << endl;
    };    
};


class Person
{   
private:
   int id;						// ID号
   Date birthDate; 				// 出生年月日
   static int numberOfObjects;  // 静态变量，表示Person类的对象数量

public:
	
    //	无参构造函数
    Person(){
        id = 001;
        birthDate = Date();
        numberOfObjects += 1;
    }

	//	带参构造函数
	Person(int idd,int yea, int mont, int da ){
        id = idd;
        birthDate = Date(yea, mont, da);
        numberOfObjects += 1;
    }

	//	拷贝构造函数
    Person(const Person &person){
        id = person.id;
        birthDate = person.birthDate;

    }

	// 	析构函数
    ~Person(){
        numberOfObjects -=1;
    }

	static int getNumberOfObjects(){  //静态成员函数
        return numberOfObjects;
    }

    void show(){
        cout << "ID: " << id << " , " << "生日：";
        birthDate.show();
    }

};

int Person::numberOfObjects = 0;