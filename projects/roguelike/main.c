#include <ncurses.h>
#include <stdlib.h>     // needed for malloc()

// struct that defines player atributes
typedef struct Player {
    int xPos;
    int yPos;
    int health;
} Player;

// function headers
int screenSetup();
int mapSetup();
Player* playerSetup();

int main(){
    Player* user;           // pointer of type Player
    int ch;                 // key pressed by the user

    screenSetup();
    mapSetup();
    user = playerSetup();   // Initialization of Player

    // game loop
    while ((ch = getch()) != 'q'){ // wait for user input ans store it in ch

    }

    endwin();      // quits ncurses
    return 0;

}

int screenSetup(){
    initscr();      // initialize ncurses
    printw("Hello world");      // print to buffer
    noecho();                   // does not show characters as user types
    refresh();
    
    return 0;                   // print to screen
}

int mapSetup(){
    mvprintw(13, 13, "--------");   // print in a x, y position of screen
    mvprintw(14, 13, "|......|");
    mvprintw(15, 13, "|......|");
    mvprintw(16, 13, "|......|");
    mvprintw(17, 13, "|......|");
    mvprintw(18, 13, "--------");

    mvprintw(2, 40, "--------");
    mvprintw(3, 40, "|......|");
    mvprintw(4, 40, "|......|");
    mvprintw(5, 40, "|......|");
    mvprintw(6, 40, "|......|");
    mvprintw(7, 40, "--------");

    mvprintw(10, 40, "------------");
    mvprintw(11, 40, "|..........|");
    mvprintw(12, 40, "|..........|");
    mvprintw(13, 40, "|..........|");
    mvprintw(14, 40, "|..........|");
    mvprintw(15, 40, "------------");

    return 0;
}

// function that initializes newPlayer and returns a pointer of type Player
Player* playerSetup(){
    Player* newPlayer;      // declaring newPlayer variable (pointer)
    newPlayer = malloc(sizeof(Player));     // reserve a spcae in memory to the Player variable

    // initialize Player attributes
    newPlayer->xPos = 14;
    newPlayer->yPos = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->yPos, newPlayer->xPos, "@");    // draw player
    move(newPlayer->yPos, newPlayer->xPos);   // move cursor back to player initial position
    
    return newPlayer;
}