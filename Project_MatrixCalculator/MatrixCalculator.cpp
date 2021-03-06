/*
 * MatrixCalculator.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: ankit
 */


/*This is a program that can be used to work with matrices:
 * 		The user has to input:
 * 			The number of rows in the matrix
 * 			The number of columns in the matrix
 * 			The elements of the matrix
 *
 * 		The functions that can then be called upon are:
 * 			getRows() - which returns the number of rows in the matrix
 * 			getColumns() - which returns the number of columns in the matrix
 * 			getMatrix() - this returns the matrix data member from the Matrix class (returns the vector of vectors)
 * 			printMatrix() - prints the matrix to the console
 * 			setElement() - which sets the elements of the matrix at a particular position
 * 			addMatrix() - which adds 2 matrices together
 * 			subtractMatrix() - which subtracts 2 matrices together
 * 			multiplyMatrix() - which multiplies 2 matrices together
 * 			transposeMatrix() - which returns the transpose of a matrix
 */

// See Level 2 example problem https://www.codesdope.com/practice/cpp-classes-and-objects/

/* This project contains the following files:
 * 	MatrixCalculator.cpp - contains the main function
 * 	matrixHeader.h - contains the interface for the Matrix class
 *	Matrix.cpp - contains the implementation for the Matrix class
 */

//These are all defined in the matrixHeader file
//#include <cstdio>
//#include <vector>
//#include <iostream>
//using namespace std;


#include "matrixHeader.h" //includes the matrixHeader.h header file



int main(){


	//Inputing the matrices using vector of vectors
	vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};

/*
	//Creating the Matrix objects
	Matrix a(3,3, m);
	a.printMatrix();
	a.setElement(0,0,0);
	a.printMatrix();

	//Matrix b = a;
	//b.setElement(1,1,21);
	//b.printMatrix();

	//Testing the add function
	puts("~~~~~~~~~Addition Function~~~~~~~~~~~");
	vector<vector<int>> k{{1,0},{1,0}};
	vector<vector<int>> l{{0,1},{0,1}};
	Matrix kMat(2,2,k);
	Matrix lMat(2,2,l);
	kMat.printMatrix();
	lMat.printMatrix();
	Matrix addition = kMat.addMatrix(lMat);
	addition.printMatrix();

	//Testing the subtract function
	puts("~~~~~~~~~Subtraction Function~~~~~~~~~~~");
	vector<vector<int>> n{{1,1},{1,1}};
	Matrix nMat(2,2,n);
	nMat.printMatrix();
	Matrix subtraction = nMat.subtractMatrix(lMat);
	subtraction.printMatrix();

*/

	//Testing the multiply function
	puts("~~~~~~~~~Multiplication Function~~~~~~~~~~~");
	vector<vector<int>> a{{1,2},{3,4}};
	vector<vector<int>> b{{1,2},{3,4}};
	Matrix aMat(2,2,a);
	Matrix bMat(2,2,b);
	Matrix multiplication_1 = aMat.multiplyMatrix(bMat);
	multiplication_1.printMatrix();

	vector<vector<int>> c{{5},{6}};
	Matrix cMat(2,1,c);
	Matrix multiplication_2 = aMat.multiplyMatrix(cMat);
	multiplication_2.printMatrix();



	//Testing the transpose function
	puts("~~~~~~~~~Transpose Function~~~~~~~~~~~");
	vector<vector<int>> t{{1,2},{3,4},{5,6}};
	Matrix tMat(3,2,t);
	tMat.printMatrix();
	Matrix transposedMatrix = tMat.transposeMatrix();
	transposedMatrix.printMatrix();

	//Example showing how an empty vector of vectors can be resized to be a 4 x 5 matrix only of zeros
	vector<vector<int>> emptyMat;
	emptyMat.resize(4,vector<int>(5,0));
	Matrix new_Mat(4,5,emptyMat);
	new_Mat.printMatrix();

	//Example of identity matrix and empty matrix constructors
	Matrix identity(3,3,'I');
	identity.printMatrix();
	Matrix testMat(3,2,'E');
	testMat.printMatrix();


	return 0;
}
