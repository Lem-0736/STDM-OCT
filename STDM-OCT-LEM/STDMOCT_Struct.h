#pragma once

struct scanSize
{
	int d, w, h;

};

struct scanVolt
{
	double x, y, x0, y0;
	double* xVoltBuf;
	double* yVoltBuf;
};
