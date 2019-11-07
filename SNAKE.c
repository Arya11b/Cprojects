#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<iostream.h>
int far* scr=(int far*)0xb8000000;
int far* buffer1=(int far*)0x0000041A;
int far* buffer2=(int far*)0x0000041C;
int food=rand() % 2000;
int snake[200];
int level=1;
int arrow_key=0;
int portal=5;
int current_portal=5;
int i=11,j=40,k=0,n=4,b=1,d=0;
char c;
void lvl()
{
	switch(level)
	{
		case 1:
		break;
		case 2:
		for(int f=0;f<23;f++)
		{
			scr[80*f]=6*16*256;
			scr[80*f+79]=6*16*256;
		}
		for(f=0;f<80;f++)
		{
			scr[f]=6*16*256;
			scr[80*23+f]=6*16*256;
		}
		for(f=25;f<56;f++)
		{
			scr[80*12+f]=6*16*256;
			scr[80*10+f]=6*16*256;
		}
		scr[80*10+40]=2*16*256;
		scr[80*12+40]=2*16*256;
		break;
		case 3:
		for(f=0;f<23;f++)
			for(int g=0;g<80;g++)
				if(f+g==79 || f-g==0 || f-g==22 || g-f==22)
					scr[80*f+g]=6*16*256;
		break;
		case 4:
		scr[80*17+4]=1*16*256;
		scr[80*5+6]=1*16*256;
		scr[80*15+40]=1*16*256;
		scr[80*19+60]=1*16*256;
		scr[80*5+60]=1*16*256;
		for(f=0;f<23;f++)
		{
			scr[80*f]=6*16*256;
			scr[80*f+79]=6*16*256;
			scr[80*f+47]=6*16*256;
		}
		for(f=0;f<80;f++)
		{
			scr[f]=6*16*256;
			scr[80*23+f]=6*16*256;
		}
		for(f=0;f<32;f++)
		{
			scr[80*9+f]=6*16*256;
			scr[80*13+22+f]=6*16*256;
			scr[80*13+79-f]=6*16*256;
		}
		for(f=0;f<10;f++)
		{
			scr[80*(22-f)+32]=6*16*256;
			scr[80*f+32]=6*16*256;
		}
		break;
	}
}
void fd()
{
	if(k>=n)k=0;
	scr[food]=(2*16+15)*256+48+b;
	if(b==10)scr[food]=(2*16+15)*256+48;
	if(80*i+j==food)
	{
		time_t tt;
		srand((unsigned)time(&tt));
		food=rand() % 2000;
		while(!(scr[food]==2*16*256)) food=rand() % 2000;
		n+=b;
		b++;
		if(b==11)
		{
			b=1;
			for(int k=0;k<200;k++)
			snake[k]=-1;
			n=4;
			i=13;
			j=40;
			level++;
			delay(500);
		}
	}
}
void snk()
{
	for(int k=0;k<1840;k++)
		if(k!=food)scr[k]=2*16*256;	//Every possible axis except food
	lvl();
	for(k=0;k<n;k++)
		if(snake[k]!=-1)
			scr[snake[k]]=4*16*256;
}
void port()
{
	time_t tt;
	if(scr[80*i+j]==1*16*256)
	{
		srand((unsigned)time(&tt));
		portal = rand() % 5;
		if(current_portal==portal)
		{
			srand((unsigned)time(&tt));
			portal = rand() % 5;
		}
	}
	switch(portal)
	{
		case 0:
		i=17;
		j=4;
		portal=5;
		current_portal=0;
		break;
		case 1:
		i=5;
		j=6;
		portal=5;
		current_portal=1;
		break;
		case 2:
		i=15;
		j=40;
		portal=5;
		current_portal=2;
		break;
		case 3:
		i=19;
		j=60;
		portal=5;
		current_portal=3;
		break;
		case 4:
		i=5;
		j=60;
		portal=5;
		current_portal=4;
		break;
	}

}
int move(int a)
{
	while(1)
	{
		*buffer1=*buffer2;
		port();
		if(scr[80*i+j]==4*16*256 || scr[80*i+j]==6*16*256 || scr[80*i+j]=='*')                 // *
		{
			gotoxy(1,0);
			cout<<"game over!";
			d=27;
			delay(1500);
			break;
		}
		fd();
		if(k>=n)k=0;
		scr[80*i+j]=(4*16+15)*256+':';
		snake[k]=80*i+j;
		k++;
		if(a==1)i--;
		if(a==2)i++;
		if(a==3)j++;
		if(a==4)j--;
		delay(160/level);
		if(j<0)j+=80;
		if(i<0)i+=23;
		if(i==23)i-=23;
		if(j==80)j-=80;
		snk();
		if(kbhit()) break;
		}
return 0;
}
void commands()
{
	int k=0;
	if(!(food==2*16*256)) food=rand() % 1840;
	while(d!=27)
	{
		if(level==5)
		{
			gotoxy(1,24);
			cout<<"you won!";
			delay(1000);
			break;
		}
		c=getch();
		d=int(c);
		if(d==0)
		{
			c=getch();
			d=int(c);
			switch(d)
			{
				case 72:
				if(arrow_key==2) move(2);
				else
				{
					move(1);
					arrow_key=1;
				}
				break;     //up
				case 80:
				if(arrow_key==1) move(1);
				else
				{
					move(2);
					arrow_key=2;
				}
				break;     //down
				case 77:
				if(arrow_key==4) move(4);
				else
				{
					move(3);
					arrow_key=3;
				}
				break;     //right
				case 75:
				if(arrow_key==3) move(3);
				else
				{
					move(4);
					arrow_key=4;
				}
				break;     //left
				case 82:
				n++;
				break;	   //cheat

			}
		}
		if(j>79)j=79;
		if(j<0)j=0;
		if(i<0)i=0;
		if(i>24)i=24;
		snk();
	}
}
void main()
{
	  for(int k=0;k<1840;k++) scr[k]=2*16*256;
	  for(k=1840;k<2000;k++) scr[k]=7*16*256;
	  for(k=0;k<200;k++) snake[k]=-1;
	  commands();
}