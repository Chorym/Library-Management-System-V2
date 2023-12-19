#include "std_library_used.h"
#include "basic_tools.h"
#include "error_handing_tools.h"
#include "verify_input_tools.h"

using std::cout;
using std::cin;

//accepts a name, or ISBN
//return the corresponding position in the array which contains that information
//only one may be accepted at one time, the rest will be entered as 0
int find_book
(
	book_title list_of_books_titles[],
	char input_isbn[], 
	char input_name[]
)
{
	int i = 0;
	if (input_isbn[0] != 0)
	{
		while (list_of_books_titles[i].isbn != 0)
		{
			if (strcmp(input_isbn, list_of_books_titles[i].isbn) == 0)
			{
				return i;
			}
			i++;
		}
	}
	else
	{
		while (input_name[0] != 0)
		{
			if (strcmp(input_name, list_of_books_titles[i].name) == 0)
			{
				return i;
			}
			i++;
		}
	}
	return -1;
}

//display menu
//prints every book with all of their info, with each page holding 4
void view_list_of_books
(
	book_title list_of_books_titles[],
	int page_number
)
{
	if (list_of_books_titles[0].isbn[0] == 0)
	{
		cout << "|                                                                                                   |" << "\n";
		cout << "|                                       ~~~ Library empty ~~~                                       |" << "\n";
		cout << "|                                                                                                   |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		return;
	}
	int i = page_number * 5;
	while (list_of_books_titles[i].isbn[0] != 0)
	{
		display_book_info(list_of_books_titles, i);
		i++;
		if (i % 5 == 0)
		{
			break;
		}
	}
}

