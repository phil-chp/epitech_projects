/*
** EPITECH PROJECT, 2020
** My Is Negative ?
** File description:
** Checks if a Number is Positive or Negative.
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else if (n >= 0) {
        my_putchar('P');
    }
    return (0);
}
