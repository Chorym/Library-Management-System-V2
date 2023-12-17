#include <iostream>
#include <conio.h>
#include <string.h>
#include "prefab_type.h"
#include "basic_tools.h"
#include "error_handing_tools.h"
#include "verify_input_tools.h"

using std::cout;
using std::cin;
using std::system;

//accepts a name, or citizen ID, or library ID
//return the corresponding position in the array which contains that information
//only one may be accepted at one time, the rest will be entered as 0
int find_reader
(
	reader list_of_readers[],
	char input_id[],
	char input_citizen_id[],
	char input_name[]
)
{
	int i = 0;
	if (input_name[0] != 0)
	{
		char full_name[100] = ""; //get surname + name = full name
		strcpy_s(full_name, 20, list_of_readers[i].surname); strcat_s(full_name, 20, " "); strcat_s(full_name, 20, list_of_readers[i].name);
		while (list_of_readers[i].surname != 0 && list_of_readers[i].name != 0)
		{
			if (strcmp(input_name, list_of_readers[i].surname) == 0 || strcmp(input_name, list_of_readers[i].name) == 0 || strcmp(input_name, full_name) == 0)
			{
				return i;
			}
			i++;
		}
	}
	else if (input_citizen_id[0] != 0)
	{
		while (list_of_readers[i].citizen_id != 0)
		{
			if (strcmp(input_citizen_id, list_of_readers[i].citizen_id) == 0)
			{
				return i;
			}
			i++;
		}
	}
	else
	{
		while (input_id[0] != 0)
		{
			if (strcmp(input_id, list_of_readers[i].library_id) == 0)
			{
				return i;
			}
			i++;
		}
	}
	return -1;
}

//display menu
//prints every reader with all of their info, with each page holding 4
void view_list_of_reader
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int page_number
)
{
	if (list_of_readers[0].library_id[0] == 0)
	{
		cout << "|                                                                                                   |" << "\n";
		cout << "|                                       ~~~ Library empty ~~~                                       |" << "\n";
		cout << "|                                                                                                   |" << "\n";
		cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
		return;
	}
	int i = page_number * 4;
	while (list_of_readers[i].library_id[0] != 0)
	{
		display_reader_info(list_of_readers, list_of_forms_for_borrowing, i);
		i++;
		if (i % 4 == 0)
		{
			break;
		}
	}
}

