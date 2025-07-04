#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid     = "SSID";
const char* password = "PASSWORD";

// Create a web server object that listens on port 80
WebServer server(80);

// HTML content for the index page 
const char* htmlIndex = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <title>ESP32 Hello World</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin-top: 50px; }
      h1 { color: #0055AA; }
    </style>
  </head>
  <body>
    <h1>Hello, world!</h1>
    <p>Your ESP32 is running a web server.</p>
  </body>
</html>
)rawliteral";

// Handler for the root path
void handleRoot() {
  server.send(200, "text/html", htmlIndex);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Connect to Wi-Fi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected!");

  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Define URLs and their handlers
  server.on("/", handleRoot);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
