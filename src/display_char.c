﻿#include <stdio.h>
#include <stdint.h>

#define		DISPLAY_FONT_MODE	1    // 1. 表示采用 '*' 和 '_' 描出字模   0. 表示显示其点阵数据

#define		MAX_GLYPH_CNT	256
#define		MAX_GLYPH_LEN	9


static char strGlyphTab[MAX_GLYPH_CNT][9] = {
"________",
"_______X",
"______X_",
"______XX",
"_____X__",
"_____X_X",
"_____XX_",
"_____XXX",
"____X___",
"____X__X",
"____X_X_",
"____X_XX",
"____XX__",
"____XX_X",
"____XXX_",
"____XXXX",
"___X____",
"___X___X",
"___X__X_",
"___X__XX",
"___X_X__",
"___X_X_X",
"___X_XX_",
"___X_XXX",
"___XX___",
"___XX__X",
"___XX_X_",
"___XX_XX",
"___XXX__",
"___XXX_X",
"___XXXX_",
"___XXXXX",
"__X_____",
"__X____X",
"__X___X_",
"__X___XX",
"__X__X__",
"__X__X_X",
"__X__XX_",
"__X__XXX",
"__X_X___",
"__X_X__X",
"__X_X_X_",
"__X_X_XX",
"__X_XX__",
"__X_XX_X",
"__X_XXX_",
"__X_XXXX",
"__XX____",
"__XX___X",
"__XX__X_",
"__XX__XX",
"__XX_X__",
"__XX_X_X",
"__XX_XX_",
"__XX_XXX",
"__XXX___",
"__XXX__X",
"__XXX_X_",
"__XXX_XX",
"__XXXX__",
"__XXXX_X",
"__XXXXX_",
"__XXXXXX",
"_X______",
"_X_____X",
"_X____X_",
"_X____XX",
"_X___X__",
"_X___X_X",
"_X___XX_",
"_X___XXX",
"_X__X___",
"_X__X__X",
"_X__X_X_",
"_X__X_XX",
"_X__XX__",
"_X__XX_X",
"_X__XXX_",
"_X__XXXX",
"_X_X____",
"_X_X___X",
"_X_X__X_",
"_X_X__XX",
"_X_X_X__",
"_X_X_X_X",
"_X_X_XX_",
"_X_X_XXX",
"_X_XX___",
"_X_XX__X",
"_X_XX_X_",
"_X_XX_XX",
"_X_XXX__",
"_X_XXX_X",
"_X_XXXX_",
"_X_XXXXX",
"_XX_____",
"_XX____X",
"_XX___X_",
"_XX___XX",
"_XX__X__",
"_XX__X_X",
"_XX__XX_",
"_XX__XXX",
"_XX_X___",
"_XX_X__X",
"_XX_X_X_",
"_XX_X_XX",
"_XX_XX__",
"_XX_XX_X",
"_XX_XXX_",
"_XX_XXXX",
"_XXX____",
"_XXX___X",
"_XXX__X_",
"_XXX__XX",
"_XXX_X__",
"_XXX_X_X",
"_XXX_XX_",
"_XXX_XXX",
"_XXXX___",
"_XXXX__X",
"_XXXX_X_",
"_XXXX_XX",
"_XXXXX__",
"_XXXXX_X",
"_XXXXXX_",
"_XXXXXXX",
"X_______",
"X______X",
"X_____X_",
"X_____XX",
"X____X__",
"X____X_X",
"X____XX_",
"X____XXX",
"X___X___",
"X___X__X",
"X___X_X_",
"X___X_XX",
"X___XX__",
"X___XX_X",
"X___XXX_",
"X___XXXX",
"X__X____",
"X__X___X",
"X__X__X_",
"X__X__XX",
"X__X_X__",
"X__X_X_X",
"X__X_XX_",
"X__X_XXX",
"X__XX___",
"X__XX__X",
"X__XX_X_",
"X__XX_XX",
"X__XXX__",
"X__XXX_X",
"X__XXXX_",
"X__XXXXX",
"X_X_____",
"X_X____X",
"X_X___X_",
"X_X___XX",
"X_X__X__",
"X_X__X_X",
"X_X__XX_",
"X_X__XXX",
"X_X_X___",
"X_X_X__X",
"X_X_X_X_",
"X_X_X_XX",
"X_X_XX__",
"X_X_XX_X",
"X_X_XXX_",
"X_X_XXXX",
"X_XX____",
"X_XX___X",
"X_XX__X_",
"X_XX__XX",
"X_XX_X__",
"X_XX_X_X",
"X_XX_XX_",
"X_XX_XXX",
"X_XXX___",
"X_XXX__X",
"X_XXX_X_",
"X_XXX_XX",
"X_XXXX__",
"X_XXXX_X",
"X_XXXXX_",
"X_XXXXXX",
"XX______",
"XX_____X",
"XX____X_",
"XX____XX",
"XX___X__",
"XX___X_X",
"XX___XX_",
"XX___XXX",
"XX__X___",
"XX__X__X",
"XX__X_X_",
"XX__X_XX",
"XX__XX__",
"XX__XX_X",
"XX__XXX_",
"XX__XXXX",
"XX_X____",
"XX_X___X",
"XX_X__X_",
"XX_X__XX",
"XX_X_X__",
"XX_X_X_X",
"XX_X_XX_",
"XX_X_XXX",
"XX_XX___",
"XX_XX__X",
"XX_XX_X_",
"XX_XX_XX",
"XX_XXX__",
"XX_XXX_X",
"XX_XXXX_",
"XX_XXXXX",
"XXX_____",
"XXX____X",
"XXX___X_",
"XXX___XX",
"XXX__X__",
"XXX__X_X",
"XXX__XX_",
"XXX__XXX",
"XXX_X___",
"XXX_X__X",
"XXX_X_X_",
"XXX_X_XX",
"XXX_XX__",
"XXX_XX_X",
"XXX_XXX_",
"XXX_XXXX",
"XXXX____",
"XXXX___X",
"XXXX__X_",
"XXXX__XX",
"XXXX_X__",
"XXXX_X_X",
"XXXX_XX_",
"XXXX_XXX",
"XXXXX___",
"XXXXX__X",
"XXXXX_X_",
"XXXXX_XX",
"XXXXXX__",
"XXXXXX_X",
"XXXXXXX_",
"XXXXXXXX"
};

