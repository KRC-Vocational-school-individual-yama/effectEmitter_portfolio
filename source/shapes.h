#pragma once
#include"shapemesh.h"
#include<DxLib.h>

class Circle :public Shape {
public:
	void Circle::Draw(){
	DrawCircleAA(param.pos.x, param.pos.y, param.radius, 20, GetColor(255, 255, 255));
	}
	CircleParam param;
};
class Box :public Shape{
public:
	void Draw() {
	float up	=param.pos.y-param.size.y;
	float left	=param.pos.x-param.size.x;
	float down	=param.pos.y+param.size.y;
	float right	=param.pos.x+param.size.x;
	DrawBoxAA(up,left,down,right,0xffffff,true);
	}

	BoxParam param;
};