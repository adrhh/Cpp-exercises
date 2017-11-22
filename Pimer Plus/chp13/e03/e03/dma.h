#ifndef DMA_H_

class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "brak", int r = 0);
	baseDMA(const baseDMA& bd); //konstuktor kopjujacy
	virtual ~baseDMA();
	virtual void view() const = 0;
	virtual baseDMA& operator=(const baseDMA& bd);
};

class lackDMA : public baseDMA
{
private:
	enum {MAXC = 40};
	char color[MAXC];
public:
	lackDMA(const char* c = "brak",
			const char* l = "brak", int r = 0);
	lackDMA(const baseDMA& bd, const char* c = "brak");
	lackDMA(const lackDMA& ld);
	~lackDMA() {};
	lackDMA& operator=(const lackDMA& ld);
	void view() const;
};

class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "brak",
			const char* l = "brak", int r = 0);
	hasDMA(const baseDMA& bd, const char* s = "brak");  ///np baseDMA ob,  hasDMA(ob, "test") wywoluje konstruktor kopjujacy baseDMA
	hasDMA(const hasDMA& hd);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hd);
	void view() const;
};

#endif // !DMA_H_
