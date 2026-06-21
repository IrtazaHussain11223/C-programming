/*pass by value has modifitcation in copy and in pass by refernce change is made in real value not in copy
and array is pass by referncea as well as all primitive data types*/
/*For file handling we use the library <fstream> know as file stream
ifstream is used for input file stream it will create an object or stream(the file with this can only be read not updated ) structure ifstream infile;(here infile is the name of user given file)
ofstream is used for output of file stream*/
/*#include<iostream//Only for reading not chnaging or outout
#include<fstream>
using namespace std;
int main()//Main return the value to Operating system  0 = ok and 1= not ok
{
	char name[20];
	char salary[10];
	char dept[30];
	ifstream inFile;//this is sink or reviever
	char fileName[] = "D:\Ch 22.txt";//file given by user
	inFile.open(fileName);//now we will attach the source file//We can write ios::in to indictae it is only for reading but it is default and is not required in cause of ifstream as it is only used for reading same cause for out
	if (!inFile)
	{
		cout << "Cant Open the file" << fileName << endl;
		exit(1);//almost same as return but return is for function as it return the control or value to the calling function where as exit termiantes the whole program and does not return anything
	}
	while (!inFile.eof())//eof is end of file it tells about the ending position of file it will automaicttly look for end by moving pointer as we enter the data
	{
		inFile >> name >> salary >> dept;
		cout << " Name " << name << " Salary " << salary << " Departemnt " << dept;
	}
//}*/
//#include<iostream>
//#include<fstream>
//using namespace std;
//int main() //in case of outfile pevious will be deleted and new will ne instered  and if we want to save the previous we will open in append mode
////if file does not exist it will create new
//{
//	ofstream outFile;
//	char fileName[] = "D:\Ch 32.txt";//trunc delets (but it is necessary for the file to exist)the previous data while ate keeps its and allows data to be written anywhere
//	outFile.open(fileName, ios::app);//(ios::out|ios::app) it will do both app and out
//	/*if (!outFile)
//	{
//		cout << "Cant open the file" << fileName << endl;
//		exit(1);
//	}*/
//	outFile << "    Programming fundamets class Room 3001";
//
//}
//#include<iostream>
//#include<fstream>
//using namespace std;
//int main()/*get can we sued here to get charcater by character and here last chacetrer in file is eof*/
//{
//	char c;
//
//}
/*#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char name[50];
	int sal = 0;
	ifstream inFile;
	ofstream outFile;
	inFile.open("D:\employee.txt");
	outFile.open("D:\empSal.txt");
	if (!inFile || !outFile)
	{
		cout << "cant open the file" << endl;
		exit(1);
	}
	outFile << "Name" << "\t" << "Salary" << endl;
	while (!inFile.eof())
	{
		inFile >> name >> sal;
		outFile << name << "\t" << (sal + 2000) << endl;
	}
	inFile.close();

}*/
/*#include<iostream>
using namespace std;
int main()
{
	const int MAXCHAR = 100;
	char buf[MAXCHAR];
	int sal = 0;
	int totalSal = 0;
	char *tokenPtr;
	int num =10;
	int &n = num;//due to the & symbol both the n and num points to same and there is no new memory alloction as n is an alais of num or we are using pass by reference concept
	n++;
	cout << num;
	return 0;

}*/
/*#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	const int MAXCHAR = 100;
	char buf[MAXCHAR];
	int sal = 0;
	int totalSal = 0;
	char* tokenPtr;
	ifstream inFile;
	ofstream outFile;
	inFile.open("D:\employee.txt");
	outFile.open("D:\empSal.txt");
	if (!inFile || !outFile)
	{
		cout << "Cant open file"<<endl;
		exit(1);
	}
	while (!inFile.eof())
	{
		inFile.getline(buf, MAXCHAR);
		tokenPtr=strtok//null in eixt will tell that the compiler will nor read from satrt rather it will read after space
	}
}*/