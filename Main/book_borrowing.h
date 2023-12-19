#pragma once

void view_all_borrowings
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int page_number
);
bool borrow_books
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int current_amount_of_forms
);
bool return_books
(
	reader list_of_readers[],
	book_title list_of_books_titles[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int current_amount_of_forms
);
int find_form
(
	char input_id[],
	borrowing_book_form list_of_forms_for_borrowing[]
);