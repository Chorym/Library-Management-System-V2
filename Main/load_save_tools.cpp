#include "std_library_used.h"
#include "prefab_type.h"

using std::cout;
using std::cin;

//load all data 
void load_all_readers(const char* file_name, reader list_of_readers[])
{
	cout << "Loading readers data..." << "\n";
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "r");
	if (file_pointer == NULL)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't open file" << "\n";
		cout << "File name required: " << file_name << "\n";
		cout << "If you want to change the file name/address, it is located at main.cpp line 31-33" << "\n";
		cin.ignore();
		return;
	}

	int i = 0, num = 0, current_number_of_readers = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_readers) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount" << "\n";
		cin.ignore();
		return;
	}

	while ((num = fscanf_s(file_pointer, "%8[^,],%12[^,],%20[^,],%30[^,],%c,%10[^,],%75[^,],%100[^,],%10[^,],%10[^,],%4[^.].\n",
		list_of_readers[i].library_id, 9,
		list_of_readers[i].citizen_id, 13,
		list_of_readers[i].surname, 21,
		list_of_readers[i].name, 31,
		&list_of_readers[i].sex, 1,
		list_of_readers[i].date_of_birth, 11,
		list_of_readers[i].email, 76,
		list_of_readers[i].address, 101,
		list_of_readers[i].card_creation_date, 11,
		list_of_readers[i].card_expiration_date, 11,
		list_of_readers[i].fine, 5
	)) != EOF && i < current_number_of_readers - 1)
	{
		if (num != 11)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data" << "\n";
			cout << num << "\n";
			cin.ignore();
			return;
		}
		i++;
	}
	fclose(file_pointer);
}
void load_all_books(const char* file_name, book_title list_of_book_titles[])
{
	cout << "Loading books data..." << "\n";
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "r");
	if (file_pointer == NULL)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't open file" << "\n";
		cout << "File name required: " << file_name << "\n";
		cout << "If you want to change the file name/address, it is located at main.cpp line 31-33" << "\n";
		cin.ignore();
		return;
	}

	int i = 0, num = 0, current_number_of_books = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_books) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount" << "\n";
		cin.ignore();
		return;
	}

	while ((num = fscanf_s(file_pointer, "%13[^,],%100[^,],%50[^,],%50[^,],%4[^,],%30[^,],%4[^,],%4[^.].\n",
		list_of_book_titles[i].isbn, 14,
		list_of_book_titles[i].name, 101,
		list_of_book_titles[i].author, 51,
		list_of_book_titles[i].publisher, 51,
		list_of_book_titles[i].publish_year, 5,
		list_of_book_titles[i].genre, 31,
		list_of_book_titles[i].price, 5,
		list_of_book_titles[i].amount, 5
	)) != EOF && i < current_number_of_books - 1)
	{
		if (num != 8)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data" << "\n";
			cout << num << " " << i << "\n";
			cin.ignore();
			return;
		}
		i++;
	}
	fclose(file_pointer);
}
void load_all_borrow_forms(const char* file_name, borrowing_book_form list_of_borrow_forms[])
{
	cout << "Loading forms data..." << "\n";
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "r");
	if (file_pointer == NULL)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't open file" << "\n";
		cout << "File name required: " << file_name << "\n";
		cout << "If you want to change the file name/address, it is located at main.cpp line 31-33" << "\n";
		cin.ignore();
		return;
	}

	int i = 0, num = 0, current_number_of_forms = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_forms) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount" << "\n";
		cin.ignore();
		return;
	}

	while ((num = fscanf_s(file_pointer, "%8[^,],%8[^,],%10[^,],%10[^,],%13[^,],%13[^,],%13[^,],%c,%1[^,],%1[^,],%1[^.].\n",
		list_of_borrow_forms[i].form_id, 9,
		list_of_borrow_forms[i].borrower_id, 9,
		list_of_borrow_forms[i].borrow_date, 11,
		list_of_borrow_forms[i].expected_return_date, 11,
		list_of_borrow_forms[i].borrowed_books_isbn[0], 14,
		list_of_borrow_forms[i].borrowed_books_isbn[1], 14,
		list_of_borrow_forms[i].borrowed_books_isbn[2], 14,
		&list_of_borrow_forms[i].form_status, 1,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[0], 2,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[1], 2,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[2], 2
	)) != EOF && i < current_number_of_forms - 1)
	{
		if (num != 11)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data" << "\n";
			cout << num << " " << i << "\n";
			cin.ignore();
			return;
		}
		i++;
	}
	fclose(file_pointer);
}