//add n number of books, the number is chosen by the user
//slowly add every infomation, with input check to verify that it is valid
//if there is no more space, simply return to display menu
bool add_book
(
	book_title list_of_books_titles[],
	int max_amount_of_books,
	int current_amount_of_books
)
{
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|    ~~~ Books management ~~~    |                  ~~~ Current mode : Adding ~~~                   |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";


	if (current_amount_of_books == max_amount_of_books)
	{
		set_cursor_position(0, 14);
		cout << "|                                |                   ~~~  Error: Library full ~~~                   |" << "\n";
		system("pause");
		return false;
	}

	const int max_input_length = 50;
	char input[max_input_length];
	int  amount_of_new_books = 0;
	bool valid_info = true;
	bool checked = false;

	cout << "|[0]: Return to main menu        |ISBN:                                                             |" << "\n"; 
	cout << "|                                |Name:                                                             |" << "\n"; 
	cout << "|                                |Genre:                                                            |" << "\n";
	cout << "|                                |Price:                                                            |" << "\n";
	cout << "|                                |Author(s):                                                        |" << "\n"; 
	cout << "|--------------------------------|Publisher:                                                        |" << "\n";
	cout << "                                 |Publish year:                                                     |" << "\r|Current amount of books: " << current_amount_of_books << "\n"; 
	cout << "                                 |Amount in stock:                                                  |" << "\r|Library capcity: " << max_amount_of_books << "\n"; 
	cout << "|Amount of books to add:         |                                                                  |" << "\n"; 
	cout << "|Current count:                  |                                                                  |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                                |                                                                  |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	set_cursor_position(25, 11); cin >> amount_of_new_books;
	if (amount_of_new_books < 1) return false;
	while (amount_of_new_books > max_amount_of_books - current_amount_of_books)
	{
		set_cursor_position(0, 14);
		cout << "|                                |            ~~~  Error: Exceeding library capacity ~~~            |" << "\n";
		set_cursor_position(0, 11);
		cout << "|Amount of books to add:         ";
		set_cursor_position(25, 11); 
		cin >> amount_of_new_books;
	}

	for (int i = current_amount_of_books; i < current_amount_of_books + amount_of_new_books; i++)
	{
		set_cursor_position(0, 3);
		cout << "|[0]: Return to main menu        |ISBN:                                                             |" << "\n"; 
		cout << "|                                |Name:                                                             |" << "\n"; 
		cout << "|                                |Genre:                                                            |" << "\n"; 
		cout << "|                                |Price:                                                            |" << "\n"; 
		cout << "|                                |Author(s):                                                        |" << "\n"; 
		cout << "|--------------------------------|Publisher:                                                        |" << "\n";
		cout << "                                 |Publish year:                                                     |" << "\r|Current amount of books: " << current_amount_of_books << "\n"; 
		cout << "                                 |Amount in stock:                                                  |" << "\r|Library capcity: " << max_amount_of_books << "\n";
		cout << "                                 |                                                                  |" << "\r|Amount of books to add: " << amount_of_new_books << "\n"; 
		cout << "                " << i - current_amount_of_books + 1 << "\r|Current count: " << "\n"; 

		//add isbn
		set_cursor_position(0, 3);
		cout << "|[0]: Return to main menu        |ISBN: "; cin.ignore(); cin.getline(input, max_input_length);
		while (check_ISBN_validity(input, list_of_books_titles) == false)
		{
			handle_add_book_error(0);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_books_titles[i].isbn , input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 4);

		//add name
		cout << "|                                |Name: "; cin.getline(input, max_input_length);
		strcpy_s(list_of_books_titles[i].name, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 5);

		//add genre
		cout << "|                                |Genre: "; cin.getline(input, max_input_length);
		while (check_if_input_is_pure_text(input) == false)
		{
			handle_add_book_error(1);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_books_titles[i].genre, input);
		set_cursor_position(0, 14);
		cout << "|                                | 0 < price <= 999                                                 |" << "\n";
		set_cursor_position(0, 6);

		//add price
		cout << "|                                |Price: "; cin.getline(input, max_input_length);
		checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(input) == false)
			{
				handle_add_book_error(2);
				cin.getline(input, max_input_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(input), 1, 999) == false)
			{
				handle_add_book_error(2);
				cin.getline(input, max_input_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[i].price, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 7);

		//add author
		cout << "|                                |Author(s): "; cin.getline(input, max_input_length);
		while (check_if_no_special_characters(input) == false)
		{
			handle_add_book_error(3);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_books_titles[i].author, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 8);

		//add publisher
		cout << "|--------------------------------|Publisher: "; cin.getline(input, max_input_length);
		strcpy_s(list_of_books_titles[i].publisher, input);
		set_cursor_position(0, 14);
		cout << "|                                | 1900 <= year <= 2023                                             |" << "\n";
		set_cursor_position(0, 9);

		//add publish year
		cout << "                                 |Publish year:                                                     |" << "\r|Current amount of books: " << current_amount_of_books;
		cout << "\n\n\n\n" << "|--------------------------------|--------------\x1b[4A"; cin.getline(input, max_input_length);
		checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(input) == false)
			{
				handle_add_book_error(5);
				cin.getline(input, max_input_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(input), 1900, 2023) == false)
			{
				handle_add_book_error(5);
				cin.getline(input, max_input_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[i].publish_year, input);
		set_cursor_position(0, 14);
		cout << "|                                | 0 < amount <= 999                                                |" << "\n";
		set_cursor_position(0, 10);

		//add amount in stock
		cout << "                                 |Amount in stock:                                                  |" << "\r|Library capcity: " << max_amount_of_books;
		cout << "\n\n\n" << "|--------------------------------|-----------------\x1b[3A"; cin.getline(input, max_input_length);
		bool checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(input) == false)
			{
				handle_add_book_error(6);
				cin.getline(input, max_input_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(input), 1, 999) == false)
			{
				handle_add_book_error(6);
				cin.getline(input, max_input_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[i].amount, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 11);
	}
	set_cursor_position(0, 14);
	cout << "|                                |       ~~~  Adding complete! Press any key to continue. ~~~       |" << "\n";
	cin.ignore();
	return true;
}

