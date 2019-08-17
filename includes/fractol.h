#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "libft.h"
#include "draw.h"
#include "errors.h"
#include "controls.h"
#include "get_next_line.h"

#define KERNEL_NAME "sources/krnl.cl"

#define R 1
#define G 2
#define B 3

typedef struct			s_opcl
{
	cl_device_id		id;
	cl_context			context;
	cl_command_queue	queue;
	cl_program 			program;
	cl_kernel			kernel;
	cl_mem				out;
	size_t				global_s;
	size_t				local_s;

}						t_opcl;

typedef struct			s_cam
{
	double 				zoom;
	double 				x_off;
	double 				y_off;
	int					iter;
	double				ms_re;
	double				ms_im;
	char				pause;
	double				zoom_x;
	double				zoom_y;
}						t_cam;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bts_pr_pxl;
	int					sz_ln;
	int					endian;
	char				fract_id;
	t_opcl				*opcl;
	t_cam				*cam;
}						t_env;

/* 					Data Inicialisation					*/
char					check_input(int argc, char **argv);
void					init_env(t_env *env);
void					init_opencl(t_opcl *opcl);

/* 					Controls							*/
void					key_hooks(t_env *env);
void					zoom(int button, int x, int y, t_env *env);
void					move_cam(int key, t_env *env);
void					change_c_julia(t_env *env, int x, int y);
void					change_color(t_env *env);
void					change_multi_mandel(int key, t_env *env);
void					draw(t_env *env);

/*					Errors								*/
//void					cl_errors();
void					std_err(int err_code);

/*					Exit								*/
int						x_close(void *param);
void					terminate(char flag, int err_code);

#endif