/* $Id$ */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//
// Доработки для LS020 Василий Линывый, livas60@mail.ru
//

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "hardware.h"	/* зависящие от процессора функции работы с портами */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef uint_fast16_t COLOR565_T;
typedef uint16_t PACKEDCOLOR565_T;
typedef uint_fast32_t COLOR24_T;
// RRRRRRR.GGGGGGGG.BBBBBBBB
#define COLOR24(red, green, blue) \
	(  (unsigned long) \
		(	\
			(((unsigned long) (red) << 16) & 0xFF0000ul)  | \
			(((unsigned long) (green) << 8) & 0xFF00ul) | \
			(((unsigned long) (blue) << 0) & 0xFFul) \
		) \
	)

// Get color componens from COLOR24_T value
#define COLOR24_R(v) (((v) >> 16) & 0xFF)
#define COLOR24_G(v) (((v) >> 8) & 0xFF)
#define COLOR24_B(v) (((v) >> 0) & 0xFF)

#define COLOR24_KEY	COLOR24(0xA0, 0, 0xA0)	// Цвет для прозрачных пикселей

#if LCDMODE_UC1601

	#include "uc1601s.h"

#endif /* LCDMODE_UC1601 */

#if LCDMODE_RDX0120 || LCDMODE_G1203H
	// Маленькие дисплеи с 32 точками по вертикали
	#include "pcf8535.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG
	#define DEFAULT_LCD_CONTRAST	100

#elif LCDMODE_RDX0077

	#define HALFCOUNT_BIG 2		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG
	#define DEFAULT_LCD_CONTRAST	100 	//  на SW2011RDX питание 8 вольт

#elif LCDMODE_RDX0154 || LCDMODE_RDT065

	#define HALFCOUNT_BIG 2		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

	#define DEFAULT_LCD_CONTRAST	100 	//  на SW2011RDX питание 8 вольт

#elif LCDMODE_UC1608
	// 240*128

	#include "uc1608.h"

	#define HALFCOUNT_BIG 5		// big and half sizes
	#define HALFCOUNT_SMALL 2	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define DEFAULT_LCD_CONTRAST	20

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_LS020 || LCDMODE_LPH88 || LCDMODE_L2F50

	#if LCDMODE_L2F50
		#include "l2f50.h"
	#elif LCDMODE_LS020
		#include "ls020.h"
	#elif LCDMODE_LPH88
		#include "lph88.h"
	#else
		#error Wrong LCDMODE_xxx
	#endif

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

	#define DEFAULT_LCD_CONTRAST	255

#elif LCDMODE_S1D13781 || LCDMODE_LQ043T3DX02K || LCDMODE_AT070TN90 || LCDMODE_AT070TNA2

	#include "s1d13781.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_WH2002 || LCDMODE_WH2004 || LCDMODE_WH2002_IGOR

	#include "hd44780.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_WH1602 || LCDMODE_WH1604

	#include "hd44780.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_ILI9320
	/* Индикатор 248*320 с контроллером ILI9320 */

	#include "ILI9320.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1 // 2	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

	#define DEFAULT_LCD_CONTRAST	255

#elif LCDMODE_ILI9225 || LCDMODE_ST7781
	/* Индикатор 178*220 с контроллером ILI9320 */
	// 320*240 ST7781

	#include "ILI9225.h"


	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_ST7735 || LCDMODE_ILI9163 || LCDMODE_ILI9341
	/* Индикатор 160*128 с контроллером Sitronix ST7735 */
	/* Индикатор 176*132 с контроллером ILITEK ILI9163 */
	/* Индикатор 320*240 с контроллером ILITEK ILI9341 */

	#include "st7735.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_ILI8961
	/* Индикатор 320*240 с контроллером ILITEK ILI8961 */

	#include "ili8961.h"

	#define HALFCOUNT_BIG 1		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_ST7565S || LCDMODE_PTE1206
	/* Индикатор WO12864C2-TFH# 128*64 с контроллером Sitronix ST7565S */

	#include "st7565s.h"


	#define HALFCOUNT_BIG 2		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size
	#define HALFCOUNT_BAR 1		// small size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_PCF8535 || LCDMODE_PCF8531

	#include "pcf8535.h"

	#define DEFAULT_LCD_CONTRAST	55 // 100

	#define HALFCOUNT_BIG 2		// big and half sizes
	#define HALFCOUNT_SMALL 1	// small size
	#define HALFCOUNT_SMALL2 1	// small2 size

	#define HALFCOUNT_FREQA HALFCOUNT_BIG

#elif LCDMODE_DUMMY
	/* При использовании frame buffer цвета восьмибитные */
	typedef uint_fast8_t COLORMAIN_T;
	typedef uint8_t PACKEDCOLORMAIN_T;
	typedef uint_fast8_t COLORPIP_T;
	typedef uint8_t PACKEDCOLORPIP_T;

	// для формирования растра с изображением водопада и спектра
	// RRRR.RGGG.GGGB.BBBB
	#define TFTRGB565(red, green, blue) 0

	#define TFTRGB(red, green, blue) 0

#else
	#error Undefined display type
#endif


