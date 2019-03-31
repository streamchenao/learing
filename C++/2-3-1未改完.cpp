#include<iostream>

using namespace std;

class Cat
{
	private:
		double weight;
		static double Totalweight;
		static int all;
	public:
		friend void Get_in(Cat CAT[])
		{
			cout<<"please input the weight of the cat!: "<<endl;
			cin>>CAT[all].weight;
			all++;
			Totalweight+=CAT[all].weight;
		}
		friend void Print(Cat CAT[]);
		static int G_all();
		static double G_weight();
};


double Cat::Totalweight=0;
int Cat::all=0;

int Cat::G_all()
{
	return all; 
} 

double Cat::G_weight()
{
	return Totalweight;
}


void Print(Cat CAT[])
{
	int i;
	for(i=0;i<=Cat::all-1;i++)
		cout<<CAT[i].weight<<endl;
}

void menu()
{
	cout<<"1-input the weight of cat"<<endl;
    cout<<"2-output the weight of all cats"<<endl;
    cout<<"3-output total weight "<<endl;
    cout<<"4-exit "<<endl;
}

int main()
{
	Cat CAT[20];

	int sel;
	do
	{
		menu();
		cout<<"please input your choice: "<<endl;
		cin>>sel;
		switch(sel)
		{
			case 1:
				Get_in(CAT);
				break;
			case 2:
				Print(CAT);
				break;
			case 3:
				cout<<Cat::G_weight()<<endl;
				break;
	
		}
	}while(sel!=4);
	return 0;
}



