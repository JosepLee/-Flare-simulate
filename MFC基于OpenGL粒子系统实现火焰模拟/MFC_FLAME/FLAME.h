#pragma once
#define MAX_PARTICLES 5000 // ����������Ŀ
struct particles// �����ṹ��
{
	float life;                 // ������������
	float fade;                 // ˥��
	float r, g, b;                //��ɫ
	float x, y, z;                // ����
	float vx, vy, vz;           //�ٶ�
	float ax, ay, az;             //���ٶ�
};
float extern Wides;
float extern Height;
float extern Width;
float extern faded;
float extern W;
float extern H;
float extern N;
float extern lifes;
float extern sizes;
int extern colormode;
float extern R;
float extern G;
float extern B;

void Init();
void InitGL(GLvoid);
void gengxin();
void display();
