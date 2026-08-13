#include "esp_sleep.h"

#define POWER_CONTROL_PIN 4
#define SLEEP_DURATION_US (60ULL * 1000000ULL) // 1 dakika

void setup() {
  Serial.begin(115200);
  delay(200);

  gpio_hold_dis(GPIO_NUM_4);
  pinMode(POWER_CONTROL_PIN, OUTPUT);

  Serial.println("\n[TEST-OTA] Test Update  succeed");

  digitalWrite(POWER_CONTROL_PIN, HIGH);
  Serial.println("[TEST-OTA] PIN HIGH - AP+STA awake");
  delay(10000);

  digitalWrite(POWER_CONTROL_PIN, LOW);
  Serial.println("[TEST-OTA] PIN LOW - sleep mode");

  gpio_hold_en(GPIO_NUM_4);
  gpio_deep_sleep_hold_en();
  Serial.flush();

  esp_sleep_enable_timer_wakeup(SLEEP_DURATION_US);
  esp_deep_sleep_start();
}

void loop() {}