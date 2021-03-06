//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		OnyxSPI.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "OnyxSPI.h"


OnyxSPI::OnyxSPI()
{
}

OnyxSPI::~OnyxSPI()
{
}

bool OnyxSPI::spiInit()
{
#ifndef NDEBUG
	bcm2835_set_debug(1);
#endif // !NDEBUG
	
	if (!bcm2835_init())         // initialize library
	{
		std::cout << "OnyxSPI::spiInit : bcm2835_init failed!\n";
		return false;
	}

	if (!bcm2835_spi_begin())        // start SPI library, Setup SPI pins
	{
		std::cout << "OnyxSPI::spiInit : bcm2835_spi_begin failed!\n";
		return false;
	}

	//Set CS pins polarity to low
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, 0);
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, 0);

	//Set SPI clock speed
		//	BCM2835_SPI_CLOCK_DIVIDER_65536 = 0,       ///< 65536 = 262.144us = 3.814697260kHz (total H+L clock period)
		//	BCM2835_SPI_CLOCK_DIVIDER_32768 = 32768,   ///< 32768 = 131.072us = 7.629394531kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_16384 = 16384,   ///< 16384 = 65.536us = 15.25878906kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_8192  = 8192,    ///< 8192 = 32.768us = 30/51757813kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_4096  = 4096,    ///< 4096 = 16.384us = 61.03515625kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_2048  = 2048,    ///< 2048 = 8.192us = 122.0703125kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_1024  = 1024,    ///< 1024 = 4.096us = 244.140625kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_512   = 512,     ///< 512 = 2.048us = 488.28125kHz
		//	BCM2835_SPI_CLOCK_DIVIDER_256   = 256,     ///< 256 = 1.024us = 976.5625MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_128   = 128,     ///< 128 = 512ns = = 1.953125MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_64    = 64,      ///< 64 = 256ns = 3.90625MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_32    = 32,      ///< 32 = 128ns = 7.8125MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_16    = 16,      ///< 16 = 64ns = 15.625MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_8     = 8,       ///< 8 = 32ns = 31.25MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_4     = 4,       ///< 4 = 16ns = 62.5MHz
		//	BCM2835_SPI_CLOCK_DIVIDER_2     = 2,       ///< 2 = 8ns = 125MHz, fastest you can get
		//	BCM2835_SPI_CLOCK_DIVIDER_1     = 1,       ///< 1 = 262.144us = 3.814697260kHz, same as 0/65536
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536);

	//Set SPI data mode
		//  BCM2835_SPI_MODE0 = 0,  // CPOL = 0, CPHA = 0, Clock idle low, data is clocked in on rising edge, output data (change) on falling edge
		//	BCM2835_SPI_MODE1 = 1,  // CPOL = 0, CPHA = 1, Clock idle low, data is clocked in on falling edge, output data (change) on rising edge
		//	BCM2835_SPI_MODE2 = 2,  // CPOL = 1, CPHA = 0, Clock idle high, data is clocked in on falling edge, output data (change) on rising edge
		//	BCM2835_SPI_MODE3 = 3,  // CPOL = 1, CPHA = 1, Clock idle high, data is clocked in on rising, edge output data (change) on falling edge
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);

	//Set with CS pin to use for next transfers
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);

	std::cout << "OnyxSPI initialized.\n";
	return true;
}


int OnyxSPI::spiTranceive(uint8_t nDataToSend)
{
	uint16_t nData = bcm2835_spi_transfer(nDataToSend);
	printf("OnyxSPI::spiTranceive,\tSent: %08X, Received data: %08X\n", nDataToSend, nData);
	return nData;
}

STMRESULT OnyxSPI::Control()
{
	for (auto it : m_vSPIVars)
	{
		it->Check();
	}

	return S_READY;
}

bool OnyxSPI::RegisterSPIVar(uint8_t& rTheVariable, string sName)
{
	SPIVar* pVar = new SPIVar(rTheVariable, sName, this);
	m_vSPIVars.push_back(pVar);

	return true;
}

