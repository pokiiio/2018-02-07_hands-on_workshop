#include <Nefry.h>
#include <HTTPClient.h> // HTTP-GETのために必要

void setup() {
  HTTPClient http; // HTTP-GETをするために必要な宣言
  int httpCode; // HTTP-GETの結果（int）を保存しておく

  // 運行情報のページにアクセス
  http.begin("http://rti-giken.jp/fhc/api/train_tetsudo/delay.json");

  String response = ""; // HTTP-GETのレスポンスを保存しておく変数

  // その結果を保存
  httpCode = http.GET();

  if (httpCode == HTTP_CODE_OK) {
    // 成功だったら、運行情報の文字列を取得して保存
    response = http.getString();
    Nefry.println("接続成功");
  } else {
    // 失敗
    Nefry.println("接続失敗");
  }
}

void loop() {

}
