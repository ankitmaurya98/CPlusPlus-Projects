/*
 * BookInventorySystem.cpp
 *
 *  Created on: Jun 14, 2021
 *      Author: ankit
 */

/*This program is a book inventory system. With this program the user can:
 * 		Search through a database to see if a book is in inventory
 * 		Checkout a book and a QTY of the book from inventory.
 * 		Add a book and QTY of that book to the inventory.
 * 		Export entire inventory as a text file.
 *
 */

//Project idea and some example code from:https: //omkarnathsingh.wordpress.com/2016/02/09/c-program-for-book-shop/

/*Explanation of Functions that are part of the Book class
 *		Constructors:
 *			Book(int code, string name, string author, int qty, int price)-Constructor with all inputs
 *			Book(int code, string name, string author)-Constructor with limited inputs
 *
 *		Member Functions:
 *			getCode() - returns the book code
 *			getName() - returns the name of the book
 *			getAuthor() - returns the author of the book
 *			getQTY() - returns the quantity of the book in inventory
 *			getPrice() - returns the price of 1 book
 *			inStock() - returns true if book is in stock or false and message if not in stock
 *			addBook() - adds a book to inventory
 *			addQuantity() - increases the quantity of the book in inventory
 *			buyBook() - when user wants to buy book
 *			printInventoryList() - makes a text file of all the books and their quantities in inventory
 */


#include "bookinventoryHeader.h" // Includes the bookinventoryHeader header file


//Menu Function that will keep running until user asks to exit
void menuFunction(vector<Book*> &inventory){

	int choice = 0;
	const int choice1 = 1;
	const int choice2 = 2;
	const int choice3 = 3;
	const int choice4 = 4;
	const int choice5 = 5;
	const int choice6 = 6;

	int runloop = 0;

	int code = 0;
	int qtyToBuy = 0;
	int addQtyStock;

	//Menu options
	while(runloop != 1){
		//Number options
		cout<<"\nMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Quantity Of Book In Inventory"
		<<"\n5. Print Inventory List"
		<<"\n6. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;

		switch(choice){
			case choice1:{
				Book newBook = inventory[0]->addBook(inventory);
				Book* book = new Book();  //pointer to a new created object
				*book = newBook;
				inventory.push_back(book);
				printf("Success! %s of Qty %d has now been added to stock.\n", (book->getName()).c_str(), book->getQTY());
				delete book;  //Using delete with the new keyword
				break;
			}
			case choice2:{
				//Asking the user
				std::cout << "Enter Book Code" << std::endl;
				cin >> code;
				std::cout << "Enter Amount You Wish to Buy" << std::endl;
				cin >> qtyToBuy;

				inventory[0]->buyBook(inventory, code, qtyToBuy);
				break;
			}
			case choice3:{
				std::cout << "Enter Book Code" << std::endl;
				cin >> code;

				inventory[0]->inStock(inventory, code);
				break;
			}
			case choice4:{
				std::cout << "Enter Book Code" << std::endl;
				cin >> code;
				std::cout << "Enter Qty Of Book Being Added to Stock" << std::endl;
				cin >> addQtyStock;

				inventory[0]->addQuantity(inventory, code, addQtyStock);
				break;
			}
			case choice5:{
				inventory[0]->printInventoryList(inventory);
				break;
			}
			case choice6:{
				runloop = 1;
				break;
			}
			default:{
				puts("Invalid Option");
				cin.ignore(100,'\n');
				break;
			}
		}

	}

}


// Main Function
int main(){


	//Creating Some Book objects
	Book book1(001, "Harry Potter", "JK Rowling", 7, 20);
	Book book2(002, "Game Of Thrones", "George RR Martin", 5, 15);
	Book book3(003, "Percy Jackson", "Rick Riordan", 5, 10);

	//The Database, Setting up a vector of pointers as you want to modify the original object, not the copy in the function
	//vector<Book*> inventory = {&book1, &book2, &book3};
	vector<Book*> inventory;

	Book* book1ptr = new Book();
	*book1ptr = book1;

	Book* book2ptr = new Book();
	*book2ptr = book2;

	Book* book3ptr = new Book();
	*book3ptr = book3;

	inventory.push_back(book1ptr);
	inventory.push_back(book2ptr);
	inventory.push_back(book3ptr);


/*
	book1.printInventoryList(inventory);

	//Checking Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//inStock() function
	book1.inStock(inventory, 001);

	//addBook() Function
	//book1.addBook(inventory);
	Book book4 = book1.addBook(inventory);
	inventory.push_back(&book4);
	printf("Author name: %s\n", (inventory[3]->getAuthor()).c_str());
	printf("%s has %d copies in inventory, CODE: %d\n", (inventory[3]->getName()).c_str(), inventory[3]->getQTY(), inventory[3]->getCode());

	//addQuantity() function
	book2.addQuantity(inventory, 002, 3);
	printf("%s Qty check: %d\n", (book2.getName()).c_str(), book2.getQTY());

	book3.addQuantity(inventory, 003, 10);
	printf("%s Qty check: %d\n", (book3.getName()).c_str(), book3.getQTY());

	book1.addQuantity(inventory, 004, 10);
	printf("%s Qty check: %d\n", (inventory[3]->getName()).c_str(), inventory[3]->getQTY());


	//buyBook() Function
	book3.buyBook(inventory, 003, 4);
	book3.buyBook(inventory, 004, 30);

	//printInventoryList()
	book1.printInventoryList(inventory);
*/

	//Testing Menu
	menuFunction(inventory);


	//Housekeeping and clearing Inventory vector once done
	for (auto &a: inventory) {
		delete a;
	}

	inventory.clear();

	puts("Program finished!");


	return 0;
}
