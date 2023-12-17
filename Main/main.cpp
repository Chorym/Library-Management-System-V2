#include <iostream>
#include <conio.h>
#include "load_save_tools.h"
#include "prefab_type.h"
#include "menus.h"
#include "basic_tools.h"

using std::cout;

//contains main menu and arrays holding all the information
//press 0-4 to move between the menus
int main()
{ 
	const int max_reader_amount = 20;
	const int max_book_title_amount = 20;
	const int max_forms_amount = 50;
	
	reader list_of_readers[max_reader_amount] = {};
	book_title list_of_books_titles[max_book_title_amount] = {};
	borrowing_book_form list_of_forms_for_borrowing[max_forms_amount] = {};

	char reader_file[19];
	char book_file[17];
	char borrow_form_file[24];

	choose_save_slot(reader_file, book_file, borrow_form_file);
	load_all_readers(reader_file, list_of_readers);
	load_all_books(book_file, list_of_books_titles);
	//load_all_borrow_forms();
	
	while (true)
	{
		system("cls");
		int option = 0;
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|                                         ~~~ Main menu ~~~                                         |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|[0]: Exit program                                |                                 Borrow book :[3]|" << "\n";
		cout << "|[1]: Reader Management                           |                     View certain statistics :[4]|" << "\n";
		cout << "|[2]: Book Management                             |                                                 |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|      ~~~ Press 0-4 to go to each menu ~~~       |                                                 |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		option = int(_getch() - 48);
		while (option < 0 || option > 4)
		{
			set_cursor_position(0, 7);
			cout << "|      ~~~ Press 0-4 to go to each menu ~~~       |       ~~~ Error: Option does't exist! ~~~       |" << "\n\n";
			option = int(_getch() - 48);
		}
		switch (option)
		{
		case 0:
			if(save_all_readers(reader_file, list_of_readers) == false || save_all_books(book_file, list_of_books_titles) == false)
			{
				cout << "save failed, continuing program...";
				std::cin.ignore();
				break;
			}
			return 0;
		case 1:
			reader_menu
			(
				list_of_readers,
				list_of_forms_for_borrowing,
				max_reader_amount
			);
			break;
		case 2:
			book_menu
			(
				list_of_books_titles,
				max_book_title_amount
			);
			break;
		case 3:
			borrow_books_menu
			(
				list_of_readers,
				list_of_books_titles,
				list_of_forms_for_borrowing
			);
			break;
		case 4:
			statistics
			(
				list_of_readers,
				list_of_books_titles,
				list_of_forms_for_borrowing
			);
			break;

		}
	}
}
