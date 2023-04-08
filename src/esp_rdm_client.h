#pragma once
#include <stdbool.h>
#include "rdm_types.h"
#include "dmx_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*start_address_changed_cb_t)(uint16_t);
typedef void (*identify_cb_t)(bool);
typedef void (*label_changed_cb_t)(const char*, size_t);
typedef void (*personality_changed_cb_t)(uint8_t personality);


//TODO comment
bool rdm_client_init(dmx_port_t dmx_num, uint16_t start_address, uint16_t footprint, const char* device_label,
                     const char *personality_description);

/// returns the id of the personality, or -1 in case of error
int rdm_client_add_personality(dmx_port_t dmx_num, uint16_t footprint, const char* description);

bool rdm_client_set_personality(dmx_port_t dmx_num, uint8_t personality);

void rdm_client_set_personality_changed_cb(dmx_port_t dmx_num, personality_changed_cb_t cb);


void rdm_client_set_start_address(dmx_port_t dmx_num, uint16_t start_address);

/** 
 * @param cb Will be invoked every time the dmx start address is changed. */
void rdm_client_set_start_address_changed_cb(dmx_port_t dmx_num, start_address_changed_cb_t cb);

/**
 * @param cb Will be invoked every time the indentify value changes.
 *           If the value is true, the device should identify itself (e.g. by blinking)
*/
void rdm_client_set_notify_cb(dmx_port_t dmx_num, identify_cb_t cb);

/**
 * @param cb Will be invoked every time the device label is changed.
 * @note the device label is **not** null-terminated
*/
void rdm_client_set_label_changed_cb(dmx_port_t dmx_num, label_changed_cb_t cb);

/**
 * This method should be called anytime a dmx-rdm message is received.
*/
void rdm_client_handle_rdm_message(dmx_port_t dmx_num, const dmx_packet_t *dmxPacket, const void *data, const uint16_t size);

extern rdm_parameters_t rdm_parameters[DMX_NUM_MAX];

void RDM_setManufacturerLabel(char *manlabel);
void RDM_setSWVersion(char *ver);
void RDM_setDeviceModelDesc(char *desc);

extern uint16_t RDM_ManUUID;

void RDM_setManUUID(uint16_t manUUID);

#ifdef __cplusplus
}
#endif
