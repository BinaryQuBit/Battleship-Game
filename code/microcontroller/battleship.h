#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED
void powerPeripherals(void);
void configureIO(void);
void turnOnLED(void);
void delay(void);
void delay1(void);
int inputRow();
int inputColumn();
void pressButton();
void trackCounter(int &Ccounter, int &Bcounter, int &Rcounter, int &Scounter, int &Dcounter);
void fire(int row, int column, int myarray[][10]);
void button();
void test();
#endif
