#include <iostream>
#include <conio.h>
#include "prefab_type.h"
#include "basic_tools.h"
#include "reader_tools.h"
#include "book_tools.h"
#include "book_borrowing.h"
#include "statistic.h"

//menu with all the reader management functions
//press 0-4 to move between the sub menus, or 8-9 to move between pages
void reader_menu
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int max_reader_amount
)
{
	int page_number = 0;
	int i = 0;
	while (list_of_readers[i].library_id[0] != 0)
	{
		i++;
	}
	int current_amount_of_reader = i;

	while (true)
	{
		int option;
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 0
		cout << "|   ~~~ Readers management ~~~   |                ~~~ Current mode : Viewing all ~~~                |" << "\n"; // line 1
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 2
		cout << "|[0]: Return to main menu        |                                                                  |" << "\n"; // line 3
		cout << "|[1]: Add reader(s)              |                                                                  |" << "\n"; // line 4
		cout << "|[2]: Adjust infomation          |                                                                  |" << "\n"; // line 5
		cout << "|[3]: Delete reader(s)           |                                                                  |" << "\n"; // line 6
		cout << "|[4]: Find reader(s)             |                                                                  |" << "\n"; // line 7
		cout << "|--------------------------------|                                                                  |" << "\n"; // line 8
		cout << "|                                |                                                                  |" << "\n"; // line 9
		cout << "|                                |                                                                  |" << "\n"; // line 10
		cout << "|                                |                                                                  |" << "\n"; // line 11
		cout << "|                                |                                                                  |" << "\n"; // line 12
		cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 13
		cout << "|[8]: Next Page    Prev Page :[9]|                                                                  |" << "\n"; // line 14
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 15
		view_list_of_reader(list_of_readers, list_of_forms_for_borrowing, page_number);
		option = int(_getch() - 48);
		while (option < 0 || option > 9)
		{
			set_cursor_position(0, 14);
			cout << "|[8]: Next Page    Prev Page :[9]|               ~~~ Error: Option doesn't exist! ~~~               |";
			option = int(_getch() - 48);
		}
		switch (option)
		{
		case 0:
			return;
		case 1:
			add_reader
			(
				list_of_readers,
				current_amount_of_reader,
				max_reader_amount
			);  break;
		case 2:
			change_reader_info
			(
				list_of_readers
			);  break;
		case 3:
			delete_reader_menu
			(
				list_of_readers,
				current_amount_of_reader
			);  break;
		case 4:
			find_reader_menu
			(
				list_of_readers,
				list_of_forms_for_borrowing
			);  break;
		case 8:
			page_number++;
			i = page_number * 4;
			if (list_of_readers[i].library_id[0] == 0)
			{
				page_number--;
			}
			break;
		case 9:
			if (page_number != 0)
			{
				page_number--;
			}
			break;
		}
	}
}

//menu with all the books management functions
//press 0-4 to move between the sub menus, or 8-9 to move between pages
void book_menu
(
	book_title list_of_books_titles[],
	int max_book_title_amount
)
{
	int page_number = 0;
	int i = 0;
	while (list_of_books_titles[i].isbn[0] != 0)
	{
		i++;
	}
	int current_amount_of_book = i;

	while (true)
	{
		int option;
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 0
		cout << "|    ~~~ Books management ~~~    |                ~~~ Current mode : Viewing all ~~~                |" << "\n"; // line 1
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 2
		cout << "|[0]: Return to main menu        |                                                                  |" << "\n"; // line 3
		cout << "|[1]: Add book(s)                |                                                                  |" << "\n"; // line 4
		cout << "|[2]: Adjust infomation          |                                                                  |" << "\n"; // line 5
		cout << "|[3]: Delete book(s)             |                                                                  |" << "\n"; // line 6
		cout << "|[4]: Find book(s)               |                                                                  |" << "\n"; // line 7
		cout << "|--------------------------------|                                                                  |" << "\n"; // line 8
		cout << "|                                |                                                                  |" << "\n"; // line 9
		cout << "|                                |                                                                  |" << "\n"; // line 10
		cout << "|                                |                                                                  |" << "\n"; // line 11
		cout << "|                                |                                                                  |" << "\n"; // line 12
		cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 13
		cout << "|[8]: Next Page    Prev Page :[9]|                                                                  |" << "\n"; // line 14
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 15
		view_list_of_books(list_of_books_titles, page_number);
		option = int(_getch() - 48);
		while (option < 0 || option > 9 || option == 5 || option == 6 || option == 7)
		{
			set_cursor_position(0, 14);
			cout << "|[8]: Next Page    Prev Page :[9]|               ~~~ Error: Option doesn't exist! ~~~               |";
			option = int(_getch() - 48);
		}
		switch (option)
		{
		case 0:
			return;
		case 1:
			add_book
			(
				list_of_books_titles,
				max_book_title_amount,
				current_amount_of_book
			);  break;
		case 2:
			change_book_info
			(
				list_of_books_titles
			);  break;
		case 3:
			delete_book_menu
			(
				list_of_books_titles,
				current_amount_of_book
			);  break;
		case 4:
			find_book_menu
			(
				list_of_books_titles
			);  break;
		case 8:
			page_number++;
			i = page_number * 5;
			if (list_of_books_titles[i].isbn[0] == 0)
			{
				page_number--;
			}
			break;
		case 9:
			if (page_number != 0)
			{
				page_number--;
			}
			break;
		}
	}
}

