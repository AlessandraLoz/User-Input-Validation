//Course: CS215, Section 05
//Project: Lab Assignment 4
//Date: 09/14/2022
//Purpose: To calculate the accumulative, largest, smallest and amount of prime numbers in User's input. The code should 
// continuously take input and display current accumulative until character Q is entered and that will display to the user the largest smallest and prime numbers.
//Author: Alessandra Lozano, ID#12523364

//For cin and cout
#include <iostream>

//for string variables
#include <string>

//for min and max calculations
#include <algorithm>

//Makes writing code more efficient
using namespace std;

//declaring main function
int main()
{
	//declaring variables for input 
	//Holds first input 
	int UserNum1 = 0;
	//Holds all other inputs 
	int UserNum = 0;
	//Variables to calculate the largest number and smallest number as well as Accumulative 
	//and the Amount of Prime
	int LargestNum = 0;
	int SmallestNum = 0;
	int Accumulative = 0;
	int AmtOfPrime = 0;
	//This variable makes checking for prime easier
	bool PrimeCheck = true;

	//string variable to check input is valid
	string flag;

	//output statement for user input
	cout << "\nPlease enter a series of numbers, then type (Q or q) to process: ";
	//storing user input in variable UserNum 
	cin >> UserNum1;

	//storing variable UserNum as all of them for the first "iteration"
	LargestNum = UserNum1;
	SmallestNum = UserNum1;
	Accumulative = UserNum1;

	//Checking if the user input is prime
	if (UserNum1 == 0 || UserNum1 == 1)
	{
		PrimeCheck = false;
	}
	else
	{	
		//when the number is not 0 or 1 this calculation will be made in 
		//order to determine if the number is prime
		for (int i = 2; i < UserNum1/2; i++)
		{	
			//if the number is divisible by a number other than 1 or 
			//itself then the number is not prime 
			if (UserNum1 % i == 0)
			{
				PrimeCheck = false;
				break; 
			}
		}
		
		//Makes amount of prime after first input one if it is prime
		if (PrimeCheck == true || UserNum == 2)
		{
			AmtOfPrime = 1;
		}
	}

	//Do-while loop will always run unless input= q or Q. If first input is q
	do
	{

		//if statement to check if UserNum is invalid
		if (cin.fail())
		{
			//clearing input in order to continue work with it in loop
			cin.ignore(1000, '\n');
			cin.clear();

			//Puts input from UserNum as the input for string flag
			cin >> flag;

			//If else statement checking wether or not we want to show total or error message
			if (flag == "Q" || flag == "q")
			{
				//clears input and ignores any other input value
				cin.ignore(1000, '\n');
				cin.clear();

				////Output statement with results of largest number, smallest number, and amount of prime
				cout << "\nLargest: " << LargestNum << endl;
				cout << "Smallest: " << SmallestNum << endl;
				cout << "How many Prime numbers? " << AmtOfPrime << endl;
				cout << "Have a great day!" << endl;

				//leaves loop
				break;
			}
			//when input fails but it's not q or Q
			else
			{	
				//ignores input and clears previous input
				cin.ignore(1000, '\n');
				cin.clear();

				//output error message for user 
				cout << "Invalid input, please try again...";
			}


		}
		// when user input doesn't fail
		else
		{
			//ignores input and clears previous input
			cin.ignore(1000, '\n');
			cin.clear();

			//output statement stating the accumulative total
			cout << "The corresponding element for the cumulative total sequence is: " << Accumulative;
		}

		//output statement directing user what to do 
		cout << "\nPlease enter a series of numbers, then type (Q or q) to process: ";

		//takes user input and stores it in variable UserNum
		cin >> UserNum;

		//Calculations for largest, smallest, and accumulative numbers
		LargestNum = max(UserNum, LargestNum);

		//if statement that compares the values held by the respective variables
		if (UserNum < SmallestNum && !cin.fail())
		{
			//Replaces Smallestnum with userNum
			SmallestNum = UserNum;

		}

		//Adds previous iteration with next iteration
		Accumulative = Accumulative + UserNum;
		
		//if else statement checking if number is 0 or 1 and the input doesn't fail
		if (UserNum == 0 || UserNum == 1 && !cin.fail())
		{
			//if conditions are met bool PrimeCheck is false since it is not prime
			PrimeCheck = false;
		}
		else
		{
			//for loop to continuously divide UserNum with i to ensure it has no factors 
			//other than itself and 1
			for (int i = 2; i < UserNum/2; i++)
			{
				//if it is prime PrimeCheck is false else its true
				if (UserNum % i == 0)
				{
					PrimeCheck = false;
				}
				else
				{
					PrimeCheck = true;
				}

			}

			//if UserNum = 2 or PrimeCheck is true then 1 is added to the value of AmtOfPrime
			if (UserNum == 2 || PrimeCheck == true)
			{
				AmtOfPrime = AmtOfPrime + 1;
			}
		
		}
	
	//while condition
	} while (flag != "Q" || flag != "q");






	//ends program
	return 0;

}
