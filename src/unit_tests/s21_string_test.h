#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memset(void);
Suite *test_strncat(void);
Suite *test_to_lower(void);
Suite *test_to_upper(void);

Suite *test_strlen(void);

#endif  // SRC_TESTS_ME_H
