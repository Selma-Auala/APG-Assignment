class book {

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
		stock = new int;
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
	friend bool check_stock(book& bk, int val) {};


	void ADD_Data();
	void Edit();
	void Show();
	int find_Book(char[], char[]);
	void purchase_Book();

};

class bookRecord
{

private:
	borrowList :
};
