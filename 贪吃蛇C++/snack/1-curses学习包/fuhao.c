#include <stdio.h>
#include <curses.h>
/*    特殊符号
        ACS_ULCORNER    ┌  	ACS_LLCORNER    └ 	ACS_URCORNER    ┐  	ACS_LRCORNER  ┘

        ACS_LTEE        ├  	ACS_RTEE        ┤  	ACS_BTEE        ┴  	ACS_TTEE      ┬

        ACS_HLINE       ─  	ACS_VLINE       │  	ACS_PLUS        ┼  	ACS_S1        

        ACS_S9            ACS_DIAMOND 		◆ 	ACS_CKBOARD 	▒  	ACS_DEGREE 	 ° 

        ACS_PLMINUS 	±   ACS_BULLET  	·   ACS_UARROW  	^  	ACS_BOARD     #

        ACS_LANTERN 	␋ 	ACS_BLOCK       #   ACS_S3            	ACS_S7        

        ACS_LEQUAL  	≤ 	ACS_GEQUAL  	≥  	ACS_PI          π  	ACS_NEQUAL 	 ≠

        ACS_STERLING    £   ACS_BSSB        ┌  	ACS_SSBB        └  	ACS_BBSS      ┐

        ACS_SBBS        ┘  	ACS_SBSS        ┤  	ACS_SSSB        ├  	ACS_SSBS      ┴

        ACS_BSSS        ┬  	ACS_BSBS        ─  	ACS_SBSB        │  	ACS_SSSS      ┼
*/

int lenth = 25 , width = 60;
int main(){
	initscr();

	WINDOW*  midscreen;
	midscreen = newwin(lenth,width,2,4);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int a = ACS_CKBOARD;
	wborder(midscreen,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen);
	WINDOW*  midscreen1;
	midscreen1 = newwin(lenth,width-2,2,5);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int b = ACS_CKBOARD;
	wborder(midscreen1,b,b,b,b,b,b,b,b);
	refresh();
	wrefresh(midscreen1);

	getch();
	endwin();
	return 0;
}
