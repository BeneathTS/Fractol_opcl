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
	err |= clSetKernelArg(env->opcl->kernel, 6, sizeof(double), &env->cam->ms_re);
	err |= clSetKernelArg(env->opcl->kernel, 7, sizeof(double), &env->cam->ms_im);
	err |= clSetKernelArg(env->opcl->kernel, 8, sizeof(double), &env->cam->zoom_x);
	err |= clSetKernelArg(env->opcl->kernel, 9, sizeof(double), &env->cam->zoom_y);
	if (CL_SUCCESS != err)
		cl_err_exit(env->opcl, ERR_SET_KERNEL_ARG);
}

static void set_work_size(t_opcl *opcl)
{
	cl_int err;

	opcl->global_s = WIDTH * HEIGHT;

	err = clGetKernelWorkGroupInfo(opcl->kernel, opcl->id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(opcl->local_s), &opcl->local_s, NULL);
	if (CL_SUCCESS != err)
		cl_err_exit(opcl, ERR_GET_LOCAL_SIZE);
}

static void rendering(t_env *env)
{
	cl_int err;

	set_work_size(env->opcl);
	set_args_to_kernel(env);
	err = clEnqueueNDRangeKernel(env->opcl->queue, env->opcl->kernel, 1, NULL, &env->opcl->global_s, &env->opcl->local_s, 0, NULL, NULL);
	if (CL_SUCCESS != err)
		cl_err_exit(env->opcl, ERR_NDRANGE);
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