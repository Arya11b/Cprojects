#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
int main()
{
	int driver,mode;
	double x[8]={-100,100,-100,100,-100,100,-100,100};
	double y[8]={-100,100,100,-100,-100,100,100,-100};
	double z[8]={-100,-100,-100,-100,100,100,100,100};
	double t[24]={-100,100,-100,100,-100,100,-100,100,-100,100,100,-100,-100,100,100,-100,-100,-100,-100,-100,100,100,100,100};
	int d,e=0;
	double rx=0,ry=0,rz=0,s=1;
	char c;
	driver=DETECT;
	initgraph(&driver,&mode,"");
	cleardevice();
	while(d!=27)
	{
		c=getch();
		d=int(c);
		switch(d)
		{
			case 49:
			if(e!=1)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=1;
				rz=0;
			}
			rz+=0.05;
			x[0]=cos(rz)*t[0]-sin(rz)*t[8];
			y[0]=sin(rz)*t[0]+cos(rz)*t[8];
			x[1]=cos(rz)*t[1]-sin(rz)*t[9];
			y[1]=sin(rz)*t[1]+cos(rz)*t[9];
			x[2]=cos(rz)*t[2]-sin(rz)*t[10];
			y[2]=sin(rz)*t[2]+cos(rz)*t[10];
			x[3]=cos(rz)*t[3]-sin(rz)*t[11];
			y[3]=sin(rz)*t[3]+cos(rz)*t[11];
			x[4]=cos(rz)*t[4]-sin(rz)*t[12];
			y[4]=sin(rz)*t[4]+cos(rz)*t[12];
			x[5]=cos(rz)*t[5]-sin(rz)*t[13];
			y[5]=sin(rz)*t[5]+cos(rz)*t[13];
			x[6]=cos(rz)*t[6]-sin(rz)*t[14];
			y[6]=sin(rz)*t[6]+cos(rz)*t[14];
			x[7]=cos(rz)*t[7]-sin(rz)*t[15];
			y[7]=sin(rz)*t[7]+cos(rz)*t[15];
			cleardevice();
			if(!e) e=1;
			break;
			case 50:
			if(e!=2)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=2;
				ry=0;
			}
			ry+=0.05;
			x[0]=cos(ry)*t[0]+sin(ry)*t[16];
			z[0]=-sin(ry)*t[0]+cos(ry)*t[16];
			x[1]=cos(ry)*t[1]+sin(ry)*t[17];
			z[1]=-sin(ry)*t[1]+cos(ry)*t[17];
			x[2]=cos(ry)*t[2]+sin(ry)*t[18];
			z[2]=-sin(ry)*t[2]+cos(ry)*t[18];
			x[3]=cos(ry)*t[3]+sin(ry)*t[19];
			z[3]=-sin(ry)*t[3]+cos(ry)*t[19];
			x[4]=cos(ry)*t[4]+sin(ry)*t[20];
			z[4]=-sin(ry)*t[4]+cos(ry)*t[20];
			x[5]=cos(ry)*t[5]+sin(ry)*t[21];
			z[5]=-sin(ry)*t[5]+cos(ry)*t[21];
			x[6]=cos(ry)*t[6]+sin(ry)*t[22];
			z[6]=-sin(ry)*t[6]+cos(ry)*t[22];
			x[7]=cos(ry)*t[7]+sin(ry)*t[23];
			z[7]=-sin(ry)*t[7]+cos(ry)*t[23];
			cleardevice();
			if(!e) e=2;
			break;
			case 51:
			rx+=0.05;
			if(e!=3)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=3;
				rx=0;
			}
			y[0]=cos(rx)*t[8]-sin(rx)*t[16];
			z[0]=sin(rx)*t[8]+cos(rx)*t[16];
			y[1]=cos(rx)*t[9]-sin(rx)*t[17];
			z[1]=sin(rx)*t[9]+cos(rx)*t[17];
			y[2]=cos(rx)*t[10]-sin(rx)*t[18];
			z[2]=sin(rx)*t[10]+cos(rx)*t[18];
			y[3]=cos(rx)*t[11]-sin(rx)*t[19];
			z[3]=sin(rx)*t[11]+cos(rx)*t[19];
			y[4]=cos(rx)*t[12]-sin(rx)*t[20];
			z[4]=sin(rx)*t[12]+cos(rx)*t[20];
			y[5]=cos(rx)*t[13]-sin(rx)*t[21];
			z[5]=sin(rx)*t[13]+cos(rx)*t[21];
			y[6]=cos(rx)*t[14]-sin(rx)*t[22];
			z[6]=sin(rx)*t[14]+cos(rx)*t[22];
			y[7]=cos(rx)*t[15]-sin(rx)*t[23];
			z[7]=sin(rx)*t[15]+cos(rx)*t[23];
			cleardevice();
			if(!e) e=3;
			break;
			case 52:
			if(e!=1)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=1;
				rz=0;
			}
			rz-=0.05;
			x[0]=cos(rz)*t[0]-sin(rz)*t[8];
			y[0]=sin(rz)*t[0]+cos(rz)*t[8];
			x[1]=cos(rz)*t[1]-sin(rz)*t[9];
			y[1]=sin(rz)*t[1]+cos(rz)*t[9];
			x[2]=cos(rz)*t[2]-sin(rz)*t[10];
			y[2]=sin(rz)*t[2]+cos(rz)*t[10];
			x[3]=cos(rz)*t[3]-sin(rz)*t[11];
			y[3]=sin(rz)*t[3]+cos(rz)*t[11];
			x[4]=cos(rz)*t[4]-sin(rz)*t[12];
			y[4]=sin(rz)*t[4]+cos(rz)*t[12];
			x[5]=cos(rz)*t[5]-sin(rz)*t[13];
			y[5]=sin(rz)*t[5]+cos(rz)*t[13];
			x[6]=cos(rz)*t[6]-sin(rz)*t[14];
			y[6]=sin(rz)*t[6]+cos(rz)*t[14];
			x[7]=cos(rz)*t[7]-sin(rz)*t[15];
			y[7]=sin(rz)*t[7]+cos(rz)*t[15];
			cleardevice();
			if(!e) e=1;
			break;
			case 53:
			if(e!=2)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=2;
				ry=0;
			}
			ry-=0.05;
			x[0]=cos(ry)*t[0]+sin(ry)*t[16];
			z[0]=-sin(ry)*t[0]+cos(ry)*t[16];
			x[1]=cos(ry)*t[1]+sin(ry)*t[17];
			z[1]=-sin(ry)*t[1]+cos(ry)*t[17];
			x[2]=cos(ry)*t[2]+sin(ry)*t[18];
			z[2]=-sin(ry)*t[2]+cos(ry)*t[18];
			x[3]=cos(ry)*t[3]+sin(ry)*t[19];
			z[3]=-sin(ry)*t[3]+cos(ry)*t[19];
			x[4]=cos(ry)*t[4]+sin(ry)*t[20];
			z[4]=-sin(ry)*t[4]+cos(ry)*t[20];
			x[5]=cos(ry)*t[5]+sin(ry)*t[21];
			z[5]=-sin(ry)*t[5]+cos(ry)*t[21];
			x[6]=cos(ry)*t[6]+sin(ry)*t[22];
			z[6]=-sin(ry)*t[6]+cos(ry)*t[22];
			x[7]=cos(ry)*t[7]+sin(ry)*t[23];
			z[7]=-sin(ry)*t[7]+cos(ry)*t[23];
			cleardevice();
			if(!e) e=2;
			break;
			case 54:
			if(e!=3)
			{
				for(int k=0;k<8;k++)
				{
					t[k]=x[k];
					t[8+k]=y[k];
					t[16+k]=z[k];
				}
				e=3;
				rx=0;
			}
			rx-=0.05;
			y[0]=cos(rx)*t[8]-sin(rx)*t[16];
			z[0]=sin(rx)*t[8]+cos(rx)*t[16];
			y[1]=cos(rx)*t[9]-sin(rx)*t[17];
			z[1]=sin(rx)*t[9]+cos(rx)*t[17];
			y[2]=cos(rx)*t[10]-sin(rx)*t[18];
			z[2]=sin(rx)*t[10]+cos(rx)*t[18];
			y[3]=cos(rx)*t[11]-sin(rx)*t[19];
			z[3]=sin(rx)*t[11]+cos(rx)*t[19];
			y[4]=cos(rx)*t[12]-sin(rx)*t[20];
			z[4]=sin(rx)*t[12]+cos(rx)*t[20];
			y[5]=cos(rx)*t[13]-sin(rx)*t[21];
			z[5]=sin(rx)*t[13]+cos(rx)*t[21];
			y[6]=cos(rx)*t[14]-sin(rx)*t[22];
			z[6]=sin(rx)*t[14]+cos(rx)*t[22];
			y[7]=cos(rx)*t[15]-sin(rx)*t[23];
			z[7]=sin(rx)*t[15]+cos(rx)*t[23];
			cleardevice();
			if(!e) e=3;
			break;
			case 83:
			s+=0.05;
			cleardevice();
			break;
			case 115:
			if(s>0) s-=0.05;
			cleardevice();
			break;

		}
		setcolor(WHITE);
		line(x[0]*s+300,y[0]*s+200,x[2]*s+300,y[2]*s+200);
		line(x[0]*s+300,y[0]*s+200,x[3]*s+300,y[3]*s+200);
		line(x[0]*s+300,y[0]*s+200,x[4]*s+300,y[4]*s+200);
		line(x[1]*s+300,y[1]*s+200,x[2]*s+300,y[2]*s+200);
		line(x[1]*s+300,y[1]*s+200,x[3]*s+300,y[3]*s+200);
		line(x[1]*s+300,y[1]*s+200,x[5]*s+300,y[5]*s+200);
		line(x[2]*s+300,y[2]*s+200,x[6]*s+300,y[6]*s+200);
		line(x[3]*s+300,y[3]*s+200,x[7]*s+300,y[7]*s+200);
		line(x[4]*s+300,y[4]*s+200,x[6]*s+300,y[6]*s+200);
		line(x[4]*s+300,y[4]*s+200,x[7]*s+300,y[7]*s+200);
		line(x[5]*s+300,y[5]*s+200,x[6]*s+300,y[6]*s+200);
		line(x[5]*s+300,y[5]*s+200,x[7]*s+300,y[7]*s+200);
	}
	closegraph();
	return 0;
}