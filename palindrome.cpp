/*
 * palindrome.cpp
 *
 *  Created on: May 1, 2019
 *      Author: Alex
 */

/*************************************************************************************************
 * This program prompts a user to enter a string, and will not exit until a palindrome is entered. 
 *************************************************************************************************/

#include<iostream>
using namespace std;

void reverse(string&, int);
bool isPalindrome(string, int, int);

const int MAX = 20;

int main()
{
	int length = 0, err = 0;
	string input;

	do
	{
		try
		{
			err = 0;
			cout << "\nEnter a string up to " << MAX << " characters: ";
			cin >> input;
			length = input.length();

			// Throw an exception if the string is too large
			if(length>MAX)
			{
				throw length;
			}
			cout << "\nThe string entered is:\t" << input;

			// reverse the string
			string inputReverse;
			reverse(input, 0);


			cout << "\nThe string reversed is:\t" << input;

			// Throw an exception if the string is not a palindrome
			if(!isPalindrome(input,0,length-1))
				throw input ;

			cout << "\nNice palindrome!\n";
		}
			catch(int length)
			{
				cerr<<input<<" over capacity by: "<<length-MAX<<"characters"<<endl;
				err=1;
			}

			catch(string& input)
			{
				cerr<<"String is not a Palindrome"<<input<<endl;
				err=1;
			}


	} while (err);
	return 0;
}
/*******************************************************************
 *  Uses recursion to reverse the input string passed by reference.
 *******************************************************************/
void reverse(string &str, int k)
{
	static int i=0;

	if(k==str.length()) // Base case
		return ;
	
	reverse(str, k+1); // Recursive call

	if(i<=k)
		swap(str[i++],str[k]);

}
/*******************************************************************
 Uses recursion to determine is the input string is a palindrome
 *******************************************************************/

bool isPalindrome(string str, int low, int high)
{
	if(low>= high)   //base case
		return true;

	if(str[low]!= str[high])//return false if mismatch
		return false;

	return isPalindrome(str, low+1, high-1); //recursive call
}


