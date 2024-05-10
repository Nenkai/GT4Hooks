#pragma once

#include "../GameStructs/PolyphonyGL.h"

#define ADDR_pglAccum 0x005A0410
#define ADDR_pglAccumBuffer 0x0059EC40
#define ADDR_pglAllocatePacket 0x005A26E0
#define ADDR_pglAlphaFail 0x0059EFF8
#define ADDR_pglAlphaFunc1ub 0x0059F0E8
#define ADDR_pglAppendGIFPacket 0x005A2700
#define ADDR_pglAppendImagePacket 0x005A8638
#define ADDR_pglApplyDepthBias_Guessed 0x0059EDC0
#define ADDR_pglApplyMatrix 0x005A45B0
#define ADDR_pglBeginStrip 0x00598AC8
#define ADDR_pglBlendFunc 0x0059F038
#define ADDR_pglBlendFunc1ub 0x0059F138
#define ADDR_pglClear 0x0059FBC0
#define ADDR_pglClearColor 0x0059F870
#define ADDR_pglClearColor1ui 0x0059F8A8
#define ADDR_pglClearDepth 0x0059F8B8
#define ADDR_pglClutBuffer 0x005A15B8
#define ADDR_pglClutLoad 0x005A13A8
#define ADDR_pglClutOffset 0x005A16D0
#define ADDR_pglColor 0x005A6B20
#define ADDR_pglColor4f 0x005A6B90
#define ADDR_pglColor4ftoi 0x005A6A88
#define ADDR_pglColorBuffer 0x0059ECA8
#define ADDR_pglColorMask1ui 0x0059F1B0
#define ADDR_pglCounterMatrix 0x005A4620
#define ADDR_pglCullFace 0x0059E1D0
#define ADDR_pglCylinderMapAxis 0x0059BFD8
#define ADDR_pglCylinderMapHint 0x0059BFA0
#define ADDR_pglCylinderMapT 0x0059BE40
#define ADDR_pglDMABuffer 0x0059E220
#define ADDR_pglDepthBias 0x0059F850
#define ADDR_pglDepthBuffer 0x0059EE20
#define ADDR_pglDepthFunc 0x0059EF20
#define ADDR_pglDepthMask 0x0059F1D8
#define ADDR_pglDestinationAlphaFunc 0x0059F088
#define ADDR_pglDisable 0x005A79F8
#define ADDR_pglDisplayMask 0x0059D130
#define ADDR_pglDisplayMode 0x0059D028
#define ADDR_pglDisplayResolution 0x0059D3D0
#define ADDR_pglDisplayViewport 0x0059D398
#define ADDR_pglDitherMatrix 0x0059DBE8
#define ADDR_pglEnable 0x0059DE58
#define ADDR_pglEndFrameMaybe 0x0059E4C8
#define ADDR_pglEndStrip 0x00598B08
#define ADDR_pglExecute 0x0059DA18
#define ADDR_pglExit 0x0059CF58
#define ADDR_pglFinish 0x0059E8F8
#define ADDR_pglFlush 0x0059C648
#define ADDR_pglFlushCache 0x005A6E58
#define ADDR_pglFog 0x005A0B28
#define ADDR_pglFogColor 0x005A0A10
#define ADDR_pglFogColor1ui 0x005A0AC8
#define ADDR_pglFree 0x005A7070
#define ADDR_pglFrontFace 0x0059E1F8
#define ADDR_pglGetColor1ui 0x005A4730
#define ADDR_pglGetColorBuffer 0x005A47A8
#define ADDR_pglGetCullFace 0x005A47D8
#define ADDR_pglGetField 0x005A4768
#define ADDR_pglGetFogColor1ui 0x005A4708
#define ADDR_pglGetViewport 0x005A47E8
#define ADDR_pglGetWorkPage 0x005A79E8
#define ADDR_pglInit 0x0059CBB8
#define ADDR_pglInverse_0 0x005A455C
#define ADDR_pglIsInFrame 0x0059D018
#define ADDR_pglLightModelfv 0x005A2830
#define ADDR_pglLightfv 0x005A2768
#define ADDR_pglLoadIdentity 0x005A3F5C
#define ADDR_pglLoadIdentityTranslate 0x005A3FA8
#define ADDR_pglLoadMatrix 0x005A3FBC
#define ADDR_pglLock 0x0059CEB0
#define ADDR_pglMatrixMode 0x005A1ED8
#define ADDR_pglMultMatrix 0x005A41A0
#define ADDR_pglMultMatrixLeft 0x005A427C
#define ADDR_pglNewFrame 0x0059E3E0
#define ADDR_pglObjectScale 0x005A4408
#define ADDR_pglOrtho 0x005A2600
#define ADDR_pglPixelCenter 0x0059F340
#define ADDR_pglPixelDomain 0x0059F388
#define ADDR_pglPoolMode 0x0059E2D0
#define ADDR_pglPopAttrib 0x005A21F8
#define ADDR_pglPopMatrix 0x005A1E08
#define ADDR_pglPushAttrib 0x005A1F88
#define ADDR_pglPushMatrix 0x005A1DB0
#define ADDR_pglResetCache 0x005A6E30
#define ADDR_pglRotate 0x005A40E0
#define ADDR_pglRotateX 0x005A4490
#define ADDR_pglRotateY 0x005A44B8
#define ADDR_pglRotateZ 0x005A44E0
#define ADDR_pglSaveSkinningMatrix 0x005A4668
#define ADDR_pglScale 0x005A4398
#define ADDR_pglScanMask 0x005A2B50
#define ADDR_pglScissor 0x0059F698
#define ADDR_pglSetTexCoords 0x0059C230
#define ADDR_pglSignalSema 0x0059D758
#define ADDR_pglStoreMatrix 0x005A4058
#define ADDR_pglStrip 0x00598FF0
#define ADDR_pglSyncDMA 0x0059EC20
#define ADDR_pglSyncV 0x0059EAF0
#define ADDR_pglTaggedAllocate 0x005A6F28
#define ADDR_pglTexFlush 0x005A1388
#define ADDR_pglTexGenf 0x0059BBC0
#define ADDR_pglTexImage 0x00597BC0
#define ADDR_pglTexParameter 0x00597EF8
#define ADDR_pglTexRegion 0x00598070
#define ADDR_pglTranslate 0x005A434C
#define ADDR_pglTriangleStrip 0x0059C2D8
#define ADDR_pglTriangleStrip_0 0x0059C5C0
#define ADDR_pglUnkEnableSomething 0x00598370
#define ADDR_pglUnlock 0x0059CF10
#define ADDR_pglVariableColorOffset 0x005A2C70
#define ADDR_pglVariableColorScale 0x005A2C50
#define ADDR_pglViewport 0x0059F550
#define ADDR_pglWaitSema 0x0059D728
#define ADDR_pglWcLine2i 0x005A35F8
#define ADDR_pglWcRect2i 0x005A2CB0
#define ADDR_pglWcSliceRect2i 0x005A2DF0
#define ADDR_pglWcSliceSprite2f 0x005A3280
#define ADDR_pglWcSprite2f 0x005A3078
#define ADDR_pglWritePixelsImm 0x005A1B28
#define ADDR_pglWritePixelsPath1 0x005A1848
#define ADDR_pglWritePixelsPath3 0x005A19B0
#define ADDR_pgl_SetGSControlRegister 0x005AA5E8
#define ADDR_pglmRandomSeed 0x005AA30C
#define ADDR_pgluApplyClutAnimation 0x00595E30
#define ADDR_pgluApplyClutPatch 0x00595BB8
#define ADDR_pgluApplyMaterial_GUESSED 0x0059ABD0
#define ADDR_pgluCacheGetSize 0x005A7008
#define ADDR_pgluCacheTexSetPath3 0x00596640
#define ADDR_pgluCallShape 0x0059A580
#define ADDR_pgluCallTstrip 0x00593E30
#define ADDR_pgluComputeTexSize 0x00598148
#define ADDR_pgluCopyPixelsToAlpha 0x005A5DC0
#define ADDR_pgluCustomizeShimmer 0x005923E0
#define ADDR_pgluDepthOffset 0x00597A80
#define ADDR_pgluExternalMatIndex 0x00599D28
#define ADDR_pgluExternalTexIndex 0x00599D70
#define ADDR_pgluField 0x0059F240
#define ADDR_pgluFontFacePDI 0x0033CDB8
#define ADDR_pgluGammaCorrection 0x005A4898
#define ADDR_pgluInitShimmer 0x00592320
#define ADDR_pgluJitter 0x0059F488
#define ADDR_pgluLoadIdentityClut 0x005A5C70
#define ADDR_pgluMapShape 0x005959F8
#define ADDR_pgluMapTexSet 0x00595A40
#define ADDR_pgluMatTable 0x00599D58
#define ADDR_pgluMaterialFunc 0x00599DB8
#define ADDR_pgluRandomFloat_Guessed 0x00591EB0
#define ADDR_pgluRandomize 0x00591EA0
#define ADDR_pgluReflection 0x005979A8
#define ADDR_pgluRelocateTexSet 0x00595740
#define ADDR_pgluResetClutAnimation_0 0x00596288
#define ADDR_pgluSetVertColors 0x0059C1D8
#define ADDR_pgluSetupFontFacePDI 0x005967C0
#define ADDR_pgluSetupKanjiImagePDI 0x00596A78
#define ADDR_pgluShapeCallback 0x00599B50
#define ADDR_pgluShapeTweenRatio 0x005A4648
#define ADDR_pgluShimmer 0x005924D0
#define ADDR_pgluShimmerMove 0x00592470
#define ADDR_pgluSignalClutAnimation 0x00596210
#define ADDR_pgluTexImage 0x005A0B78
#define ADDR_pgluTexIsCachedMaybe 0x005A7140
#define ADDR_pgluTexParameter 0x005A0FC8
#define ADDR_pgluTexRegion_SetClampSettings 0x005A1288
#define ADDR_pgluTexReset 0x00597B98
#define ADDR_pgluTexSize 0x00597E28
#define ADDR_pgluTexSize_setTW_TH 0x005A0E90
#define ADDR_pgluTexTable 0x00599DA0
#define ADDR_pgluTexture 0x00599B60
#define ADDR_pgluTriangleList2fv 0x005995E0
#define ADDR_pgluTriangleStrip2fv 0x00599A80
#define ADDR_pgluTriangleStrip3fv 0x0059C570
#define ADDR_pgluUpdateClutAnimation 0x00595EA0
#define ADDR_pgluWeirdTextureThingWithSizes 0x005A1720
#define ADDR_pgluWriteKanjiImagePDI 0x00596B60