//add n number of reader, the number is chosen by the user
//slowly add every infomation, with input check to verify that it is valid
//if there is no more space, simply return to display menu
void add_reader
(
	reader list_of_readers[],
	int  current_amount_of_reader,
	int  max_amount_of_reader
)
{
	system("cls");
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|   ~~~ Readers management ~~~   |                  ~~~ Current mode : Adding ~~~                   |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";

	if (current_amount_of_reader == max_amount_of_reader)
	{
		set_cursor_position(0, 9);
		cout << "|[8]: Next Page    Prev Page :[9]|                   ~~~  Error: Library full ~~~                   |" << "\n";
		system("pause");
		return;
	}

	const int max_input_length = 50;
	char input[max_input_length];
	int amount_of_new_reader = 0;
	bool valid_info = true;

	cout << "|[0]: Return to main menu        |Cit. ID :                                                         |" << "\n"; // line 4
	cout << "|                                |Surname :                                                         |" << "\n"; // line 5
	cout << "|                                |Name    :                                                         |" << "\n"; // line 6
	cout << "|                                |Sex     :                                                         |" << "\n"; // line 7
	cout << "|                                |Email   :                                                         |" << "\n"; // line 8
	cout << "|--------------------------------|Date of birth :                                                   |" << "\n"; // line 9
	cout << "                                 |Card cre. date:                                                   |" << "\r|Current amount of reader: " << current_amount_of_reader << "\n"; // line 10
	cout << "                                 |Address :                                                         |" << "\r|Library capcity: " << max_amount_of_reader << "\n"; // line 11
	cout << "|Amount of reader to add:        |                                                                  |" << "\n"; // line 12
	cout << "|Current count:                  |                                                                  |" << "\n"; // line 13
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	cout << "|                                |                                                                  |" << "\n";
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n";
	set_cursor_position(26, 11); cin >> amount_of_new_reader;
	if (amount_of_new_reader < 1) return;
	while (amount_of_new_reader > max_amount_of_reader - current_amount_of_reader)
	{
		set_cursor_position(0, 14);
		cout << "|[8]: Next Page    Prev Page :[9]|            ~~~  Error: Exceeding library capacity ~~~            |" << "\n";
		set_cursor_position(0, 11); cout << "|Amount of reader to add:        ";
		set_cursor_position(26, 11); cin >> amount_of_new_reader;
	}

	for (int i = current_amount_of_reader; i < current_amount_of_reader + amount_of_new_reader; i++)
	{
		set_cursor_position(0, 3);
		cout << "|[0]: Return to main menu        |Cit. ID :                                                         |" << "\n"; // line 4
		cout << "|                                |Surname :                                                         |" << "\n"; // line 5
		cout << "|                                |Name    :                                                         |" << "\n"; // line 6
		cout << "|                                |Sex     :                                                         |" << "\n"; // line 7
		cout << "|                                |Email   :                                                         |" << "\n"; // line 8
		cout << "|--------------------------------|Date of birth :                                                   |" << "\n"; // line 9
		cout << "                                 |Card cre. date:                                                   |" << "\r|Current amount of reader: " << current_amount_of_reader << "\n"; // line 10
		cout << "                                 |Address :                                                         |" << "\r|Library capcity: " << max_amount_of_reader << "\n\n"; // line 11
		cout << "                " << i - current_amount_of_reader + 1 << "\r|Current count: " << "\n"; // line 13

		//add cit. ID
		set_cursor_position(0, 3);
		cout << "|[0]: Return to main menu        |Cit. ID : "; cin.ignore(); cin.getline(input, max_input_length);
		while (check_citizenID_validity(input) == false)
		{
			handle_add_reader_error(0);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].citizen_id, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 4);

		//add surname
		cout << "|                                |Surname : "; cin.getline(input, max_input_length);
		while (check_if_input_is_pure_text(input) == false)
		{
			handle_add_reader_error(1);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].surname, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 5);

		//add name
		cout << "|                                |Name    : "; cin.getline(input, max_input_length);
		while (check_if_input_is_pure_text(input) == false)
		{
			handle_add_reader_error(2);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].name, input);
		set_cursor_position(0, 14);
		cout << "|                                | 1: Male / 2: Female                                              |" << "\n";
		set_cursor_position(0, 6);

		//add sex
		cout << "|                                |Sex     : "; cin.getline(input, max_input_length);
		while (strcmp(input, "1") != 0 && strcmp(input, "2") != 0)
		{
			handle_add_reader_error(3);
			cin.getline(input, max_input_length);
		}
		list_of_readers[i].sex = input[0];
		set_cursor_position(0, 14);
		cout << "|                                | ~~~ @gmail only! ~~~                                             |" << "\n";
		set_cursor_position(0, 7);

		//add email
		cout << "|                                |Email   : "; cin.getline(input, max_input_length);
		while (check_gmail_validity(input) == false)
		{
			handle_add_reader_error(4);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].email, input);
		set_cursor_position(0, 14);
		cout << "|                                | dd/mm/yyyy                                                       |" << "\n";
		set_cursor_position(0, 8);

		//add birthday
		cout << "|--------------------------------|Date of birth : "; cin.getline(input, max_input_length);
		while (check_birthday_validity(input) == false)
		{
			handle_add_reader_error(5);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].date_of_birth, input);
		set_cursor_position(0, 14);
		cout << "|                                | dd/mm/yyyy                                                       |" << "\n";
		set_cursor_position(0, 9);

		//add card cre
		cout << "|Current amount of reader: " << current_amount_of_reader; 
		set_cursor_position(33,9);
		cout << "|Card cre. date: ";
		cin.getline(input, max_input_length);
		while (check_date_validity(input) == false)
		{
			handle_add_reader_error(6);
			cin.getline(input, max_input_length);
		}
		strcpy_s(list_of_readers[i].card_creation_date, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";
		set_cursor_position(0, 10);

		//add card exp
		int int_year = (int(input[9]) - 48) + (int(input[8]) - 48) * 10 + (int(input[7]) - 48) * 100 + (int(input[6]) - 48) * 1000;
		int_year += 4;
		int j = 1000;
		for (int i = 0; i < 4; i++)
		{
			int temp = int_year / j;
			int_year %= j;
			j /= 10;
			input[i + 6] = char(temp + 48);
		}
		strcpy_s(list_of_readers[i].card_expiration_date, input);

		//add address
		cout << "\r|Library capcity: " << max_amount_of_reader;
		set_cursor_position(33, 10);
		cout << "|Address : "; cin.getline(input, max_input_length);
		while (false) //handle error when added
		{
			//handle_add_reader_error(7);
		}
		strcpy_s(list_of_readers[i].address, input);
		set_cursor_position(0, 14);
		cout << "|                                |                                                                  |" << "\n";

		//add id
		char str_generated_id[9] = "00000000";
		int generated_id;
		bool successfully_generated = false;
		while (!successfully_generated)
		{
			generated_id = rand() % 1000;
			while (generated_id < 100)
			{
				generated_id = rand() % 1000;
			}
			generated_id += 20230000;
			j = 10000000;
			for (int i = 0; i < 8; i++)
			{
				int temp = generated_id / j;
				generated_id %= j;
				j /= 10;
				str_generated_id[i] = char(temp + 48);
			}
			j = 0;
			while (j < current_amount_of_reader + 1)
			{
				if (strcmp(list_of_readers[j].library_id, str_generated_id) == 0) break;
				if(j == current_amount_of_reader) successfully_generated = true;
				j++;
			}
		}
		strcpy_s(list_of_readers[i].library_id, 9, str_generated_id);
	}
	set_cursor_position(0, 14);
	cout << "|                                |       ~~~  Adding complete! Press any key to continue. ~~~       |" << "\n";
	cin.ignore();
}

