//Name: Amandip Padda
//SID: 200455829
//Class: ENSE 352
//Description: Battleship Game
#include "stm32f10x.h"
#include "battleship.h"

using namespace std;
static int Ccounter, Bcounter, Rcounter, Scounter, Dcounter, allCounter = 0;


//This is a 2d array that stores the required data for ships
static int myarray[10][10] =
{
    { 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 }, // C - Carrier
    { 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 }, // B - Battleship
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 }, // R - Crusier
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 }, // S - Submarine
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 }, // D - Destroyer
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 , 'D', 'D'}
	};
			 
int main()
  {
	powerPeripherals(); //power clocks
	configureIO(); //configure output pins
	turnOnLED(); // turning led on
	while(1)
		{
			if(allCounter < 2) // number of ships
				{
					int x = inputRow();
					if(x == 69)
					{
						continue;
					}					
					columnAgain: int y = inputColumn();
					if(y == 69)
					{
						goto columnAgain;
					}
					
					fire(x, y, myarray); // sends the row and column + array to the function
					trackCounter(Ccounter, Bcounter, Rcounter, Scounter, Dcounter); // this is to track the number of times the ship was hit
				}
			else // an error function to display game over sequence
				{
					while(1)
					{
							GPIOA->ODR |= GPIO_ODR_ODR0;
							delay1();
							GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
					
							GPIOA->ODR |= GPIO_ODR_ODR1;
							delay1();
							GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR1;
					
							GPIOA->ODR |= GPIO_ODR_ODR4;
							delay1();
							GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR4;
					
							GPIOB->ODR |= GPIO_ODR_ODR0;
							delay1();
							GPIOB->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
					
							GPIOC->ODR |= GPIO_ODR_ODR11;
							delay1();
							GPIOC->ODR &= (uint32_t) ~GPIO_ODR_ODR11;
						
							GPIOC->ODR |= GPIO_ODR_ODR12;
							delay1();
							GPIOC->ODR &= (uint32_t) ~GPIO_ODR_ODR12;
					
							GPIOD->ODR |= GPIO_ODR_ODR2;
							delay1();
							GPIOD->ODR &= (uint32_t) ~GPIO_ODR_ODR2;
					
							GPIOA->ODR |= GPIO_ODR_ODR10;
							delay1();
							GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR10;
				}
				}
		}
}


void powerPeripherals() //power clocks
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN; 
}

void configureIO() // configure output pins
{
	GPIOA->CRL |=  GPIO_CRL_MODE0_0 |  GPIO_CRL_MODE0_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0_1;
	
	GPIOA->CRL |=  GPIO_CRL_MODE1_0 |  GPIO_CRL_MODE1_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1_0 &~ GPIO_CRL_CNF1_1;
	
	GPIOA->CRL |=  GPIO_CRL_MODE4_0 |  GPIO_CRL_MODE4_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF4_0 &~ GPIO_CRL_CNF4_1;
	
	GPIOB->CRL |=  GPIO_CRL_MODE0_0 |  GPIO_CRL_MODE0_1;
	GPIOB->CRL &= ~GPIO_CRL_CNF0_0 &~ GPIO_CRL_CNF0_1;
	
	GPIOC->CRH |=  GPIO_CRH_MODE11_0 |  GPIO_CRH_MODE11_1;
	GPIOC->CRH &= ~GPIO_CRH_CNF11_0 &~ GPIO_CRH_CNF11_1;
	
	GPIOC->CRH |=  GPIO_CRH_MODE12_0 |  GPIO_CRH_MODE12_1;
	GPIOC->CRH &= ~GPIO_CRH_CNF12_0 &~ GPIO_CRH_CNF12_1;
	
	GPIOD->CRL |=  GPIO_CRL_MODE2_0 |  GPIO_CRL_MODE2_1;
	GPIOD->CRL &= ~GPIO_CRL_CNF2_0 &~ GPIO_CRL_CNF2_1;
	
	GPIOA->CRH |=  GPIO_CRH_MODE10_0 |  GPIO_CRH_MODE10_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF10_0 &~ GPIO_CRH_CNF10_1;
	
	//Test
	GPIOA->CRL |=  GPIO_CRL_MODE3_0 |  GPIO_CRL_MODE3_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF3_0 &~ GPIO_CRL_CNF3_1;
	
}

