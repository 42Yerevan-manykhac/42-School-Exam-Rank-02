/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:53:58 by manykhac          #+#    #+#             */
/*   Updated: 2022/08/06 15:59:22 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/

#include <unistd.h>

int check(char c, char *str, int  index)
{
	int i = index;
	while(str[i] != '\0')
	{	
		if (c == str[i])
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	return -1;
}


int main(int argc, char **argv)
{
	int i=0;
	int index = 0;
	if (argc ==3)
	{
		if(argv[1][i] == '\0')
		{
			write(1,"1",1);
		}
		else
		{
			while(argv[1][i]!= '\0')
			{
				index = check(argv[1][i], argv[2], index);
				if (index  != -1)
				{
					i++;
				}
				else if (index == -1)
				{
					write (1,"0", 1);
					break;
				}
			}
			if (index != -1)
			{
				write (1, "1", 1);
		   	}
		}
	}
	write (1, "\n", 1);
}
