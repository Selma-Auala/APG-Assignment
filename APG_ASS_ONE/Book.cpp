#include<iostream>

using namespace std;

class book {
public:
	char* author, * title, * publisher;
	double price;
	int stock;
	char* nextLine;

public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = 0;
		stock = 0;
		nextLine = new char[20];
	}

	//Copy Constructor
	book(const book& old_Book) {
		author = old_Book.author;
		title = old_Book.title;
		publisher = old_Book.publisher;
		price = old_Book.price;
		stock = old_Book.stock;
		nextLine = old_Book.nextLine;

	}
	//friend class
	friend class bookRecord;


	//friend function
	friend bool check_stock(book& bk, int val);


	void ADD_Data();
	void Edit();
	void Show();
	int find_Book(char[], char[]);
	void purchase_Book();
	void read();

};



class borrowed : book
{

private:
	bool available;
	char* loaner;

public:
	friend char* borrow(char* name, char* address, string date);
};

//Function for loaning a book
template <typename borrowedBook>

borrowedBook loanBook(book libBook, char* name, char* address, string date, borrowed loner) {
	loner = libBook;

	borrowedBook borrowedBook = loner.borrow(name, address, date);

	return borrowedBook;
}