#include <stdio.h>
#include <curses.h>
#include <unistd.h>//设置sleep函数
#include <stdlib.h>//设置随机数
#include <time.h>

int beginy = 3;//蛇的起始位置x
int beginx = 6;//蛇的起始位置y
int snack[1500][2][2];//蛇 各个节点的位置
int wlenth = 25 , width = 60;//界面大小
int speed = 12;//爬行速度
int lenth;//蛇的长度
int ra,rb;//食物的坐标(ra,rb)
int score;//得分
WINDOW*  midscreen2;//创建的窗口midscreen2
int F = 4;//设置蛇方向F: 上、下、左、右 分别对应 1、2、3、4

//cut函数将数组内存的 上一个坐标转变成下一个坐标
void cut(int lenth,int snack[1500][2][2]){
    for(int k=1;k<=lenth;k++){
        for(int j=0;j<2;j++){
            snack[k][j][0] = snack[k+1][j][0];
            snack[k][j][1] = snack[k+1][j][1];
        }
    }
    lenth -= 1;
}

//设置蛇的方向问题
void direction(int F,int snack[1500][2][2],int lenth){
		//根据方向，给出 snack[lenth] 的新位置
		//F = 1 表示 上
		//F = 2 表示 下
		//F = 3 表示 左
		//F = 4 表示 右
		if(F == 1){
            snack[lenth][0][0] = snack[lenth-1][0][0]-1;
            snack[lenth][0][1] = snack[lenth-1][0][1];
            snack[lenth][1][0] = snack[lenth-1][1][0]-1;
            snack[lenth][1][1] = snack[lenth-1][1][1];
        }
        if(F == 2){
            snack[lenth][0][0] = snack[lenth-1][0][0]+1;
            snack[lenth][0][1] = snack[lenth-1][0][1];
            snack[lenth][1][0] = snack[lenth-1][1][0]+1;
            snack[lenth][1][1] = snack[lenth-1][1][1];
        }
        if(F == 3){
            snack[lenth][0][0] = snack[lenth-1][0][0];
            snack[lenth][0][1] = snack[lenth-1][0][1]-2;
            snack[lenth][1][0] = snack[lenth-1][1][0];
            snack[lenth][1][1] = snack[lenth-1][1][1]-2;
        }
        if(F == 4){
            snack[lenth][0][0] = snack[lenth-1][0][0];
            snack[lenth][0][1] = snack[lenth-1][0][1]+2;
            snack[lenth][1][0] = snack[lenth-1][1][0];
            snack[lenth][1][1] = snack[lenth-1][1][1]+2;
        }
}

//对游戏是否结束进行判断
void judge(bool *paint,bool *end,int lenth,int snack[1500][2][2]){
		//如果撞到左右边框结束
        if(snack[lenth][1][1]>=56 || snack[lenth][0][1]<0 ){
            *paint = 0;
			*end = 1;
        }
		//如果撞到上下边框结束
        if(snack[lenth][0][0]<0 || snack[lenth][1][0]>22){
            *paint = 0;
			*end = 1;
			
        }
        for(int k=1;k<lenth;k++){//如果撞到蛇身结束
                if(snack[k][0][0]== snack[lenth][0][0] &&
                   snack[k][0][1]== snack[lenth][0][1] &&
                   snack[k][1][0]== snack[lenth][1][0] &&
                   snack[k][1][1]== snack[lenth][1][1] ){
                    *paint = 0;
					*end = 1;
                }
        }
}

