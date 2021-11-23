#include <iostream>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
int main()
{
	char ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
	char personaje = 'O';
	int personaje_x = 10;
	int personaje_y = 5;
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (i== 0 || i== CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
			{
				ConsoleScreen[i][j] = '#';
			}
			else {
				ConsoleScreen[i][j] = '-';
			}	
		}	

	}
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (personaje_x == j && personaje_y == i ) {
				cout << personaje;
			
			}
			else
			{
				cout << ConsoleScreen[i][j];
			}
			
		}
		cout << endl; 
	}
}