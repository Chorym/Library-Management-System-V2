#include "std_library_used.h"
#include "basic_tools.h"

using std::cout;

//not done, some value and user format are missing
void handle_add_reader_error(int error_case)
{
	set_cursor_position(33, 3 + error_case);
	switch (error_case)
	{
	case 0:
	{
		cout << "|Cit. ID :                                                         |" << "\n";
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "|                                |                   ~~~ Error: Invalid value ~~~                   |" << "\n";
		cout << "\r|-------------------------------------------\x1b[12A";
		break;
	}
	case 1:
	{
		cout << "|Surname :                                                         |" << "\n";
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "|                                |                   ~~~ Error: Invalid value ~~~                   |" << "\n";
		cout << "\r|-------------------------------------------\x1b[11A"; 
		break;
	}
	case 2:
	{
		cout << "|Name    :                                                         |" << "\n";
		cout << "\n\n\n\n\n\n\n\n";
		cout << "|                                |                   ~~~ Error: Invalid value ~~~                   |" << "\n";
		cout << "\r|-------------------------------------------\x1b[10A"; 
		break;
	}
	case 3:
	{
		cout << "|Sex     :                                                         |" << "\n";
		cout << "\n\n\n\n\n\n\n";
		cout << "|                                | 1: Male / 2: Female         ~~~ Error: Invalid value ~~~         |" << "\n";
		cout << "\r|-------------------------------------------\x1b[9A";
		break;
	}
	case 4:
	{
		cout << "|Email   :                                                         |" << "\n";
		cout << "\n\n\n\n\n\n";
		cout << "|                                | ~~~ @gmail only! ~~~         ~~~ Error: Invalid value ~~~        |" << "\n";
		cout << "\r|-------------------------------------------\x1b[8A";
		break;
	}
	case 5:
	{
		cout << "|Date of birth :                                                   |" << "\n";
		cout << "\n\n\n\n\n";
		cout << "|                                | Format: dd/mm/yyyy         ~~~ Error: Invalid value ~~~          |" << "\n";
		cout << "\r|-------------------------------------------------\x1b[7A";
		break;
	}
	case 6:
	{
		cout << "|Address :                                                         |" << "\n";
		cout << "\n\n\n";
		cout << "|                                |                   ~~~ Error: Invalid value ~~~                   |" << "\n";
		cout << "\r|-------------------------------------------\x1b[5A"; 
		break;
	}
	}
}
void handle_fix_reader_error(int error_case)
{
	switch (error_case)
	{
	case 1:
	case 2:
	case 3:
	{
		set_cursor_position(33, 8);
		cout << "|New info :                                                        " << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  |                   ~~~ Error: Invalid value ~~~                   |" << "\n";
		set_cursor_position(45, 8); break;
	}
	case 4:
	{
		set_cursor_position(33, 8);
		cout << "|New info :                                                        " << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  | 1 = Male / 2 = Female       ~~~ Error: Invalid value ~~~         |" << "\n";
		set_cursor_position(45, 8); break;
	}
	case 5:
	{
		set_cursor_position(33, 8);
		cout << "|New info :                                                        " << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  | Format: DD/MM/YYYY          ~~~ Error: Invalid date ~~~          |" << "\n";
		set_cursor_position(45, 8); break;
	}
	case 6:
	{
		set_cursor_position(33, 8);
		cout << "|New info :                                                        " << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  |                   ~~~ Error: Invalid email ~~~                   |" << "\n";
		set_cursor_position(45, 8); break;
	}
	case 7:
	{
		set_cursor_position(33, 8);
		cout << "|New info :                                                        " << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  |                   ~~~ Error: Invalid data! ~~~                   |" << "\n";
		set_cursor_position(45, 8); break;
	}
	case 10:
	{
		set_cursor_position(0, 9);
		cout << "|Find reader to fix with: ";
		set_cursor_position(33, 14);
		cout << "|               ~~~ Error: Option doesn't exist! ~~~               |" << "\n\n";
		set_cursor_position(26, 9); break;
	}
	case 11:
	{
		set_cursor_position(0, 10);
		cout << "|Reader ID:                      |";
		set_cursor_position(33, 14);
		cout << "|               ~~~ Error: Reader doesn't exist! ~~~               |" << "\n\n";
		set_cursor_position(12, 10); break;
	}
	case 12:
	{
		set_cursor_position(0, 11);
		cout << "|What to fix: ";
		set_cursor_position(33, 14);
		cout << "|               ~~~ Error: Option doesn't exist! ~~~               |" << "\n\n";
		set_cursor_position(14, 11); break;
	}
	}
}
void handle_find_reader_error(int error_case)
{
	switch (error_case)
	{
	case 0:
	{
		cout << "\x1b[1A|Search with:                        " << "\n\n";
		cout << "|                                    |    ~~~ Error: Invalid value! ~~~   |" << "\n\n";
		cout << "\r              \x1b[4A"; break;
	}
	case 1:
	{
		cout << "\x1b[1A";
		cout << "|Search:                             |[0]: Return                         |" << "\n";
		cout << "|                                    |    ~~~ Error: Invalid value! ~~~   |" << "\n\n";
		cout << "\r         \x1b[3A"; break;
	}
	}
}

