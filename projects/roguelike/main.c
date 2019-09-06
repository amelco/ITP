#include <ncurses.h>
#include <stdlib.h>     // needed for malloc()
#include <time.h>       // to use inside srand()

typedef struct Position {
    int x;
    int y;
} Position;

// struct that defines room atributes
typedef struct Room {
    // top left coordinate of the room
    Position position;

    // room dimensions
    int height;
    int width;

    Position door[4];
    
    // monsters inside the room
    // Monster** monsters;    // array of pointers of type Monster

    // items inside the room
    // Items** items;    // array of pointers of type Item
} Room;

// struct that defines player atributes
typedef struct Player {
    Position position;
    int health;
    // Room* room;     // tells wich room the player is
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
    srand(time(NULL));      // seed to call rand()
    
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
    newRoom->position.x = x;
    newRoom->position.y = y;
    newRoom->height = height;
    newRoom->width = width;


    // top door
    newRoom->door[0].x = rand() % (width - 2) + newRoom->position.x + 1;
    newRoom->door[0].y = newRoom->position.y;

    // bottom door
    newRoom->door[1].x = rand() % (width - 2) + newRoom->position.x + 1;
    newRoom->door[1].y = newRoom->position.y + newRoom->height - 1;
    
    // left door
    newRoom->door[2].x = newRoom->position.x;
    newRoom->door[2].y = rand() % (height - 2) + newRoom->position.y + 1;
    
    // right door
    newRoom->door[3].x = newRoom->position.x + newRoom->width - 1;
    newRoom->door[3].y = rand() % (height - 2) + newRoom->position.y + 1;

    return newRoom;
}

int drawRoom(Room* room){
    // draw north and south walls
    for (int x=room->position.x; x<room->position.x + room->width; x++){
        mvprintw(room->position.y, x, "-");        
        mvprintw(room->position.y+room->height-1, x, "-");        
    }
    
    // draw east and west walls and floor
    for (int y=room->position.y + 1; y<room->position.y + room->height-1; y++){
        mvprintw(y, room->position.x, "|");        
        mvprintw(y, room->position.x+room->width-1, "|");
        for (int x = room->position.x+1; x<room->position.x+room->width-1; x++){
            mvprintw(y,x,".");
        }
    }

    // draw doors
    for (int i=0; i<4; i++){
        mvprintw(room->door[i].y, room->door[i].x, "#");
    }

    return 0;
}

// function that initializes newPlayer and returns a pointer of type Player
Player* playerSetup(){
    Player* newPlayer;      // declaring newPlayer variable (pointer)
    newPlayer = malloc(sizeof(Player));     // reserve a spcae in memory to the Player variable

    // initialize Player attributes
    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    playerMove(newPlayer->position.y, newPlayer->position.x, newPlayer);   // draw player
    
    return newPlayer;
}

int handleInput(int input, Player* user){
    int newX = 0;
    int newY = 0;
    switch (input){
        // move up
        case 'w':
        case 'W':
            newX =user->position.x; 
            newY =user->position.y - 1; 
            // playerMove(user->position.x, user->position.y - 1, user);
            break;
        // move left
        case 'a':
        case 'A':
            newX =user->position.x - 1; 
            newY =user->position.y; 
            // playerMove(user->position.x - 1, user->position.y, user);
            break;
        // move down
        case 's':
        case 'S':
            newX =user->position.x; 
            newY =user->position.y + 1; 
            // playerMove(user->position.x, user->position.y + 1, user);
            break;
        // move right
        case 'd':
        case 'D':
            newX =user->position.x + 1; 
            newY =user->position.y; 
            // playerMove(user->position.x + 1, user->position.y, user);
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
            move(user->position.y, user->position.x);
            break;
    }
    return 0;
}

int playerMove(int x, int y, Player* user){
    mvprintw(user->position.y, user->position.x, ".");      // current player location is now empty
    
    // update player coordinates
    user->position.x = x;
    user->position.y = y;
    
    mvprintw(user->position.y, user->position.x, "@");      // draw new player current location
    move(y, x);                                 // move cursor back to player initial position

    return 0;
}
