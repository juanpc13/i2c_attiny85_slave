# i2c_attiny85_slave

Envia 2 bytes de datos al dispositivo master

## Master Code:
```c++
  int data = 0;
  Wire.beginTransmission(13);
  Wire.write(1);
  Wire.requestFrom(13, 2);
  data = Wire.read() << 2 | Wire.read();    
  Wire.endTransmission();
  Serial.println(data);
```
