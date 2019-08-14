#include "fractol.h"

char *load_kernel(const char *name)
{
	int fd;
	char *line;
	char *src;

	src = ft_strnew(1);
	if (0 > (fd = open(name, O_RDONLY)))
		terminate(STD, errno);
	while (get_next_line(fd, &line) > 0)
	{
		src = ft_strjoinfree(src, line, 3);
		src = ft_strjoinfree(src, "\n", 1);
	}
	free(line);
	close(fd);
	return (src);
}

static void build_program(t_opcl *opcl)
{
	cl_int err;
	char buf[10000];

	err = clBuildProgram(opcl->program, 1, &opcl->id, "-I includes", NULL, NULL);
	if (CL_SUCCESS != err)
	{
		clGetProgramBuildInfo(opcl->program, opcl->id, CL_PROGRAM_BUILD_LOG, 100000, &buf, NULL);
		ft_putstr(buf);
		terminate(CL, EXIT);
	}
	if (!(opcl->kernel = clCreateKernel(opcl->program, "draw_fractals", &err)))
		terminate(CL, EXIT);
}

/* Нужно дописать коды ошибок */
static void check_platform(t_opcl *opcl)
{
	cl_uint num_pltfrms;
	cl_uint nd;
	cl_platform_id pltfrm;
	cl_uint err;

	err = clGetPlatformIDs(0, NULL, &num_pltfrms);
	if (CL_SUCCESS != (err |= clGetPlatformIDs(num_pltfrms, &pltfrm, NULL)))
		terminate(CL, EXIT);

	err = clGetDeviceIDs(pltfrm, CL_DEVICE_TYPE_GPU, 0, NULL, &nd);
	if (CL_SUCCESS != (err |= clGetDeviceIDs(pltfrm, CL_DEVICE_TYPE_GPU, nd, &opcl->id, NULL)))
		terminate(CL, EXIT);
}

/* Нужно дописать коды ошибок */
void init_opencl(t_opcl *opcl)
{
	cl_int err;
	char *src;

	check_platform(opcl);
	if (!(opcl->context = clCreateContext(NULL, 1, &opcl->id, NULL, NULL, &err)))
		terminate(CL, EXIT);
	if (!(opcl->queue = clCreateCommandQueue(opcl->context, opcl->id, 0, &err)))
		terminate(CL, EXIT);
	opcl->out = clCreateBuffer(opcl->context, CL_MEM_WRITE_ONLY, WIDTH * HEIGHT * 4, NULL, &err);
	if (CL_SUCCESS != err)
		terminate(CL, EXIT);
	src = load_kernel(KERNEL_NAME);
	if(!(opcl->program = clCreateProgramWithSource(opcl->context, 1, (const char**)&src, NULL, &err)))
	 	terminate(CL, EXIT);
	build_program(opcl);
}