//change a book information
//user choose a book by entering its ISBN code
//then pick a certain piece of info to change
//enter the new info, the input is checked just as it is checked in add book menu
bool change_book_info
(
	book_title list_of_books_titles[]
)
{
	int i = 0;
	bool checked = false;
	const int max_string_length = 50;
	char new_info[max_string_length];
	char finding_data[max_string_length];
	int  book_number = 0;
	int  finding_option = 0;
	int  fixing_option = 0;

	set_cursor_position(0, 0);
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 0
	cout << "|    ~~~ Books management ~~~    |                  ~~~ Current mode : Fixing ~~~                   |" << "\n"; // line 1
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 2
	cout << "|[0]: Return to menu             |                                                                  |" << "\n"; // line 3
	cout << "|                                |                                                                  |" << "\n"; // line 4
	cout << "|                                |                                                                  |" << "\n"; // line 5
	cout << "|                                |                                                                  |" << "\n"; // line 6
	cout << "|                                |                                                                  |" << "\n"; // line 7
	cout << "|--------------------------------|                                                                  |" << "\n"; // line 8
	cout << "|Find book to fix with:          |                                                                  |" << "\n"; // line 9
	cout << "|                                |                                                                  |" << "\n"; // line 10
	cout << "|                                |                                                                  |" << "\n"; // line 11
	cout << "|                                |                                                                  |" << "\n"; // line 12
	cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 13
	cout << "|[1]: ISBN                       |                                                                  |" << "\n"; // line 14
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 15
	set_cursor_position(24, 9); finding_option = int(_getch() - 48); 

	while (finding_option < 0 || finding_option > 1)
	{
		handle_fix_book_error(10);
		finding_option = int(_getch() - 48);
	}

	if (finding_option == 0)
	{
		return false;
	}
	else if (finding_option == 1)
	{
		cout << "\r|Find book to fix with: ISBN" << "\n";
		cout << "|ISBN: "; cin.getline(finding_data, max_string_length);
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |                        ~~~ Book found ~~~                        |" << "\n";
		book_number = find_book(list_of_books_titles, finding_data, 0);
		while (book_number == -1)
		{
			handle_fix_book_error(11);
			cin.getline(finding_data, max_string_length);
			book_number = find_book(list_of_books_titles, finding_data, 0);
		}
	}
	

	set_cursor_position(0, 3);
	cout << "|[0]: Return to menu             |[1]: ISBN   [4]: Price            [7]: Publisher                  |" << "\n"; 
	cout << "|                                |[2]: Name   [5]: Author           [8]: Publish year               |" << "\n"; 
	cout << "|                                |[3]: Genre  [6]: Amount in stock                                  |" << "\n"; 
	cout << "|                                |------------------------------------------------------------------|" << "\n"; 
	set_cursor_position(0, 10);
	cout << "|What to fix:                   ";
	cout << "\r|What to fix: ";
	fixing_option = int(_getch() - 48);

	while (fixing_option < 1 || fixing_option > 8)
	{
		handle_fix_book_error(11);
		fixing_option = int(_getch() - 48);
	}

	cout << fixing_option;
	switch (fixing_option)
	{
	case 1:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].isbn << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_ISBN_validity(new_info, list_of_books_titles) == false)
		{
			handle_fix_book_error(fixing_option); 
			cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_books_titles[book_number].isbn, new_info);
		break;
	}
	case 2:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].name << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		strcpy_s(list_of_books_titles[book_number].name, new_info);
		break;
	}
	case 3:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].genre << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_if_input_is_pure_text(new_info) == false)
		{
			handle_fix_book_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_books_titles[book_number].genre, new_info);
		break;
	}
	case 4:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 0 < price <= 999                                                 |" << "\n";
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].price << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(new_info) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(new_info), 1, 999) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[book_number].price, new_info);
		break;
	}
	case 5:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].author << "\n";
		cout << "|--------------------------------|New info : " ; cin.getline(new_info, max_string_length);
		while (check_if_no_special_characters(new_info) == false)
		{
			handle_fix_book_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_books_titles[book_number].author, new_info);
		break;
	}
	case 6:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 0 < amount <= 999                                                |" << "\n";
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].amount << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(new_info) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(new_info), 1, 999) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[book_number].amount, new_info);
		break;
	}
	case 7:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].publisher << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		strcpy_s(list_of_books_titles[book_number].publisher, new_info);
		break;
	}
	case 8:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 1900 <= year <= 2023                                              |" << "\n";
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_books_titles[book_number].publish_year << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		checked = false;
		while (!checked)
		{
			if (check_if_input_is_pure_number(new_info) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			if (check_within_range(convert_str_number_to_int_number(new_info), 1900, 2023) == false)
			{
				handle_fix_book_error(fixing_option);
				cin.getline(new_info, max_string_length);
				continue;
			}
			checked = true;
		}
		strcpy_s(list_of_books_titles[book_number].publish_year, new_info);
		break;
	}
	}
	set_cursor_position(0, 14);
	cout << "|[1]: ISBN                       |             ~~~ Information changed successfully ~~~             |";
	cin.ignore();
	return true;
}

