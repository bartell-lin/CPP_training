add_test( BigNumberTest.mult /Users/bartell/SS/week2/Practice/build/hello_test [==[--gtest_filter=BigNumberTest.mult]==] --gtest_also_run_disabled_tests)
set_tests_properties( BigNumberTest.mult PROPERTIES WORKING_DIRECTORY /Users/bartell/SS/week2/Practice/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( BigNumberTest.overflow /Users/bartell/SS/week2/Practice/build/hello_test [==[--gtest_filter=BigNumberTest.overflow]==] --gtest_also_run_disabled_tests)
set_tests_properties( BigNumberTest.overflow PROPERTIES WORKING_DIRECTORY /Users/bartell/SS/week2/Practice/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( CalandarTest.cal /Users/bartell/SS/week2/Practice/build/hello_test [==[--gtest_filter=CalandarTest.cal]==] --gtest_also_run_disabled_tests)
set_tests_properties( CalandarTest.cal PROPERTIES WORKING_DIRECTORY /Users/bartell/SS/week2/Practice/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hello_test_TESTS BigNumberTest.mult BigNumberTest.overflow CalandarTest.cal)
