
#include<iostream>
using namespace std;
#include<string.h>
class Book
{
private:
    char name[21];//假设最多为10个汉字
    char publish[21];
    char author[9];
    float price;
public:
    Book(){};
    void print_price() const;//常成员函数是将关键字const写在函数首部
    void print_others();
    int Search();
    void input(int n);
};
void Book::input(int n)
{
    int j;
    for(j=0;j<n;j++)
    {
     cout<<"依次输入书名、作者、出版社、价格："<<endl;
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
    ob[k].input(5);//通过对象数组调用input函数来实现入库。
	//ob[k].print_others;
    
	return 0;
}