extern void (*pglPopMatrix)();
extern void (*pglLoadIdentity)();
extern void (*pglEnable)(pglFlags);
extern void (*pglDisable)(pglFlags);
extern void (*pglAccum)(int, float);
extern void (*pglAccumBuffer)(unsigned int, char, int, int);
extern void (*pglAllocatePacket)(unsigned int);
extern void (*pglAlphaFail)(unsigned int);
extern void (*pglAlphaFunc1ub)(char val, unsigned char val2);
extern void (*pgluTriangleStrip3fv)(int, MathVector3*, MathVector3*, MathVector3*, int*);
extern void (*pglColor)(unsigned int);
extern void (*pglWcRect2i)(int, int, int, int);
extern void (*pglColor4f)(float, float, float, float);
extern void (*pglColor4ftoi)(float, float, float, float);
extern void (*pglGetViewport)(float*, float*, float*, float*);
extern void (*pglScale)(float, float, float);
extern void (*pglAppendGIFPacket)(unsigned long long);
extern void (*pglAppendImagePacket)(unsigned long long);
extern void (*pglApplyMatrix)(float*, float*);
extern void (*pglBeginStrip)();
extern void (*pglBlendFunc1ub)();
extern void (*pglClear)();
extern void (*pglClearColor)(float, float, float, float);
extern void (*pglClearColor1ui)(unsigned int);
extern void (*pglClearDepth)(float);
extern void (*pglClutBuffer)(int, unsigned long long);
extern void (*pglClutLoad)(int);
extern void (*pglClutOffset)(char);
extern void (*pglColorBuffer)(unsigned int tbp, char tbw, int a3, int a4);
extern void (*pglColorMask1ui)(unsigned int color);
extern void (*pglCounterMatrix)(float* matrix);
extern void (*pglCullFace)(int mode);
extern void (*pglCylinderMapAxis)(float, float, float, float, float, float);
extern void (*pglCylinderMapHint)(float, float, float);
extern void (*pglCylinderMapT)(float, float);
extern void (*pglDMABuffer)(int, int);
extern void (*pglDepthBias)(float);
extern void (*pglDepthBuffer)(unsigned int a1, unsigned int a2);
extern void (*pglDepthMask)(char a1);
extern void (*pglDestinationAlphaFunc)(int gsTestValue);
extern void (*pglDisplayMask)(char enableDisplayMask);
extern void (*pglDisplayMode)(int a1, int outputMode, int a3);
extern void (*pglDisplayResolution)(short width, short height);
extern void (*pglDisplayViewport)(short x, short y, short width, short height);
extern void (*pglDitherMatrix)(int*);
extern void (*pglEndStrip)();
extern void (*pglExit)();
extern void (*pglFinish)();
extern void (*pglFlush)();
extern void (*pglFlushCache)();
extern void (*pglFog)(float, float);
extern void (*pglFogColor)(float r, float g, float b);
extern void (*pglFogColor1ui)(int fogcol, unsigned int color);
extern void (*pglFrontFace)(int a1);
extern void (*pglFree)(int a1);
extern int (*pglGetColor1ui)();
extern void (*pglGetColorBuffer)(int*, int*, int*, int*);
extern int (*pglGetCullFace)();
extern int (*pglGetField)(int);
extern unsigned int (*pglGetFogColor1ui)(int);
extern int (*pglGetWorkPage)();
extern void (*pglInit)();
extern void (*pglInverse_0)(float* matrix);
extern char (*pglIsInFrame)();
extern void (*pglLightModelfv)(int sides, float*);
extern void (*pglLightfv)(int unkMode, int a2, int a3);
extern void (*pglLoadIdentity)();
extern void (*pglLoadIdentityTranslate)(float* matrix);
extern void (*pglLoadMatrix)();
extern void (*pglLock)();
extern void (*pglMatrixMode)(int mode);
extern void (*pglMultMatrix)(float* matrix);
extern void (*pglMultMatrixLeft)(float* matrix);
extern void (*pglNewFrame)();
extern void (*pglObjectScale)(float a1, float a2, float a3);
extern void (*pglOrtho)(float, float, float, float, float, float);
extern void (*pglPixelCenter)(float a1, float a2);
extern void (*pglPixelDomain)(float a1, float a2, float a3);
extern void (*pglPoolMode)(int mode);
extern void (*pglPopAttrib)();
extern void (*pglPopMatrix)();
extern void (*pglPushAttrib)(int attrib);
extern void (*pglPushMatrix)();
extern void (*pglResetCache)();
extern void (*pglRotate)(float x, float y, float z, float w);
extern void (*pglRotateX)(float x);
extern void (*pglRotateY)(float y);
extern void (*pglRotateZ)(float z);
extern void (*pglSaveSkinningMatrix)(int a1, int a2);
extern void (*pglScale)(float x, float y, float z);
extern void (*pglScanMask)(int scanMskOp);
extern void (*pglScissor)(int x, int y, int w, int h);
extern void (*pglSetTexCoords)(int a1, int texCoords, int count);
extern void (*pglSignalSema)(int dmaChannel);
extern void (*pglStoreMatrix)(float* matrix);
extern void (*pglStrip)(int num, float* vertices, float* texcoords, float* normals, int* a5, int* a6);
extern void (*pglSyncDMA)();
extern void (*pglSyncV)(int a1);
extern void (*pglTaggedAllocate)(int a1, int a2);
extern void (*pglTexFlush)();
extern void (*pglTexGenf)(int unkMode, float value);
extern void (*pglTexImage)(void* pgluTex, int mipmapLevel, unsigned int actualOffset, char a4, int tbwActual);
extern void (*pglTexParameter)(void* pgluTex, pgluParamType paramType, short value);
extern void (*pglTexRegion)(void* pgluTex, int a2, short x, short y);
extern void (*pglTranslate)(float x, float y, float z);
extern void (*pglTriangleStrip)(void* dmaThing, float* vertices, float* unused, unsigned int* colors,
    float* texcoordUV, int numVertex, char useTrifanInsteadOfStrip);
