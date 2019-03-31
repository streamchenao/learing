#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	private:
		char name[10];
		int no;
		float score;
		static int totalnum;
		static float totalscore;
	public:
		Student(int num,char na[],float s):no(num),score(s)
		{
			strcpy(name,na);
			totalnum++;
			totalscore+=score;
		}
		Student(){}
		static int GetTotalNum()
		{
			return totalnum;
		}
		static float GetTotalScore()
		{
			return totalscore;
		}
		
		friend void Sort(Student stu[]);
		friend void Print(Student stu[]);
 };
 
 void menu();
 void Sort(Student stu[]);
 void Print(Student stu[]);
 int Student::totalnum=0;
 float Student::totalscore=0;
 
 
 int main()
 {
 	int n;
 	Student stud[50];
 	menu();
 	cout<<"����ѡ�"<<endl;
 
 
 	cin>>n;
 	while(n) 
 	{
 		if(n==1)
 		{
 			int num;
 			char na[20];
 			float sco;
 			cout<<"������ѧ��ѧ�ţ��������ɼ���"<<endl;
 			cin>>num>>na>>sco;
 			Student s(num,na,sco);
 			stud[Student::GetTotalNum()-1]=s;
		}
		else if(n==2)
		cout<<"��������"<<Student::GetTotalNum()<<endl;
		else if(n==3)
		cout<<"�ܷ�����"<<Student::GetTotalScore()<<endl;
		else if(n==4)
		{
			void Sort(Student stu[]);
			void Print(Student stu[]);
		}
		else if(n==5)
		exit(0); 
		
	}
	 return 0;
 }
 
 void menu()
 {
	cout<<"1...�����Ϣ"<<endl;
	cout<<"2...������"<<endl;
	cout<<"3...�ܳɼ�"<<endl;
	cout<<"4...����"<<endl;
	cout<<"5...�˳�"<<endl; 
 }
 
 void Sort(Student stu[])
 {
 	Student temp;
 	int i,j;
 	for(i=0;i<Student::GetTotalNum()-2;i++)
 	{
 		for(j=i+1;j<Student::GetTotalNum()-1;j++)
 		if(stu[i].score<stu[j].score)
 		{
 			temp=stu[i];
 			stu[i]=stu[j];
 			stu[j]=temp;
		 }
	 }
 }
 
 void Print(Student stu[])
 {
 	int i;
 	for(i=0;i<Student::GetTotalNum()-1;i++)
 	{
 		cout<<stu[i].no<<stu[i].name<<stu[i].score<<endl;	
	}
 }
 
 
