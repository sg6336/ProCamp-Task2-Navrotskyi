// Task2_3:
// Create on integer array library with functions 
// ar_push(), ar_find_first(), ar_remove().
// Array should be allocated dynamically.
// The arr_push() function adds a new element afer the last one;
// arr_find_first() returns the positive index of the first occurrence of
// the given element in the array or -1 if the number is not in the array;
// arr_remove() removes the element by it`s index.
// Order of elements in an array is not important.

#include "ProCamp_Task2_3_array.h"

#define test_section(desc)\
  do {\
    printf("--- %s\n", desc);\
  } while (0)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define test_assert(cond)\
  do {\
    int pass__ = cond;\
    printf("[%s] %s:%d: ", pass__ ? "PASS" : "FAIL", __FILENAME__, __LINE__);\
    printf((strlen(#cond) > 50 ? "%.47s...\n" : "%s\n"), #cond);\
    if (pass__) { pass_count++; } else { fail_count++; }\
  } while (0)

int pass_count = 0;
int fail_count = 0;

void task2_3_main_array()
{
	printf("Task2_3: an integer array library with functions \n");
	printf("Start \n\n");

	{
		test_section("arr_push");
		vec_int_t v;
		vec_init(&v);
		int i;
		for (i = 0; i < 1000; i++) arr_push(&v, i * 2);
		test_assert(v.data[1] == 2);
		test_assert(v.data[999] == 999 * 2);
		test_assert(arr_push(&v, 10) == 0);
		vec_deinit(&v);
	}

	{
		test_section("ar_find_first");
		vec_int_t v;
		vec_init(&v);
		int i;
		for (i = 0; i < 26; i++) arr_push(&v, 'a' + i);
		ar_find_first(&v, 'a', &i);
		test_assert(i == 0);
		ar_find_first(&v, 'z', &i);
		test_assert(i == 25);
		ar_find_first(&v, 'd', &i);
		test_assert(i == 3);
		ar_find_first(&v, '_', &i);
		test_assert(i == -1);
		vec_deinit(&v);
	}
	
	{
		test_section("ar_remove");
		vec_int_t v;
		vec_init(&v);
		int i;
		for (i = 0; i < 26; i++) arr_push(&v, 'a' + i);
		ar_remove(&v, '_');
		test_assert(v.length == 26);
		ar_remove(&v, 'c');
		test_assert(v.data[0] == 'a' && v.data[1] == 'b' &&
			v.data[2] == 'd' && v.data[3] == 'e');
		test_assert(v.length == 25);
		vec_deinit(&v);
	}
	
	printf("\n\n");
	printf("Task2_3: an integer array library with functions \n");
	printf("Stop \n\n");
}

int arr_push(vec_int_t* v, int val)
{
	return (vec_expand_(vec_unpack_(v)) ? -1 : ((v)->data[(v)->length++] = (val), 0), 0);
}

int vec_expand_(char** data, int* length, int* capacity, int memsz) 
{
	if (*length + 1 > *capacity) {
		void* ptr;
		int n = (*capacity == 0) ? 1 : *capacity << 1;
		ptr = realloc(*data, n * memsz);
		if (ptr == NULL) return -1;
		*data = ptr;
		*capacity = n;
	}
	return 0;
}

void ar_find_first(vec_int_t* v, int val, int* idx)
{
	do {
		for ((*idx) = 0; (*idx) < (v)->length; (*idx)++) {
			if ((v)->data[(*idx)] == (val))
				break;
		}
		if ((*idx) == (v)->length) (*idx) = -1;
	} while (0);
}

void ar_remove(vec_int_t* v, int val)
{
	do {
		int idx__;
		ar_find_first(v, val, &idx__);
		if (idx__ != -1) vec_splice(v, idx__, 1);
	} while (0);
}

void vec_splice(vec_int_t* v, int start, int count)
{
	(vec_splice_(vec_unpack_(v), start, count), (v)->length -= (count));
}

void vec_splice_(char** data, int* length, int* capacity, int memsz, int start, int count) 
{
	(void)capacity;
	memmove(*data + start * memsz,
		*data + (start + count) * memsz,
		(*length - start - count) * memsz);
}