/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:51:05 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:03:48 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#ifdef __linux__
#define OS_NAME "Linux"
#else
#define OS_NAME ""
#endif

int	test_isdigit(int c)
{
	if (strcmp(OS_NAME, "Linux") == 0)
	{
		if (isdigit(c) == 0)
			return (0);
		return (1);
	}
		return (isdigit(c));
}

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isdigit('0'), test_isdigit('0'));
	/* 2 */ ASSERT_EQ_I(ft_isdigit('0' - 1), test_isdigit('0' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isdigit('0' + 1), test_isdigit('0' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isdigit('9'), test_isdigit('9'));
	/* 5 */ ASSERT_EQ_I(ft_isdigit('9' - 1), test_isdigit('9' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isdigit('9' + 1), test_isdigit('9' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isdigit('!'), test_isdigit('!'));
	/* 8 */ ASSERT_EQ_I(ft_isdigit('{'), test_isdigit('}'));
	/* 9 */ ASSERT_EQ_I(ft_isdigit('~'), test_isdigit('~'));
	/* 10. zero */ ASSERT_EQ_I(ft_isdigit(0), test_isdigit(0));
	// undefined: /* 11. INI_MAX */ ASSERT_EQ_I(ft_isdigit(INT_MAX), test_isdigit(INT_MAX));
	// undefined: /* 12. INT_MIN */ ASSERT_EQ_I(ft_isdigit(INT_MIN), test_isdigit(INT_MIN));
	/* 13 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isdigit(i), test_isdigit(i)); }
	return (0);
}
