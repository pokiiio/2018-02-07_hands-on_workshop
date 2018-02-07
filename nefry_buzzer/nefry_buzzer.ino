#include <Nefry.h>

#define BUZZER D2
#define BEAT 200

#define LEDC_CHANNEL_2     2
#define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     5000

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  tone(BUZZER, 311); // レ#
  delay(BEAT);

  tone(BUZZER, 370); // ファ#
  delay(BEAT);

  tone(BUZZER, 494); // シ
  delay(BEAT);

  tone(BUZZER, 466); // ラ#
  delay(BEAT);

  tone(BUZZER, 494); // シ
  delay(BEAT * 2);

  tone(BUZZER, 370); // ファ#
  delay(BEAT * 2);

  tone(BUZZER, 330); // ミ
  delay(BEAT);

  tone(BUZZER, 415); // ソ#
  delay(BEAT);

  tone(BUZZER, 554); // ド#
  delay(BEAT);

  tone(BUZZER, 494); // シ
  delay(BEAT);

  tone(BUZZER, 466); // ラ#
  delay(BEAT);

  tone(BUZZER, 415); // ソ#
  delay(BEAT);

  tone(BUZZER, 466); // ラ#
  delay(BEAT);

  tone(BUZZER, 370); // ファ#
  delay(BEAT);

  noTone(BUZZER);
  delay(BEAT / 2);

  tone(BUZZER, 370); // ファ#
  delay(BEAT);

  tone(BUZZER, 440); // ラ
  delay(BEAT);

  tone(BUZZER, 587); // レ
  delay(BEAT);

  tone(BUZZER, 554); // ド#
  delay(BEAT);

  tone(BUZZER, 587); // レ
  delay(BEAT * 2);

  tone(BUZZER, 440); // ラ
  delay(BEAT * 2);

  tone(BUZZER, 392); // ソ
  delay(BEAT);

  tone(BUZZER, 494); // シ
  delay(BEAT);

  tone(BUZZER, 659); // ミ
  delay(BEAT);

  tone(BUZZER, 587); // レ
  delay(BEAT);

  tone(BUZZER, 554); // ド#
  delay(BEAT);

  tone(BUZZER, 494); // シ
  delay(BEAT);

  tone(BUZZER, 554); // ド#
  delay(BEAT);

  tone(BUZZER, 440); // ラ
  delay(BEAT);

  tone(BUZZER, 587); // レ
  delay(BEAT);

  tone(BUZZER, 440); // ラ
  delay(BEAT);

  tone(BUZZER, 392); // ソ
  delay(BEAT);

  tone(BUZZER, 440); // ラ
  delay(BEAT);

  tone(BUZZER, 370); // ファ#
  delay(BEAT * 4);

  noTone(BUZZER);
  delay(3000);
}

// https://www.1ft-seabass.jp/memo/2017/12/24/nefrybt-grove-skeaker-melody/

void tone(int pin, int freq) {
  ledcSetup(LEDC_CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(pin, LEDC_CHANNEL_2);
  ledcWriteTone(LEDC_CHANNEL_2, freq);
}

void noTone(int pin)
{
  ledcWriteTone(LEDC_CHANNEL_2, 0.0);
}
