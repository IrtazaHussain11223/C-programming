#include <cstdlib>
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(int argc, char * arvg[])
{
string arr= argv[1];
int arr1[100];
string temp = "";
int c=0;
for(int i=0;i<arr.lenght();i++)
{
if(arr[i]=='$')
{
arr1[count++] = atoi(temp.c_str());
            temp = "";

}
else
        {
            temp += input[i];
        }
}
arr[count++] = atoi(temp.c_str());
pid_t pid1 = fork();
if (pid1 == 0)
{
int sum = 0;
for (int i = 0; i < count; i++)
sum += arr[i];
cout << "child 1 PID: " << getpid() << endl;
cout << "Sum = " << sum << endl;
id_t pid2 = fork();
if (pid2 == 0)
{
int sum = 0;
for (int i = 0; i < count; i++)
sum += arr[i];
float avg = (float)sum / count;
cout << "Child 2 PID: " << getpid() << endl;
cout << "Average = " << avg << endl;
   
}
}
