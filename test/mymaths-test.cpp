
#include <mymaths.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE ("add42 0", "[mymaths]") {
  const int input = 0;
  const int result = mymaths::add42(input);
  const int expected = 42;
  REQUIRE( result == expected );
}

TEST_CASE ("add42 1", "[mymaths]") {
  const int input = 1;
  const int result = mymaths::add42(input);
  const int expected = 43;
  REQUIRE( result == expected );
}

TEST_CASE ("add42 42", "[mymaths]") {
  const int input = 42;
  const int result = mymaths::add42(input);
  const int expected = 84;
  REQUIRE( result == expected );
}

