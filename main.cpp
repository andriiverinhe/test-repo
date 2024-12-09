#include <functional>
#include <iostream>
#include <vector>

#include "TestCandel.h"
#include "candle.h"

/*< Tests for the `body_contains` method >*/
bool test_body_contains_red_candle() {
  Candle c(12, 15, 5, 10);
  bool res = true;

  if (c.body_contains(11) == false) res = false;
  if (c.body_contains(12) == false) res = false;
  if (c.body_contains(10) == false) res = false;
  if (c.body_contains(9) == true) res = false;
  if (c.body_contains(13) == true) res = false;

  return res;
}

bool test_body_contains_green_candle() {
  Candle c(10, 15, 5, 12);
  bool res = true;

  if (c.body_contains(11) == false) res = false;
  if (c.body_contains(10) == false) res = false;
  if (c.body_contains(12) == false) res = false;
  if (c.body_contains(9) == true) res = false;
  if (c.body_contains(13) == true) res = false;

  return res;
}

bool test_body_contains_doji_candle() {
  Candle c(10, 10, 5, 10);
  bool res = true;

  if (c.body_contains(10) == false) res = false;
  if (c.body_contains(9) == true) res = false;
  if (c.body_contains(11) == true) res = false;

  return res;
}

/*< Tests for the `contains` method >*/
bool test_contains_within_range() {
  Candle c(10, 15, 5, 12);
  return c.contains(7);
}

bool test_contains_below_range() {
  Candle c(10, 15, 5, 12);
  return (c.contains(1) == false);
}

bool test_contains_above_range() {
  Candle c(10, 15, 5, 12);
  return (c.contains(20) == false);
}

/*< Tests for the `full_size` method >*/
bool test_full_size_1() {
  Candle c(10, 15, 5, 12);
  return (c.full_size() == 10);
}

bool test_full_size_2() {
  Candle c(10, 5, 15, 12);
  return (c.full_size() == 10);
}

bool test_full_size_3() {
  Candle c(10, 55, -45, 12);
  return (c.full_size() == 100);
}
/*< Tests for the `body_size` method >*/
bool test_body_size_1() {
  Candle c(5, 2, 18, 15);
  return (c.body_size() == 10);
}

bool test_body_size_2() {
  Candle c(15, 2, 18, 5);
  return (c.body_size() == 10);
}

bool test_body_size_3() {
  Candle c(55, 2, 18, -45);
  return (c.body_size() == 100);
}
/*< Tests for the `is_red` method >*/
bool test_is_red_1() {
  Candle c(10, 5, 15, 12);
  return (c.is_red() == false);
}

bool test_is_red_2() {
  Candle c(12, 5, 15, 10);
  return (c.is_red() == true);
}

bool test_is_red_3() {
  Candle c(12, 5, 15, 12);
  return (c.is_red() == false);
}
/*< Tests for the `is_green` method >*/


int main() {
  TestCandel tc;
  tc.initTests({test_body_contains_red_candle, test_body_contains_green_candle,
                test_body_contains_doji_candle, test_contains_within_range,
                test_contains_below_range, test_contains_above_range,
                test_full_size_1, test_full_size_2, test_full_size_3,
                test_body_size_1, test_body_size_2, test_body_size_3,
                test_is_red_1, test_is_red_2, test_is_red_3});
  return tc.launchTests();
}
