#include <WiFi.h>
#include <M5StickC.h>
#include <PinButton.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 27

#define LED_BUILTIN 10

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 5, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

void setupmatrix() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setTextColor(0);
  matrix.setBrightness(30);
  matrix.fillScreen(matrix.Color(0,0,0));
  }

int tnlen = 1; //LET THIS BE - FOR VMIX RECONNECTION

Preferences preferences;

//DON'T CHANGE THESE VARIABLES, YOU CAN CHANGE THEM IN THE WEB UI
String WIFI_SSID = "";
String WIFI_PASS = "";
String VMIX_IP = "";
String M_TALLY = "";
int VMIX_PORT = 8099; //USES THE TCP API PORT, THIS IS FIXED IN VMIX
int TALLY_NR = 1;
int BRIGHTNESS = 12; //100%
int CONN_INT = 10; //THIS IS HOW LONG THE M5 WILL WAIT BEFORE RECONNECTING TO VMIX IF THE CONNECTION IS LOST. SET TO 0 TO DISABLE
