#include <iostream>
#include <iomanip>
#include "basic_tools.h"
#include "verify_input_tools.h"

using namespace std;

//prints every book title with its amount in stock
//prints a total amount of books in stock
void stats_amount_of_books
(
	book_title list_of_books_titles[]
)
{
	int i = 0;
	int sum = 0;
	int sum_title = 0;
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                                 ~~~ Amount of books in library ~~~                                |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|          -- ISBN --          |                 -- Name --                  |     -- Amount --     |" << "\n";
;	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	while (list_of_books_titles[i].isbn[0] != 0)
	{
		cout << setw(101) << "|";
		cout << "\r" << setw(90) << list_of_books_titles[i].amount;
		cout << "\r" << setw(78) << "|";
		cout << "\r                               |             " << list_of_books_titles[i].name;
		cout <<	"\r|        " << list_of_books_titles[i].isbn << "\n";
		sum += convert_str_number_to_int_number(list_of_books_titles[i].amount);
		sum_title++;
		i++;
	}
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << setw(101) << "|";
	cout << "\r" << setw(90) << "|          Total amount of book title: " << sum_title;
	cout << "\r|       Total amount of current books: " << sum << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	system("pause");
}

//print every title in a genre section with their amount in stock
//the genre is printed with the total amount of books in stock of that genre
void stats_amount_of_books_genre
(
	book_title list_of_books_titles[]
)
{
	char current_genre[20];
	char printed_genre[20][20] = {};
	int current_sum = 0;
	int current_title_sum = 0;
	int i = 0;
	int j = 0;
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                            ~~~ Amount of books by genre in library ~~~                            |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|      -- ISBN --      |            -- Name --           |        -- Genre --        | -- Amount -- |" << "\n";
	;	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	while (list_of_books_titles[j].genre[0] != 0)
	{
		strcpy_s(current_genre, list_of_books_titles[j].genre);
		int k = 0;
		while(printed_genre[k][0] != 0)
		{
			if(strcmp(current_genre, printed_genre[k]) == 0)
			{
				j++;
				strcpy_s(current_genre, list_of_books_titles[j].genre);
				k = -1;
			}
			k++;
		}
		strcpy_s(current_genre, list_of_books_titles[j].genre);
		strcpy_s(printed_genre[j], current_genre);
		i = 0;
		current_sum = 0;
		current_title_sum = 0;
		while (list_of_books_titles[i].genre[0] != 0)
		{
			if(strcmp(current_genre, list_of_books_titles[i].genre) == 0)
			{
				cout << setw(101) << "|";
				cout << "\r" << setw(94) << list_of_books_titles[i].amount;
				cout << "\r" << setw(86) << "|";
				cout << "\r" << setw(80) << list_of_books_titles[i].genre;
				cout << "\r" << setw(58) << "|";
				cout << "\r" << setw(50) << list_of_books_titles[i].name;
				cout << "\r" << setw(24) << "|";
				cout << "\r|     " << list_of_books_titles[i].isbn << "\n";
				current_sum += convert_str_number_to_int_number(list_of_books_titles[i].amount);
				current_title_sum++;
			}
			i++;
		}
		j++;
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		if(list_of_books_titles[j].genre[0] != 0)
		{
			cout << setw(101) << "|";
			cout << "\r" << setw(97) << "|  Total amount of book title by genre: " << current_title_sum;
			cout << "\r|     Total amount of books by genre: " << current_sum << "\n";
			cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		}
	}
	cout << "\x1b[1A                                                                                                     \r";
	system("pause");
}

//print the number of how many book are being borrowed 
void stats_amount_being_borrowed
(
	borrowing_book_form list_of_forms_for_borrowing[]
)
{
	int sum = 0;
	int amount_being_borrowed = 0;
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                         ~~~ Amount of books currently being borrowed ~~~                          |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	
	int i = 0, j = 0;
	while (list_of_forms_for_borrowing[i].borrowed_books_isbn[0][0] != 0)
	{
		while (list_of_forms_for_borrowing[i].borrowed_books_isbn[j][0] != 0)
		{
			sum++;
			j++;
		}
		i++;
	}

	cout << setw(101) << "|" << "\r| Total amount of books currently being borrowed: " << sum << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	system("pause");
}

//print the number of reader in library
void stats_amount_of_readers
(
	reader list_of_readers[]
)
{
	int sum = 0;
	int i = 0;
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                                ~~~ Amount of reader in library ~~~                                |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";

	while (list_of_readers[i].library_id[0] != 0)
	{
		sum++;
		i++;
	}
	cout << setw(101) << "\r| Total amount of reader in library: " << sum << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	system("pause");
}

//print 2 number, total amount of male reader and total amount of female reader
void stats_amount_of_readers_sex
(
	reader list_of_readers[]
)
{
	int sum_male= 0;
	int sum_female = 0;
	int i = 0;
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                            ~~~ Amount of reader by sex in library ~~~                             |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	while (list_of_readers[i].sex != 0)
	{
		if(list_of_readers[i].sex == '1')
		{
			sum_male++;
			i++;
		}
		else
		{
			sum_female++;
			i++;
		}
	}
	cout << setw(102) << "|\r" << setw(95) << "|    Total amount of male reader in library: " << sum_male;
	cout << "\r|   Total amount of female reader in library: " << sum_female << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	system("pause");
}

//enter current date
//return amount of books being borrowed that are overdue
void stats_amount_of_readers_books_overdue
(
	borrowing_book_form list_of_forms_for_borrowing[]
)
{
	char input_current_date[11];
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                            ~~~ Amount of reader with overdue books ~~~                            |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	
	cout << setw(101) << "dd/mm/yyyy |" << "\r| Enter current date: " << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	set_cursor_position(0, 3);
	cout << "| Enter current date: ";  cin.getline(input_current_date, 11);
	while (check_date_validity(input_current_date) == false)
	{
		set_cursor_position(0, 3);
		cout << "| Enter current date: ";  cin.getline(input_current_date, 11);
	}
	int sum = 0;
	int i = 0;
	while (list_of_forms_for_borrowing[i].borrow_date[0] != 0)
	{
		if (find_distance_between_2_dates(list_of_forms_for_borrowing[i].borrow_date, input_current_date) > 7)
		{
			sum++;
		}
		i++;
	}
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << setw(101) << "|" << "\r| Total amount of reader with overdue books: " << sum << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	system("pause");
}
