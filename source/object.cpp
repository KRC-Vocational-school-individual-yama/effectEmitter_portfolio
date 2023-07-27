#include"object.h"
#include<DxLib.h>
#include"config.h"

#include"emitterexprosion.h"
namespace {
	EmitterExprosion* emitter;

	bool keystop = false;
}

void Init() {
	emitter = new EmitterExprosion;
	emitter->Init();
	emitter->On();
}
void Update() {
	bool key = CheckHitKey(KEY_INPUT_R);
	if (key && !keystop) {
		emitter->Reset();
		emitter->On();
	}
	keystop = key;

	emitter->Update();
}
void Draw() {
	emitter->Draw();
}
void Delete() {
	delete emitter;
}