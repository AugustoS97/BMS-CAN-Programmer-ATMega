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
#define BALANCING_TYPE_addr 9

//ID de los mensajes CAN en decimal
#define BAT_MSG1_ID 0x40
#define BAT_MSG2_ID 0x41
#define BAT_MSG3_ID 0x42
#define TEMP_MSG1_ID 0x43
#define TEMP_MSG2_ID 0x44
#define TEMP_MSG3_ID 0x45
#define TEMP_MSG4_ID 0x46
#define SOC_MSG_ID 0x47
#define SOH_MSG_ID 0x48
#define CURRENT_MSG_ID 0x49
#define TYPE_BALANCING_MSG_ID 0x3F
#define WARNING_ID 0
#define VUV_MSG_ID 0X02
#define VOV_MSG_ID 0x03
#define DCTO_MSG_ID 0x04
#define NCELL_MSG_ID 0x05
#define N_NTC_MSG_ID 0x06
#define TSLEEP_MSG_ID 0x07
#define BAL1TO8_MSG_ID 0x08
#define BAL9TO12_MSG_ID 0x09 
#define ASK_CONFIG_MSG_ID 0x0B 
#define ANSWER_CONFIG_MSG_ID 0x0C 
#define MAX_DIFF_CELL_MSG_ID 0x0D 


#define PIN_SYNC_MUX 8 //Pin del CS del ADG731  (D8 que es el PB0 en ATMega 328P)
#define PIN_CURRENT_SENSOR A1 //Pin al que se conecta el sensor de corriente
#define PIN_ANALOG_NTC A0 //Pin para la lectura de las Temperaturas
#define SENSIBILITY_CURRENT 0.066 //Sensibilidad del sensor de corriente ACS712 30A
#define SAMPLESNUMBER 100 //Numero de muestras tomadas para hacer la media de la corriente

//#define SERIAL_DEBUG

#endif
