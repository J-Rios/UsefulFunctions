
#define SERIAL_BAUDS 9600 // 9600: 206 samples; 19200: 142 samples; 57600: 166 samples; 115200: 63 samples; 230400: 231 samples; 250000: 228 samples

unsigned long t1, t2;
uint16_t read;

void setup()
{
    Serial.begin(SERIAL_BAUDS);
    t1 = millis();
    t2 = t1;
}

void loop()
{
    static uint8_t num_samples = 0;
    
    if(t2 - t1 < 1000)
    {
        read = analogRead(A0);
        Serial.println(read);
        num_samples = num_samples + 1;
        t2 = millis();
    }
    else
    {
        Serial.println();
        Serial.print("Number of ADC samples readed in 1 second: ");
        Serial.print(num_samples);
        while(1);
    }
}
