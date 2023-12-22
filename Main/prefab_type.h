#pragma once

struct reader
{
	char library_id[9];
	char citizen_id[13];
	char surname[21];
	char name[31];
	char sex;
	char date_of_birth[11];
	char email[76];
	char address[101];
	char card_creation_date[11];
	char card_expiration_date[11];
	char fine[5];
};

struct book_title
{
	char isbn[14];
	char name[101];
	char author[51];
	char publisher[51];
	char publish_year[5];
	char genre[31];
	char price[5];
	char amount[5];
};

struct borrowing_book_form
{
	char form_id[9];
	char borrower_id[9];
	char borrow_date[11];
	char expected_return_date[11];
	char borrowed_books_isbn[3][14];
	char form_status;
	char lost_borrowed_books_isbn[3][2];
};

