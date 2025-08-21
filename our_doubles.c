//
//  our_doubles.c
//
//  Created by Pedro Guerreiro on 01/11/2018.
//  Copyright © 2018 Pedro Guerreiro. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "our_ints.h"
#include "our_doubles.h"

// Operations on individual doubles

// Read one double from the console and return it.
double dbl_get(void)
{
  double result;
  scanf("%lf", &result);
  return result;
}

// ------------------

// Operations on arrays of doubles

// Write array elements in a line, separated by a space.
void doubles_println_basic(const double *a, int n)
{
  if (n > 0)
  {
    printf("%g", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf(" %g", a[i]);
  }
  printf("\n");
}

// Like doubles_println_basic, but empty arrays are represented
// by a line with an asterisk.
void doubles_println_special(const double *a, int n)
{
  if (n == 0)
    printf("*\n");
  else
    doubles_println_basic(a, n);
}

// Write array elements on file, separated by separator.
void doubles_fprint(FILE *f, const double *a, int n, const char *separator)
{
  if (n > 0)
  {
    fprintf(f, "%g", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      fprintf(f, "%s%g", separator, a[i]);
  }
}

// Same as `doubles_fprint` followed by newline.
void doubles_fprintln(FILE *f, const double *a, int n, const char *separator)
{
  doubles_fprint(f, a, n, separator);
  fprintf(f, "\n");
}

// Write array elements on console, separated by separator.
void doubles_print(const double *a, int n, const char *separator)
{
  doubles_fprint(stdout, a, n, separator);
}

// Same as `doubles_print` followed by newline
void doubles_println(const double *a, int n, const char *separator)
{
  doubles_fprintln(stdout, a, n, separator);
}

// Write array elements on file, each with given format.
void doubles_fprintf(FILE *f, const char *fmt, const double *a, int n)
{
  for (int i = 0; i < n; i++)
    fprintf(f, fmt, a[i]);
}

// Write array elements on file, each with given format, and then change line.
void doubles_fprintfln(FILE *f, const char *fmt, const double *a, int n)
{
  doubles_fprintf(f, fmt, a, n);
  fprintf(f, "\n");
}

// Write array elements on console, each with given format.
void doubles_printf(const char *fmt, const double *a, int n)
{
  doubles_fprintf(stdout, fmt, a, n);
}

// Write array elements on console, each with given format, and then change line.
void doubles_printfln(const char *fmt, const double *a, int n)
{
  doubles_fprintfln(stdout, fmt, a, n);
}

// Write two arrays on file, one element of each array per line,
// separated by one space.
void doubles_fprint_two(FILE* f, const double *a, const double *b, int n)
{
  for (int i = 0; i < n; i++)
    fprintf(f, "%g %g\n", a[i], b[i]);
}

// Write two arrays, one element of each array per line,
// separated by one space.
void doubles_print_two(const double *a, const double *b, int n)
{
  doubles_fprint_two(stdout, a, b, n);
}

// Read array elements until no more items exists for reading.
int doubles_get(double *a)
{
  int result = 0;
  double x;
  while (scanf("%lf", &x) != EOF)
    a[result++] = x;
  return result;
}

// Read array elements until a terminator value is read
// or until no more items exist for reading.
// The terminator is NOT read into the array.
int doubles_get_until(double terminator, double *a)
{
  int result = 0;
  double x;
  while (scanf("%lf", &x) != EOF && x != terminator)
    a[result++] = x;
  return result;
}

// Read at most `n` array elements
// or until no more items exist for reading, whichever happens first.
int doubles_get_some(double *a, int n)
{
  int result = 0;
  double x;
  while (result < n && scanf("%lf", &x) != EOF)
    a[result++] = x;
  return result;
}

// Read two arrays in parallel, until EOF.
int doubles_get_two(double *a, double *b)
{
  int result = 0;
  double x, y;
  while (scanf("%lf%lf", &x, &y) != EOF)
  {
    a[result] = x;
    b[result] = y;
    result++;
  }
  return result;
}

// ---------------

// Set the n first elements to zero.
void doubles_clear(double *a, int n)
{
  memset(a, 0, n * sizeof(double));
}

// Build an array `a` with `n` elements where `a[i]` is `i`.
int doubles_id(double *a, int n)
{
  for (int i = 0; i < n; i++)
    a[i] = (double)i;
  return n;
}

// Build an array `a` with `n` elements where all elements are `x`.
int doubles_fill(double x, int n, double *a)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    a[result++] = x;
  assert(result == n);
  return result;
}

// The first `n` elements of `a` will have value `x`, `x+1`, ... `x+(n-1)`.
int doubles_range(double start, int n, double *a)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    a[result++] = start+i;
  assert(result == n);
  return result;
}

