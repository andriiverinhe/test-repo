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

/*<  >*/

int main() {
  TestCandel tc;
  tc.initTests({test_body_contains_red_candle, test_body_contains_green_candle,
                test_body_contains_doji_candle, test_contains_within_range,
                test_contains_below_range, test_contains_above_range});
  return tc.launchTests();
}
