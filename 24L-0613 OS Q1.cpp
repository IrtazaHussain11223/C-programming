#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<math.h>
using namespace std;
int main()
{
char matrix[4][4]={
{'B','W','W','B'},
{'W','B','B','W'},
{'B','W','B','B'},
{'W','B','W','W'}
};


int count=0;
pid_t child1=fork();
pid_t child2;
if(child1==0)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
if(matrix[i][j]=='B')
count++;
}
}
exit(count);
}
else {
child2 = fork();
if (child2 == 0)
{
int count = 0;
for (int i = 0; i < 4; i++)
if (matrix[0][i] == 'B')
count++;
for (int i = 0; i < 4; i++)
if (matrix[3][i] == 'B')
count++;
for (int i = 1; i < 3; i++)
if (matrix[i][0] == 'B')
count++;
for (int i = 1; i < 3; i++)
if (matrix[i][3] == 'B')
count++;
exit(count);
}
}

int status1;
int status2;
waitpid(child1, &status1, 0);
waitpid(child2, &status2, 0);
int totalshade = WEXITSTATUS(status2);
int totalBlack = WEXITSTATUS(status1);
cout << "Border Black Pixels = " << totalshade << endl;
double borderRatio = (totalshade * 100.0) / totalBlack;
cout << "Border Contribution Ratio (%) = " << borderRatio << endl;
cout << "Total Black Pixels = " << totalBlack << endl;
double density = (totalBlack * 100.0) / 16;
cout << "Black Pixel Density (%) = " << density << endl;
}