void handle_add_book_error(int error_case)
{
	switch (error_case)
	{
	case 0:
	{
		set_cursor_position(0, 14);
		cout << "|                                |                   ~~~ Error: Invalid ISBN! ~~~                   |";
		set_cursor_position(0, 3);
		cout << "|[0]: Return to main menu        |ISBN:                                                             |";
		set_cursor_position(40, 3);
		break;
	}
	case 1:
	{
		set_cursor_position(0, 14);
		cout << "|                                |                   ~~~ Error: Invalid genre ~~~                   |";
		set_cursor_position(0, 5);
		cout << "|                                |Genre:                                                            |";
		set_cursor_position(41, 5);
		break;
	}
	case 2:
	{
		set_cursor_position(0, 14);
		cout << "|                                | 0 < price < 999           ~~~ Error: Invalid price ~~~           |";
		set_cursor_position(0, 6);
		cout << "|                                |Price:                                                            |";
		set_cursor_position(41, 6);
		break;
	}
	case 3:
	{
		set_cursor_position(0, 14);
		cout << "|                                |                   ~~~ Error: Invalid name! ~~~                   |";
		set_cursor_position(0, 7);
		cout << "|                                |Author(s):                                                        |";
		set_cursor_position(45, 7);
		break;
	}
	case 5:
	{
		set_cursor_position(0, 14);
		cout << "|                                | 1900 < year < 2023          ~~~ Error: Invalid year ~~~          |";
		set_cursor_position(33, 9);
		cout << "|Publish year:                                                     |";
		set_cursor_position(48, 9);
		break;
	}
	case 6:
	{
		set_cursor_position(0, 14);
		cout << "|                                | 0 < amount < 999          ~~~ Error: Invalid amount ~~~          |";
		set_cursor_position(33, 10);
		cout << "|Amount in stock:                                                  |";
		set_cursor_position(51, 10);
		break;
	}
	}
}
void handle_fix_book_error(int error_case)
{
	switch(error_case)
	{
	case 1:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |                   ~~~ Error: Invalid ISBN! ~~~                   |";
		break;
	}
	case 3:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |                   ~~~ Error: Invalid genre ~~~                   |";
		break;
	}
	case 4:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 0 < price <= 999          ~~~ Error: Invalid price ~~~           |";
		break;
	}
	case 5:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |                   ~~~ Error: Invalid name! ~~~                   |";
		break;
	}
	case 6:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 0 < amount <= 999         ~~~ Error: Invalid amount ~~~          |";
		break;
	}
	case 8:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       | 1900 <= year <= 2023        ~~~ Error: Invalid year ~~~          |";
		break;
	}
	case 10:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |               ~~~ Error: Option doesn't exist! ~~~               |";
		set_cursor_position(24, 9);
		return;
	}
	case 11:
	{
		set_cursor_position(0, 14);
		cout << "|[1]: ISBN                       |                  ~~~ Error: Can't find book ~~~                  |";
		set_cursor_position(0, 10);
		cout << "                                ";
		set_cursor_position(0, 10);
		cout << "\r|ISBN: ";
		return;
	}
	}
	set_cursor_position(0, 8);
	cout << "|--------------------------------|New info :                                                        |";
	set_cursor_position(45, 8);
}
void handle_find_book_error(int error_case)
{
	switch (error_case)
	{
	case 0:
	{
		set_cursor_position(34, 14);
		cout << "               ~~~ Error: Option doesn't exist! ~~~               ";
		set_cursor_position(12, 9);
		break;
	}
	case 1:
	{
		set_cursor_position(34, 14);
		cout << "             ~~~ Error: Book doesn't exist in lib ~~~             ";
		set_cursor_position(0, 10);
		cout << "|                                ";
		cout << "\r|ISBN: ";
		break;
	}
	case 2:
	{
		set_cursor_position(34, 14);
		cout << "             ~~~ Error: Book doesn't exist in lib ~~~             ";
		set_cursor_position(0, 10);
		cout << "|                                ";
		cout << "\r|Name: ";
		break;
	}
	}
}

