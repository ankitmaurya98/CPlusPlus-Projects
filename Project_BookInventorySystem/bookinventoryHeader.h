/*
 * bookinventoryHeader.h
 *
 *  Created on: Jun 15, 2021
 *      Author: ankit
 */

#ifndef BOOKINVENTORYHEADER_H_
#define BOOKINVENTORYHEADER_H_


#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Defining the Book class
//Interface
class Book {
	int bookCode = 0;                //Code identifier for the book (Each book has a unique number)
	string bookName = "No Name";     //The name of the book
	string bookAuthor = "No Author"; //The book author
	int bookQTY = 0;                 //How much quantity of the book is in inventory
	int bookPrice = 0;               //Price of 1 book

	//Book(); // Making the default constructor private
public:
	Book();
	Book(int code, string name, string author, int qty, int price);
	Book(int code, string name, string author);
	Book(const Book &);  //Copy Constructor
	int getCode();
	string getName();
	string getAuthor();
	int getQTY();
	int getPrice();
	bool inStock(vector<Book*> &, int bookID);
	//void addBook(vector<Book*> &);
	Book addBook(vector<Book*> &);
	void addQuantity(vector<Book*> &, int bookID, int qtytoAdd);
	void buyBook(vector<Book*> &, int bookID, int qtytoBuy);
	void printInventoryList(vector<Book*> &);
	~Book();
};




#endif /* BOOKINVENTORYHEADER_H_ */