//remove everything from a or ALL book
//user choose which option to delete, 1 or all
//if choose 1, enter book ISBN to delete
//if choose all, type confirm to delete all
bool delete_book_menu
(
	book_title list_of_books_titles[],
	int  current_amount_of_books
)
{
	char input_isbn[14];
	int  delete_option = 0;
	int  i = 0;

	cout << "\x1b[H";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 0
	cout << "|    ~~~ Books management ~~~    |                  ~~~ Current mode : Deleting ~~~                 |" << "\n"; // line 1
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 2
	cout << "|[0]: Return to menu             |                                                                  |" << "\n"; // line 3
	cout << "|[1]: Delete 1                   |                                                                  |" << "\n"; // line 4
	cout << "|[2]: Delete ALL                 |                                                                  |" << "\n"; // line 5
	cout << "|                                |                                                                  |" << "\n"; // line 6
	cout << "|                                |                                                                  |" << "\n"; // line 7
	cout << "|--------------------------------|                                                                  |" << "\n"; // line 8
	cout << "|Delete option :                 |                                                                  |" << "\n"; // line 9
	cout << "|Enter ISBN :                    |                                                                  |" << "\n"; // line 10
	cout << "|                                |                                                                  |" << "\n"; // line 11
	cout << "|                                |                                                                  |" << "\n"; // line 12
	cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 13
	cout << "|                                |                                                                  |" << "\n"; // line 14
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 15
	set_cursor_position(16, 9); delete_option = int(_getch() - 48); cout << "\n";
	while (delete_option < 0 || delete_option > 2)
	{
		set_cursor_position(0, 9);
		cout << "|Delete option : ";
		delete_option = int(_getch() - 48); cout << "\n";
	}

	switch (delete_option)
	{
	case 0:
		return false;
	case 1:
	{
		set_cursor_position(0, 9);
		cout << "|Delete option : Delete 1" << "\n";
		cout << "\r|Enter ISBN : "; cin.getline(input_isbn, 9);
		i = find_book(list_of_books_titles, input_isbn, 0);
		while (i == -1)
		{
			set_cursor_position(34, 14);
			cout << "             ~~~ Error: Book doesn't exist in lib ~~~             ";
			set_cursor_position(0, 10);
			cout << "|                                ";
			cout << "\r|Enter ISBN : "; cin.getline(input_isbn, 30);
			i = find_book(list_of_books_titles, input_isbn, 0);
		}
		while (true)
		{
			if (i == current_amount_of_books)
			{
				strcpy_s(list_of_books_titles[i].isbn, "");
				strcpy_s(list_of_books_titles[i].name, "");
				strcpy_s(list_of_books_titles[i].author, "");
				strcpy_s(list_of_books_titles[i].genre, "");
				strcpy_s(list_of_books_titles[i].price, "");
				strcpy_s(list_of_books_titles[i].amount, "");
				strcpy_s(list_of_books_titles[i].publisher, "");
				strcpy_s(list_of_books_titles[i].publish_year, "");
				cout << "\n\n\n";
				cout << "|                                |                         ~~~ Deleted! ~~~                         |";
				cin.ignore();
				return true;
			}
			strcpy_s(list_of_books_titles[i].isbn, list_of_books_titles[i + 1].isbn);
			strcpy_s(list_of_books_titles[i].name, list_of_books_titles[i + 1].name);
			strcpy_s(list_of_books_titles[i].author, list_of_books_titles[i + 1].author);
			strcpy_s(list_of_books_titles[i].genre, list_of_books_titles[i + 1].genre);
			strcpy_s(list_of_books_titles[i].price, list_of_books_titles[i + 1].price);
			strcpy_s(list_of_books_titles[i].amount, list_of_books_titles[i + 1].amount);
			strcpy_s(list_of_books_titles[i].publisher, list_of_books_titles[i + 1].publisher);
			strcpy_s(list_of_books_titles[i].publish_year, list_of_books_titles[i + 1].publish_year);
			i++;
		}
	}
	case 2:
	{
		set_cursor_position(0, 9);
		cout << "|Delete option : ALL" << "\n";
		char input[8];
		set_cursor_position(0, 14);
		cout << "|                                |                  Type CONFIRM to delete: "; cin.getline(input, 8);
		if (strcmp(input, "CONFIRM") == 0)
		{
			for (int i = 0; i < current_amount_of_books; i++)
			{
				strcpy_s(list_of_books_titles[i].isbn, "");
				strcpy_s(list_of_books_titles[i].name, "");
				strcpy_s(list_of_books_titles[i].author, "");
				strcpy_s(list_of_books_titles[i].genre, "");
				strcpy_s(list_of_books_titles[i].price, "");
				strcpy_s(list_of_books_titles[i].amount, "");
				strcpy_s(list_of_books_titles[i].publisher, "");
				strcpy_s(list_of_books_titles[i].publish_year, "");
			}
			cout << "\r|                                |                       ~~~ Deleted all! ~~~                       |";
			cin.ignore();
			return true;
		}
		else
		{
			cout << "\r|                                |                   ~~~ Deleting all failed! ~~~                   |";
			cin.ignore();
			return false;
		}
	}
	}
	return false;
}

