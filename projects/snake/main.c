#include <stdio.h>
#include <curses.h>     // adds screen buffer and other functions like mvprintw
#include <time.h>       // needed to calculate elapsedTime
#include <math.h>       // needed to calculate fmod()

int debug = 1;

// game resolution
int const screenWidth = 120;
int const screenHeight = 40;

struct timespec tstart={0,0}, tend={0,0};
double elapsedTime = 0.0;

int ups = 2, usups = 0;     // updates per second, updates per microseconds
int frames = 0;

void printDebug(){
    mvprintw(screenHeight+2, 0, "Elapsed time: %lf", elapsedTime);
    mvprintw(screenHeight+3, 0, "frames: %2d", frames);
    mvprintw(screenHeight+4, 0, "ups: %2d", ups);
}

void clearScreen(){
    for (int i=0; i<screenWidth*screenHeight; i++){
        mvprintw(i/screenWidth, i%screenWidth, " ");
    }
}

void update(){
    // GAME TICK (60 fps)
    usups = ((61-ups)/60.0 * 1000000);
    usleep(usups); // try nanosleep() to get rid of the warning
    frames++;
    
    if (frames>2) {
        ups+=5;
        frames=0;
        if (ups>30) ups=30;
    }
    
}

void draw(){
    clearScreen();
    // for debug only
    if (debug) printDebug();
    
    // draw borders
    for (int i=0; i<screenWidth*screenHeight; i++){
        int x = i/screenWidth;
        int y = i%screenWidth;
        if (x==0 || x==screenHeight-1) mvprintw(x,y, "#");
        if (y==0 || y==screenWidth-1) mvprintw(x,y, "#");

    }
}

int main(){
    // start curses mode
    initscr();
    
    // initiate time
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    while(1){    
        // update game state
        update();

        // draw to screen buffer
        draw();

        // draw to (update) screen
        refresh();

        // get user input
        // getch();

        // update time
        clock_gettime(CLOCK_MONOTONIC, &tend);
        elapsedTime = ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
    }

    // end curses mode
    endwin();
    
    return 0;
}