//menu with all the borrowing books functions
//press 0-2 to move between the sub menus, or 8-9 to move between pages
void borrow_books_menu
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[]
)
{
	int option = 0;
	int page_number = 0;
	int i = 0;
	int j = 0;
	while (list_of_forms_for_borrowing[j].form_id[0] != 0)
	{
		j++;
	}
	int current_amount_of_forms = j;

	while (true)
	{
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 0
		cout << "|                               ~~~ Borrowing and returning books ~~~                               |" << "\n"; //line 1
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 2
		cout << "|[0]: Return to main menu       |                                                                   |" << "\n"; //line 3
		cout << "|[1]: Borrow books              |                                                                   |" << "\n"; //line 4
		cout << "|[2]: Return books              |                                                                   |" << "\n"; //line 5
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 6
		cout << "|[8]: Next page   Prev Page :[9]|                                                                   |" << "\n"; //line 7
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 8
		view_all_borrowings(list_of_readers, list_of_books_titles, list_of_forms_for_borrowing, page_number);

		option = int(_getch() - 48);
		while (option != 0 && option != 1 && option != 2 && option != 8 && option != 9)
		{
			set_cursor_position(34, 7);
			cout << "               ~~~ Error: Option doesn't exist! ~~~               ";
			option = int(_getch() - 48);
		}

		switch (option)
		{
		case 0:
			return;
		case 1:
			borrow_books
			(
				list_of_readers,
				list_of_books_titles,
				list_of_forms_for_borrowing,
				current_amount_of_forms
			);
			break;
		case 2:
			return_books
			(
				list_of_readers,
				list_of_books_titles,
				list_of_forms_for_borrowing,
				current_amount_of_forms
			);
			break;
		case 8:
			page_number++;
			i = page_number * 5;
			if (list_of_forms_for_borrowing[i].form_id[0] == 0)
			{
				page_number--;
			}
			break;
		case 9:
			if (page_number != 0)
			{
				page_number--;
			}
			break;
		}
	}
}

//menu with all the statistic functions
//press 0-2 to move between the sub menus, or 8-9 to move between pages
void statistics
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[]
)
{
	while (true)
	{
		system("cls");
		int option = 0;
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|[0]: Return to main menu                 ~~~ Statistic ~~~                                         |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|[1]: Amount of books in library                  |                 Amount of reader in library :[4]|" << "\n";
		cout << "|[2]: Amount of books in library through genre    |     Amount of reader in library through sex :[5]|" << "\n";
		cout << "|[3]: Amount of books currently being borrowed    |       Amount of reader with overdue returns :[6]|" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|                                                 |                                                 |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		option = int(_getch() - 48);
		while (option < 0 || option > 6)
		{
			set_cursor_position(0, 7);
			cout << "|                                                 |       ~~~ Error: Option does't exist! ~~~       |" << "\n\n";
			option = int(_getch() - 48);
		}
		switch (option)
		{
		case 0:
			return;
		case 1:
			stats_amount_of_books
			(
				list_of_books_titles
			);
			break;
		case 2:
			stats_amount_of_books_genre
			(
				list_of_books_titles
			);
			break;
		case 3:
			stats_amount_being_borrowed
			(
				list_of_forms_for_borrowing
			);
			break;
		case 4:
			stats_amount_of_readers
			(
				list_of_readers
			);
			break;
		case 5:
			stats_amount_of_readers_sex
			(
				list_of_readers
			);
			break;
		case 6:
			stats_amount_of_readers_books_overdue
			(
				list_of_forms_for_borrowing
			);
			break;
		}
	}
}