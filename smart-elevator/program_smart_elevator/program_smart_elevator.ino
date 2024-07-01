#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define stopp 1 
#define naik 2
#define turun 3
#define elevator1 4 
#define elevator2 5
#define sensorGas 6
#define sensorApi 7
#define loadcell 8
#define speaker 9

void elevatorStop();
void elevatorStop();
void elevatorNaik ();

void setup() {
  lcd.init();
  lcd.init();

  lcd.backlight();

  lcd.setCursor(0,1);
  lcd.print("        Smart       ");
  
  lcd.setCursor(0,2);
  lcd.print("       Elevator     ");

  pinMode(stopp, INPUT);
  pinMode(naik, INPUT);
  pinMode(turun, INPUT);
  
  pinMode(elevator1, OUTPUT);
  pinMode(elevator2, OUTPUT);
  
  pinMode(sensorGas, INPUT);
  pinMode(sensorApi, INPUT);
  pinMode(loadcell, INPUT);

  pinMode(speaker, OUTPUT);
}

void loop() {
  if (digitalRead(loadcell) == LOW) {  
    elevatorStop();
    digitalWrite(speaker, HIGH);
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print(">  Beban melebihi  <");

    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print(">  batas maksimum  <");

    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,2);
    lcd.print("> Silahkan kurangi <");

    lcd.setCursor(0,3);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print(">   jumlah beban   <");

    tone (speaker, 100);

    delay(300);
  }

  else if(digitalRead(loadcell) == HIGH) {
    if (digitalRead(stopp) == HIGH && digitalRead(naik) == HIGH && digitalRead(turun) == HIGH) {
      elevatorStop();
      
      lcd.setCursor(0,0);
      lcd.print("                    ");
      lcd.setCursor(0,0);
      lcd.print(">  Silahkan Tekan  <");
    
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,1);
      lcd.print(">   Mode Operasi   <");
    
      lcd.setCursor(0,2);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print(">       dari       <");
      
      lcd.setCursor(0,3);
      lcd.print("                    ");
      lcd.setCursor(0,3);
      lcd.print(">  Smart Elevator  <");

      delay(300);
    }
    else if (digitalRead(stopp) == LOW && digitalRead(naik) == HIGH && digitalRead(turun) == HIGH) {
      digitalWrite(stopp, LOW);
      digitalWrite(naik, HIGH);
      digitalWrite(turun, HIGH);

       if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == HIGH) {
          elevatorStop();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Stop");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == LOW) {
          elevatorStop();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Stop");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          tone (speaker, 100, 200);

          delay(300);
       }

        else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == HIGH) {
          elevatorStop();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Stop");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == LOW) {
          elevatorStop();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Stop");

          
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          delay(300);
       }
    }

   else if (digitalRead(stopp) == HIGH && digitalRead(naik) == LOW && digitalRead(turun) == HIGH) {
      digitalWrite(naik, HIGH);
      digitalWrite(stopp, HIGH);
      digitalWrite(turun, HIGH);

       if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == HIGH) {
          elevatorNaik();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Naik");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == LOW) {
          elevatorNaik();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Naik");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          tone (speaker, 100, 200);

          delay(300);
       }

        else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == HIGH) {
          elevatorNaik();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Naik");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == LOW) {
          elevatorNaik();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Naik");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          delay(300);
       }
    }

     if (digitalRead(stopp) == HIGH && digitalRead(naik) == HIGH && digitalRead(turun) == LOW) {
      digitalWrite(naik, HIGH);
      digitalWrite(stopp, HIGH);

       if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == HIGH) {
          elevatorTurun();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Turun");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == HIGH && digitalRead(sensorGas) == LOW) {
          elevatorTurun();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Turun");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Hidup");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          tone (speaker, 100, 200);

          delay(300);
       }

        else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == HIGH) {
          elevatorTurun();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Turun");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Hidup");

          tone (speaker, 100, 200);

          delay(300);
       }

       else if(digitalRead(sensorApi) == LOW && digitalRead(sensorGas) == LOW) {
          elevatorTurun();

          lcd.setCursor(0,0);
          lcd.print("                    ");
          lcd.setCursor(0,0);
          lcd.print("> Gerak Lift : Turun");
        
          lcd.setCursor(0,1);
          lcd.print("                    ");
          lcd.setCursor(0,1);
          lcd.print("> Berat : Aman");
        
          lcd.setCursor(0,2);
          lcd.print("                    ");
          lcd.setCursor(0,2);
          lcd.print("> Sensor Api : Mati");
          
          lcd.setCursor(0,3);
          lcd.print("                    ");
          lcd.setCursor(0,3);
          lcd.print("> Sensor Gas : Mati");

          delay(300);
       }
    }
  }
  
  delay(300);
  
  lcd.clear();
  
  noTone(speaker);
  
}


void elevatorStop() {
  digitalWrite(elevator1, LOW);
  digitalWrite(elevator2, LOW);
}

void elevatorNaik () {
  digitalWrite(elevator1, HIGH);
  digitalWrite(elevator2, LOW);
}

void elevatorTurun () {
  digitalWrite(elevator1, LOW);
  digitalWrite(elevator2, HIGH);
}
