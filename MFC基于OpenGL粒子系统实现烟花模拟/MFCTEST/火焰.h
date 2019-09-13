#pragma once
extern int MAX_PARTICLES2; // 每个烟花升空散开的小烟花个数
struct particles// 创建结构体
{
	float life;                 // 粒子生命周期
	float fade;                 // 衰退
	float r, g, b;                //颜色
	float x, y, z;                // 坐标
	float vx, vy, vz;           //速度
	float ax, ay, az;             //加速度
};

//particles(*Firework2) = new particles[MAX_PARTICLES2];

void Init2();
void InitGL2(GLvoid);
void gengxin2();
void display2();