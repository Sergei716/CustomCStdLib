#include "s21_string_test.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_memchr(),   test_memcmp(),   test_memcpy(),
                              test_memset(),   test_strncat(),  test_strlen(),
                              test_to_upper(), test_to_lower(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Failed tests: %d\n", failed);

  return failed == 0 ? 0 : 1;
}