//#include<iostream>
//using namespace std;
//void allocateMemory(int*& p, int& s)
//{
//	while (s <= 0)
//	{
//		cout << "Enter +ve value\n";
//		cin >> s;
//	}
//	p = new int[s];//If we do not enter by reference changes made here will not be saved in main and memoery will aslo be wasted.
//}
//void getData(int* const& a, int* const& b)
//{
//	cout << "Enter values\n";
//	for (int i = 0; (a + i) != b; i++)
//	{
//		while (*(a + i) < 0)
//		{
//			cout << "Enter +ve value only";
//			cin >> *(a + i);
//		}
//	}//If we use constant ptr to const int then we will not be able to make any chages in the ptr
//}
//void growarray(int*& p, int& s)
//{
//	int temp_s = 0;
//	cout << "Enter the new size\n";
//	cin >> temp_s;
//	while ((s * 2) > temp_s)
//	{
//		cout << "Enter valid data(should be double of previous size)\n";
//		cin >> temp_s;
//	}
//	int* temp = 0;
//	temp = new int[temp_s];
//	for (int i = 0; i < s; i++)
//	{
//		*(temp + i) = *(p + i);
//	}
//	cout << "Enter data for new cells\n";
//	for (int i = s; i < temp_s; i++)
//	{
//		cin >> (*(temp + i));
//		while ((*(temp)+i) < 0)
//		{
//			cout << "Enter +ve value for cell " << i << endl;
//			cin >> (*(temp + i));
//		}
//	}
//	s = temp_s;
//	delete[]p;
//	p = temp;//if we dont do dealloction and realloction then there is a change of memory leak and dandling pointers and to get new array with large size
//	//if any or both parameters were by value then changes made in function will not apear in the main
//}
//void printArray(const int* const& a, const int& s)
//{
//	for (int i = 0; i < s; i++)
//	{
//		cout << *(a + i) << " ";
//	}
//	//to save memory 
//	//to make the ptr to point to its original aka no change in memory adress being pointed
//	//to make sure both the ptr and its value is original aka no chage in both
//	//to keep size varibale original aka avoid chnage 
//}
//int* shrinkArray(int* p, int& s)
//{
//	int t_size = 0;
//	cout << "Enter the shrink size(Any value less than the half of current size)\n";
//	cin >> t_size;
//	while ((s) / 2 < t_size)
//	{
//		cout << "Enter valid input\n";
//		cin >> t_size;
//	}
//	int* temp = new int[t_size];
//	for (int i = 0; i < t_size; i++)
//	{
//		*(temp + i) = *(p + i);
//	}
//	s = t_size;
//	delete[] p;
//	return(temp);
//}
//void getDistinct(int*& p, int& s)
//{
//	int count = 0;
//	int count2 = 0;
//	for (int i = 0; i < s; i++)
//	{
//		for (int j = 0; j < s; j++)
//		{
//			if ((p[i] == p[j]) && (i != j))
//			{
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			count2++;
//		}
//		count = 0;
//	}
//	int* temp = new int[count2];
//	count = 0;
//	for (int i = 0; i < s; i++)
//	{
//		for (int j = 0; j < s; j++)
//		{
//			if ((p[i] == p[j]) && (i != j))
//			{
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			*(temp + i) = *(p + i);
//		}
//		count = 0;
//	}
//	s = count2;
//	delete[] p;
//	p = temp;
//}
//void releaseResources(int*& p)
//{
//	delete[] p;
//	p = NULL;
//	//if we revice const pointe to integer the delete will not work as its address is fixed and NUll will also not work as it chnages the memory address
//}
//int main()
//{
//	int* ptr = NULL;
//	int size = 0;
//	allocateMemory(ptr, size);
//	int* p = (ptr + size);
//	getData(ptr, p);
//	growarray(ptr, size);
//	printArray(ptr, size);
//	ptr = shrinkArray(ptr, size);
//	cout << endl;
//	printArray(ptr, size);
//	cout << endl;
//	getDistinct(ptr, size);
//	cout << "Distinct elements are\n";
//	printArray(ptr, size);
//	releaseResources(ptr);
//
//}