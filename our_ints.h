//
//  our_ints.h
//
//  Created by Pedro Guerreiro on 01/11/2018.
//  Copyright © 2018 Pedro Guerreiro. All rights reserved.
//

// 2021 Edition

#ifndef our_ints_h
#define our_ints_h

int int_get(void);

void ints_println_basic(const int *a, int n);
void ints_println_special(const int *a, int n);
void ints_fprint(FILE *f, const int *a, int n, const char *separator);
void ints_fprintln(FILE *f, const int *a, int n, const char *separator);
void ints_print(const int *a, int n, const char *separator);
void ints_println(const int *a, int n, const char *separator);
void ints_print_two(const int *a, const int *b, int n);
void ints_printf(const char *fmt, const int *a, int n);
void ints_printfln(const char *fmt, const int *a, int n);
void ints_fprintf(FILE *f, const char *fmt, const int *a, int n);
void ints_fprintfln(FILE *f, const char *fmt, const int *a, int n);

int ints_get(int *a);
int ints_get_until(int terminator, int *a);
int ints_get_some(int *a, int n);
int ints_get_two(int *a, int *b);

void ints_clear(int *a, int n);
int ints_id(int *a, int n);
int ints_fill(int x, int n, int *a);
int ints_range(int x, int n, int *a);

int ints_count(const int *a, int n, int x);
int ints_sum(const int *a, int n);
double ints_mean(const int *a, int n);
int ints_remove(const int *a, int n, int x, int *b);
int ints_max(const int *a, int n);
int ints_min(const int *a, int n);
int ints_argmax(const int *a, int n);
int ints_argmin(const int *a, int n);
int ints_indices(const int *a, int n, int x, int* b);
int ints_find(const int *a, int n, int x);
int ints_find_last(const int *a, int n, int x);
int ints_nub(const int *a, int n, int *b);

int ints_equal(const int *a, const int n, const int *b, int m);

void unit_test_ints_count(void);
void unit_test_ints_sum(void);
void unit_test_ints_remove(void);
void unit_test_ints_max(void);
void unit_test_ints_min(void);
void unit_test_ints_argmax(void);
void unit_test_ints_argmin(void);
void unit_test_ints_indices(void);
void unit_test_ints_find(void);
void unit_test_ints_find_last(void);
void unit_test_ints_nub(void);

void unit_test_ints_equal(void);

void our_ints_unit_tests(void);

#endif

