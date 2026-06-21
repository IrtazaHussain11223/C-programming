#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
int z, i ; 
 int a [ 100 ] ; 
 // Initializing the array. 
 srand(time(0));
 for ( i =0 ; i < 100 ; i ++ ) 
 { 
 a [i] = (rand()%6)+1; 
 } 
 cout << " Please enter a positive integer " ; 
 cin >> z ; 
 int found = 0 ; 
 // loop to search the number. 
 for ( i = 0 ; i < 100 ; i ++ ) 
 { 
 if ( z == a [ i ] ) 
 { 
 found = 1 ; 
 break ; 
 } 
 } 
 if ( found == 1 ) 
 cout << " We found the integer at position " << i<<endl; 
 else 
 cout << "The number was not found"  ;
system("pause");
return 0;

}

