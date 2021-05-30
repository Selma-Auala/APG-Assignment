class book {
private:
	char* author, * title, * publisher;
	float* price;
	int* stock;
public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}
	void ADD_Data();
	void Edit();
	void Show();
	int find_Book(char[], char[]);
	void purchase_Book();

};