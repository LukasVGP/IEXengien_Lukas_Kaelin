#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// COLOR                    1   xyzw        1     NONE   float   xyzw
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
// c0         cb0            13         1  ( FLT, FLT, FLT, FLT)
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pin<0,1,2,3>
    dcl t1  // pin<4,5,6,7>

#line 23 "D:\unity\IEXengien_Lukas_Kaelin\External\DirectXTK\Src\Shaders\Common.fxh"
    mov r0, t0  // pin<0,1,2,3>
    mad r0.xyz, t1, r0.w, r0  // AddSpecular::color<0,1,2>

#line 17
    mad r1.xyz, c0, t0.w, -r0
    mad r0.xyz, t1.w, r1, r0  // ApplyFog::color<0,1,2>
    mov r0.w, t0.w
    mov oC0, r0  // ::PSBasicVertexLighting<0,1,2,3>

// approximately 6 instruction slots used
ps_4_0
dcl_constantbuffer CB0[14], immediateIndexed
dcl_input_ps linear v0.xyzw
dcl_input_ps linear v1.xyzw
dcl_output o0.xyzw
dcl_temps 2
mad r0.xyz, v1.xyzx, v0.wwww, v0.xyzx
mad r1.xyz, cb0[13].xyzx, v0.wwww, -r0.xyzx
mad o0.xyz, v1.wwww, r1.xyzx, r0.xyzx
mov o0.w, v0.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_PSBasicVertexLighting[] =
{
     68,  88,  66,  67,  98,  48, 
     32, 111, 111,  74, 248, 108, 
    131, 218,  36, 114,  74, 186, 
     60, 170,   1,   0,   0,   0, 
     72,   4,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    244,   2,   0,   0, 204,   3, 
      0,   0,  20,   4,   0,   0, 
     65, 111, 110,  57, 188,   2, 
      0,   0, 188,   2,   0,   0, 
      0,   2, 255, 255, 140,   2, 
      0,   0,  48,   0,   0,   0, 
      1,   0,  36,   0,   0,   0, 
     48,   0,   0,   0,  48,   0, 
      0,   0,  36,   0,   0,   0, 
     48,   0,   0,   0,  13,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   2, 255, 255, 
    254, 255, 130,   0,  68,  66, 
     85,  71,  40,   0,   0,   0, 
    220,   1,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    116,   0,   0,   0,   8,   0, 
      0,   0, 120,   0,   0,   0, 
      4,   0,   0,   0, 140,   1, 
      0,   0, 184,   0,   0,   0, 
     68,  58,  92, 117, 110, 105, 
    116, 121,  92,  73,  69,  88, 
    101, 110, 103, 105, 101, 110, 
     95,  76, 117, 107,  97, 115, 
     95,  75,  97, 101, 108, 105, 
    110,  92,  69, 120, 116, 101, 
    114, 110,  97, 108,  92,  68, 
    105, 114, 101,  99, 116,  88, 
     84,  75,  92,  83, 114,  99, 
     92,  83, 104,  97, 100, 101, 
    114, 115,  92,  67, 111, 109, 
    109, 111, 110,  46, 102, 120, 
    104,   0, 171, 171,  40,   0, 
      0,   0,   0,   0, 255, 255, 
     16,   2,   0,   0,   0,   0, 
    255, 255,  28,   2,   0,   0, 
     23,   0,   0,   0,  40,   2, 
      0,   0,  23,   0,   0,   0, 
     52,   2,   0,   0,  17,   0, 
      0,   0,  72,   2,   0,   0, 
     17,   0,   0,   0,  92,   2, 
      0,   0,  17,   0,   0,   0, 
    112,   2,   0,   0,  17,   0, 
      0,   0, 124,   2,   0,   0, 
     80,  83,  66,  97, 115, 105, 
     99,  86, 101, 114, 116, 101, 
    120,  76, 105, 103, 104, 116, 
    105, 110, 103,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0,  65, 112, 
    112, 108, 121,  70, 111, 103, 
      0,  99, 111, 108, 111, 114, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     65, 100, 100,  83, 112, 101, 
     99, 117, 108,  97, 114,   0, 
      3,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    112, 105, 110,   0,  68, 105, 
    102, 102, 117, 115, 101,   0, 
     83, 112, 101,  99, 117, 108, 
     97, 114,   0, 171, 171, 171, 
     52,   1,   0,   0, 252,   0, 
      0,   0,  60,   1,   0,   0, 
    252,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,   8,   0, 
      1,   0,   2,   0,  72,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,   1,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
      7,   0,   2,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,   0,   0,   0,   0, 
    184,   0,   0,   0, 208,   0, 
      0,   0,   1,   0,   0,   0, 
    224,   0,   0,   0, 236,   0, 
      0,   0, 245,   0,   0,   0, 
    252,   0,   0,   0,   1,   0, 
      0,   0,  12,   1,   0,   0, 
     24,   1,   0,   0, 245,   0, 
      0,   0, 252,   0,   0,   0, 
      1,   0,   0,   0,  36,   1, 
      0,   0, 184,   0,   0,   0, 
     48,   1,   0,   0,  88,   1, 
      0,   0,   3,   0,   0,   0, 
    104,   1,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
     15, 176,   1,   0,   0,   2, 
      0,   0,  15, 128,   0,   0, 
    228, 176,   4,   0,   0,   4, 
      0,   0,   7, 128,   1,   0, 
    228, 176,   0,   0, 255, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      0,   0, 228, 160,   0,   0, 
    255, 176,   0,   0, 228, 129, 
      4,   0,   0,   4,   0,   0, 
      7, 128,   1,   0, 255, 176, 
      1,   0, 228, 128,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   0,   8, 128,   0,   0, 
    255, 176,   1,   0,   0,   2, 
      0,   8,  15, 128,   0,   0, 
    228, 128, 255, 255,   0,   0, 
     83,  72,  68,  82, 208,   0, 
      0,   0,  64,   0,   0,   0, 
     52,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      2,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
    246,  31,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  11, 114,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     13,   0,   0,   0, 246,  31, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,   9, 114,  32, 
     16,   0,   0,   0,   0,   0, 
    246,  31,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   0,   0,   0,   0, 
     58,  16,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     73,  83,  71,  78,  64,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,  56,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  56,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0,  67,  79, 
     76,  79,  82,   0, 171, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};
