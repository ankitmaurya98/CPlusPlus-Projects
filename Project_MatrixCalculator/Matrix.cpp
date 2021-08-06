/*
 * Matrix.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: ankit
 */


#include "matrixHeader.h" //includes the matrixHeader.h header file
//#include <cstdio>


//Implementation for the Matrix class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Constructor with arguments, have to input in a created vector of vectors
Matrix::Matrix(int r, int c, vector<vector<int>> &m)
:rows(r), columns(c), matrix(m){} //inputs: r is the # rows, c is the # columns, m is a vector of vectors matrix

/*
//Copy Constructor
Matrix::Matrix(Matrix &m){
	rows = m.rows;
	columns = m.columns;
	//matrix = m;
}
*/

//Constructor with arguments to create an identity matrix, returns an empty matrix if conditions are not met
Matrix::Matrix(int r, int c, char matType)
:rows(r), columns(c){

	matrix.resize(r, vector<int>(c,0));

	//Setting for identity matrix
	if(matType == 'I' && r == c){
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(i == j){
					matrix[i][j] = 1;
				}
			}
		}
	//Setting for empty matrix
	}
}


//Destructor
Matrix::~Matrix(){
	puts("Destructor Called");
}

//getRows() function
int Matrix::getRows(){
	//printf("The number of rows in the matrix is %d\n", rows);
	return rows;
}

//getColumns() function
int Matrix::getColumns(){
	//printf("The number of columns in the matrix is %d\n", columns);
	return columns;
}

//getMatrix() function
vector<vector<int>> Matrix::getMatrix(){
	return matrix;
}

//printMatrix function
void Matrix::printMatrix(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%d ", matrix[i][j]);
		}
		puts(" ");
	}
	puts(" ");
}

//setElement() function
void Matrix::setElement(int i, int j, int val){
	/* Inputs:
	 * 		int i - row element # (starting from 0)
	 * 		int j - column element # (starting from 0)
	 * 		int val - new value that will be set in that position
	 *
	 * 	Output:
	 * 		void output, however it will replace the current value in that matrix element with the new value
	 */

	matrix[i][j] = val;
}

//addMatrix() function
Matrix Matrix::addMatrix(Matrix &x){
	/* Inputs:
	 *		Matrix x - passing in a reference to second matrix object
	 *		Calling this function on an already created matrix object in order to add another matrix to that
	 *	Output:
	 *		A matrix of type Matrix with its rows and columns
	 */


	if(x.getRows() == rows && x.getColumns() == columns){
		vector<vector<int>> z; //creating a vector of vectors to hold the resultant matrix
		z.resize(rows,vector<int>(columns,0)); //resize the vector to R(rows) elements of type vector<int>, each having size C(columns), where new values will be initialized to 0
		//Getting the matrix data member from inputed Matrix object
		vector<vector<int>> xMatrix = x.getMatrix();

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				z[i][j] = matrix[i][j] + xMatrix[i][j];
			}
		}

		Matrix sum(rows, columns, z);
		return sum;
	}else{
		puts("The matrices are not the same size, therefore they can't be added together");
		vector<vector<int>> empty{{0,0},{0,0}}; //creating a empty 2 x 2 matrix to return
		Matrix emptyMat(2,2,empty);
		return emptyMat; //returning a empty 2 x 2 matrix if the addition can't be performed
	}
}

//subtractMatrix() function
Matrix Matrix::subtractMatrix(Matrix &x){
	/* Inputs:
	 *		Matrix x - passing in a reference to second matrix object
	 *		Calling this function on an already created matrix object in order to subtract another matrix to that
	 *	Output:
	 *		A matrix of type Matrix with its rows and columns
	 */


	if(x.getRows() == rows && x.getColumns() == columns){
		vector<vector<int>> z; //creating a vector of vectors to hold the resultant matrix
		z.resize(rows,vector<int>(columns,0)); //resize the vector to R(rows) elements of type vector<int>, each having size C(columns), where new values will be initialized to 0

		//Getting the matrix data member from inputed Matrix object
		vector<vector<int>> xMatrix = x.getMatrix();

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				z[i][j] = matrix[i][j] - xMatrix[i][j];
			}
		}

		Matrix subtractedMatrix(rows, columns, z);
		return subtractedMatrix;
	}else{
		puts("The matrices are not the same size, therefore they can't be subtracted together");
		vector<vector<int>> empty{{0,0},{0,0}}; //creating a empty 2 x 2 matrix to return
		Matrix emptyMat(2,2,empty);
		return emptyMat; //returning a empty 2 x 2 matrix if the addition can't be performed
	}
}


//multiplyMatrix() function
Matrix Matrix::multiplyMatrix(Matrix &x){
	/* Input:
	 * 		Matrix x -  passing in a reference to second matrix object
	 * 		Calling this function on an already created matrix object in order to multiply another matrix to that
	 * 	Output:
	 * 		A matrix of type Matrix with its rows and columns
	 */

	//Checking to see if matrix dimensions are correct in order to perform multiplication
	if(columns == x.getRows()){
		vector<vector<int>> z; //creating a vector of vectors to hold the resultant matrix
		z.resize(rows,vector<int>(x.getColumns(),0)); //resize the vector to R(rows) elements of type vector<int>, each having size C(columns), where new values will be initialized to 0

		//Getting the matrix data member from inputed Matrix object
		vector<vector<int>> xMatrix = x.getMatrix();

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < x.getColumns(); j++){
				for(int k = 0; k < columns; k++){
					z[i][j] = z[i][j] + (matrix[i][k]*xMatrix[k][j]);
				}
			}
		}
		/* Example of how algorithm for multiplication above works
		 * 		1st time through k for loop: z[0][0] = z[0][0] + matrix[0][0]*xMatrix[0][0]
		 * 		next step in k for loop: z[0][0] = z[0][0] + matrix[0][1]*xMatrix[1][0]
		 * 		etc...
		 *
		 * 		bc for example if have C = A*B:
		 * 			C[1][1] = A[1][1]*B[1][1] + A[1][2]*B[2][1]
		 * 			C[1][2] = A[1][1]*B[1][2] + A[1][2]*B[2][2]
		 */

		Matrix multipliedMatrix(rows, x.getColumns(), z);
		return multipliedMatrix;

	}else{
		puts("The matrices do not have the correct dimensions, "
				"therefore they can't be multiplied together");
		vector<vector<int>> empty{{0,0},{0,0}}; //creating a empty 2 x 2 matrix to return
		Matrix emptyMat(2,2,empty);
		return emptyMat; //returning a empty 2 x 2 matrix if the addition can't be performed
	}
}

//transposeMatrix() function
Matrix Matrix::transposeMatrix(){

	/*	Input:
	 * 		No inputs
	 * 	Output:
	 * 		A transposed matrix is returned as a Matrix object
	 */

	vector<vector<int>> tMat; //creating a vector of vectors to hold the resultant matrix
	tMat.resize(columns,vector<int>(rows, 0)); //resize the vector to R(columns) elements of type vector<int>, each having size C(rows)

	//Transpose algorithm where the rows of the original matrix becomes columns of the resultant matrix
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			tMat[j][i] = matrix[i][j];
		}
	}
	Matrix transposedMatrix(columns, rows, tMat); //Creating a Matrix object from the resultant vector of vectors

	return transposedMatrix;
}






