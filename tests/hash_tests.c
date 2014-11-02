#include <check.h>
#include "hash.h"

#include <stdlib.h>

void 
setup()
{
  hash_init();
}

void
cleanup()
{
}

START_TEST(hash_new_WhenCalledWithNameAndLenReturnsHash)
{
  Hash *h = hash_new("Test hash", HASHLEN);

  ck_assert(h != NULL);
  ck_assert(h->Name != NULL);
  ck_assert_str_eq(h->Name, "Test hash");
}
END_TEST

START_TEST(hash_new_WhenCalledWithNullNameAndLenReturnsHash)
{
  Hash *h = hash_new(NULL, HASHLEN);

  ck_assert(h != NULL);
}
END_TEST

START_TEST(hash_new_WhenCalledWithZeroLenReturnsNull)
{
  Hash *h = hash_new("Fail", 0);

  ck_assert(h == NULL);
}
END_TEST

Suite *
hash_suite()
{
  Suite  *s;
  TCase *tcCore;
  
  s = suite_create("Hash");

  tcCore = tcase_create("Core");

  tcase_add_unchecked_fixture(tcCore, setup, cleanup);
  tcase_add_test(tcCore, hash_new_WhenCalledWithNameAndLenReturnsHash);
  tcase_add_test(tcCore, hash_new_WhenCalledWithNullNameAndLenReturnsHash);
  tcase_add_test(tcCore, hash_new_WhenCalledWithZeroLenReturnsNull);
  suite_add_tcase(s, tcCore);

  return s;
}

int 
main()
{
  int numberFailed;
  Suite *s;
  SRunner *sr;

  s = hash_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
