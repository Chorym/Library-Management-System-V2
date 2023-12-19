#pragma once
#include "prefab_type.h"

void get_system_time(char return_current_date[11], char return_current_time[6]);
void set_cursor_position(int x, int y);
int convert_date_to_day(char input[]);
int find_distance_between_2_dates(char date1[], char date2[]);
int convert_str_number_to_int_number(char input[]);
void display_reader_info
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int i
); 
void display_book_info
(
	book_title list_of_books_titles[],
	int i
);

void display_borrow_forms
(
	borrowing_book_form list_of_forms_for_borrowing[],
	int i
);
