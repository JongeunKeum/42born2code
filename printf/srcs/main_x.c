#include <stdio.h>
#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...);

int		main(void)
{
	printf("return:%d\n", printf("01. hello %x world %10x\n\n", 12345, -9876));
	printf("return:%d\n", ft_printf("01. hello %x world %10x\n\n", 12345, -9876));

	printf("return:%d\n", printf("03. hello %10x world\n", 12345));
	printf("return:%d\n", ft_printf("03. hello %10x world\n\n", 12345));

	printf("04. hello %10x world\n", -12345);
	ft_printf("04. hello %10x world\n\n", -12345);

	printf("05. hello %010x world\n", 12345);
	ft_printf("05. hello %010x world\n\n", 12345);

	printf("06. hello %-10x world\n", 12345);
	ft_printf("06. hello %-10x world\n\n", 12345);

	printf("07. hello %-10x world\n", -12345);
	ft_printf("07. hello %-10x world\n\n", -12345);

	printf("08. hello %010x world\n", -12345);
	ft_printf("08. hello %010x world\n\n", -12345);

	printf("09. hello %4x world\n", 12345);
	ft_printf("09. hello %4x world\n\n", 12345);

	printf("10. hello %4x world\n", -12345);
	ft_printf("10. hello %4x world\n\n", -12345);

	printf("11. hello %10.5x world\n", 123);
	ft_printf("11. hello %10.5x world\n\n", 123);

	printf("12. hello %10.5x world\n", -123);
	ft_printf("12. hello %10.5x world\n\n", -123);

	printf("13. hello %10.1x world\n", 123);
	ft_printf("13. hello %10.1x world\n\n", 123);

	printf("14. hello %10.1x world\n", -123);
	ft_printf("14. hello %10.1x world\n\n", -123);

	printf("15. hello %2.5x world\n", 123);
	ft_printf("15. hello %2.5x world\n\n", 123);

	printf("16. hello %2.5x world\n", -123);
	ft_printf("16. hello %2.5x world\n\n", -123);

	printf("17. hello %2.2x world\n", 123);
	ft_printf("17. hello %2.2x world\n\n", 123);

	printf("18. hello %2.2x world\n", -123);
	ft_printf("18. hello %2.2x world\n\n", -123);

	printf("19. hello %.2x world\n", 123);
	ft_printf("19. hello %.2x world\n\n", 123);

	printf("20. hello %.2x world\n", -123);
	ft_printf("20. hello %.2x world\n\n", -123);

	printf("21. hello %.6x world\n", 123);
	ft_printf("21. hello %.6x world\n\n", 123);

	printf("22. hello %.6x world\n", -123);
	ft_printf("22. hello %.6x world\n\n", -123);

	printf("23. hello %010.5x world\n", 123);
	ft_printf("23. hello %010.5x world\n\n", 123);

	printf("24. hello %010.*x world\n", 5, 123);
	ft_printf("24. hello %010.*x world\n\n", 5, 123);

	printf("25. hello %10.*x world\n", 2, 123);
	ft_printf("25. hello %10.*x world\n\n", 2, 123);

	printf("26. hello %.*x world\n", 5, 123);
	ft_printf("26. hello %.*x world\n\n", 5, 123);

	printf("27. hello %.x world\n", 0);
	ft_printf("27. hello %.x world\n\n", 0);

	printf("28. hello %.0x world\n", 0);
	ft_printf("28. hello %.0x world\n\n", 0);

	printf("29. hello %10.x world\n", 0);
	ft_printf("29. hello %10.x world\n\n", 0);

	printf("30. hello %*x world\n", 10, 123);
	ft_printf("30. hello %*x world\n\n", 10, 123);

	printf("31. hello %0*x world\n", 10, 123);
	ft_printf("31. hello %0*x world\n\n", 10, 123);

	printf("32. hello %#x world\n", 123);
	ft_printf("32. hello %#x world\n\n", 123);

	printf("33. hello %#10x world\n", 123);
	ft_printf("33. hello %#10x world\n\n", 123);

	printf("34. hello %#5x world\n", 123);
	ft_printf("34. hello %#5x world\n\n", 123);

	printf("35. hello %#.7x world\n", 123);
	ft_printf("35. hello %#.7x world\n\n", 123);

	printf("35. hello %#.x world\n", 123);
	ft_printf("35. hello %#.x world\n\n", 123);

	printf("36. hello %#07x world\n", 123);
	ft_printf("36. hello %#07x world\n\n", 123);

	printf("37. hello %#-7.4x world\n", 123);
	ft_printf("37. hello %#-7.4x world\n\n", 123);

	printf("38. hello %#5x world\n", 0);
	ft_printf("38. hello %#5x world\n\n", 0);

	printf("38. hello %5x world\n", 0);
	ft_printf("38. hello %5x world\n\n", 0);

	printf("39. hello %#.5x world\n", 0);
	ft_printf("39. hello %#.5x world\n\n", 0);

	printf("39. hello %.5x world\n", 0);
	ft_printf("39. hello %.5x world\n\n", 0);

	printf("40. hello %#10.5x world\n", 0);
	ft_printf("40. hello %#10.5x world\n\n", 0);

	printf("40. hello %10.5x world\n", 0);
	ft_printf("40. hello %10.5x world\n\n", 0);

	printf("41. hello %10.x world\n", 0);
	ft_printf("41. hello %10.x world\n\n", 0);

	printf("42. hello %10.0x world\n", 0);
	ft_printf("42. hello %10.0x world\n\n", 0);

	printf("43. hello %#010x world\n", 123);
	ft_printf("43. hello %#010x world\n\n", 123);

	printf("44. hello %#010.5x world\n", 123);
	ft_printf("44. hello %#010.5x world\n\n", 123);

	printf("45. hello %#10x world\n", 123);
	ft_printf("45. hello %#10x world\n\n", 123);

	printf("46. hello %#x world\n", 123);
	ft_printf("46. hello %#x world\n\n", 123);

	printf("47. hello %-#x world\n", 123);
	ft_printf("47. hello %-#x world\n\n", 123);

	printf("48. hello %-#7x world\n", 123);
	ft_printf("48. hello %-#7x world\n\n", 123);

	printf("49. hello %#5x world\n", 52625);
	ft_printf("49. hello %#5x world\n\n", 52625);

//	printf("32. hello %+7x world\n", 123);
//	ft_printf("32. hello %+7x world\n\n", 123);

//	printf("33. hello %+7x world\n", -123);
//	ft_printf("33. hello %+7x world\n\n", -123);

//	printf("34. hello %+-7x world\n", 123);
//	ft_printf("34. hello %+-7x world\n\n", 123);

//	printf("35. hello %+-7x world\n", -123);
//	ft_printf("35. hello %+-7x world\n\n", -123);

//	printf("36. hello %+2x world\n", 123);
//	ft_printf("36. hello %+2x world\n\n", 123);

//	printf("37. hello %+2x world\n", -123);
//	ft_printf("37. hello %+2x world\n\n", -123);

//	printf("38. hello %+.7x world\n", 123);
//	ft_printf("38. hello %+.7x world\n\n", 123);

//	printf("39. hello %+.7x world\n", -123);
//	ft_printf("39. hello %+.7x world\n\n", -123);

//	printf("40. hello %+.2x world\n", 123);
//	ft_printf("40. hello %+.2x world\n\n", 123);

//	printf("41. hello %+.2x world\n", -123);
//	ft_printf("41. hello %+.2x world\n\n", -123);

//	printf("42. hello %+10.2x world\n", 123);
//	ft_printf("42. hello %+10.2x world\n\n", 123);

//	printf("43. hello %+10.2x world\n", -123);
//	ft_printf("43. hello %+10.2x world\n\n", -123);

//	printf("44. hello %+10.7x world\n", 123);
//	ft_printf("44. hello %+10.7x world\n\n", 123);

//	printf("45. hello %+10.7x world\n", -123);
//	ft_printf("45. hello %+10.7x world\n\n", -123);

//	printf("46. hello %+010.7x world\n", 123);
//	ft_printf("46. hello %+010.7x world\n\n", 123);

//	printf("47. hello %+010.7x world\n", -123);
//	ft_printf("47. hello %+010.7x world\n\n", -123);

//	printf("48. hello %+010x world\n", 123);
//	ft_printf("48. hello %+010x world\n\n", 123);

//	printf("49. hello %+-10.7x world\n", 123);
//	ft_printf("49. hello %+-10.7x world\n\n", 123);

//	printf("50. hello % x world\n", 123);
//	ft_printf("50. hello % x world\n\n", 123);

//	printf("51. hello % 7x world\n", 123);
//	ft_printf("51. hello % 7x world\n\n", 123);

//	printf("52. hello % 7x world\n", -123);
//	ft_printf("52. hello % 7x world\n\n", -123);

//	printf("53. hello % -7x world\n", 123);
//	ft_printf("53. hello % -7x world\n\n", 123);

//	printf("54. hello % -7x world\n", -123);
//	ft_printf("54. hello % -7x world\n\n", -123);

//	printf("55. hello % +7x world\n", 123);
//	ft_printf("55. hello % +7x world\n\n", 123);

//	printf("56. hello % +7x world\n", -123);
//	ft_printf("56. hello % +7x world\n\n", -123);

//	printf("55. hello % .7x world\n", 123);
//	ft_printf("55. hello % .7x world\n\n", 123);

//	printf("56. hello % .7x world\n", -123);
//	ft_printf("56. hello % .7x world\n\n", -123);

//	printf("57. hello % +05x world\n", 123);
//	ft_printf("57. hello % +05x world\n\n", 123);

//	printf("58. hello % +-10.5x world\n", -123);
//	ft_printf("58. hello % +-10.5x world\n\n", -123);

//	printf("59. hello %+-10.5x world\n", -216);
//	ft_printf("59. hello %+-10.5x world\n\n", -216);

//	printf("60. hello %+-8.3x world\n", -8473);
//	ft_printf("60. hello %+-8.3x world\n\n", -8473);

	return (0);
}
