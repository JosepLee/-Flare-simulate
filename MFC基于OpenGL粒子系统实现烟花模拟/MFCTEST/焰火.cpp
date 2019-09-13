// ConsoleApplication17.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"���.h"
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
	int WAVE_NUM = 24;// ���5���̻�
	int MAX_PARTICLES = 24; // ÿ���̻�����ɢ����С�̻�����
	float lifes = 1.0;		//����
	float G = -0.005;		//y������ٶ�
	float speeds=1;				//�ٶ�
	float EXP_speed = rand() % 3 + 4;
Fire *g_fires;//�������ṹ������
int num1, num2, num3, num4, num5, num6;

void Init()//��ʼ���̻�����λ���Լ��̻����Ӳ���
{

	g_fires = new Fire[MAX_FIRES];
	for (int loop = 0; loop < MAX_FIRES; loop++) {
		//��ʼ�̻�����λ�ã���һ��С�ռ������λ�÷���
		float xtemp = rand() % 30 - 15;							//x������
		float ytemp = (-1)*rand() % 5 - 8;						//y������
		float ztemp = (-1)*rand() % 5 - 100;					//z������								
		g_fires[loop].life = lifes;								//����
		g_fires[loop].fade = 0.003f;							//������С�ٶ�
		g_fires[loop].rad = EXP_speed;						//����ը������ٶȻ���

		for (int loop1 = 0; loop1 < MAX_PARTICLES; loop1++) {

			//��ʼ��ɫ
			g_fires[loop].Firework[loop1][0].r = 1.0f;
			g_fires[loop].Firework[loop1][0].g = 1.0f;
			g_fires[loop].Firework[loop1][0].b = 1.0f;
			//��ʼλ��
			g_fires[loop].Firework[loop1][0].x = xtemp;
			g_fires[loop].Firework[loop1][0].y = ytemp;
			g_fires[loop].Firework[loop1][0].z = ztemp;
			//��ʼ�ٶ�
			g_fires[loop].Firework[loop1][0].xs = 0.0f;
			g_fires[loop].Firework[loop1][0].ys = speeds;
			g_fires[loop].Firework[loop1][0].zs = 0.0f;
			//��ʼ���ٶ�
			g_fires[loop].Firework[loop1][0].xg = 0.0f;
			g_fires[loop].Firework[loop1][0].yg = G;
			g_fires[loop].Firework[loop1][0].zg = 0.0f;
			g_fires[loop].Firework[loop1][0].up = true;

			//β����ʼ��
			for (int loop2 = 1; loop2 < MAX_TAILS; loop2++) {
				g_fires[loop].Firework[loop1][loop2].x = g_fires[loop].Firework[loop1][0].x;
				g_fires[loop].Firework[loop1][loop2].y = g_fires[loop].Firework[loop1][0].y;
				g_fires[loop].Firework[loop1][loop2].z = g_fires[loop].Firework[loop1][0].z;
			} //for loop2 end
		}//for loop2 end
	}//for loop end

}
void InitGL(GLvoid) // OpenGL ������
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);//���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);


}
void gengxin()//�������
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// �����Ļ�Ի���
	glLoadIdentity();		// ���þ���

	for (int loop = 0; loop < MAX_FIRES; loop++) {
		for (int loop1 = 0; loop1 < MAX_PARTICLES; loop1++) {
			for (int loop2 = 0; loop2 < MAX_TAILS; loop2++) {
				//��¼ÿ�����ӵ�x,y,z����������������
				float x = g_fires[loop].Firework[loop1][loop2].x;
				float y = g_fires[loop].Firework[loop1][loop2].y;
				float z = g_fires[loop].Firework[loop1][loop2].z;
				float dt = 1 - (float)loop2 / MAX_TAILS;
				
				for (int flag = 1; flag <= WAVES; flag++) { //�ֲ����Ʊ�ը����
					//�ֲ�����ɫ��ͨ�����Ʋ������̻������������ƣ��������̻�������������  �����.h��
					if ((loop1*WAVES / MAX_PARTICLES) <= flag && (loop1*WAVES / MAX_PARTICLES) >= flag - 1) {
						if (g_fires[loop].life>0)
						{ 						
							if(color_mode==0)
								glColor4ub(241, 141, 0, (g_fires[loop].life * dt) * 250);
							if(color_mode==1)
							glColor4ub(num1 + (((num4 - num1) / WAVES)*flag), num2 + (((num5 - num2) / WAVES)*flag), num3 + (((num6 - num3) / WAVES)*flag), (g_fires[loop].life * dt) * 250);
						}
	

						float size = SIZE_s * dt;				//�̻����Ӵ�С100 * float((flag - 1) / 3)
						glBegin(GL_POLYGON);				
						glVertex3f(x + size, y + size, z); // Top Right
						glVertex3f(x + size, y - size, z); // Bottom Right
						glVertex3f(x - size, y - size, z); // Bottom Left
						glVertex3f(x - size, y + size, z); // Bottom Right
						glEnd(); 



					}
				}


			}
			// �������β������λ�ã����β������λ��Ϊ��һ��ͷ������ǰһ������λ��
			for (int loop2 = MAX_TAILS - 1; loop2 > 0; loop2--) {
				g_fires[loop].Firework[loop1][loop2].x = g_fires[loop].Firework[loop1][loop2 - 1].x;
				g_fires[loop].Firework[loop1][loop2].y = g_fires[loop].Firework[loop1][loop2 - 1].y;
				g_fires[loop].Firework[loop1][loop2].z = g_fires[loop].Firework[loop1][loop2 - 1].z;
			} //for loop2 end
			
			  //���λ�ø���
			g_fires[loop].Firework[loop1][0].x += g_fires[loop].Firework[loop1][0].xs;
			g_fires[loop].Firework[loop1][0].y += g_fires[loop].Firework[loop1][0].ys;
			g_fires[loop].Firework[loop1][0].z += g_fires[loop].Firework[loop1][0].zs;

			// ����y�᷽���ϵ��ٶ�
			float yd = g_fires[loop].Firework[loop1][0].yg;
			g_fires[loop].Firework[loop1][0].ys += yd;
			

			//���������������y���ٶ�С��0�����ﶥ�㣩���趨��ըʱ�������ӵķ����ٶȲ���
			if (g_fires[loop].Firework[loop1][0].up && g_fires[loop].Firework[loop1][0].ys < 0) {
				double radian = 3.14159*loop1*(360 * WAVES / MAX_PARTICLES) / 180.0;	//�ı�������ȷ�����Բ��ը����ÿ��������ӵķ���
				//��ͬ�����в�ͬ�ĳ��ٶ�
				for (int flag = 1; flag <= WAVES; flag++) {      
					if ((loop1*WAVES / MAX_PARTICLES) <= flag && (loop1*WAVES / MAX_PARTICLES) >= flag - 1) {        
						g_fires[loop].Firework[loop1][0].xs = ((float)(g_fires[loop].rad*sin(radian)) / (10 + flag * 3))*2.5;         //�趨ը�������ӳ���ͬ����ĳ��ٶȣ�x��
						g_fires[loop].Firework[loop1][0].zs = ((float)(g_fires[loop].rad*cos(radian)) / (10 + flag * 3))*2.5;		  //�趨ը�������ӳ���ͬ����ĳ��ٶȣ�y��

					}
				}


			}

		}
		g_fires[loop].life -= g_fires[loop].fade; //�������ÿ�ε��ö���������

		if (g_fires[loop].life < -0.5) {
			Init();								//�������������������µ����ѭ��
		}
	}

}
void display()								//���ø��º�������ʼ��ͼ
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gengxin();//����
}
