#pragma once

#include "stdafx.hpp"

class IShape
{
public:
	virtual ~IShape() {};
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};

