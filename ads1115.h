#ifndef ADS1115_H
#define ADS1115_H

#include "ads1115api.h"

class Ads1115
{
protected:

  int handle;
  uint8_t adr_;
  ASD1115_CONFIG_REGISTER configReg_;




public:
   // Ads1115( uint8_t Adr=0x48);
    Ads1115(uint8_t reg3Gain=FSR_2, uint8_t reg2DataRate=SPS_128,  uint8_t reg3Mux= MUX_AIN0_AIN1, uint8_t reg2CompLatch=1, uint8_t reg2CompPolarity=1, uint8_t adr=0x48);


    ~Ads1115();
    bool  ADS1115_Init();
    bool  ADS1115_IsrInit(int pin, int edgeType, void (*fonction)(void));
    bool ADS1115_StartScan();
    bool ADS1115_ReadDataReg(int &data);

    void SetGain(uint8_t reg3Gain);
    void SetDataRate(uint8_t reg2DataRate);
    void SetMux(uint8_t reg3Mux);
    void SetComLatch(uint8_t reg2ComLatch);
    void SetCompPolarity(uint8_t reg2CompPolarity);
    static void ADS1115_ISR(void);
    uint16_t VoltageConvert(float Vref, float voltage);
};
#endif // ADS1115_H