//change a reader information
//user choose a book by entering their library ID
//then pick a certain piece of info to change
//enter the new info, the input is checked just as it is checked in add book menu
void change_reader_info
(
	reader list_of_readers[]
)
{
	int i = 0;
	const int max_string_length = 50;
	char new_info[max_string_length];
	char finding_data[max_string_length];
	int  reader_number = 0;
	int  finding_option = 0;
	int  fixing_option = 0;
	
	set_cursor_position(0, 0);
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 1
	cout << "|   ~~~ Readers management ~~~   |                  ~~~ Current mode : Fixing ~~~                   |" << "\n"; // line 2
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 3
	cout << "|[0]: Return to menu             |                                                                  |" << "\n"; // line 4
	cout << "|                                |                                                                  |" << "\n"; // line 5
	cout << "|                                |                                                                  |" << "\n"; // line 6
	cout << "|                                |                                                                  |" << "\n"; // line 7
	cout << "|                                |                                                                  |" << "\n"; // line 8
	cout << "|--------------------------------|                                                                  |" << "\n"; // line 9
	cout << "|Find reader to fix with:        |                                                                  |" << "\n"; // line 10
	cout << "|                                |                                                                  |" << "\n"; // line 11
	cout << "|                                |                                                                  |" << "\n"; // line 12
	cout << "|                                |                                                                  |" << "\n"; // line 13
	cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 14
	cout << "|[1]: Reader ID                  |                                                                  |" << "\n"; // line 15
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 16
	set_cursor_position(26, 9); finding_option = int(_getch() - 48);
	
	while (finding_option < 0 || finding_option > 1)
	{
		handle_fix_reader_error(10);
		finding_option = int(_getch() - 48);
	}

	if (finding_option == 0)
	{
		return;
	}
	else if (finding_option == 1)
	{
		cout << "\r|Find reader to fix with: ID" << "\n";
		cout << "|Reader ID: "; cin.getline(finding_data, max_string_length);
		reader_number = find_reader(list_of_readers, finding_data, 0, 0);
		while (reader_number == -1)
		{
			handle_fix_reader_error(11);
			cin.getline(finding_data, max_string_length);
			reader_number = find_reader(list_of_readers, finding_data, 0, 0);

		}
		cout << "\n\n\n";
		cout << "|[1]: Reader ID                  |                       ~~~ Reader found ~~~                       |" << "\n";
	}
	
	set_cursor_position(0, 3);
	cout << "|[0]: Return to menu             |[1]: Cit. ID   [4]: Sex            [7]: Address                   |" << "\n"; 
	cout << "|                                |[2]: Surname   [5]: Date of birth                                 |" << "\n";
	cout << "|                                |[3]: Name      [6]: Email                                         |" << "\n"; 
	cout << "|                                |------------------------------------------------------------------|" << "\n";
	cout << "\n\n\n\n";
	cout << "|What to fix:              "; 
	cout << "\r|What to fix: ";
	fixing_option = int(_getch() - 48); 

	while (fixing_option < 1 || fixing_option > 7)
	{
		handle_fix_reader_error(12);
		fixing_option = int(_getch() - 48);
	}

	cout << fixing_option;
	switch (fixing_option)
	{
	case 1:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].citizen_id << "\n"; 
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length); 
		while (check_citizenID_validity(new_info) == false)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_readers[reader_number].citizen_id, new_info);
		break;
	}
	case 2:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].surname << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_if_input_is_pure_text(new_info) == false)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_readers[reader_number].surname, new_info);
		break;
	}
	case 3:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].name << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_if_input_is_pure_text(new_info) == false)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_readers[reader_number].name, new_info);
		break;
	}
	case 4: 
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].sex << "\n";
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  | 1 = Male / 2 = Female                                            |" << "\n";
		set_cursor_position(0, 8);
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (strcmp(new_info, "1") != 0 && strcmp(new_info, "2") != 0)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		list_of_readers[reader_number].sex = new_info[0];
		break;
	}
	case 5:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].date_of_birth << "\n"; 
		set_cursor_position(0, 14);
		cout << "|[1]: Reader ID                  | Format: DD/MM/YYYY                                               |" << "\n";
		set_cursor_position(0, 8);
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_birthday_validity(new_info) == false)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_readers[reader_number].date_of_birth, new_info);
		break;
	}
	case 6:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].email << "\n"; 
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		while (check_gmail_validity(new_info) == false)
		{
			handle_fix_reader_error(fixing_option); cin.getline(new_info, max_string_length);
		}
		strcpy_s(list_of_readers[reader_number].email, new_info);
		break;
	}
	case 7:
	{
		set_cursor_position(33, 7);
		cout << "|Prev info: " << list_of_readers[reader_number].address << "\n";
		cout << "|--------------------------------|New info : "; cin.getline(new_info, max_string_length);
		strcpy_s(list_of_readers[reader_number].address, new_info);
		break;
	}
	}
	set_cursor_position(0, 14);
	cout << "|                                |             ~~~ Information changed successfully ~~~             |";
	cin.ignore();
	return;
}

