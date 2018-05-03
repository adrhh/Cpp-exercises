#ifndef RGBA_H_
#define RGBA_H_

class Rgba
{
public:
	virtual int getRed() const = 0;
	virtual int getGreen() const = 0;
	virtual int getBlue() const = 0;
	virtual int getAlpha() const = 0;
	virtual void setRed(char val) = 0;
	virtual void setGreen(char val) = 0;
	virtual void setBlue(char val) = 0;
	virtual void setAlpha(char val) = 0;
};

class MyRGBA : public Rgba
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
private:
	unsigned int rgba;
	int toInt(unsigned int color) const;
	void changeRGBA(char val, unsigned int color);
public:
	MyRGBA(unsigned int rgbaVal) : rgba(rgbaVal) {}
	void setColorToZero(unsigned int color);
	int getRed() const { return toInt(RED); }
	int getGreen() const { return toInt(GREEN); }
	int getBlue() const { return toInt(BLUE); }
	int getAlpha() const { return toInt(ALPHA); }
	void setRed(char val) { changeRGBA(val, RED); }
	void setGreen(char val) { changeRGBA(val, GREEN); }
	void setBlue(char val) { changeRGBA(val, BLUE); }
	void setAlpha(char val) { changeRGBA(val, ALPHA); }
};

class MyRGBAStruct : public Rgba
{
private:
	struct Colors
	{
		char red : 8;
		char green : 8;
		char blue : 8;
		char alpha : 8;
		Colors(char r, char g, char b, char a) : red(r), green(g), blue(a), alpha(a) {}
	};
	Colors rgba;
public:
	MyRGBAStruct(char r, char g, char b, char a) : rgba(r,g,b,a) {}
	int getRed() const { return static_cast<unsigned int>(rgba.red); }
	int getGreen() const { return static_cast<unsigned int>(rgba.green); }
	int getBlue() const { return static_cast<unsigned int>(rgba.blue); }
	int getAlpha() const { return static_cast<unsigned int>(rgba.alpha); }
	void setRed(char val) { rgba.red = val; }
	void setGreen(char val) { rgba.green = val; }
	void setBlue(char val) { rgba.blue = val; }
	void setAlpha(char val) { rgba.alpha = val; }
};

#endif // !RGBA_H_
