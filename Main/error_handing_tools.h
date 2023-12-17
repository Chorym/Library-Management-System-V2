#pragma once

void handle_add_reader_error(int error_case);
void handle_fix_reader_error(int error_case);
void handle_find_reader_error(int error_case);

void handle_add_book_error(int error_case);
void handle_find_book_error(int error_case);
void handle_fix_book_error(int error_case);

void handle_add_form_error(int error_case, int i);
void handle_return_form_error(int error_case);
