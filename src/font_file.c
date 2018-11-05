﻿#include "font_file.h"


#include "stdio.h"
FILE *g_prf = NULL;

int font_file_open(const char* file)
{
	if((g_prf = fopen(file, "rb")) !=NULL)
		return 1;	
	return 0;
}

int font_file_seek(long offset)
{
	if(g_prf != NULL)
		return fseek(g_prf, offset, SEEK_SET);

	return -1;
}

int font_file_read(void *pdata, long size)
{
	if(g_prf != NULL)
		return fread(pdata, size, 1, g_prf);

	return 0;
}

void font_file_close()
{
	if(g_prf != NULL)
		fclose(g_prf);
}
