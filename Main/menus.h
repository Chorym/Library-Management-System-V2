#pragma once
#include "prefab_type.h"

void reader_menu
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int max_reader_amount
);

void book_menu
(
	book_title list_of_books_titles[],
	borrowing_book_form list_of_borrow_forms[],
	int max_book_title_amount
);
		
void borrow_books_menu
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[]
);
		
void statistics
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[]
);