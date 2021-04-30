#include "config.h"
#include "mcp2515.h"

String inReadString = "";


MCP2515 mcp2515(10);

struct can_frame can_msg_in;
struct can_frame can_msg_out;

void can_msg_rcv(){
  noInterrupts();
  if(mcp2515.readMessage(&can_msg_in) == MCP2515::ERROR_OK){
    Serial.print("Mensaje recibido Correctamente. ID:");
    Serial.println(can_msg_in.can_id, DEC);
  }
  interrupts();
}
void setup() {
  attachInterrupt(0, can_msg_rcv, FALLING); //Se configura interrupcion al recibir mensaje CAN
  Serial.begin(115200);
  //inReadString.reserve(10);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  inReadString = serial_event(); //Se lee puerto serial y se almacena lo leido
  char ID_in = char(inReadString[0]); //Se obtiene el ID que es el byte 0 del String leido por serial
  uint8_t config_value = uint8_t(get_data(inReadString)); //Se obtiene el valor del parametro y se  almacena en 1 byte

  switch (ID_in){
    case 'A':
      Serial.print("Mensaje de VUV. Valor: ");
      Serial.print(config_value, BIN);
      Serial.print(" = ");
      Serial.println(config_value*0.02);
      can_msg_out.can_id = VUV_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    case 'B':
      Serial.print("Mensaje de VOV. Valor: ");
      Serial.print(config_value, BIN);
      Serial.print(" = ");
      Serial.println(config_value*0.02);
      can_msg_out.can_id = VOV_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;    
    case 'C':
      Serial.print("Mensaje de DCTO. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = DCTO_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    case 'D':
      Serial.print("Mensaje de N_CELDAS. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = NCELL_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    case 'E':
      Serial.print("Mensaje de N SENSORES Temp. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = N_NTC_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    case 'F':
      Serial.print("Mensaje de TSLEEP. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = TSLEEP_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    case 'G':
      Serial.print("Mensaje de Balanceo 1-8. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = BAL1TO8_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      
      break;
    case 'H':
      Serial.print("Mensaje de Balanceo 9-12. Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = BAL9TO12_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
      
    case 'I':
      Serial.print("Mensaje de Máxima V de diferencia entre celdas (mV) . Valor: ");
      Serial.println(config_value, BIN);
      can_msg_out.can_id = MAX_DIFF_CELL_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    case 'Z': //Para pedir todos los valores de config. Escribir Z255
      Serial.print("Mensaje de pedir Config Actual. Valor: ");
      Serial.println(config_value, BIN); 
      can_msg_out.can_id = ASK_CONFIG_MSG_ID;
      can_msg_out.can_dlc = 1;
      can_msg_out.data[0] = uint8_t(config_value);
      mcp2515.sendMessage(&can_msg_out);
      break;
    default:
      //Serial.println("Ninguno de los ID se ha identificado");
      break;
  } //Fin del Switch


//Leer mensajes del CAN (Con interrupcion) y enviar un mensaje serial con cada valor.
  
}





String serial_event(){
  String inputString = "";
  inputString.reserve(10); //Se reservan 200 bytes
  while(Serial.available()){
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '\n'){
      return inputString;
    }
  }
}

int get_data (String serial_msg){
  String data = "";
  for (int i=1; i<serial_msg.length()-1; i++){ //comienza en 1 para eliminar el ID y acaba en length -2 para evitar el '\n'
    data += char(serial_msg[i]); //Se anida en el string el siguiente caracter
  }
  return data.toInt();
}
