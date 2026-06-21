# include<iostream>
using namespace std;
int main()
{
int p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y;
int d1,d2,d3,d4,dg1,dg2;
cout<<"***Enter Points***"<<endl;
cout<<"P1: ";
cin>>p1x>>p1y;
cout<<"\n";
cout<<"P2: ";
cin>>p2x>>p2y;
cout<<"\n";
cout<<"P3: ";
cin>>p3x>>p3y;
cout<<"\n";
cout<<"P4: ";
cin>>p4x>>p4y;
cout<<"\n";// equal to endl
d1=((p2x-p1x)*(p2x-p1x)+(p2y-p1y)*(p2y-p1y));
d2=((p3x-p2x)*(p3x-p2x)+(p3y-p2y)*(p3y-p2y));
d3=((p4x-p3x)*(p4x-p3x)+(p4y-p3y)*(p4y-p3y));
d4=((p1x-p4x)*(p1x-p4x)+(p1y-p4y)*(p1y-p4y));
//diagonal
dg1=((p3x-p1x)*(p3x-p1x)+(p3y-p1y)*(p3y-p1y));
dg2=((p4x-p2x)*(p4x-p2x)+(p4y-p2y)*(p4y-p2y));
//Checkes
if(d1==d2 && d1==d3 && d1==d4)
{
if(dg1==dg2)
{cout<<"Its a Square"<<endl;
	}	else
	{
		cout<<"Its a Rhombus"<<endl;
	}
	
} else if(d1==d3 && d2==d4 && d1!=d2)
{
	if(dg1==dg2)
	{cout<<"Its a Rectangle"<<endl;
	}else
	{cout<<"Its a Parallelogram"<<endl;
	}
}else {cout<<"Its a Quardrilateral"<<endl;
}
return 0;
}

