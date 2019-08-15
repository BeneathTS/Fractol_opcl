#include "draw.h"

static int get_x(size_t id)
{
	while (id >= WIDTH)
		id -= WIDTH;
	return ((int)id);
}

void kernel draw_fractals(__global char *out, double zoom, double x_off, double y_off, 
char fract_id, int iter, double ms_re, double ms_im)
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
	c_re = (x - WIDTH / 2) / (0.6 * zoom * WIDTH) + x_off;
	c_im = (y - HEIGHT / 2) / (zoom * HEIGHT) + y_off;
	re[NEW] = c_re;
	im[NEW] = c_im;
	if (fract_id == MANDEL)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = POW(re[OLD]) - POW(im[OLD]) + c_re;
			im[NEW] = 2 * re[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == JUL)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = POW(re[OLD]) - POW(im[OLD]) + ms_re;
			im[NEW] = 2 * re[OLD] * im[OLD] + ms_im;
		}
	}
	else if (fract_id == BRN_SP)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			im[NEW] = 2.0 * fabs(re[OLD] * im[OLD])+ c_im;
			re[NEW] = POW(re[OLD]) - POW(im[OLD]) + c_re;
		}
	}
	if(i < iter)
		((__global int*)out)[id] = (i * 8) % 255; 
	else
	 	((__global int*)out)[id]  = 0x0;
}