#if LCDMODE_LTDC

	#define DISPLAYMODES_FPS 5	/* количество обновлений отображения режимов работы */
	#define DISPLAY_FPS	10	/* обновление показаний частоты десять раз в секунду */
	#define DISPLAYSWR_FPS 10	/* количество обновлений SWR и панорамы за секунду */

	#define LCDMODE_COLORED	1

	#if LCDMODE_LTDC_L24

		typedef uint_fast32_t COLORMAIN_T;
		struct rgb_24b
		{
			uint8_t r, g, b;
		} ATTRPACKED;// аттрибут GCC, исключает "дыры" в структуре.

		typedef struct rgb_24b PACKEDCOLORMAIN_T;	// 3 байта для последовательной выдачи как RGB для LCDMODE_ILI8961

		// RRRRRRR.GGGGGGGG.BBBBBBBB
		#define TFTRGB(red, green, blue) \
			(  (unsigned long) \
				(	\
					(((unsigned long) (red) << 16) & 0xFF0000ul)  | \
					(((unsigned long) (green) << 8) & 0xFF00ul) | \
					(((unsigned long) (blue) << 0) & 0xFFul) \
				) \
			)

	#elif LCDMODE_MAIN_L8

		/* При использовании frame buffer цвета восьмибитные */
		typedef uint_fast8_t COLORMAIN_T;
		typedef uint8_t PACKEDCOLORMAIN_T;

		// RRRGGGBB
		#define TFTRGB(red, green, blue) \
			(  (unsigned char) \
				(	\
					(((red) >> 0) & 0xe0)  | \
					(((green) >> 3) & 0x1c) | \
					(((blue) >> 6) & 0x03) \
				) \
			)

		// для формирования растра с изображением водопада и спектра
		// RRRR.RGGG.GGGB.BBBB
		#define TFTRGB565(red, green, blue) \
			(  (uint_fast16_t) \
				(	\
					(((uint_fast16_t) (red) << 8) &   0xF800)  | \
					(((uint_fast16_t) (green) << 3) & 0x07E0) | \
					(((uint_fast16_t) (blue) >> 3) &  0x001F) \
				) \
			)

	#else /* LCDMODE_MAIN_L8 */

		//#define LCDMODE_RGB565 1
		typedef uint_fast16_t COLORMAIN_T;
		typedef uint16_t PACKEDCOLORMAIN_T;

		// RRRR.RGGG.GGGB.BBBB
		#define TFTRGB(red, green, blue) \
			(  (uint_fast16_t) \
				(	\
					(((uint_fast16_t) (red) << 8) &   0xf800)  | \
					(((uint_fast16_t) (green) << 3) & 0x07e0) | \
					(((uint_fast16_t) (blue) >> 3) &  0x001f) \
				) \
			)

		// для формирования растра с изображением водопада и спектра
		#define TFTRGB565 TFTRGB

	#endif /* LCDMODE_MAIN_L8 */

	#if LCDMODE_PIP_L8
		typedef uint8_t PACKEDCOLORPIP_T;
		typedef uint_fast8_t COLORPIP_T;

	#elif LCDMODE_PIP_RGB565
		typedef uint16_t PACKEDCOLORPIP_T;
		typedef uint_fast16_t COLORPIP_T;

	#else /* LCDMODE_PIP_RGB565 */
		/* если только MAIN - тип PIP соответствует */
		typedef PACKEDCOLORMAIN_T PACKEDCOLORPIP_T;
		typedef COLORMAIN_T COLORPIP_T;

	#endif /* LCDMODE_PIP_L8 */


#endif /* LCDMODE_LTDC */

#define GXALIGN 8	/* размер каждой строки видеобуфера кратен этому заначению */

#define GXADJ(dx) (((dx) + (GXALIGN - 1)) / GXALIGN * GXALIGN)
#define MGADJ(dx) (((dx) + (MGALIGN - 1)) / MGALIGN * MGALIGN)

#if LCDMODE_S1D13781
	// биты слова буфера располагаются на экране горизонтально
	// старший битт левее
	#define MGALIGN 16
	typedef uint16_t GX_t;	/* тип элемента буфера для выдачи монохромного растра */
#elif LCDMODE_COLORED
	// биты слова буфера располагаются на экране вертикально
	#define MGALIGN 8
	typedef uint8_t GX_t;	/* тип элемента буфера для выдачи монохромного растра */
#else	/* LCDMODE_S1D13781 */
	// биты слова буфера располагаются на экране вертикально
	#define MGALIGN 8
	typedef uint8_t GX_t;	/* тип элемента буфера для выдачи монохромного растра */
#endif	/* */

#define MGSIZE(dx, dy)	((unsigned long) MGADJ(dx) * (dy))	// размер буфера для монохромного растра
#define GXSIZE(dx, dy)	((unsigned long) GXADJ(dx) * (dy))	// размер буфера для цветного растра

COLORMAIN_T display_getbgcolor(void);
void display_setbgcolor(COLORMAIN_T c);

// Интерфейсные функции, специфические для драйвера дисплея - зависящие от типа микросхемы контроллера.
void display_hardware_initialize(void);	/* вызывается при запрещённых прерываниях. */
void display_reset(void);				/* вызывается при разрешённых прерываниях. */
void display_initialize(void);			/* вызывается при разрешённых прерываниях. */
void display_discharge(void);			/* вызывается при разрешённых прерываниях. */
void display_set_contrast(uint_fast8_t v);

/* индивидуальные функции драйвера дисплея - реализованы в соответствующем из файлов */
void display_clear(void);
void colmain_setcolors(COLORMAIN_T fg, COLORMAIN_T bg);
void colmain_setcolors3(COLORMAIN_T fg, COLORMAIN_T bg, COLORMAIN_T bgfg);	// bgfg - цвет для отрисовки антиалиасинга

#if 1
/* работа с цветным буфером */
void display_plotfrom(uint_fast16_t x, uint_fast16_t y);	// Координаты в пикселях
void display_plotstart(uint_fast16_t dy);	// Высота окна источника в пикселях
void display_plot(const PACKEDCOLORMAIN_T * buffer, uint_fast16_t dx, uint_fast16_t dy, uint_fast16_t xpix, uint_fast16_t ypix);	// Размеры окна в пикселях и начальная точка рисования
void display_plotstop(void);
#endif

// самый маленький шрифт
uint_fast16_t display_wrdata2_begin(uint_fast8_t xcell, uint_fast8_t ycell, uint_fast16_t * yp);
void display_wrdata2_end(void);
uint_fast16_t display_put_char_small2(uint_fast16_t xpix, uint_fast16_t ypix, uint_fast8_t c, uint_fast8_t lowhalf);
// полоса индикатора
uint_fast16_t display_wrdatabar_begin(uint_fast8_t xcell, uint_fast8_t ycell, uint_fast16_t * yp);
uint_fast16_t display_barcolumn(uint_fast16_t xpix, uint_fast16_t ypix, uint_fast8_t pattern);	// Выдать восемь цветных пикселей, младший бит - самый верхний в растре
void display_wrdatabar_end(void);
// большие и средние цифры (частота)
uint_fast16_t display_wrdatabig_begin(uint_fast8_t xcell, uint_fast8_t ycell, uint_fast16_t * yp);
uint_fast16_t display_put_char_big(uint_fast16_t xpix, uint_fast16_t ypix, uint_fast8_t c, uint_fast8_t lowhalf);
uint_fast16_t display_put_char_half(uint_fast16_t xpix, uint_fast16_t ypix, uint_fast8_t c, uint_fast8_t lowhalf);
void display_wrdatabig_end(void);
// обычный шрифт
uint_fast16_t display_wrdata_begin(uint_fast8_t xcell, uint_fast8_t ycell, uint_fast16_t * yp);
uint_fast16_t display_put_char_small(uint_fast16_t xpix, uint_fast16_t ypix, uint_fast8_t c, uint_fast8_t lowhalf);
void display_wrdata_end(void);

typedef struct pipparams_tag
{
	uint16_t x, y, w, h;	// в пикселях
	//uintptr_t frame;	// default framebufer

} pipparams_t;

void display2_getpipparams(pipparams_t * p);	/* получить координаты окна с панорамой и/или водопадом. */

/* выдать на дисплей монохромный буфер с размерами dx * dy битов */
void display_showbuffer(
	const GX_t * buffer,
	unsigned dx,	// пиксели
	unsigned dy,	// пиксели
	uint_fast8_t col,	// сетка
	uint_fast8_t row	// сетка
	);
