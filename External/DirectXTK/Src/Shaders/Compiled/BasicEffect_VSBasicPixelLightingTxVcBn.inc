#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float   xyz 
// TEXCOORD                 0   xy          2     NONE   float   xy  
// COLOR                    0   xyzw        3     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
// TEXCOORD                 1   xyzw        1     NONE   float   xyzw
// TEXCOORD                 2   xyz         2     NONE   float   xyz 
// COLOR                    0   xyzw        3     NONE   float   xyzw
// SV_Position              0   xyzw        4      POS   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c1         cb0             0         1  ( FLT, FLT, FLT, FLT)
// c2         cb0            14         4  ( FLT, FLT, FLT, FLT)
// c6         cb0            19         7  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c0                              Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
    def c13, 2, -1, 0, 1
    dcl_texcoord v0  // vin<0,1,2,3>
    dcl_texcoord1 v1  // vin<4,5,6>
    dcl_texcoord2 v2  // vin<7,8>
    dcl_texcoord3 v3  // vin<9,10,11,12>

#line 82 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\Lighting.fxh"
    dp4 oPos.z, v0, c11  // ::VSBasicPixelLightingTxVcBn<15>
    dp4 oT1.x, v0, c3  // ::VSBasicPixelLightingTxVcBn<2>
    dp4 oT1.y, v0, c4  // ::VSBasicPixelLightingTxVcBn<3>
    dp4 oT1.z, v0, c5  // ::VSBasicPixelLightingTxVcBn<4>

#line 11 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\Utilities.fxh"
    mad r0.xyz, v1, c13.x, c13.y  // ::BiasX2<0,1,2>

#line 84 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\Lighting.fxh"
    dp3 r1.x, r0, c6
    dp3 r1.y, r0, c7
    dp3 r1.z, r0, c8
    dp3 r0.x, r1, r1
    rsq r0.x, r0.x
    mul oT2.xyz, r0.x, r1  // ::VSBasicPixelLightingTxVcBn<6,7,8>

#line 11 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\Common.fxh"
    dp4 r0.x, v0, c2
    max r0.x, r0.x, c13.z
    min oT1.w, r0.x, c13.w  // ::VSBasicPixelLightingTxVcBn<5>

#line 482 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\BasicEffect.fx"
    mul oT3.w, v3.w, c1.w  // ::VSBasicPixelLightingTxVcBn<12>

#line 82 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\Lighting.fxh"
    dp4 r0.x, v0, c9  // ::vout<0>
    dp4 r0.y, v0, c10  // ::vout<1>
    dp4 r0.z, v0, c12  // ::vout<3>

#line 472 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\BasicEffect.fx"
    mad oPos.xy, r0.z, c0, r0  // ::VSBasicPixelLightingTxVcBn<13,14>
    mov oPos.w, r0.z  // ::VSBasicPixelLightingTxVcBn<16>

#line 483
    mov oT0.xy, v2  // ::VSBasicPixelLightingTxVcBn<0,1>
    mov oT3.xyz, v3  // ::VSBasicPixelLightingTxVcBn<9,10,11>

