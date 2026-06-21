/*#include<iostream>
using namespace std;
int main()/*This code checks for each duplicate value as we go by and then display if any  error in next line and 
if there is no duplictae value it simply ontinues to the next row and takes output of that row. */
{
	int A[9];
	int a[9];
	int B[9];
	int b[9];
	int C[9];
	int c[9];
	int D[9];
	int d[9];
	int E[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (A[i] == A[j]) 
			{
				cout << "Duplicate found: in row one " << endl;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (a[i] == a[j])
			{
				cout << "Duplicate found: in row two " << endl;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (B[i] == B[j])
			{
				cout << "Duplicate found: in row three " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (b[i] == b[j])
			{
				cout << "Duplicate found: in row four " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> C[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (C[i] == C[j])
			{
				cout << "Duplicate found: in row five " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> c[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (c[i] == c[j])
			{
				cout << "Duplicate found: in row six " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> D[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (D[i] == D[j])
			{
				cout << "Duplicate found: in row seven " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> d[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (d[i] == d[j])
			{
				cout << "Duplicate found: in row eight " << endl;
			}
		}
	}for (int i = 0; i < 9; i++)
	{
		cin >> E[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; ++j) {
			if (E[i] == E[j])
			{
				cout << "Duplicate found: in row nine " << endl;
			}
		}
	}
}*/