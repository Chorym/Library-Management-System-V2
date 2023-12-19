#pragma once
#include "prefab_type.h"

void view_list_of_reader
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[],
	int  page_number
);

bool add_reader
(
	reader list_of_readers[],
	int  current_amount_of_reader,
	int  max_amount_of_reader
);

bool change_reader_info
(
	reader list_of_readers[]
);

bool delete_reader_menu
(
	reader list_of_readers[],
	int  current_amount_of_reader
);

void find_reader_menu
(
	reader list_of_readers[],
	borrowing_book_form list_of_forms_for_borrowing[]
);

int find_reader
(
	reader list_of_readers[],
	char input_id[],
	char input_citizen_id[],
	char input_name[]
);