/*****************************************************************
功能：根据点阵信息显示一个字模
参数：
	  nYSize--字符的高度
	  nBytesPerLine--每行占的字节数（公式为：（像素宽＋７）／８＝？）
      pFontData--字符的点阵信息。
*****************************************************************/
void display_char(int nYSize, int nBytesPerLine, unsigned char *pFontData)
{
	int i, j;
	printf("bytesPerLine = %d\n", nBytesPerLine);

	for(i = 0; i < nYSize; i++)	
	{
		for(j = 0; j < nBytesPerLine; j++)
		{
#if(DISPLAY_FONT_MODE)	
			printf(strGlyphTab[pFontData[i * nBytesPerLine + j]]);
#else  //显示点阵数据
			printf("%x, ", pFontData[i * nBytesPerLine + j]);
#endif			
		}
		printf("\n");
	}
}

void display(int nYSize, int width, int nBytesPerLine, unsigned char *pFontData)
{
	int i, j, k;
	printf("bytesPerLine = %d\n", nBytesPerLine);

	for(i = 0; i < nYSize; i++)	
	{
		for(j = 0; j < nBytesPerLine; j++)
		{
            if(width < 8)
            {
                for(k = 7; k >=8 - width; k--)
                {
                    if(pFontData[i * nBytesPerLine + j] & 1 << k)
                        printf("*");
                    else
                        printf(" ");
                }
            }else
            {
                if(j == 0)
                {
                    for(k = 7; k >=0; k--)
                    {
                        if(pFontData[i * nBytesPerLine + j] & 1 << k)
                            printf("*");
                        else
                            printf(" ");
                    }
                }
                if(j == 1)
                {
                    for(k = 7; k >=15 - width; k--)
                    {
                        if(pFontData[i * nBytesPerLine + j] & 1 << k)
                            printf("*");
                        else
                            printf(" ");
                    }
                }
            }
		}
		printf("\n");
	}

}
