/**************************************************************************/
/*!
    @file     Bridge.h
    @author   M. Fegerl (Sensate Digital Solutions GmbH)
    @license  GPL (see LICENSE file)
    The Sensate ESP8266 firmware is used to connect ESP8266 based hardware 
    with the Sensate Cloud and the Sensate apps.

    ----> https://www.sensate.io

    SOURCE: https://github.com/sensate-io/firmware-esp8266.git

    @section  HISTORY
    v33 - Added Digital Sensor Switch Support
    v32 - Added MQTT Support!
    v29 - First Public Release
*/
/**************************************************************************/

#include <Esp.h>
#include <EEPROM.h>

#ifndef _Bridge_h_
#define _Bridge_h_

#include "StateHelper.h"
#include "UUID.h"
#include "../communication/WiFiManager.h"
#include "../communication/MQTT.h"
#include "../input/Sensor.h"
#include "../input/analog/SensorAnalogue.h"
#include "../input/SensorDigitalSwitch.h"
#include "../input/i2c/Ads1x15.h"
#include "../input/i2c/SensorBMx280.h"
#include "../input/i2c/SensorBME680.h"
#include "../input/i2c/SensorMax44009.h"
#include "../input/i2c/SensorBH1750.h"
#include "../input/onewire/SensorDHT.h"
#include "../input/onewire/SensorDallas.h"
#include "../output/display/DisplayOLED128.h"

bool registerBridge();
void restoreBridgeConfig();
void restart();

bool getBridgeConfig();
void configureBridge(JsonObject&);
void configureExpansionPort(int, JsonObject&);
void configurePort(int, JsonObject&);
void addSensor(Sensor *);
void loopSensor(int);
boolean postSensorData(Data* data[], int);
void checkStatus();
void trySleep(long);
void storeDisplayAndPowerConfig(boolean);
void doPowerSaving();
void doPowerSavingInit(boolean);
uint8_t translateGPIOPort(String);
void tryInitMQTT();

#endif