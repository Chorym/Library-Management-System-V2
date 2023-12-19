#include "std_library_used.h"
#include "prefab_type.h"
#include "book_tools.h"
#include "book_borrowing.h"

using std::cout;
using std::setw;

//get current system time
void get_system_time(char return_current_date[11], char return_current_time[6])
{
	auto system_time = std::chrono::system_clock::now();
	time_t c_time = std::chrono::system_clock::to_time_t(system_time);
	tm tm;
	localtime_s(&tm, &c_time);
	strftime(return_current_date, sizeof(return_current_date), "%d/%m/%Y", &tm);
	strftime(return_current_time, sizeof(return_current_time), "%H:%M", &tm);
}

//move the cursor of a desired position on the console screen
//may work differently depending on the operating system
void set_cursor_position(int x, int y)
{
	cout << "\x1b[" << y + 1 << ";" << x + 1 << "H";
}

//accept a string of numbers and turn it into a integer type
//long long to accommodate for book ISBN
int convert_str_number_to_int_number(char input[])
{
	int result = 0;
	result = atoi(input);
	return result;
}

//accept a string holding a date
//turn it into 3 number, day, month, year
//find the position of that date in the year
int convert_date_to_day(char input[])
{
	int day = (int(input[1]) - 48) + (int(input[0]) - 48) * 10;
	int month = (int(input[4]) - 48) + (int(input[3]) - 48) * 10;
	int year = (int(input[9]) - 48) + (int(input[8]) - 48) * 10 + (int(input[7]) - 48) * 100 + (int(input[6]) - 48) * 1000;
	bool leap_year = false;
	int result = 0;
	if ((year % 400 == 0 && year % 100 == 0) || year % 4 == 0) leap_year = true;
	for (int i = 1; i < month; i++)
	{
		if (i == 2 && leap_year) result += 29;
		else if (i == 2) result += 28;
		else if (i == 3 || i == 5 || i == 7 || i == 8 || i == 10) result += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11) result += 30;
		else result += 31; 
	}
	result += day;
	return result;
}

//accept 2 string holding dates
//turn them both into day, month, year
//using the [convert_date_to_day] function to find the day
//find distance between the 2 days
int find_distance_between_2_dates(char date1[], char date2[])
{
	int result = 0;
	int day1 = convert_date_to_day(date1);
	int day2 = convert_date_to_day(date2);
	int year1 = (int(date1[9]) - 48) + (int(date1[8]) - 48) * 10 + (int(date1[7]) - 48) * 100 + (int(date1[6]) - 48) * 1000;
	int year2 = (int(date2[9]) - 48) + (int(date2[8]) - 48) * 10 + (int(date2[7]) - 48) * 100 + (int(date2[6]) - 48) * 1000;
	bool if_year1_leap_year = false;
	bool if_year2_leap_year = false;
	if ((year1 % 400 == 0 && year1 % 100 == 0) || year1 % 4 == 0) if_year1_leap_year = true;
	if ((year2 % 400 == 0 && year2 % 100 == 0) || year2 % 4 == 0) if_year2_leap_year = true;
	if (year1 == year2)
	{
		result = abs(day1 - day2);
	}
	else if (abs(year1 - year2) == 1)
	{
		if (year1 > year2)
		{
			if (if_year2_leap_year) result = day1 + (366 - day2);
			else result = day1 + (365 - day2);
		}
		else
		{
			if (if_year1_leap_year) result = day2 + (366 - day1);
			else result = day2 + (365 - day1);
		}
	}
	else
	{
		int start_year = 0;
		int end_year = 0;
		if (year1 > year2)
		{
			start_year = year2;
			end_year = year1;
			result = day1 + (if_year2_leap_year ? 366 : 365 - day2);
		}
		else
		{
			start_year = year1;
			end_year = year2;
			result += day2 + (if_year1_leap_year ? 366 : 365 - day1);
		}

		for (int i = start_year + 1; i < end_year; i++)
		{
			if ((i % 400 == 0 && i % 100 == 0) || i % 4 == 0) result += 366;
			else result += 365;
		}
	}
	return result;
}

