#include "ft_printf.h"

int	main(void)
{
	size_t	count;
	int		x;

	// ft_putchar
	count = 0;
	write(1, "ft_putchar: ", 13);
	ft_putchar('A', &count);
	write(1, " | count = ", 11);
	ft_putnbr(count, &count);
	write(1, "\n\n", 2);
	// ft_putstr
	count = 0;
	write(1, "ft_putstr: ", 12);
	ft_putstr("Hello I am Ahmed.", &count);
	write(1, " | count = ", 11);
	ft_putnbr(count, &count);
	write(1, "\n\n", 2);
	// ft_putnbr(signed)
	count = 0;
	write(1, "ft_putnbr: ", 12);
	ft_putnbr(-12345, &count);
	write(1, " | count = ", 11);
	ft_putnbr(count, &count);
	write(1, "\n\n", 2);
	// ft_putunbr
	count = 0;
	write(1, "ft_putunbr: ", 13);
	ft_putunbr(123456789, &count);
	write(1, " | count = ", 11);
	ft_putnbr(count, &count);
	write(1, "\n\n", 2);
	// ft_puthexa
	count = 0;
	write(1, "ft_puthexa (x): ", 17);
	ft_puthexa(15, &count, 'x');
	write(1, "\nft_puthexa (X): ", 18);
	ft_puthexa(255, &count, 'X');
	write(1, "\n\n", 2);
	// ft_putaddr
	count = 0;
	x = 42;
	write(1, "ft_putaddr: ", 13);
	ft_putaddr(&x, &count);
	write(1, "\nft_putaddr(NULL): ", 20);
	ft_putaddr(NULL, &count);
	write(1, "\n", 1);
}
