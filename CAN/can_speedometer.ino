#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg, canMsg1, canMsg2;

int velocity = 0;

const uint8_t ASCII [10] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39}; // ASCII for numbers 0..9
const uint8_t SPACE = 0x20;
const uint8_t KMH_MESSAGE [8] = {SPACE, SPACE, 0x4b, 0x4d, 0x2f, 0x48, SPACE, SPACE}; //ASCII for '  KM/H  '

MCP2515 mcp2515(10);


void setup() {

  canMsg1.can_id  = 0x261; // Message ID for the first row of the DIS
  canMsg1.can_dlc = 8;

  for(int i=0; i<8; i++){
    canMsg1.data[i] = SPACE; // Initialising the speed message (first row of                               
                             // DIS) with SPACES
  }

  canMsg2.can_id  = 0x263; // Message ID for the second row of the DIS 
  canMsg2.can_dlc = 8;
  for(int j=0; j<8; j++){
    canMsg2.data[j] = KMH_MESSAGE[j];
  }
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_100KBPS, MCP_16MHZ);
  mcp2515.setNormalMode();
  
}



void loop() {
  
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    if(canMsg.can_id == 0x351){ // ID for speed information on CAN-Bus
        
        velocity = canMsg.data[1]; // Speed is stored in the second byte of  
                                      // the message                                      
    }  
  }

  if(velocity < 10){
    canMsg1.data[2] = ASCII[velocity];
    }

  else if(velocity < 100){
    canMsg1.data[2] = ASCII[velocity/10]; // Splitting integer to single                                                
                                             //numbers
    canMsg1.data[3] = ASCII[velocity%10];
    }
  else{
    canMsg1.data[2] = ASCII[velocity/100];
    canMsg1.data[3] = ASCII[velocity/10];
    canMsg1.data[4] = ASCII[velocity%10];
    
  }
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);
  
  delay(40); // The car radio sends it own radio station data every 0,8s to
             // the instrument cluster, so I have to send my data with much                
             // higher rate, so the display won't start to blink
}