/* выдать на дисплей монохромный буфер с размерами dx * dy битов */
void s1d13781_showbuffer(
	const GX_t * buffer,
	unsigned dx,	// пиксели
	unsigned dy,	// пиксели
	uint_fast8_t x,	// сетка
	uint_fast8_t y	// сетка
	);
/* поставить точку в буфере кадра */
void display_pixelbuffer(
	GX_t * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y	// вертикальная координата пикселя (0..dy-1) сверху вниз
	);

/* поставить точку в буфере кадра */
void display_pixelbuffer_xor(
	GX_t * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y	// вертикальная координата пикселя (0..dy-1) сверху вниз
	);
void display_pixelbuffer_line(
	GX_t * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x0,	
	uint_fast16_t y0,
	uint_fast16_t x1,	
	uint_fast16_t y1
	);
void display_pixelbuffer_clear(
	GX_t * buffer,
	uint_fast16_t dx,	
	uint_fast16_t dy
	);

// начальная инициализация буфера
// Формат RGB565
// Эта функция используется только в тесте
void colpip_fill(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	COLORPIP_T color
	);

// Выдать цветной буфер на дисплей
// В случае фреймбуфеных дисплеев - формат цвета и там и там одинаковый
void colpip_to_main(
	const PACKEDCOLORPIP_T * buffer,	// источник
	uint_fast16_t dx,	// ширина буфера источника
	uint_fast16_t dy,	// высота буфера источника
	uint_fast16_t col,	// горизонтальная координата левого верхнего угла на экране (0..dx-1) слева направо
	uint_fast16_t row	// вертикальная координата левого верхнего угла на экране (0..dy-1) сверху вниз
	);

// Нарисовать линию указанным цветом
void colpip_line(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x0,	
	uint_fast16_t y0,
	uint_fast16_t x1,	
	uint_fast16_t y1,
	COLORPIP_T color
	);

// Нарисовать закрашенный или пустой прямоугольник
void colpip_rect(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// размер буфера
	uint_fast16_t dy,	// размер буфера
	uint_fast16_t x1,	// начальная координата
	uint_fast16_t y1,	// начальная координата
	uint_fast16_t x2,	// конечная координата (включена в заполняемую облсть)
	uint_fast16_t y2,	// конечная координата (включена в заполняемую облсть)
	COLORPIP_T color,
	uint_fast8_t fill
	);

// Поставить цветную точку.
void colpip_point(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	
	uint_fast16_t dy,
	uint_fast16_t col,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t row,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	COLORPIP_T color
	);

// поставить цветную точку (модификация с сохранением старого изоьражения).
void colpip_point_xor(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	
	uint_fast16_t dy,
	uint_fast16_t col,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t row,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	COLORPIP_T color
	);

/* возвращает новую позицию по x */
uint_fast16_t
colpip_string(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// размеры буфера
	uint_fast16_t dy,
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * s
	);

/* возвращает новую позицию по x */
uint_fast16_t
colmain_string(
	PACKEDCOLORMAIN_T * buffer,
	uint_fast16_t dx,	// размеры буфера
	uint_fast16_t dy,
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * s
	);
// Используется при выводе на графический индикатор,
// transparent background - не меняем цвет фона.
void
colpip_string_tbg(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,
	uint_fast16_t dy,
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * s,
	COLORPIP_T fg		// цвет вывода текста
	);
// Используется при выводе на графический индикатор,
// transparent background - не меняем цвет фона.
void
colpip_string2_tbg(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,
	uint_fast16_t dy,
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * s,
	COLORPIP_T fg		// цвет вывода текста
	);
// Используется при выводе на графический индикатор,
// transparent background - не меняем цвет фона.
void colpip_string3_tbg(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,
	uint_fast16_t dy,
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * s,
	COLORPIP_T fg		// цвет вывода текста
	);
// Используется при выводе на графический индикатор,
// Возвращает ширину строки в пикселях
uint_fast16_t strwidth3(
	const char * s
	);
// Возвращает ширину строки в пикселях
uint_fast16_t strwidth2(
	const char * s
	);
// Возвращает ширину строки в пикселях
uint_fast16_t strwidth(
	const char * s
	);
// Возвращает высоту строки в пикселях
uint_fast16_t strheight(
	const char * s
	);

/* копирование содержимого окна с перекрытием для водопада */
void
display_scroll_down(
	uint_fast16_t x0,	// левый верхний угол окна
	uint_fast16_t y0,	// левый верхний угол окна
	uint_fast16_t w, 	// до 65535 пикселей - ширина окна
	uint_fast16_t h, 	// до 65535 пикселей - высота окна
	uint_fast16_t n,	// количество строк прокрутки
	int_fast16_t hshift	// количество пиксеелей для сдвига влево (отрицательное число) или вправо (положительное).
	);

/* копирование содержимого окна с перекрытием для водопада */
void
display_scroll_up(
	uint_fast16_t x0,	// левый верхний угол окна
	uint_fast16_t y0,	// левый верхний угол окна
	uint_fast16_t w, 	// до 65535 пикселей - ширина окна
	uint_fast16_t h, 	// до 65535 пикселей - высота окна
	uint_fast16_t n,	// количество строк прокрутки
	int_fast16_t hshift	// количество пиксеелей для сдвига влево (отрицательное число) или вправо (положительное).
	);

void
display_panel(
	uint_fast8_t x, // левый верхний угод
	uint_fast8_t y,
	uint_fast8_t w, // ширина и высота в знакоместах
	uint_fast8_t h
	);

void
display2_menu_value(
	uint_fast8_t x,
	uint_fast8_t y,
	int_fast32_t value,
	uint_fast8_t width,	// full width (if >= 128 - display with sign)
	uint_fast8_t comma,		// comma position (from right, inside width)
	uint_fast8_t rj,		// right truncated
	uint_fast8_t lowhalf
	);

// Вызовы этой функции (или группу вызовов) требуется "обрамить" парой вызовов
// display_wrdatabar_begin() и display_wrdatabar_end().
void display_bar(
	uint_fast16_t xpix,
	uint_fast16_t ypix,
	uint_fast8_t width,	/* количество знакомест, занимаемых индикатором */
	uint_fast8_t value,		/* значение, которое надо отобразить */
	uint_fast8_t tracevalue,		/* значение маркера, которое надо отобразить */
	uint_fast8_t topvalue,	/* значение, соответствующее полностью заполненному индикатору */
	uint_fast8_t pattern,	/* DISPLAY_BAR_HALF или DISPLAY_BAR_FULL */
	uint_fast8_t patternmax,	/* DISPLAY_BAR_HALF или DISPLAY_BAR_FULL - для отображения запомненного значения */
	uint_fast8_t emptyp			/* паттерн для заполнения между штрихами */
	);

