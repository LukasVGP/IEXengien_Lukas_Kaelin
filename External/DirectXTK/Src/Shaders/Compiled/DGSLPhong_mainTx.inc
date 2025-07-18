#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// TEXCOORD                 1   xyz         3     NONE   float   xyz 
// TEXCOORD                 2   xyz         4     NONE   float       
// TEXCOORD                 3   xyz         5     NONE   float   xyz 
// TEXCOORD                 4   xyzw        6     NONE   float       
// TEXCOORD                 5   xyz         7     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0         1  ( FLT, FLT, FLT, FLT)
// c1         cb0             2         1  ( FLT, FLT, FLT, FLT)
// c2         cb0             4         1  ( FLT, FLT, FLT, FLT)
// c3         cb1             0         4  ( FLT, FLT, FLT, FLT)
// c7         cb1             9         3  ( FLT, FLT, FLT, FLT)
// c10        cb1            13         3  ( FLT, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c13, 9.99999975e-005, 0, 0, 0
    dcl t0  // pixel<4,5,6,7>
    dcl t1.xy  // pixel<8,9>
    dcl t2.xyz  // pixel<10,11,12>
    dcl t4.xyz  // pixel<16,17,18>
    dcl_2d s0

#line 176 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\DGSLPhong.hlsl"
    texld r0, t1, s0

#line 100
    mov r1.xyz, c1  // MaterialVars::MaterialSpecular<0,1,2>
    mul r2.xyz, r1, c4
    mul r3.xyz, r1, c5

#line 164
    dp3 r1.w, t4, t4
    rsq r1.w, r1.w

#line 97
    mad r4.xyz, t4, r1.w, c8
    nrm r5.xyz, r4  // ::vHalf<0,1,2>

#line 163
    nrm r4.xyz, t2  // ::worldNormal<0,1,2>

#line 98
    dp3_sat r2.w, r4, r5  // ::specularAmount<0>
    mov r3.w, c2.x  // MaterialVars::MaterialSpecularPower<0>
    max r4.w, r3.w, c13.x
    pow r3.w, r2.w, r4.w
    mul r2.w, r3.w, c11.x  // ::specularAmount<0>
    mul r3.xyz, r2.w, r3  // ::specular<0,1,2>

#line 97
    mad r5.xyz, t4, r1.w, c7
    mad r6.xyz, t4, r1.w, c9
    nrm r7.xyz, r6  // ::vHalf<0,1,2>
    dp3_sat r1.w, r4, r7  // ::specularAmount<0>
    pow r2.w, r1.w, r4.w
    mul r1.w, r2.w, c12.x  // ::specularAmount<0>
    nrm r6.xyz, r5  // ::vHalf<0,1,2>
    dp3_sat r2.w, r4, r6  // ::specularAmount<0>
    pow r3.w, r2.w, r4.w
    mul r2.w, r3.w, c10.x  // ::specularAmount<0>

#line 172
    mad r2.xyz, r2, r2.w, r3  // ::local4<0,1,2>

#line 100
    mul r1.xyz, r1, c6

#line 172
    mad r1.xyz, r1, r1.w, r2  // ::local4<0,1,2>

#line 78
    dp3_sat r1.w, c7, r4  // ::diffuseAmount<0>
    mul r2.xyz, r1.w, c4
    mul r2.xyz, r2, t0  // ::diffuse<0,1,2>

#line 171
    mov r3.xyz, c0  // MaterialVars::MaterialAmbient<0,1,2>
    mad r2.xyz, r3, c3, r2  // ::local1<0,1,2>

#line 78
    dp3_sat r1.w, c8, r4  // ::diffuseAmount<0>
    dp3_sat r2.w, c9, r4  // ::diffuseAmount<0>
    mul r3.xyz, r2.w, c6
    mul r4.xyz, r1.w, c5

#line 171
    mad r2.xyz, r4, t0, r2  // ::local1<0,1,2>
    mad_sat r2.xyz, r3, t0, r2  // ::local1<0,1,2>

#line 176
    mad r1.xyz, r2, r0, r1  // ::local5<0,1,2>
    mul r1.w, r0.w, t0.w  // ::local6<0>
    mov oC0, r1  // ::mainTx<0,1,2,3>

