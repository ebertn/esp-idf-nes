// Copyright 2018 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*******************************************************************************
 *
 *  Filename:      btc_hf_client.h
 *
 *  Description:   Main API header file for all BTC HF client functions accessed
 *                 from internal stack.
 *
 *******************************************************************************/

#ifndef __BTC_HF_CLIENT_H__
#define __BTC_HF_CLIENT_H__

#include "common/bt_target.h"
#include "esp_hf_client_api.h"
#include "btc/btc_task.h"
#include "btc/btc_common.h"
#include "bta/bta_hf_client_api.h"

#if (BTC_HF_CLIENT_INCLUDED == TRUE)
/*******************************************************************************
**  Type definitions for callback functions
********************************************************************************/
typedef enum {
    BTC_HF_CLIENT_INIT_EVT,
    BTC_HF_CLIENT_DEINIT_EVT,
    BTC_HF_CLIENT_CONNECT_EVT,
    BTC_HF_CLIENT_DISCONNECT_EVT,
    BTC_HF_CLIENT_CONNECT_AUDIO_EVT,
    BTC_HF_CLIENT_DISCONNECT_AUDIO_EVT,
    BTC_HF_CLIENT_START_VOICE_RECOGNITION_EVT,
    BTC_HF_CLIENT_STOP_VOICE_RECOGNITION_EVT,
    BTC_HF_CLIENT_VOLUME_UPDATE_EVT,
    BTC_HF_CLIENT_DIAL_EVT,
    BTC_HF_CLIENT_DIAL_MEMORY_EVT,
    BTC_HF_CLIENT_SEND_CHLD_CMD_EVT,
    BTC_HF_CLIENT_SEND_BTRH_CMD_EVT,
    BTC_HF_CLIENT_ANSWER_CALL_EVT,
    BTC_HF_CLIENT_REJECT_CALL_EVT,
    BTC_HF_CLIENT_QUERY_CURRENT_CALLS_EVT,
    BTC_HF_CLIENT_QUERY_CURRENT_OPERATOR_NAME_EVT,
    BTC_HF_CLIENT_RETRIEVE_SUBSCRIBER_INFO_EVT,
    BTC_HF_CLIENT_SEND_DTMF_EVT,
    BTC_HF_CLIENT_REQUEST_LAST_VOICE_TAG_NUMBER_EVT,
    BTC_HF_CLIENT_REGISTER_DATA_CALLBACK_EVT,
} btc_hf_client_act_t;

/* btc_hf_client_args_t */
typedef union {
    // BTC_HF_CLIENT_CONNECT_EVT
    bt_bdaddr_t connect;

    // BTC_HF_CLIENT_DISCONNECT_EVT
    bt_bdaddr_t disconnect;

    // BTC_HF_CLIENT_CONNECT_AUDIO_EVT
    bt_bdaddr_t connect_audio;

    // BTC_HF_CLIENT_DISCONNECT_AUDIO_EVT
    bt_bdaddr_t disconnect_audio;

    // BTC_HF_CLIENT_VOLUME_UPDATE_EVT,
    struct volume_update_args {
        esp_hf_volume_control_target_t type;
        int volume;
    } volume_update;

    // BTC_HF_CLIENT_DIAL_EVT
    struct dial_args {
        char number[ESP_BT_HF_CLIENT_NUMBER_LEN + 1];
    } dial;

    // BTC_HF_CLIENT_DIAL_MEMORY_EVT
    struct dial_memory_args {
        int location;
    } dial_memory;

    // BTC_HF_CLIENT_SEND_CHLD_CMD_EVT
    struct send_chld_cmd_args {
        esp_hf_chld_type_t type;
        int idx;
    } chld;

    // BTC_HF_CLIENT_SEND_BTRH_CMD_EVT
    struct send_btrh_cmd_args {
        esp_hf_btrh_cmd_t cmd;
    } btrh;

    // BTC_HF_CLIENT_SEND_DTMF_EVT
    struct send_dtmf {
        char code;
    } send_dtmf;

    // BTC_HF_CLIENT_REGISTER_DATA_CALLBACK_EVT
    struct reg_data_callback {
        esp_hf_client_incoming_data_cb_t recv;
        esp_hf_client_outgoing_data_cb_t send;
    } reg_data_cb;
} btc_hf_client_args_t;

/*******************************************************************************
**  BTC HF AG API
********************************************************************************/

void btc_hf_client_call_handler(btc_msg_t *msg);

void btc_hf_client_cb_handler(btc_msg_t *msg);

void btc_hf_client_incoming_data_cb_to_app(const uint8_t *data, uint32_t len);

uint32_t btc_hf_client_outgoing_data_cb_to_app(uint8_t *data, uint32_t len);
#endif  ///BTC_HF_CLIENT_INCLUDED == TRUE

#endif /* __BTC_HF_CLIENT_H__ */
