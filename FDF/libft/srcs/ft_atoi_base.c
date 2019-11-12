/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:11:18 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/09 14:13:40 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test_base(const char c)
{
    int		nb;

    if (c >= '0' && c <= '9')
        nb = c - '0';
    else if (c >= 'a' && c <= 'z')
        nb = c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        nb = c - 'A' + 10;
    else
        nb = -1;
    return (nb);
}

int		ft_atoi_base(const char *str, int base)
{
    int		neg;
    int		nb;
    int		i;

    nb = 0;
    while (*str == ' ' || *str == '\n' || *str == '\t'
           || *str == '\f' || *str == '\r' || *str == '\v')
        str++;
    neg = (*str == '-' ? 1 : 0);
    if (*str == '-' || *str == '+')
        str++;
    i = test_base(*str);
    while (i >= 0 && i < base)
    {
        nb = nb * base + i;
        str++;
        i = test_base(*str);
    }
    return (neg ? -nb : nb);
}
