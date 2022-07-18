
#include "score.h"  
int main()  
{  
    int n = 3;  
    Student* Stu = new Student[n];
    string Num;             // 学号  
    string Name;            // 姓名  
    float Chinese;          // 语文课成绩  
    float    English;       // 英语课成绩   
    float    Mathematics;   // 数学课成绩
    // 输入测试数据  
    for (int i = 0; i < n; i++)  
    {  
        cin >> Num >> Name >> Chinese >> English >> Mathematics;  
        // 调用有参构造函数  
        Stu[i] = Student(Num, Name, Chinese, English, Mathematics);  
    }
    // 打印所有学生信息  
    for (int i = 0; i < n; i++)  
    {          
        Stu[i].print();  
    }
    // 修改某个学生信息，重新打印输出所有学生信息  
    Stu[1].modify("202216", "学生K", 99, 98, 90);  
    cout << "修改后为：" << endl;  
    for (int i = 0; i < n; i++)  
    {  
        Stu[i].print();  
    }  
    return 0;
}  