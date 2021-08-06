/*
 * matrixHeader.h
 *
 *  Created on: Mar 28, 2021
 *      Author: ankit
 */




#ifndef MATRIXHEADER_H_
#define MATRIXHEADER_H_

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


//Defining the Matrix Class
//Interface
class Matrix {
	int rows = 0;
	int columns = 0;
	vector<vector<int>> matrix;
	Matrix(); //making the default constructor private so that it can't be called
public:
	Matrix(int r, int c, vector<vector<int>> &m);
	Matrix(int r, int c, char matType); //matType is a character I for identity matrix, otherwise an empty matrix is returned
	//Matrix(Matrix &); //copy constructor
	int getRows();
	int getColumns();
	vector<vector<int>> getMatrix();
	void printMatrix();
	void setElement(int i, int j, int val);
	Matrix addMatrix(Matrix &);
	Matrix subtractMatrix(Matrix &);
	Matrix multiplyMatrix(Matrix &);
	Matrix transposeMatrix();
	~Matrix();
};



#endif /* MATRIXHEADER_H_ */
