void HAL_SYSTICK_Callback()
{
  encoder1_read();
  encoder2_read();
  encoder3_read();
}

void encoder1_read(void)
{
  volatile static uint8_t ABs = 0;
  ABs = (ABs << 2) & 0x0f; //left 2 bits now contain the previous AB key read-out;
  ABs |= (digitalRead(ENC_CLK) << 1) | digitalRead(ENC_DATA);
  switch (ABs)
  {
    case 0x0d:
      encoderCount++;
      break;
    case 0x0e:
      encoderCount--;
      break;
  }
}

void encoder2_read(void)
{
  volatile static uint8_t ABs = 0;
  ABs = (ABs << 2) & 0x0f; //left 2 bits now contain the previous AB key read-out;
  ABs |= (digitalRead(ENC_CLK2) << 1) | digitalRead(ENC_DATA2);
  switch (ABs)
  {
    case 0x0d:
      encoderCount2++;
      break;
    case 0x0e:
      encoderCount2--;
      break;
  }
}

  void encoder3_read(void)
{
  volatile static uint8_t ABs = 0;
  ABs = (ABs << 2) & 0x0f; //left 2 bits now contain the previous AB key read-out;
  ABs |= (digitalRead(ENC_CLK3) << 1) | digitalRead(ENC_DATA3);
  switch (ABs)
  {
    case 0x0d:
      encoderCount3++;
      break;
    case 0x0e:
      encoderCount3--;
      break;
  }
}