void handle_add_form_error(int error_case, int i)
{
	switch (error_case)
	{
	case 0:
	{
		set_cursor_position(37, 10);
		cout << "|             ~~~ Error: Can't find reader! ~~~             ";
		set_cursor_position(18, 3);
		cout << "                  ";
		set_cursor_position(0, 3); cout << "|Enter Reader ID: ";
		break;
	}
	case 1:
	{
		set_cursor_position(37, 10);
		cout << "|               ~~~ Error: Invalid value! ~~~               ";
		set_cursor_position(33, 6);
		cout << "    ";
		set_cursor_position(33, 6);
		break;
	}
	case 2:
	{
		set_cursor_position(37, 10);
		cout << "|                ~~~ Error: Can't find book ~~~                |";
		set_cursor_position(0, 6 + i);
		cout << "                                     ";
		set_cursor_position(0, 6 + i); cout << "|Enter Book: " << i + 1 << " ISBN: ";
		break;
	}
	case 3:
	{
		set_cursor_position(37, 10);
		cout << "|               ~~~ Error: This book ran out ~~~               |";
		set_cursor_position(0, 6 + i);
		cout << "                                     ";
		set_cursor_position(0, 6 + i); cout << "|Enter Book: " << i + 1 << " ISBN: ";
		break;
	}
	case 4:
	{
		set_cursor_position(37, 10);
		cout << "|                  ~~~ Error: Invalid date ~~~                  ";
		set_cursor_position(14, 4);
		cout << "                       ";
		set_cursor_position(14, 4);
		break;
	}
	case 5:
	{
		set_cursor_position(37, 10);
		cout << "|                  ~~~ Error: Invalid date ~~~                  ";
		set_cursor_position(37, 4);
		cout << "                                       ";
		set_cursor_position(37, 4);
		cout << "|Return date: ";
		break;
	}
	}
}
void handle_return_form_error(int error_case)
{
	switch (error_case)
	{
	case 0:
	{
		set_cursor_position(34, 10); cout << "                  ~~~ Error: Can't find form! ~~~";
		set_cursor_position(49, 3);
		cout << "                                                   ";
		set_cursor_position(49, 3);
		break;
	}
	case 1:
	{
		set_cursor_position(34, 10);
		cout << "                   ~~~ Error: Invalid date ~~~";
		set_cursor_position(49, 4);
		cout << "                                                   ";
		set_cursor_position(49, 4);
		break;
	}
	}
}