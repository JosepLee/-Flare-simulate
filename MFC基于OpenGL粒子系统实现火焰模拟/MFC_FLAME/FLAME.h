#pragma once
#define MAX_PARTICLES 5000 // 粒子数的数目
struct particles// 创建结构体
{
	float life;                 // 粒子生命周期
	float fade;                 // 衰退
	float r, g, b;                //颜色
	float x, y, z;                // 坐标
	float vx, vy, vz;           //速度
	float ax, ay, az;             //加速度
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