void display_at(uint_fast8_t x, uint_fast8_t y, const char * s);		// Выдача строки из ОЗУ в указанное место экрана.
void display_at_P(uint_fast8_t x, uint_fast8_t y, const FLASHMEM char * s); // Выдача строки из ПЗУ в указанное место экрана.


#define BGCOLOR (display_getbgcolor())

void display_2states_P(
	uint_fast8_t x, 
	uint_fast8_t y, 
	uint_fast8_t state,
	const FLASHMEM char * state1,	// активное
	const FLASHMEM char * state0
	);

void display_2states(
	uint_fast8_t x, 
	uint_fast8_t y, 
	uint_fast8_t state,
	const char * state1,	// активное
	const char * state0
	);
// параметры, не меняющие состояния цветом
void display_1state_P(
	uint_fast8_t x, 
	uint_fast8_t y, 
	const FLASHMEM char * label
	);
// параметры, не меняющие состояния цветом
void display_1state(
	uint_fast8_t x, 
	uint_fast8_t y, 
	const char * label
	);

#define SWRMIN 10	// минимум - соответствует SWR = 1.0, точность = 0.1

/* заполнение прямоугольника на основном экране произвольным цветом
*/
void
display_fillrect(
	uint_fast16_t x, uint_fast16_t y, 	// координаты в пикселях
	uint_fast16_t w, uint_fast16_t h, 	// размеры в пикселях
	COLORMAIN_T color
	);

/* заполнение прямоугольника в буфере произвольным цветом
*/
void
colmain_fillrect(
	PACKEDCOLORMAIN_T * buffer,
	uint_fast16_t dx,
	uint_fast16_t dy,
	uint_fast16_t x, uint_fast16_t y, 	// координаты в пикселях
	uint_fast16_t w, uint_fast16_t h, 	// размеры в пикселях
	COLORMAIN_T color
	);

// скоприовать прямоугольник с типом пикселей соответствующим основному экрану
void colmain_plot(
	PACKEDCOLORMAIN_T * tbuffer,	// получатель
	uint_fast16_t tdx,	// получатель
	uint_fast16_t tdy,	// получатель
	uint_fast16_t x,	// получатель
	uint_fast16_t y,	// получатель
	const PACKEDCOLORMAIN_T * buffer, 	// источник
	uint_fast16_t dx,	// источник Размеры окна в пикселях
	uint_fast16_t dy	// источник
	);

// скоприовать прямоугольник с типом пикселей соответствующим pip
void colpip_plot(
	PACKEDCOLORPIP_T * tbuffer,	// получатель
	uint_fast16_t tdx,	// получатель
	uint_fast16_t tdy,	// получатель
	uint_fast16_t x,	// получатель
	uint_fast16_t y,	// получатель
	const PACKEDCOLORPIP_T * buffer, 	// источник
	uint_fast16_t dx,	// источник Размеры окна в пикселях
	uint_fast16_t dy	// источник
	);

void
colmain_string3_at_xy(
	PACKEDCOLORMAIN_T * buffer,
	const uint_fast16_t dx,
	const uint_fast16_t dy,
	uint_fast16_t x,
	uint_fast16_t y,
	const char * s
	);


/* Нарисовать прямоугольник со скругленными углами */
void
colmain_rounded_rect(
		PACKEDCOLORMAIN_T * buffer,
		uint_fast16_t bx,	// ширина буфера
		uint_fast16_t by,	// высота буфера
		uint_fast16_t x1,
		uint_fast16_t y1,
		uint_fast16_t x2,
		uint_fast16_t y2,
		uint_fast8_t r,		// радиус закругления углов
		COLORMAIN_T color,
		uint_fast8_t fill
		);

void
polar_to_dek(
		uint_fast16_t xc,
		uint_fast16_t yc,
		uint_fast16_t gs,
		uint_fast16_t r,
		uint_fast16_t * x,
		uint_fast16_t * y,
		uint_fast8_t style);

void
display_radius_buf(
		PACKEDCOLORMAIN_T * buffer,
		uint_fast16_t bx,	// ширина буфера
		uint_fast16_t by,	// высота буфера
		int xc, int yc,
		unsigned gs,
		unsigned r1, unsigned r2,
		COLORMAIN_T color,
		int antialiasing,
		int style);			// 1 - растягивание по горизонтали

void
display_segm_buf(
		PACKEDCOLORMAIN_T * buffer,
		uint_fast16_t bx,	// ширина буфера
		uint_fast16_t by,	// высота буфера
		int xc, int yc,
		unsigned gs, unsigned ge,
		unsigned r, int step,
		COLORMAIN_T color,
		int antialiasing,
		int style);			// 1 - растягивание по горизонтали;

// Нарисовать вертикальную цветную полосу
void
display_colorbuf_xor_vline(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t col,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t row0,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	uint_fast16_t h,	// высота
	COLORPIP_T color
	);

// Нарисовать вертикальную цветную полосу
// Формат RGB565
void
display_colorbuf_set_vline(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t col,	// горизонтальная координата начального пикселя (0..dx-1) слева направо
	uint_fast16_t row0,	// вертикальная координата начального пикселя (0..dy-1) сверху вниз
	uint_fast16_t h,	// высота
	COLORPIP_T color
	);

// получить адрес требуемой позиции в буфере
PACKEDCOLORMAIN_T *
colmain_mem_at_debug(
	PACKEDCOLORMAIN_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	const char * file,
	int line
	);

#define colmain_mem_at(a,b,c,d,e) (colmain_mem_at_debug((a), (b), (c), (d), (e), __FILE__, __LINE__))

void display_putpixel(
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	COLORMAIN_T color
	);

void colmain_putpixel(
	PACKEDCOLORMAIN_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// горизонтальная координата пикселя (0..dx-1) слева направо
	uint_fast16_t y,	// вертикальная координата пикселя (0..dy-1) сверху вниз
	COLORMAIN_T color
	);

void display_at_xy(uint_fast16_t x, uint_fast16_t y, const char * s);

void board_set_topdb(int_fast16_t v);	/* верхний предел FFT */
void board_set_bottomdb(int_fast16_t v);	/* нижний предел FFT */
void board_set_topdbwf(int_fast16_t v);	/* верхний предел FFT */
void board_set_bottomdbwf(int_fast16_t v);	/* нижний предел FFT */
void board_set_zoomxpow2(uint_fast8_t v);	/* уменьшение отображаемого участка спектра */
void board_set_fillspect(uint_fast8_t v); /* заливать заполнением площадь под графиком спектра */
void board_set_wflevelsep(uint_fast8_t v); /* чувствительность водопада регулируется отдельной парой параметров */
void board_set_wfshiftenable(uint_fast8_t v);	   /* разрешение или запрет сдвига водопада при изменении частоты */
void board_set_spantialiasing(uint_fast8_t v); /* разрешение или запрет антиалиасинга спектра */
void board_set_showdbm(uint_fast8_t v);	// Отображение уровня сигнала в dBm или S-memter (в зависимости от настроек)

