#pragma once

#include <string>

using namespace std;

void view_list_of_books
(
	book_title list_of_books_titles[],
	int page_number
);
bool add_book
(
	book_title list_of_books_titles[],
	int max_amount_of_books,
	int current_amount_of_books
);
bool change_book_info
(
	book_title list_of_books_titles[]
);
bool delete_book_menu
(
	book_title list_of_books_titles[],
	borrowing_book_form list_of_borrow_forms[],
	int  current_amount_of_books
);
void find_book_menu
(
	book_title list_of_books_titles[]
);
int find_book
(
	book_title list_of_books_titles[],
	char input_isbn[],
	char input_name[]
);

