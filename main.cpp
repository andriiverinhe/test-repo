#include <functional>
#include <iostream>
#include <vector>

#include "TestCandel.h"
#include "candle.h"

/*< Tests for the `body_contains` method >*/
bool test_body_contains_red_candle() {
  Candle redCandle(12, 15, 5, 10);
  bool result = true;

  if (redCandle.body_contains(11) == false) result = false;
  if (redCandle.body_contains(12) == false) result = false;
  if (redCandle.body_contains(10) == false) result = false;
  if (redCandle.body_contains(9) == true) result = false;
  if (redCandle.body_contains(13) == true) result = false;

  return result;
}

bool test_body_contains_green_candle() {
  Candle greenCandle(10, 15, 5, 12);
  bool result = true;

  if (greenCandle.body_contains(11) == false) result = false;
  if (greenCandle.body_contains(10) == false) result = false;
  if (greenCandle.body_contains(12) == false) result = false;
  if (greenCandle.body_contains(9) == true) result = false;
  if (greenCandle.body_contains(13) == true) result = false;

  return result;
}

bool test_body_contains_doji_candle() {
  Candle neutralCandle(10, 10, 5, 10);
  bool result = true;

  if (neutralCandle.body_contains(10) == false) result = false;
  if (neutralCandle.body_contains(9) == true) result = false;
  if (neutralCandle.body_contains(11) == true) result = false;

  return result;
}

/*< >*/

int main() {
  TestCandel tc;
  tc.initTests({test_body_contains_red_candle, test_body_contains_green_candle,
                test_body_contains_doji_candle});
  return tc.launchTests();
}