PACKEDCOLORMAIN_T * colmain_fb_draw(void);	// буфер для построения изображения
PACKEDCOLORMAIN_T * colmain_fb_show(void);	// буфер для отображения
void colmain_fb_next(void);		// прерключиться на использование следующего фреймбуфера.

#if WITHALPHA
#define DEFAULT_ALPHA WITHALPHA
#else
#define DEFAULT_ALPHA 128	// 0..255
#endif

void display2_xltrgb24(COLOR24_T * xtable);

void hwaccel_copy(
	uintptr_t dstinvalidateaddr,
	size_t dstinvalidatesize,
	PACKEDCOLORMAIN_T * dst,
	const PACKEDCOLORMAIN_T * src,
	unsigned w,
	unsigned t,	// разница в размере строки получателя от источника
	unsigned h
	);

// для случая когда горизонтальные пиксели в видеопямяти располагаются подряд
void ltdc_horizontal_pixels(
	PACKEDCOLORMAIN_T * tgr,		// target raster
	const FLASHMEM uint8_t * raster,
	uint_fast16_t width	// number of bits (start from LSB first byte in raster)
	);

// Установить прозрачность для прямоугольника
void display_transparency(
	uint_fast16_t x1, uint_fast16_t y1,
	uint_fast16_t x2, uint_fast16_t y2,
	uint_fast8_t alpha	// на сколько затемнять цвета (0 - чёрный, 255 - без изменений)
	);

// заполнение прямоугольной области в видеобуфере
void colpip_fillrect(
	PACKEDCOLORPIP_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// начальная координата
	uint_fast16_t y,	// начальная координата
	uint_fast16_t w,	// ширниа
	uint_fast16_t h,	// высота
	COLORPIP_T color	// цвет
	);

uint_fast8_t smallfont_decode(uint_fast8_t c);
uint_fast8_t bigfont_decode(uint_fast8_t c);

int_fast32_t display_zoomedbw(void);

void display_string3_at_xy(uint_fast16_t x, uint_fast16_t y, const char * s, COLORMAIN_T fg, COLORMAIN_T bg);

void colmain_line(
		PACKEDCOLORMAIN_T * buffer,
		uint_fast16_t bx,	// ширина буфера
		uint_fast16_t by,	// высота буфера
		int xn, int yn,
		int xk, int yk,
		COLORMAIN_T color,
		int antialiasing);

// Отображение цифр в поле "больших цифр" - индикатор основной частоты настройки аппарата.
void
display_value_big(
	uint_fast8_t xcell,	// x координата начала вывода значения
	uint_fast8_t ycell,	// y координата начала вывода значения
	uint_fast32_t freq,
	uint_fast8_t width, // = 8;	// full width
	uint_fast8_t comma, // = 2;	// comma position (from right, inside width)
	uint_fast8_t comma2,	// = comma + 3;		// comma position (from right, inside width)
	uint_fast8_t rj,	// = 1;		// right truncated
	uint_fast8_t blinkpos,		// позиция, где символ заменён пробелом
	uint_fast8_t blinkstate,	// 0 - пробел, 1 - курсор
	uint_fast8_t withhalf,		// 0 - только большие цифры
	uint_fast8_t lowhalf		// lower half
	);

void
display_value_small(
	uint_fast8_t xcell,	// x координата начала вывода значения
	uint_fast8_t ycell,	// y координата начала вывода значения
	int_fast32_t freq,
	uint_fast8_t width,	// full width (if >= 128 - display with sign)
	uint_fast8_t comma,		// comma position (from right, inside width)
	uint_fast8_t comma2,
	uint_fast8_t rj,		// right truncated
	uint_fast8_t lowhalf
	);

void display_floodfill(
	PACKEDCOLORMAIN_T * buffer,
	uint_fast16_t dx,	// ширина буфера
	uint_fast16_t dy,	// высота буфера
	uint_fast16_t x,	// начальная координата
	uint_fast16_t y,	// начальная координата
	COLORMAIN_T newColor,
	COLORMAIN_T oldColor,
	uint_fast8_t type	// 0 - быстрая закраска (только выпуклый контур), 1 - более медленная закраска любого контура
	);

COLORPIP_T getshadedcolor(
	COLORPIP_T dot, // исходный цвет
	uint_fast8_t alpha	// на сколько затемнять цвета (0 - чёрный, 255 - без изменений)
	);

/* стркутура хранит цвета элементов дизайна. Возмодно треите поле - для анталиасингового формирования изображения */
typedef struct colorpair_tag
{
	COLORMAIN_T fg, bg;
} COLORPAIR_T;

typedef struct editfreq_tag
{
	uint32_t val;
	uint8_t num;
	uint8_t key;
} editfreq_t;

typedef struct editfreq2_tag
{
	uint32_t freq;
	uint8_t blinkpos;		// позиция (степень 10) редактируесого символа
	uint8_t blinkstate;	// в месте редактируемого символа отображается подчёркивание (0 - пробел)
} editfreq2_t;

typedef struct dctx_tag
{
	enum { DCTX_FREQ, DCTX_MENU } type;
	const void * pv;
} dctx_t;

