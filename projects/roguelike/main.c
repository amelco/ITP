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
int handleInput(int input, Player* user);
int playerMove(int x, int y, Player* user);
int checkPosition(int newX, int newY, Player* user);

int main(){
    Player* user;           // pointer of type Player
    int ch;                 // key pressed by the user

    screenSetup();
    mapSetup();
    user = playerSetup();   // Initialization of Player

    // game loop
    while ((ch = getch()) != 'q'){ // wait for user input ans store it in ch
        handleInput(ch, user);      // call function to handle user input

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

    playerMove(newPlayer->yPos, newPlayer->xPos, newPlayer);   // draw player
    
    return newPlayer;
}

int handleInput(int input, Player* user){
    int newX = 0;
    int newY = 0;
    switch (input){
        // move up
        case 'w':
        case 'W':
            newX =user->xPos; 
            newY =user->yPos - 1; 
            // playerMove(user->xPos, user->yPos - 1, user);
            break;
        // move left
        case 'a':
        case 'A':
            newX =user->xPos - 1; 
            newY =user->yPos; 
            // playerMove(user->xPos - 1, user->yPos, user);
            break;
        // move down
        case 's':
        case 'S':
            newX =user->xPos; 
            newY =user->yPos + 1; 
            // playerMove(user->xPos, user->yPos + 1, user);
            break;
        // move right
        case 'd':
        case 'D':
            newX =user->xPos + 1; 
            newY =user->yPos; 
            // playerMove(user->xPos + 1, user->yPos, user);
            break;

        default:
            break;
    }
    checkPosition(newX, newY, user);
    
    return 0;
}

// check what is at player's next position 
int checkPosition(int newX, int newY, Player* user){
    int newPos;
    switch (mvinch(newY, newX)){    // gets character of the Y and X coordinates
        // free space (player can move)
        case '.':
            playerMove(newX, newY, user);
            break;
       default:
            move(user->yPos, user->xPos);
            break;
    }
    return 0;
}

int playerMove(int x, int y, Player* user){
    mvprintw(user->yPos, user->xPos, ".");      // current player location is now empty
    
    // update player coordinates
    user->xPos = x;
    user->yPos = y;
    
    mvprintw(user->yPos, user->xPos, "@");      // draw new player current location
    move(y, x);                                 // move cursor back to player initial position

    return 0;
}