//save all data
bool save_all_readers(const char* file_name, reader list_of_readers[])
{
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "w");
	if (file_pointer == NULL)
	{
		return false;
	}

	int current_number_of_readers = 0;
	while (list_of_readers[current_number_of_readers].library_id[0] != 0)
	{
		current_number_of_readers++;
	}

	fprintf_s(file_pointer, "%d\n", current_number_of_readers);
	for (int i = 0; i < current_number_of_readers; i++)
	{
		fprintf_s(file_pointer, "%s,%s,%s,%s,%c,%s,%s,%s,%s,%s,%s.\n",
			list_of_readers[i].library_id,
			list_of_readers[i].citizen_id, 
			list_of_readers[i].surname, 
			list_of_readers[i].name, 
			list_of_readers[i].sex, 
			list_of_readers[i].date_of_birth, 
			list_of_readers[i].email,
			list_of_readers[i].address, 
			list_of_readers[i].card_creation_date, 
			list_of_readers[i].card_expiration_date, 
			list_of_readers[i].fine
		);
	}
	fclose(file_pointer);
	return true;
}
bool save_all_books(const char* file_name, book_title list_of_book_titles[])
{
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "w");
	if (file_pointer == NULL)
	{
		return false;
	}

	int current_number_of_books = 0;
	while (list_of_book_titles[current_number_of_books].isbn[0] != 0)
	{
		current_number_of_books++;
	}

	fprintf_s(file_pointer, "%d\n", current_number_of_books);
	for (int i = 0; i < current_number_of_books; i++)
	{
		fprintf_s(file_pointer, "%s,%s,%s,%s,%s,%s,%s,%s.\n",
			list_of_book_titles[i].isbn, 
			list_of_book_titles[i].name, 
			list_of_book_titles[i].author, 
			list_of_book_titles[i].publisher,
			list_of_book_titles[i].publish_year, 
			list_of_book_titles[i].genre, 
			list_of_book_titles[i].price, 
			list_of_book_titles[i].amount
		);
	}
	fclose(file_pointer);
	return true;
}
bool save_all_borrow_forms(const char* file_name, borrowing_book_form list_of_borrow_forms[])
{
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name, "w");
	if (file_pointer == NULL)
	{
		return false;
	}

	int current_number_of_forms = 0;
	while (list_of_borrow_forms[current_number_of_forms].form_id[0] != 0)
	{
		current_number_of_forms++;
	}

	fprintf_s(file_pointer, "%d\n", current_number_of_forms);
	for (int i = 0; i < current_number_of_forms; i++)
	{
		fprintf_s(file_pointer, "%s,%s,%s,%s,%s,%s,%s,%c,%s,%s,%s.\n",
			list_of_borrow_forms[i].form_id, 
			list_of_borrow_forms[i].borrower_id, 
			list_of_borrow_forms[i].borrow_date, 
			list_of_borrow_forms[i].expected_return_date, 
			list_of_borrow_forms[i].borrowed_books_isbn[0], 
			list_of_borrow_forms[i].borrowed_books_isbn[1], 
			list_of_borrow_forms[i].borrowed_books_isbn[2],
			list_of_borrow_forms[i].form_status,
			list_of_borrow_forms[i].lost_borrowed_books_isbn[0],
			list_of_borrow_forms[i].lost_borrowed_books_isbn[1],
			list_of_borrow_forms[i].lost_borrowed_books_isbn[2]
		);
	}
	fclose(file_pointer);
	return true;
}

