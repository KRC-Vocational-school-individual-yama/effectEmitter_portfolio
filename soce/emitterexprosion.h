#pragma once
#include"shapes.h"
#include<vector>
#include"config.h"
class EmitterExprosion
{
public:
	EmitterExprosion();
	~EmitterExprosion();
	void Init();
	void Reset();
	void Update();
	void Draw();
	void On();
	void Off();

private:
	void NaturalLifeTime(int &i);
	void Move(int &i);
	void Resistance(int &i);
	void Gravity(int &i);
	void BoundGround(int &i);
	void BoundWall(int &i);

	std::vector<Circle*>circle;
	std::vector<Vectwo>velocity;
	std::vector<int>nonmovecount;
	std::vector<bool>active;
	const int circlenum=30;
	const int ground = SCREEN_HEIGHT-100;
	const float gravity=0.6f;
	const float resistance = 0.98f;
};