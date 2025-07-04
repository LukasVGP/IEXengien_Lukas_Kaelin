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
// TEXCOORD                 0   xy          2     NONE   float       
// TEXCOORD                 1   xyz         3     NONE   float       
// TEXCOORD                 2   xyz         4     NONE   float       
// TEXCOORD                 3   xyz         5     NONE   float       
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
// Level9 shader bytecode:
//
    ps_2_0
    def c0, -1, -0, 0, 0
    dcl t0  // pixel<4,5,6,7>

#line 89 "C:\Users\lcv2322605\Documents\GitHub\IEXengien_Lukas_Kaelin\External\DirectXTK\src\Shaders\DGSLUnlit.hlsl"
    mul r0.w, t0.w, t0.w
    cmp r0, -r0.w, c0.x, c0.y
    texkill r0
    mov r0, t0  // ::mainTk<0,1,2,3>
    mov oC0, r0  // ::mainTk<0,1,2,3>

// approximately 5 instruction slots used
ps_4_0
dcl_input_ps linear v1.xyzw
dcl_output o0.xyzw
dcl_temps 1
eq r0.x, v1.w, l(0.000000)
discard_nz r0.x
mov o0.xyzw, v1.xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE DGSLUnlit_mainTk[] =
{
     68,  88,  66,  67,  89, 207, 
    137, 164, 210, 252, 144,  65, 
    115,  83, 177, 132,  71, 148, 
     33, 215,   1,   0,   0,   0, 
    148,   4,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
      4,   3,   0,   0, 116,   3, 
      0,   0,  96,   4,   0,   0, 
     65, 111, 110,  57, 204,   2, 
      0,   0, 204,   2,   0,   0, 
      0,   2, 255, 255, 168,   2, 
      0,   0,  36,   0,   0,   0, 
      0,   0,  36,   0,   0,   0, 
     36,   0,   0,   0,  36,   0, 
      0,   0,  36,   0,   0,   0, 
     36,   0,   0,   2, 255, 255, 
    254, 255, 141,   0,  68,  66, 
     85,  71,  40,   0,   0,   0, 
      8,   2,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    148,   0,   0,   0,   7,   0, 
      0,   0, 152,   0,   0,   0, 
      2,   0,   0,   0, 224,   1, 
      0,   0, 208,   0,   0,   0, 
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
     92,  68,  71,  83,  76,  85, 
    110, 108, 105, 116,  46, 104, 
    108, 115, 108,   0, 171, 171, 
     40,   0,   0,   0,   0,   0, 
    255, 255,  60,   2,   0,   0, 
      0,   0, 255, 255,  84,   2, 
      0,   0,  89,   0,   0,   0, 
     96,   2,   0,   0,  89,   0, 
      0,   0, 112,   2,   0,   0, 
     89,   0,   0,   0, 132,   2, 
      0,   0,  91,   0,   0,   0, 
    140,   2,   0,   0,  91,   0, 
      0,   0, 152,   2,   0,   0, 
    109,  97, 105, 110,  84, 107, 
      0, 102, 114,  97, 103, 109, 
    101, 110, 116,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 215,   0,   0,   0, 
    224,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,   4,   0, 
      1,   0,   1,   0, 240,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,   6,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0, 112, 105, 120, 101, 
    108,   0, 112, 111, 115,   0, 
    100, 105, 102, 102, 117, 115, 
    101,   0, 117, 118,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    119, 111, 114, 108, 100,  78, 
    111, 114, 109,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      3,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 119, 111, 
    114, 108, 100,  80, 111, 115, 
      0, 116, 111,  69, 121, 101, 
      0, 116,  97, 110, 103, 101, 
    110, 116,   0, 110, 111, 114, 
    109,  97, 108,   0, 171, 171, 
     38,   1,   0,   0, 224,   0, 
      0,   0,  42,   1,   0,   0, 
    224,   0,   0,   0,  50,   1, 
      0,   0,  56,   1,   0,   0, 
     72,   1,   0,   0,  84,   1, 
      0,   0, 100,   1,   0,   0, 
     84,   1,   0,   0, 109,   1, 
      0,   0,  84,   1,   0,   0, 
    115,   1,   0,   0, 224,   0, 
      0,   0, 123,   1,   0,   0, 
     84,   1,   0,   0,   5,   0, 
      0,   0,   1,   0,  26,   0, 
      1,   0,   8,   0, 132,   1, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
      7,   0,   0,   0,   0,   0, 
    208,   0,   0,   0, 248,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   1,   0,   0, 208,   0, 
      0,   0,  32,   1,   0,   0, 
    196,   1,   0,   0,   1,   0, 
      0,   0, 212,   1,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  81,   0, 
      0,   5,   0,   0,  15, 160, 
      0,   0, 128, 191,   0,   0, 
      0, 128,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      0,   0,  15, 176,   5,   0, 
      0,   3,   0,   0,   8, 128, 
      0,   0, 255, 176,   0,   0, 
    255, 176,  88,   0,   0,   4, 
      0,   0,  15, 128,   0,   0, 
    255, 129,   0,   0,   0, 160, 
      0,   0,  85, 160,  65,   0, 
      0,   1,   0,   0,  15, 128, 
      1,   0,   0,   2,   0,   0, 
     15, 128,   0,   0, 228, 176, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 104,   0,   0,   0, 
     64,   0,   0,   0,  26,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      1,   0,   0,   0,  24,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  73,  83,  71,  78, 
    228,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    212,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
    218,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
    218,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,  15,   0,   0,   0, 
    218,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   7,   0,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     67,  79,  76,  79,  82,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171
};