// Copy array `a` to array `b`.
int doubles_copy(const double *a, int n, double *b)
{
  if (n < 0)
    n = 0;
  memmove(b, a, n * sizeof(double));  // Note: 3rd arg is unsigned.
  return n;
}

// How many elements of `a` have value `x`?
int doubles_count(const double *a, int n, double x)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      result++;
  return result;
}

void unit_test_doubles_count(void)
{
  double a1[16] = {6,7,1,8, 9,3,3,5, 6,7,3,9, 6,1,1,1};
  assert(doubles_count(a1, 16, 1.0) == 4);
  assert(doubles_count(a1, 16, 9.0) == 2);
  assert(doubles_count(a1, 16, 2.0) == 0);
  assert(doubles_count(a1, 8, 1.0) == 1);
  assert(doubles_count(a1, 8, 2.0) == 0);
  assert(doubles_count(a1, 0, 6.0) == 0);
}

// Sum of all elements of the array.
double doubles_sum(const double *a, int n)
{
  double result = 0;
  for (int i = 0; i < n; i++)
    result += a[i];
  return result;
}

void unit_test_doubles_sum(void)
{
  double a1[8] = {6,7,1,8, 9,3,3,5};
  assert(doubles_sum(a1, 8) == 42.0);
  assert(doubles_sum(a1, 4) == 22.0);
  assert(doubles_sum(a1, 2) == 13.0);
  assert(doubles_sum(a1, 1) == 6.0);
  assert(doubles_sum(a1, 0) == 0.0);
  double a2[10] = {1,5,9,13, 17,21,25,29, 33,37};
  assert(doubles_sum(a2, 10) == 190.0);
  assert(doubles_sum(a2, 5) == 45.0);
}

// Average of the array
double doubles_mean(const double *a, int n)
{
  assert(n > 0);
  return doubles_sum(a, n) / n;
}

// Array `b` has all elements of `a`, except those with value `x`, in the
// same order.
int doubles_remove(const double *a, int n, int x, double *b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != x)
      b[result++] = a[i];
  return result;
}

void unit_test_doubles_remove(void)
{
  double a[5] = {6,7,1,8,7};
  double b1[5];
  int m1 = doubles_remove(a, 5, 7.0, b1);
  double c1[3] = {6,1,8};
  assert(doubles_equal(b1, m1, c1, 3));
  double b2[5];
  int m2 = doubles_remove(a, 5, 6.0, b2);
  double c2[4] = {7,1,8,7};
  assert(doubles_equal(b2, m2, c2, 4));
  double b3[5];
  double m3 = doubles_remove(a, 5, 3.0, b3);
  assert(doubles_equal(b3, m3, a, 5));
  double b4[5];
  double m4 = doubles_remove(a, 0, 7.0, b4);
  assert(m4 == 0);
 }

// Max value of non-empty array.
double doubles_max(const double *a, int n)
{
  assert(n > 0);
  double result = a[0];
  for (int i = 1; i < n; i++)  // i = 1
    if (result < a[i])
      result = a[i];
  return result;
}

void unit_test_doubles_max(void)
{
  double a1[16] = {6,7,3,8, 9,3,3,5, 6,7,3,9, 6,1,8,3};
  assert(doubles_max(a1, 16) == 9.0);
  assert(doubles_max(a1, 4) == 8.0);
  assert(doubles_max(a1, 1) == 6.0);
  double a2[10] = {32,67,81,23, 27,12,90,13, 75,13};
  assert(doubles_max(a2, 10) == 90.0);
  assert(doubles_max(a2, 6) == 81.0);
  double a3[5] = {715,318,914,422,313};
  assert(doubles_max(a3, 5) == 914.0);
  double a4[5] = {-2,0,2,-9,3};
  assert(doubles_max(a4, 5) == 3.0);
  double a5[5] = {-7,-3,-1,-7,-3};
  assert(doubles_max(a5, 5) == -1.0);
}

