#pragma once
extern int MAX_PARTICLES2; // ÿ���̻�����ɢ����С�̻�����
struct particles// �����ṹ��
{
	float life;                 // ������������
	float fade;                 // ˥��
	float r, g, b;                //��ɫ
	float x, y, z;                // ����
	float vx, vy, vz;           //�ٶ�
	float ax, ay, az;             //���ٶ�
};

//particles(*Firework2) = new particles[MAX_PARTICLES2];

void Init2();
void InitGL2(GLvoid);
void gengxin2();
void display2();