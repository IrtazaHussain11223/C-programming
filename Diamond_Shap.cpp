# include<iostream>
using namespace std;
int main()
{
int height;
cout<<"Enter height: ";
cin>>height;
int row=0;
while(row<height)
{int count=0;
while(count<height-row)
	{cout<<" ";
	count++;
	}
count=0;
while(count<2*row+1)
{cout<<"*";
count++;
	}	
cout<<endl;
row++;	
}
while(row>=0)
{int count=0;
while(count<height-row)
	{cout<<" ";
	count++;
	}
count=0;
while(count<2*row+1)
{cout<<"*";
count++;
	}	
cout<<endl;
row--;	

}
return 0;
}

