#include "fractol.h"

static void set_args_to_kernel(t_env *env)
{
	cl_int err;

	err = clSetKernelArg(env->opcl->kernel, 0, sizeof(cl_mem), &env->opcl->out);
	err |= clSetKernelArg(env->opcl->kernel, 1, sizeof(double), &env->cam->zoom);
	err |= clSetKernelArg(env->opcl->kernel, 2, sizeof(double), &env->cam->x_off);
	err |= clSetKernelArg(env->opcl->kernel, 3, sizeof(double), &env->cam->y_off);
	err |= clSetKernelArg(env->opcl->kernel, 4, sizeof(char), &env->fract_id);
	err |= clSetKernelArg(env->opcl->kernel, 5, sizeof(int), &env->cam->iter);
	if (CL_SUCCESS != err)
		terminate(EXIT, CL);
}

static void set_work_size(t_opcl *opcl)
{
	cl_int err;

	opcl->global_s = WIDTH * HEIGHT;

	err = clGetKernelWorkGroupInfo(opcl->kernel, opcl->id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(opcl->local_s), &opcl->local_s, NULL);
	if (CL_SUCCESS != err)
		terminate(CL, EXIT);
}

static void rendering(t_env *env)
{
	//cl_int err;

	set_work_size(env->opcl);
	set_args_to_kernel(env);
	clEnqueueNDRangeKernel(env->opcl->queue, env->opcl->kernel, 1, NULL, &env->opcl->global_s, &env->opcl->local_s, 0, NULL, NULL);
}

void draw(t_env *env)
{
	ft_bzero(env->data_addr, (WIDTH * env->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(env->mlx, env->win);
	rendering(env);
	clEnqueueReadBuffer(env->opcl->queue, env->opcl->out, CL_TRUE, 0, WIDTH * HEIGHT * 4, env->data_addr, 0, NULL, NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_do_sync(env->mlx);
}