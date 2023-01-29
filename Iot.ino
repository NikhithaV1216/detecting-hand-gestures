int a = 0;

int b = 0;

int c = 0;

int d = 0;

int e = 0;
int GSMBaud = 9600; 
#define BUZZER 4
const String PHONE = "6302102929";
double latitude = 16.485387;
double longitude = 80.691425;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  Serial2.begin(GSMBaud);
  delay(1000);
}

void loop()
{
  a = analogRead(A0); //thumb
  b = analogRead(A1); //index
  c = analogRead(A2); //middle
  d = analogRead(A3); //ring
  e = analogRead(A4); //little
 {  
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
    Serial.println(e);
    Serial.println("------");
    if(a>220 && b>135 && c<120 && d<120 && e<100){
      Serial.println("feeling");  
      delay(500);
      Serial.println("sick");
    }
    else if(a>220 && b>135 && c>140 && d<120 && e<100){
      Serial.println("feeling");  
      delay(500);
      Serial.println("hungry");
 
    }   
    else if(a<220 && b<135 && c>140 && d>120 && e>100){
      Serial.println("Ok");
    }
    else if(a>220 && b<135 && c>140 && d>120 && e<100){
      Serial.println("Need");
      delay(500);
      Serial.println("water");
    }
    else if(a>220  && b<135 && c>140 && d>120 && e>100){
      Serial.println("Thank");
      delay(500);
      Serial.println("you");
    }
     else if(a<220 && b<135 && c<140 && d<120 && e>100){
      Serial.println("take");
      delay(500);
      Serial.println("Me To");
      delay(500);
      Serial.println("wash");
      delay(500);
      Serial.println("room");
      
    }
    else if(a<220 && b<135 && c<140 && d<120 && e<120){
      Serial.println("Sorry");
    }
    else if(a<220 && b>135 && c>140 && d<120 && e<120){
      Serial.println("See");
      delay(500);
      Serial.println("you");
      delay(500);
      Serial.println("again");
    }
    else if(a>220 && b<135 && c<140 && d<120 && e<120){
      Serial.println("Bye");
    }
    
    else if(a<220 && b>135 && c>140 && d>120 && e>120){
      SendTextMessage();
    }
   

      
    }
    
    
  
  delay(5000);

  }

void SendTextMessage(){
  digitalWrite(BUZZER, HIGH);
  delay(5000);
  digitalWrite(BUZZER, LOW);
  Serial.println("Sending");
  delay(500);
  Serial.println("Text");
  String sms_data_1;
  sms_data_1 = "Alert! Kindly help me in an emergency. This is where I am : \r";
  sms_data_1 += "http://maps.google.com/maps?q=loc:";
  sms_data_1 += String(latitude,6) + "," + String(longitude,6);


  
  Serial2.print("AT+CMGF=1\r");
  delay(1000);
  Serial2.print("AT+CMGS=\""+PHONE+"\"\r");
  delay(1000);
  Serial2.print(sms_data_1);
  delay(100);
  Serial2.write(0x1A); //ascii code for ctrl-26 //sim800.println((char)26); //ascii code for ctrl-26
  delay(1000);
  Serial.println("SMS");
  delay(500);
  Serial.println("Sent");
  delay(500);
  Serial.println("Successfully");
  delay(5000);
}
