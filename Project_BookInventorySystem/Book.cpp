/*
 * Book.cpp
 *
 *  Created on: Jun 15, 2021
 *      Author: ankit
 */

//This is the class file for the Book class

#include "bookinventoryHeader.h" // Includes the bookinventoryHeader header file


//Implementation for the Book class
Book::Book(){}

//Constructor that has all inputs
Book::Book(int code, string name, string author, int qty, int price)
:bookCode(code), bookName(name), bookAuthor(author), bookQTY(qty), bookPrice(price){puts("CONSTRUCTOR");}

//Constructor with just book code, book name, and book author as the input
Book::Book(int code, string name, string author)
:bookCode(code), bookName(name), bookAuthor(author){puts("CONSTRUCTOR");}

//Copy Constructor
Book::Book(const Book &a){
	bookCode = a.bookCode;
	bookName = a.bookName;
	bookAuthor = a.bookAuthor;
	bookQTY = a.bookQTY;
	bookPrice = a.bookPrice;
}

//Destructor
Book::~Book(){
	puts("Destructor called");
}

//getCode() function
int Book::getCode(){
	/* Inputs:
	 * 		None
	 * 	Output:
	 * 		int value of the unique code that identifies the book
	 */
	return bookCode;
}

//getName() function
string Book::getName(){
	/* Inputs:
	 * 		None
	 * 	Output:
	 * 		string value of the name of the book
	 */
	return bookName;
}

//getAuthor() function
string Book::getAuthor(){
	/* Inputs:
	 * 		None
	 * 	Output:
	 * 		string value of the author of the book
	 */
	return bookAuthor;
}

//getQTY() function
int Book::getQTY(){
	/* Inputs:
		 * 		None
		 * 	Output:
		 * 		int value of the quantity of book in inventory
		 */
	return bookQTY;
}

//getPrice() function
int Book::getPrice(){
	/* Inputs:
		 * 		None
		 * 	Output:
		 * 		int value of the price of 1 book
		 */
	return bookPrice;
}

//inStock(Book &) function
bool Book::inStock(vector<Book*> &database, int bookID){
	/* Inputs:
	 * 		a vector database that contains all books listed
	 * 		int value of the book that is being checked
	 * 	Output:
	 * 		true/false if book is in stock. If in stock then returns how many copies in stock
	 */


	for(unsigned int i = 0; i < database.size(); i++){
		if(database[i]->getCode() == bookID){
			printf("The book %s is in stock. There are %d copies in stock\n", (database[i]->getName()).c_str(), database[i]->getQTY());
			return true;
		}
	}
	return false;
}


//addBook() function
//void Book::addBook(vector<Book*> &database){
Book Book::addBook(vector<Book*> &database){
	/* Inputs:
	 * 		a vector database that contains all books listed
	 * 		The user will then be asked to input all the requested info in the console
	 * 	Output:
	 * 		Nothing returned - Just a print statement stating updated quantity of book in storage
	 * 		Database vector will be updated to hold the new entry
	 */

	std::string BookName;
	std::string BookAuthor;
	int BookQty;
	int BookPrice;

	cin.ignore();
	std::cout << "Please enter the Book Title, Use $ at then end of entry as delimiter:" << std::endl;
	getline (cin, BookName,'$');
	std::cout << "Please enter the Book Author, Use $ at then end of entry as delimiter:" << std::endl;
	cin.ignore();
	getline (cin, BookAuthor, '$');
	std::cout << "Please enter quantity of books being added to the database:" << std::endl;
	cin.ignore();
	cin >> BookQty;
	std::cout << "Please enter the cost of one book:" << std::endl;
	cin.ignore();
	cin >> BookPrice;

/*
	puts("Start Function");
	Book book(database.size() + 1, BookName, BookAuthor, BookQty, BookPrice);
	puts("Object Created");
	database.push_back(&book);
*/
	Book newBook(database.size() + 1, BookName, BookAuthor, BookQty, BookPrice);

	return newBook;
}

//addQuantity() function
void Book::addQuantity(vector<Book*> &database, int bookID, int qtytoAdd){
	/* Inputs:
	 * 		a vector database that contains all books listed
	 * 		int value of the bookID
	 * 		int value of the quantity to add for that book
	 * 	Output:
	 * 		Nothing returned - Just a print statement stating updated quantity of book in storage
	 */


	for(unsigned int i = 0; i < database.size(); i++){
		if(database[i]->getCode() == bookID){
			database[i]->bookQTY = database[i]->getQTY() + qtytoAdd;
			printf("The Book: %s now had %d copies in inventory\n", (database[i]->getName()).c_str(), database[i]->getQTY());
		}

	}


}

//buyBook() function
void Book::buyBook(vector<Book*> &database, int bookID, int qtytoBuy){

	for(unsigned int i = 0; i < database.size(); i++){
		if(database[i]->getCode() == bookID){
			if(database[i]->bookQTY < qtytoBuy){
				printf("Not enough books in inventory can only buy %d books.\n", database[i]->bookQTY);
				printf("Your total comes out to be: $%d\n", (database[i]->bookQTY)*(database[i]->bookPrice));
				database[i]->bookQTY = 0;
			}else{
				database[i]->bookQTY = database[i]->getQTY() - qtytoBuy;
				printf("Your total comes out to be: $%d\n", (qtytoBuy)*(database[i]->bookPrice));
			}
			printf("The Book: %s now had %d copies in inventory\n", (database[i]->getName()).c_str(), database[i]->getQTY());
		}

	}
}


//printInventoryList() function
void Book::printInventoryList(vector<Book*> &database){
	for(unsigned int i = 0; i < database.size(); i++){
		printf("Book Code: %d~~The Book: %s by Author %s, now has %d copies in inventory at cost $%d\n",database[i]->getCode(), (database[i]->getName()).c_str(), (database[i]->getAuthor()).c_str(), database[i]->getQTY(), database[i]->getPrice());

	}
}
