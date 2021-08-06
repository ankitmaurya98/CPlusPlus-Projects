/*
 * TLEReader.cpp
 *
 *  Created on: Jun 9, 2021
 *      Author: ankit
 */


// This is a simple TLE reader that shows how to load in files into C++
// It then separates out the TLE into the various components and then outputs it to a new text file

/*
 * The input file text file contains the TLE, which is in 3 rows
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//TLE reader function using cstdio
//Enter string "cstdio" if want to use the cstdio functions"
//Enter string "fstream" if want to use the fstream functions"
void TLEReader_func(const char *filename, string openchoice){

	constexpr int maxstring = 1024; // read buffer size

	//Used for switch statement
	const int line1 = 1;
	const int line2 = 2;
	const int line3 = 3;

	if(openchoice == "cstdio"){
		//Using the cstdio functions to open the file and write to new file
		puts("Using cstdio");

		//Reading in the TLE file and writing to new file
		char buf[maxstring]; // creating a buffer
		FILE * myFile = fopen(filename,"r");           //Opening TLE file
		FILE * newFile = fopen("TLEStripped.txt","w"); //Creating new txt file to write to
		//Setup for while loop that reads through the TLE file
		int linecounter = 1;
		char *line1_read;
		char *line3_read;
		while(fgets(buf, maxstring, myFile)){   //While loop that steps through each line in the txt file
			//fputs(buf,stdout);
			//Simple switch statement to perform functions based on what line is being read from the file
			switch(linecounter){
				case line1:
					line1_read = buf;
					fputs(line1_read, newFile);  // Writing to new file
					break;
				case line2:
					puts("read line 2");
					break;
				case line3:
					line3_read = buf;
					fputs(line3_read, newFile);  // Writing to new file
					break;
				default:
					puts("Invalid Case");
					break;
			}

			linecounter+=1;   // Increasing this counter for next iteration as the next line will be read
		}
		fclose(myFile);
		fclose(newFile);



	}else if(openchoice == "fstream"){
		//Using the fstream functions to open the file and write to new file
		puts("Using fstream");

		//Reading in the TLE file and writing to new file
		ifstream inFile;        //Setting up to read in the TLE file
		inFile.open(filename);  // Opening the file
		ofstream outFile("TLE Output fstream.txt");
		string line;
		int linecounter_fstream = 1;

		while(getline(inFile, line)){
			cout << line << endl;
			//Simple switch statement to perform functions based on what line is being read from the file
			switch(linecounter_fstream){
				case line1:
					outFile << line << "\n";
					break;
				case line2:
					puts("read line 2");
					break;
				case line3:
					outFile << line << "\n";
					break;
				default:
					puts("Invalid Case");
					break;
			}
			linecounter_fstream+=1;
		}
		inFile.close();
		outFile.close();


	}else{
		printf("Invalid string entered. Please enter either cstdio or fstream");
	}

}


//Main function
int main(){

	const char * filename = "TLE.txt"; // This is the file that will be opened

	//Opened using the cstdio functions
	//TLEReader_func(filename, "cstdio");

	//Opened using the fstream function
	TLEReader_func(filename, "fstream");

	return (0);
}


