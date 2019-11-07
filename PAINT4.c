#include<conio.h>
#include<dos.h>
int far* scr=(int far*)0xb8000000;
int draw(int i,int j,int b)
{
	for(int k=0;k<2000;k++)
	if(scr[k]==b*256+30)scr[k]=b*256+219;
	scr[80*i+j]=b*256+30;
	return 0;
}
int ndraw(int b,int mem)
{
	for(int k=0;k<2000;k++){
	if(scr[k]==b*256+30) scr[k]=mem;}
	return 0;
}
int palette()
{
for(int i=0;i<25;i++)
{
	for(int j=0;j<15;j++)
	{
		scr[80*i+j]=15*256+219;
	}
	scr[80*i+14]=7*256+186;
}
for(int b=0;b<8;b++)
{
	scr[80*(1+3*b)+2]=(b*16+b+8)*256+49+b;
	for(int j=3;j<6;j++)
	{
		scr[(1+3*b)*80+j]=b*256+219;
		scr[(2+3*b)*80+j]=b*256+219;
	}
}
return 0;}
int altpalette()
{
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<15;j++)
		{
			scr[80*i+j]=15*256+219;
		}
	scr[80*i+14]=7*256+186;
	}
	for(int b=8;b<16;b++)
	{
		scr[80*(1+3*(b-8))+2]=((b-8)*16+b)*256+49+(b-8);
		for(int j=3;j<6;j++){
		scr[(1+3*(b-8))*80+j]=b*256+219;
		scr[(2+3*(b-8))*80+j]=b*256+219;
		scr[22*80+3]=256*(15+112)+'W';
		scr[22*80+4]=256*(15+112)+'h';
		scr[22*80+5]=256*(15+112)+'i';
		scr[22*80+6]=256*(15+112)+'t';
		scr[22*80+7]=256*(15+112)+'e';
	 }
}
return 0;}
int dir()
{
	scr[2*80+6]=256*(15+112)+'F';
	scr[2*80+7]=256*(15+112)+'i';
	scr[2*80+8]=256*(15+112)+'l';
	scr[2*80+9]=256*(15+112)+'l';
	scr[2*80+10]=256*(15+112)+':';
	scr[2*80+11]=256*(15+112)+'f';
	scr[4*80+6]=256*(15+112)+'A';
	scr[4*80+7]=256*(15+112)+'l';
	scr[4*80+8]=256*(15+112)+'t';
	scr[5*80+6]=256*(15+112)+'C';
	scr[5*80+7]=256*(15+112)+'o';
	scr[5*80+8]=256*(15+112)+'l';
	scr[5*80+9]=256*(15+112)+'o';
	scr[5*80+10]=256*(15+112)+'r';
	scr[5*80+11]=256*(15+112)+'s';
	scr[5*80+12]=256*(15+112)+':';
	scr[6*80+6]=256*(15+112)+'t';
	scr[6*80+7]=256*(15+112)+'a';
	scr[6*80+8]=256*(15+112)+'b';
return 0;}
int dmode()
{
	scr[24*80+1] =256*(15+128)+'D';
	scr[24*80+2] =256*(15+128)+'r';
	scr[24*80+3] =256*(15+128)+'a';
	scr[24*80+4] =256*(15+128)+'w';
	scr[24*80+5] =256*(15+128)+'i';
	scr[24*80+6] =256*(15+128)+'n';
	scr[24*80+7] =256*(15+128)+'g';
	scr[24*80+8] =256*(15+128)+' ';
	scr[24*80+9] =256*(15+128)+'m';
	scr[24*80+10]=256*(15+128)+'o';
	scr[24*80+11]=256*(15+128)+'d';
	scr[24*80+12]=256*(15+128)+'e';
return 0;}
int ndmode()
{
	for(int j=1;j<13;j++)
	scr[24*80+j]=256*15+219;
return 0;}
void fill(int mem,int i,int j,int b)
{
     scr[80*i+j]=256*b+219;
     if(scr[80*(i-1)+j]==mem && i>=0) fill(mem,i-1,j,b);
     if(scr[80*(i+1)+j]==mem && i<25) fill(mem,i+1,j,b);
     if(scr[80*i+j-1]==mem && j>15)   fill(mem,i,j-1,b);
     if(scr[80*i+j+1]==mem && j<79)   fill(mem,i,j+1,b);
}
int main()
{
	  int i=0,d=0,b=7*16,j=35,ins=0,alternate=0,mem;
	  char c;
	  for(int I=0;I<25;I++)
	  {
		for(int J=15;J<80;J++)scr[80*I+J]=15*256+219;
	  }
	  palette();
	  dir();
	  while(d!=27)
	  {
		c=getch();
		d=int(c);
		switch(d)
		{
			case 9: if(alternate==0)
			{
				alternate=1;
				altpalette();
				dir();
			}
			else
			{
				palette();
				dir();
				alternate=0;
			}
			break;
			case 102: fill(mem,i,j,b);

		}
		if(d==0)
		{
			c=getch();
			d=int(c);
			switch(d)
			{
				case 72: i--;
				break;     //up
				case 80: i++;
				break;     //down
				case 77: j++;
				break;     //right
				case 75: j--;
				break;     //left
				case 82:if(ins==0)
					{
						ins=1;
						dmode();
					}
				 else
				 {
					ins=0;
					scr[i*80+j]=b*256+219;   //for drawing the position of the cursor
					ndmode();
				 }
				 break;
			  }
		}

		else
		{
			if(d<57 && d>48 && alternate==0) b=d-49;
			if(d<57 && d>48 && alternate==1) b=d-41;
			if(b==0) b+=7*16;
		}
		if(j>79)j=79;
		if(j<15)j=15;
		if(i<0)i=0;
		if(i>24)i=24;
		if(ins==1) draw(i,j,b);
		else
		{
			ndraw(b,mem);
			if(d>56 || d<49) mem=scr[80*i+j];
			scr[80*i+j]=b*256+30;
		}
	  }
return 0;}