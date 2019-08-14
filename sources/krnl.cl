#include "draw.h"

static int get_x(size_t id)
{
	while (id > WIDTH)
		id -= WIDTH;
	return ((int)id);
}

void kernel draw_fractals(__global char *out, double zoom, double x_off, double y_off, char fract_id, int iter)
{
	double re[2];
	double im[2];
	int x;
	int y;
	double c_im;
	double c_re;
	int i;
	size_t id;

	id = get_global_id(0);

	x = get_x(id);
	y = id / WIDTH;
	i = -1;
	if (fract_id == MANDEL)
	{
		c_re = (x - WIDTH / 2) / (0.6 * zoom * WIDTH) + x_off;
		c_im = (y - HEIGHT / 2) / (zoom * HEIGHT) + y_off;
		re[NEW] = c_re;
		im[NEW] = c_im;
		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
			im[NEW] = 2 * re[OLD] * im[OLD] + c_im;
		}
		if(i < iter)
			((__global unsigned int*)out)[id] = 0xFFFFFF; 
		 else
		 	((__global unsigned int*)out)[id]  = 0x0;
	}
}