//print a formatted screen holding every information of a reader
void display_reader_info
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int i
)
{
	int form_number = find_form(list_of_readers[i].library_id, list_of_forms_for_borrowing);
	//start
	cout << "                                                                   --|--       ~~~ Notes ~~~      --|" << "\r|--                            --|--              [" << i + 1 << "]" << "\n";

	//line 1
	if(list_of_readers[i].fine[0] == 0 || strcmp(list_of_readers[i].fine, "0") == 0) cout << setw(102) << "|Fine: None                    |\r";
	else cout << setw(102) << "|\r" << setw(76) << "|Fine: " << list_of_readers[i].fine << " 000 VND";
	cout << setw(41) << "|Email: " << list_of_readers[i].email << "\r|Lib. ID: " << list_of_readers[i].library_id << "\n";

	//line 2
	if (form_number == -1 || list_of_forms_for_borrowing[form_number].borrowed_books_isbn[0] == 0) cout << setw(102) << "|Borrowing: None               |\r";
	else cout << setw(102) << "|\r" << setw(81) << "|Borrowing: " << list_of_forms_for_borrowing[form_number].borrowed_books_isbn[0];
	cout << "\r" << setw(50) << "|Date of birth : " << list_of_readers[i].date_of_birth << "\r|Cit. ID: " << list_of_readers[i].citizen_id << "\n";

	//line 3
	if (form_number == -1 || list_of_forms_for_borrowing[form_number].borrowed_books_isbn[1] == 0) cout << setw(102) << "|Borrowing: None               |\r";
	else cout << setw(102) << "|\r" << setw(81) << "|Borrowing: " << list_of_forms_for_borrowing[form_number].borrowed_books_isbn[1];
	cout << "\r" << setw(54) << "|Card creation date: " << list_of_readers[i].card_creation_date << "\r|Surname: " << list_of_readers[i].surname << "\n";

	//line 4
	if (form_number == -1 || list_of_forms_for_borrowing[form_number].borrowed_books_isbn[2] == 0) cout << setw(102) << "|Borrowing: None               |\r";
	else cout << setw(102) << "|\r" << setw(81) << "|Borrowing: " << list_of_forms_for_borrowing[form_number].borrowed_books_isbn[2];
	cout << "\r" << setw(56) << "|Card expiration date: " << list_of_readers[i].card_expiration_date << "\r|Name   : " << list_of_readers[i].name << "\n";

	//line 5
	cout << setw(102) << "|-----------------------------------|------------------------------|\r";
	if (list_of_readers[i].sex == '1') cout << "\r|Sex    : M" << "\n";
	else if (list_of_readers[i].sex == '2') cout << "\r|Sex    : F" << "\n";

	//line 6
	cout << setw(102) << "|\r" << "|Address: " << list_of_readers[i].address << "\n";

	//end
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
}

//print a formatted screen holding every information of a book
void display_book_info
(
	book_title list_of_books_titles[],
	int i
)
{
	cout << "                                                                   --|--       ~~~ Notes ~~~      --|" << "\r|                              --|--              [" << i + 1 << "]" << "\n";
	cout << setw(102) << "|                              |\r" << setw(45) << "|Publisher: " << list_of_books_titles[i].publisher << "\r|ISBN : " << list_of_books_titles[i].isbn << "\n";
	cout << setw(102) << "|                              |\r" << setw(49) << "|Publish year : " << list_of_books_titles[i].publish_year << "\r|Name : " << list_of_books_titles[i].name << "\n";
	cout << setw(102) << "|------------------------------|\r" << setw(51) << "|Amount in stock: " << list_of_books_titles[i].amount << "\r|Genre: " << list_of_books_titles[i].genre << "\n";
	cout << setw(102) << "|\r" << setw(43) << "|Authors: " << list_of_books_titles[i].author << "\r|Price: " << list_of_books_titles[i].price << " 000 VND" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
}

//print a formatted screen holding every information of a borrowing books form
void display_borrow_forms
(
	borrowing_book_form list_of_forms_for_borrowing[],
	int i
)
{
	int book_number = 0;
	cout << "|                              --|--              [" << i + 1 << "]              --|--                          --|" << "\n";
	cout << setw(102) << "|\r" << setw(83) << "|Borrow date: " << list_of_forms_for_borrowing[i].borrow_date << "\r" << setw(42) << "|Book 1: " << list_of_forms_for_borrowing[i].borrowed_books_isbn[0] << "\r|Forms ID : " << list_of_forms_for_borrowing[i].form_id << "\n";
	cout << setw(102) << "|\r" << setw(83) << "|Return date: " << list_of_forms_for_borrowing[i].expected_return_date << "\r" << setw(42) << "|Book 2: " << list_of_forms_for_borrowing[i].borrowed_books_isbn[1] << "\r|Reader ID: " << list_of_forms_for_borrowing[i].borrower_id << "\n";
	cout << setw(102) << "|                              |\r" << setw(42) << "|Book 3: " << list_of_forms_for_borrowing[i].borrowed_books_isbn[2] << "\r|" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
}