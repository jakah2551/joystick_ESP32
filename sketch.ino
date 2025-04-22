#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>
#include "function\function.h"

WebServer server(80);

const char* ssid = "ESP32_Controller";
const char* password = "12345678";
bool r=false;
char- command="ON"


void setup() {
    Serial.begin(115200);

    // Inizializza LittleFS
    if (!LittleFS.begin()) {
        Serial.println("Error initializing LittleFS");
        return;
    }

    // Access Point Wi-Fi
    WiFi.softAP(ssid, password);
    Serial.println("WiFi attivo: " + WiFi.softAPIP().toString());

    // Route per la homepage
    server.on("/", HTTP_GET, []() {
        File file = LittleFS.open("/index.html", "r");
        if (!file) {
        server.send(500, "text/plain", "File not found");
        return;
        }
        server.streamFile(file, "text/html");
        file.close();
    });

    // Route per i dati ricevuti
    server.on("/update", handleUpdate);

    server.begin();
    }

void loop() {
    server.handleClient();
}

void handleUpdate() {
    String type = server.arg("type");

    if (type == "joystick") {
        float x = server.arg("x").toFloat();
        float y = server.arg("y").toFloat();
        Serial.printf("Joystick: X=%.2f, Y=%.2f\n", x, y);
        command=(str)gestisciAngolo(x,y,r);
    } else if (type == "button") {
        String button = server.arg("button");
        int state = server.arg("state").toInt();

        if (button == "L1") {
            Serial.println(state ? "L1 pressed" : "L1 released");
            coomand="L1"
        } else if (button == "L2") {
            Serial.println(state ? "L2 pressed" : "L2 released");
            coomand="L2"
        } else if (button == "R1") {
            Serial.println(state ? "R1 pressed" : "R1 released");
            coomand="R1"
        } else if (button == "R2") {
            Serial.println(state ? "R2 pressed" : "R2 released");
            coomand="R2"
        }
    } else if (type == "switch") {
        String id = server.arg("id");
        int state = server.arg("state").toInt();
        Serial.printf("Switch %s: %s\n", id.c_str(), state ? "ON" : "OFF");

        // Puoi aggiungere logica per fare qualcosa in base allo stato del switch
        if (id == "switch1") {
            if (state == 1) {
                // Attiva tema rosso
                r=true;
                Serial.println("Race mode enabled");
            } else {
                // Disattiva tema rosso
                r=false;
                Serial.println("Race mode disabled");
            }
        } else if (id == "switch2") {
            if (state == 1) {
                command="SIT";
                Serial.println("Sitting mode enabled");
            } else {
                command="STUP";
                Serial.println("Sitting mode disabled");
            }
        }
    }

    server.send(200, "text/plain", "OK");
}




/*

Connettiti dallo smartphone al Wi-Fi ESP32_Controller
Apri il browser su 192.168.4.1

*/




//manca ancora la gestione del joystick sia html che back