
#include<iostream>
using namespace std;
#include<string.h>
class Book
{
private:
    char name[21];//�������Ϊ10������
    char publish[21];
    char author[9];
    float price;
public:
    Book(){};
    void print_price() const;//����Ա�����ǽ��ؼ���constд�ں����ײ�
    void print_others();
    int Search();
    void input(int n);
};
void Book::input(int n)
{
    int j;
    for(j=0;j<n;j++)
    {
     cout<<"�����������������ߡ������硢�۸�"<<endl;
    cin>>name>>author>>publish>>price;
   }
}
/*void Book::print_others()
{
	
	cout<<ob[k].name<<ob[k].author<<ob[k].publish<<endl;
}*/
int main()

{
    int k;
    //cin>>n;
    Book ob[5];
	for(k=0;k<=5;k++)
    ob[k].input(5);//ͨ�������������input������ʵ����⡣
	//ob[k].print_others;
    
	return 0;
}



