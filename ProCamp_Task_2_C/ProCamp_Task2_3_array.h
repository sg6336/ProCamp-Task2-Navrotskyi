// Task2_3:
// Create on integer array library with functions 
// ar_push(), ar_find_first(), ar_remove().
// Array should be allocated dynamically.
// The arr_push() function adds a new element afer the last one;
// arr_find_first() returns the positive index of the first occurrence of
// the given element in the array or -1 if the number is not in the array;
// arr_remove() removes the element by it`s index.
// Order of elements in an array is not important.
/*
* void task2_3_main_array(); // main() for task2_3
* int arr_push(vec_int_t* v, int val); // function adds a new element val afer the last one in array v
* int vec_expand_(char** data, int* length, int* capacity, int memsz); // part of function arr_push()
* void ar_find_first(vec_int_t* v, int val, int* idx); // returns the positive index of the first occurrence of the given element in the array or -1 if the number is not in the array
* void ar_remove(vec_int_t* v, int val); // removes the element by val index in array v
* void vec_splice(vec_int_t* v, int start, int count); // splice array, part of function ar_remove()
* void vec_splice_(char** data, int* length, int* capacity, int memsz, int start, int count); // splice array, part of function vec_splice, need for ar_remove()
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vec_t(T)\
  struct { T *data; int length, capacity; }

#define vec_init(v)\
  memset((v), 0, sizeof(*(v)))

#define vec_deinit(v)\
  ( free((v)->data),\
    vec_init(v) ) 

#define vec_unpack_(v)\
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data) 

typedef vec_t(int) vec_int_t;

void task2_3_main_array(void);
int arr_push(vec_int_t*, int);
void ar_find_first(vec_int_t*, int, int*);
void ar_remove(vec_int_t*, int);

int vec_expand_(char** data, int* length, int* capacity, int memsz);
void vec_splice_(char** data, int* length, int* capacity, int memsz, int start, int count);
void vec_splice(vec_int_t*, int, int);