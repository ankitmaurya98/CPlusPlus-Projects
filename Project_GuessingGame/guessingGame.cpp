/*
 * guessingGame.cpp
 *
 *  Created on: Mar 23, 2021
 *      Author: ankit
 */



//This program is a simple guessing game where the user has to try to guess a number correctly between 1-100

/*
 * Instructions:
 * The user is allowed to make up to 5 guesses in order to get the correct number.
 * When prompted, the user will enter their guess in the console.
 * The program will then return if the user's guess is either the correct number of it's higher/lower.
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
using namespace std;


int main(){

	//Defining number of guesses
	const static int totNumGuess = 5;

	//Getting the random number
	/* initialize random seed: */
	srand(time(0));
	int correctNum = rand() % 100 + 1;


	//printf("The correct number is: %d\n", correctNum); //Just used to check what random number is being generated

	puts("Welcome to my Guessing Game!");
	puts("You have 5 tries to correctly guess a number between 1-100");
	puts(" ");

	//Loop until you either guess the correct number or run out of tries
	int tries = 0;
	while(tries < totNumGuess){

		//Getting the user guess
		int guess;
		cout << "Please enter your guess: " << endl;
		cin >> guess;

		//Doing a check to make sure the input is within the specified range
		if(guess < 1 || guess > 100){
			cout << "Please re-enter a number between 1-100 only: " << endl;
			cin >> guess;
		}

		//Comparing the user's guess to the correct number
		if(guess < correctNum){
			puts("You're guess is lower than the correct number");
			printf("You have %d tries left\n", 4-tries);
		}else if(guess > correctNum){
			puts("You're guess is higher than the correct number");
			printf("You have %d tries left\n", 4-tries);
		}else{
			printf("Congratulations! You have correctly guessed that the number is: %d", guess);

			break; //Breaking out of the loop
		}

		//Incrementing the number of guesses that the user has made
		tries++;
	}
	if(tries == totNumGuess){
		puts(" ");
		printf("Sorry you ran out of tries. The correct number was: %d", correctNum);
	}

	return (0);
}
