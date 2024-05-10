#pragma once

typedef enum
{
	setTCC = 0x0,
	setTFX = 0x1,
	setMMIN = 0x2,
	setMMAX = 0x3,
	setWMS = 0x4,
	setWMT = 0x5,
	setLCM_LightColorMatrix = 0x6,
	setK = 0x8,
	setL = 0x9,
} pgluParamType;


typedef enum
{
	PGL_PrimTME_Textured = 0x2,
	PGL_TEST_DestinationAlphaTest = 0x3,
	PGL_TEST_AlphaTest = 0x4,
	PGL_TEST_DepthTest = 0x5,
	PGL_PrimABE_AlphaBlend = 0x6,
	PGL_7 = 0x7,
	PGL_PrimFGE_Fogging = 0x8,
	PGL_PrimAA1_Antialiasing = 0x9,
	PGL_10 = 0xA,
	PGL_11 = 0xB,
	PGL_12 = 0xC,
	PGL_13 = 0xD,
	PGL_14 = 0xE,
	PGL_CullMode = 0xF,
	PGL_16 = 0x10,
	PGL_17 = 0x11,
	PGL_Scissor = 0x12,
	PGL_19 = 0x13,
	PGL_20 = 0x14,
	PGL_21 = 0x15,
	PGL_Display1Y = 0x16,
	PGL_Display1X = 0x17,
	PGL_LightUnk1 = 0x65,
	PGL_LightUnk2 = 0x66,
	PGL_LightUnk3 = 0x67,
	PGL_LightUnk4 = 0x68,
	PGL_LightUnk5 = 0x69,
	PGL_LightUnk6 = 0x6A,
	PGL_LightUnk7 = 0x6B,
	PGL_LightUnk8 = 0x6C,
} pglFlags;

typedef struct
{
	float x;
	float y;
	float z;
} MathVector3;

typedef struct
{
	float x;
	float y;
	float z;
} MathVector2;
