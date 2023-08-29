int Relaypin1 = 7;                 // IN1
int Relaypin2 = 8;                 // IN2
int Relaypin3 = 9;                 // IN3
int Relaypin4 =10;
bool state1, state2 , state3, state4;

void setup()
{
  Serial.begin(9600);
  
pinMode(Relaypin1,OUTPUT);         // 릴레이 제어 1번핀을 출력으로 설정
pinMode(Relaypin2,OUTPUT);         // 릴레이 제어 2번핀을 출력으로 설정
pinMode(Relaypin3,OUTPUT);         // 릴레이 제어 3번핀을 출력으로 설정
pinMode(Relaypin4,OUTPUT);         // 릴레이 제어 4번핀을 출력으로 설정

digitalWrite (Relaypin1, LOW); // 릴레이 OFF
digitalWrite (Relaypin2, LOW); // 릴레이 OFF
digitalWrite (Relaypin3, LOW); // 릴레이 OFF
digitalWrite (Relaypin4, LOW); // 릴레이 OFF
}

void loop()
{
   if (Serial.available()) {
        switch (Serial.read()) {
          
            case '1':   Serial.println("Relay1");
                        if(state1==false){
                          state1 = true;
                          digitalWrite (Relaypin1, HIGH);
                        }
                        else if(state1==true){
                          state1 = false;
                          digitalWrite (Relaypin1, LOW);
                        }
                        break;
                        
            case '2':    Serial.println("Relay2");
                         if(state2==false){
                          state2 = true;
                          digitalWrite (Relaypin2, HIGH);
                        }
                        else if(state2==true){
                          state2 = false;
                          digitalWrite (Relaypin2, LOW);
                        }
                        break;
                        
            case '3':    Serial.println("Relay3");
                         if(state3==false){
                          state3 = true;
                          digitalWrite (Relaypin3, HIGH);
                        }
                        else if(state3==true){
                          state3 = false;
                          digitalWrite (Relaypin3, LOW);
                        }
                        break;
                        
            case '4':    Serial.println("Relay4");
                        if(state4==false){
                          state4 = true;
                          digitalWrite (Relaypin4, HIGH);
                        }
                        else if(state4==true){
                          state4 = false;
                          digitalWrite (Relaypin4, LOW);
                        }
                        break;
                        
            case '0':    Serial.println("OFF");
                        state1=false;
                        state2=false;
                        state3=false;
                        state4=false;
                        digitalWrite (Relaypin1, LOW);
                        digitalWrite (Relaypin2, LOW);
                        digitalWrite (Relaypin3, LOW);
                        digitalWrite (Relaypin4, LOW);
                        break;
                        
            case '9':    Serial.println("On");
                        state1=true;
                        state2=true;
                        state3=true;
                        state4=true;
                        
                        digitalWrite (Relaypin1, HIGH);
                        digitalWrite (Relaypin2, HIGH);
                        digitalWrite (Relaypin3, HIGH);
                        digitalWrite (Relaypin4, HIGH);
                        
                        
                        
                        break;               
            default:    
                        break;
        }
   }

}
