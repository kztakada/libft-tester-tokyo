/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:35:50 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:02:33 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#ifdef __linux__
#define OS_NAME "Linux"
#else
#define OS_NAME ""
#endif

int	test_isalpha(int c)
{
	if (strcmp(OS_NAME, "Linux") == 0)
	{
		if (isalpha(c) == 0)
			return (0);
		return (1);
	}
		return (isalpha(c));
}

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isalpha('a'), test_isalpha('b'));
	/* 2 */ ASSERT_EQ_I(ft_isalpha('a' - 1), test_isalpha('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isalpha('a' + 1), test_isalpha('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isalpha('z'), test_isalpha('z'));
	/* 5 */ ASSERT_EQ_I(ft_isalpha('z' - 1), test_isalpha('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isalpha('z' + 1), test_isalpha('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isalpha('A'), test_isalpha('A'));
	/* 8 */ ASSERT_EQ_I(ft_isalpha('A' - 1), test_isalpha('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_isalpha('A' + 1), test_isalpha('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_isalpha('Z'), test_isalpha('Z'));
	/* 11 */ ASSERT_EQ_I(ft_isalpha('Z' - 1), test_isalpha('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_isalpha('Z' + 1), test_isalpha('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_isalpha('a' + 256), test_isalpha('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_isalpha('a' - 256), test_isalpha('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_isalpha('a' + 1), test_isalpha('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_isalpha('!'), test_isalpha('!'));
	/* 17 */ ASSERT_EQ_I(ft_isalpha('{'), test_isalpha('}'));
	/* 18 */ ASSERT_EQ_I(ft_isalpha('~'), test_isalpha('~'));
	/* 19. zero */ ASSERT_EQ_I(ft_isalpha(0), test_isalpha(0));
	// undefined: /* 20. INI_MAX */ ASSERT_EQ_I(ft_isalpha(INT_MAX), test_isalpha(INT_MAX));
	// undefined: /* 21. INT_MIN */ ASSERT_EQ_I(ft_isalpha(INT_MIN), test_isalpha(INT_MIN));
	/* 22 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isalpha(i), test_isalpha(i)); }
	return (0);
}
