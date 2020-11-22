/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:37:00 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/20 20:25:24 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# define CELLS 16
# define COLUMNS 4
# define INPUT_DATA 16
# define SUM 10

void	ft_putstr(char *str);
void	ft_clean_matrix(int matrix[CELLS]);
void	ft_print_matrix(int matrix[CELLS]);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