//display 1 book, found using the find book function
//can be found by using either name or ISBN
//input must be exact or book can not be found
void find_book_menu
(
	book_title list_of_books_titles[]
)
{
	int  finding_option = 0;
	int  book_number = 0;
	char input[30];

	while (true)
	{
		if (book_number == 0) system("cls"); //only reset at first entry
		else set_cursor_position(0, 0);
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 1
		cout << "|   ~~~ Readers management ~~~   |                 ~~~ Current mode : Viewing one ~~~               |" << "\n"; // line 2
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 3
		cout << "|[0]: Return to menu             |                                                                  |" << "\n"; // line 4
		cout << "|                                |                                                                  |" << "\n"; // line 5
		cout << "|                                |                                                                  |" << "\n"; // line 6
		cout << "|                                |                                                                  |" << "\n"; // line 7
		cout << "|                                |                                                                  |" << "\n"; // line 8
		cout << "|--------------------------------|                                                                  |" << "\n"; // line 9
		cout << "|Find with:                      |                                                                  |" << "\n"; // line 10
		cout << "|[1]: ISBN                       |                                                                  |" << "\n"; // line 11
		cout << "|[2]: Name                       |                                                                  |" << "\n"; // line 12
		cout << "|                                |                                                                  |" << "\n"; // line 13
		cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 14
		cout << "|                                |                                                                  |" << "\n"; // line 15
		cout << "|---------------------------------------------------------------------------------------------------|"; // line 16
		set_cursor_position(12, 9); finding_option = int(_getch() - 48);

		while (finding_option < 0 || finding_option > 2)
		{
			handle_find_book_error(0);
			finding_option = int(_getch() - 48);
		}

		switch (finding_option)
		{
		case 0:
			return;
		case 1:
			cout << "ISBN" << "\n";
			cout << "|                               " << "\n" << "|                               " << "\n" << "|                               " << "\n";
			set_cursor_position(0, 10);
			cout << "|ISBN: ";
			cin.getline(input, 30);
			book_number = find_book(list_of_books_titles, input, 0);
			while (book_number == -1)
			{
				handle_find_book_error(1);
				cin.getline(input, 30);
				book_number = find_book(list_of_books_titles, input, 0);
			}
			set_cursor_position(0, 16);
			display_book_info(list_of_books_titles, book_number);
			set_cursor_position(34, 14);
			cout << "                        ~~~ Book found ~~~                        " << "\n\n"; cin.ignore();
			break;
		case 2:
			cout << "Name" << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			set_cursor_position(0, 10);
			cout << "|Name: ";
			cin.getline(input, 30);
			book_number = find_book(list_of_books_titles, 0, input);
			while (book_number == -1)
			{
				handle_find_book_error(2);
				cin.getline(input, 30);
				book_number = find_book(list_of_books_titles, 0, input);
			}
			set_cursor_position(0, 16);
			display_book_info(list_of_books_titles, book_number);
			set_cursor_position(34, 14);
			cout << "                        ~~~ Book found ~~~                        " << "\n\n"; cin.ignore();
			break;
		}

	}
}