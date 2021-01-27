/*
Digital speedometer to Audi Driver Information System

Reads vehicle speed from Audi Concert Gala-wire (
Sends information to instrument cluster via Audi concert pins)


*/
#define pulse_ip 2
#define enable 6
#define sck 7
#define sda 8

unsigned long ontime,offtime, period;
float freq = 0;
int final_speed = 0;
float speed_ = 0;
float circumference = 0.63719; // in meters
uint8_t header = 0xf0;
uint8_t command_byte = 0x1c;
uint8_t message [18], checksum;

// numbers from 0 to 9 in ASCII-form
uint8_t ASCII [10] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39}; 

uint8_t KMH [5] = {0x20,0x4B,0x4D, 0x2F,0x48}; // ASCII for: ' km/h'
uint8_t SPACE = 0x20; // ASCII for: ' '

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(pulse_ip, INPUT); // pin for vehicle speed signal (GALA) 

  pinMode(enable, OUTPUT);
  pinMode(sck, OUTPUT);
  pinMode(sda, OUTPUT);
}


// the loop function runs over and over again forever
void loop() {

  ontime = pulseIn(pulse_ip,HIGH);
  offtime = pulseIn(pulse_ip,LOW);
  period = ontime+offtime;
  freq = 1000000.0/(period*2); // 2 periods per one wheel rotation
  speed_ = freq*circumference*3.6;
  speed_ = round(speed_);
  final_speed = speed_; 
   
  message[0] = header;
  message[16] = command_byte;

  message[1] = SPACE; // For alignment
  message[2] = SPACE;

  if(final_speed < 10){
    message[3] = ASCII[final_speed];
    message[4] = SPACE;
    message[5] = SPACE;
    }
      
  else if(final_speed < 100){
    message[3] = ASCII[final_speed / 10];
    message[4] = ASCII[final_speed % 10];
    message[5] = SPACE;
    }
    
  else{
    message[3] = ASCII[final_speed / 100];
    message[4] = ASCII[final_speed / 10];
    message[5] = ASCII[final_speed % 10];
    }

  for(int i = 6; i < 11; i++){ // for alignment
    message[i] = SPACE;
    }
    
     
  message[11] = KMH[1];
  message[12] = KMH[2];
  message[13] = KMH[3];
  message[14] = KMH[4];

  message[15] = SPACE;

  checksum = 0;
  for(int j = 0; j < 17; j++){
    checksum += message[j];
    }
     
  checksum ^= 0xff;
  message[17] = checksum;

  digitalWrite(enable, HIGH);

  // Sending the data
  for(int i = 0; i < 18; i++){
    uint8_t data = message[i];

    for(int k = 0; k < 8; k++){

      if(data & 0x80){
        digitalWrite(sda, HIGH);
        }
      else{
        digitalWrite(sda, LOW);
        }
      digitalWrite(sck, LOW);
      digitalWrite(sck, HIGH);
      data <<=1; //Shifting 1 left
      }
    }
    digitalWrite(enable, LOW);
    delay(500);
    }