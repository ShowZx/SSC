
#ifndef ADS1115API_H
#define ADS1115API_H

// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ADS1115
// This code is designed to work with the ADS1115_I2CADC I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS1115_I2CADC#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <wiringPi.h>


#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <stdint.h>
#include <QThread>
#include <QDebug>
#include <iostream>
using namespace std;



//CS      -----   SPICS
//DIN     -----   MOSI
//DOUT  -----   MISO
//SCLK   -----   SCLK
//DRDY  -----   ctl_IO     data  starting
//RST     -----   ctl_IO     reset

//#define  DRDY  RPI_GPIO_P1_11         //P0
#define  DRDY  17
//#define  RST  RPI_GPIO_P1_12     //P1
#define  RST  18
//#define	SPICS	RPI_GPIO_P1_15	//P3   ads1256  cs
#define       SPICS  22
//#define	SPICS1	RPI_GPIO_P1_16	//P4   DAC8552 CS
#define       SPICS1  RPI_GPIO_P1_16



#define CS_1() bcm2835_gpio_write(SPICS,HIGH)
#define CS_0()  bcm2835_gpio_write(SPICS,LOW)


#define DRDY_IS_LOW()	((bcm2835_gpio_lev(DRDY)==0))

#define RST_1() 	bcm2835_gpio_write(RST,HIGH)
#define RST_0() 	bcm2835_gpio_write(RST,LOW)


enum ADS1115_ADR_POINTER
{
    DATA_REG =0,
    CONFIG_REG,
};


// Single Shot Conversion Start
enum ADS115_OS
{
   NO_EFFECT = 0,
   SINGLE_CONVERSION
};

enum ADS1115_MUX
{
 MUX_AIN0_AIN1  = 0x000,   //default
 MUX_AIN0_AIN3,
 MUX_AIN1_AIN3,
 MUX_AIN0_GND,
 MUX_AIN1_GND,
 MUX_AIN2_GND,
 MUX_AIN3_GND,
};




/* GAIN */
enum ADS1115_PGA
{
    FSR_0			= 0,
    FSR_1,
    FSR_2,  // DEFAULT
    FSR_3,
    FSR_4,
    FSR_5,
    AFSR_6,
    FSR_7
};

enum ADS1115_MODE
{
    MODE_CONTINUOUS_CONV = 0,
    MODE_SINGLE_SHOT, //   //  1 = default
    //MODE_POWER_DOWN   1 //default
 };


// Data Rate
enum ADS1115_DR
{
    SPS_8 = 0,
    SPS_16,
    SPS_32,
    SPS_64,
    SPS_128, //default
    SPS_250,
    SPS_475,
    SPS_860
 };

//Comparator Mode
enum ADS1115_COMP_MODE
{
    TRANDITIONAL_COMPARATOR = 0,
    WINDOWS_COMPARATOR
};

//Comparator polarity
enum ADS1115_COMP_POL
{
    ACTIVE_LOW = 0,
    ACTIVE_HIGH
};

//Latching Comparator
enum ADS1115_COMP_LAT
{
    NON_LATCHING_COMPARATOR = 0,
    LATCHING_COMPARATOR
};

//Comparator Queue and Disable

enum ADS1115_COMP_QUE
{
    ASSERT_AFTER_ONE_CONVERSION = 0,
    ASSERT_AFTER_TWO_CONVERSION,
    ASSERT_AFTER_FOUR_CONVERSION,
    SET_ALERT_RDY  // disable Comaparator

};



struct RG3BST
{
 uint8_t   OS    ;   // bit 8
 uint8_t    MUX    ;  // bit 4-5-6
 uint8_t    PGA    ;   // bit 1-2-3
 uint8_t    MODE   ;  // bit 0
};


struct RG2BST
{
  uint8_t   DR     ;    // Bit 5-6-7
  uint8_t   COMP_MODE;  // bit 4
  uint8_t   COMP_POL;    // bit 3
  uint8_t   COMP_LAT ;    // bit 2
  uint8_t   COMP_QUE;    // bit 0-1
};
struct RG1BST
{
  uint8_t  NC;
  uint8_t P;
};


struct ASD1115_CONFIG_REGISTER
{
 RG3BST rg3;
 RG2BST rg2;
 RG1BST rg1;

 uint8_t config[3] ;

 void PrepareConfig ()
 {
   config[0] = rg1.P ;
   config[1] = 0;
   config[1] = rg2.COMP_QUE | rg2.COMP_LAT<< 2 | rg2.COMP_POL << 3 |  rg2.COMP_MODE << 4 |  rg2.DR << 5;
   config[2] = rg3.MODE     | rg3.PGA <<  1    | rg3.MUX      << 4 |  rg3.OS << 7;
   qDebug()<<"Registre_1 ="<<hex<<config[0] ;
   qDebug()<<"Registre_2 ="<<hex<<config[1] ;
   qDebug()<<"Registre_3 ="<<hex<<config[2] ;
 }
};



#endif // ADS1115API_H
