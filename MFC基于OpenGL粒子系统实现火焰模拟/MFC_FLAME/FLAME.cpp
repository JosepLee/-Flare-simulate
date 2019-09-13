#include"stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <Gl/glut.h>
#include "math.h"
#include"FLAME.h"

float  Wides=1;
float  Height=1;
float  Width=1;
float  faded=0.0;
float  W = 10.0;
float  H =10.0;
float  N = 10.0;
float lifes = 0.01;
float sizes = 0.01;
float R = 0, G = 0, B = 0;
int colormode = 1;
#define MAX_PARTICLES 5000 // ����������Ŀ
particles particle[MAX_PARTICLES]; // ������������

void Init()                //��ʼ������
{
	for (int loop = 0; loop<MAX_PARTICLES; loop++)
	{

		particle[loop].life = 1.5f;
		particle[loop].fade = float(rand() % 15000) / 1500.0f + 0.02f;
		particle[loop].r = 0;
		particle[loop].g = 0;
		particle[loop].b = 0;
		particle[loop].ax = 0.0f;
		particle[loop].ay = 0.3f;
		particle[loop].az = 0.0f;
	}
}
void InitGL(GLvoid) //��OPENGL��һЩ����
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);//���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	Init();//��ʼ��

}
void gengxin()//���£��Զ��κ���ģ�����
{
	for (int loop = 0; loop<MAX_PARTICLES; loop++)
	{
		float x = particle[loop].x;
		float y = particle[loop].y + 10;
		float z = particle[loop].z - 30;
		float a = (20 - y)*(0.08+sizes);       //�ɿ������Ӵ�С��ϵ��
		if (y >= 15)
			a = (20 - y)*0.05;
		glColor4ub(particle[loop].r, particle[loop].g, particle[loop].b, particle[loop].life - 0.99*255); //������ɫ��͸����
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(x + a, y + a, z); //�ı��α�ʾ��������
		glVertex3f(x - a, y + a, z);
		glVertex3f(x + a, y - a, z);
		glVertex3f(x - a, y - a, z);
		glEnd();
		particle[loop].x += particle[loop].vx / (100*W); //��������
		particle[loop].y += particle[loop].vy / (100*H);
		particle[loop].z += particle[loop].vz / (150*N);
		particle[loop].vx += particle[loop].ax; // X ����ٶ��� X ��ļ��ٶȱ仯
		particle[loop].vy += particle[loop].ay;
		particle[loop].vz += particle[loop].az;
		particle[loop].life -= particle[loop].fade; // ����˥��
		if (particle[loop].life<0.0f || y>18)//���������ڽ��������¸�ֵ
		{
			particle[loop].life = 1.5f+lifes;
			particle[loop].fade = float(rand() % 150) / 1500.0f + 0.002f + faded;
			particle[loop].x = 0.0f;
			particle[loop].y = 0.0f;
			particle[loop].z = 0.0f;
			particle[loop].vx = float((rand() % 60*Wides) - 30.0f);
			particle[loop].vy = float((rand() % 60*Width) - 0.0f);
			particle[loop].vz = float((rand() % 60*Height) - 30.0f);
			if (colormode == 1) {
			particle[loop].r = 0.75*255;
			particle[loop].g = 0.17*255;
			particle[loop].b = 0;
			}
			if(colormode==0){
			particle[loop].r =R;
			particle[loop].g = G;
			particle[loop].b = B;
			}

			particle[loop].ax = 0;
			particle[loop].ay = 1.1;//��y��ļ��ٶ�
			particle[loop].az = 0.0f;

		}
	}

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 2, 0, 1.5, 0, 0, 1, 0);
	gengxin();

}

void ReSizeGLScene(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200.0f);
}
