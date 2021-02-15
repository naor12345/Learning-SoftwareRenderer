#include "utils.h"

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	bool sharp = false;
	if (std::abs(x0 - x1) < std::abs(y0 - y1)) 
	{
		sharp = true;
		std::swap(x0, y0);
		std::swap(x1, y1);
	}

	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}


	int dx = x1 - x0;
	int dy = y1 - y0;

	int k = 2 * dy;
	int up = k >= 0 ? 1 : -1;
	k = std::abs(k);
	int error = 0;
	int y = y0;

	if (sharp)
	{
		for (int i = x0; i < x1; ++i)
		{
			image.set(y, i, color);
			error += k;
			if (error > dx)
			{
				error -= 2 * dx;
				y += up;
			}
		}
	}
	else
	{
		for (int i = x0; i < x1; ++i)
		{
			image.set(i, y, color);
			error += k;
			if (error > dx)
			{
				error -= 2 * dx;
				y += up;
			}
		}
	}
}