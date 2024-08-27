#include <gtest/gtest.h>
#include "AlertInEmail.h"
#include "TemperatureAlert_checker.h"
#include "breach_detector.h" 
#include "alert_to_controller.h"
#include "cooling_config.h"

TEST(CheckAndAlertTest, SendToController) {
  battery_character batteryChar = {PASSIVE_COOLING, "Battery 1"};
  check_and_alert(TO_CONTROLLER, batteryChar, -1);
  check_and_alert(TO_CONTROLLER, batteryChar, 36);
  check_and_alert(TO_CONTROLLER, batteryChar, 25);
}

TEST(CheckAndAlertTest, SendToEmail) {
  battery_character batteryChar = {PASSIVE_COOLING, "Battery 1"};
  check_and_alert(TO_EMAIL, batteryChar, -1);
  check_and_alert(TO_EMAIL, batteryChar, 36);
  check_and_alert(TO_EMAIL, batteryChar, 25);
}

TEST(InferBreachTest, TemperatureTooLow) {
  EXPECT_EQ(infer_breach(9, 10, 35), TOO_LOW);
  EXPECT_EQ(infer_breach(-1, 0, 35), TOO_LOW);  
}

TEST(InferBreachTest, TemperatureTooHigh) {
  EXPECT_EQ(infer_breach(65, 0, 60), TOO_HIGH);
  EXPECT_EQ(infer_breach(40, 0, 39), TOO_HIGH);
}

TEST(InferBreachTest, TemperatureNormal) { 
  EXPECT_EQ(infer_breach(30, 0, 40), NORMAL);
  EXPECT_EQ(infer_breach(5, 0, 35), NORMAL);
  EXPECT_EQ(infer_breach(40, 0, 50), NORMAL);
}

TEST(ClassifyTemperatureBreachTest, PassiveCooling) {
  EXPECT_EQ(classify_temperature_breach(PASSIVE_COOLING, -1), TOO_LOW);
  EXPECT_EQ(classify_temperature_breach(PASSIVE_COOLING, 0), NORMAL);
  EXPECT_EQ(classify_temperature_breach(PASSIVE_COOLING, 35), NORMAL);
  EXPECT_EQ(classify_temperature_breach(PASSIVE_COOLING, 36), TOO_HIGH);
}

TEST(ClassifyTemperatureBreachTest, HighActiveCooling) {
  EXPECT_EQ(classify_temperature_breach(HI_ACTIVE_COOLING, -1), TOO_LOW);
  EXPECT_EQ(classify_temperature_breach(HI_ACTIVE_COOLING, 0), NORMAL);
  EXPECT_EQ(classify_temperature_breach(HI_ACTIVE_COOLING, 45), NORMAL);
  EXPECT_EQ(classify_temperature_breach(HI_ACTIVE_COOLING, 46), TOO_HIGH);
}

TEST(ClassifyTemperatureBreachTest, MedActiveCooling) {
  EXPECT_EQ(classify_temperature_breach(MED_ACTIVE_COOLING, -1), TOO_LOW);
  EXPECT_EQ(classify_temperature_breach(MED_ACTIVE_COOLING, 0), NORMAL);
  EXPECT_EQ(classify_temperature_breach(MED_ACTIVE_COOLING, 40), NORMAL);
  EXPECT_EQ(classify_temperature_breach(MED_ACTIVE_COOLING, 41), TOO_HIGH);
}


