#include <ncurses.h>
#include <stdlib.h>     // needed for malloc()

// struct that defines room atributes
typedef struct Room {
    // top left coordinate of the room
    int xPos;
    int yPos;

    // room dimensions
    int height;
    int width;
    
    // monsters inside the room
    // Monster** monsters;    // array of pointers of type Monster

    // items inside the room
    // Items** items;    // array of pointers of type Item
} Room;

// struct that defines player atributes
typedef struct Player {
    int xPos;
    int yPos;
    int health;
} Player;

// function headers
int screenSetup();
Room** mapSetup();
Player* playerSetup();
int handleInput(int input, Player* user);
int playerMove(int x, int y, Player* user);
int checkPosition(int newX, int newY, Player* user);

/* room functions */
Room* createRoom(int x, int y, int height, int width);
int drawRoom(Room* room);

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

Room** mapSetup(){  // it returns an array of rooms
    Room** rooms;   // array of rooms
    rooms = malloc(sizeof(Room)*6);     // reserves space in memory to 6 type Room

    rooms[0] = createRoom(13, 13, 6, 8);
    drawRoom(rooms[0]);
    rooms[1] = createRoom(40, 2, 6, 8);
    drawRoom(rooms[1]);
    rooms[2] = createRoom(40, 10, 6, 12);
    drawRoom(rooms[2]);

    return rooms;
}

Room* createRoom(int x, int y, int height, int width){
    Room* newRoom;                      // creating newRoom pointer to Room
    newRoom = malloc(sizeof(Room));     // reserving memory space to 1 Room
    
    // initializing newRoom attributes
    newRoom->xPos = x;
    newRoom->yPos = y;
    newRoom->height = height;
    newRoom->width = width;

    return newRoom;
}

int drawRoom(Room* room){
    // draw north and south walls
    for (int x=room->xPos; x<room->xPos + room->width; x++){
        mvprintw(room->yPos, x, "-");        
        mvprintw(room->yPos+room->height-1, x, "-");        
    }
    
    // draw east and west walls and floor
    for (int y=room->yPos + 1; y<room->yPos + room->height-1; y++){
        mvprintw(y, room->xPos, "|");        
        mvprintw(y, room->xPos+room->width-1, "|");
        for (int x = room->xPos+1; x<room->xPos+room->width-1; x++){
            mvprintw(y,x,".");
        }
    }
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
