#include <iostream>
using namespace std;    
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

void RellenarMapa();
void Inputs();
void Logica();
void ImprimirPantalla();

enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };
enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };

//Caracteres para imprimir en consola
MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
int map_points = 0;
char personaje = 'O';
//Posicion inicial del jugador en consola
int personaje_x = 10;
int personaje_y = 5;
int personaje_points = 0;
USER_INPUTS input = USER_INPUTS::NONE;
bool run = true;

int main()
{
    RellenarMapa();
    ImprimirPantalla();
    while (run)
    {
        Inputs();
        Logica();
        ImprimirPantalla();
    }
}
void RellenarMapa()
{
    //Valores y posiciones que se dan para la fila y la columna 
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
            {
                ConsoleScreen[i][j] = MAP_TILES::WALL;
            }
            else
            {
                ConsoleScreen[i][j] = MAP_TILES::EMPTY;
            }
        }
    }
    //Teletransporte Horizontal
    ConsoleScreen[2][0] = MAP_TILES::EMPTY;
    ConsoleScreen[3][0] = MAP_TILES::EMPTY;
    ConsoleScreen[2][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
    ConsoleScreen[3][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
  
   //Teletransporte Vertical
    ConsoleScreen[0][15] = MAP_TILES::EMPTY;
    ConsoleScreen[0][16] = MAP_TILES::EMPTY;
    ConsoleScreen[0][17] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][15] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][16] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][17] = MAP_TILES::EMPTY;
    ConsoleScreen[0][95] = MAP_TILES::EMPTY;
    ConsoleScreen[0][96] = MAP_TILES::EMPTY;
    ConsoleScreen[0][97] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][95] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][96] = MAP_TILES::EMPTY;
    ConsoleScreen[CONSOLE_HEIGHT - 1][97] = MAP_TILES::EMPTY;

}

void Inputs()
{
    char input_raw;
    cin >> input_raw;
    switch (input_raw)
    {
    case 'W':
    case 'w':
        input = USER_INPUTS::UP;
        break;
    case 'A':
    case 'a':
        input = USER_INPUTS::LEFT;
        break;
    case 'S':
    case 's':
        input = USER_INPUTS::DOWN;
        break;
    case 'D':
    case 'd':
        input = USER_INPUTS::RIGHT;
        break;
    case 'Q':
    case 'q':
        input = USER_INPUTS::QUIT;
        break;
    default:
        input = USER_INPUTS::NONE;
        break;
    }
}

void Logica()
{
    int personaje_y_new = personaje_y;
    int personaje_x_new = personaje_x;
    switch (input)
    {
    case UP:
        personaje_y_new--;
        break;
    case DOWN:
        personaje_y_new++;
        break;
    case RIGHT:
        personaje_x_new++;
        break;
    case LEFT:
        personaje_x_new--;
        break;
    case QUIT:
        run = false;
        break;
    }
    if (personaje_x_new < 0) {
        personaje_x_new = CONSOLE_WIDTH - 1;
    }
    personaje_x_new %= CONSOLE_WIDTH;
    if (personaje_y_new < 0) {
        personaje_y_new = CONSOLE_HEIGHT - 1;
    }
    personaje_y_new %= CONSOLE_HEIGHT;
    if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
        personaje_y_new = personaje_y;
        personaje_x_new = personaje_x;
    }
    else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::POINT) {
        map_points--;
        personaje_points++;
        ConsoleScreen[personaje_y_new][personaje_x_new] = MAP_TILES::EMPTY;
    }
    personaje_y = personaje_y_new;
    personaje_x = personaje_x_new;
}

void ImprimirPantalla()
{
    system("CLS");
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            if (personaje_x == j && personaje_y == i)
            {
                cout << personaje;
            }
            else
            {
                cout << (char)ConsoleScreen[i][j];
            }
        }
        cout << endl;
    }
}
