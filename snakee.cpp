#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>


	int width=50,length=50,gameover,score;
	int applex,appley,x,y,command;

void game(){
	
	gameover=0;
	
		x=length/2;
		y=width/2;
    label1:
    	applex=rand()%50;
    	if (applex==0)
			goto label1;
	label2:
		appley=rand()%50;
		if(appley==0)
			goto label2;
		score=0;	
}

void area()
{
   
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == width - 1
                || j == 0
                || j == length - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y)
                    printf("0");
                else if (i == applex
                         && j == appley)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score=%d",score);
    printf("\n");
    printf("press q to quit game");
}

void keys(){
	if(kbhit()){
	switch(getch()){
		case"a":
			command=1;
		case"s":
			command=2;
		case"d":
			command=3;
		case"w":
			command=4;
		case"q":
			gameover=1;
			break;
		}
	}	

}  	

void logic()
{
    sleep(0.01);
    switch (command) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
 if (x < 0 || x > length
        || y < 0 || y > width)
        gameover = 1;
  
   
    if (x == applex && y == appley) {
    label3:
        applex = rand() % 50;
        if (applex == 0)
            goto label3;
  
   
    label4:
        appley = rand() % 50;
        if (appley == 0)
            goto label4;
        score += 10;
    }
}
  

int main()
{
    int m, n;
  
    
    game();
  
    
    while (!gameover) {
  
       
       area();
       keys();
    	logic();
    }
}
