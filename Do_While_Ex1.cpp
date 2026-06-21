//This program allows the user to guess a character from a to z
//do-while construct is used to allow five tries for guessing
# include <iostream>
using namespace std;
int main ( )
{
 //declare & initialize variables
int tryNum = 0 ;
char c ;
// do-while construct, prompt the user to guess a number and compares it
do
{
cout << "Please enter a character between a-z for guessing : ";
cin >> c;
//check the entered character for equality
if ( c == 'z')
 {
 cout << "Congratulations, Your guess is correct" ;
}
else
{
 tryNum = tryNum + 1;
}
}
 while ( tryNum <= 5 && c != 'z' );
return 0;
} 