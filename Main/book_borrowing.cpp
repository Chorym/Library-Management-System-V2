#include "std_library_used.h"
#include "prefab_type.h"
#include "basic_tools.h"
#include "reader_tools.h"
#include "book_tools.h"
#include "verify_input_tools.h"
#include "error_handing_tools.h"

using std::cout;
using std::cin;

//accepts a reader library id
//return the corresponding position in the array holding the form id with said library
int find_form
(
	borrowing_book_form list_of_forms_for_borrowing[],
	char input_library_id[],
	char input_form_id[]
)
{
	int i = 0;
	if(input_library_id != 0)
	{
		while (list_of_forms_for_borrowing[i].borrower_id[0] != 0)
		{
			if (strcmp(list_of_forms_for_borrowing[i].borrower_id, input_library_id) == 0) return i;
			i++;
		}
	}
	else
	{
		while (list_of_forms_for_borrowing[i].form_id[0] != 0)
		{
			if (strcmp(list_of_forms_for_borrowing[i].form_id, input_form_id) == 0) return i;
			i++;
		}
	}
	return -1;
}

//delete all forms data
void delete_all_forms(borrowing_book_form list_of_forms_for_borrowing[])
{
	for (int i = 0; list_of_forms_for_borrowing[i].form_id[0] != 0; i++)
	{
		strcpy_s(list_of_forms_for_borrowing[i].form_id, "");
		strcpy_s(list_of_forms_for_borrowing[i].borrower_id, "");
		strcpy_s(list_of_forms_for_borrowing[i].expected_return_date, "");
		strcpy_s(list_of_forms_for_borrowing[i].borrow_date, "");
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[0], "");
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[1], "");
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[2], "");
	}
}

//delete one form data at any position picked
void delete_one_form(borrowing_book_form list_of_forms_for_borrowing[], int position)
{
	for (int i = position; list_of_forms_for_borrowing[i].form_id[0] != 0 && list_of_forms_for_borrowing[i + 1].form_id[0] != 0 ; i++)
	{
		strcpy_s(list_of_forms_for_borrowing[i].form_id, list_of_forms_for_borrowing[i + 1].form_id);
		strcpy_s(list_of_forms_for_borrowing[i].borrower_id, list_of_forms_for_borrowing[i + 1].borrower_id);
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[0], list_of_forms_for_borrowing[i + 1].borrowed_books_isbn[0]);
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[1], list_of_forms_for_borrowing[i + 1].borrowed_books_isbn[1]);
		strcpy_s(list_of_forms_for_borrowing[i].borrowed_books_isbn[2], list_of_forms_for_borrowing[i + 1].borrowed_books_isbn[2]);
		strcpy_s(list_of_forms_for_borrowing[i].borrow_date, list_of_forms_for_borrowing[i + 1].borrow_date);
		strcpy_s(list_of_forms_for_borrowing[i].expected_return_date, list_of_forms_for_borrowing[i + 1].expected_return_date);
		position++;
	}
	strcpy_s(list_of_forms_for_borrowing[position].form_id, "");
	strcpy_s(list_of_forms_for_borrowing[position].borrower_id, "");
	strcpy_s(list_of_forms_for_borrowing[position].expected_return_date, "");
	strcpy_s(list_of_forms_for_borrowing[position].borrow_date, "");
	strcpy_s(list_of_forms_for_borrowing[position].borrowed_books_isbn[0], "");
	strcpy_s(list_of_forms_for_borrowing[position].borrowed_books_isbn[1], "");
	strcpy_s(list_of_forms_for_borrowing[position].borrowed_books_isbn[2], "");
}

//display menu
//prints every form all of its info, with each page holding 5
void view_all_borrowings
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int page_number
)
{
	if (list_of_forms_for_borrowing[0].form_id[0] == 0)
	{
		cout << "|                                                                                                   |" << "\n";
		cout << "|                                     ~~~ No borrowed books ~~~                                     |" << "\n";
		cout << "|                                                                                                   |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		return;
	}
	int i = page_number * 5;
	while (list_of_forms_for_borrowing[i].form_id[0] != 0)
	{
		display_borrow_forms(list_of_forms_for_borrowing, i);
		i++;
		if (i % 5 == 0)
		{
			break;
		}
	}
}

