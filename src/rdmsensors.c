#include "rdmsensors.h"
#include "string.h"
RDMSensor sensors[8];
uint8_t numOfSensors = 0;


void addRDMSensor(uint8_t sensorNum, uint8_t sensorType, uint8_t sensorUnit, uint8_t sensorPrefix, int16_t range_min, int16_t range_max, int16_t normal_min, int16_t normal_max, char *sensor_desc){
    
    sensors[numOfSensors].sdef.sensorNum = sensorNum;
    sensors[numOfSensors].sdef.sensorType = sensorType;
    sensors[numOfSensors].sdef.sensorUnit = sensorUnit;
    sensors[numOfSensors].sdef.sensorPrefix = sensorPrefix;
    sensors[numOfSensors].sdef.range_min = range_min;
    sensors[numOfSensors].sdef.range_max = range_max;
    sensors[numOfSensors].sdef.normal_min = normal_min;
    sensors[numOfSensors].sdef.normal_max = normal_max;
    strcpy(sensors[numOfSensors].sdef.sensorDesc,sensor_desc);


    numOfSensors++;
}


sensorData_t *getSensorData(uint8_t sensorNum){
    
   return &(sensors[sensorNum].sdata);
}

sensorDef_t *getSensorDef(uint8_t sensorNum){
    return &(sensors[sensorNum].sdef);
}


void setSensorVal(uint8_t sensorNum, int16_t val){
    sensors[sensorNum].sdata.sensorVal = val;
    if(val<sensors[sensorNum].sdata.minVal) sensors[sensorNum].sdata.minVal = val;
    if(val<sensors[sensorNum].sdata.maxVal) sensors[sensorNum].sdata.maxVal = val;
}