//对食物进行设置并判断食物是否被吃
void food(int *ra,int *rb,int *score,int *lenth,int snack[1500][2][2],int *speed,WINDOW*  midscreen2){
        //画出食物，并判断蛇是否吃到食物
		if((snack[*lenth][0][0] == *ra&&
			snack[*lenth][0][1] == *rb)||
			(snack[*lenth][0][0] == *ra&&
			snack[*lenth][0][1] == *rb-1)||
			(snack[*lenth][0][0] == *ra&&
			snack[*lenth][0][1] == (*rb+1))
			)
            {
            srand(time(0));
            *ra = rand() % (23);
            *rb = rand() % (55);
            wattron(midscreen2,COLOR_PAIR(2));
            wmove(midscreen2,*ra,*rb);
            wprintw(midscreen2,"+");
            wmove(midscreen2,*ra,*rb+1);
            wprintw(midscreen2,"+");
            wattroff(midscreen2,COLOR_PAIR(2));
            wrefresh(midscreen2);

            *score += 1;
			*lenth += 1;
			
			//设置难度（重置speed值）
			if(*score > 20) *speed = 1;
			else if (*score > 15) *speed = 2;
			else if (*score > 10) *speed = 4;
			else if (*score > 5) *speed = 6;

        }
        else{
            wattron(midscreen2,COLOR_PAIR(2));
            wmove(midscreen2,*ra,*rb);
            wprintw(midscreen2,"+");
            wmove(midscreen2,*ra,*rb+1);
            wprintw(midscreen2,"+");
            wattroff(midscreen2,COLOR_PAIR(2));
            wrefresh(midscreen2);

			cut(*lenth,snack);

        }
}

int main(){
	
	initscr();
	start_color();//开启颜色设置
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);//颜色初始化
	init_pair(2,COLOR_BLACK,COLOR_GREEN);
	init_pair(3,COLOR_BLACK,COLOR_BLACK);
	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	init_pair(5,COLOR_RED,COLOR_BLACK);
	init_pair(6,COLOR_YELLOW,COLOR_BLACK);
    keypad(stdscr,1);
    attron(COLOR_PAIR(3));

    //初始化窗口
    WINDOW*  midscreen;//边框1
	midscreen = newwin(wlenth,width,2,4);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int a = ACS_CKBOARD;
	//wborder(midscreen,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen);
	WINDOW*  midscreen1;//边框2
	midscreen1 = newwin(wlenth,width-2,2,5);
	//wborder(midscreen1,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen1);
	WINDOW*  midscreen2;//游戏主窗口
	midscreen2 = newwin(wlenth-2,width-4,3,6);
	WINDOW*  midscreen3;//游戏开始界面
	midscreen3 = newwin(wlenth-2,width-4,3,6);
	
	keypad(midscreen2,1);
	keypad(midscreen3,1);

    int lenth = 3;//蛇的长度

    refresh();
    wrefresh(midscreen2);

    int F = 4;//设置初始方向
    bool paint = 1;//设置while循环bool量
    
	int start_ch;//开始界面getch的值
	int end_ch;//结束界面getch的值
    
	int ra = 11,rb = 24;//设置食物初始位置
	int score = 0;//设置分数
	bool start = 1;//开始界面的bool值
	bool end = 1;//结束界面的bool值
	bool run = 1;//总运行的bool值
	