// approximately 56 instruction slots used (1 texture, 55 arithmetic)
ps_4_0
dcl_constantbuffer CB0[5], immediateIndexed
dcl_constantbuffer CB1[16], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_input_ps linear v3.xyz
dcl_input_ps linear v5.xyz
dcl_output o0.xyzw
dcl_temps 5
mul r0.xyz, cb0[2].xyzx, cb1[1].xyzx
mul r1.xyz, cb0[2].xyzx, cb1[2].xyzx
dp3 r0.w, v5.xyzx, v5.xyzx
rsq r0.w, r0.w
mad r2.xyz, v5.xyzx, r0.wwww, cb1[10].xyzx
dp3 r1.w, r2.xyzx, r2.xyzx
rsq r1.w, r1.w
mul r2.xyz, r1.wwww, r2.xyzx
dp3 r1.w, v3.xyzx, v3.xyzx
rsq r1.w, r1.w
mul r3.xyz, r1.wwww, v3.xyzx
dp3_sat r1.w, r3.xyzx, r2.xyzx
log r1.w, r1.w
max r2.x, cb0[4].x, l(0.000100)
mul r1.w, r1.w, r2.x
exp r1.w, r1.w
mul r1.w, r1.w, cb1[14].x
mul r1.xyz, r1.wwww, r1.xyzx
mad r2.yzw, v5.xxyz, r0.wwww, cb1[9].xxyz
mad r4.xyz, v5.xyzx, r0.wwww, cb1[11].xyzx
dp3 r0.w, r2.yzwy, r2.yzwy
rsq r0.w, r0.w
mul r2.yzw, r0.wwww, r2.yyzw
dp3_sat r0.w, r3.xyzx, r2.yzwy
log r0.w, r0.w
mul r0.w, r0.w, r2.x
exp r0.w, r0.w
mul r0.w, r0.w, cb1[13].x
mad r0.xyz, r0.xyzx, r0.wwww, r1.xyzx
mul r1.xyz, cb0[2].xyzx, cb1[3].xyzx
dp3 r0.w, r4.xyzx, r4.xyzx
rsq r0.w, r0.w
mul r2.yzw, r0.wwww, r4.xxyz
dp3_sat r0.w, r3.xyzx, r2.yzwy
log r0.w, r0.w
mul r0.w, r0.w, r2.x
exp r0.w, r0.w
mul r0.w, r0.w, cb1[15].x
mad r0.xyz, r1.xyzx, r0.wwww, r0.xyzx
dp3_sat r0.w, cb1[9].xyzx, r3.xyzx
mul r1.xyz, r0.wwww, cb1[1].xyzx
mul r1.xyz, r1.xyzx, v1.xyzx
mad r1.xyz, cb0[0].xyzx, cb1[0].xyzx, r1.xyzx
dp3_sat r0.w, cb1[10].xyzx, r3.xyzx
dp3_sat r1.w, cb1[11].xyzx, r3.xyzx
mul r2.xyz, r1.wwww, cb1[3].xyzx
mul r3.xyz, r0.wwww, cb1[2].xyzx
mad r1.xyz, r3.xyzx, v1.xyzx, r1.xyzx
mad_sat r1.xyz, r2.xyzx, v1.xyzx, r1.xyzx
sample r2.xyzw, v2.xyxx, t0.xyzw, s0
mad o0.xyz, r1.xyzx, r2.xyzx, r0.xyzx
mul o0.w, r2.w, v1.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE DGSLPhong_mainTx[] =
{
     68,  88,  66,  67,  41,   4, 
    218, 171, 166, 228, 122, 228, 
    219,  96,  95,  46,  61, 232, 
     90, 250,   1,   0,   0,   0, 
    244,  17,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
     68,  10,   0,   0, 212,  16, 
      0,   0, 192,  17,   0,   0, 
     65, 111, 110,  57,  12,  10, 
      0,   0,  12,  10,   0,   0, 
      0,   2, 255, 255, 156,   9, 
      0,   0, 112,   0,   0,   0, 
      6,   0,  40,   0,   0,   0, 
    112,   0,   0,   0, 112,   0, 
      1,   0,  36,   0,   0,   0, 
    112,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   1,   0, 
      2,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   4,   0, 
      3,   0,   0,   0,   0,   0, 
      1,   0,   9,   0,   3,   0, 
      7,   0,   0,   0,   0,   0, 
      1,   0,  13,   0,   3,   0, 
     10,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    167,   1,  68,  66,  85,  71, 
     40,   0,   0,   0, 112,   6, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 148,   0, 
      0,   0,  48,   0,   0,   0, 
    152,   0,   0,   0,  15,   0, 
      0,   0,  68,   5,   0,   0, 
    132,   3,   0,   0,  67,  58, 
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
    100, 101, 114, 115,  92,  68, 
     71,  83,  76,  80, 104, 111, 
    110, 103,  46, 104, 108, 115, 
    108,   0, 171, 171,  40,   0, 
      0,   0,   0,   0, 255, 255, 
    164,   6,   0,   0,   0,   0, 
    255, 255, 188,   6,   0,   0, 
      0,   0, 255, 255, 200,   6, 
      0,   0,   0,   0, 255, 255, 
    212,   6,   0,   0,   0,   0, 
    255, 255, 224,   6,   0,   0, 
      0,   0, 255, 255, 236,   6, 
      0,   0, 176,   0,   0,   0, 
    248,   6,   0,   0, 100,   0, 
      0,   0,   8,   7,   0,   0, 
    100,   0,   0,   0,  20,   7, 
      0,   0, 100,   0,   0,   0, 
     36,   7,   0,   0, 164,   0, 
      0,   0,  52,   7,   0,   0, 
    164,   0,   0,   0,  68,   7, 
      0,   0,  97,   0,   0,   0, 
     80,   7,   0,   0,  97,   0, 
      0,   0, 100,   7,   0,   0, 
    163,   0,   0,   0, 112,   7, 
      0,   0,  98,   0,   0,   0, 
    124,   7,   0,   0,  99,   0, 
      0,   0, 140,   7,   0,   0, 
     99,   0,   0,   0, 152,   7, 
      0,   0,  99,   0,   0,   0, 
    168,   7,   0,   0,  99,   0, 
      0,   0, 184,   7,   0,   0, 
    100,   0,   0,   0, 200,   7, 
      0,   0,  97,   0,   0,   0, 
    216,   7,   0,   0,  97,   0, 
      0,   0, 236,   7,   0,   0, 
     97,   0,   0,   0,   0,   8, 
      0,   0,  98,   0,   0,   0, 
     12,   8,   0,   0,  99,   0, 
      0,   0,  28,   8,   0,   0, 
     99,   0,   0,   0,  44,   8, 
      0,   0,  97,   0,   0,   0, 
     60,   8,   0,   0,  98,   0, 
      0,   0,  72,   8,   0,   0, 
     99,   0,   0,   0,  88,   8, 
      0,   0,  99,   0,   0,   0, 
    104,   8,   0,   0, 172,   0, 
      0,   0, 120,   8,   0,   0, 
    100,   0,   0,   0, 140,   8, 
      0,   0, 172,   0,   0,   0, 
    156,   8,   0,   0,  78,   0, 
      0,   0, 176,   8,   0,   0, 
     79,   0,   0,   0, 192,   8, 
      0,   0,  79,   0,   0,   0, 
    208,   8,   0,   0, 171,   0, 
      0,   0, 224,   8,   0,   0, 
    171,   0,   0,   0, 236,   8, 
      0,   0,  78,   0,   0,   0, 
      0,   9,   0,   0,  78,   0, 
      0,   0,  16,   9,   0,   0, 
     79,   0,   0,   0,  32,   9, 
      0,   0,  79,   0,   0,   0, 
     48,   9,   0,   0, 171,   0, 
      0,   0,  64,   9,   0,   0, 
    171,   0,   0,   0,  84,   9, 
      0,   0, 176,   0,   0,   0, 
    104,   9,   0,   0, 177,   0, 
      0,   0, 124,   9,   0,   0, 
    176,   0,   0,   0, 140,   9, 
      0,   0,  77,  97, 116, 101, 
    114, 105,  97, 108,  86,  97, 
    114, 115,   0,  77,  97, 116, 
    101, 114, 105,  97, 108,  65, 
    109,  98, 105, 101, 110, 116, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  37,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  77,  97, 116, 101, 
    114, 105,  97, 108,  83, 112, 
    101,  99, 117, 108,  97, 114, 
      0, 171, 171, 171,   7,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  77,  97, 
    116, 101, 114, 105,  97, 108, 
     83, 112, 101,  99, 117, 108, 
     97, 114,  80, 111, 119, 101, 
    114,   0, 171, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0, 100, 105, 102, 102, 
    117, 115, 101,   0,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  36,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255, 100, 105, 102, 102, 
    117, 115, 101,  65, 109, 111, 
    117, 110, 116,   0, 171, 171, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  34,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   0,   0,  39,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   0,   0,  40,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   0,   0, 108, 111, 
     99,  97, 108,  49,   0, 171, 
     38,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     43,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     44,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    108, 111,  99,  97, 108,  52, 
      0, 171,  31,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  33,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255, 108, 111,  99,  97, 
    108,  53,   0, 171,  45,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 108, 111, 
     99,  97, 108,  54,   0, 171, 
     46,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,   0,   0, 
    109,  97, 105, 110,  84, 120, 
      0, 102, 114,  97, 103, 109, 
    101, 110, 116,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 139,   3,   0,   0, 
    148,   3,   0,   0,   5,   0, 
      0,   0,   1,   0,   4,   0, 
      1,   0,   1,   0, 164,   3, 
      0,   0,  47,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0, 112, 105, 120, 101, 
    108,   0, 112, 111, 115,   0, 
    117, 118,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      2,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 119, 111, 
    114, 108, 100,  78, 111, 114, 
    109,   0, 119, 111, 114, 108, 
    100,  80, 111, 115,   0, 116, 
    111,  69, 121, 101,   0, 116, 
     97, 110, 103, 101, 110, 116, 
      0, 110, 111, 114, 109,  97, 
    108,   0, 206,   3,   0,   0, 
    148,   3,   0,   0, 168,   2, 
      0,   0, 148,   3,   0,   0, 
    210,   3,   0,   0, 216,   3, 
      0,   0, 232,   3,   0,   0, 
    176,   2,   0,   0, 242,   3, 
      0,   0, 176,   2,   0,   0, 
    251,   3,   0,   0, 176,   2, 
      0,   0,   1,   4,   0,   0, 
    148,   3,   0,   0,   9,   4, 
      0,   0, 176,   2,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     26,   0,   1,   0,   8,   0, 
     16,   4,   0,   0,   1,   0, 
      0,   0,   4,   0,   5,   0, 
      6,   0,   7,   0,   2,   0, 
      0,   0,   8,   0,   9,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,  10,   0,  11,   0, 
     12,   0, 255, 255,   4,   0, 
      0,   0,  16,   0,  17,   0, 
     18,   0, 255, 255, 115, 112, 
    101,  99, 117, 108,  97, 114, 
      0, 171, 171, 171,  20,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 115, 112, 
    101,  99, 117, 108,  97, 114, 
     65, 109, 111, 117, 110, 116, 
      0, 171,  15,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  19,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  24,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  26,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  28,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  30,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0, 118,  72,  97, 108, 
    102,   0, 171, 171,  13,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  23,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  27,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 119, 111, 
    114, 108, 100,  78, 111, 114, 
    109,  97, 108,   0,  14,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  24,   2, 
      0,   0,  37,   2,   0,   0, 
     56,   2,   0,   0,   1,   0, 
      0,   0,  72,   2,   0,   0, 
     24,   2,   0,   0,  84,   2, 
      0,   0,  56,   2,   0,   0, 
      1,   0,   0,   0, 104,   2, 
      0,   0,  24,   2,   0,   0, 
    116,   2,   0,   0, 140,   2, 
      0,   0,   1,   0,   0,   0, 
    156,   2,   0,   0,   0,   0, 
      0,   0, 168,   2,   0,   0, 
    176,   2,   0,   0,   1,   0, 
      0,   0, 192,   2,   0,   0, 
      0,   0,   0,   0, 204,   2, 
      0,   0, 220,   2,   0,   0, 
      3,   0,   0,   0, 236,   2, 
      0,   0,   0,   0,   0,   0, 
     16,   3,   0,   0, 176,   2, 
      0,   0,   3,   0,   0,   0, 
     24,   3,   0,   0,   0,   0, 
      0,   0,  60,   3,   0,   0, 
    176,   2,   0,   0,   2,   0, 
      0,   0,  68,   3,   0,   0, 
      0,   0,   0,   0,  92,   3, 
      0,   0, 176,   2,   0,   0, 
      1,   0,   0,   0, 100,   3, 
      0,   0,   0,   0,   0,   0, 
    112,   3,   0,   0, 220,   2, 
      0,   0,   1,   0,   0,   0, 
    120,   3,   0,   0,   0,   0, 
      0,   0, 132,   3,   0,   0, 
    172,   3,   0,   0,   1,   0, 
      0,   0, 188,   3,   0,   0, 
    132,   3,   0,   0, 200,   3, 
      0,   0,  80,   4,   0,   0, 
      4,   0,   0,   0,  96,   4, 
      0,   0,   0,   0,   0,   0, 
    144,   4,   0,   0, 176,   2, 
      0,   0,   1,   0,   0,   0, 
    156,   4,   0,   0,   0,   0, 
      0,   0, 168,   4,   0,   0, 
    220,   2,   0,   0,   6,   0, 
      0,   0, 184,   4,   0,   0, 
      0,   0,   0,   0,   0,   5, 
      0,   0, 176,   2,   0,   0, 
      3,   0,   0,   0,   8,   5, 
      0,   0,   0,   0,   0,   0, 
     44,   5,   0,   0, 176,   2, 
      0,   0,   1,   0,   0,   0, 
     56,   5,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  81,   0,   0,   5, 
     13,   0,  15, 160,  23, 183, 
    209,  56,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
      3, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   2,   0, 
      7, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   4,   0, 
      7, 176,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  66,   0,   0,   3, 
      0,   0,  15, 128,   1,   0, 
    228, 176,   0,   8, 228, 160, 
      1,   0,   0,   2,   1,   0, 
      7, 128,   1,   0, 228, 160, 
      5,   0,   0,   3,   2,   0, 
      7, 128,   1,   0, 228, 128, 
      4,   0, 228, 160,   5,   0, 
      0,   3,   3,   0,   7, 128, 
      1,   0, 228, 128,   5,   0, 
    228, 160,   8,   0,   0,   3, 
      1,   0,   8, 128,   4,   0, 
    228, 176,   4,   0, 228, 176, 
      7,   0,   0,   2,   1,   0, 
      8, 128,   1,   0, 255, 128, 
      4,   0,   0,   4,   4,   0, 
      7, 128,   4,   0, 228, 176, 
      1,   0, 255, 128,   8,   0, 
    228, 160,  36,   0,   0,   2, 
      5,   0,   7, 128,   4,   0, 
    228, 128,  36,   0,   0,   2, 
      4,   0,   7, 128,   2,   0, 
    228, 176,   8,   0,   0,   3, 
      2,   0,  24, 128,   4,   0, 
    228, 128,   5,   0, 228, 128, 
      1,   0,   0,   2,   3,   0, 
      8, 128,   2,   0,   0, 160, 
     11,   0,   0,   3,   4,   0, 
      8, 128,   3,   0, 255, 128, 
     13,   0,   0, 160,  32,   0, 
      0,   3,   3,   0,   8, 128, 
      2,   0, 255, 128,   4,   0, 
    255, 128,   5,   0,   0,   3, 
      2,   0,   8, 128,   3,   0, 
    255, 128,  11,   0,   0, 160, 
      5,   0,   0,   3,   3,   0, 
      7, 128,   2,   0, 255, 128, 
      3,   0, 228, 128,   4,   0, 
      0,   4,   5,   0,   7, 128, 
      4,   0, 228, 176,   1,   0, 
    255, 128,   7,   0, 228, 160, 
      4,   0,   0,   4,   6,   0, 
      7, 128,   4,   0, 228, 176, 
      1,   0, 255, 128,   9,   0, 
    228, 160,  36,   0,   0,   2, 
      7,   0,   7, 128,   6,   0, 
    228, 128,   8,   0,   0,   3, 
      1,   0,  24, 128,   4,   0, 
    228, 128,   7,   0, 228, 128, 
     32,   0,   0,   3,   2,   0, 
      8, 128,   1,   0, 255, 128, 
      4,   0, 255, 128,   5,   0, 
      0,   3,   1,   0,   8, 128, 
      2,   0, 255, 128,  12,   0, 
      0, 160,  36,   0,   0,   2, 
      6,   0,   7, 128,   5,   0, 
    228, 128,   8,   0,   0,   3, 
      2,   0,  24, 128,   4,   0, 
    228, 128,   6,   0, 228, 128, 
     32,   0,   0,   3,   3,   0, 
      8, 128,   2,   0, 255, 128, 
      4,   0, 255, 128,   5,   0, 
      0,   3,   2,   0,   8, 128, 
      3,   0, 255, 128,  10,   0, 
      0, 160,   4,   0,   0,   4, 
      2,   0,   7, 128,   2,   0, 
    228, 128,   2,   0, 255, 128, 
      3,   0, 228, 128,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      1,   0, 228, 128,   6,   0, 
    228, 160,   4,   0,   0,   4, 
      1,   0,   7, 128,   1,   0, 
    228, 128,   1,   0, 255, 128, 
      2,   0, 228, 128,   8,   0, 
      0,   3,   1,   0,  24, 128, 
      7,   0, 228, 160,   4,   0, 
    228, 128,   5,   0,   0,   3, 
      2,   0,   7, 128,   1,   0, 
    255, 128,   4,   0, 228, 160, 
      5,   0,   0,   3,   2,   0, 
      7, 128,   2,   0, 228, 128, 
      0,   0, 228, 176,   1,   0, 
      0,   2,   3,   0,   7, 128, 
      0,   0, 228, 160,   4,   0, 
      0,   4,   2,   0,   7, 128, 
      3,   0, 228, 128,   3,   0, 
    228, 160,   2,   0, 228, 128, 
      8,   0,   0,   3,   1,   0, 
     24, 128,   8,   0, 228, 160, 
      4,   0, 228, 128,   8,   0, 
      0,   3,   2,   0,  24, 128, 
      9,   0, 228, 160,   4,   0, 
    228, 128,   5,   0,   0,   3, 
      3,   0,   7, 128,   2,   0, 
    255, 128,   6,   0, 228, 160, 
      5,   0,   0,   3,   4,   0, 
      7, 128,   1,   0, 255, 128, 
      5,   0, 228, 160,   4,   0, 
      0,   4,   2,   0,   7, 128, 
      4,   0, 228, 128,   0,   0, 
    228, 176,   2,   0, 228, 128, 
      4,   0,   0,   4,   2,   0, 
     23, 128,   3,   0, 228, 128, 
      0,   0, 228, 176,   2,   0, 
    228, 128,   4,   0,   0,   4, 
      1,   0,   7, 128,   2,   0, 
    228, 128,   0,   0, 228, 128, 
      1,   0, 228, 128,   5,   0, 
      0,   3,   1,   0,   8, 128, 
      0,   0, 255, 128,   0,   0, 
    255, 176,   1,   0,   0,   2, 
      0,   8,  15, 128,   1,   0, 
    228, 128, 255, 255,   0,   0, 
     83,  72,  68,  82, 136,   6, 
      0,   0,  64,   0,   0,   0, 
    162,   1,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   1,   0, 
      0,   0,  16,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      3,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      5,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   5,   0,   0,   0, 
     56,   0,   0,   9, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     56,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   5,   0, 
      0,   0,  70,  18,  16,   0, 
      5,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  18,  16,   0,   5,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
     10,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      3,   0,   0,   0,  70,  18, 
     16,   0,   3,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   3,   0,   0,   0, 
     16,  32,   0,   7, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  47,   0, 
      0,   5, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     52,   0,   0,   8,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,  64,   0,   0,  23, 183, 
    209,  56,  56,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   0,   1,   0,   0,   0, 
     14,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    226,   0,  16,   0,   2,   0, 
      0,   0,   6,  25,  16,   0, 
      5,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
      6, 137,  32,   0,   1,   0, 
      0,   0,   9,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  18,  16,   0,   5,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
     11,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0, 150,   7, 
     16,   0,   2,   0,   0,   0, 
    150,   7,  16,   0,   2,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 226,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     86,  14,  16,   0,   2,   0, 
      0,   0,  16,  32,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0, 150,   7, 
     16,   0,   2,   0,   0,   0, 
     47,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 226,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
      6,   9,  16,   0,   4,   0, 
      0,   0,  16,  32,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0, 150,   7, 
     16,   0,   2,   0,   0,   0, 
     47,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   1,   0,   0,   0, 
     15,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  16,  32, 
      0,   8, 130,   0,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  16,  32,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      1,   0,   0,   0,  10,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  16,  32, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
     11,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  50,  32, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  16, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 130,  32,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     58,  16,  16,   0,   1,   0, 
      0,   0,  62,   0,   0,   1, 
     73,  83,  71,  78, 228,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0, 200,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 212,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0, 218,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   3,   0,   0, 218,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   7,   0,   0, 218,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   0,   0,   0, 218,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      7,   7,   0,   0, 218,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   0,   0,   0, 218,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      7,   0,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171
};
