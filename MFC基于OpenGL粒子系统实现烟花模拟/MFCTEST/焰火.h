#pragma once
// ConsoleApplication17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <Gl/glut.h>
#include<stdlib.h>
#include "math.h"



extern int num1, num2, num3, num4, num5, num6;
extern int color ;
extern int WAVES ;
extern float lifes;
extern float speeds;
extern float G;
extern float EXP_speed;
extern int MAX_FIRES ;
extern float SIZE_s;
extern int color_mode;
extern int WAVE_NUM ;// 最多5个烟花
extern int MAX_PARTICLES ; // 每个烟花升空散开的小烟花个数
const int MAX_TAILS =40;      // 烟花尾迹

typedef struct {
	float r, g, b;      /* color */
	float x, y, z;      /* position  */
	float xs, ys, zs;   /* speed  */
	float xg, yg, zg;   /* gravity  */
	boolean up;         /* up or down */
} Particle;

typedef struct {
	Particle (*Firework)[MAX_TAILS] = new Particle[MAX_PARTICLES][MAX_TAILS];		 // 烟花系统数组

	float life, fade, rad; // 生命，衰减速度，x-z平面上的运动速度
} Fire;




void Init();
void InitGL(GLvoid);
void gengxin();
void display();

