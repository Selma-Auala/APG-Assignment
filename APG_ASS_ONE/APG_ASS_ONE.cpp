#include <iostream>

#include <string.h>

#include <stdlib.h>

#include "Book.cpp"

using namespace std;

//Check Number Before Entering

double check_number(string str)
{

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return -1;

    stringstream geek(str);
    double num;

    geek >> num;

    return num;
}

double check_number(string str) {

	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return -1;

	stringstream geek(str);
	double num;

	geek >> num;

	return num;
}

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

	cout << "Enter Stock Position: ";   cin >> *stock;

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
	cin >> *stock;


}

void book::Show() {
	cout << "\nAuthor Name: " << author;
	cout << "\nTitle Name: " << title;
	cout << "\nPublisher Name: " << publisher;
	cout << "\nPrice: " << price;
	cout << "\nStock Position: " << *stock;

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
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: Rs. " << (price)*count;
	}
	else
		cout << "\nRequired Copies not in Stock";
}

int main()
{
}
