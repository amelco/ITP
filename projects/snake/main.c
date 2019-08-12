#include <stdio.h>
#include <curses.h>

int screenWidth = 120;
int screenHeight = 40;

int main(){
    initscr();
    printw("Hello World!", 2, 2);
    refresh();
    getch();
    endwin();
    
    return 0;
}