/*
 * Seeed_esp32-radio
 * esp32-c3 is too slow - chops up output - reduce sample rate?
 * esp32-s3 ???
 */
#include "Arduino.h"   
#include "WiFi.h"
#include "Audio.h"

#define I2S_DOUT      4 // 26  // connect to DAC pin DIN
#define I2S_BCLK      3 // 27  // connect to DAC pin BCK
#define I2S_LRC       2 // 25  // connect to DAC pin LCK

Audio audio;

const char* ssid =     "EVEEKO";
const char* password = "neeko58oh";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.println("Waiting for network ...");
      delay(1500);
    }
    Serial.println("Connected.");
    
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(21);
    audio.connecttohost("http://s1.knixx.fm/dein_webradio_64.aac"); // 64 kbp/s aac+
}

void loop() {
    audio.loop();
}

// optional
void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char *info){
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreaminfo(const char *info){
    Serial.print("streaminfo  ");Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}
void audio_eof_speech(const char *info){
    Serial.print("eof_speech  ");Serial.println(info);
}