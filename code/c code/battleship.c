#include <iostream>

using namespace std;

int Ccounter, Bcounter, Rcounter, Scounter, Dcounter, allCounter = 0;

int myarray[10][10] =
	{
        {'C', 'C', 'C', 'C', 'C',  0 ,  0 ,  0 ,  0 ,  0 }, // C - Carrier
        { 0 ,  0 ,  0 ,  0 , 'B',  0 ,  0 ,  0 ,  0 ,  0 }, // B - Battleship
		{ 0 ,  0 ,  0 ,  0 , 'B',  0 ,  0 ,  0 ,  0 ,  0 }, // R - Crusier
		{ 0 ,  0 ,  0 ,  0 , 'B',  0 ,  0 ,  0 ,  0 ,  0 }, // S - Submarine
		{ 0 ,  0 ,  0 ,  0 , 'B',  0 ,  0 ,  0 ,  0 ,  0 }, // D - Destroyer
		{ 0 ,  0 ,  0 ,  0 ,  0 , 'R', 'R', 'R',  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 , 'S',  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 , 'S',  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 , 'S',  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 , 'D', 'D'}
	};
	
void trackCounter(int Ccounter, int Bcounter, int Rcounter, int Scounter, int Dcounter)
{
    if (Ccounter == 5)
    {
        cout << "Carriership has been SUNK" << endl;
    }
    else if (Bcounter == 4)
    {
        cout << "Battleship has been SUNK" << endl;
    }
    else if (Rcounter == 3)
    {
        cout << "CruiserShip has been SUNK" << endl;
    }
    else if (Scounter == 3)
    {
        cout << "Submarineship has been SUNK" << endl;
    }
    else if (Dcounter == 2)
    {
        cout << "Destroyership has been SUNK" << endl;
    }
}

void print(int myarray[][10], int rowSize, int columnSize)
{
        for (int i = 0; i < rowSize; i++)
    {
        cout << "  ";
        for (int j = 0; j < columnSize; j++)
        {
            cout << "  " << myarray[i][j];
        }
        cout << endl;
    }

};

void fire(int row, int column, int myarray[][10], int rowSize, int columnSize)
{
    if (myarray[row][column] == 0)
    {
        cout << "Its a MISS" << endl;
    }
    
    if (myarray[row][column] == 'C')
    {
        myarray[row][column] = 0;
        Ccounter = Ccounter + 1;
        allCounter = allCounter + 1;
        cout << "Carrier Ship has been hit" << endl;
    }
    
    if (myarray[row][column] == 'B')
    {
        myarray[row][column] = 0;
        Bcounter = Bcounter + 1;
        allCounter = allCounter + 1;
        cout << "Battle Ship has been hit" << endl;
    }
    
    if (myarray[row][column] == 'R')
    {
        myarray[row][column] = 0;
        Rcounter = Rcounter + 1;
        allCounter = allCounter + 1;
        cout << "Cruiser Ship has been hit" << endl;
    }
    
    if (myarray[row][column] == 'S')
    {
        myarray[row][column] = 0;
        Scounter = Scounter + 1;
        allCounter = allCounter + 1;
        cout << "Submarine Ship has been hit" << endl;
    }
    
    if (myarray[row][column] == 'D')
    {
        myarray[row][column] = 0;
        Dcounter = Dcounter + 1;
        allCounter = allCounter + 1;
        cout << "Destroyer Ship has been hit" << endl;
    }
    
}
    

int main() {
    int inputRow, inputColumn;
	cout << "Welcome to Battleship" << endl;
	cout << "The grid is 10 by 10" << endl;
    while(1)
    {
        if(allCounter < 17)
        {
	        cout << "Choose Row: ";
	        cin >> inputRow;
	        cout << "Choose Column: ";
	        cin >> inputColumn;
	        fire(inputRow, inputColumn, myarray, 10, 10);
	        trackCounter(Ccounter, Bcounter, Rcounter, Scounter, Dcounter);
	        cout << endl;
        }
        else
        {
            cout << "All ships are SUNK" << endl;
            cout << "Game Over" << endl;
            break;
        }
    }
	

    return 0;
}