#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	private:
		char name[10],num[10];
		float score;
		static float Totalscore;
		static int Total;
	public:
		Student()
		{
			strcpy(name,0);
			strcpy(num,0);
			score=0;
		}
		friend void Get_In(Student stu[])
		{
			cout<<"����ѧ����ѧ�ţ�������������"<<endl;
			cin>>stu[Total].num>>stu[Total].name>>stu[Total].score;
			Totalscore=Totalscore+stu[Total].score;
			Total++;
		}
		friend void Print(Student stu[]);
		friend void sort(Student stu[]);
		static int Get_Totalscore();
		static int Get_Total();
};

float Student::Totalscore=0;
int Student::Total=0;

int Student::Get_Totalscore()					//�þ�̬��Ա��������̬���ݳ�Ա���س��� 
{
	return Totalscore;
}

int Student::Get_Total()						//�þ�̬��Ա��������̬���ݳ�Ա���س��� 
{
	return Total;
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
	for(i=0;i<=Student::Total;i++)				//ȫ�ֺ������þ�̬���ݳ�ԱʱҪ�������������򣬳�Ա��������ʱ���������������� 
	{
		cout<<stu[i].num<<stu[i].name<<stu[i].score<<endl;
	}
	cout<<"Finished!"<<endl;
}

void Print(Student stu[])
{
	int i;
	for(i=0;i<Student::Total;i++)
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

int main()
{
	menu();
	int sel;
	Student STU[20];
	do
	{
		cout<<"your choice:"<<endl;
		cin>>sel;
		switch(sel)
		{
			case 1: Get_In(STU);
				break;
			case 2: 
				cout<<Student::Get_Total()<<endl;
				break;
			case 3: sort(STU);
				break;
			case 4: Print(STU);
				break;
		}
	} while(sel!=5);
	return 0;
}
