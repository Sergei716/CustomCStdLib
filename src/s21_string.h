#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <stdlib.h>

// string.h Types
typedef unsigned long s21_size_t;

#define BUFFER 1000

void *s21_memchr(const void *, int, s21_size_t);
int s21_memcmp(const void *, const void *, s21_size_t);
void *s21_memcpy(void *, const void *, s21_size_t);
void *s21_memset(void *, int, s21_size_t);
char *s21_strncat(char *, const char *, s21_size_t);
void *s21_to_upper(const char *);
void *s21_to_lower(const char *);
s21_size_t s21_strlen(const char *str);

#endif  // S21_STRING_H_
