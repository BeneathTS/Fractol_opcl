#include "draw.h"

int set_color(int i, char c_id)
{
	if (c_id == STD_COLOR)
		return (((i * 6) % 255) << 16 | ((i * 6) % 255));
	else if (c_id == GREEN)
		return (((i * 6) % 255) << 8);
	else if (c_id == BLUE)
		return (((i * 6) % 255));
	else if (c_id == RED)
		return (((i * 6) % 255) << 16);
	else if (c_id == WHITE)
		return (((i * 6) % 255) << 16 | ((i * 6) % 255) << 8 | ((i * 6) % 255));
	else if (c_id == BLACK_N_WHITE)
	{
		if (i % 2)
			return (((i * 6) % 255) << 16 | ((i * 6) % 255) << 8 | ((i * 6) % 255));
		else 
			return (0x0);
	}
	else if (c_id == DRK_BLUE)
		return (i > 2 ? 0x36665c / i : 0x153836);
}

static int get_x(size_t id)
{
	while (id >= WIDTH)
		id -= WIDTH;
	return ((int)id);
}

void kernel draw_fractals(__global char *out, double zoom, double x_off, double y_off, 
char fract_id, int iter, double ms_re, double ms_im, double zoom_x, double zoom_y, char c_id)
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
	c_re = (x - zoom_x) / (zoom * WIDTH / HEIGHT) + x_off;
	c_im = (y - zoom_y) / (zoom * WIDTH / HEIGHT) + y_off;
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
	else if (fract_id == MULTI_MANDEL_3)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = re[OLD] * re[OLD] * re[OLD] - 3 * re[OLD] * im[OLD] * im[OLD] + c_re;
			im[NEW] = 3 * re[OLD] * re[OLD] * im[OLD] - im[OLD] * im[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == MULTI_MANDEL_4)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = re[OLD] * re[OLD] * re[OLD] * re[OLD] + 
			im[NEW] * im[OLD] * im[OLD] * im[OLD] - 
			6 * re[OLD] * re[OLD] * im[OLD] * im[OLD] + c_re;
			im[NEW] = 4 * re[OLD] * re[OLD] * re[OLD] * im[OLD] - 
			4 * re[OLD] * im[OLD] * im[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == MULTI_MANDEL_5)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = re[OLD] * re[OLD] * re[OLD] * re[OLD] * re[OLD] -
			10 * re[OLD] * re[OLD] * re[OLD] * im[OLD] * im[OLD] +
			5 * re[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] + c_re;
			im[NEW] = 5 * re[OLD] * re[OLD] * re[OLD] * re[OLD] * im[OLD] -
			10 * re[OLD] * re[OLD] * im[OLD] * im[OLD] * im[OLD] + 
			im[OLD] * im[OLD] * im[OLD] * im[OLD] *im[OLD] + c_im;
		}
	}
	else if (fract_id == MULTI_MANDEL_6)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			
			re[NEW] = re[OLD] * re[OLD] * re[OLD] * re[OLD] * re[OLD] * re[OLD] -
			im[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] -
			15 * re[OLD] * re[OLD] * re[OLD] * re[OLD] * im[OLD] * im[OLD] +
			15 * re[OLD] * re[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] + c_re;
			im[NEW] = 6 * re[OLD] * re[OLD] * re[OLD] * re[OLD] * re[OLD] * im[OLD] +
			6 * re[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] * im[OLD] - 
			20 * re[OLD] * re[OLD] * re[OLD] * im[OLD] * im[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == TRICORN)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = POW(re[OLD]) - POW(im[OLD]) + c_re;
			im[NEW] = -2 * re[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == CEL_MANDEL)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = fabs(POW(re[OLD]) - POW(im[OLD])) + c_re;
			im[NEW] = 2 * re[OLD] * im[OLD] + c_im;
		}
	}
	else if (fract_id == CEL_MANDEL_C)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			re[NEW] = fabs(POW(re[OLD]) - POW(im[OLD])) + ms_re;
			im[NEW] = 2 * re[OLD] * im[OLD] + ms_im;
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
	else if (fract_id == BRN_SP_C)
	{
		while (POW(re[NEW]) + POW(im[NEW]) < 4 && ++i < iter)
		{
			re[OLD] = re[NEW];
			im[OLD] = im[NEW];
			im[NEW] = 2.0 * fabs(re[OLD] * im[OLD])+ ms_im;
			re[NEW] = POW(re[OLD]) - POW(im[OLD]) + ms_re;
		}
	}
	if(i < iter)
		((__global int*)out)[id] = set_color(i, c_id); //(i * 8) % 255
	else
	 	((__global int*)out)[id]  = 0x0;
}