// Min value of non-empty array.
double doubles_min(const double *a, int n)
{
  assert(n > 0);
  double result = a[0];
  for (int i = 0; i < n; i++)
    if (result > a[i])
      result = a[i];
  return result;
}

void unit_test_doubles_min(void)
{
  double a1[16] = {6,7,3,8, 9,3,3,5, 6,7,3,9, 6,1,8,3};
  assert(doubles_min(a1, 16) == 1.0);
  assert(doubles_min(a1, 4) == 3.0);
  assert(doubles_min(a1, 1) == 6.0);
  double a2[10] = {32,67,81,25, 27,42,90,13, 75,13};
  assert(doubles_min(a2, 10) == 13.0);
  assert(doubles_min(a2, 6) == 25.0);
  double a3[5] = {715,318,914,422,313};
  assert(doubles_min(a3, 5) == 313.0);
  double a4[5] = {-2,0,2,-9,3};
  assert(doubles_min(a4, 5) == -9.0);
  double a5[5] = {-7,-3,-0,-7,13};
  assert(doubles_min(a5, 5) == -7.0);
}

// Index of first ocurrence of the max value in an non-empty array.
int doubles_argmax(const double *a, int n)
{
  assert(n > 0);
  int result = 0;
  double m = a[0];
  for (int i = 1; i < n; i++)   // i = 1
    if (m < a[i])
      m = a[result = i];
  return result;
}

void unit_test_doubles_argmax(void)
{
  double a1[16] = {6,7,3,8, 9,3,3,5, 6,7,3,9, 6,1,8,3};
  assert(doubles_argmax(a1, 16) == 4);
  assert(doubles_argmax(a1, 4) == 3);
  assert(doubles_argmax(a1, 1) == 0);
  double a2[10] = {32,67,81,23, 27,12,90,13, 75,13};
  assert(doubles_argmax(a2, 10) == 6);
  assert(doubles_argmax(a2, 6) == 2);
}

// Index of first ocurrence of the min value in na non-empty array.
int doubles_argmin(const double *a, int n)
{
  assert(n > 0);
  int result = 0;
  double m = a[0];
  for (int i = 1; i < n; i++)   // i = 1
    if (m > a[i])
      m = a[result = i];
  return result;
}

void unit_test_doubles_argmin(void)
{
  double a1[16] = {6,7,3,8, 9,3,3,5, 6,7,3,9, 6,1,8,3};
  assert(doubles_argmin(a1, 16) == 13);
  assert(doubles_argmin(a1, 4) == 2);
  assert(doubles_argmin(a1, 1) == 0);
  double a2[10] = {32,67,81,23, 27,12,90,13, 75,13};
  assert(doubles_argmin(a2, 10) == 5);
  assert(doubles_argmin(a2, 6) == 5);
}

// Array of the positions of `x` in `a`.
int doubles_indices(const double *a, int n, int x, int* b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      b[result++] = i;
  return result;
}

void unit_test_doubles_indices(void)
{
  double a1[16] = {1,5,9,13, 5,5,7,3, 9,12,16,12, 1,1,12,5};
  int b11[16];
  int m11 = doubles_indices(a1, 16, 5, b11);
  int c11[4] = {1,4,5,15};
  assert(ints_equal(b11, m11, c11, 4));
  int b12[16];
  int m12 = doubles_indices(a1, 16, 1, b12);
  int c12[4] = {0, 12, 13};
  assert(ints_equal(b12, m12, c12, 3));
  int b13[16];
  int m13 = doubles_indices(a1, 16, 3, b13);
  assert(m13 == 1 && b13[0] == 7);
  int b14[16];
  int m14 = doubles_indices(a1, 16, 8, b14);
  assert(m14 == 0);
  int b15[16];
  int m15 = doubles_indices(a1, 0, 5, b15);
  assert(m15 == 0);

  double a2[5] = {4,4,4,4,4};
  int b21[5];
  int m21 = doubles_indices(a2, 6, 4.0, b21);
  int c21[5] = {0,1,2,3,4};
  assert(ints_equal(b21, m21, c21, 5));
  int b22[5];
  int m22 = doubles_indices(a2, 6, 5.0, b22);
  assert(m22 == 0);
}

// Index of the first occurrence of `x` in `a` or -1 if it does not occur.
int doubles_find(const double *a, int n, double x)
{
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return -1;
}

