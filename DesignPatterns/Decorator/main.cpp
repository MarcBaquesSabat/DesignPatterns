#include <iostream>

class Beverage {
private:
	
public:
	std::string description = "Beverage description.";
	std::string& GetDescription() {
		return description;
	}
	virtual int Cost() const = 0;
};

class CondimentDecorator : public Beverage {
public:
	virtual std::string GetDescription() const = 0;
	Beverage* beverage{ nullptr };
private:

};

class Espresso : public Beverage {
public:
	Espresso() {
		description = "Espresso";
	}
private:

	// Inherited via Beverage
	virtual int Cost() const override
	{
		return 5;
	}
};

class Coffee : public Beverage {
public:
	Coffee() {
		description = "Coffee";
	}
private:

	// Inherited via Beverage
	virtual int Cost() const override
	{
		return 4;
	}
};

class Milk : public CondimentDecorator {
public:
	Milk(Beverage& _beverage) {
		description = "Milk";
		beverage = &_beverage;
	}
private:
	// Inherited via CondimentDecorator
	virtual int Cost() const override
	{
		return beverage->Cost() + 1;
	}

	virtual std::string GetDescription() const override
	{
		return beverage->GetDescription() + ", Milk";
	}

};

int main() {

	std::cout << "Hello world.\n";
	Beverage* myBeverage = new Espresso();
	
	return 0;
}

