#ifndef RGBA_H_
#define RGBA_H_

class MyRGBA
{
public:
	static const unsigned int MyRGBA::RED_SHIFT = 24;
	static const unsigned int MyRGBA::GREEN_SHIFT = 16;
	static const unsigned int MyRGBA::BLUE_SHIFT = 8;
	static const unsigned int MyRGBA::ALPHA_SHIFT = 0;
	static const unsigned int MyRGBA::ALPHA = 0x000000FF;
	static const unsigned int MyRGBA::BLUE = MyRGBA::ALPHA << MyRGBA::BLUE_SHIFT;
	static const unsigned int MyRGBA::GREEN = MyRGBA::ALPHA << MyRGBA::GREEN_SHIFT;
	static const unsigned int MyRGBA::RED = MyRGBA::ALPHA << MyRGBA::RED_SHIFT;
	unsigned int rgba;
	int toInt(unsigned int color) const;
public:
	MyRGBA(unsigned int rgbaVal) : rgba(rgbaVal) {}
	int getRed() const { return toInt(RED); }
	int getGreen() const { return toInt(GREEN); }
	int getBlue() const { return toInt(BLUE); }
	int getAlpha() const { return toInt(ALPHA); }
};

#endif // !RGBA_H_
