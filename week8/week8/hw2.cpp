#include <iostream>

class Strategy
{
public:
	virtual int doOperation(int n1, int n2) { return 0; }
};


class OperationAdd : public Strategy {

public:
	int doOperation(int n1, int n2) {
		return n1 + n2;
	}
};

class OperationMultiply : public Strategy {

public:
	int doOperation(int n1, int n2)  {
		return n1 * n2;
	}
};

class OperationSubstract : public Strategy {

public:
	int doOperation(int n1, int n2)  {
		return n1 - n2;
	}
};


class Context {
private:
	Strategy* strategy;
public:
	Context(Strategy* strategy) {
		this->strategy = strategy;
	}
	int executeStrategy(int n1, int n2) {
		return (*strategy).doOperation(n1, n2);
	}
};


int main(void) {


	Context context =  Context(new OperationAdd());
	printf("10 + 5 = %d\n", context.executeStrategy(10, 5));

	context = Context(new OperationSubstract());
	printf("10 - 5 = %d\n", context.executeStrategy(10, 5));

	context = Context(new OperationMultiply());
	printf("10 * 5 = %d\n", context.executeStrategy(10, 5));

	return 0;
}