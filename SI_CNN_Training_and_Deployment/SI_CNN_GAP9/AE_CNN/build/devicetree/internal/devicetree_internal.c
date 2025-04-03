/*
 * Copyright (C) 2024 GreenWaves Technologies
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* @file    devicetree_internal.c
 * @brief   C formatted devicetree content
 *
 * This file has been generated from the devicetree (*.dts files) and enabled
 * Kconfig options. It defines availables features from the board you are using
 *
 * @note This file is automatically generated during the project configuration
 *       Do not edit it.
 */

#include <devicetree_internal.h>

// BSP includes ****************************************************************

#include <bsp_gap9mod_v1_0_b.h>
#include <bsp_gap9evk_v1_3.h>

// mx25u51245g *****************************************************************

pi_mx25u51245g_conf_t mx25u51245g_conf = {
    .baudrate    = 200000000,
    .xip_en      = 0,
    .sector_size = 4096,
    .size        = 67108864,
    .spi_cs      = 0,
    .spi_itf     = 0,
};

pi_mx25u51245g_data_t mx25u51245g_data;

pi_device_t mx25u51245g_dev = {
    .config = &mx25u51245g_conf,
    .data   = &mx25u51245g_data,
    .api    = (pi_device_api_t*) &mx25u51245g_api,
};

// mram ************************************************************************

pi_mram_conf_t mram_conf = {
    .itf      = 0,
    .baudrate = 34000000,
    .xip_en   = 0,
};

pi_mram_data_t mram_data;

pi_device_t mram_dev = {
    .config = &mram_conf,
    .data   = &mram_data,
    .api    = (pi_device_api_t*) &mram_api,
};

// periph3v3 *******************************************************************

pi_powersupplygpio_conf_t periph3v3_conf = {
    .pad_id = 35,
};

pi_powersupplygpio_data_t periph3v3_data;

pi_device_t periph3v3_dev = {
    .config = &periph3v3_conf,
    .data   = &periph3v3_data,
    .api    = (pi_device_api_t*) &powersupplygpio_api,
};

// cam3v3 **********************************************************************

pi_powersupplygpio_conf_t cam3v3_conf = {
    .pad_id = 0,
};

pi_powersupplygpio_data_t cam3v3_data;

pi_device_t cam3v3_dev = {
    .config = &cam3v3_conf,
    .data   = &cam3v3_data,
    .api    = (pi_device_api_t*) &powersupplygpio_api,
};

// aps256xxn *******************************************************************

pi_aps256xxn_conf_t aps256xxn_conf = {
    .ram.aes_conf.qk_en   = 0,
    .ram.aes_conf.enabled = 0,
    .mba                  = 33554432,
    .reserve_addr_0       = 1,
    .xip_en               = 0,
    .baudrate             = 200000000,
    .ram_size             = 33554432,
    .ram_start            = 0,
    .spi_cs               = 1,
    .spi_itf              = 0,
};

pi_aps256xxn_data_t aps256xxn_data;

pi_device_t aps256xxn_dev = {
    .config = &aps256xxn_conf,
    .data   = &aps256xxn_data,
    .api    = (pi_device_api_t*) &aps256xxn_api,
};

