#pragma once
// ConsoleApplication17.cpp : �������̨Ӧ�ó������ڵ㡣
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
extern int WAVE_NUM ;// ���5���̻�
extern int MAX_PARTICLES ; // ÿ���̻�����ɢ����С�̻�����
const int MAX_TAILS =40;      // �̻�β��

typedef struct {
	float r, g, b;      /* color */
	float x, y, z;      /* position  */
	float xs, ys, zs;   /* speed  */
	float xg, yg, zg;   /* gravity  */
	boolean up;         /* up or down */
} Particle;

typedef struct {
	Particle (*Firework)[MAX_TAILS] = new Particle[MAX_PARTICLES][MAX_TAILS];		 // �̻�ϵͳ����

	float life, fade, rad; // ������˥���ٶȣ�x-zƽ���ϵ��˶��ٶ�
} Fire;




void Init();
void InitGL(GLvoid);
void gengxin();
void display();

