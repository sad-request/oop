#pragma once
#include "IShape.hpp"

class ISolidShape: public IShape
{
public:
	virtual ~ISolidShape() {};
	virtual uint32_t GetFillColor() const = 0;
};
