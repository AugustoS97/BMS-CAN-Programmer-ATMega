#ifndef config_h
#define config_h

/************************************
  Constantes y parámetros
  ***********************************/
#define CFGR0_addr 1
#define VUV_addr 2
#define VOV_addr 3
#define DCTO_addr 4
#define NCELL_addr 5
#define N_NTC_addr 6
#define TSLEEP_addr 7
#define MAX_DIFF_CELL_addr 8

//ID de los mensajes CAN en hexadecimal
#define BAT_MSG1_ID 64
#define BAT_MSG2_ID 65
#define BAT_MSG3_ID 66
#define TEMP_MSG1_ID 67
#define TEMP_MSG2_ID 68
#define TEMP_MSG3_ID 69
#define TEMP_MSG4_ID 70
#define WARNING_ID 0
#define VUV_MSG_ID 0X02
#define VOV_MSG_ID 0x03
#define DCTO_MSG_ID 0x04
#define NCELL_MSG_ID 0x05
#define N_NTC_MSG_ID 0x06
#define TSLEEP_MSG_ID 0x07
#define BAL1TO8_MSG_ID 0x08
#define BAL9TO12_MSG_ID 0x09 
#define ASK_CONFIG_MSG_ID 0xB 
#define SEND_CONFIG_MSG_ID 0xC 
#define MAX_DIFF_CELL_MSG_ID 0xD 

#define PIN_SYNC_MUX 8 //Pin del CS del ADG731  (D8 que es el PB0 en ATMega 328P)

//#define SERIAL_DEBUG

#endif