void display2_smeter15(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

void
display2_smeter15_init(
	uint_fast8_t xgrid,
	uint_fast8_t ygrid,
	dctx_t * pctx
	);

// FUNC item label
void display2_fnlabel9(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
// FUNC item value
void display2_fnvalue9(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);


// Вызывается из display2.c
//Отображение многострочного меню для больших экранов (группы)
void display2_multilinemenu_block_groups(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
//Отображение многострочного меню для больших экранов (параметры)
void display2_multilinemenu_block_params(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
//Отображение многострочного меню для больших экранов (значения)
void display2_multilinemenu_block_vals(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
// Вызывается из display2.c
// группа, в которой находится редактируемый параметр
void display2_menu_group(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Вызывается из display2.c
// значение параметра
void display2_menu_valxx(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Вызывается из display2.c
// название редактируемого параметра или группы
void display2_menu_lblst(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Вызывается из display2.c
// название редактируемого параметра
// если группа - ничего не отображаем
void display2_menu_lblng(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Вызывается из display2.c
// код редактируемого параметра
void display2_menu_lblc3(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

#if defined (COLORPIP_SHADED)

	// цвета
	// 0..COLORPIP_BASE-1 - волопад
	// COLORPIP_BASE..127 - надписи и элементы дизайна
	// то же с кодом больше на 128 - затененные цвета для получения полупрозрачности
	// 0..95 - палитра водопада
	// 96..111 - норм цвета
	// 112..127 - первая степень AA
	// Заполнение палитры производится в display2_xltrgb24()

	#define COLORPIP_YELLOW      (COLORPIP_BASE + 0) // TFTRGB(0xFF, 0xFF, 0x00)
	#define COLORPIP_ORANGE      (COLORPIP_BASE + 1) // TFTRGB(0xFF, 0xA5, 0x00)
	#define COLORPIP_BLACK       (COLORPIP_BASE + 2) // TFTRGB(0x00, 0x00, 0x00)
	#define COLORPIP_WHITE       (COLORPIP_BASE + 3) // TFTRGB(0xFF, 0xFF, 0xFF)
	#define COLORPIP_GRAY        (COLORPIP_BASE + 4) // TFTRGB(0x80, 0x80, 0x80)
	#define COLORPIP_DARKGRAY    (COLORPIP_BASE + 5) // TFTRGB(0x70, 0x70, 0x70) FIXME: use right value
	#define COLORPIP_DARKGREEN   (COLORPIP_BASE + 5) // TFTRGB(0x00, 0x64, 0x00)
	#define COLORPIP_BLUE        (COLORPIP_BASE + 6) // TFTRGB(0x00, 0x00, 0xFF)
	#define COLORPIP_GREEN       (COLORPIP_BASE + 7) // TFTRGB(0x00, 0xFF, 0x00)
	#define COLORPIP_RED         (COLORPIP_BASE + 8) // TFTRGB(0xFF, 0x00, 0x00)

	#define COLORPIP_LOCKED  	 	(COLORPIP_BASE + 9) // TFTRGB(0x3C, 0x3C, 0x00)
	#define COLORPIP_GRIDCOLOR		(COLORPIP_BASE + 10) // TFTRGB565(128, 0, 0)		//COLOR_GRAY - center marker
	#define COLORPIP_GRIDCOLOR2		(COLORPIP_BASE + 11) // TFTRGB565(96, 96, 96)		//COLOR_DARKRED - other markers
	#define COLORPIP_SPECTRUMBG		(COLORPIP_BASE + 12) // TFTRGB565(0, 64, 24)			//
	#define COLORMAIN_SPECTRUMBG2	(COLORPIP_BASE + 13) // TFTRGB565(0, 24, 8)		//COLOR_xxx - полоса пропускания приемника
	#define COLORPIP_SPECTRUMFG		(COLORPIP_BASE + 14) // TFTRGB565(0, 255, 0)		//COLOR_GREEN

	#if COLORSTYLE_ATS52
		// new (for ats52).
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW
		#define DESIGNCOLOR_SPECTRUMFENCE	COLORPIP_WHITE

	#else
		// old
		//#define COLORPIP_SPECTRUMLINE	COLORPIP_GREEN
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW
		#define DESIGNCOLOR_SPECTRUMFENCE	COLORPIP_WHITE

	#endif

	#if LCDMODE_MAIN_L8
		// Цвета, используемые на основном экране
		#define COLORMAIN_BLACK COLORPIP_BLACK
		#define COLORMAIN_WHITE COLORPIP_WHITE
		#define COLORMAIN_BLUE COLORPIP_BLUE
		#define COLORMAIN_GREEN COLORPIP_GREEN
		#define COLORMAIN_RED COLORPIP_RED
		#define COLORMAIN_GRAY COLORPIP_GRAY
		#define COLORMAIN_DARKGREEN COLORPIP_DARKGREEN
		#define COLORMAIN_YELLOW COLORPIP_YELLOW
		#define COLORMAIN_DARKRED  COLORPIP_GRIDCOLOR2	// COLORPIP_DARKRED
	#endif /* LCDMODE_MAIN_L8 */

#else /* LCDMODE_PIP_L8 */

	// определение основных цветов
	///

	/* RGB 24-bits color table definition (RGB888). */
	#define COLOR_BLACK          TFTRGB(0x00, 0x00, 0x00)
	#define COLOR_WHITE          TFTRGB(0xFF, 0xFF, 0xFF)
	#define COLOR_BLUE           TFTRGB(0x00, 0x00, 0xFF)
	#define COLOR_GREEN          TFTRGB(0x00, 0xFF, 0x00)
	#define COLOR_RED            TFTRGB(0xFF, 0x00, 0x00)
	#define COLOR_NAVY           TFTRGB(0x00, 0x00, 0x80)
	#define COLOR_DARKBLUE       TFTRGB(0x00, 0x00, 0x8B)
	#define COLOR_DARKGREEN      TFTRGB(0x00, 0x64, 0x00)
	#define COLOR_DARKGREEN2     TFTRGB(0x00, 0x20, 0x00)
	#define COLOR_DARKCYAN       TFTRGB(0x00, 0x8B, 0x8B)
	#define COLOR_CYAN           TFTRGB(0x00, 0xFF, 0xFF)
	#define COLOR_TURQUOISE      TFTRGB(0x40, 0xE0, 0xD0)
	#define COLOR_INDIGO         TFTRGB(0x4B, 0x00, 0x82)
	#define COLOR_DARKRED        TFTRGB(0x80, 0x00, 0x00)
	#define COLOR_DARKRED2       TFTRGB(0x40, 0x00, 0x00)
	#define COLOR_OLIVE          TFTRGB(0x80, 0x80, 0x00)
	#define COLOR_GRAY           TFTRGB(0x80, 0x80, 0x80)
	#define COLOR_SKYBLUE        TFTRGB(0x87, 0xCE, 0xEB)
	#define COLOR_BLUEVIOLET     TFTRGB(0x8A, 0x2B, 0xE2)
	#define COLOR_LIGHTGREEN     TFTRGB(0x90, 0xEE, 0x90)
	#define COLOR_DARKVIOLET     TFTRGB(0x94, 0x00, 0xD3)
	#define COLOR_YELLOWGREEN    TFTRGB(0x9A, 0xCD, 0x32)
	#define COLOR_BROWN          TFTRGB(0xA5, 0x2A, 0x2A)
	#define COLOR_DARKGRAY       TFTRGB(0xA9, 0xA9, 0xA9)
	#define COLOR_SIENNA         TFTRGB(0xA0, 0x52, 0x2D)
	#define COLOR_LIGHTBLUE      TFTRGB(0xAD, 0xD8, 0xE6)
	#define COLOR_GREENYELLOW    TFTRGB(0xAD, 0xFF, 0x2F)
	#define COLOR_SILVER         TFTRGB(0xC0, 0xC0, 0xC0)
	#define COLOR_LIGHTGREY      TFTRGB(0xD3, 0xD3, 0xD3)
	#define COLOR_LIGHTCYAN      TFTRGB(0xE0, 0xFF, 0xFF)
	#define COLOR_VIOLET         TFTRGB(0xEE, 0x82, 0xEE)
	#define COLOR_AZUR           TFTRGB(0xF0, 0xFF, 0xFF)
	#define COLOR_BEIGE          TFTRGB(0xF5, 0xF5, 0xDC)
	#define COLOR_MAGENTA        TFTRGB(0xFF, 0x00, 0xFF)
	#define COLOR_TOMATO         TFTRGB(0xFF, 0x63, 0x47)
	#define COLOR_GOLD           TFTRGB(0xFF, 0xD7, 0x00)
	#define COLOR_ORANGE         TFTRGB(0xFF, 0xA5, 0x00)
	#define COLOR_SNOW           TFTRGB(0xFF, 0xFA, 0xFA)
	#define COLOR_YELLOW         TFTRGB(0xFF, 0xFF, 0x00)
	#define COLOR_BROWN   		 TFTRGB(0xA5, 0x2A, 0x2A)	// коричневый
	#define COLOR_PEAR    		 TFTRGB(0xD1, 0xE2, 0x31)	// грушевый

	// Заполнение палитры производится в display2_xltrgb24()

	#define COLORPIP_YELLOW      TFTRGB565(0xFF, 0xFF, 0x00)
	#define COLORPIP_ORANGE      TFTRGB565(0xFF, 0xA5, 0x00)
	#define COLORPIP_BLACK       TFTRGB565(0x00, 0x00, 0x00)
	#define COLORPIP_WHITE       TFTRGB565(0xFF, 0xFF, 0xFF)
	#define COLORPIP_GRAY        TFTRGB565(0x80, 0x80, 0x80)
	#define COLORPIP_DARKGRAY    TFTRGB565(0x70, 0x70, 0x70)
	#define COLORPIP_DARKGREEN   TFTRGB565(0x00, 0x40, 0x00)
	#define COLORPIP_BLUE        TFTRGB565(0x00, 0x00, 0xFF)
	#define COLORPIP_GREEN       TFTRGB565(0x00, 0xFF, 0x00)
	#define COLORPIP_RED         TFTRGB565(0xFF, 0x00, 0x00)
	#define COLORPIP_LOCKED  	 TFTRGB565(0x3C, 0x3C, 0x00)

	#if COLORSTYLE_ATS52
		// new (for ats52).
		#define COLORPIP_GRIDCOLOR		TFTRGB565(128, 0, 0)		//COLOR_GRAY - center marker
		#define COLORPIP_GRIDCOLOR2		TFTRGB565(96, 96, 96)		//COLOR_DARKRED - other markers
		#define COLORPIP_SPECTRUMBG		TFTRGB565(0, 64, 24)			//
		#define COLORMAIN_SPECTRUMBG2	TFTRGB565(0, 24, 8)		//COLOR_xxx - полоса пропускания приемника
		#define COLORPIP_SPECTRUMFG		TFTRGB565(0, 255, 0)		//COLOR_GREEN
		#define DESIGNCOLOR_SPECTRUMFENCE	TFTRGB565(255, 255, 255)	//COLOR_WHITE
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#else
		// old
		#define COLORPIP_GRIDCOLOR      TFTRGB565(128, 128, 0)        //COLOR_GRAY - center marker
		#define COLORPIP_GRIDCOLOR2     TFTRGB565(128, 0, 0x00)        //COLOR_DARKRED - other markers
		#define COLORPIP_SPECTRUMBG     TFTRGB565(0, 0, 0)            //COLOR_BLACK
		#define COLORMAIN_SPECTRUMBG2    TFTRGB565(0, 128, 128)        //COLOR_CYAN - полоса пропускания приемника
		#define COLORPIP_SPECTRUMFG		TFTRGB565(0, 255, 0)		//COLOR_GREEN
		#define DESIGNCOLOR_SPECTRUMFENCE	TFTRGB565(255, 255, 255)	//COLOR_WHITE
		//#define COLORPIP_SPECTRUMLINE	COLORPIP_GREEN
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#endif


	// Цвета, используемые на основном экране
	#define COLORMAIN_BLACK COLOR_BLACK
	#define COLORMAIN_WHITE COLOR_WHITE
	#define COLORMAIN_BLUE COLOR_BLUE
	#define COLORMAIN_GREEN COLOR_GREEN
	#define COLORMAIN_RED COLOR_RED
	#define COLORMAIN_GRAY COLOR_GRAY
	#define COLORMAIN_DARKGREEN COLOR_DARKGREEN
	#define COLORMAIN_YELLOW COLOR_YELLOW
	#define COLORMAIN_DARKRED  COLOR_DARKRED

#endif /* LCDMODE_PIP_L8 */

#if LCDMODE_PIP_L8
	#define COLOR_BUTTON_NON_LOCKED		COLORPIP_GREEN
	#define COLOR_BUTTON_PR_NON_LOCKED	COLORPIP_DARKGREEN	// was: COLORPIP_DARKGREEN2
	#define COLOR_BUTTON_LOCKED			COLORPIP_YELLOW
	#define COLOR_BUTTON_PR_LOCKED		COLORPIP_LOCKED // TFTRGB565(0x3C, 0x3C, 0x00)
	#define COLOR_BUTTON_DISABLED		COLORPIP_GRAY // TFTRGB565(0x50, 0x50, 0x50) FIXME: use right value

#else /* LCDMODE_PIP_L8 */
	#define COLOR_BUTTON_NON_LOCKED		COLORPIP_GREEN
	#define COLOR_BUTTON_PR_NON_LOCKED	COLORPIP_DARKGREEN
	#define COLOR_BUTTON_LOCKED			COLORPIP_YELLOW
	#define COLOR_BUTTON_PR_LOCKED		COLORPIP_LOCKED // TFTRGB565(0x3C, 0x3C, 0x00)
	#define COLOR_BUTTON_DISABLED		COLORPIP_GRAY

#endif /* LCDMODE_PIP_L8 */

// Цвета используемые для отображения
// различных элементов на основном экране.

#define LCOLOR	COLORMAIN_GREEN		// цвет левой половины S-метра
#define RCOLOR	COLORMAIN_RED			// цвет правой половины S-метра
#define PWRCOLOR	COLORMAIN_RED		// цвет измерителя мощности
#define SWRCOLOR	COLORMAIN_YELLOW		// цвет SWR-метра

#define OVFCOLOR COLORMAIN_RED
#define LOCKCOLOR COLORMAIN_RED
#define TXRXMODECOLOR COLORMAIN_BLACK
#define MODECOLORBG_TX COLORMAIN_RED
#define MODECOLORBG_RX	COLORMAIN_GREEN

#define MENUGROUPCOLOR COLORMAIN_YELLOW
#define MENUCOLOR COLORMAIN_WHITE
#define MNUVALCOLOR COLORMAIN_WHITE
#define MENUSELCOLOR	COLORMAIN_GREEN

#if COLORSTYLE_RED
	// "All-in-red": FT1000 inspired color scheme
	#define DESIGNBIGCOLOR 		COLORMAIN_RED 		// DARK RED
	#define DESIGNBIGCOLORB 	COLORMAIN_RED		// цвет частоты дополнительного приемника

	#define LABELACTIVETEXT		COLORMAIN_WHITE
	#define LABELACTIVEBACK		COLORMAIN_DARKRED
	#define LABELINACTIVETEXT	COLORMAIN_BLACK
	#define LABELINACTIVEBACK	COLORMAIN_RED
	#define LABELTEXT			COLORMAIN_RED
	#define LABELBACK			COLORMAIN_BLACK

#elif COLORSTYLE_ATS52
	#define DESIGNBIGCOLOR 		COLORMAIN_YELLOW 	// GOLD
	#define DESIGNBIGCOLORB 	COLORMAIN_YELLOW		// цвет частоты дополнительного приемника

	#define LABELACTIVETEXT		COLORMAIN_YELLOW
	#define LABELACTIVEBACK		COLORMAIN_DARKGREEN
	#define LABELINACTIVETEXT	COLORMAIN_BLACK
	#define LABELINACTIVEBACK	COLORMAIN_DARKGREEN
	#define LABELTEXT			COLORMAIN_GREEN
	#define LABELBACK			COLORMAIN_BLACK


#else /* COLORSTYLE_RED */
	#define DESIGNBIGCOLOR 		COLORMAIN_YELLOW 	// GOLD
	#define DESIGNBIGCOLORB 	COLORMAIN_SPECTRUMBG2		// цвет частоты дополнительного приемника

	#define LABELACTIVETEXT		COLORMAIN_WHITE
	#define LABELACTIVEBACK		COLORMAIN_DARKGREEN
	#define LABELINACTIVETEXT	COLORMAIN_BLACK
	#define LABELINACTIVEBACK	COLORMAIN_GREEN
	#define LABELTEXT			COLORMAIN_GREEN
	#define LABELBACK			COLORMAIN_BLACK

#endif /* COLORSTYLE_RED */

uint_fast8_t display_getpagesmax(void);	// количество разных вариантов отображения (menuset)
uint_fast8_t display_getpagesleep(void);	// номер варианта отображения для "сна"
uint_fast8_t display_getfreqformat(uint_fast8_t * prjv);	// получить параметры отображения частоты (для функции прямого ввода)

void display2_bgprocess(void);	// выполнение шагов state machine отображения дисплея
void display2_bgreset(void);	// сброс state machine отображения дисплея

void display2_dispfreq_a2(
	uint_fast32_t freq,
	uint_fast8_t blinkpos,		// позиция (степень 10) редактируесого символа
	uint_fast8_t blinkstate,	// в месте редактируемого символа отображается подчёркивание (0 - пробел)
	uint_fast8_t menuset	/* индекс режима отображения (0..3) */
	);

void display2_dispfreq_ab(
	uint_fast8_t menuset	/* индекс режима отображения (0..3) */
	);
void display2_volts(
	uint_fast8_t menuset,	/* индекс режима отображения (0..3) */
	uint_fast8_t extra		/* находимся в режиме отображения настроек */
	);

// Статическая часть отображения режима работы
void display2_mode_subset(
	uint_fast8_t menuset	/* индекс режима отображения (0..3) */
	);

// S-meter, SWR-meter, voltmeter
void display2_barmeters_subset(
	uint_fast8_t menuset,	/* индекс режима отображения (0..3) */
	uint_fast8_t extra		/* находимся в режиме отображения настроек */
	);

struct menudef;


// Обновление изоражения экрана при нахождении в режиме меню
void display2_menu(
	const FLASHMEM struct menudef * mp,
	uint_fast8_t byname			/* был выполнен прямой вход в меню */
	);

// Вызывается из display2.c
void
display2_bars(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
// Вызывается из display2.c
void
display2_bars_rx(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
// Вызывается из display2.c
void
display2_bars_tx(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);
// Вызывается из display2.c
void
display2_adctest(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Вызывается из display2.c (версия для CTLSTYLE_RA4YBO_AM0)
void
display2_bars_amv0(
	uint_fast8_t x,
	uint_fast8_t y,
	dctx_t * pctx
	);

// Параметры отображения многострочного меню для больших экранов
typedef struct multimenuwnd_tag
{
	uint8_t multilinemenu_max_rows;
	uint8_t menurow_count;
	uint8_t ystep;
	uint8_t reverse;	// 0/1
	uint8_t valuew;	/* количество текстовых символов занимаемых полем вывола значения в меню. */
} multimenuwnd_t;

#define LABELW 8

void display2_getmultimenu(multimenuwnd_t * p); /* получение параметров окна для меню */

void display_smeter(
	uint_fast8_t x,
	uint_fast8_t y,
	uint_fast8_t value,
	uint_fast8_t tracemax,
	uint_fast8_t level9,	// s9 level
	uint_fast8_t delta1,	// s9 - s0 delta
	uint_fast8_t delta2		// s9+50 - s9 delta
	);

void display_smeter_amv0(
	uint_fast8_t x,
	uint_fast8_t y,
	uint_fast8_t value,
	uint_fast8_t tracemax,
	uint_fast8_t level9,	// s9 level
	uint_fast8_t delta1,	// s9 - s0 delta
	uint_fast8_t delta2		// s9+50 - s9 delta
	);

// Вызывается из display2_bars_amv0 (версия для CTLSTYLE_RA4YBO_AM0)
void display_modulationmeter_amv0(
	uint_fast8_t x,
	uint_fast8_t y,
	uint_fast8_t value,
	uint_fast8_t maxvalue
	);

void display_pwrmeter(
	uint_fast8_t x,
	uint_fast8_t y,
	uint_fast8_t pwr,
	uint_fast8_t tracemax,
	uint_fast8_t maxpwrcali		// значение для отклонения на всю шкалу
	);

void display_pwrmeter_amvo(
	uint_fast8_t x,
	uint_fast8_t y,
	uint_fast8_t pwr,
	uint_fast8_t tracemax,
	uint_fast8_t maxpwrcali		// значение для отклонения на всю шкалу
	);

#define WSIGNFLAG 0x80	// отображается плюс или минус в зависимости от знака значения
#define WMINUSFLAG 0x40	// отображается пробел или минус в зависимости от знака значения
#define WWIDTHFLAG 0x3F	// оставшиеся биты под ширину поля

uint_fast8_t display2_getswrmax(void);

uint_fast16_t normalize(
	uint_fast16_t raw,
	uint_fast16_t rawmin,
	uint_fast16_t rawmax,
	uint_fast16_t range
	);

uint_fast16_t get_swr(uint_fast16_t swr_fullscale);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DISPLAY_H_INCLUDED */