void unit_test_doubles_find(void)
{
  double a[] = {9,5,6,6, 5,7,5,3};
  assert(doubles_find(a, 8, 9.0) == 0);
  assert(doubles_find(a, 8, 5.0) == 1);
  assert(doubles_find(a, 8, 6.0) == 2);
  assert(doubles_find(a, 8, 7.0) == 5);
  assert(doubles_find(a, 8, 3.0) == 7);
  assert(doubles_find(a, 8, 2.0) == -1);
  assert(doubles_find(a, 4, 7.0) == -1);
  assert(doubles_find(a, 4, 5.0) == 1);
  assert(doubles_find(a, 0, 9.0) == -1);
  assert(doubles_find(a, 0, 4.0) == -1);
  double b[] = {3,3,3,3};
  assert(doubles_find(b, 4, 3.0) == 0);
  assert(doubles_find(b, 4, 5.0) == -1);
}

// Index of the last occurrence of `x` in `a` or -1 if it does not occur.
int doubles_find_last(const double *a, int n, double x)
{
  int result = n-1;
  while (result >= 0 && a[result] != x)
    result--;
  return result;
}

void unit_test_doubles_find_last(void)
{
  double a[8] = {9,5,6,6, 5,7,5,3};
  assert(doubles_find_last(a, 8, 9) == 0);
  assert(doubles_find_last(a, 8, 5) == 6);
  assert(doubles_find_last(a, 8, 6) == 3);
  assert(doubles_find_last(a, 8, 7) == 5);
  assert(doubles_find_last(a, 8, 3) == 7);
  assert(doubles_find_last(a, 8, 2) == -1);
  assert(doubles_find_last(a, 4, 7) == -1);
  assert(doubles_find_last(a, 4, 5) == 1);
  assert(doubles_find_last(a, 0, 9) == -1);
  assert(doubles_find_last(a, 0, 4) == -1);
  double b[4] = {3,3,3,3};
  assert(doubles_find_last(b, 4, 3) == 3);
  assert(doubles_find_last(b, 4, 5) == -1);
}

// Array `b` shall contain the first ocurrence of each element of array `a`,
// in the same order.
int doubles_nub(const double *a, int n, double *b)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (doubles_find(b, result, a[i]) == -1)
      b[result++] = a[i];
  return result;
}

void unit_test_doubles_nub(void)
{
  double a1[12] = {6,2,6,9, 4,2,9,9, 9,2,1,2};
  double b1[12];
  int m1 = doubles_nub(a1, 12, b1);
  double z1[5] = {6,2,9,4,1};
  assert(doubles_equal(b1, m1, z1, 5));

  double a2[6] = {1,2,3,3,2,1};
  double b2[6];
  int m2 = doubles_nub(a2, 6, b2);
  double z2[3] = {1,2,3};
  assert(doubles_equal(b2, m2, z2, 3));

  double a3[5] = {8,8,8,8,8};
  double b3[5];
  int m3 = doubles_nub(a3, 5, b3);
  assert(m3 == 1 && b3[0] == 8);
}

// ---------------

// Are the two arrays equal?
int doubles_equal(const double *a, int n, const double *b, int m)
{
  int result = n == m;
  int i = 0;
  while (result && i < n)
    if (a[i] != b[i])
      result = 0;
    else
      i++;
  return result;
}

void unit_test_doubles_equal(void)
{
  double a[] = {7, 4, 1, 5};
  double b[] = {7, 4, 2, 7, 5};
  double c[] = {4, 1, 5, 7};
  double d[] = {4, 1, 5, 8};
  assert(doubles_equal(a, 4, a, 4));
  assert(doubles_equal(a, 2, b, 2));
  assert(doubles_equal(c, 3, d, 3));
  assert(doubles_equal(a, 0, c, 0));
  assert(!doubles_equal(a, 3, c, 2));
  assert(!doubles_equal(a, 4, b, 5));
  assert(!doubles_equal(c, 4, d, 4));
  assert(!doubles_equal(a, 3, b, 3));
}

void unit_tests_our_doubles(void)
{
  unit_test_doubles_count();
  unit_test_doubles_sum();
  unit_test_doubles_remove();
  unit_test_doubles_max();
  unit_test_doubles_min();
  unit_test_doubles_argmax();
  unit_test_doubles_argmin();
  unit_test_doubles_indices();
  unit_test_doubles_find();
  unit_test_doubles_find_last();
  unit_test_doubles_nub();
  unit_test_doubles_equal();
}