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
          		refresh(); /* notice! refresh() is here! */
          }
		  getch();
          endwin();
}