//user start by entering a reader library ID
//when id is found, slowly add the book ISBN that the reader want to borrow
//max amount is 3
//if the reader want to borrow less than 3, enter 0 into the input
//afterwards, enter the borrow date (current date) and an expected return date
//a form is generated with a random id, holding all of the above information
bool borrow_books
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int current_amount_of_forms
)
{
	//which reader is borrowing 
	//which book is being borrowed
	//amount in stock --;
	//if amount in stock == 0; error
	//status = [days left]

	int i = 0;
	while (list_of_books_titles[i].isbn[0] != 0)
	{
		i++;
	}
	int current_amount_of_book = i;

	const int max_input_length = 30;
	int reader_number = 0;
	int book_number = 0;
	int amount_of_different_title_to_borrow = 0;
	char input[max_input_length];
	int j = 0;

	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 0
	cout << "|                                      ~~~ Borrowing books ~~~                                      |" << "\n"; //line 1
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 2
	cout << "|Enter Reader ID:                    |Reader name:                                                  |" << "\n"; //line 3
	cout << "|                                    |                                                              |" << "\n"; //line 4
	cout << "|------------------------------------|--------------------------------------------------------------|" << "\n"; //line 5
	cout << "|How many books to borrow (1-3):     |                                                              |" << "\n"; //line 6
	cout << "|                                    |                                                              |" << "\n"; //line 7
	cout << "|                                    |                                                              |" << "\n"; //line 8
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 9
	cout << "|                                    |                                                              |" << "\n"; //line 10
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 11
	
	//get reader
	set_cursor_position(18, 3);
	cin.getline(input, max_input_length);
	reader_number = find_reader(list_of_readers, input, 0, 0);
	bool checked = false;
	while (!checked)
	{
		if (strcmp(input, "0") == 0) return false;
		if (reader_number == -1)
		{
			handle_add_form_error(0, 0);
			cin.getline(input, max_input_length);
			reader_number = find_reader(list_of_readers, input, 0, 0);
			continue;
		}
		if (find_form(list_of_forms_for_borrowing, input, 0) != -1)
		{
			handle_add_form_error(1, 0);
			cin.getline(input, max_input_length);
			reader_number = find_reader(list_of_readers, input, 0, 0);
			continue;
		}
		checked = true;
	}
	strcpy_s(list_of_forms_for_borrowing[current_amount_of_forms].borrower_id, input);
	set_cursor_position(51, 3);
	cout << list_of_readers[reader_number].surname << " " << list_of_readers[reader_number].name;

	//get book
	set_cursor_position(33, 6);
	amount_of_different_title_to_borrow = int(_getch() - 48);
	while (amount_of_different_title_to_borrow > current_amount_of_book || (amount_of_different_title_to_borrow > 3 || amount_of_different_title_to_borrow < 1))
	{
		handle_add_form_error(2, 0);
		amount_of_different_title_to_borrow = int(_getch() - 48);
	}

	for (int i = 0; i < amount_of_different_title_to_borrow; i++)
	{
		switch(i)
		{
		case 0:
			set_cursor_position(0, 6);
			cout << "|Enter Book 1 ISBN:                  |Book 1 name: " << "\n"; 
			break;
		case 1:
			set_cursor_position(0, 7);
			cout << "|Enter Book 2 ISBN:                  |Book 2 name: " << "\n"; 
			break;
		case 2:
			set_cursor_position(0, 8);
			cout << "|Enter Book 3 ISBN:                  |Book 3 name: " << "\n"; 
			break;
		}
		set_cursor_position(20, 6 + i);
		cin.getline(input, max_input_length);
		book_number = find_book(list_of_books_titles, input, 0);
		while (book_number == -1 || list_of_books_titles[book_number].amount == 0 || input[0] == 0)
		{
			if(book_number == -1)
			{
				handle_add_form_error(3, i);
				cin.getline(input, max_input_length);
				book_number = find_book(list_of_books_titles, input, 0);
			}
			else
			{
				handle_add_form_error(4, i);
				cin.getline(input, max_input_length);
				book_number = find_book(list_of_books_titles, input, 0);
			}
		}
		set_cursor_position(51, 6 + i);
		cout << list_of_books_titles[book_number].name;
		strcpy_s(list_of_forms_for_borrowing[current_amount_of_forms].borrowed_books_isbn[i], input);
		//
		int temp = convert_str_number_to_int_number(list_of_books_titles[i].amount);
		temp--;
		char temp2[5] = {};
		_itoa_s(temp, temp2, 10);
		strcpy_s(list_of_books_titles[i].amount, temp2);
	}

	while (amount_of_different_title_to_borrow < 3)
	{
		strcpy_s(list_of_forms_for_borrowing[current_amount_of_forms].borrowed_books_isbn[amount_of_different_title_to_borrow], 5, "None");
		amount_of_different_title_to_borrow++;
	}
	
	//get borrow date
	char current_date[11];
	get_system_time(current_date);
	set_cursor_position(0, 4);
	cout << "|Today: " << current_date;
	strcpy_s(list_of_forms_for_borrowing[current_amount_of_forms].borrow_date, current_date);
	int borrow_day = convert_date_to_day(current_date);

	//get expected return date
	set_cursor_position(37, 4);
	cout << "|Return date: ";
	cin.getline(input, max_input_length);
	checked = false;
	while (!checked)
	{
		if (check_date_validity(input) == false)
		{
			handle_add_form_error(6, 0);
			cin.getline(input, max_input_length);
			continue;
		}
		int return_day = convert_date_to_day(input);
		if (return_day - borrow_day <= 0 || find_distance_between_2_dates(current_date, input) > 7)
		{
			handle_add_form_error(6, 0);
			cin.getline(input, max_input_length);
			continue;
		}
		checked = true;
	}
	strcpy_s(list_of_forms_for_borrowing[current_amount_of_forms].expected_return_date, input);

	//assign forms id
	char str_generated_id[9] = "00000000";
	int generated_id;
	bool successfully_generated = false;
	while (!successfully_generated)
	{
		generated_id = rand();
		while (generated_id < 1000 || generated_id > 10000)
		{
			generated_id = rand();
		}
		generated_id += 13370000;
		j = 10000000;
		for (int i = 0; i < 8; i++)
		{
			int temp = generated_id / j;
			generated_id %= j;
			j /= 10;
			str_generated_id[i] = char(temp + 48);
		}
		j = 0;
		while (j < current_amount_of_forms + 1)
		{
			if (strcmp(list_of_forms_for_borrowing[j].form_id, str_generated_id) == 0) break;
			if (j == current_amount_of_forms)
			{
				successfully_generated = true; break;
			}
			j++;
		}
	}
	strcpy_s(list_of_forms_for_borrowing[j].form_id, 9, str_generated_id);
	set_cursor_position(0, 10);
	cout << "|                                    |                     ~~~ Form created ~~~                     |" << "\n\n"; //line 10
	cin.ignore();
	return true;
}

