#pragma once

typedef struct
{
	char Empty[0x2C];
	void* FontSet;
	void* Kanji;
	float UnkWidth; // 0x34
	float UnkHeight; // 0x38
	char Empty2[0x20]; // 0x3C
	unsigned int Color; // 0x5C
	int field_0x60;
	int IsAligned;
	int field_0x68;
	int RegionX1;
	int RegionY1;
	int RegionX2;
	int RegionY2;
	int AlignMode;
} FontManagerClass;