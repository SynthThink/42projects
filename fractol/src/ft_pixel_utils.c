void	place_pixel(t_win *mlx, int u, int v, int color)
{
	int	coord;
	int	red;
	int	blue;
	int	green;

	if (color == 0)
		color = rgb(255, 255, 255);
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color) & 0xFF;
	u = ft_imax(u, 0);
	coord = u * 4 + v * WIDTH * 4;
	if (coord < WIDTH * 4 * HEIGHT && coord >= 0 && u < WIDTH)
	{
		(mlx->image_str)[coord] = blue;
		(mlx->image_str)[coord + 1] = green;
		(mlx->image_str)[coord + 2] = red;
	}
}
