#include "ads1115.h"

Ads1115::Ads1115(uint8_t reg3Gain, uint8_t reg2DataRate, uint8_t reg3Mux, uint8_t reg2CompLatch, uint8_t reg2CompPolarity,  uint8_t adr)
{

 adr_ = adr;
 configReg_.rg1.P           = 1;                    /// CONFIG_REG;
 configReg_.rg2.DR          = reg2DataRate;         /// SPS_128;
 configReg_.rg2.COMP_MODE   = 0;                    /// DEFAULT
 configReg_.rg2.COMP_POL    = reg2CompPolarity;     /// ACTIVE POLARITY
 configReg_.rg2.COMP_LAT    = reg2CompLatch;        /// ACTIVE LATCH COMPARATOR
 configReg_.rg2.COMP_QUE    = 0;                    /// DEFAULT
 configReg_.rg3.OS          = 1;                    /// DEFAULT
 configReg_.rg3.MUX         = reg3Mux;              /// MUX_AIN0_AIN1
 configReg_.rg3.PGA         = reg3Gain;             /// GAIN 3 BITS (REglable)
 configReg_.rg3.MODE        = 0;                    /// MODE_SINGLE_SHOT;
 if ((handle = open("/dev/i2c-1", O_RDWR)) < 0)
  {
   printf("Failed to open the bus. \n");
   exit(1);
  }
  ioctl(handle, I2C_SLAVE, adr_);
  ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: ADS1115_Init()
*	function: The intialisation of the ADC
*
*	The return value: Bool
*********************************************************************************************************
*/
bool  Ads1115::ADS1115_Init()
{
   configReg_.PrepareConfig();
   write(handle,configReg_.config, 3);
   QThread::msleep(1000);
   if(!ADS1115_StartScan()) {qDebug() <<"Erreur config"; exit(-1);}
 }
/*
*********************************************************************************************************
*	name: ADS1115_Init()
*	function: The intialisation of the ADC
*
*	The return value: Bool
*********************************************************************************************************
*/
 bool  Ads1115::ADS1115_IsrInit(int pin, int mode, void (*fonction)(void))
 {
     if (wiringPiSetup () < 0)
      {
        fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
      }
    pinMode(pin, INPUT);
    wiringPiISR(pin,mode, fonction);
 }
/*
*********************************************************************************************************
*	name: ~ADS1115()
*	function: Close i2c Descriptor
*
*	The return value: Bool
*********************************************************************************************************
*/
Ads1115::~Ads1115()
{
 close(handle);
}

/*
*********************************************************************************************************
*	name: ADS1115_ReadReg
*	function: Read  the corresponding register
*	parameter: _RegID: register  ID
*	The return value: read register value
*********************************************************************************************************
*/
 bool Ads1115::ADS1115_ReadDataReg(int &data)
{
     int err;
     char raw_adc[2] ;

     err = read(handle,raw_adc,2);
     if (err >= 0)
     {
     data= raw_adc[0] * 256 + raw_adc[1];
     if (data > 32767) data -= 65535;
     return true;
     }
     return false;
 }
 /*
 *********************************************************************************************************
 *	name: ADS1115_StartScan()
 *	function: Configuration : Config th ADS1115 fot read the  data register . StarScan is folow
 *  an ADA1115 initialisation.
 *	parameter:  void
 *	The return value: bool
 *********************************************************************************************************
 */
 bool Ads1115::ADS1115_StartScan()
 {
     int err;
     char  dataRegister =0;
     err = write (handle,&dataRegister,1);
     if(err >= 0) return true;
     return false;
 }

/*
*********************************************************************************************************
*	name: SetMux()
*	function: Configuration channel number
*	parameter:  _ch:  channel number  0--3
**********************************************************************************************************
*/
 /*
 *********************************************************************************************************
 *	name: SetMux()
 *	function: Configuration channel number
 *	parameter:  _ch:  channel number  0--3
 **********************************************************************************************************
 */
void Ads1115::SetMux(uint8_t reg3Mux)
{
    configReg_.rg3.MUX         = reg3Mux;
    ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: SetMux()
*	function: Configuration channel number
*	parameter:  _ch:  channel number  0--3
**********************************************************************************************************
*/
void Ads1115::SetGain(uint8_t reg3Gain)
{
    configReg_.rg3.PGA = reg3Gain;
    ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: SetMux()
*	function: Configuration channel number
*	parameter:  _ch:  channel number  0--3
**********************************************************************************************************
*/
void Ads1115::SetDataRate(uint8_t reg2DataRate)
{
    configReg_.rg2.DR = reg2DataRate;
    ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: SetMux()
*	function: Configuration channel number
*	parameter:  _ch:  channel number  0--3
**********************************************************************************************************
*/
void Ads1115::SetComLatch(uint8_t reg2ComLatch)
{
    configReg_.rg2.COMP_LAT = reg2ComLatch;
    ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: SetMux()
*	function: Configuration channel number
*	parameter:  _ch:  channel number  0--3
**********************************************************************************************************
*/
void Ads1115::SetCompPolarity(uint8_t reg2CompPolarity)
{
    configReg_.rg2.COMP_POL = reg2CompPolarity;
    ADS1115_Init();
}
/*
*********************************************************************************************************
*	name: ADS1115_ISR
*	function: Collection procedures
*	parameter: NULL
*	The return value:  NULL
*********************************************************************************************************
*/
void Ads1115::ADS1115_ISR(void)
{
  static long cpt;
  cout << "COMPTEUR"<<cpt++;
}
/*
*********************************************************************************************************
*	name: Voltage_Convert
*	function:  Voltage value conversion function
*	parameter: Vref : The reference voltage 3.3V or 5V
*			   voltage : output DAC value
*	The return value:  NULL
*********************************************************************************************************
*/
uint16_t Ads1115::VoltageConvert(float Vref, float voltage)
{
    uint16_t _D_;
    _D_ = (uint16_t)(65536 * voltage / Vref);

    return _D_;
}
