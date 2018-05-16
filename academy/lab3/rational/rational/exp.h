#ifndef EXP_H_
#define EXP_H_

#include <cmath>
#include <memory>
#include <iostream>

class Visitor;

class Expression
{
public:
	virtual ~Expression() = default;
	virtual void accept(Visitor* v) const = 0;
	virtual double eval() const = 0;
};

class Literal : public Expression
{
private:
	double value;
public:
	explicit Literal(double v) : value(v) {}
	double eval() const override { return value; }
	void accept(Visitor* v) const override;
	~Literal() = default;
};

class BinnaryOp : public Expression
{
protected:
	std::unique_ptr<Expression> left;
	std::unique_ptr<Expression> right;
public: 
	void accept(Visitor* v) const override {}
	BinnaryOp(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)) , right(std::move(r)) {}
};

class UnaryOp : public Expression
{
protected:
	std::unique_ptr<Expression> subExpression;
public:
	void accept(Visitor* v) const override {}
	UnaryOp(std::unique_ptr<Expression> e) : subExpression(std::move(e)) {}
};

class Minus : UnaryOp
{
public:
	using UnaryOp::UnaryOp; //C11 
	double eval() const override
	{return -(subExpression->eval());}
};

class Sqrt : UnaryOp
{
public:
	using UnaryOp::UnaryOp;
	double eval() const override
	{return std::sqrt(subExpression->eval());}
};

class Add: public BinnaryOp
{
public:
	using BinnaryOp::BinnaryOp;
	double eval() const override
	{return left->eval() + right->eval();}

	void accept(Visitor* v) const override;
};

class Mult : public BinnaryOp
{
public:
	using BinnaryOp::BinnaryOp;
	double eval() const override
	{return left->eval() * right->eval();}
	void accept(Visitor* v) const override;
};

class Visitor
{
public:
	virtual void visit(const Literal& e) = 0;
	virtual void visit(const Add& e) = 0;
	virtual void visit(const Mult& e) = 0;
	virtual ~Visitor() = default;
};

class Printer : public Visitor
{
	virtual void visit(const Literal& e) override
	{
		std::cout << e.eval();
	}
	virtual void visit(const Add& e) override
	{
		std::cout << e.eval();
	}
	virtual void visit(const Mult& e) override
	{
		std::cout << e.eval();
	}
};
#endif // !EXP_H_