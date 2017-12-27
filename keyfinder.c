#include <mlx.h>
#include <X.h>
#include <stdio.h>

int	print_key(int keycode, void *not)
{
	(void)not;
	printf("%#x\n", keycode);
	return (0);
}

int main(int argc, const char *argv[])
{
	void	*mlx;
	void	*win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "Keyfinder");
	mlx_hook(win, KeyPress, KeyPressMask, print_key, mlx);
	mlx_loop(mlx);
	return 0;
}