//user starts by entering a form id, created by borrow books function
//after form is found, enter the return date(current date)
//then every book borrowed prompts the user to input either 1 or 2
//1 means the book is still here, 2 means the reader lost the book
//if the return date is 7 days or more than the borrow date in the form, a fine is made
//total fine (if there is one) is made by adding the fine from the lost books and late return date
//fine is then returned and displayed in the reader management menu
bool return_books
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int current_amount_of_forms
)
{
	//enter form id
	//check status, if == [days left], good
	//if == overdue, no good, punished accordingly to the time overdue
	//amount in stock ++;
	bool status_opened = true;
	int fine = 0;
	int days_overdue;
	int form_number;
	int book_number;
	int book_status;
	const int max_string_length = 11;
	char input[11];

	if (list_of_forms_for_borrowing[0].form_id[0] == 0)
	{
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; 
		cout << "|                                      ~~~ Returning books ~~~                                      |" << "\n"; 
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; 
		cout << "|                                                                                                   |" << "\n"; 
		cout << "|                                 ~~~ Nobody is borrowing books ~~~                                 |" << "\n"; 
		cout << "|                                                                                                   |" << "\n"; 
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; 
		system("pause");
		return false;
	}

	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 0
	cout << "|                                      ~~~ Returning books ~~~                                      |" << "\n"; //line 1
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 2
	cout << "|[0]: Return to main menu        |Enter Form ID:                                                    |" << "\n"; //line 3
	cout << "|                                |Today :                                                           |" << "\n"; //line 4
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 5
	cout << "|                                |                                                                  |" << "\n"; //line 6
	cout << "|                                |                                                                  |" << "\n"; //line 7
	cout << "|                                |                                                                  |" << "\n"; //line 8
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 9
	cout << "|                                |                                                                  |" << "\n"; //line 10
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 11
	set_cursor_position(49, 3);  cin.getline(input, max_string_length);

	//find form 
	int i = 0;
	while (true)
	{
		if (strcmp(input, "0") == 0) return false;
		if (i == current_amount_of_forms + 1 || list_of_forms_for_borrowing[i].form_status == '0')
		{
			i = 0;
			handle_return_form_error(0);
			cin.getline(input, max_string_length);
		}
		if (strcmp(input, list_of_forms_for_borrowing[i].form_id) == 0)
		{
			set_cursor_position(34, 10); cout << "                        ~~~ Form found! ~~~                       ";
			break;
		}
		i++;
	}
	form_number = i;
	set_cursor_position(0, 12);
	display_borrow_forms(list_of_forms_for_borrowing, form_number);

	//get borrow day
	char borrow_day[11];
	strcpy_s(borrow_day, list_of_forms_for_borrowing[form_number].borrow_date);
	
	//get return day
	char current_date[11];
	get_system_time(current_date);
	set_cursor_position(42, 4);
	cout << current_date;

	//check if return if overdue
	if (find_distance_between_2_dates(current_date, borrow_day) > 7)
	{
		days_overdue = find_distance_between_2_dates(current_date, borrow_day) - 7;
		fine += 5 * days_overdue;
	}

	//book stuff
	int price_of_current_book = 0;
	for (int j = 0; j < 3; j++)
	{
		//
		book_number = find_book(list_of_books_titles, list_of_forms_for_borrowing[form_number].borrowed_books_isbn[j], 0);
		if (book_number == -1) continue;
		//
		if (list_of_forms_for_borrowing[form_number].borrowed_books_isbn[j] == 0) break;
		set_cursor_position(0, 6 + j);
		switch (j)
		{
		case 0:
			cout << "|Book 1: ";
			break;
		case 1:
			cout << "|Book 2: ";
			break;
		case 2:
			cout << "|Book 3: ";
			break;
		}
		cout << list_of_forms_for_borrowing[form_number].borrowed_books_isbn[j];
		set_cursor_position(34, 10);
		cout << "1: Normal / 2: Lost                                     ";
		set_cursor_position(33, 6 + j);
		cout << "|Book status: "; cin >> book_status;
		while (book_status != 1 && book_status != 2)
		{
			set_cursor_position(33, 6 + j);
			cout << "                                                                   ";
			set_cursor_position(33, 6 + j);
			cout << "|Book status: "; cin >> book_status;
		}
		if (book_status == 2)
		{
			status_opened = false;
			strcpy_s(list_of_forms_for_borrowing[form_number].lost_borrowed_books_isbn[book_number - 1], 2, "1");
			price_of_current_book = convert_str_number_to_int_number(list_of_books_titles[book_number].price);
			fine += 2 * price_of_current_book;
		}
		else
		{
			int temp = convert_str_number_to_int_number(list_of_books_titles[book_number].amount);
			temp++;
			char temp2[5] = {};
			_itoa_s(temp, temp2, 10);
			strcpy_s(list_of_books_titles[book_number].amount, temp2);
		}
	}
	char temp[5] = { 0 };
	_itoa_s(fine, temp, 10);
	int reader_number = find_reader(list_of_readers, list_of_forms_for_borrowing[form_number].borrower_id, 0, 0);
	strcpy_s(list_of_readers[reader_number].fine, temp);

	if (status_opened == true)
	{
		//after done, remove form
		delete_one_form(list_of_forms_for_borrowing, form_number);
	}
	else list_of_forms_for_borrowing[form_number].form_status = '0';

	cin.ignore();
	return true;
}

