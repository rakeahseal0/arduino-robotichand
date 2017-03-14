#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Servo.h>
//by Rakesh Seal
//date 14.3.2017
MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

Servo myservo;
Servo myservo1;

int val; //arm
int prevVal; 
int val1; //base
int a=0;

void setup() 
{
    Wire.begin();
    Serial.begin(38400);

    Serial.println("Initialize MPU");
    mpu.initialize();
    Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
    myservo.attach(9); //arm
    myservo1.attach(10); //base
}

void loop() 
{
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    val = map(ax, -17000, 17000, 0, 179);
     
     delay(50);
    if (val != prevVal)
    {
        myservo.write(val);
        prevVal = val;
    }
     val1 = map(ay, -17000, 17000,0, 179);
     Serial.println(val1);
     Serial.println("\t");
     delay(50);
    if (val1 != prevVal)
    {
        myservo1.write(val1);
        prevVal = val1;
    }


    delay(50);
}
