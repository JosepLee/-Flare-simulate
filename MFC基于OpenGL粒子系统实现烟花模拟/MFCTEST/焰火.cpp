// ConsoleApplication17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"焰火.h"
#include <windows.h>
#include <stdio.h>
#include <Gl/glut.h>

#include<stdlib.h>
#include "math.h"
	float SIZE_s = 2.8;
	int color_mode = 0;
	int color = 100;
	int WAVES = 1;
	int MAX_FIRES = 1;
	int WAVE_NUM = 24;// 最多5个烟花
	int MAX_PARTICLES = 24; // 每个烟花升空散开的小烟花个数
	float lifes = 1.0;		//生命
	float G = -0.005;		//y方向加速度
	float speeds=1;				//速度
	float EXP_speed = rand() % 3 + 4;
Fire *g_fires;//定义焰火结构体数组
int num1, num2, num3, num4, num5, num6;

void Init()//初始化烟花粒子位置以及烟花粒子参数
{

	g_fires = new Fire[MAX_FIRES];
	for (int loop = 0; loop < MAX_FIRES; loop++) {
		//初始烟花发射位置，在一个小空间内随机位置发射
		float xtemp = rand() % 30 - 15;							//x初坐标
		float ytemp = (-1)*rand() % 5 - 8;						//y初坐标
		float ztemp = (-1)*rand() % 5 - 100;					//z初坐标								
		g_fires[loop].life = lifes;								//生命
		g_fires[loop].fade = 0.003f;							//生命减小速度
		g_fires[loop].rad = EXP_speed;						//粒子炸开后的速度基数

		for (int loop1 = 0; loop1 < MAX_PARTICLES; loop1++) {

			//初始颜色
			g_fires[loop].Firework[loop1][0].r = 1.0f;
			g_fires[loop].Firework[loop1][0].g = 1.0f;
			g_fires[loop].Firework[loop1][0].b = 1.0f;
			//初始位置
			g_fires[loop].Firework[loop1][0].x = xtemp;
			g_fires[loop].Firework[loop1][0].y = ytemp;
			g_fires[loop].Firework[loop1][0].z = ztemp;
			//初始速度
			g_fires[loop].Firework[loop1][0].xs = 0.0f;
			g_fires[loop].Firework[loop1][0].ys = speeds;
			g_fires[loop].Firework[loop1][0].zs = 0.0f;
			//初始加速度
			g_fires[loop].Firework[loop1][0].xg = 0.0f;
			g_fires[loop].Firework[loop1][0].yg = G;
			g_fires[loop].Firework[loop1][0].zg = 0.0f;
			g_fires[loop].Firework[loop1][0].up = true;

			//尾部初始化
			for (int loop2 = 1; loop2 < MAX_TAILS; loop2++) {
				g_fires[loop].Firework[loop1][loop2].x = g_fires[loop].Firework[loop1][0].x;
				g_fires[loop].Firework[loop1][loop2].y = g_fires[loop].Firework[loop1][0].y;
				g_fires[loop].Firework[loop1][loop2].z = g_fires[loop].Firework[loop1][0].z;
			} //for loop2 end
		}//for loop2 end
	}//for loop end

}
void InitGL(GLvoid) // OpenGL 的设置
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);//混合
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);


}
void gengxin()//更新焰火
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// 清除屏幕以缓存
	glLoadIdentity();		// 重置矩阵

	for (int loop = 0; loop < MAX_FIRES; loop++) {
		for (int loop1 = 0; loop1 < MAX_PARTICLES; loop1++) {
			for (int loop2 = 0; loop2 < MAX_TAILS; loop2++) {
				//记录每个粒子的x,y,z坐标用来绘制粒子
				float x = g_fires[loop].Firework[loop1][loop2].x;
				float y = g_fires[loop].Firework[loop1][loop2].y;
				float z = g_fires[loop].Firework[loop1][loop2].z;
				float dt = 1 - (float)loop2 / MAX_TAILS;
				
				for (int flag = 1; flag <= WAVES; flag++) { //分波绘制爆炸粒子
					//分波换颜色，通过控制波数，烟花粒子数来控制，波数和烟花粒子数定义在  “焰火.h”
					if ((loop1*WAVES / MAX_PARTICLES) <= flag && (loop1*WAVES / MAX_PARTICLES) >= flag - 1) {
						if (g_fires[loop].life>0)
						{ 						
							if(color_mode==0)
								glColor4ub(241, 141, 0, (g_fires[loop].life * dt) * 250);
							if(color_mode==1)
							glColor4ub(num1 + (((num4 - num1) / WAVES)*flag), num2 + (((num5 - num2) / WAVES)*flag), num3 + (((num6 - num3) / WAVES)*flag), (g_fires[loop].life * dt) * 250);
						}
	

						float size = SIZE_s * dt;				//烟花粒子大小100 * float((flag - 1) / 3)
						glBegin(GL_POLYGON);				
						glVertex3f(x + size, y + size, z); // Top Right
						glVertex3f(x + size, y - size, z); // Bottom Right
						glVertex3f(x - size, y - size, z); // Bottom Left
						glVertex3f(x - size, y + size, z); // Bottom Right
						glEnd(); 



					}
				}


			}
			// 更新焰火尾部粒子位置，焰火尾部粒子位置为上一个头部粒子前一个所处位置
			for (int loop2 = MAX_TAILS - 1; loop2 > 0; loop2--) {
				g_fires[loop].Firework[loop1][loop2].x = g_fires[loop].Firework[loop1][loop2 - 1].x;
				g_fires[loop].Firework[loop1][loop2].y = g_fires[loop].Firework[loop1][loop2 - 1].y;
				g_fires[loop].Firework[loop1][loop2].z = g_fires[loop].Firework[loop1][loop2 - 1].z;
			} //for loop2 end
			
			  //焰火位置更新
			g_fires[loop].Firework[loop1][0].x += g_fires[loop].Firework[loop1][0].xs;
			g_fires[loop].Firework[loop1][0].y += g_fires[loop].Firework[loop1][0].ys;
			g_fires[loop].Firework[loop1][0].z += g_fires[loop].Firework[loop1][0].zs;

			// 更新y轴方向上的速度
			float yd = g_fires[loop].Firework[loop1][0].yg;
			g_fires[loop].Firework[loop1][0].ys += yd;
			

			//当焰火上升过程中y轴速度小于0（到达顶点），设定爆炸时各个粒子的方向速度参数
			if (g_fires[loop].Firework[loop1][0].up && g_fires[loop].Firework[loop1][0].ys < 0) {
				double radian = 3.14159*loop1*(360 * WAVES / MAX_PARTICLES) / 180.0;	//改变量用于确定焰火按圆形炸开后每个焰火粒子的方向
				//不同波数有不同的初速度
				for (int flag = 1; flag <= WAVES; flag++) {      
					if ((loop1*WAVES / MAX_PARTICLES) <= flag && (loop1*WAVES / MAX_PARTICLES) >= flag - 1) {        
						g_fires[loop].Firework[loop1][0].xs = ((float)(g_fires[loop].rad*sin(radian)) / (10 + flag * 3))*2.5;         //设定炸开后粒子朝向不同方向的初速度，x轴
						g_fires[loop].Firework[loop1][0].zs = ((float)(g_fires[loop].rad*cos(radian)) / (10 + flag * 3))*2.5;		  //设定炸开后粒子朝向不同方向的初速度，y轴

					}
				}


			}

		}
		g_fires[loop].life -= g_fires[loop].fade; //焰火粒子每次调用都减少生命

		if (g_fires[loop].life < -0.5) {
			Init();								//如果生命结束，则产生新的焰火，循环
		}
	}

}
void display()								//调用更新函数，开始绘图
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gengxin();//更新
}
