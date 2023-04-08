#pragma once

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct __attribute__ ((packed)) sensorData_t {
                        uint8_t sensorNum;
                        int16_t sensorVal;
                        int16_t minVal;
                        int16_t maxVal;
                        int16_t recVal;
                    } sensorData_t;

typedef struct __attribute__ ((packed)) sensorDef_t {
                        uint8_t sensorNum;
                        uint8_t sensorType;
                        uint8_t sensorUnit;
                        uint8_t sensorPrefix;
                        int16_t range_min;
                        int16_t range_max;
                        int16_t normal_min;
                        int16_t normal_max;
                        uint8_t sensorHistory;
                        char sensorDesc[32];
                    } sensorDef_t;

typedef struct RDMSensor {
    sensorData_t sdata;
    sensorDef_t sdef;

} RDMSensor;


#define PREFIX_NONE 0x00// Multiply by 1
#define PREFIX_DECI 0x01// Multiply by 10-1
#define PREFIX_CENTI 0x02// Multiply by 10-2
#define PREFIX_MILLI 0x03// Multiply by 10-3
#define PREFIX_MICRO 0x04// Multiply by 10-6
#define PREFIX_NANO 0x05// Multiply by 10-9
#define PREFIX_PICO 0x06// Multiply by 10-12
#define PREFIX_FEMPTO 0x07// Multiply by 10-15
#define PREFIX_ATTO 0x08// Multiply by 10-18
#define PREFIX_ZEPTO 0x09// Multiply by 10-21
#define PREFIX_YOCTO 0x0A// Multiply by 10-24
#define PREFIX_DECA 0x11// Multiply by 10+1
#define PREFIX_HECTO 0x12// Multiply by 10+2
#define PREFIX_KILO 0x13// Multiply by 10+3
#define PREFIX_MEGA 0x14// Multiply by 10+6
#define PREFIX_GIGA 0x15// Multiply by 10+9
#define PREFIX_TERRA 0x16// Multiply by 10+12
#define PREFIX_PETA 0x17// Multiply by 10+15
#define PREFIX_EXA 0x18// Multiply by 10+18
#define PREFIX_ZETTA 0x19// Multiply by 10+21
#define PREFIX_YOTTA 0x1A// Multiply by 10+24

#define UNITS_NONE 0x00// CONTACTS
#define UNITS_CENTIGRADE 0x01// TEMPERATURE
#define UNITS_VOLTS_DC 0x02// VOLTAGE
#define UNITS_VOLTS_AC_PEAK 0x03// VOLTAGE
#define UNITS_VOLTS_AC_RMS 0x04// VOLTAGE
#define UNITS_AMPERE_DC 0x05// CURRENT
#define UNITS_AMPERE_AC_PEAK 0x06// CURRENT
#define UNITS_AMPERE_AC_RMS 0x07// CURRENT
#define UNITS_HERTZ 0x08// FREQUENCY / ANG_VEL
#define UNITS_OHM 0x09// RESISTANCE
#define UNITS_WATT 0x0A// POWER
#define UNITS_KILOGRAM 0x0B// MASS
#define UNITS_METERS 0x0C// LENGTH / POSITION
#define UNITS_METERS_SQUARED 0x0D// AREA
#define UNITS_METERS_CUBED 0x0E// VOLUME
#define UNITS_KILOGRAMMES_PER_METER_CUBED 0x0F// DENSITY
#define UNITS_METERS_PER_SECOND 0x10// VELOCITY
#define UNITS_METERS_PER_SECOND_SQUARED 0x11// ACCELERATION
#define UNITS_NEWTON 0x12// FORCE
#define UNITS_JOULE 0x13// ENERGY
#define UNITS_PASCAL 0x14// PRESSURE
#define UNITS_SECOND 0x15// TIME
#define UNITS_DEGREE 0x16// ANGLE
#define UNITS_STERADIAN 0x17// ANGLE
#define UNITS_CANDELA 0x18// LUMINOUS_INTENSITY
#define UNITS_LUMEN 0x19// LUMINOUS_FLUX
#define UNITS_LUX 0x1A// ILLUMINANCE
#define UNITS_IRE 0x1B// CHROMINANCE
#define UNITS_BYTE 0x1C// MEMORY

#define SENS_TEMPERATURE 0x00
#define SENS_VOLTAGE 0x01
#define SENS_CURRENT 0x02
#define SENS_FREQUENCY 0x03
#define SENS_RESISTANCE 0x04// Eg: Cable resistance
#define SENS_POWER 0x05
#define SENS_MASS 0x06 // Eg: Truss load Cell
#define SENS_LENGTH 0x07
#define SENS_AREA 0x08
#define SENS_VOLUME 0x09// Eg: Smoke Fluid
#define SENS_DENSITY 0x0A
#define SENS_VELOCITY 0x0B
#define SENS_ACCELERATION 0x0C
#define SENS_FORCE 0x0D

#define NOHISTORY 0
#define RECSUPPORTED 1
#define MINMAXSUPPORTED 2
#define MINMAXANDRECSUPPORTED 3

//extern RDMSensor sensors[8];
//extern uint8_t numOfSensors;
 void addRDMSensor(uint8_t sensorNum, uint8_t sensorType, uint8_t sensorUnit, uint8_t sensorPrefix, int16_t range_min, int16_t range_max, int16_t normal_min, int16_t normal_max, char *sensorDesc);

sensorData_t *getSensorData(uint8_t sensorNum);
sensorDef_t *getSensorDef(uint8_t sensorNum);
void setSensorVal(uint8_t sensorNum, int16_t val);

#ifdef __cplusplus
}
#endif