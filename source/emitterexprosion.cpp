#include "emitterexprosion.h"
#include<DxLib.h>

EmitterExprosion::EmitterExprosion()
{
	circle.resize(circlenum);
	velocity.resize(circlenum);
	nonmovecount.resize(circlenum);
	active.resize(circlenum);
}

EmitterExprosion::~EmitterExprosion(){
	for (int i = 0; i < circlenum; i++) {
		delete circle[i];
	}
}

void EmitterExprosion::Init(){
	Reset();
}

void EmitterExprosion::Reset(){
	for (int i = 0; i < circle.size(); i++) {
		circle[i] = new Circle();
		circle[i]->param.pos.x = SCREEN_WIDTH /2.0f;//GetRand(400) + 100;
		circle[i]->param.pos.y = SCREEN_HEIGHT/2.0f;//GetRand(300) + 100;
		circle[i]->param.radius = 5;
		velocity[i].x = GetRand(50)-GetRand(50);
		velocity[i].y = GetRand(25) - GetRand(50);
		nonmovecount[i] = 0;
		active[i] = false;
	}
}

void EmitterExprosion::Update() {
	for(int i = 0; i < circle.size(); i++) {
		if (!active[i])continue;
		Gravity(i);
		Move(i);
		NaturalLifeTime(i);
		Resistance(i);
		BoundGround(i);
		BoundWall(i);
	}
}
void EmitterExprosion::Draw()
{
	for (int i = 0; i < circle.size(); i++) {
		if (!active[i]) continue;
		circle[i]->Draw();
	}
}
void EmitterExprosion::On(){
	for (int i = 0; i < circlenum; i++) {
		if (active[i])continue;
		active[i] = true;
	}
}
void EmitterExprosion::Off(){
	for (int i = 0; i < circlenum; i++) {
		if (!active[i])continue;
		active[i] = false;
	}
}
void EmitterExprosion::NaturalLifeTime(int &i){
	bool notmoveflag = (int)velocity[i].x==0&&(int)velocity[i].y==0;
	if (!notmoveflag)return;
	nonmovecount[i]++;
	if (nonmovecount[i] > 60) {
		active[i] = false;
	}
}
void EmitterExprosion::Move(int &i){
	circle[i]->param.pos.x+=velocity[i].x;
	circle[i]->param.pos.y+=velocity[i].y;

}

void EmitterExprosion::Resistance(int &i){
	velocity[i].x *= resistance;
	velocity[i].y *= resistance;
}

void EmitterExprosion::Gravity(int &i){
	velocity[i].y += gravity;
}

void EmitterExprosion::BoundGround(int &i){
	if (velocity[i].y <= 0.0f)return;
	if (circle[i]->param.pos.y > ground) {
		circle[i]->param.pos.y = ground;
			float decelerate = 0.2f+GetRand(5)/10.0f;//Œ¸‘¬
		velocity[i].y *= -1*decelerate;
		velocity[i].x *= resistance;
	}
}

void EmitterExprosion::BoundWall(int &i){
	if (circle[i]->param.pos.x < 0) {
		circle[i]->param.pos.x = 0;
		velocity[i].x *= -1;
	}
	if (circle[i]->param.pos.x > SCREEN_WIDTH) {
		circle[i]->param.pos.x = SCREEN_WIDTH;
		velocity[i].x *= -1;
	}
}
