// Breeding program.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CSC 275 Final Project
// Daniel Connell

#include <iostream>				// allows for inputs from keyboard and output to monitor
						
#include <fstream>			    // allows for input and output to file
#include <string>				// allows string variables
#include "female.h"	    // allows for accdes to this specified .h file
#include "male.h"	 
#include "animal.h"

 
using namespace std;			// eliminates std::



int main()						// start main
								
{

													// title out put to screen

	cout << "\n\n\t Welcome to the Reindeer Farm Breeding program \n\n";

													// intro
   cout << "\tThis is an herd breeding managment program\n";
   cout << "\tYou will be asked to provide input on your herd\n";
   cout << "\tSpecific information may be needed for animal identification:\nincluding animals gender, age, or ID number.";   
   cout << "\tBased on herd breeding dynamics only 1 male reindeer will be used for each breeding cohort. \n";

   //Class 1 Object 1 //Parent Class
   //animal;
   //Class 2 Object 2					//Child Class
   female reindeerFemale;		 // here we create object reindeerFemale from classes
   //Class 3 Object 3					//Child Class
   male reindeerMale;			// here we create object reindeerMale from classes
   cout << "\n\n\n\t*** My name is Dan. *** \n\n";
													// Ask user for their name
   cout << "\n\t*** When you are ready to plan your herd breeding plan\nenter your farms name. *** \n\n";
													// creates a variable in memory to hold the palyers name
   string farmName;
													// This will get the palyers name
   cout << "\tMy farms name is:  ";
													//get line cin gets input from the player to be used throughout the game
   getline(cin, farmName);
													// Welcome the user
   cout << "\t" << " Welcome to the " + farmName + "Breeding program. \n\tLets get some information about your herd. \n\n";
   
   //Exception
START:                                // creates a start point reference 
   int usrin;                            // allows for user input
   try {
	   cout << "\t" << " Please tell me how many female reindeer you plan to breed this year (between 1-10).\n" << endl;
	   cin >> usrin;                     //accepts user input
	   if (usrin < 1 || usrin > 10)      //defines allowable input parameters
	   {
		   throw "Bad Input, Try Again"; //this must match the catch type (int,char)
	   }
	   if (usrin >= 1 || usrin <= 10)    //defines allowable input parameters
	   {
		   throw 1;                      //this must match the catch type (int,char)
	   }

   }
   catch (const char* txtException)     //This will catch the throw and trigger the exception function
   {
	   cout << txtException << endl;
	   goto START;
   }
   catch (int)                          //This will catch the throw and trigger the exception function
   {
	   cout << "You plan to breed "  << endl;

   }



   
   string reindeerQuantityFemales;
   string malesID;

   getline(cin, reindeerQuantityFemales);//get line cin gets input from the player to be used throughout the game

   cout << "\t" << "Please enter the ID# for you male reindeer you plan to breed this year.\n";

   getline(cin, malesID);

   cout <<"\tDan replies - I understand you have " + reindeerQuantityFemales << " females and "  <<  " male to breed this year.\n\n\n";
   //File input and output processing 
   string line;										//line is the variable used
   fstream inFile;									//Creates a class for file input 
   fstream outFile;									//Creates a class for file output
   
   outFile.open("Reindeer Breeding.txt", ios::out);	/*this will createand allow access to the.txt file named here
													write__ios::app will preserve prior data and add new data to the file
													ios::out allows writing to the file and will over write previous data on each line */        
   {
	   outFile << reindeerQuantityFemales + " females and "  + " males to breed this year.\n";

	outFile.close();								 //this closes the outfile
	
	inFile.open("Reindeer Breeding.txt", ios::app); //write__ios::app will preserve prior data and add new data to the file   
	if (inFile.is_open())							 //infile is a class and .is_open is a method
	{
		inFile << reindeerQuantityFemales + " females and " + " males to breed this year.\n"; // inFile << will write data into this file
		inFile.close();								//this closes the infile
	}
   }												//end of outfile
   
   inFile.open("Reindeer Breeding.txt", ios::in);	//read__
   if (inFile.is_open())							//file is a class and .is_open is a method
   {
	   while (getline(inFile, line))				//this WHILE LOOP uses the GETLINE FUNCTION to access OBJECT OUTFILE          
	   {
		   cout << line << endl;					//this Write the contents of the .txt to the display                         

	   }
	   inFile.close();								//this closes the infile

   }												//end of outfile
   else cout << "unable to open output file" << endl;


   
   
	
   system("pause");
   return 0;
} // end main
