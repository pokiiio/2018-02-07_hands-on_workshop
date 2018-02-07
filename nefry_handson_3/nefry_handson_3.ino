#include <Nefry.h>
#include <HTTPClient.h> // HTTP-GETのために必要

void setup() {

}

void loop() {
  String trainDelayJson = getTrainDelayJson();

  if (/** 遅延してたら **/) {
    Nefry.setLed(255, 0, 0); // 赤く光らせる
  } else {
    Nefry.setLed(0, 0, 255); // 青く光らせる
  }

  Nefry.ndelay(30000); // 30秒待つ
}

String getTrainDelayJson() {
  String payload = ""; // 運行情報を保存しておく
  HTTPClient http; // HTTP-GETをするために必要な宣言
  int httpCode; // HTTP-GETの結果（int）を保存しておく

  // 運行情報のページにアクセス
  http.begin("http://rti-giken.jp/fhc/api/train_tetsudo/delay.json");

  // その結果を保存
  httpCode = http.GET();

  if (httpCode == HTTP_CODE_OK) {
    // 成功だったら、運行情報の文字列を取得して保存
    payload = http.getString();
    Nefry.println("接続成功");
    Nefry.println(payload);
  } else {
    // 失敗だったら、エラーコードをログに出力
    Nefry.println("接続失敗");
    Nefry.println(http.errorToString(httpCode));
  }

  return payload;
}

