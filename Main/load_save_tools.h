#pragma once
#include "prefab_type.h"

//load all data
void load_all_readers(const char* file_name, reader list_of_readers[]);
void load_all_books(const char* file_name, book_title list_of_book_titles[]);
void load_all_borrow_forms(const char* file_name, borrowing_book_form list_of_borrow_forms[]);

//save all data
bool save_all_readers(const char* file_name, reader list_of_readers[]);
bool save_all_books(const char* file_name, book_title list_of_book_titles[]);
bool save_all_borrow_forms(const char* file_name, borrowing_book_form list_of_borrow_forms[]);

bool load_all_test_data
(
	const char* loader_file,
	reader list_of_readers[],
	book_title list_of_book_titles[],
	borrowing_book_form list_of_borrow_forms[]
);