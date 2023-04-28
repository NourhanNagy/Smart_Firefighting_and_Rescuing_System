#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif
// Provide the token generation process info.
#include <addons/TokenHelper.h>
// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>
 #include <HardwareSerial.h>
HardwareSerial SerialPort(0); // use UART0

/* 1. Define the WiFi credentials */
#define WIFI_SSID "LINKDSL-FML007"
#define WIFI_PASSWORD "Johannes@Copen41"

// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyC_Nxkbdq0ErvLwTY9S988H9zXuoIbsjow"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://fir-system1-e1002-default-rtdb.firebaseio.com/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "powerrangers@gmail.com"
#define USER_PASSWORD "powerrangers"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;
 int fire = 0 ;
int human = 0;
 int pump = 0;
 int quad = 0;
 int system_status = 0;
void setup()
{

Serial.begin(9600); // Initialize serial communication at 9600 bits per second
SerialPort.begin(115200, SERIAL_8N1, 16, 17);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
config.token_status_callback = tokenStatusCallback;   
  Firebase.begin(&config, &auth);

  // Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);
  /* Assign the callback function for the long running token generation task */     

}
void Fire (){
   if (SerialPort.available() > 0) { // Check if there is any data available
   fire = SerialPort.read(); // Read the next byte of data
    Serial.print(fire); // Print the received character
 Serial.printf("Set Int... %s\n", Firebase.setInt(fbdo, F("/Rooms/01/fire"), fire) ? "ok" : fbdo.errorReason().c_str());
 delay (10000);
  }
else {
  Serial.print("NO UART SIGNAL");
}  }
  
 void Human (){
if (SerialPort.available() > 0) { // Check if there is any data available
   human = SerialPort.read(); // Read the next byte of data
    Serial.print(human); // Print the received character   
  Serial.printf("Set Int... %s\n", Firebase.setInt(fbdo, F("/Rooms/01/human"), human) ? "ok" : fbdo.errorReason().c_str());} 
else {
  Serial.print("NO UART SIGNAL");
}}
 void Quad(){
if (SerialPort.available() > 0) { // Check if there is any data available
   quad = SerialPort.read(); // Read the next byte of data
    Serial.print(quad); // Print the received character   
  Serial.printf("Set Int... %s\n", Firebase.setInt(fbdo, F("/Rooms/01/quad"), quad) ? "ok" : fbdo.errorReason().c_str());} 
 }
void Pump(){
  if (SerialPort.available() > 0) { // Check if there is any data available
   pump = SerialPort.read(); // Read the next byte of data
    Serial.print(pump); // Print the received character   
  Serial.printf("Set Int... %s\n", Firebase.setInt(fbdo, F("/Rooms/01/pump"), pump) ? "ok" : fbdo.errorReason().c_str());}  
 }
 void SystemStatus(){
if (SerialPort.available() > 0) { // Check if there is any data available
   system_status = SerialPort.read(); // Read the next byte of data
    Serial.print(system_status); // Print the received character   
  Serial.printf("Set Int... %s\n", Firebase.setInt(fbdo, F("/Rooms/01/system_status"), system_status) ? "ok" : fbdo.errorReason().c_str());} 
//Serial.printf("Get Int... %s\n", Firebase.getInt(fbdo, F("/Rooms/01/system_status")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
}
void ManualOperation () {
if (Firebase.getInt(fbdo, F("/Rooms/01/man_op"))){
Serial.printf("Get Int... %s\n", Firebase.getInt(fbdo, F("/Rooms/01/man_op")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
  
   // Serial.print(); // Print the received character  
  SerialPort.write(Firebase.getInt(fbdo, F("/Rooms/01/man_op"))); // Send each character of the text
 } }
// void ManualOperation () {
//   int data = Firebase.getInt(fbdo, F("/Rooms/01/man_op")); // Read data from Firebase
//   if (data) {
//     Serial.print("Data: ");
//     Serial.println(data);
//     SerialPort.write("1");// Convert data to character and send to STM32
//   }
// }
void ManualQuad () {
  if (Firebase.getInt(fbdo, F("/Rooms/01/man_quad"))){
Serial.printf("Get Int... %s\n", Firebase.getInt(fbdo, F("/Rooms/01/man_quad")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
  
   // Serial.print(); // Print the received character  
  SerialPort.write(Firebase.getInt(fbdo, F("/Rooms/01/man_quad"))); // Send each character of the text
 }
}
 void ManualPump () {
   if (Firebase.getInt(fbdo, F("/Rooms/01/man_pump"))){
Serial.printf("Get Int... %s\n", Firebase.getInt(fbdo, F("/Rooms/01/man_pump")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
   // Serial.print(); // Print the received character  
  SerialPort.write(Firebase.getInt(fbdo, F("/Rooms/01/man_pump"))); // Send each character of the text
 }}
//  void getSystemStatus () {
//    if (Firebase.getInt(fbdo, F("/Rooms/01/getSystemStatus"))){
// Serial.printf("Get Int... %s\n", Firebase.getInt(fbdo, F("/Rooms/01/getSystemStatus")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
//    // Serial.print(); // Print the received character  
//   SerialPort.write(Firebase.getInt(fbdo, F("/Rooms/01/getSystemStatus"))); // Send each character of the text
//  }}
void Manual () {
if (SerialPort.available()) { // Check if there is any data available
  
 String  manual = SerialPort.read(); 
 if (manual == "rr" ) {
     ManualOperation ();  
  
          }
     else if (manual== "xc" ) {
       ManualQuad(); 
        }
     else if(manual == "ab" ) {
       
       ManualPump();
       }
  else {
    
        //Serial.print(manual);
         Serial.print("Don't Send anything");
       }
     
} } 


void loop() {
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  { 
    sendDataPrevMillis = millis();
     Fire();
    delay (1500);
     Human ();
    delay (1500);
     Quad();
     delay (1500);
      Pump();
     delay (1500);
      SystemStatus();
      delay (1500);
    Manual();
          delay (1500);
    //getSystemStatus ();
   // RoomID(); 
 // ManualQuad(); 
   FirebaseJson json;
    count++;  
    }
}
