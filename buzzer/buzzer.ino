// Pin connected to buzzer
int buzzer = 6;

void setup() 
{
    // Defines the Buzzer pin as output 
    pinMode(buzzer,OUTPUT);    
}

void loop() 
{
    // Sounds the buzzer at the frequency relative to the note C in Hz
    tone(buzzer,261);    
    // Waits some time to turn off
    delay(200);
    //Turns the buzzer off
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note D in Hz   
    tone(buzzer,293);             
    delay(200);    
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note E in Hz
    tone(buzzer,329);      
    delay(200);
    noTone(buzzer);     
    // Sounds the buzzer at the frequency relative to the note F in Hz
    tone(buzzer,349);    
    delay(200);    
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note G in Hz
    tone(buzzer,392);            
    delay(200);
    noTone(buzzer); 
}
