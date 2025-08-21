//
//  our_doubles.h
//
//  Created by Pedro Guerreiro on 01/11/2018.
//  Copyright © 2018 Pedro Guerreiro. All rights reserved.
//

#ifndef our_doubles_h
#define our_doubles_h

double dbl_get(void);

void doubles_println_basic(const double *a, int n);
void doubles_println_special(const double *a, int n);
void doubles_fprint(FILE *f, const double *a, int n, const char *separator);
void doubles_fprintln(FILE *f, const double *a, int n, const char *separator);
void doubles_print(const double *a, int n, const char *separator);
void doubles_println(const double *a, int n, const char *separator);
void doubles_print_two(const double *a, const double *b, int n);
void doubles_printf(const char *fmt, const double *a, int n);
void doubles_printfln(const char *fmt, const double *a, int n);
void doubles_fprintf(FILE *f, const char *fmt, const double *a, int n);
void doubles_fprintfln(FILE *f, const char *fmt, const double *a, int n);
void doubles_print_two(const double *a, const double *b, int n);
void doubles_fprint_two(FILE *f, const double *a, const double *b, int n);

int doubles_get(double *a);
int doubles_get_until(double terminator, double *a);
int doubles_get_some(double *a, int n);
int doubles_get_two(double *a, double *b);

void doubles_clear(double *a, int n);
int doubles_id(double *a, int n);
int doubles_fill(double x, int n, double *a);
int doubles_range(double start, int n, double *a);

int doubles_copy(const double *a, int n, double *b);

int doubles_count(const double *a, int n, double x);
double doubles_sum(const double *a, int n);
double doubles_mean(const double *a, int n);
int doubles_remove(const double *a, int n, int x, double *b);
double doubles_max(const double *a, int n);
double doubles_min(const double *a, int n);
int doubles_argmax(const double *a, int n);
int doubles_argmin(const double *a, int n);
int doubles_indices(const double *a, int n, int x, int* b);
int doubles_find(const double *a, int n, double x);
int doubles_find_last(const double *a, int n, double x);
int doubles_nub(const double *a, int n, double *b);

int doubles_equal(const double *a, int n, const double *b, int m);

void unit_test_doubles_count(void);
void unit_test_doubles_sum(void);
void unit_test_doubles_remove(void);
void unit_test_doubles_max(void);
void unit_test_doubles_min(void);
void unit_test_doubles_argmax(void);
void unit_test_doubles_argmin(void);
void unit_test_doubles_indices(void);
void unit_test_doubles_find(void);
void unit_test_doubles_find_last(void);
void unit_test_ints_nub(void);

void unit_test_doubles_equal(void);

void unit_tests_our_doubles(void);

#endif