// approximately 22 instruction slots used
vs_4_0
dcl_constantbuffer CB0[26], immediateIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xy
dcl_input v3.xyzw
dcl_output o0.xy
dcl_output o1.xyzw
dcl_output o2.xyz
dcl_output o3.xyzw
dcl_output_siv o4.xyzw, position
dcl_temps 2
mov o0.xy, v2.xyxx
dp4 o1.x, v0.xyzw, cb0[15].xyzw
dp4 o1.y, v0.xyzw, cb0[16].xyzw
dp4 o1.z, v0.xyzw, cb0[17].xyzw
dp4_sat o1.w, v0.xyzw, cb0[14].xyzw
mad r0.xyz, v1.xyzx, l(2.000000, 2.000000, 2.000000, 0.000000), l(-1.000000, -1.000000, -1.000000, 0.000000)
dp3 r1.x, r0.xyzx, cb0[19].xyzx
dp3 r1.y, r0.xyzx, cb0[20].xyzx
dp3 r1.z, r0.xyzx, cb0[21].xyzx
dp3 r0.x, r1.xyzx, r1.xyzx
rsq r0.x, r0.x
mul o2.xyz, r0.xxxx, r1.xyzx
mul o3.w, v3.w, cb0[0].w
mov o3.xyz, v3.xyzx
dp4 o4.x, v0.xyzw, cb0[22].xyzw
dp4 o4.y, v0.xyzw, cb0[23].xyzw
dp4 o4.z, v0.xyzw, cb0[24].xyzw
dp4 o4.w, v0.xyzw, cb0[25].xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_VSBasicPixelLightingTxVcBn[] =
{
     68,  88,  66,  67, 126, 177, 
    167, 234,  10,  99,  30, 130, 
    156,   9, 225, 188,  47, 102, 
    135,  15,   1,   0,   0,   0, 
    204,  11,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    200,   7,   0,   0, 148,  10, 
      0,   0,  40,  11,   0,   0, 
     65, 111, 110,  57, 144,   7, 
      0,   0, 144,   7,   0,   0, 
      0,   2, 254, 255,  68,   7, 
      0,   0,  76,   0,   0,   0, 
      3,   0,  36,   0,   0,   0, 
     72,   0,   0,   0,  72,   0, 
      0,   0,  36,   0,   1,   0, 
     72,   0,   0,   0,   0,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  14,   0, 
      4,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,  19,   0, 
      7,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2, 254, 255, 254, 255, 
    102,   1,  68,  66,  85,  71, 
     40,   0,   0,   0, 108,   5, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0, 204,   1, 
      0,   0,  27,   0,   0,   0, 
    220,   1,   0,   0,   4,   0, 
      0,   0,  28,   5,   0,   0, 
    216,   2,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92, 108,  99, 118,  50,  51, 
     50,  50,  54,  48,  53,  92, 
     68, 111,  99, 117, 109, 101, 
    110, 116, 115,  92,  71, 105, 
    116,  72, 117,  98,  92,  73, 
     69,  88, 101, 110, 103, 105, 
    101, 110,  95,  76, 117, 107, 
     97, 115,  95,  75,  97, 101, 
    108, 105, 110,  92,  69, 120, 
    116, 101, 114, 110,  97, 108, 
     92,  68, 105, 114, 101,  99, 
    116,  88,  84,  75,  92, 115, 
    114,  99,  92,  83, 104,  97, 
    100, 101, 114, 115,  92,  76, 
    105, 103, 104, 116, 105, 110, 
    103,  46, 102, 120, 104,   0, 
     67,  58,  92,  85, 115, 101, 
    114, 115,  92, 108,  99, 118, 
     50,  51,  50,  50,  54,  48, 
     53,  92,  68, 111,  99, 117, 
    109, 101, 110, 116, 115,  92, 
     71, 105, 116,  72, 117,  98, 
     92,  73,  69,  88, 101, 110, 
    103, 105, 101, 110,  95,  76, 
    117, 107,  97, 115,  95,  75, 
     97, 101, 108, 105, 110,  92, 
     69, 120, 116, 101, 114, 110, 
     97, 108,  92,  68, 105, 114, 
    101,  99, 116,  88,  84,  75, 
     92, 115, 114,  99,  92,  83, 
    104,  97, 100, 101, 114, 115, 
     92,  85, 116, 105, 108, 105, 
    116, 105, 101, 115,  46, 102, 
    120, 104,   0,  67,  58,  92, 
     85, 115, 101, 114, 115,  92, 
    108,  99, 118,  50,  51,  50, 
     50,  54,  48,  53,  92,  68, 
    111,  99, 117, 109, 101, 110, 
    116, 115,  92,  71, 105, 116, 
     72, 117,  98,  92,  73,  69, 
     88, 101, 110, 103, 105, 101, 
    110,  95,  76, 117, 107,  97, 
    115,  95,  75,  97, 101, 108, 
    105, 110,  92,  69, 120, 116, 
    101, 114, 110,  97, 108,  92, 
     68, 105, 114, 101,  99, 116, 
     88,  84,  75,  92, 115, 114, 
     99,  92,  83, 104,  97, 100, 
    101, 114, 115,  92,  67, 111, 
    109, 109, 111, 110,  46, 102, 
    120, 104,   0,  67,  58,  92, 
     85, 115, 101, 114, 115,  92, 
    108,  99, 118,  50,  51,  50, 
     50,  54,  48,  53,  92,  68, 
    111,  99, 117, 109, 101, 110, 
    116, 115,  92,  71, 105, 116, 
     72, 117,  98,  92,  73,  69, 
     88, 101, 110, 103, 105, 101, 
    110,  95,  76, 117, 107,  97, 
    115,  95,  75,  97, 101, 108, 
    105, 110,  92,  69, 120, 116, 
    101, 114, 110,  97, 108,  92, 
     68, 105, 114, 101,  99, 116, 
     88,  84,  75,  92, 115, 114, 
     99,  92,  83, 104,  97, 100, 
    101, 114, 115,  92,  66,  97, 
    115, 105,  99,  69, 102, 102, 
    101,  99, 116,  46, 102, 120, 
      0, 171, 171, 171,  40,   0, 
      0,   0, 144,   0,   0,   0, 
    249,   0,   0,   0,  95,   1, 
      0,   0,   0,   0, 255, 255, 
    160,   5,   0,   0,   0,   0, 
    255, 255, 184,   5,   0,   0, 
      0,   0, 255, 255, 196,   5, 
      0,   0,   0,   0, 255, 255, 
    208,   5,   0,   0,   0,   0, 
    255, 255, 220,   5,   0,   0, 
     82,   0,   0,   0, 232,   5, 
      0,   0,  83,   0,   0,   0, 
    248,   5,   0,   0,  83,   0, 
      0,   0,   8,   6,   0,   0, 
     83,   0,   0,   0,  24,   6, 
      0,   0,  11,   0,   1,   0, 
     40,   6,   0,   0,  84,   0, 
      0,   0,  60,   6,   0,   0, 
     84,   0,   0,   0,  76,   6, 
      0,   0,  84,   0,   0,   0, 
     92,   6,   0,   0,  84,   0, 
      0,   0, 108,   6,   0,   0, 
     84,   0,   0,   0, 124,   6, 
      0,   0,  84,   0,   0,   0, 
    136,   6,   0,   0,  11,   0, 
      2,   0, 152,   6,   0,   0, 
     11,   0,   2,   0, 168,   6, 
      0,   0,  11,   0,   2,   0, 
    184,   6,   0,   0, 226,   1, 
      3,   0, 200,   6,   0,   0, 
     82,   0,   0,   0, 216,   6, 
      0,   0,  82,   0,   0,   0, 
    232,   6,   0,   0,  82,   0, 
      0,   0, 248,   6,   0,   0, 
    216,   1,   3,   0,   8,   7, 
      0,   0, 216,   1,   3,   0, 
     28,   7,   0,   0, 227,   1, 
      3,   0,  40,   7,   0,   0, 
    225,   1,   3,   0,  52,   7, 
      0,   0,  66, 105,  97, 115, 
     88,  50,   0, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  86,  83,  66,  97, 
    115, 105,  99,  80, 105, 120, 
    101, 108,  76, 105, 103, 104, 
    116, 105, 110, 103,  84, 120, 
     86,  99,  66, 110,   0,  84, 
    101, 120,  67, 111, 111, 114, 
    100,   0,   1,   0,   3,   0, 
      1,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     80, 111, 115, 105, 116, 105, 
    111, 110,  87,  83,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  78, 111, 
    114, 109,  97, 108,  87,  83, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  68, 105, 102, 102, 
    117, 115, 101,   0,  80, 111, 
    115, 105, 116, 105, 111, 110, 
     80,  83,   0, 171, 243,   2, 
      0,   0, 252,   2,   0,   0, 
     12,   3,   0,   0,  24,   3, 
      0,   0,  40,   3,   0,   0, 
     52,   3,   0,   0,  68,   3, 
      0,   0,  24,   3,   0,   0, 
     76,   3,   0,   0,  24,   3, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  17,   0,   1,   0, 
      5,   0,  88,   3,   0,   0, 
      5,   0,   0,   0, 255, 255, 
    255, 255,  15,   0, 255, 255, 
      6,   0,   0,   0,   2,   0, 
    255, 255, 255, 255, 255, 255, 
      7,   0,   0,   0, 255, 255, 
      3,   0, 255, 255, 255, 255, 
      8,   0,   0,   0, 255, 255, 
    255, 255,   4,   0, 255, 255, 
     15,   0,   0,   0,   6,   0, 
      7,   0,   8,   0, 255, 255, 
     18,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,   5,   0, 
     19,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  12,   0, 
     23,   0,   0,   0,  13,   0, 
     14,   0, 255, 255, 255, 255, 
     24,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  16,   0, 
     25,   0,   0,   0,   0,   0, 
      1,   0, 255, 255, 255, 255, 
     26,   0,   0,   0,   9,   0, 
     10,   0,  11,   0, 255, 255, 
    118, 105, 110,   0,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0,  78, 111, 114, 109,  97, 
    108,   0,  67, 111, 108, 111, 
    114,   0, 171, 171,  24,   4, 
      0,   0,  24,   3,   0,   0, 
     33,   4,   0,   0,  52,   3, 
      0,   0, 243,   2,   0,   0, 
    252,   2,   0,   0,  40,   4, 
      0,   0,  24,   3,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     13,   0,   1,   0,   4,   0, 
     48,   4,   0,   0,   1,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0,   2,   0, 
      0,   0,   4,   0,   5,   0, 
      6,   0, 255, 255,   3,   0, 
      0,   0,   7,   0,   8,   0, 
    255, 255, 255, 255,   4,   0, 
      0,   0,   9,   0,  10,   0, 
     11,   0,  12,   0, 118, 111, 
    117, 116,   0,  80, 111, 115, 
     95, 112, 115,   0,  80, 111, 
    115,  95, 119, 115,   0,  78, 
    111, 114, 109,  97, 108,  95, 
    119, 115,   0,  70, 111, 103, 
     70,  97,  99, 116, 111, 114, 
      0, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    149,   4,   0,   0,  24,   3, 
      0,   0, 156,   4,   0,   0, 
     52,   3,   0,   0, 163,   4, 
      0,   0,  52,   3,   0,   0, 
    173,   4,   0,   0, 184,   4, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  11,   0,   1,   0, 
      4,   0, 200,   4,   0,   0, 
     20,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     21,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     22,   0,   0,   0, 255, 255, 
    255, 255,   3,   0, 255, 255, 
      0,   0,   0,   0, 180,   2, 
      0,   0, 188,   2,   0,   0, 
      1,   0,   0,   0, 204,   2, 
      0,   0,   0,   0,   0,   0, 
    216,   2,   0,   0, 128,   3, 
      0,   0,  11,   0,   0,   0, 
    144,   3,   0,   0, 216,   2, 
      0,   0,  20,   4,   0,   0, 
     80,   4,   0,   0,   4,   0, 
      0,   0,  96,   4,   0,   0, 
      0,   0,   0,   0, 144,   4, 
      0,   0, 232,   4,   0,   0, 
      3,   0,   0,   0, 248,   4, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     81,   0,   0,   5,  13,   0, 
     15, 160,   0,   0,   0,  64, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0, 128,  63, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      1, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      2, 128,   2,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      3, 128,   3,   0,  15, 144, 
      9,   0,   0,   3,   0,   0, 
      4, 192,   0,   0, 228, 144, 
     11,   0, 228, 160,   9,   0, 
      0,   3,   1,   0,   1, 224, 
      0,   0, 228, 144,   3,   0, 
    228, 160,   9,   0,   0,   3, 
      1,   0,   2, 224,   0,   0, 
    228, 144,   4,   0, 228, 160, 
      9,   0,   0,   3,   1,   0, 
      4, 224,   0,   0, 228, 144, 
      5,   0, 228, 160,   4,   0, 
      0,   4,   0,   0,   7, 128, 
      1,   0, 228, 144,  13,   0, 
      0, 160,  13,   0,  85, 160, 
      8,   0,   0,   3,   1,   0, 
      1, 128,   0,   0, 228, 128, 
      6,   0, 228, 160,   8,   0, 
      0,   3,   1,   0,   2, 128, 
      0,   0, 228, 128,   7,   0, 
    228, 160,   8,   0,   0,   3, 
      1,   0,   4, 128,   0,   0, 
    228, 128,   8,   0, 228, 160, 
      8,   0,   0,   3,   0,   0, 
      1, 128,   1,   0, 228, 128, 
      1,   0, 228, 128,   7,   0, 
      0,   2,   0,   0,   1, 128, 
      0,   0,   0, 128,   5,   0, 
      0,   3,   2,   0,   7, 224, 
      0,   0,   0, 128,   1,   0, 
    228, 128,   9,   0,   0,   3, 
      0,   0,   1, 128,   0,   0, 
    228, 144,   2,   0, 228, 160, 
     11,   0,   0,   3,   0,   0, 
      1, 128,   0,   0,   0, 128, 
     13,   0, 170, 160,  10,   0, 
      0,   3,   1,   0,   8, 224, 
      0,   0,   0, 128,  13,   0, 
    255, 160,   5,   0,   0,   3, 
      3,   0,   8, 224,   3,   0, 
    255, 144,   1,   0, 255, 160, 
      9,   0,   0,   3,   0,   0, 
      1, 128,   0,   0, 228, 144, 
      9,   0, 228, 160,   9,   0, 
      0,   3,   0,   0,   2, 128, 
      0,   0, 228, 144,  10,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   4, 128,   0,   0, 
    228, 144,  12,   0, 228, 160, 
      4,   0,   0,   4,   0,   0, 
      3, 192,   0,   0, 170, 128, 
      0,   0, 228, 160,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   0,   8, 192,   0,   0, 
    170, 128,   1,   0,   0,   2, 
      0,   0,   3, 224,   2,   0, 
    228, 144,   1,   0,   0,   2, 
      3,   0,   7, 224,   3,   0, 
    228, 144, 255, 255,   0,   0, 
     83,  72,  68,  82, 196,   2, 
      0,   0,  64,   0,   1,   0, 
    177,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  26,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   1,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   2,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   0,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    114,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   3,   0, 
      0,   0, 103,   0,   0,   4, 
    242,  32,  16,   0,   4,   0, 
      0,   0,   1,   0,   0,   0, 
    104,   0,   0,   2,   2,   0, 
      0,   0,  54,   0,   0,   5, 
     50,  32,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   8,  18,  32,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     17,   0,   0,   8,  34,  32, 
     16,   0,   1,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,  17,   0,   0,   8, 
     66,  32,  16,   0,   1,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     17,   0,   0,   0,  17,  32, 
      0,   8, 130,  32,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     50,   0,   0,  15, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0,   0,   0, 
     16,   0,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  19,   0, 
      0,   0,  16,   0,   0,   8, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     20,   0,   0,   0,  16,   0, 
      0,   8,  66,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,  21,   0,   0,   0, 
     16,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  68,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,  32, 
     16,   0,   2,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   8, 130,  32,  16,   0, 
      3,   0,   0,   0,  58,  16, 
     16,   0,   3,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 114,  32, 
     16,   0,   3,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,  17,   0,   0,   8, 
     18,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     22,   0,   0,   0,  17,   0, 
      0,   8,  34,  32,  16,   0, 
      4,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  23,   0,   0,   0, 
     17,   0,   0,   8,  66,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  24,   0, 
      0,   0,  17,   0,   0,   8, 
    130,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     25,   0,   0,   0,  62,   0, 
      0,   1,  73,  83,  71,  78, 
    140,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,  15,   0,   0, 
    116,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   7,   0,   0, 
    123,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
    132,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,  15,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     78,  79,  82,  77,  65,  76, 
      0,  84,  69,  88,  67,  79, 
     79,  82,  68,   0,  67,  79, 
     76,  79,  82,   0, 171, 171, 
     79,  83,  71,  78, 156,   0, 
      0,   0,   5,   0,   0,   0, 
      8,   0,   0,   0, 128,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,  12,   0,   0, 128,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0, 128,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      7,   8,   0,   0, 137,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,   0,   0,   0, 143,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,   0,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  67,  79,  76,  79,  82, 
      0,  83,  86,  95,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0, 171
};
