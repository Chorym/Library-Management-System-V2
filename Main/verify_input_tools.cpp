#include "std_library_used.h"
#include "prefab_type.h"
#include "reader_tools.h"
#include "book_tools.h"

//accept a string holding a date
//turn it info day, month, year
//if one is invalid, return false
bool check_date_validity(char input[])
{
	if (strlen(input) != 10) return false;
	for (int i = 0; i < 11; i++)
	{
		if (i != 2 && i != 5)
		{
			if (isdigit(input[i] == false)) return false;
		}
	}

	int day = 0, month = 0, year = 0;

	//get date
	day += (int(input[1]) - 48);
	day += (int(input[0]) - 48) * 10;

	//get month
	month += (int(input[4]) - 48);
	month += (int(input[3]) - 48) * 10;

	//get year
	year += (int(input[9]) - 48);
	year += (int(input[8]) - 48) * 10;
	year += (int(input[7]) - 48) * 100;
	year += (int(input[6]) - 48) * 1000;

	if (day < 1 || day > 31) return false;
	if (month < 1 || month > 12) return false;
	if (year < 2023 || year > 2024) return false;
	if (month == 2)
	{
		if ((year % 400 == 0 && year % 100 == 0) || year % 4 == 0)
		{
			if (day < 1 || day > 29) return false;
		}
		else
		{
			if (day < 1 || day > 28) return false;
		}
	}
	return true;
}

//accept a string holding a gmail
//if the ending is not @gmail.com, return false
bool check_gmail_validity(char input[])
{
	char gmail_ending[11] = "moc.liamg@";

	if (strlen(input) < 11) return false;

	int i = 0;
	int input_ending = 0;
	while (true)
	{
		if (int(input[i]) == 0)
		{
			input_ending = i - 1;
			break;
		}
		i++;
	}
	int j = input_ending;
	for (int i = 0; i < 10; i++)
	{
		if (int(input[j]) != int(gmail_ending[i])) return false;
		j--;
	}

	for (int i = 0; i < strlen(input) - 10; i++)
	{
		if(isalpha(input[i]) == false && isdigit(input[i]) == false) return false;
	}
	return true;
}

//accept a string holding a date
//turn it info day, month, year
//if one is invalid, return false
bool check_birthday_validity(char input[])
{
	if (strlen(input) != 10) return false;
	for (int i = 0; i < 11; i++)
	{
		if (i != 2 && i != 5)
		{
			if (isdigit(input[i] == false)) return false;
		}
	}

	int day = 0, month = 0, year = 0;
	int value = 0;

	//get date
	day += (int(input[1]) - 48);
	day += (int(input[0]) - 48) * 10;

	//get month
	month += (int(input[4]) - 48);
	month += (int(input[3]) - 48) * 10;

	//get year
	year += (int(input[9]) - 48);
	year += (int(input[8]) - 48) * 10;
	year += (int(input[7]) - 48) * 100;
	year += (int(input[6]) - 48) * 1000;

	if (day < 1 || day > 31) return false;
	if (month < 1 || month > 12) return false;
	if (year < 1995 || year > 2006) return false;
	if (month == 2)
	{
		if ((year % 400 == 0 && year % 100 == 0) || year % 4 == 0)
		{
			if (day < 1 || day > 29) return false;
		}
		else
		{
			if (day < 1 || day > 28) return false;
		}
	}
	return true;
}

//accept a string holding a citizen ID
//if a char is not a number or the length is not 12 and/or has already existed in the database, return false
bool check_citizenID_validity(char input[], reader list_of_readers[])
{
	if (strlen(input) != 12) return false;
	for (int i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) == false) return false;
	}
	int reader_number = find_reader(list_of_readers, input, 0, 0);
	if (reader_number != -1) return false;
	return true;
}

//accept a string holding a book ISBN
//if a char is not a number or the length is not 13 and/or has already existed in the database, return false
bool check_ISBN_validity(char input[], book_title list_of_book_titles[])
{
	if (strlen(input) != 13) return false;
	for (int i = 0; i < 13; i++)
	{
		if (isdigit(input[i]) == false) return false;
	}
	int book_number = find_book(list_of_book_titles, input, 0);
	if (book_number != -1) return false;
	return true;
}

//accept a string 
//if string has a char that is not text (letters), return false
bool check_if_input_is_pure_text(char input[])
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (isalpha(input[i]) == false) return false;
	}
	return true;
}

//accept a string 
//if string has a char that is not an integer (number), return false
bool check_if_input_is_pure_number(char input[])
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) == false) return false;
	}
	return true;
}

//accept a string 
//if string has a char that is neither a letter or number, return false
bool check_if_no_special_characters(char input[])
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) == false && isalpha(input[i]) == false) return false;
	}
	return true;
}

//accept one input and 2 cap
//find if the input is within the caps, else return false
bool check_within_range(int input, int min, int max)
{
	if (input < min || input > max) return false;
	return true;
}