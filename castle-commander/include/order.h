#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
	virtual ~Order() = default;
	virtual void Execute() = 0;
};

#endif
