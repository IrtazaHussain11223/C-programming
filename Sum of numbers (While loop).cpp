/* This program calculates sum of even numbers for a given upper limit of
integers */
#include <iostream>
using namespace std;
main()
{
 //declaration of variables
 int sum, number, upperLimit;

 //Initialization of the variables
 sum = 0;
 number = 1;

 // Prompt the user to enter upper limit of integers
 cout << "Please enter the upper limit for which you want the sum " ;
 cin >> upperLimit;
 // using the while loop to find out the sum of first 1000 integers starting from 1

 while(number <= upperLimit)
 {
 // Adding the even integer to the contents of sum
 if ( ( number % 2 ) == 0 )
 {//((number/2)*2==number)
 sum = sum + number;
 }

 // Generate the next integer by adding 1 to the integer
 number = number + 1;
 }

 cout << "The sum of even numbers of first " << upperLimit << " integers starting from 1 is " << sum;
} 
