#pragma once
struct Vectwo {
	float x;
	float y;
};
struct CircleParam {
	Vectwo pos;
	float radius;
};
struct BoxParam {
	Vectwo pos;
	Vectwo size;
};
struct Image {
	Vectwo pos;
	Vectwo size;
	int img;
};
class Shape {
public:
	Shape() = default;
	~Shape() = default;
	virtual void Draw() = 0 {}
};