extern void (*pglTriangleStrip_0)(float* vertices, float* unused, unsigned int* colors, float* texcoordUV, int numVertex);
extern void (*pglUnkEnableSomething)();
extern void (*pglUnlock)();
extern void (*pglVariableColorOffset)(float r, float g, float b, float a);
extern void (*pglVariableColorScale)(float r, float g, float b, float a);
extern void (*pglViewport)(float x, float y, float w, float h);
extern void (*pglWaitSema)(int dmaChannel);
extern void (*pglWcLine2i)(int x1, int y1, int x2, int y2);
extern void (*pglWcRect2i)(int x, int y, int w, int h);
extern void (*pglWcSliceRect2i)(int x, int y, int w, int h);
extern void (*pglWcSliceSprite2f)(int x, int y, float a3, float a4, int a5, float a6, int a7, float a8);
extern void (*pglWcSprite2f)(float a1, float a2, float a3, int a4, float a5, int a6, float a7);
extern void (*pglWritePixelsImm)(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void (*pglWritePixelsPath1)(unsigned int a1, int a2, int a3, int a4, int a5, int width, int height, int* a8);
extern void (*pglWritePixelsPath3)(unsigned int a1, int format, int unkType, int a4, int a5, int width, int height, int* a8);
extern void (*pgl_SetGSControlRegister)(short a1, short a2, short a3, short a4);
extern void (*pglmRandomSeed)(float val);
extern void (*pgluApplyClutAnimation)(void*);
extern void (*pgluApplyClutPatch)(void* pgluTexSet, void* clutPatch);
extern int (*pgluCacheGetSize)(int texSize, void* pgluTexSet);
extern void (*pgluCacheTexSetPath3)(void* pgluTexSet);
extern void (*pgluCallShape)(void* pgluShape);
extern void (*pgluCallTstrip)(int a1, int a2, float a3, float a4, float a5, float a6);
extern int (*pgluComputeTexSize)(int format, int w, int h, int* outUnk);
extern void (*pgluCopyPixelsToAlpha)(unsigned int a1, unsigned int a2, unsigned int a3, int a4, int a5);
extern void (*pgluCustomizeShimmer)(int a1, float a2, float a3, float a4, float a5, float a6);
extern void (*pgluDepthOffset)(float value);
extern void (*pgluExternalMatIndex)(int idx);
extern void (*pgluExternalTexIndex)(int idx);
extern void (*pgluField)(int field);
extern void (*pgluFontFacePDI)(/* 11 arguments.. */);
extern void (*pgluGammaCorrection)(int a1, float a2);
extern void (*pgluInitShimmer)(unsigned int a1, int a2, int a3);
extern void (*pgluJitter)(int a1, int a2);
extern void (*pgluLoadIdentityClut)(int a1);
extern void (*pgluMapShape)(void* pgluShape);
extern void (*pgluMapTexSet)(void* pgluTexSet);
extern void (*pgluMatTable)(int tableIdx);
extern void (*pgluMaterialFunc)(int packedBits);
extern float (*pgluRandomFloat_Guessed)();
extern void (*pgluRandomize)(int value);
extern void (*pgluReflection)(float a1, float a2, float a3, float a4, float a5, float a6);
extern void (*pgluRelocateTexSet)(void* pgluTexSet, unsigned int baseFrameBufferPos);
extern void (*pgluResetClutAnimation_0)(void* a1, int a2);
extern void (*pgluSetVertColors)(void* dmaThing, unsigned int* colors, int numColors);
extern void (*pgluSetupFontFacePDI)(void*);
extern void (*pgluSetupKanjiImagePDI)(int offset, int format, int a3, int a4, int a5, int width, int height);
extern void (*pgluShapeCallback)(void* callback);
extern void (*pgluShapeTweenRatio)(float tweenRatio);
extern void (*pgluShimmer)(void* unkMatrixMaybe);
extern void (*pgluShimmerMove)(void* unk);
extern void (*pgluSignalClutAnimation)(void* unk, int a2);
extern void (*pgluTexImage)(int mipLevel, unsigned int offset, char format, int a4);
extern char (*pgluTexIsCachedMaybe)(void*);
extern void (*pgluTexParameter)(pgluParamType param, int value);
extern void (*pgluTexRegion_SetClampSettings)(int unkMode, short x, short y);
extern void (*pgluTexReset)(void* pgluTex);
extern void (*pgluTexSize)(void* pgluTex, short width, short height);
extern void (*pgluTexSize_setTW_TH)(int tw, int th);
extern void (*pgluTexTable)(void* pgluTex);
extern void (*pgluTexture)(void* pgluTex);
extern void (*pgluTriangleList2fv)(int numVerts, void* a2, void* a3, void* a4);
extern void (*pgluTriangleStrip2fv)(int numVerts, float* vertices, int* a3, int* a4);
extern void (*pgluUpdateClutAnimation)(void*, void*, float);
extern void (*pgluWriteKanjiImagePDI)(void* a1);

