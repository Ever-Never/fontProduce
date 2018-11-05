#include "font.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_FONT_SIZE					64
#define	MODE_DEBUG						0
 

extern void display_char(int nYSize, int nBytesPerLine, unsigned char *pFontData);
extern void display(int nYSize, int width, int nBytesPerLine, unsigned char *pFontData);

void HowToUser()
{	
	printf("*********************************************************************\n");
	printf("Example:\n");
	printf("\tReadfontInfo.exe D:\\test\\a\\aa\\arialuni_U16.bin 33\n\n");

	printf("QQ:	9599598\n");
	printf("Msn:	wujianguo19@hotmail.com\n");
	printf("*********************************************************************/\n\n");
}

void main(int argc, char *argv[])
{
    int i = 0;
    FILE *fp = NULL;
    char *text = "#include \"font_data.h\"\n"
"\n"
"//****************** header info ***********************\n"
"GUI_FONT_HEADER fontHeader = {\n"
    "'U', 'F', 'L', 0x11,     // magic\n"
   " 1,         // section number\n"
    "16,         // ySize (Height)\n"
    "0x4082,         // flag of codepage\n"
    "6894,         // total chars\n"
    "0,         // scan mode \n"
"};\n"
"\n"
"//****************** sections ***********************\n"
"GUI_FONT_SECTION fonts_sections[1] = {\n"
 "       0x0020, 0xffe3, 0x0,\n"
"};";

	if(argc != 3)
	{
		HowToUser();
	}
	else
	{
		char *pfontfile = argv[1];  
		WORD wCode = atoi(argv[2]); 

		if(font_init(pfontfile))
		{
			int i = 0, j = 0;
            int sum = 0;
			int nWidth = 0; 
            int offset = 0;
			WORD bytesPerLine = 0;
			BYTE buf[MAX_FONT_SIZE * (MAX_FONT_SIZE/PIXELS_PER_BYTE)];

            fp = fopen("font_data.c", "w");
            
            fprintf(fp, "%s\n", text);
            fprintf(fp, "GUI_FONT_INDEX fonts_index[65477]= {\n");
            for(wCode = 0x20; wCode < 0xffe5; wCode++)
            {
                nWidth = font_read_char_distX(wCode);
                fprintf(fp, "%d, 0x%x,\n", nWidth, offset);
                if (nWidth == 0)
                {
                    offset += 0;
                }else if( nWidth <= 8)
                    offset += 1 * 16;
                else
                    offset += 2 * 16;
                sum++;
            } 
            printf("%d\n", sum);
            fprintf(fp, "};\n");

            fprintf(fp, "unsigned char fonts_data[]= {\n");
            sum = 0;
            for(wCode = 0x20; wCode <= 0xffe5; wCode++)
            {
                nWidth = font_read_char_distX(wCode);
                if(font_read_char_dot_array(wCode, buf, &bytesPerLine))
                {
                    for(i = 0; i < bytesPerLine * 16; i++)
                    {
                        fprintf(fp ,"0x%x, ", buf[i]);
                        if((i + 1) % 16 == 0)
                        {
                            fprintf(fp, "\n");
                        }
                        sum++;
                    }
                    //printf("--------------------\n");
                    //display_char(font_get_ysize(), bytesPerLine, buf);
                    //display(font_get_ysize(), nWidth, bytesPerLine, buf);
                }
            }
            printf("%d\n", sum);
            fprintf(fp, "};\n");
            fclose(fp);
			font_exit();
		}	
	}
}
