unsigned int SCALE0 = 0;
unsigned int SCALE1 = 0;
unsigned int SCALE2 = 0;
unsigned int SCALE3 = 0;
unsigned int SCALE4 = 0;
unsigned int SCALE5 = 0;
unsigned int SCALE6 = 0;
char sendStr[40]; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  SCALE0 = 0;
  SCALE1 = 0;
  SCALE2 = 0;
  SCALE3 = 0;
  SCALE4 = 0;
  SCALE5 = 0;
  SCALE6 = 0;
  int nAvg = 64;
  for(int i = 0; i<nAvg; i++)
  {
    analogRead(A0);
    SCALE0 += analogRead(A0);
    analogRead(A6); 
    SCALE6 += analogRead(A6); 
    analogRead(A1); 
    SCALE1 += analogRead(A1);  
    analogRead(A5);  
    SCALE5 += analogRead(A5);    
    analogRead(A2); 
    SCALE2 += analogRead(A2); 
    analogRead(A4);   
    SCALE4 += analogRead(A4);   
    analogRead(A3);  
    SCALE3 += analogRead(A3);
  }
  SCALE0 /= nAvg;
  SCALE1 /= nAvg;
  SCALE2 /= nAvg;
  SCALE3 /= nAvg;
  SCALE4 /= nAvg;
  SCALE5 /= nAvg;
  SCALE6 /= nAvg;
  sprintf(sendStr,"Data:%04d;%04d;%04d;%04d;%04d;%04d;%04d\n",SCALE0,SCALE1,SCALE2,SCALE3,SCALE4,SCALE5,SCALE6);
  Serial.print(sendStr);
  /*
  Serial.print(SCALE0); // 27.4 mW/mm2
  Serial.print(";"); 
  Serial.print(SCALE1); // 9.13 mW/mm2
  Serial.print(";");
  Serial.print(SCALE2); // 3.04 mW/mm2
  Serial.print(";");
  Serial.print(SCALE3); // 1.01 mW/mm2 = 101 mW/cm2
  Serial.print(";");
  Serial.print(SCALE4); // 33.8 mW/cm2
  Serial.print(";");
  Serial.print(SCALE5); // 11.3 mW/cm2
  Serial.print(";");
  Serial.println(SCALE6); // 3.8 mW/cm2
  */
  delay(1000);
}
