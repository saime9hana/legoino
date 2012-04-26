

#define I2C_4RELAY_ID 33

void I2CRelay4Setup()
{
  //make sure Wire.begin() is running; initiated in the Wire setup
  
  I2CRelay4SetRegister(I2C_4RELAY_ID, 0x05, 0b00000100); // initialize CONFREG (0x05)
  delay(5);
  I2CRelay4SetRegister(I2C_4RELAY_ID, 0x00, 0b00000000); // initialize IOREG (0x00)
  delay(5);
  I2CRelay4SetRegister(I2C_4RELAY_ID, 0x0A, 0b00001111); // pin control
  delay(5); 
  
}

void I2CRelay4Info(Print* output)
{
  output->println("Switching relay."); 
}

void I2CRelay4Switch()
{
   byte commandByte = 0b00000101;
   I2CRelay4SetRegister(I2C_4RELAY_ID, 0x0A, commandByte);

}


void I2CRelay4SetRegister(byte deviceID, byte reg, byte data)
{
  Wire.beginTransmission(deviceID);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
  
}