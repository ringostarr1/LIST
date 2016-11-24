#include <conio.h>
#include "List.h"
//#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	Collection q;//список 1

	int amount_of_element = 0;
	cout << "Please, enter the amount of elements of list:  ";
	cin >> amount_of_element;
	int variable = 0;

	for (int i = 0; i < amount_of_element; i++)
	{
		cin >> variable;
		q.add(variable);
	}

	char choice = '1';
	cout << "1)  Search index of element\n";
	cout << "2)  Insert an element at position\n";
	cout << "3)  Remove the element at position\n";
	cout << "4)  Output on display\n";
	cout << "5)  Exit\n";

	while (choice != '5')
	{
		cout << "Choice:  ";
		cin >> choice;
		switch (choice)
		{
		case '1':{
					 int quest = 0;
					 cout << "Please, enter queast:  ";
					 cin >> quest;
					 if (q.search_index(quest) == -1) cout << "Element have not found";
					 else   cout << "Index quest is " << q.search_index(quest) << endl;
					 break;
		}
		case '2':{
					 int number_insert = 0;
					 int index_insert = 0;

					 cout << "Please, enter number_insert and index_insert:  ";
					 cin >> number_insert >> index_insert;
					 q.add_push(number_insert, index_insert);
					 break;
		}
		case '3':{
					 int index_delete = 0;
					 cout << "Please, enter index_delete:  ";
					 cin >> index_delete;
					 q.remove_push(index_delete);
					 break;
		}
		case '4':
		{
					q.print(); 
					cout << endl;
					break;
		}
		default:cout << "Wrong input\n";
		}
	}



	_getch();
	return 0;
}