//remove everything from a or ALL reader
//user choose which option to delete, 1 or all
//if choose 1, enter reader library ID to delete
//if choose all, type confirm to delete all
void delete_reader_menu
(
	reader list_of_readers[],
	int current_amount_of_reader
)
{
	char input_id[9];
	int  delete_option = 0;
	int  reader_number = 0;
	int  i = 0;

	set_cursor_position(0, 0);
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 0
	cout << "|   ~~~ Readers management ~~~   |                  ~~~ Current mode : Deleting ~~~                 |" << "\n"; // line 1
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 2
	cout << "|[0]: Return to menu             |                                                                  |" << "\n"; // line 3
	cout << "|[1]: Delete 1                   |                                                                  |" << "\n"; // line 4
	cout << "|[2]: Delete ALL                 |                                                                  |" << "\n"; // line 5
	cout << "|                                |                                                                  |" << "\n"; // line 6
	cout << "|                                |                                                                  |" << "\n"; // line 7
	cout << "|--------------------------------|                                                                  |" << "\n"; // line 8
	cout << "|Delete option :                 |                                                                  |" << "\n"; // line 9
	cout << "|Enter Lib. ID :                 |                                                                  |" << "\n"; // line 10
	cout << "|                                |                                                                  |" << "\n"; // line 11
	cout << "|                                |                                                                  |" << "\n"; // line 12
	cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 13
	cout << "|                                |                                                                  |" << "\n"; // line 14
	cout << "|---------------------------------------------------------------------------------------------------|" << "\n"; // line 15
	set_cursor_position(17, 9); delete_option = int(_getch() - 48); cout << "\n";
	while (delete_option < 0 || delete_option > 3)
	{
		set_cursor_position(17, 9);
		cout << "|Delete option: ";
		delete_option = int(_getch() - 48); cout << "\n";
	}

	switch (delete_option)
	{
	case 0:
		return;
	case 1:
		set_cursor_position(0, 9);
		cout << "|Delete option : Delete 1" << "\n";
		cout << "|Enter Lib. ID : "; cin.getline(input_id, 9);
		i = find_reader(list_of_readers, input_id, 0, 0);
		while (i == -1)
		{
			//error
			i = find_reader(list_of_readers, input_id, 0, 0);
		}
		//display user found, type confirm to delete
		while (i < current_amount_of_reader)
		{
			strcpy_s(list_of_readers[i].library_id, list_of_readers[i + 1].library_id);
			strcpy_s(list_of_readers[i].citizen_id, list_of_readers[i + 1].citizen_id);
			strcpy_s(list_of_readers[i].surname, list_of_readers[i + 1].surname);
			strcpy_s(list_of_readers[i].name, list_of_readers[i + 1].name);
			strcpy_s(list_of_readers[i].date_of_birth, list_of_readers[i + 1].date_of_birth);
			list_of_readers[i].sex = list_of_readers[i + 1].sex;
			strcpy_s(list_of_readers[i].email, list_of_readers[i + 1].email);
			strcpy_s(list_of_readers[i].address, list_of_readers[i + 1].address);
			strcpy_s(list_of_readers[i].card_creation_date, list_of_readers[i + 1].card_creation_date);
			strcpy_s(list_of_readers[i].card_expiration_date, list_of_readers[i + 1].card_expiration_date);
			i++;
		}
		strcpy_s(list_of_readers[i].library_id, "");
		strcpy_s(list_of_readers[i].citizen_id, "");
		strcpy_s(list_of_readers[i].surname, "");
		strcpy_s(list_of_readers[i].name, "");
		strcpy_s(list_of_readers[i].date_of_birth, "");
		list_of_readers[i].sex = ' ';
		strcpy_s(list_of_readers[i].email, "");
		strcpy_s(list_of_readers[i].address, "");
		strcpy_s(list_of_readers[i].card_creation_date, "");
		strcpy_s(list_of_readers[i].card_expiration_date, "");
		set_cursor_position(34, 14);
		cout << "                         ~~~ Deleted! ~~~                         |";
		cin.ignore();
		return;
	case 2:
		set_cursor_position(0, 9);
		cout << "|Delete option : ALL" << "\n";
		char input[8];
		set_cursor_position(52, 14);
		cout << "Type CONFIRM to delete: "; cin.getline(input, 8);
		if (strcmp(input, "CONFIRM") == 0)
		{
			for (int i = 0; i < current_amount_of_reader; i++)
			{
				strcpy_s(list_of_readers[i].library_id, "");
				strcpy_s(list_of_readers[i].citizen_id, "");
				strcpy_s(list_of_readers[i].surname, "");
				strcpy_s(list_of_readers[i].name, "");
				strcpy_s(list_of_readers[i].date_of_birth, "");
				list_of_readers[i].sex = ' ';
				strcpy_s(list_of_readers[i].email, "");
				strcpy_s(list_of_readers[i].address, "");
				strcpy_s(list_of_readers[i].card_creation_date, "");
				strcpy_s(list_of_readers[i].card_expiration_date, "");
			}
			set_cursor_position(34, 14);
			cout << "                       ~~~ Deleted all! ~~~                       |";
			cin.ignore();
			return;
		}
		else
		{
			set_cursor_position(34, 14);
			cout << "                   ~~~ Deleting all failed! ~~~                   |";
			cin.ignore();
			return;
		}
	}
}

