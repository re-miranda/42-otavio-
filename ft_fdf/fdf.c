/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:49:07 by oburato           #+#    #+#             */
/*   Updated: 2022/09/07 20:33:12 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>

#define K_Escape 0xff1b
#define DestroyNotify 17
#define NoEventMask 0L

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int ft_render(t_screen *screen);
int ft_close(t_screen *screen);
int ft_render_rect(t_screen *screen, t_rect rect);
int ft_render_line(t_screen *screen, t_rect rect);

int ft_render_line(t_screen *screen, t_rect rect)
{
	int i;
	int j;

	if (screen->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(screen->mlx_ptr, screen->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

int ft_render_rect(t_screen *screen, t_rect rect)
{
	int y;
	int x;

	if (screen->win_ptr == NULL)
		return (1);
	y = rect.y;
	while (y < rect.y + rect.height)
	{
		x = rect.x;
		while (x < rect.x + rect.width)
			mlx_pixel_put(screen->mlx_ptr, screen->win_ptr, x++, y, rect.color);
		++y;
	}
	return (0);
}

int ft_key_hook(int keysym, t_screen *screen)
{
	if (keysym == K_Escape)
	{
		mlx_destroy_image(screen->mlx_ptr, screen->img.mlx_img);
		mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
		mlx_destroy_display(screen->mlx_ptr);
		mlx_loop_end(screen->mlx_ptr);
		free(screen->mlx_ptr);
		free(screen);
		exit(0);
	}
	printf("-> %d \n", keysym); // TODO TIRAR
	return (0);
}

int ft_close(t_screen *screen)
{
	mlx_destroy_image(screen->mlx_ptr, screen->img.mlx_img);
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	mlx_destroy_display(screen->mlx_ptr);
	mlx_loop_end(screen->mlx_ptr);
	free(screen->mlx_ptr);
	free(screen);
	exit(0);
}

int ft_render(t_screen *screen)
{
	ft_render_rect(screen, (t_rect){0, 0, 100, 100, 0xFF0000});
	return (0);
}

int main(void)
{
	setbuf(stdout, NULL); // TODO TIRAR
	t_screen *screen;

	screen = (t_screen *)malloc(sizeof(t_screen));
	screen->mlx_ptr = mlx_init();

	if (screen->mlx_ptr == NULL)
		return (1);
	screen->win_ptr = mlx_new_window(screen->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (screen->win_ptr == NULL)
		return (1);

	screen->img.mlx_img = mlx_new_image(screen->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

	mlx_hook(screen->win_ptr, DestroyNotify, NoEventMask, ft_close, screen);
	mlx_key_hook(screen->win_ptr, ft_key_hook, screen);
	mlx_loop_hook(screen->mlx_ptr, ft_render, screen);

	mlx_loop(screen->mlx_ptr);
}