//debugger load tool
//This is a temporary function to load ALL test data, any new changes will be overwriten
//This function will only run ONCE at first launch of the program and can not be run again unless the program is closed and re-opened
//Press 1 to run this function, anything else to not
bool load_all_test_data
(
	const char* loader_file, 
	reader list_of_readers[],
	book_title list_of_book_titles[],
	borrowing_book_form list_of_borrow_forms[]
)
{
	cout << "- This is a temporary function to load ALL test data, any new changes will be overwriten" << "\n";
	cout << "- This function will only run ONCE at first launch of the program\n  and can not be run again unless the program is closed and re-opened" << "\n";
	cout << "- Press 1 to run this function, anything else to not" << "\n";
	int a = int(_getch() - 48);
	if (a != 1) return false;
	
	FILE* file_pointer;
	fopen_s(&file_pointer, loader_file, "r");
	if (file_pointer == NULL)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't open file" << "\n";
		cout << "File name required: " << loader_file << "\n";
		cout << "If you want to change the file name/address, it is located at main.cpp line 22-29" << "\n";
		return false;
	}

	///////////////////////////////////////
	int i = 0, num = 0, current_number_of_readers = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_readers) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount reader" << "\n";
		return false;
	}
	cout << current_number_of_readers << "\n";
	while ((num = fscanf_s(file_pointer, "%8[^,],%12[^,],%20[^,],%30[^,],%c,%10[^,],%75[^,],%100[^,],%10[^,],%10[^,],%4[^.].\n",
		list_of_readers[i].library_id, 9,
		list_of_readers[i].citizen_id, 13,
		list_of_readers[i].surname, 21,
		list_of_readers[i].name, 31,
		&list_of_readers[i].sex, 1,
		list_of_readers[i].date_of_birth, 11,
		list_of_readers[i].email, 76,
		list_of_readers[i].address, 101,
		list_of_readers[i].card_creation_date, 11,
		list_of_readers[i].card_expiration_date, 11,
		list_of_readers[i].fine, 5
	)) != EOF && i < current_number_of_readers - 1)
	{
		if (num != 11)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data reader" << "\n";
			cout << num << i << "\n";
			return false;
		}
		i++;
	}
	///////////////////////////////////////
	i = 0;
	num = 0;
	int current_number_of_books = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_books) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount book" << "\n";
		return false;
	}
	cout << current_number_of_books << "\n";
	while ((num = fscanf_s(file_pointer, "%13[^,],%100[^,],%50[^,],%50[^,],%4[^,],%30[^,],%4[^,],%4[^.].\n",
		list_of_book_titles[i].isbn, 14,
		list_of_book_titles[i].name, 101,
		list_of_book_titles[i].author, 51,
		list_of_book_titles[i].publisher, 51,
		list_of_book_titles[i].publish_year, 5,
		list_of_book_titles[i].genre, 31,
		list_of_book_titles[i].price, 5,
		list_of_book_titles[i].amount, 5
	)) != EOF && i < current_number_of_books - 1)
	{
		if (num != 8)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data book" << "\n";
			cout << num << " " << i << "\n";
			return false;
		}
		i++;
	}

	///////////////////////////////////////
	i = 0;
	num = 0;
	int current_number_of_forms = 0;
	if (fscanf_s(file_pointer, "%d\n", &current_number_of_forms) != 1)
	{
		cout << "Data failed to load! Closing program..." << "\n";
		cout << "Error: Can't read amount form" << "\n";
		return false;
	}
	cout << current_number_of_forms << "\n";
	while ((num = fscanf_s(file_pointer, "%8[^,],%8[^,],%10[^,],%10[^,],%13[^,],%13[^,],%13[^,],%c,%1[^,],%1[^,],%1[^.].\n",
		list_of_borrow_forms[i].form_id, 9,
		list_of_borrow_forms[i].borrower_id, 9,
		list_of_borrow_forms[i].borrow_date, 11,
		list_of_borrow_forms[i].expected_return_date, 11,
		list_of_borrow_forms[i].borrowed_books_isbn[0], 14,
		list_of_borrow_forms[i].borrowed_books_isbn[1], 14,
		list_of_borrow_forms[i].borrowed_books_isbn[2], 14,
		&list_of_borrow_forms[i].form_status, 1,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[0], 2,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[1], 2,
		list_of_borrow_forms[i].lost_borrowed_books_isbn[2], 2
	)) != EOF && i < current_number_of_forms - 1)
	{
		if (num != 11)
		{
			cout << "Data failed to load! Closing program..." << "\n";
			cout << "Error: Can't read data form" << "\n";
			cout << num << " " << i << "\n";
			return false;
		}
		i++;
	}
	fclose(file_pointer);
	return true;
}