bool repay_fine
(
	reader list_of_readers[],
	book_title list_of_book_titles[],
	borrowing_book_form list_of_borrowing_forms[]
)
{
	char confirm_input[8];
	char input_form_id[9];
	int  form_number = 0;

	if (list_of_borrowing_forms[0].form_id[0] == 0)
	{
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|[0]: Return to menu                     ~~~ Repay fines ~~~                                        |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		cout << "|                                                                                                   |" << "\n";
		cout << "|                                 ~~~ Nobody is borrowing books ~~~                                 |" << "\n";
		cout << "|                                                                                                   |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		system("pause");
		return false;
	}

	while (true)
	{
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 0
		cout << "|[0]: Return to menu                     ~~~ Repay fines ~~~                                        |" << "\n"; //line 1
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 2
		cout << "|Enter form ID:                  |                                                                  |" << "\n"; //line 3
		cout << "|                                |                                                                  |" << "\n"; //line 4
		cout << "|                                |                                                                  |" << "\n"; //line 5
		cout << "|                                |                                                                  |" << "\n"; //line 6
		cout << "|                                |                                                                  |" << "\n"; //line 7
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 8
		cout << "|                                |                                                                  |" << "\n"; //line 9
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; //line 10
		
		set_cursor_position(16, 3); cin.getline(input_form_id, 9);
		form_number = find_form(list_of_borrowing_forms, 0, input_form_id); 

		bool checked = false;
		while (!checked)
		{
			if (strcmp(input_form_id, "0") == 0) return false;
			if (form_number == -1 || list_of_borrowing_forms[form_number].form_status == '1')
			{
				//
				set_cursor_position(35, 9);
				cout << "        ~~~ Error: Can't find form or form is opened ~~~         ";
				set_cursor_position(0, 3);
				cout << "|Enter form ID:                  ";
				set_cursor_position(16, 3);
				//
				cin.getline(input_form_id, 9);
				form_number = find_form(list_of_borrowing_forms, 0, input_form_id);
				continue;
			}
			checked = true;
		}
		set_cursor_position(35, 3);
		cout << "Lost books: \n";
		for (int i = 0; i < 3; i++)
		{
			if (list_of_borrowing_forms[form_number].borrowed_books_isbn[i] != "None" && strcmp(list_of_borrowing_forms[form_number].lost_borrowed_books_isbn[i], "0") != 0)
			{
				set_cursor_position(35, 4 + i);
				cout << list_of_borrowing_forms[form_number].borrowed_books_isbn[i] << "\n";
			}
		}

		set_cursor_position(0, 11);
		display_borrow_forms(list_of_borrowing_forms, form_number);

		set_cursor_position(34, 9);
		cout << "   Type CONFIRM to return books and remove fine: ";
		cin.getline(confirm_input, 9);
		if (strcmp(confirm_input, "CONFIRM") == 0)
		{
			//
			for (int i = 0; i < 3; i++)
			{
				if (list_of_borrowing_forms[form_number].borrowed_books_isbn[i] != "None" && strcmp(list_of_borrowing_forms[form_number].lost_borrowed_books_isbn[i], "0") != 0)
				{
					int book_number = find_book(list_of_book_titles, list_of_borrowing_forms[form_number].borrowed_books_isbn[i], 0);
					int current_book_amount = convert_str_number_to_int_number(list_of_book_titles[book_number].amount);
					current_book_amount++;
					char temp[4] = {};
					_itoa_s(current_book_amount, temp, 10);
					strcpy_s(list_of_book_titles[book_number].amount, 4, temp);
				}
			}
			int reader_number = find_reader(list_of_readers, list_of_borrowing_forms[form_number].borrower_id, 0, 0);
			strcpy_s(list_of_readers[reader_number].fine, "0");
			//

			//
			delete_one_form(list_of_borrowing_forms, form_number);
			//

			
			set_cursor_position(34, 9);
			cout << "                    ~~~ Return successfull ~~~            ";
			cin.ignore();
			return true;
		}
		else
		{
			set_cursor_position(34, 9);
			cout << "                      ~~~ Return failed! ~~~            ";
			cin.ignore();
			return false;
		}
	}
}



