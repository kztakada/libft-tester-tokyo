/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:22:06 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:45 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

void toupper_test(void)
{
	/* 1 */ ASSERT_EQ_I(ft_toupper('a'), toupper('a'));
	/* 2 */ ASSERT_EQ_I(ft_toupper('a' - 1), toupper('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_toupper('a' + 1), toupper('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_toupper('z'), toupper('z'));
	/* 5 */ ASSERT_EQ_I(ft_toupper('z' - 1), toupper('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_toupper('z' + 1), toupper('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_toupper('A'), toupper('A'));
	/* 8 */ ASSERT_EQ_I(ft_toupper('A' - 1), toupper('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_toupper('A' + 1), toupper('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_toupper('Z'), toupper('Z'));
	/* 11 */ ASSERT_EQ_I(ft_toupper('Z' - 1), toupper('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_toupper('Z' + 1), toupper('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_toupper('a' + 256), toupper('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_toupper('a' - 256), toupper('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_toupper('a' + 1), toupper('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_toupper('!'), toupper('!'));
	/* 17 */ ASSERT_EQ_I(ft_toupper('{'), toupper('{'));
	/* 18 */ ASSERT_EQ_I(ft_toupper('~'), toupper('~'));
	/* 19. zero */ ASSERT_EQ_I(ft_toupper(0), toupper(0));
	/* 20. INT_MAX */ ASSERT_EQ_I(ft_toupper(INT_MAX), toupper(INT_MAX));
	/* 21. INT_MIN */ ASSERT_EQ_I(ft_toupper(INT_MIN), toupper(INT_MIN));
	/* 22 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_toupper(i), toupper(i)); }
}
void linux_test(void)
{
			FILE *fp;
    char locale[128];

    // locale -a コマンドを実行して、利用可能なロケールを取得
    fp = popen("locale -a", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // 利用可能なロケールを一つずつ読み取り
    while (fgets(locale, sizeof(locale)-1, fp) != NULL) {
        // 改行文字を削除
        locale[strcspn(locale, "\n")] = 0;

        // ロケールを設定
        setlocale(LC_CTYPE, locale);
		toupper_test();
    }

    // コマンド実行を終了
    pclose(fp);
}

int	main(void)
{
	if (ISLINUX == 1)
		linux_test();
	else
		toupper_test();
	return (0);
}