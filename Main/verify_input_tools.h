#pragma once
#include <string>

using namespace std;

bool check_gmail_validity(char input[]);
bool check_if_input_is_pure_text(char input[]);
bool check_if_input_is_pure_number(char input[]);
bool check_birthday_validity(char input[]);
bool check_citizenID_validity(char input[]);
bool check_date_validity(char input[]);
bool check_if_no_special_characters(char input[]);
bool check_within_range(int input, int min, int max);
bool check_ISBN_validity(char input[], book_title list_of_book_titles[]);