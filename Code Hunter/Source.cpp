// CodeHunter.cpp : Defines the entry point for the console application.
//Edited by: Zack Driscoll

//Found Compile Time Error Here.  This line is not needed and breaks this version of Visual Studio.  This was only valid in Visual Studio 2017 for a different type of project.
//#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string textToAnalyze;

	//Useless variable. Never called by the program and it serves no purpose.
	//Fix:
	//int foo = 0;
	
	//Variables to hold the number of vowels, consonants, numbers, spaces, unknown characters, the length of the user input, and the sum of characters in the user input.
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int spaces = 0;
	int lengthOfStringSubmittedForAnalysis = 0;
	int unknownCharacters = 0;
	int checkSum = 0;

	//Another useless variable that is never called and serves no purpose.
	//Fix:
	//int bar = 0;

	//Output to welcome the user and give instructions.
	//Minor fix. Added '\n' to make the output look nicer for the user.
	cout << "Welcome to the CIA code Hunter Program!" << endl;
	cout << "Please type in text to analyze: \n" << endl;

	//Code to allow access user input.
	getline(cin, textToAnalyze);

	//Loop to analyze the user input.
	for (int i = 0; i < textToAnalyze.length(); ++i)
	{
		//This is checking to see if the current letter is a vowel or not.
		if (textToAnalyze[i] == 'a' || textToAnalyze[i] == 'e' || textToAnalyze[i] == 'i' ||
			textToAnalyze[i] == 'o' || textToAnalyze[i] == 'u' || textToAnalyze[i] == 'A' ||
			textToAnalyze[i] == 'E' || textToAnalyze[i] == 'I' || textToAnalyze[i] == 'O' ||
			textToAnalyze[i] == 'U')
		{
			//If it is a vowel it will run this code and should add to the vowel count.
			//However, this is an error because it is subtracting from our vowel count.
			//Fix
			//--vowels;
			//Fixed
			vowels++;
		}
		else if ((textToAnalyze[i] >= 'a' && textToAnalyze[i] <= 'z') || (textToAnalyze[i] >= 'A' && textToAnalyze[i] <= 'Z'))
		{
			//This 'else if' looks for consonants and adds them to the variable if they are one.
			
			//Error: "++consonants;" shouldn't be commented out. Causes program to not count any of the consonants in the user input.
			//Fix
			//++consonants;
			//Fixed
			consonants++;
		}
		else if (textToAnalyze[i] >= '0' && textToAnalyze[i] <= '9')
		{
			//Checks for numbers.
			++digits;
		}
		else if (textToAnalyze[i] == ' ')
		{
			//Checks for spaces.
			++spaces;
		}
		else
		{
			//Checks for any symbol/character that the program doesn't recognize.
			++unknownCharacters;
		}
	}

	//Gets the length of the user input and adds the variables to get the character count.
	lengthOfStringSubmittedForAnalysis = textToAnalyze.length();
	checkSum = unknownCharacters + vowels + consonants + digits + spaces;

	//Prints out results of the program and prints them for the user.
	//Minor fix. Added '\n' to make the output look nicer for the user.
	cout << "\nVowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White spaces: " << spaces << endl;
	cout << "Length of string submitted for analysis: " << lengthOfStringSubmittedForAnalysis << endl;
	cout << "Number of characters CodeHunter could not identify: " << unknownCharacters << endl;
	cout << "Checksum: " << checkSum << endl;

	//Checks to see if the Analysis is valid and print out a message depending on the result.
	//Minor fix. Added '\n' to make the output look nicer for the user.
	if (checkSum == lengthOfStringSubmittedForAnalysis)
	{
		cout << "\nThis program self checking has found this Analysis to be valid." << endl;
	}
	else
	{
		cout << "\nWARNING! *** This program self checking has found this Analysis to be invalid! Do not use this data!" << endl;
	}

	system("pause");

	return 0;
}