//display 1 reader, found using the find reader function
//can be found by using name, citizen id or library id
//input must be exact or book can not be found
void find_reader_menu
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[]
)
{
	int  finding_option = 0;
	int  reader_number = 0;
	char input[30];

	while (true)
	{
		if (reader_number == 0) system("cls"); //only reset at first entry
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
		cout << "|[1]: Lib. ID                    |                                                                  |" << "\n"; // line 11
		cout << "|[2]: Cit. ID                    |                                                                  |" << "\n"; // line 12
		cout << "|[3]: Name                       |                                                                  |" << "\n"; // line 13
		cout << "|--------------------------------|------------------------------------------------------------------|" << "\n"; // line 14
		cout << "|                                |                                                                  |" << "\n"; // line 15
		cout << "|---------------------------------------------------------------------------------------------------|"; // line 16
		set_cursor_position(12, 9); finding_option = int(_getch() - 48);
		
		while (finding_option < 0 || finding_option > 3)
		{
			set_cursor_position(34, 14);
			cout << "               ~~~ Error: Option doesn't exist! ~~~               ";
			set_cursor_position(12, 9);
			finding_option = int(_getch() - 48);
		}

		switch (finding_option)
		{
		case 0:
			return;
		case 1:
		{
			cout << "Lib. ID" << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			set_cursor_position(0, 10);
			cout << "|Lib ID: ";
			cin.getline(input, 30);
			if (input == "0") return;
			reader_number = find_reader(list_of_readers, input, 0, 0);
			while (reader_number == -1)
			{
				set_cursor_position(34, 14);
				cout << "            ~~~ Error: Reader doesn't exist in lib ~~~            ";
				set_cursor_position(0, 10);
				cout << "|                                ";
				cout << "\r|Lib ID: "; cin.getline(input, 30);
				if (input == "0") return;
				reader_number = find_reader(list_of_readers, input, 0, 0);
			}
			set_cursor_position(0, 16);
			display_reader_info(list_of_readers, list_of_forms_for_borrowing, reader_number);
			set_cursor_position(34, 14);
			cout << "                       ~~~ Reader found ~~~                       " << "\n\n"; cin.ignore();
			break;
		}
		case 2:
		{
			cout << "Cit. ID" << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			set_cursor_position(0, 10);
			cout << "|Cit. ID: ";
			cin.getline(input, 30);
			reader_number = find_reader(list_of_readers, 0, input, 0);
			while (reader_number == -1)
			{
				set_cursor_position(34, 14);
				cout << "            ~~~ Error: Reader doesn't exist in lib ~~~            ";
				set_cursor_position(0, 10);
				cout << "|                                ";
				cout << "\r|Cit. ID: "; cin.getline(input, 30);
				reader_number = find_reader(list_of_readers, 0, input, 0);
			}
			set_cursor_position(0, 16);
			display_reader_info(list_of_readers, list_of_forms_for_borrowing, reader_number);
			set_cursor_position(34, 14);
			cout << "                       ~~~ Reader found ~~~                       " << "\n\n"; cin.ignore();
			break;
		}
		case 3:
		{
			cout << "Name" << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			cout << "|                               " << "\n";
			set_cursor_position(0, 10);
			cout << "|Name: ";
			cin.getline(input, 30);
			reader_number = find_reader(list_of_readers, 0, 0, input);
			while (reader_number == -1)
			{
				set_cursor_position(34, 14);
				cout << "            ~~~ Error: Reader doesn't exist in lib ~~~            ";
				set_cursor_position(0, 10);
				cout << "|                                ";
				cout << "\r|Name: "; cin.getline(input, 30);
				reader_number = find_reader(list_of_readers, 0, 0, input);
			}
			set_cursor_position(0, 16);
			display_reader_info(list_of_readers, list_of_forms_for_borrowing, reader_number);
			set_cursor_position(34, 14);
			cout << "                       ~~~ Reader found ~~~                       " << "\n\n"; cin.ignore();
			break;
		}
		}

	}
}