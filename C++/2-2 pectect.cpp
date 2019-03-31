#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Student
{
	private:
		char name[10],num[10];
		float score;
		static int Total;
		static float Totalscore;
	public:
		Student()
		{	
			strcpy(name,0);
			strcpy(num,0);
			score=0; 
		} 
		
		friend void Get_in(Student stu[])
		{
			cout<<"please input the number,name,score:"<<endl;
			cin>>stu[Total].num>>stu[Total].name>>stu[Total].score;
			Total++;
			Totalscore=Totalscore+stu[Total].score;
		}
		
		friend void Print(Student stu[]);
		friend void Sort(Student stu[]);
		static int Get_Total();
		static float Get_Totalscore();
};


float Student::Totalscore=0;
int Student::Total=0;		

int Student::Get_Total()		//用静态成员函数将静态数据成员返回出来 
{
	return Total;
}

float Student::Get_Totalscore()
{
	return Totalscore;	
} 

void Print(Student stu[])
{
	int i;
	for(i=0;i<Student::Total;i++)		//在此使用做上限的时候 ，不是使用Get_Total 
		cout<<stu[i].num<<stu[i].name<<stu[i].score<<endl;
}

void menu()
{
	cout<<"1-Enter student information!"<<endl;
	cout<<"2-Output the current total number of people!"<<endl;
	cout<<"3-Sort by grade!"<<endl;
	cout<<"4-Output all student information!"<<endl;
	cout<<"5-exit!"<<endl;
}

void sort(Student stu[])
{
	int i,j,k;
	Student temp;
	for(i=0;i<=Student::Total;i++)
	{
		for(j=i+1;j<=Student::Total;j++)
		{
			if(stu[i].score<stu[j].score)
			k=i;
			else
			k=j;
		}
		temp=stu[i];
		stu[i]=stu[k];
		stu[k]=temp;
	}
	for(i=0;i<=Student::Total;i++)			//全局函数调用静态数据成员时要加类名和作用域，成员函数调用时不用类名和作用域 
	{
		cout<<stu[i].num<<stu[i].name<<stu[i].score<<endl;
		
	}
	cout<<"Finished!"<<endl; 
}

int main()
{
	menu();
	int sel;
	Student STU[30];
	do
	{
		cout<<"your choice!"<<endl;
		cin>>sel;
		switch(sel)
		{
			case 1: Get_in(STU);
					break;
			case 2: cout<<Student::Get_Total()<<endl;
					break;
			case 3: sort(STU);
					break;
			case 4: Print(STU);
					break;
		}	
	} while(sel!=5);
	return 0;
}