while(run){
		curs_set(0);//取消光标闪烁
		
		int lenth = 3;//蛇的长度
		//设置蛇的初始坐标
		int snack[1500][2][2] = {
        {{0,0},{0,0}},
        {{beginy,beginx},{beginy,beginx+1}},
        {{beginy,beginx+2},{beginy,beginx+3}},
        {{beginy+1,beginx+2},{beginy+1,beginx+3}}
		};
	
	//设置游戏登陆界面
	while(start){
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD );
		box(midscreen3,ACS_VLINE,ACS_HLINE);
		mvwprintw(midscreen3,7,16,"welcome to SnackGame !");
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD |A_STANDOUT);
		mvwprintw(midscreen3,12,15,"Enter 'Esc' to end game ");
		mvwprintw(midscreen3,15,15,"Enter  'p'  to end game ");
		wattroff(midscreen3, COLOR_PAIR(6)|A_BOLD |A_STANDOUT);
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD );
		refresh();
		wrefresh(midscreen3);
		//判断输入的字符
		start_ch = wgetch(midscreen3);
		wclear(midscreen3);
		switch(start_ch){
			case 'p':  start = 0; break;
			case 27 :  start = 0; paint = 0;end =0;run =0;break; //27表示的是Esc键
		}
		refresh();
		wrefresh(midscreen3);
	}
    //设置游戏界面
	while(paint){		
        int ch;
		halfdelay(speed);//设置速度
		//（getch函数必须在halfdelay后面）
		ch = getch();
        
		wclear(midscreen2);//清屏
		wclear(midscreen);
		wclear(midscreen1);
		
		wborder(midscreen,a,a,a,a,a,a,a,a);
		wborder(midscreen1,a,a,a,a,a,a,a,a);
		wrefresh(midscreen);
		wrefresh(midscreen1);
		
		food(&ra,&rb,&score,&lenth,snack,&speed,midscreen2);

		//设置键盘功能键
		switch(ch){
			case KEY_UP:  {if(F == 2){break;} F=1;break;}
			case KEY_DOWN:  {if(F == 1){break;} F=2; break;}
			case KEY_LEFT:  {if(F == 4){break;} F=3; break;}
			case KEY_RIGHT:  {if(F == 3){break;} F=4; break;}
			case 27 : {paint=0; end = 1; break;}//27表示的是Esc键
		}
        
		//方向函数
		direction(F,snack,lenth);
		
		//画出蛇身
        for(int k=1;k<=lenth;k++){
            for(int j=0;j<2;j++){
                wmove(midscreen2,snack[k][j][0],snack[k][j][1]);
                wattron(midscreen2,COLOR_PAIR(1));
                wprintw(midscreen2,"%c", '+' );
                wattroff(midscreen2,COLOR_PAIR(1));
            }
        }
		
		//游戏结束判断
		judge(&paint,&end,lenth,snack);

        wmove(midscreen2,0,0);
        curs_set(0);//取消光标闪烁
        
		//输出分数
		move(27,8);
		attron(COLOR_PAIR(4) | A_BOLD);//设置颜色并加粗
		printw("now score is %d",score);
		
		//根据分数打印出相应的难度等级
		if(score<5) mvprintw(28,8,"Difficulty: *		simple");
		else if(score<10) mvprintw(28,8,"Difficulty: **	general");
		else if(score<15) mvprintw(28,8,"Difficulty: ***	difficult");
		else if(score<20) mvprintw(28,8,"Difficulty: ****	Purgatory");
		
		attron(COLOR_PAIR(4) | A_BOLD|A_STANDOUT);
		
		//打印出游戏规则
		mvprintw(30,8,"Enter 'UP','DOWN','LEFT'or'RIGHT' to control direction!");
		mvprintw(31,8,"                                                       ");
		mvprintw(32,8,"Enter 'Esc' to end the running game!                   ");
		attroff(COLOR_PAIR(4) | A_BOLD|A_STANDOUT);
		attroff(COLOR_PAIR(4) | A_BOLD);

        refresh();
        wrefresh(midscreen2 );

    }
	
	//在while间的空隙过程，清除stdscr（主窗口）和midscreen3（副窗口3）两个窗口的内容
	clear();
	wclear(midscreen3);
	wrefresh(midscreen3);
	
	//设置游戏结束界面
	while(end){
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD );
		box(midscreen3,ACS_VLINE,ACS_HLINE);//给窗口加边框
		mvwprintw(midscreen3,7,18,"Your score is %d ",score);
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD |A_STANDOUT);
		mvwprintw(midscreen3,12,15,"Enter 'Esc' to end game ");
		mvwprintw(midscreen3,15,15,"Enter 'p' to play again ");
		wattroff(midscreen3, COLOR_PAIR(4)|A_BOLD |A_STANDOUT);
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD );
		refresh();
		wrefresh(midscreen3);
		
		end_ch = wgetch(midscreen3);
		wclear(midscreen3);
		switch(end_ch){
			case 'p':  {//这里是重玩按钮，下面操作将各个值赋回初始值
				end = 0; 
				start = 0; 
				paint=1;
				lenth = 3;
				score = 0;
				speed = 12;
				F = 4;
				break;
			}
			case 27 :  end = 0; run = 0 ; break; //27表示的是Esc键
		}
		refresh();
		wrefresh(midscreen3);
	}
	
}//while(run)的结束
	
    refresh();
	endwin();//退出curses
	return 0;
}
