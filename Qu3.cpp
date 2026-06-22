#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
string arr = argv[1];
int arr1[100];
string temp = "";
int count = 0;

for (int i = 0; i < arr.length(); i++)
{
if (arr[i] == '$')
{
arr1[count++] = atoi(temp.c_str());
temp = "";
}
else
{
temp += arr[i];
}
}

arr1[count++] = atoi(temp.c_str());

pid_t pid1 = fork();
if (pid1 == 0)
{
int sum = 0;
for (int i = 0; i < count; i++)
sum += arr1[i];
cout << "Child 1 PID: " << getpid() << endl;
cout << "Sum = " << sum << endl;
return 0;
}

pid_t pid2 = fork();
if (pid2 == 0)
{
int sum = 0;
for (int i = 0; i < count; i++)
sum += arr1[i];
float avg = (float)sum / count;
cout << "Child 2 PID: " << getpid() << endl;
cout << "Average = " << avg << endl;
return 0;
}

wait(NULL);
wait(NULL);

return 0;
}
