#include<iostream>

#include<string.h>

#include<stdlib.h>

#include <sstream>

#include "Book.cpp"


using namespace std;

double check_number(string str) {

	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return -1;

	stringstream geek(str);
	double num;

	geek >> num;

	return num;
}

bool check_stock(book& bk, int val) {
	if (bk.stock >= val)
	{
		return true;
	}
	else {
		return false;
	};

};

void book::ADD_Data() {
	cin.ignore();
	cout << "\nEnter Author Name: ";
	cin.getline(author, 20);

	cout << "Enter Title Name: ";
	cin.getline(title, 20);

	cout << "Enter Publisher Name: ";
	cin.getline(publisher, 20);

	cout << "Enter Price: ";
	cin.getline(nextLine, 20);

	price = check_number(nextLine);

	cout << "Enter Stock Position: ";   cin >> stock;

}

void book::Edit() {

	cout << "\nAuthor Name: ";
	cin.getline(author, 20);

	cout << "Title Name: ";
	cin.getline(title, 20);

	cout << "Publisher Name: ";
	cin.getline(publisher, 20);

	cout << "Price: ";
	cin.getline(nextLine, 20);
	price = check_number(nextLine);

	cout << "Stock Position: ";
	cin >> stock;


}

void book::Show() {
	cout << "\nAuthor Name: " << author;
	cout << "\nTitle Name: " << title;
	cout << "\nPublisher Name: " << publisher;
	cout << "\nPrice: " << price;
	cout << "\nStock Position: " << stock;

}

int book::find_Book(char byTitle[20], char byAuthor[20]) {

	if (strcmp(byTitle, title) == 0 && strcmp(byAuthor, author) == 0)
		return 1;
	else return 0;

}

void book::purchase_Book() {
	int count;
	cout << "\nEnter Number Of Books to buy: ";
	cin >> count;
	if (count <= stock) {
		stock = stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: Rs. " << (price)*count;
	}
	else
		cout << "\nRequired Copies not in Stock";
}

int main() {
	book* B[20];
	int i = 0;
	int r;
	int t;
	int choice;

	char B_Title[20], B_Author[20];
	while (1) {
		cout << "\n***************************************************************************" << endl;
		cout << "*\t\t\t\t\tMENU\t\t\t\t  *" << endl;
		cout << "***************************************************************************" << endl;
		cout << ""
			<< "\n\t\t1. Entry of New Book"
			<< "\n\t\t2. Buy Book"
			<< "\n\t\t3. find_Book For Book"
			<< "\n\t\t4. Edit Details Of Book"
			<< "\n\t\t5. Exit"
			<< "\n\nEnter your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			B[i] = new book;
			B[i]->ADD_Data();
			i++;	break;

		case 2: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(B_Title, 20);
			cout << "Enter Author Of Book: ";  cin.getline(B_Author, 20);
			for (t = 0;t < i;t++) {
				if (B[t]->find_Book(B_Title, B_Author)) {
					B[t]->purchase_Book();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis Book is Not in Stock";

			break;
		case 3: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(B_Title, 20);
			cout << "Enter Author Of Book: ";  cin.getline(B_Author, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->find_Book(B_Title, B_Author)) {
					cout << "\nBook Found Successfully";
					B[t]->Show();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 4: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(B_Title, 20);
			cout << "Enter Author Of Book: ";  cin.getline(B_Author, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->find_Book(B_Title, B_Author)) {
					cout << "\nBook Found Successfully";
					B[t]->Edit();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 5: exit(0);

		default:
			cout << "\nInvalid Choice Entered";
			cin;
			break;

		}
	}




	return 0;
}