void turnOnLED() // turning on the leds
{
		GPIOA->ODR |= GPIO_ODR_ODR5;
		
		GPIOA->ODR |= GPIO_ODR_ODR0;
		
		GPIOA->ODR |= GPIO_ODR_ODR1;
		
		GPIOA->ODR |= GPIO_ODR_ODR4;
		
		GPIOB->ODR |= GPIO_ODR_ODR0;
		
		GPIOC->ODR |= GPIO_ODR_ODR11;
}

void trackCounter(int &CCounter, int &BCounter, int &RCounter, int &SCounter, int &DCounter) // turning the led off as soon as the counter reaches a number of ships
{
	if (CCounter == 5)
	{
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
  }
  if (BCounter == 4)
  {
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR1;
  }
  if (RCounter == 3)
  {
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR4;
  }
  if (SCounter == 3)
  {
		GPIOB->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
  }
  if (DCounter == 2)
  {
		GPIOC->ODR &= (uint32_t) ~GPIO_ODR_ODR11;
  }
}

void fire(int Row, int Column, int myArray[][10]) // check the input wirh the array
{
	if (myArray[Row][Column] == 0)
	{
		GPIOD->ODR |= GPIO_ODR_ODR2;
		GPIOC->ODR |= GPIO_ODR_ODR12;
		delay();
		GPIOD->ODR &= (uint32_t) ~GPIO_ODR_ODR2;
		GPIOC->ODR &= (uint32_t) ~GPIO_ODR_ODR12;
  }
    
	if (myArray[Row][Column] == 'C')
  {
		myArray[Row][Column] = 0;
    Ccounter = Ccounter + 1;
    allCounter = allCounter + 1;
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
		delay();
		GPIOA->ODR |= GPIO_ODR_ODR0;
  }
    
	if (myArray[Row][Column] == 'B')
  {
		myArray[Row][Column] = 0;
    Bcounter = Bcounter + 1;
    allCounter = allCounter + 1;
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR1;
		delay();
		GPIOA->ODR |= GPIO_ODR_ODR1;
  }
    
  if (myarray[Row][Column] == 'R')
  {
		myarray[Row][Column] = 0;
    Rcounter = Rcounter + 1;
    allCounter = allCounter + 1;
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR4;
		delay();
		GPIOA->ODR |= GPIO_ODR_ODR4;
    }
    
	if (myArray[Row][Column] == 'S')
  {
		myArray[Row][Column] = 0;
    Scounter = Scounter + 1;
    allCounter = allCounter + 1;
		GPIOB->ODR &= (uint32_t) ~GPIO_ODR_ODR0;
		delay();
		GPIOB->ODR |= GPIO_ODR_ODR0;
    }
    
	if (myArray[Row][Column] == 'D')
	{
		myarray[Row][Column] = 0;
    Dcounter = Dcounter + 1;
    allCounter = allCounter + 1;
		GPIOC->ODR &= (uint32_t) ~GPIO_ODR_ODR11;
		delay();
		GPIOC->ODR |= GPIO_ODR_ODR11;
    }
}

int inputRow() // input row 
{
	GPIOD->ODR |= GPIO_ODR_ODR2;
	button();
	int rowValue = (GPIOC->IDR & 0x0000000F);
	if(rowValue > 9)
		{
				for(int i = 0; i < 3; i++)
				{
				GPIOD->ODR &= (uint32_t) ~GPIO_ODR_ODR2;
				delay();
				GPIOD->ODR |= GPIO_ODR_ODR2;
				delay();
				}
				return 69;			
			}
			else
			{
				GPIOD->ODR &= (uint32_t) ~GPIO_ODR_ODR2;
				return rowValue;
			}
		}

void button() // a stopping mechanism with the button
{
	while(1)
	{
		if(((GPIOC->IDR) & 0x00000700) == 0x00000700)
		{
			break;
		}
	}
	delay();
}

int inputColumn() // input column
{
	GPIOA->ODR |= GPIO_ODR_ODR10;
	button();
	int rowValue = (GPIOC->IDR & 0x0000000F);
	if(rowValue > 9)
		{
				for(int i = 0; i < 3; i++)
				{
				GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR10;
				delay();
				GPIOA->ODR |= GPIO_ODR_ODR10;
				delay();
				}
				return 69;			
			}
			else
			{
				GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR10;
				return rowValue;
			}
		}

void delay() // delay the button
{	
	unsigned volatile int c, d;  
   for (c = 1; c <= 2000; c++)
       for (d = 1; d <= 2000; d++)
       {}
}

void delay1() //  delay the leds for game over
{	
	unsigned volatile int c, d;  
   for (c = 1; c <= 1000; c++)
       for (d = 1; d <= 1000; d++)
       {}
}
