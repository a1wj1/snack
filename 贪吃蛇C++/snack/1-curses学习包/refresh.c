#include <stdio.h>
#include <curses.h>

int main()
{
          int line;
          char c;

          initscr();
          refresh();
          for(line=0;line<LINES;line++){
                  move(line,line);
                  c=line+'0';
                  addch(c);
                 //for(i=0;i<500000;i++);
          }
          getch();
          refresh(); /* notice! refresh() is here! */
          endwin();

}
