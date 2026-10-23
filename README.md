# ft_printf

An educational C implementation of a subset of `printf`, built for the 42 curriculum to study variadic arguments, format parsing, and numeric conversion.

## Build and use

Requires a C compiler, Make, and `ar`.

```bash
git clone https://github.com/ahmedaitelaaoud/printf.git
cd printf
make
```

This produces `libftprintf.a`. Include `ft_printf.h` and link the archive after your source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("value=%d, hex=%x\n", 42, 42u);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror -I. example.c libftprintf.a -o example
./example
```

## Supported conversions

| Specifier | Value |
| --- | --- |
| `%c`, `%s` | Character and string |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x`, `%X` | Lowercase or uppercase hexadecimal |
| `%p` | Pointer address |
| `%%` | Literal percent sign |

`ft_printf.c` walks the format string and dispatches to the conversion helpers. The helpers write to standard output and accumulate a count. The public interface is `int ft_printf(const char *format, ...)`.

## Scope and limitations

This is not a complete libc-compatible formatter: width, precision, flags, floating-point conversions, and length modifiers are not implemented. Output failures need stronger handling; the current count accumulation does not provide a comprehensive `write()` error contract. Early error returns also deserve review for balanced variadic-argument cleanup.

No automated test suite is committed. Useful next checks are output and return-value comparisons for supported conversions, integer boundaries, pointer formatting, and failed output writes.

```bash
make clean
make fclean
make re
```

## License

No repository-level license is currently included. The previous MIT badge did not correspond to a LICENSE file.
