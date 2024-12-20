// SPDX-License-Identifier: ODbL-1.0

// ******************************************************************
// * D3DDevice__m_VerticalBlankEvent__GenericFragment
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// NOTE: This signature will find any generic match with D3D_g_pDevice
//       Currently, this is the best method without rely on
//       D3DDevice_BlockUntilVerticalBlank detection.
//       So, even though it's scanning for D3DDevice_BlockUntilVerticalBlank,
//       this OOVPA itself is not a symbol.
OOVPA_SIG_HEADER_XREF_DETECT(D3DDevice__m_VerticalBlankEvent__GenericFragment,
                             3911,
                             XRefTwo,
                             DetectFirst)
OOVPA_SIG_MATCH(

    // mov eax, [D3D_g_pDevice]
    XREF_ENTRY(0x01, XREF_D3D_g_pDevice),

    // add eax, OFFSET_D3DDevice__m_VerticalBlankEvent
    XREF_ENTRY(0x18, XREF_D3DDevice__m_VerticalBlankEvent_OFFSET), // <-- Deriving this XRef is the purpose of this OOVPA

    // mov eax,[D3D_g_pDevice]
    OV_MATCH(0x00, 0xA1),

    // push 0; push 0; push 1
    OV_MATCH(0x05, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x01),

    // mov dword ptr [eax+OFFSET_D3DDEVICE_M_???],
    OV_MATCH(0x0B, 0xC7, 0x80),

    // push 6
    OV_MATCH(0x15, 0x6A, 0x06),

    // add eax, OFFSET_D3DDevice__m_VerticalBlankEvent
    OV_MATCH(0x17, 0x05),

    // push eax
    OV_MATCH(0x1C, 0x50),

    // call e__
    OV_MATCH(0x1D, 0xFF),

    //
);

// ******************************************************************
// * D3DRS_Stencils_and_Occlusion__GenericFragment
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF_DETECT(D3DRS_Stencils_and_Occlusion__GenericFragment,
                             3911,
                             XRefFour,
                             DetectFirst)
OOVPA_SIG_MATCH(

    // mov e??, [D3DRS_StencilCullEnable]
    XREF_ENTRY(0x02, XREF_D3DRS_StencilCullEnable),

    // mov e??, [D3DRS_OcclusionCullEnable]
    XREF_ENTRY(0x13, XREF_D3DRS_OcclusionCullEnable),

    // mov e??, [D3DRS_StencilEnable]
    XREF_ENTRY(0x1D, XREF_D3DRS_StencilEnable),

    // cmp [D3DRS_StencilFail],0x1E00
    XREF_ENTRY(0x27, XREF_D3DRS_StencilFail),

    // mov e??, [D3DRS_StencilCullEnable]
    OV_MATCH(0x00, 0x8B),

    // mov ecx,0x2
    OV_MATCH(0x0C, 0xB9, 0x02, 0x00 /*, 0x00, 0x00*/),

    // mov e??, [D3DRS_OcclusionCullEnable]
    OV_MATCH(0x11, 0x8B),

    // mov e??, [D3DRS_StencilEnable]
    OV_MATCH(0x1B, 0x8B),

    // cmp [D3DRS_StencilFail],0x1E00
    OV_MATCH(0x25, 0x81),

    // or ecx,0x1
    OV_MATCH(0x31, 0x83, 0xC9, 0x01),
    //
);

// ******************************************************************
// * D3D_g_pDevice
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3D_g_pDevice,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * D3DDevice__m_PixelShader OFFSET
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3DDevice__m_PixelShader_OFFSET,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * D3DDevice__m_VerticalBlankEvent OFFSET
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3DDevice__m_VerticalBlankEvent_OFFSET,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * D3DDevice__m_SwapCallback OFFSET
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3DDevice__m_SwapCallback_OFFSET,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * D3DDevice__m_VBlankCallback OFFSET
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3DDevice__m_VBlankCallback_OFFSET,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * D3DDevice__m_VertexShader OFFSET
// ******************************************************************
// dummy signature
OOVPA_SIG_HEADER_NO_XREF(D3DDevice__m_VertexShader_OFFSET,
                         0)
OOVPA_SIG_MATCH_DUMMY();

// ******************************************************************
// * Direct3D_CreateDevice
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(Direct3D_CreateDevice,
                         3911) // Also for 4361, 4627, 5558, 5659, 5788, 5849, 5933 (NOT 5344!)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x85 },
    { 0x06, 0xC0 },
    { 0x07, 0x75 },
    { 0x08, 0x0A },
    { 0x09, 0xC7 },
    { 0x0A, 0x05 },

    { 0x0F, 0x00 },
    { 0x10, 0x00 },
    { 0x11, 0x08 },
    { 0x12, 0x00 },
    { 0x13, 0xA1 },

    { 0x18, 0x85 },
    { 0x19, 0xC0 },
    { 0x1A, 0x75 },
    { 0x1B, 0x0A },
    { 0x1C, 0xC7 },
    { 0x1D, 0x05 },
    //
);

// ******************************************************************
// * D3DDevice_GetTexture, named with 2 suffix to match EMUPATCH(D3DDevice_GetTexture2)
// ******************************************************************
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_GetTexture2, 3911, 23)
    {
#else
OOVPA_XREF(D3DDevice_GetTexture2, 3911, 1 + 23, // Also for 3948, ?4361?
           XRefOne)
{

    XREF_ENTRY(0x0E, XREF_OFFSET_D3DDevice__m_Textures), // Derived
#endif
        { 0x00, 0x8B },
            { 0x01, 0x44 },
            { 0x02, 0x24 },
            { 0x03, 0x04 },
            { 0x04, 0x8B },
            { 0x05, 0x0D },

            { 0x0A, 0x56 },
            { 0x0B, 0x8D },
            { 0x0C, 0xB4 },
            { 0x0D, 0x81 },
            { 0x0E, 0xA0 }, // GetTexture A00B vs GetPalette B00B
            { 0x0F, 0x0B },
            { 0x10, 0x00 },
            { 0x11, 0x00 },
            { 0x12, 0x8B },
            { 0x13, 0x06 },
            { 0x14, 0x85 },
            { 0x15, 0xC0 },
            { 0x16, 0x74 },

            { 0x18, 0x50 },
            { 0x19, 0xE8 },

            { 0x1E, 0x8B },
            { 0x1F, 0x16 },
    }
OOVPA_END;

// ******************************************************************
// * D3DDevice_SetTexture
// ******************************************************************
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_SetTexture, 3911, 28)
    {
#else
OOVPA_XREF(D3DDevice_SetTexture,
           3911,
           1 + 28,
           XRefOne)
{

    XREF_ENTRY(0x11, XREF_OFFSET_D3DDevice__m_Textures), // Derived
#endif
        { 0x00, 0x51 },
            { 0x01, 0x53 },
            { 0x02, 0x8B },
            { 0x03, 0x5C },
            { 0x04, 0x24 },
            { 0x05, 0x0C },
            { 0x06, 0x55 },
            { 0x07, 0x57 },
            { 0x08, 0x8B },
            { 0x09, 0x3D },

            { 0x0E, 0x8B },
            { 0x0F, 0x84 },
            { 0x10, 0x9F },
            { 0x11, 0xA0 },
            { 0x12, 0x0B },
            { 0x13, 0x00 },
            { 0x14, 0x00 },
            { 0x15, 0x85 },
            { 0x16, 0xC0 },
            { 0x17, 0x89 },
            { 0x18, 0x44 },
            { 0x19, 0x24 },
            { 0x1A, 0x0C },
            { 0x1B, 0x74 },
            { 0x1C, 0x20 },
            { 0x1D, 0x8B },
            { 0x1E, 0x4F },
            { 0x1F, 0x1C },
    }
OOVPA_END;

// ******************************************************************
// * D3DDevice_DrawRectPatch
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DrawRectPatch,
                         3911) // Also verified for 4361, 4627, 5344, 5558, 5659, 5788, 5849, 5933
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x38 },
    { 0x03, 0xA1 },

    { 0x08, 0x8B },
    { 0x09, 0x48 },
    //{ 0x0A, 0x0C }, // 0x08 for 4361 and up
    { 0x0B, 0x53 },
    { 0x0C, 0x55 },
    { 0x0D, 0x56 },
    { 0x0E, 0x57 },
    { 0x0F, 0x8B },
    { 0x10, 0x7C },
    { 0x11, 0x24 },
    { 0x12, 0x50 },
    { 0x13, 0x33 },
    { 0x14, 0xED },
    { 0x15, 0x81 },
    { 0x16, 0xC9 },
    { 0x17, 0x00 },
    { 0x18, 0x08 },
    { 0x19, 0x00 },
    { 0x1A, 0x00 },
    { 0x1B, 0x85 },
    { 0x1C, 0xFF },
    { 0x1D, 0x89 },
    { 0x1E, 0x6C },
    { 0x1F, 0x24 },
    //
);

// ******************************************************************
// * D3DDevice_DrawTriPatch
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DrawTriPatch,
                         3911) // Also verified for 4361, 4627, 5344, 5558, 5659, 5788, 5849, 5933
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x14 },
    { 0x03, 0xA1 },

    { 0x08, 0x8B },
    { 0x09, 0x48 },
    //{ 0x0A, 0x0C }, // 0x08 for 4361 and up
    { 0x0B, 0x53 },
    { 0x0C, 0x55 },
    { 0x0D, 0x56 },
    { 0x0E, 0x57 },
    { 0x0F, 0x8B },
    { 0x10, 0x7C },
    { 0x11, 0x24 },
    { 0x12, 0x2C },
    { 0x13, 0x81 },
    { 0x14, 0xC9 },
    { 0x15, 0x00 },
    { 0x16, 0x08 },
    { 0x17, 0x00 },
    { 0x18, 0x00 },
    { 0x19, 0x33 },
    { 0x1A, 0xDB },
    { 0x1B, 0x85 },
    { 0x1C, 0xFF },
    { 0x1D, 0x89 },
    { 0x1E, 0x44 },
    { 0x1F, 0x24 },
    //
);

// ******************************************************************
// * D3DDevice_CreateVertexShader
// ******************************************************************
// Based on Dxbx patterns for 3911, 4361, 4627, 5344, 5558, 5659, 5788, 5849, 5933
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateVertexShader,
                         3911)
OOVPA_SIG_MATCH(

    // IDirect3DDevice8_CreateVertexShader+0x00 : push ecx; push ebx; push ebp
    { 0x00, 0x51 },
    { 0x01, 0x53 },
    { 0x02, 0x55 },

    { 0x03, 0x8B },
    { 0x04, 0x6C },
    { 0x05, 0x24 },
    { 0x06, 0x14 },
    { 0x07, 0x85 },
    { 0x08, 0xED },
    { 0x09, 0x56 },

    // IDirect3DDevice8_CreateVertexShader+0x0A : jz +0x10
    { 0x0A, 0x74 },
    { 0x0B, 0x10 },

    { 0x0C, 0x0F },
    { 0x0D, 0xB7 },
    { 0x0E, 0x45 },
    { 0x0F, 0x00 },
    { 0x10, 0x0F },
    { 0x11, 0xB7 },
    { 0x12, 0x4D },
    { 0x13, 0x02 },
    { 0x14, 0x89 },
    { 0x15, 0x44 },
    { 0x16, 0x24 },
    { 0x17, 0x0C },
    { 0x18, 0x89 },
    { 0x19, 0x4C },
    { 0x1A, 0x24 },
    { 0x1B, 0x18 },
    { 0x1C, 0x33 },
    { 0x1D, 0xF6 },
    { 0x1E, 0x85 },
    { 0x1F, 0xED },

    // D3DDevice_CreateVertexShader+0x43 : shl eax, 0x02
    { 0x43, 0xC1 },
    { 0x44, 0xE0 },
    { 0x45, 0x02 },

    { 0x46, 0x8D },
    { 0x47, 0x1C },
    { 0x48, 0x30 },
    /*
    OOVPA_NO_XREF(D3DDevice_CreateVertexShader, 5558)
OOVPA_SIG_MATCH(

        // D3DDevice_CreateVertexShader+0x73 : mov eax, 0x8007000E
        { 0x65, 0x07 },
        { 0x66, 0x80 },

        // D3DDevice_CreateVertexShader+0x69 : retn 0x10
        { 0x69, 0xC2 },
        { 0x6A, 0x10 },
*/
    /*
    OOVPA_NO_XREF(D3DDevice_CreateVertexShader, 5788)
OOVPA_SIG_MATCH(

        { 0x3E, 0xE8 },
        { 0x5E, 0x75 },
        { 0x7E, 0x04 },
        { 0x9E, 0x24 },
        { 0xBE, 0x24 },
        { 0xDE, 0x83 },
        { 0xFE, 0xC7 },
*/
    /*
    OOVPA_NO_XREF(D3DDevice_CreateVertexShader, 5849)
OOVPA_SIG_MATCH(

        { 0x3E, 0xE8 },
        { 0x5E, 0x75 },
        { 0x7E, 0x04 },
        { 0x9E, 0x24 },
        { 0xBE, 0x24 },
        { 0xDE, 0x83 },
        { 0xFE, 0xC7 },
*/
    //
);

// ******************************************************************
// * D3DDevice_Release
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// NOTE: LTCG titles may have inlined the function. Therefore need
//       to have end of function inspection.
// TODO: Add signature for a function at offset 0x15, then use it to
//       secure signature a bit better if necessary.
// NOTE2: Function reference at offset 0x15 is also called in
//       Direct3D_CreateDevice function.
OOVPA_SIG_HEADER_XREF(D3DDevice_Release,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // push edi
    OV_MATCH(0x00, 0x57),

    // cmp eax,0x01
    OV_MATCH(0x0D, 0x83, 0xF8, 0x01),
    // jnz +0x??
    OV_MATCH(0x10, 0x75),
    // mov e?x,edi
    OV_MATCH(0x12, 0x8B),
    // call ????
    OV_MATCH(0x14, 0xE8),

    // pop edi
    // ret
    // dec eax
    OV_MATCH(0x2C, 0x5F, 0xC3, 0x48),

    // pop edi
    // ret
    OV_MATCH(0x35, 0x5F, 0xC3),
    //
);

// ******************************************************************
// * D3DDevice_GetDepthStencilSurface
// ******************************************************************
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_GetDepthStencilSurface, 3911, 18)
    {
#else
OOVPA_XREF(D3DDevice_GetDepthStencilSurface,
           3911,
           1 + 18,
           XRefOne)
{

    XREF_ENTRY(0x07, XREF_OFFSET_D3DDevice__m_DepthStencil), // Derived
#endif
        { 0x00, 0xA1 },

            { 0x05, 0x8B },
            { 0x06, 0x80 },

            { 0x09, 0x00 },
            { 0x0A, 0x00 },
            { 0x0B, 0x85 },
            { 0x0C, 0xC0 },
            { 0x0D, 0x8B },
            { 0x0E, 0x4C },
            { 0x0F, 0x24 },
            { 0x10, 0x04 },
            { 0x11, 0x89 },
            { 0x12, 0x01 },
            { 0x13, 0x74 },
            { 0x14, 0x0B },
            { 0x15, 0x50 },
            { 0x16, 0xE8 },

            { 0x1E, 0x04 },
    }
OOVPA_END;

// ******************************************************************
// * D3DDevice_GetGammaRamp
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetGammaRamp,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x8B },

    { 0x0A, 0x00 },
    { 0x0B, 0x56 },
    { 0x0C, 0x8D },
    { 0x0D, 0x0C },
    { 0x0E, 0x49 },
    { 0x0F, 0xC1 },
    { 0x10, 0xE1 },
    { 0x11, 0x08 },

    { 0x16, 0x0C },
    { 0x1C, 0x00 },
    { 0x22, 0x00 },
    { 0x27, 0xC2 },
    //
);

// ******************************************************************
// * D3D_DestroyResource
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3D_DestroyResource,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // D3D_DestroyResource+0x1D : D3D_BlockOnResource
    XREF_ENTRY(0x1E, XREF_D3D_BlockOnResource),

    // D3D_DestroyResource+0x00 : push esi
    OV_MATCH(0x00, 0x56),

    // D3D_DestroyResource+0x06 : mov eax, [edi]
    OV_MATCH(0x06, 0x8B, 0x07), // STD offset 0x06 vs LTCG offset 0x00

    // D3D_DestroyResource+0x0A : and esi, $70000
    OV_MATCH(0x0A, 0x81, 0xE6, 0x00, 0x00, 0x07, 0x00),

    // D3D_DestroyResource+0x10 : cmp esi, $50000
    OV_MATCH(0x10, 0x81, 0xFE, 0x00, 0x00, 0x05, 0x00),

    // D3D_DestroyResource+0x1C : push edi
    OV_MATCH(0x1C, 0x57), // STD push edi vs LTCG mov e__,e__

    // relative to 0x06; STD offset 0x22 vs LTCG offset 0x24
    // D3D_DestroyResource+0x : cmp esi, $50000
    OV_MATCH(0x28, 0x81, 0xFE, 0x00, 0x00, 0x05, 0x00),
    //
);

// ******************************************************************
// * D3D_SetPushBufferSize
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3D_SetPushBufferSize,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x8B },
    { 0x05, 0x4C },
    { 0x06, 0x24 },
    { 0x07, 0x08 },
    { 0x08, 0xA3 },
    { 0x0D, 0x89 },
    { 0x0E, 0x0D },
    { 0x13, 0xC2 },
    { 0x14, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_LightEnable
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_LightEnable,
                      3911, // valid upto at least 4627, next known difference is from 5344 onwards
                      XRefTwo)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x0B, XREF_D3D_g_pDevice), // Derived
    XREF_ENTRY(0x67, XREF_D3DDevice_SetLight),

    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x68 },
    { 0x03, 0x53 },

    { 0x04, 0x8B },
    { 0x05, 0x5C },
    { 0x06, 0x24 },
    { 0x07, 0x70 },
    { 0x08, 0x56 },

    { 0x09, 0x8B },
    { 0x0A, 0x35 },

    { 0x0F, 0x3B },
    { 0x10, 0x9E },
    //{ 0x11, 0x84 }, // 94
    //{ 0x12, 0x04 }, // 03
    { 0x13, 0x00 },

    { 0x14, 0x00 },
    { 0x15, 0x73 },
    { 0x16, 0x13 },
    { 0x17, 0x8B },
    { 0x18, 0x8E },

    //{ 0x19, 0x80 }, // 90
    //{ 0x1A, 0x04 }, // 03
    { 0x1B, 0x00 },
    { 0x1C, 0x00 },
    { 0x1D, 0x8D },
    { 0x1E, 0x04 },
    { 0x1F, 0xDB },
    /*
        { 0x36, 0x00 },
        { 0x52, 0x00 },
        { 0x6E, 0x75 },
        { 0x8A, 0x88 },
        { 0xA6, 0x75 },
        { 0xC2, 0x00 },
*/
    //
);

// ******************************************************************
// * D3DDevice_GetLightEnable
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_GetLightEnable,
                      3911, // valid upto at least 5233, next known difference is from 5344 onwards
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x05, XREF_D3D_g_pDevice), // Derived

    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x02, 0x24 },
    { 0x03, 0x04 },

    { 0x04, 0xA1 },
    { 0x09, 0x8B },
    { 0x0A, 0x90 },
    // 0x0B, 0x80 }, // 0x8004 vs 4134 0x9003
    // 0x0C, 0x04 },

    { 0x0D, 0x00 },
    { 0x0E, 0x00 },
    { 0x0F, 0x8B },
    { 0x10, 0x80 },
    // 0x11, 0x88 }, // 0x8804 vs 4134 0x9803

    // 0x12, 0x04 },
    { 0x13, 0x00 },
    { 0x14, 0x00 },
    { 0x15, 0x8D },
    { 0x16, 0x0C },

    { 0x17, 0xC9 },
    { 0x18, 0xC1 },
    { 0x19, 0xE1 },
    { 0x1A, 0x04 },
    { 0x1B, 0x03 },

    { 0x1C, 0xCA },
    { 0x1D, 0x85 },
    { 0x1E, 0xC0 },
    { 0x1F, 0x74 },
    //
);

// ******************************************************************
// * D3D_ClearStateBlockFlags
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_ClearStateBlockFlags,
                         3911)
OOVPA_SIG_MATCH(

    { 0x01, 0x15 },
    { 0x07, 0x57 },
    { 0x0F, 0xBF },
    { 0x14, 0xF3 },
    { 0x15, 0xAB },
    { 0x16, 0x8B },
    { 0x17, 0x8A },
    //{ 0x18, 0x84 },
    //{ 0x19, 0x04 },
    { 0x1A, 0x00 },
    { 0x1B, 0x00 },
    { 0x1C, 0x33 },
    { 0x1D, 0xF6 },
    { 0x1E, 0x8D },
    { 0x1F, 0x82 },
    //
);

// ******************************************************************
// * D3DDevice_BeginStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_BeginStateBlock,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // D3DDevice_BeginStateBlock+0x0F : call [ClearStateBlockFlags]
    XREF_ENTRY(0x0A, XREF_D3D_ClearStateBlockFlags),

    // D3DDevice_BeginStateBlock+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_BeginStateBlock+0x05 : mov [eax+C], 0x20
    { 0x05, 0x83 },
    { 0x06, 0x48 },
    { 0x07, 0x0C }, //0C VS 08
    { 0x08, 0x20 },
    { 0x09, 0xE9 },
    //
);

// ******************************************************************
// * D3D_RecordStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_RecordStateBlock,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x18 },
    { 0x06, 0x53 },
    { 0x07, 0x56 },

    { 0x0F, 0x8B },
    { 0x1F, 0x89 },

    { 0x37, 0x89 },
    { 0x38, 0x45 },
    { 0x39, 0xEC },
    { 0x3A, 0x8A },
    { 0x3B, 0x02 },
    { 0x3C, 0x42 },
    { 0x3D, 0x84 },
    { 0x3E, 0xC0 },
    { 0x5C, 0xE8 },
    //
);

// ******************************************************************
// * D3DDevice_EndStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_EndStateBlock,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // D3DDevice_EndStateBlock+0x0F : call [ClearStateBlockFlags]
    XREF_ENTRY(0x0A, XREF_D3D_RecordStateBlock),

    // D3DDevice_EndStateBlock+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_EndStateBlock+0x05 : and [eax+0C], 0xFFFFFFDF
    { 0x05, 0x83 },
    { 0x06, 0x60 },
    { 0x07, 0x0C },
    { 0x08, 0xDF },
    //
);

// ******************************************************************
// * CMiniport::InitHardware
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CMiniport_InitHardware,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x0C },
    { 0x06, 0x53 },
    { 0x07, 0x56 },
    { 0x08, 0x8B },
    { 0x09, 0xF1 },
    { 0x0A, 0x56 },
    { 0x0B, 0x68 },

    { 0x10, 0x8D },
    { 0x11, 0x86 },
    { 0x12, 0x88 },
    { 0x13, 0x00 },
    { 0x14, 0x00 },
    { 0x15, 0x00 },
    { 0x16, 0x50 },
    { 0x17, 0xFF },
    { 0x18, 0x15 },

    { 0x1D, 0x80 },
    { 0x1E, 0xA6 },
    { 0x1F, 0xF8 },
    //
);

// ******************************************************************
// * CMiniport::CreateCtxDmaObject
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CMiniport_CreateCtxDmaObject,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x51 },
    { 0x04, 0x51 },
    { 0x05, 0x53 },
    { 0x06, 0x56 },
    { 0x07, 0x57 },
    { 0x08, 0x33 },
    { 0x09, 0xF6 },
    { 0x0A, 0x56 },
    { 0x0B, 0x8D },
    { 0x0C, 0x45 },
    { 0x0D, 0xFC },
    { 0x0E, 0x50 },
    { 0x0F, 0x8D },
    { 0x10, 0x45 },
    { 0x11, 0xF8 },
    { 0x12, 0x50 },
    { 0x13, 0xFF },
    { 0x14, 0x75 },
    { 0x15, 0x10 },
    { 0x16, 0x8B },
    { 0x17, 0xD1 },
    { 0x18, 0x8B },
    { 0x19, 0x3A },
    { 0x1A, 0x89 },
    { 0x1B, 0x75 },
    { 0x1C, 0xF8 },
    { 0x1D, 0x89 },
    { 0x1E, 0x75 },
    { 0x1F, 0xFC },
    //
);

// ******************************************************************
// * D3D_CMiniport_GetDisplayCapabilities
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CMiniport_GetDisplayCapabilities,
                         3911)
OOVPA_SIG_MATCH(

    // D3D_CMiniport_GetDisplayCapabilities+0x00 : xor eax, eax
    { 0x00, 0x33 },
    { 0x01, 0xC0 },
    // D3D_CMiniport_GetDisplayCapabilities+0x02 : cmp ds:_D3D__AvInfo, eax
    { 0x02, 0x39 },
    { 0x03, 0x05 },
    // D3D_CMiniport_GetDisplayCapabilities+0x08 : jne
    { 0x08, 0x75 },
    { 0x09, 0x0f },
    // D3D_CMiniport_GetDisplayCapabilities+0x0A : push #
    { 0x0A, 0x68 },
    // D3D_CMiniport_GetDisplayCapabilities+0x0F : push eax
    { 0x0F, 0x50 },
    // D3D_CMiniport_GetDisplayCapabilities+0x10 : push 6
    { 0x10, 0x6A },
    { 0x11, 0x06 },
    // D3D_CMiniport_GetDisplayCapabilities+0x12 : push eax
    { 0x12, 0x50 },
    // D3D_CMiniport_GetDisplayCapabilities+0x13 : call ds:AvSendTVEncoderOption
    { 0x13, 0xFF },
    { 0x14, 0x15 },
    // D3D_CMiniport_GetDisplayCapabilities+0x19 : mov    eax, #
    { 0x19, 0xA1 },
    // D3D_CMiniport_GetDisplayCapabilities+0x1E : retn
    { 0x1E, 0xC3 },
    //
);

// ******************************************************************
// * D3DBaseTexture_GetLevelCount
// ******************************************************************
/* Accuracy is not gauranteed.
   It might be a ?GetMipmapLevelCount@PixelJar@D3D@@YGKPAUD3DPixelContainer@@@Z
   that has an identical signature... */
OOVPA_SIG_HEADER_NO_XREF(D3DBaseTexture_GetLevelCount,
                         3911)
OOVPA_SIG_MATCH(

    // D3DBaseTexture_GetLevelCount+0x00 : mov eax, [esp+0x04]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },

    // D3DBaseTexture_GetLevelCount+0x04 : movzx eax, [eax+0x0E]
    { 0x04, 0x0F },
    { 0x05, 0xB6 },
    { 0x06, 0x40 },
    { 0x07, 0x0E },

    // D3DBaseTexture_GetLevelCount+0x08 : and eax, 0x0F
    { 0x08, 0x83 },
    { 0x09, 0xE0 },
    { 0x0A, 0x0F },

    // D3DBaseTexture_GetLevelCount+0x0B : retn 0x04
    { 0x0B, 0xC2 },
    { 0x0C, 0x04 },
    //
);

// ******************************************************************
// * D3DCubeTexture_GetCubeMapSurface
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DCubeTexture_GetCubeMapSurface,
                         3911)
OOVPA_SIG_MATCH(

    // sub esp,8
    OV_MATCH(0x00, 0x83, 0xEC, 0x08),

    // mov e??,[esp + 0x10]
    OV_MATCH(0x04, 0x8B),
    OV_MATCH(0x06, 0x24, 0x10),

    // mov e??,[esp + 0x24]
    OV_MATCH(0x17, 0x8B),
    OV_MATCH(0x19, 0x24, 0x24),
    // lea eax,[esp + 0x14]
    OV_MATCH(0x1B, 0x8D),
    OV_MATCH(0x1D, 0x24, 0x14),
    // push eax
    OV_MATCH(0x1F, 0x50),

    // mov e??,[esp + 0x24]
    OV_MATCH(0x20, 0x8B),
    OV_MATCH(0x22, 0x24, 0x24),

    // call ????
    OV_MATCH(0x46, 0xE8),

    // add esp,8
    OV_MATCH(0x4C, 0x83, 0xC4, 0x08),
    // retn 0x10
    OV_MATCH(0x4F, 0xC2, 0x10),
    //
);

// ******************************************************************
// * D3DDevice_GetCreationParameters
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetCreationParameters,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x06, 0x8B },
    { 0x0E, 0x8B },
    { 0x16, 0x4E },
    { 0x1E, 0x83 },
    { 0x26, 0x00 },
    { 0x2E, 0x5E },
    { 0x36, 0xC9 },
    //
);

// ******************************************************************
// * D3DDevice_GetScissors
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetScissors,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x85 },
    { 0x05, 0xC9 },
    { 0x06, 0xA1 },

    { 0x11, 0x00 },
    { 0x18, 0x08 },
    { 0x19, 0x85 },
    { 0x1A, 0xC9 },
    { 0x1B, 0x74 },
    { 0x1C, 0x08 },
    { 0x1D, 0x8B },
    { 0x1E, 0x90 },
    //{ 0x1F, 0x00 },
    //
);

// ******************************************************************
// * D3D::LazySetPointParams
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_LazySetPointParams,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x0A, 0x57 },
    { 0x0B, 0x08 },
    { 0x0C, 0x83 },
    { 0x0D, 0xE2 },
    { 0x0E, 0xFE },
    { 0x0F, 0x57 },
    { 0x10, 0x89 },
    { 0x11, 0x57 },
    { 0x12, 0x08 },
    { 0x13, 0xE8 },
    { 0x37, 0x89 },
    { 0x6E, 0x15 },
    //
);

// ******************************************************************
// * Lock3DSurface
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(Lock3DSurface,
                         3911)
OOVPA_SIG_MATCH(

    // D3D::PixelJar::Lock3DSurface + 0x00: sub esp, 8
    { 0x00, 0x83 },

    // D3D::PixelJar::Lock3DSurface + 0x08: test bl, 0x20
    { 0x08, 0xF6 },
    { 0x09, 0xC3 },
    { 0x0A, 0x20 },

    // D3D::PixelJar::Lock3DSurface + 0x40: test bl, 0x40
    { 0x40, 0xF6 },
    { 0x41, 0xC3 },
    { 0x42, 0x40 },

    // D3D::PixelJar::Lock3DSurface + 0x6D: and edx, 0x3C
    { 0x6D, 0x83 },
    { 0x6E, 0xE2 },
    { 0x6F, 0x3C },

    // D3D::PixelJar::Lock3DSurface + 0x99: ret 0x14
    { 0x99, 0xC2 },
    { 0x9A, 0x14 },
    //
);

// ******************************************************************
// * D3D::CDevice::SetStateUP
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CDevice_SetStateUP,
                         3911)
OOVPA_SIG_MATCH(

    // sub esp,0x??
    OV_MATCH(0x00, 0x83, 0xEC),

    // call ????
    OV_MATCH(0x0A, 0xE8),

    // and eax,0xFFFFFEFF
    OV_MATCH(0x1B, 0x25, 0xFF, 0xFE, 0xFF, 0xFF),

    // or eax,0x80
    OV_MATCH(0x21, 0x0D, 0x80, 0x00, 0x00),
    //
);

// ******************************************************************
// * D3D::CDevice::SetStateVB
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CDevice_SetStateVB,
                         3911)
OOVPA_SIG_MATCH(

    // push ecx
    OV_MATCH(0x00, 0x51),

    // call ????
    OV_MATCH(0x08, 0xE8),

    // test eax,0x40000000
    OV_MATCH(0x10, 0xA9, 0x00, 0x00, 0x00, 0x40),

    // and eax,0xBFFFFF7F
    OV_MATCH(0x2C, 0x25, 0x7F, 0xFF, 0xFF, 0xBF),
    // or eax,0x300
    OV_MATCH(0x31, 0x0D, 0x00, 0x03, 0x00 /*, 0x00*/),
    //
);

// ******************************************************************
// * Direct3D_CheckDeviceMultiSampleType
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(Direct3D_CheckDeviceMultiSampleType,
                         3911)
OOVPA_SIG_MATCH(

    { 0x0E, 0x00 },
    { 0x1E, 0x54 },
    { 0x2E, 0xC9 },
    { 0x3E, 0x8B },
    { 0x4E, 0x08 },
    { 0x5E, 0x72 },
    { 0x6E, 0x03 },
    //
);

// ******************************************************************
// * D3DDevice_GetOverlayUpdateStatus
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetOverlayUpdateStatus,
                         3911) // Also for 4134, 4361, 4627, 5344, 5558, 5788, 5849
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x8B },
    { 0x06, 0x88 },
    //{ 0x07, 0x88 },
    //{ 0x08, 0x2A },
    { 0x09, 0x00 },

    //{ 0x0E, 0x5C },
    //{ 0x0F, 0x24 },
    { 0x10, 0x00 },
    { 0x11, 0x00 },
    { 0x12, 0x33 },
    { 0x13, 0xD2 },
    { 0x14, 0x3B },
    //{ 0x15, 0xCE }, // F1 vs CE

    { 0x16, 0x0F },
    { 0x17, 0x95 },
    { 0x18, 0xC2 },
    { 0x19, 0x5E },
    { 0x1A, 0x8B },
    { 0x1B, 0xC2 },
    { 0x1C, 0xC3 },
    //
);

// ******************************************************************
// * D3D_CheckDeviceFormat
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_CheckDeviceFormat,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x0E, 0x18 },
    { 0x1E, 0x00 },
    { 0x2E, 0x42 },
    { 0x41, 0x40 },
    { 0x4E, 0x74 },
    { 0x5E, 0x08 },
    { 0x6E, 0x3C },
    //
);
// ******************************************************************
// * D3DDevice_EnableOverlay
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_EnableOverlay,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },

    { 0x09, 0x8B },
    { 0x0A, 0x80 },
    { 0x0B, 0x04 },
    { 0x0C, 0x04 },
    { 0x0D, 0x00 },
    { 0x0E, 0x00 },
    { 0x0F, 0x33 },
    { 0x10, 0xC9 },
    { 0x11, 0x3B },
    { 0x12, 0xD1 },
    { 0x13, 0x74 },
    { 0x14, 0x0A },
    { 0x15, 0x39 },
    { 0x16, 0x88 },
    { 0x17, 0x00 },
    { 0x18, 0x87 },
    { 0x19, 0x00 },
    { 0x1A, 0x00 },
    { 0x1B, 0x75 },
    { 0x1C, 0xF8 },
    { 0x1D, 0xEB },
    { 0x1E, 0x0A },
    { 0x1F, 0xC7 },
    //
);

// ******************************************************************
// * D3DDevice_UpdateOverlay
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_UpdateOverlay,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0x08 },
    { 0x1F, 0x7C },
    { 0x6F, 0x8B },

    { 0x80, 0x8B },
    { 0x81, 0x54 },
    { 0x82, 0x24 },
    { 0x83, 0x20 },
    { 0x84, 0x8B },
    { 0x85, 0x3F },
    { 0x86, 0x83 },
    { 0x87, 0xE1 },
    //
);

// ******************************************************************
// * D3DDevice_SetTextureState_TexCoordIndex
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetTextureState_TexCoordIndex,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x11, XREF_D3DTSS_TEXCOORDINDEX), // Derived

    // D3DDevice_SetTextureState_TexCoordIndex+0x00 : mov ecx, [esp+arg_4]
    { 0x00, 0x8B },

    // D3DDevice_SetTextureState_TexCoordIndex+0x0B : shl eax, 0x07
    { 0x0B, 0xC1 },
    { 0x0C, 0xE0 },
    { 0x0D, 0x07 },

    // D3DDevice_SetTextureState_TexCoordIndex+0x24 : cmp eax, 0x20000
    { 0x24, 0x81 },
    { 0x25, 0xF9 },
    { 0x28, 0x02 },

    // D3DDevice_SetTextureState_TexCoordIndex+0x3B : mov edi, 0x8511
    { 0x3B, 0xBF },
    { 0x3C, 0x11 },
    { 0x3D, 0x85 },

    // D3DDevice_SetTextureState_TexCoordIndex+0x97 : shl eax, cl
    { 0x97, 0xD3 },
    { 0x98, 0xE0 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_CullMode
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_CullMode,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),
    // mov [D3DRS_CullMode],e??
    XREF_ENTRY(0x25, XREF_D3DRS_CullMode),

    // push esi
    OV_MATCH(0x00, 0x56),

    // unique
    // mov [eax],0x40308
    OV_MATCH(0x13, 0xC7, 0x00, 0x08, 0x03, 0x04, 0x00),
    // jnz +0x??
    OV_MATCH(0x19, 0x75),
    //
);

// ******************************************************************
// * D3DDevice_RunPushBuffer
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_RunPushBuffer,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x05, 0x1D },

    { 0x0A, 0x55 },
    { 0x0B, 0x56 },
    { 0x0C, 0x57 },
    { 0x0D, 0x6A },
    { 0x0E, 0x00 },
    { 0x0F, 0x8B },
    { 0x10, 0xCB },
    { 0x11, 0xE8 },

    { 0x1A, 0x83 },
    { 0x23, 0x8B },
    //
);

// ******************************************************************
// * D3DDevice_IsBusy
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_IsBusy,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x12, 0x49 },

    { 0x20, 0xB8 },
    { 0x21, 0x01 },
    { 0x22, 0x00 },
    { 0x23, 0x00 },
    { 0x24, 0x00 },
    { 0x25, 0xC3 },
    { 0x26, 0x8B },
    { 0x27, 0x92 },

    { 0x33, 0xC3 },
    //
);

// ******************************************************************
// * D3DDevice_GetDeviceCaps
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetDeviceCaps,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_GetDeviceCaps+0x00 : push esi; push edi
    { 0x00, 0x56 },
    { 0x01, 0x57 },

    // D3DDevice_GetDeviceCaps+0x06 : mov ecx, 0x35
    { 0x06, 0xB9 },
    { 0x07, 0x35 },
    { 0x08, 0x00 },
    { 0x09, 0x00 },
    { 0x0A, 0x00 },

    // D3DDevice_GetDeviceCaps+0x10 : rep movsd
    { 0x10, 0xF3 },
    { 0x11, 0xA5 },

    // D3DDevice_GetDeviceCaps+0x14 : retn 0x04
    { 0x14, 0xC2 },
    { 0x15, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_BeginVisibilityTest
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_BeginVisibilityTest,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // push esi
    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x00, 0x56, 0x8B, 0x35),

    // mov ecx,1
    OV_MATCH(0x0D, 0xB9, 0x01, 0x00),
    // mov [eax],0x000817C8
    OV_MATCH(0x12, 0xC7, 0x00, 0xC8, 0x17, 0x08, 0x00),

    // add eax,0x0C
    OV_MATCH(0x1E, 0x83, 0xC0, 0x0C),

    // ret
    OV_MATCH(0x24, 0xC3),
    //
);

// ******************************************************************
// * D3DDevice_GetMaterial
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetMaterial,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x56 },
    { 0x06, 0x57 },
    { 0x0A, 0x0C },
    { 0x0C, 0xB0 },
    { 0x0D, 0x18 },
    { 0x0E, 0x0B },
    { 0x11, 0xB9 },
    { 0x16, 0xF3 },
    { 0x1A, 0xC2 },
    //
);

// ******************************************************************
// * D3DDevice_EndVisibilityTest
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_EndVisibilityTest,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x06, 0xE8 },

    { 0x0B, 0x8B },
    { 0x0C, 0xF0 },
    { 0x0D, 0x85 },
    { 0x0E, 0xF6 },
    { 0x0F, 0x75 },
    { 0x10, 0x09 },
    { 0x11, 0xB8 },
    { 0x12, 0x0E },
    { 0x13, 0x00 },
    { 0x14, 0x07 },
    { 0x15, 0x80 },
    { 0x16, 0x5E },
    { 0x17, 0xC2 },
    { 0x18, 0x04 },
    { 0x19, 0x00 },
    { 0x1A, 0x57 },
    { 0x1B, 0x8B },
    { 0x1C, 0x3D },

    { 0x37, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_GetVisibilityTestResult
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVisibilityTestResult,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_GetVisibilityTestResult+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_GetVisibilityTestResult+0x0C : shr ecx, 8
    { 0x0C, 0xC1 },
    { 0x0D, 0xE9 },
    { 0x0E, 0x08 },

    // D3DDevice_GetVisibilityTestResult+0x0F : and eax, 0xFF
    { 0x0F, 0x25 },
    { 0x10, 0xFF },
    { 0x11, 0x00 },

    // D3DDevice_GetVisibilityTestResult+0x2B : mov eax, 0x88760828
    { 0x2B, 0xB8 },
    { 0x2C, 0x28 },
    { 0x2D, 0x08 },
    { 0x2E, 0x76 },
    { 0x2F, 0x88 },
    //
);

// ******************************************************************
// * D3D::CDevice::KickOff
// ******************************************************************
OOVPA_SIG_HEADER_XREF(CDevice_KickOff,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(
    // mov eax, [D3D_g_pDevice]
    XREF_ENTRY(0x1F, XREF_D3D_g_pDevice),

    // push ecx
    // mov eax, [addr]
    OV_MATCH(0x00, 0x51, 0xA1),

    // test byte ptr [ecx + 0xC], 0x04
    // jz eip + 8
    OV_MATCH(0x0E, 0xF6, 0x41, 0x0C, 0x04, 0x74, 0x08),

    // mov eax, [D3D_g_pDevice]
    OV_MATCH(0x1E, 0xA1),

    // ret
    OV_MATCH(0x69, 0xC3),
    //
);

// ******************************************************************
// * D3DDevice_LoadVertexShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_LoadVertexShader,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_LoadVertexShader+0x00 : push ebx
    { 0x00, 0x53 },

    // D3DDevice_LoadVertexShader+0x07 : mov al, [ebx+0x0C]
    { 0x07, 0x8A },
    { 0x08, 0x43 },
    { 0x09, 0x0C },

    // D3DDevice_LoadVertexShader+0x3D : mov dword ptr [eax], 0x00041E9C
    { 0x3D, 0xC7 },
    { 0x3E, 0x00 },
    { 0x3F, 0x9C },
    { 0x40, 0x1E },
    { 0x41, 0x04 },

    // D3DDevice_LoadVertexShader+0x4E : mov [ebx], ebx
    { 0x4E, 0x89 },
    { 0x4F, 0x13 },
    //
);

// ******************************************************************
// * D3DDevice_SelectVertexShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SelectVertexShader,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SelectVertexShader+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_SelectVertexShader+0x16 : or ecx, 0x3A0
    { 0x16, 0x81 },
    { 0x17, 0xC9 },
    { 0x18, 0xA0 },
    { 0x19, 0x03 },

    // D3DDevice_SelectVertexShader+0x3F : mov dword ptr [eax], 0x00081E94
    { 0x3F, 0xC7 },
    { 0x40, 0x00 },
    { 0x41, 0x94 },
    { 0x42, 0x1E },
    { 0x43, 0x08 },

    // D3DDevice_SelectVertexShader+0x51 : mov [esi], eax
    { 0x51, 0x89 },
    { 0x52, 0x06 },
    //
);

// ******************************************************************
// * D3DDevice_BlockUntilVerticalBlank
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_BlockUntilVerticalBlank,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // D3DDevice_BlockUntilVerticalBlank+0x00 : mov eax, [D3D_g_pDevice]
    XREF_ENTRY(0x01, XREF_D3D_g_pDevice),

    // D3DDevice_BlockUntilVerticalBlank+0x17 : add eax, OFFSET_D3DDevice__m_VerticalBlankEvent
    XREF_ENTRY(0x18, XREF_D3DDevice__m_VerticalBlankEvent_OFFSET),

    // D3DDevice_BlockUntilVerticalBlank+0x00 : mov eax,[D3D_g_pDevice]
    OV_MATCH(0x00, 0xA1),

    // D3DDevice_BlockUntilVerticalBlank+0x05 : push 0; push 0; push 1
    OV_MATCH(0x05, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x01),

    // D3DDevice_BlockUntilVerticalBlank+0x0B : mov dword ptr [eax+OFFSET_D3DDEVICE_M_???],
    OV_MATCH(0x0B, 0xC7, 0x80),

    // D3DDevice_BlockUntilVerticalBlank+0x15 : push 6
    OV_MATCH(0x15, 0x6A, 0x06),

    // D3DDevice_BlockUntilVerticalBlank+0x17 : add eax, OFFSET_D3DDevice__m_VerticalBlankEvent
    OV_MATCH(0x17, 0x05),

    // D3DDevice_BlockUntilVerticalBlank+0x1D : call [KeWaitForSingleObject]
    OV_MATCH(0x1D, 0xFF, 0x15),

    // D3DDevice_BlockUntilVerticalBlank+0x23 : ret
    OV_MATCH(0x23, 0xC3), // NOTE: LTCG doesn't have a ret here and is extended function.

    //
);

// ******************************************************************
// * D3DDevice_SetVerticalBlankCallback
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetVerticalBlankCallback,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // D3DDevice_SetVerticalBlankCallback+0x04 : mov ecx,[D3D_g_pDevice]
    XREF_ENTRY(0x06, XREF_D3D_g_pDevice),

    // D3DDevice_SetVerticalBlankCallback+0x0A : mov [ecx+OFFSET_D3DDevice__m_VBlankCallback],eax
    XREF_ENTRY(0x0C, XREF_D3DDevice__m_VBlankCallback_OFFSET),

    // D3DDevice_SetVerticalBlankCallback+0x00 : mov eax,[esp+0x04]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // D3DDevice_SetVerticalBlankCallback+0x0A : mov [ecx+OFFSET_D3DDevice__m_VBlankCallback],eax
    OV_MATCH(0x0A, 0x89, 0x81),

    // D3DDevice_SetVerticalBlankCallback+0x10 : retn 0x04
    OV_MATCH(0x10, 0xC2, 0x04, 0x00),

    //
);

// ******************************************************************
// * D3DDevice_SetRenderTarget
// ******************************************************************
// NOTE: Signature is not compatible with LTCG
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_SetRenderTarget, 3911, 11)
    {
#else
OOVPA_XREF(D3DDevice_SetRenderTarget,
           3911,
           1 + 11,
           XRefOne)
{

    XREF_ENTRY(0x17, XREF_OFFSET_D3DDevice__m_RenderTarget), // Derived
#endif
        // D3DDevice_SetRenderTarget+0x00 : sub esp, 0x20
        OV_MATCH(0x00, 0x83, 0xEC),

            // D3DDevice_SetRenderTarget+0x50 : mov esi, 0x00000001
            OV_MATCH(0x50, 0xBE, 0x01, 0x00),

            // D3DDevice_SetRenderTarget+0x55 : and ecx, 0x0F
            OV_MATCH(0x55, 0x83, 0xE1, 0x0F),

            // D3DDevice_SetRenderTarget+0x60 : shr eax,0x0C
            OV_MATCH(0x60, 0xC1, 0xE8, 0x0C),
    }
OOVPA_END;

// ******************************************************************
// * D3DSurface_GetDesc
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DSurface_GetDesc,
                         3911)
OOVPA_SIG_MATCH(

    // D3DSurface_GetDesc+0x00 : mov eax, [esp+0x08]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x08 },

    // D3DSurface_GetDesc+0x04 : mov ecx, [esp+0x04]
    { 0x04, 0x8B },
    { 0x05, 0x4C },
    { 0x06, 0x24 },
    { 0x07, 0x04 },

    // D3DSurface_GetDesc+0x08 : push eax
    { 0x08, 0x50 },

    // D3DSurface_GetDesc+0x09 : push 0
    { 0x09, 0x6A },
    { 0x0A, 0x00 },

    // D3DSurface_GetDesc+0x0B : push ecx
    { 0x0B, 0x51 },

    // D3DSurface_GetDesc+0x0C : call [abs]
    { 0x0C, 0xE8 },

    // D3DSurface_GetDesc+0x11 : retn 0x08
    { 0x11, 0xC2 },
    { 0x12, 0x08 },
    { 0x13, 0x00 },

    //
);

// ******************************************************************
// * D3DDevice_GetTransform
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetTransform,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_GetTransform+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_GetTransform+0x06 : mov esi, [esp+4+arg_0]
    { 0x06, 0x8B },
    { 0x07, 0x74 },
    { 0x08, 0x24 },

    // D3DDevice_GetTransform+0x12 : shl esi, 6; add esi, eax
    { 0x12, 0xC1 },
    { 0x13, 0xE6 },
    { 0x14, 0x06 },
    { 0x15, 0x03 },
    { 0x16, 0xF0 },

    // D3DDevice_GetTransform+0x17 : mov ecx, 0x10
    { 0x17, 0xB9 },
    { 0x18, 0x10 },

    // D3DDevice_GetTransform+0x20 : retn 0x08
    { 0x20, 0xC2 },
    { 0x21, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetStreamSource
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetStreamSource,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x23, XREF_D3D_g_Stream_i_pVertexBuffer), // Derived
    XREF_ENTRY(0x53, XREF_D3D_g_Stream), // Derived

    // D3DDevice_SetStreamSource+0x00 : push ebx
    { 0x00, 0x53 },

    // D3DDevice_SetStreamSource+0x39 : add edx, 0xFFF80000
    { 0x39, 0x81 },
    { 0x3A, 0xC2 },
    { 0x3B, 0x00 },
    { 0x3C, 0x00 },
    { 0x3D, 0xF8 },
    { 0x3E, 0xFF },

    // D3DDevice_SetStreamSource+0x49 : jnz +0x06
    { 0x49, 0x75 },
    { 0x4A, 0x06 },

    // D3DDevice_SetStreamSource+0x6A : or ecx, 0x280
    { 0x6A, 0x81 },
    { 0x6B, 0xC9 },
    { 0x6C, 0x80 },
    { 0x6D, 0x02 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexShader
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetVertexShader,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x12, XREF_D3DDevice__m_VertexShader_OFFSET), // Derived

    // D3DDevice_SetVertexShader+0x00 : push ebx
    { 0x00, 0x53 },

    // D3DDevice_SetVertexShader+0x05 : test bl, 1
    { 0x05, 0xF6 },
    { 0x06, 0xC3 },
    { 0x07, 0x01 },

    // D3DDevice_SetVertexShader+0x10 : mov eax, [esi+0x0470]
    { 0x10, 0x8B },
    { 0x11, 0x86 },
    { 0x12, 0x70 },
    { 0x13, 0x04 },

    // D3DDevice_SetVertexShader+0x6D : retn 0x04
    { 0x6D, 0xC2 },
    { 0x6E, 0x04 },

    // D3DDevice_SetVertexShader+0x8C : mov dword ptr [eax], 0x81E94
    { 0x8C, 0xC7 },
    { 0x8D, 0x40 },
    { 0x8E, 0x08 },
    { 0x8F, 0x94 },
    { 0x90, 0x1E },
    //
);

// ******************************************************************
// * D3DDevice_CreatePixelShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreatePixelShader,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreatePixelShader+0x00 : push 0xFC
    { 0x00, 0x68 },
    { 0x01, 0xFC },

    // D3DDevice_CreatePixelShader+0x10 : mov eax, 0x8007000E
    { 0x10, 0xB8 },
    { 0x11, 0x0E },
    { 0x12, 0x00 },
    { 0x13, 0x07 },
    { 0x14, 0x80 },

    // D3DDevice_CreatePixelShader+0x31 : mov ecx, 0x3C
    { 0x31, 0xB9 },
    { 0x32, 0x3C },

    // D3DDevice_CreatePixelShader+0x42 : retn 0x08
    { 0x42, 0xC2 },
    { 0x43, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetPixelShader
// ******************************************************************
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_SetPixelShader, 3911, 11)
    {
#else
OOVPA_XREF(D3DDevice_SetPixelShader,
           3911,
           1 + 11,
           XRefOne)
{

    XREF_ENTRY(0x10, XREF_OFFSET_D3DDevice__m_PixelShader), // Derived
#endif
        // D3DDevice_SetPixelShader+0x00 : mov eax, [esp+arg_0]
        { 0x00, 0x8B },

            // D3DDevice_SetPixelShader+0x0E : mov esi, [ebx+0x0414]
            { 0x0E, 0x8B },
            { 0x0F, 0xB3 },
            { 0x10, 0x14 }, // part of an offset
            { 0x11, 0x04 },

            // D3DDevice_SetPixelShader+0x34 : or eax, 0x40
            { 0x35, 0xC8 },
            { 0x36, 0x40 },

            // D3DDevice_SetPixelShader+0x68 : retn 0x04
            { 0x68, 0xC2 },
            { 0x69, 0x04 },

            // D3DDevice_SetPixelShader+0xE3 : rep movsd
            { 0xE3, 0xF3 },
            { 0xE4, 0xA5 },
    }
OOVPA_END;

// ******************************************************************
// * D3DDevice_SetIndices
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetIndices,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetIndices+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetIndices+0x0E : jz +0x10
    { 0x0E, 0x74 },
    { 0x0F, 0x10 },

    // D3DDevice_SetIndices+0x3E : test ecx, 0x78FFFF
    { 0x3E, 0xF7 },
    { 0x3F, 0xC1 },
    { 0x40, 0xFF },
    { 0x41, 0xFF },
    { 0x42, 0x78 },

    // D3DDevice_SetIndices+0x67 : mov [esi+0x047C], edi
    { 0x67, 0x89 },
    { 0x68, 0xBE },
    { 0x69, 0x7C },
    { 0x6A, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetViewport
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetViewport,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetViewport+0x00 : sub esp, 0x08
    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x08 },

    // D3DDevice_SetViewport+0x2F : mov ebx, [esp+0x1C]
    { 0x2F, 0x8B },
    { 0x30, 0x5C },
    { 0x31, 0x24 },
    { 0x32, 0x1C },

    // D3DDevice_SetViewport+0x55 : jnz +0x12
    { 0x55, 0x75 },
    { 0x56, 0x12 },

    // D3DDevice_SetViewport+0x9D : inc edx
    { 0x9D, 0x42 },
    //
);

// ******************************************************************
// * D3DDevice_DrawIndexedVertices
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_DrawIndexedVertices,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x0A, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateVB
    XREF_ENTRY(0x1C, XREF_D3D_CDevice_SetStateVB),

    // push ebp
    OV_MATCH(0x00, 0x55),

    // sub esp,0x08
    OV_MATCH(0x03, 0x83, 0xEC, 0x08),

    // mov e??,[D3D_g_pDevice]
    OV_MATCH(0x08, 0x8B),

    // mov [ebp - 8],esi
    OV_MATCH(0x18, 0x89, 0x75, 0xF8),
    // call D3D::CDevice::SetStateVB
    OV_MATCH(0x1B, 0xE8),
    // Do not use any offsets after 0x1F
);

// ******************************************************************
// * D3DDevice_Begin
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_Begin,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_Begin+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_Begin+0x20 : mov dword ptr [eax], 0x417FC
    { 0x20, 0xC7 },
    { 0x21, 0x00 },
    { 0x22, 0xFC },
    { 0x23, 0x17 },
    { 0x24, 0x04 },
    { 0x25, 0x00 },

    // D3DDevice_Begin+0x2E : shl edx, 6
    { 0x2E, 0x0D },
    { 0x2F, 0x00 },
    { 0x30, 0x08 },

    // D3DDevice_Begin+0x38 : retn 0x08
    { 0x38, 0xC2 },
    { 0x39, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexData2f
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetVertexData2f,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // push esi
    OV_MATCH(0x00, 0x56),
    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x01, 0x8B, 0x35),

    // lea edx,[ecx * 8 + 0x81880]
    OV_MATCH(0x11, 0x8D, 0x14, 0xCD, 0x80, 0x18, 0x08, 0x00),

    // add eax,0x0C
    OV_MATCH(0x28, 0x83, 0xC0, 0x0C),

    // retn 0x0C
    OV_MATCH(0x2E, 0xC2, 0x0C),
    //
);

// ******************************************************************
// * D3DDevice_SetVertexData2s
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexData2s,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetVertexData2f+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetVertexData2s+0x11 : lea edx, ds:abs[ecx*4]
    { 0x11, 0x8D },
    { 0x12, 0x14 },
    { 0x13, 0x8D },

    // D3DDevice_SetVertexData2s+0x24 : shl ecx, 0x10
    { 0x24, 0xC1 },
    { 0x25, 0xE1 },
    { 0x26, 0x10 },

    // D3DDevice_SetVertexData2s+0x29 : mov [eax+4], ecx
    { 0x29, 0x89 },
    { 0x2A, 0x48 },
    { 0x2B, 0x04 },

    // D3DDevice_SetVertexData2s+0x32 : retn 0x0C
    { 0x32, 0xC2 },
    { 0x33, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexData4f
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexData4f,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetVertexData4f+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetVertexData4f+0x11 : cmp ecx, -1; jnz +0x07
    { 0x11, 0x83 },
    { 0x12, 0xF9 },
    { 0x13, 0xFF },
    { 0x14, 0x75 },
    { 0x15, 0x07 },

    // D3DDevice_SetVertexData4f+0x1D : add ecx, 0x01A0
    { 0x1D, 0x81 },
    { 0x1E, 0xC1 },
    { 0x1F, 0xA0 },
    { 0x20, 0x01 },

    // D3DDevice_SetVertexData4f+0x50 : retn 0x14
    { 0x50, 0xC2 },
    { 0x51, 0x14 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexDataColor
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexDataColor,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetVertexDataColor+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetVertexDataColor+0x1F : mov byte ptr [esp+?]
    { 0x1F, 0x0F },
    { 0x20, 0xB6 },
    { 0x21, 0x54 },
    { 0x22, 0x24 },
    { 0x23, 0x12 },

    // D3DDevice_SetVertexDataColor+0x26 : add edi, 0xFF; shl edi, 0x10
    { 0x26, 0x81 },
    { 0x27, 0xE7 },
    { 0x28, 0xFF },
    { 0x2C, 0xC1 },
    { 0x2D, 0xE7 },
    { 0x2E, 0x10 },

    // D3DDevice_SetVertexDataColor+0x31 : and ecx, 0xFF00FF00
    { 0x31, 0x81 },
    { 0x32, 0xE1 },
    { 0x33, 0x00 },
    { 0x34, 0xFF },
    { 0x35, 0x00 },
    { 0x36, 0xFF },
    //
);

// ******************************************************************
// * D3DDevice_End
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_End,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_End+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_End+0x17 : mov dword ptr [eax], 0x417FC
    { 0x17, 0xC7 },
    { 0x18, 0x00 },
    { 0x19, 0xFC },
    { 0x1A, 0x17 },
    { 0x1B, 0x04 },
    { 0x1C, 0x00 },

    // D3DDevice_End+0x2C : test ah, 0x10
    { 0x2C, 0xF6 },
    { 0x2D, 0xC4 },
    { 0x2E, 0x10 },

    // D3DDevice_End+0x2F : jz +0x07
    { 0x2F, 0x74 },
    { 0x30, 0x07 },

    // D3DDevice_End+0x40 : retn
    { 0x40, 0xC3 },
    //
);

// ******************************************************************
// * D3DDevice_Clear
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_Clear,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_Clear+0x00 : sub esp, 0x38
    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x38 },

    // D3DDevice_Clear+0x25 : test cl, 1
    { 0x25, 0xF6 },
    { 0x26, 0xC1 },
    { 0x27, 0x01 },

    // D3DDevice_Clear+0x5D : mov [esi], eax; xor ebp, ebp
    { 0x5D, 0x89 },
    { 0x5E, 0x06 },
    { 0x5F, 0x33 },
    { 0x60, 0xED },
    //
);

// ******************************************************************
// * D3DDevice_CreatePalette
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreatePalette,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreatePalette+0x01 : push 0x0C
    { 0x01, 0x6A },
    { 0x02, 0x0C },

    // D3DDevice_CreatePalette+0x03 : push 0x40
    { 0x03, 0x6A },
    { 0x04, 0x40 },

    // D3DDevice_CreatePalette+0x10 : mov eax, 0x8007000E
    { 0x10, 0xB8 },
    { 0x11, 0x0E },
    { 0x12, 0x00 },
    { 0x13, 0x07 },
    { 0x14, 0x80 },

    // D3DDevice_CreatePalette+0x4E : shl esi, 0x1E
    { 0x4E, 0xC1 },
    { 0x4F, 0xE6 },
    { 0x50, 0x1E },
    //
);

// ******************************************************************
// * D3DDevice_SetPalette
// ******************************************************************
#ifndef WIP_LessVertexPatching
OOVPA_NO_XREF(D3DDevice_SetPalette, 3911, 12)
    {
#else
OOVPA_XREF(D3DDevice_SetPalette,
           3911,
           1 + 12,
           XRefOne)
{

    XREF_ENTRY(0x10, XREF_OFFSET_D3DDevice__m_Palettes), // Derived verified on 3911
#endif
        // D3DDevice_SetPalette+0x0D : mov eax, [edi+esi*4+0x0BB0]
        { 0x0D, 0x8B },
            { 0x0E, 0x84 },
            { 0x0F, 0xB7 },
            { 0x10, 0xB0 }, // part of an offset
            { 0x11, 0x0B },

            // D3DDevice_SetPalette+0x68 : add esi, 0x41B20
            { 0x68, 0x81 },
            { 0x69, 0xC6 },
            { 0x6A, 0x20 },
            { 0x6B, 0x1B },
            { 0x6C, 0x04 },

            // D3DDevice_SetPalette+0x7C : retn 0x08
            { 0x7C, 0xC2 },
            { 0x7D, 0x08 },
    }
OOVPA_END;

// ******************************************************************
// * D3DDevice_CreateTexture
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateTexture,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreateTexture+0x00 : mov eax, [esp+0x1C]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x1C },

    // D3DDevice_CreateTexture+0x0C : push eax
    { 0x0C, 0x50 },

    // D3DDevice_CreateTexture+0x11 : push 0
    { 0x11, 0x6A },
    { 0x12, 0x00 },

    // D3DDevice_CreateTexture+0x13 : push 0
    { 0x13, 0x6A },
    { 0x14, 0x00 },

    // D3DDevice_CreateTexture+0x15 : push ecx
    { 0x15, 0x51 },

    // D3DDevice_CreateTexture+0x22 : push ecx
    { 0x22, 0x51 },

    // D3DDevice_CreateTexture+0x23 : push edx
    { 0x23, 0x52 },

    // D3DDevice_CreateTexture+0x29 : retn 0x1C
    { 0x29, 0xC2 },
    { 0x2A, 0x1C },
    //
);

// ******************************************************************
// * D3DDevice_CreateVolumeTexture
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateVolumeTexture,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreateVolumeTexture+0x00 : mov eax, [esp+0x1C]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x20 },

    // D3DDevice_CreateVolumeTexture+0x0C : push eax
    { 0x0C, 0x50 },

    // D3DDevice_CreateVolumeTexture+0x11 : push 1
    { 0x11, 0x6A },
    { 0x12, 0x01 },

    // D3DDevice_CreateVolumeTexture+0x13 : push 0
    { 0x13, 0x6A },
    { 0x14, 0x00 },

    // D3DDevice_CreateVolumeTexture+0x16 : mov ecx, [esp+0x1C]
    { 0x16, 0x8B },
    { 0x17, 0x4C },
    { 0x18, 0x24 },
    { 0x19, 0x1C },

    // D3DDevice_CreateVolumeTexture+0x2C : retn 0x20
    { 0x2C, 0xC2 },
    { 0x2D, 0x20 },
    //
);

// ******************************************************************
// * D3DDevice_CreateCubeTexture
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateCubeTexture,
                         3911)
OOVPA_SIG_MATCH(

    // mov eax,[esp + 0x1C]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x18),

    // push eax
    OV_MATCH(0x0C, 0x50),

    // push 0
    // push 1
    OV_MATCH(0x11, 0x6A, 0x00, 0x6A, 0x01),

    // mov eax,[esp + 0x1C]
    OV_MATCH(0x18, 0x8B, 0x44, 0x24, 0x1C),

    // retn 0x18
    OV_MATCH(0x25, 0xC2, 0x18),
    //
);

// ******************************************************************
// * D3DDevice_CreateIndexBuffer
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateIndexBuffer,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreateIndexBuffer+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_CreateIndexBuffer+0x13 : mov eax, 0x8007000E
    { 0x13, 0xB8 },
    { 0x14, 0x0E },
    { 0x15, 0x00 },
    { 0x16, 0x07 },
    { 0x17, 0x80 },

    // D3DDevice_CreateIndexBuffer+0x18 : retn 0x14
    { 0x18, 0xC2 },
    { 0x19, 0x14 },

    // D3DDevice_CreateIndexBuffer+0x2E : mov dword ptr [eax], 0x1010001
    { 0x2E, 0xC7 },
    { 0x2F, 0x00 },
    { 0x30, 0x01 },
    { 0x31, 0x00 },
    { 0x32, 0x01 },
    { 0x33, 0x01 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexShaderConstant
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexShaderConstant,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetVertexShaderConstant+0x00 : push ebp
    { 0x00, 0x55 },

    // D3DDevice_SetVertexShaderConstant+0x11 : mov cl, [ebx+0x0C]
    { 0x11, 0x8A },
    { 0x12, 0x4B },
    { 0x13, 0x0C },

    // D3DDevice_SetVertexShaderConstant+0x1A : test cl, 0x10
    { 0x1A, 0xF6 },
    { 0x1B, 0xC1 },
    { 0x1C, 0x10 },

    // D3DDevice_SetVertexShaderConstant+0x63 : jle +0x19
    { 0x63, 0x7E },
    { 0x64, 0x19 },

    // D3DDevice_SetVertexShaderConstant+0x9B : retn 0x0C
    { 0x9B, 0xC2 },
    { 0x9C, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_SetFlickerFilter
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetFlickerFilter,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetFlickerFilter+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_SetFlickerFilter+0x0A : mov edx, [ecx+0x2308]
    { 0x0A, 0x8B },
    { 0x0B, 0x91 },
    { 0x0C, 0x08 },
    { 0x0D, 0x23 },

    // D3DDevice_SetFlickerFilter+0x10 : push 0; push eax; push 0x0B; push edx
    { 0x10, 0x6A },
    { 0x11, 0x00 },
    { 0x12, 0x50 },
    { 0x13, 0x6A },
    { 0x14, 0x0B },
    { 0x15, 0x52 },

    // D3DDevice_SetFlickerFilter+0x1C : retn 0x08
    { 0x1C, 0xC2 },
    { 0x1D, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetSoftDisplayFilter
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetSoftDisplayFilter,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetSoftDisplayFilter+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_SetSoftDisplayFilter+0x0A : mov edx, [ecx+0x2308]
    { 0x0A, 0x8B },
    { 0x0B, 0x91 },
    { 0x0C, 0x08 },
    { 0x0D, 0x23 },

    // D3DDevice_SetSoftDisplayFilter+0x10 : push 0; push eax; push 0x0E; push edx
    { 0x10, 0x6A },
    { 0x11, 0x00 },
    { 0x12, 0x50 },
    { 0x13, 0x6A },
    { 0x14, 0x0E },
    { 0x15, 0x52 },

    // D3DDevice_SetSoftDisplayFilter+0x1C : retn 0x08
    { 0x1C, 0xC2 },
    { 0x1D, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetTextureState_BorderColor
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetTextureState_BorderColor,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetTextureState_BorderColor+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetTextureState_BorderColor+0x13 : shl eax, 0x07
    { 0x13, 0xC1 },
    { 0x14, 0xE2 },
    { 0x15, 0x06 },

    // D3DDevice_SetTextureState_BorderColor+0x16 : add edx, 0x41B24
    { 0x16, 0x81 },
    { 0x17, 0xC2 },
    { 0x18, 0x24 },
    { 0x19, 0x1B },
    { 0x1A, 0x04 },

    // D3DDevice_SetTextureState_BorderColor+0x2A : shl ecx, 7
    { 0x2A, 0xC1 },
    { 0x2B, 0xE1 },
    { 0x2C, 0x07 },

    // D3DDevice_SetTextureState_BorderColor+0x34 : retn 0x08
    { 0x34, 0xC2 },
    { 0x35, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_PSTextureModes
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_PSTextureModes,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov eax,[D3D_g_pDevice]
    XREF_ENTRY(0x01, XREF_D3D_g_pDevice),

    // mov [D3DRS_PSTextureModes],e??
    XREF_ENTRY(0x1D, XREF_D3DRS_PSTextureModes),

    // mov eax,[D3D_g_pDevice]
    OV_MATCH(0x00, 0xA1),

    // or edx,0x400
    OV_MATCH(0x0C, 0x81, 0xCA, 0x00, 0x04),

    // mov [D3DRS_PSTextureModes],e??
    OV_MATCH(0x1B, 0x89),

    // retn 4
    OV_MATCH(0x21, 0xC2, 0x04),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_StencilFail
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_StencilFail,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // mov [D3DRS_StencilFail],e??
    XREF_ENTRY(0x61, XREF_D3DRS_StencilFail),

    // push esi
    OV_MATCH(0x00, 0x56),
    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x01, 0x8B, 0x35),

    // mov [e??],0x40370
    OV_MATCH(0x51, 0xC7),
    OV_MATCH(0x53, 0x70, 0x03, 0x04, 0x00),

    // mov [D3DRS_StencilFail],e??
    OV_MATCH(0x5F, 0x89),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_Simple
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_Simple,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_Simple+0x00 : mov eax, [D3D__DEVICE]
    OV_MATCH(0x00, 0xA1),

    // D3DDevice_SetRenderState_Simple+0x05 : add eax, 0x08
    OV_MATCH(0x05, 0x83, 0xC0, 0x08),

    // Unique offset
    // D3DDevice_SetRenderState_Simple+0x15 : mov [eax-8], ecx
    OV_MATCH(0x15, 0x89, 0x48, 0xF8),

    // Unique offset
    // D3DDevice_SetRenderState_Simple+0x18 : mov [eax-4], ecx
    OV_MATCH(0x18, 0x89, 0x50, 0xFC),

    // D3DDevice_SetRenderState_Simple+0x1C : push edx; push ecx
    OV_MATCH(0x1C, 0x52, 0x51),

    // Offset 0x1E and later has shift forward in 4034
    //
);

// ******************************************************************
// * D3DDevice_SetTransform
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetTransform,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // mov ebx,[D3D_g_pDevice]
    XREF_ENTRY(0x0B, XREF_D3D_g_pDevice), // Derived

    // mov eax, [esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // mov edx, [esp + param_2]
    OV_MATCH(0x04, 0x8B, 0x54, 0x24, 0x08),
    // push ebx
    // mov ebx,[D3D_g_pDevice]
    OV_MATCH(0x08, 0x53),
    OV_MATCH(0x09, 0x8B, 0x1D),

    // lea edi, [param_1 + 0x22]
    OV_MATCH(0x11, 0x8D, 0x78 /*, 0x22*/), // 3911 0x22 vs 5344 0x21 value
    // shl edi,0x6
    OV_MATCH(0x14, 0xC1, 0xE7, 0x06),

    // mov ecx,0x10
    OV_MATCH(0x19, 0xB9, 0x10, 0x00 /*, 0x00, 0x00*/),
    //
);

// ******************************************************************
// * D3D::UpdateProjectionViewportTransform
// ******************************************************************
// NOTE: 4034 signature is detected in NASACAR Heat 2002 (LTCG title), compiled with 3925 build.
// For now, use 39XX as signature revision for this symbol.
OOVPA_SIG_HEADER_XREF(D3D_UpdateProjectionViewportTransform,
                      3900,
                      XRefOne)
OOVPA_SIG_MATCH(
    // mov e??, XREF_D3D_g_pDevice
    XREF_ENTRY(0x0C, XREF_D3D_g_pDevice), // Derived

    // and  esp, 0FFFFFFF0h
    // sub  esp, 58h
    OV_MATCH(0x03, 0x83, 0xE4, 0xF0, 0x83, 0xEC, 0x58),

    // Start of assembly code group since anything afterward does change over time.
    // mov e??,
    OV_MATCH(0x0A, 0x8B),
    // mov eax, [e?? + 0x?]
    OV_MATCH(0x10, 0x8B),
    // fild [ e?? + 0x?]
    OV_MATCH(0x16, 0xDB),

    // jge +0x06
    OV_MATCH(0x1F, 0x7D, 0x06),
    //
);

// ******************************************************************
// * D3DDevice_MultiplyTransform
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_MultiplyTransform,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xE4 },
    { 0x05, 0xF0 },

    { 0x12, 0x56 },
    { 0x13, 0x8B },
    { 0x14, 0x75 },
    { 0x15, 0x0C },
    { 0x16, 0x57 },
    { 0x17, 0xB9 },
    { 0x18, 0x10 },

    { 0x4D, 0xC2 },
    { 0x4E, 0x08 },
    { 0x4F, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_FogColor
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_FogColor,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_FogColor+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_FogColor+0x2E : mov dword ptr [eax], 0x402A8
    { 0x2E, 0xC7 },
    { 0x2F, 0x00 },
    { 0x30, 0xA8 },
    { 0x31, 0x02 },
    { 0x32, 0x04 },
    { 0x33, 0x00 },

    // D3DDevice_SetRenderState_FogColor+0x37 : add eax, 0x08
    { 0x37, 0x83 },
    { 0x38, 0xC0 },
    { 0x39, 0x08 },

    // D3DDevice_SetRenderState_FogColor+0x44 : retn 0x04
    { 0x44, 0xC2 },
    { 0x45, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_FillMode
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_FillMode,
                      3911,
                      XRefThree)
OOVPA_SIG_MATCH(

    // mov ecx,ptr [D3DRS_TwoSidedLighting]
    XREF_ENTRY(0x0F, XREF_D3DRS_TwoSidedLighting),
    // mov edx,ptr [D3DRS_BackFillMode]
    XREF_ENTRY(0x15, XREF_D3DRS_BackFillMode),
    // mov ptr [D3DRS_FillMode],ecx
    XREF_ENTRY(0x36, XREF_D3DRS_FillMode),

    // push esi
    OV_MATCH(0x00, 0x56),

    // mov ecx,ptr [D3DRS_TwoSidedLighting]
    OV_MATCH(0x0D, 0x8B),

    // mov edx,ptr [D3DRS_BackFillMode]
    OV_MATCH(0x13, 0x8B),

    // mov ptr [eax],0x008038C
    OV_MATCH(0x23, 0xC7, 0x00, 0x8C, 0x03, 0x08, 0x00),

    // add eax,0x0C
    OV_MATCH(0x2F, 0x83, 0xC0, 0x0C),

    // mov ptr [D3DRS_FillMode],ecx
    OV_MATCH(0x34, 0x89),

    // retn 0x04
    OV_MATCH(0x3B, 0xC2, 0x04),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_StencilEnable
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_StencilEnable,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // mov [D3DRS_StencilEnable],e??
    XREF_ENTRY(0x78, XREF_D3DRS_StencilEnable),

    // push esi
    OV_MATCH(0x00, 0x56),
    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x01, 0x8B, 0x35),

    // mov [e??],0x4032C
    OV_MATCH(0x68, 0xC7),
    OV_MATCH(0x6A, 0x2C, 0x03, 0x04, 0x00),

    // mov [D3DRS_StencilEnable],e??
    OV_MATCH(0x76, 0x89),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_Dxt1NoiseEnable
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// NOTE: D3DRS_Dxt1NoiseEnable is referenced at end of the function,
//       therefore will require additional OOVPA signatures. This
//       signature is currently the best generic version.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_Dxt1NoiseEnable,
                         3911)
OOVPA_SIG_MATCH(

    // push ebx
    OV_MATCH(0x00, 0x53),
    // mov ebx,[esp + 0x??]
    OV_MATCH(0x01, 0x8B),

    // push esi
    OV_MATCH(0x05, 0x56),

    // and dl, 0x3C
    OV_MATCH(0x1D, 0x80, 0xE2, 0x3C),

    // cmp dl, 0x20
    OV_MATCH(0x22, 0x80, 0xFA, 0x20),

    // and ecx,0x01
    OV_MATCH(0x2E, 0x83, 0xE1, 0x01),

    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_ZBias
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// NOTE: D3DRS_ZBias is referenced at end of the function,
//       therefore will require additional OOVPA signatures. This
//       signature is currently the best generic version.
// NOTE2: Above note include LTCG's titles detection.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_ZBias,
                         3911)
OOVPA_SIG_MATCH(
    // push ecx
    // push esi
    OV_MATCH(0x00, 0x51, 0x56),

    // setnz al
    OV_MATCH(0x0B, 0x0F, 0x95, 0xC0),

    // fild [esp + param_1]
    OV_MATCH(0x14, 0xDB, 0x44, 0x24, 0x10),

    // jge +0x06
    OV_MATCH(0x1A, 0x7D, 0x06),
    // fadd [0x????????]
    OV_MATCH(0x1C, 0xD8, 0x05),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_ZEnable
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_ZEnable,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_ZEnable+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_ZEnable+0x13 : jz +0x11
    { 0x13, 0x74 },
    { 0x14, 0x11 },

    // D3DDevice_SetRenderState_ZEnable+0x15 : mov edx, [esi+0x0410]
    { 0x15, 0x8B },
    { 0x16, 0x96 },
    { 0x17, 0x10 },
    { 0x18, 0x04 },

    // D3DDevice_SetRenderState_ZEnable+0x28 : mov dword ptr [eax], 0x4030
    { 0x28, 0xC7 },
    { 0x29, 0x00 },
    { 0x2A, 0x0C },
    { 0x2B, 0x03 },
    { 0x2C, 0x04 },

    // D3DDevice_SetRenderState_ZEnable+0x69 : retn 0x04
    { 0x69, 0xC2 },
    { 0x6A, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_Present
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_Present,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_Present+0x00 : sub esp, 8
    { 0x00, 0x83 },

    // D3DDevice_Present+0x0A : push 2
    { 0x0A, 0x6A },
    { 0x0B, 0x02 },

    // D3DDevice_Present+0x11 : mov eax, [esi+2518]
    { 0x11, 0x8B },
    { 0x12, 0x86 },
    { 0x13, 0x18 },
    { 0x14, 0x25 },

    // D3DDevice_Present+0xBE : shr ebx, 1
    { 0xBE, 0xD1 },
    { 0xBF, 0xEB },

    // D3DDevice_Present+0xC0 : xor edi, edi
    { 0xC0, 0x33 },
    { 0xC1, 0xFF },
    //
);

// ******************************************************************
// * D3DDevice_SetShaderConstantMode
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetShaderConstantMode,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x09, XREF_D3D_g_pDevice),

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // test al,0x10
    OV_MATCH(0x04, 0xA8, 0x10),

    // mov e??,[D3D_g_pDevice]
    OV_MATCH(0x07, 0x8B),

    // or ecx,0x200
    OV_MATCH(0x12, 0x81, 0xC9, 0x00, 0x02, 0x00, 0x00),
    // Offset 0x32 and later had change over time.
);

// ******************************************************************
// * D3DDevice_GetBackBuffer
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetBackBuffer,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_GetBackBuffer+0x00 : mov eax, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DDevice_GetBackBuffer+0x04 : cmp eax, 0xFFFFFFFF
    { 0x04, 0x83 },
    { 0x05, 0xF8 },
    { 0x06, 0xFF },

    // D3DDevice_GetBackBuffer+0x0D : jnz +0x07
    { 0x0D, 0x75 },
    { 0x0E, 0x07 },

    // D3DDevice_GetBackBuffer+0x1E : lea eax, [ecx+eax*8+0x2150]
    { 0x1E, 0x8D },
    { 0x1F, 0x84 },
    { 0x20, 0xC1 },
    { 0x21, 0x50 },
    { 0x22, 0x21 },

    // D3DDevice_GetBackBuffer+0x31 : retn 0x0C
    { 0x31, 0xC2 },
    { 0x32, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_GetRenderTarget
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_GetRenderTarget,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov eax,[D3D_g_pDevice]
    XREF_ENTRY(0x01, XREF_D3D_g_pDevice),

    // TODO: Uncomment when WIP_LessVertexPatching is defined
    // XREF_ENTRY(0x07, XREF_OFFSET_D3DDevice__m_RenderTarget), // Derived

    // call D3DResource_AddRef
    XREF_ENTRY(0x17, XREF_D3DResource_AddRef),

    // mov eax,[D3D_g_pDevice]
    OV_MATCH(0x00, 0xA1),

    // mov eax,[eax + OFFSET_D3DDevice__m_RenderTarget]
    OV_MATCH(0x05, 0x8B, 0x80),

    // test eax,eax
    OV_MATCH(0x0B, 0x85, 0xC0),
    // mov ecx,[esp + param_1]
    OV_MATCH(0x0D, 0x8B, 0x4C, 0x24, 0x04),
    // mov [ecx],eax
    OV_MATCH(0x11, 0x89, 0x01),
    // jz +0x06
    OV_MATCH(0x13, 0x74, 0x06),
    // push eax
    OV_MATCH(0x15, 0x50),
    // call D3DResource_AddRef
    OV_MATCH(0x16, 0xE8),

    // retn 0x04
    OV_MATCH(0x1D, 0xC2, 0x04),
    //
);

// ******************************************************************
// * D3DDevice_CreateVertexBuffer
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateVertexBuffer,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_CreateVertexBuffer+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_CreateVertexBuffer+0x03 : push 0x40
    { 0x03, 0x6A },
    { 0x04, 0x40 },

    // D3DDevice_CreateVertexBuffer+0x10 : mov eax, [esp+8]
    { 0x10, 0x8B },
    { 0x11, 0x44 },
    { 0x12, 0x24 },
    { 0x13, 0x08 },

    // D3DDevice_CreateVertexBuffer+0x48 : mov dword ptr [esi], 0x01000001
    { 0x48, 0xC7 },
    { 0x49, 0x06 },
    { 0x4A, 0x01 },
    { 0x4B, 0x00 },
    { 0x4D, 0x01 },

    // D3DDevice_CreateVertexBuffer+0x53 : retn 0x14
    { 0x53, 0xC2 },
    { 0x54, 0x14 },
    //
);

// ******************************************************************
// * D3DVertexBuffer_Lock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DVertexBuffer_Lock,
                         3911)
OOVPA_SIG_MATCH(

    // D3DVertexBuffer_Lock+0x01 : mov bl, [esp+0x18]
    { 0x01, 0x8A },
    { 0x02, 0x5C },
    { 0x03, 0x24 },
    { 0x04, 0x18 },

    // D3DVertexBuffer_Lock+0x09 : jnz +0x24
    { 0x09, 0x75 },
    { 0x0A, 0x1E },

    // D3DVertexBuffer_Lock+0x29 : test bl, 0xA0
    { 0x29, 0xF6 },
    { 0x2A, 0xC3 },
    { 0x2B, 0xA0 },

    // D3DVertexBuffer_Lock+0x4A : retn 0x14
    { 0x4A, 0xC2 },
    { 0x4B, 0x14 },
    //
);

// ******************************************************************
// * D3DResource_Register
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DResource_Register,
                         3911)
OOVPA_SIG_MATCH(

    // D3DResource_Register+0x00 : mov ecx, [esp+0x04]
    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x03, 0x04 },

    // D3DResource_Register+0x04 : mov edx, [esp+0x08]
    { 0x04, 0x8B },
    { 0x05, 0x54 },
    { 0x07, 0x08 },

    // D3DResource_Register+0x08 : mov eax, [ecx+0x04]
    { 0x08, 0x8B },
    { 0x09, 0x41 },
    { 0x0A, 0x04 },

    // D3DResource_Register+0x0F : and edx, 0x00070000
    { 0x0F, 0x81 },
    { 0x10, 0xE2 },
    { 0x13, 0x07 },

    // D3DResource_Register+0x15 : cmp edx, 0x00020000
    { 0x15, 0x81 },
    { 0x16, 0xFA },
    { 0x19, 0x02 },

    // D3DResource_Register+0x1B : jnz +0x05
    { 0x1B, 0x74 },
    { 0x1C, 0x05 },

    // D3DResource_Register+0x25 : retn 0x08
    { 0x25, 0xC2 },
    { 0x26, 0x08 },
    //
);

// ******************************************************************
// * D3DResource_Release
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DResource_Release,
                         3911)
OOVPA_SIG_MATCH(

    // D3DResource_Release+0x00 : push esi
    { 0x00, 0x56 },

    // D3DResource_Release+0x09 : and ecx, 0xFFFF
    { 0x09, 0x81 },
    { 0x0A, 0xE1 },
    { 0x0B, 0xFF },
    { 0x0C, 0xFF },

    // D3DResource_Release+0x14 : and eax, 0x00070000
    { 0x14, 0x25 },
    { 0x17, 0x07 },

    // D3DResource_Release+0x19 : cmp eax, 0x00050000
    { 0x19, 0x3D },
    { 0x1C, 0x05 },

    // D3DResource_Release+0x3E : pop esi
    { 0x3E, 0x5E },

    // D3DResource_Release+0x4B : retn 0x04
    { 0x4B, 0xC2 },
    { 0x4C, 0x04 },
    //
);

// ******************************************************************
// * D3DResource_AddRef
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DResource_AddRef,
                         3911)
OOVPA_SIG_MATCH(

    // D3DResource_AddRef+0x00 : push esi
    { 0x00, 0x56 },

    // D3DResource_AddRef+0x07 : test eax, 0xFFFF
    { 0x07, 0xA9 },
    { 0x08, 0xFF },
    { 0x09, 0xFF },

    // D3DResource_AddRef+0x0E : and eax, 0x00070000
    { 0x0E, 0x25 },
    { 0x11, 0x07 },

    // D3DResource_AddRef+0x13 : cmp eax, 0x00050000
    { 0x13, 0x3D },
    { 0x16, 0x05 },

    // D3DResource_AddRef+0x33 : pop esi
    { 0x33, 0x5E },

    // D3DResource_AddRef+0x34 : retn 0x04
    { 0x34, 0xC2 },
    { 0x35, 0x04 },
    //
);

// ******************************************************************
// * D3DResource_IsBusy
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DResource_IsBusy,
                         3911)
OOVPA_SIG_MATCH(

    // D3DResource_IsBusy+0x00 : mov ecx, [esp+arg_0]
    { 0x00, 0x8B },

    // D3DResource_IsBusy+0x24 : test eax, 0x780000
    { 0x24, 0xA9 },
    { 0x25, 0x00 },
    { 0x26, 0x00 },
    { 0x27, 0x78 },

    // D3DResource_IsBusy+0x35 : jnz +0x44
    { 0x35, 0x75 },
    { 0x36, 0x44 },

    // D3DResource_IsBusy+0x4E : mov eax, [ecx+0x14]
    { 0x4E, 0x8B },
    { 0x4F, 0x41 },
    { 0x50, 0x14 },

    // D3DResource_IsBusy+0x79 : jnb +0x09
    { 0x79, 0x73 },
    { 0x7A, 0x09 },
    //
);

// ******************************************************************
// * D3DSurface_LockRect
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DSurface_LockRect,
                         3911)
OOVPA_SIG_MATCH(

    // D3DSurface_LockRect+0x00 : mov eax, [esp+0x10]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x10 },

    // D3DSurface_LockRect+0x04 : mov ecx, [esp+0x0C]
    { 0x04, 0x8B },
    { 0x05, 0x4C },
    { 0x06, 0x24 },
    { 0x07, 0x0C },

    // D3DSurface_LockRect+0x0C : push eax
    { 0x0C, 0x50 },

    // D3DSurface_LockRect+0x11 : push ecx; push edx; push 0; push 0
    { 0x11, 0x51 },
    { 0x12, 0x52 },
    { 0x13, 0x6A },
    { 0x15, 0x6A },

    // D3DSurface_LockRect+0x18 : call [abs]
    { 0x18, 0xE8 },

    // D3DSurface_LockRect+0x11 : retn 0x10
    { 0x1D, 0xC2 },
    { 0x1E, 0x10 },
    //
);

// ******************************************************************
// * D3DPalette_Lock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DPalette_Lock,
                         3911)
OOVPA_SIG_MATCH(

    // D3DPalette_Lock+0x00 : test [esp+0x0C], 0xA0
    { 0x00, 0xF6 },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x0C },
    { 0x04, 0xA0 },

    // D3DPalette_Lock+0x0A : jnz +0x06
    { 0x0A, 0x75 },
    { 0x0B, 0x06 },

    // D3DPalette_Lock+0x18 : mov ecx, [esp+0x0C]
    { 0x18, 0x8B },
    { 0x19, 0x4C },
    { 0x1A, 0x24 },
    { 0x1B, 0x0C },

    // D3DPalette_Lock+0x1C : mov [ecx], eax
    { 0x1C, 0x89 },
    { 0x1D, 0x01 },
    //
);

// ******************************************************************
// * D3DTexture_LockRect
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DTexture_LockRect,
                         3911)
OOVPA_SIG_MATCH(

    // D3DTexture_LockRect+0x00 : mov eax, [esp+0x14]
    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x14 },

    // D3DTexture_LockRect+0x04 : mov ecx, [esp+0x10]
    { 0x04, 0x8B },
    { 0x05, 0x4C },
    { 0x06, 0x24 },
    { 0x07, 0x10 },

    // D3DTexture_LockRect+0x0C : push eax, push ecx, push edx, push eax, push 0
    { 0x0C, 0x50 },
    { 0x11, 0x51 },
    { 0x16, 0x52 },
    { 0x17, 0x50 },
    { 0x18, 0x6A },
    { 0x19, 0x00 },

    // D3DTexture_LockRect+0x1B : call [addr]
    { 0x1B, 0xE8 },

    // D3DTexture_LockRect+0x20 : retn 0x14
    { 0x20, 0xC2 },
    { 0x21, 0x14 },
    //
);

// ******************************************************************
// * D3DVolumeTexture_LockBox
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DVolumeTexture_LockBox,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x01, XREF_D3D8_Lock3DSurface),

    { 0x00, 0xE9 },
    //
);

// ******************************************************************
// * D3DCubeTexture_LockRect
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DCubeTexture_LockRect,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x01, XREF_D3D8_Lock2DSurface),

    { 0x00, 0xE9 },
    //
);

// ******************************************************************
// * D3DTexture_GetSurfaceLevel
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DTexture_GetSurfaceLevel,
                         3911)
OOVPA_SIG_MATCH(

    // D3DTexture_GetSurfaceLevel+0x08 : lea [esp+0x14]
    { 0x08, 0x8D },
    { 0x0B, 0x14 },

    // D3DTexture_GetSurfaceLevel+0x17 : mov edx, [esp+0x24]
    { 0x17, 0x8B },
    { 0x1A, 0x24 },

    // D3DTexture_GetSurfaceLevel+0x20 : lea ecx, [esp+0x28]
    { 0x23, 0x28 },

    // D3DTexture_GetSurfaceLevel+0x24 : push ecx
    { 0x24, 0x51 },

    // D3DTexture_GetSurfaceLevel+0x25 : push edx
    { 0x25, 0x52 },

    // D3DTexture_GetSurfaceLevel+0x26 : push 0
    { 0x26, 0x6A },

    // D3DTexture_GetSurfaceLevel+0x43 : call [abs]
    { 0x43, 0xE8 },

    // D3DTexture_GetSurfaceLevel+0x4C : retn 0x0C
    { 0x4C, 0xC2 },
    { 0x4D, 0x0C },
    //
);

// ******************************************************************
// * Lock2DSurface
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(Lock2DSurface,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x51 },
    { 0x06, 0xF6 },
    { 0x07, 0xC3 },
    { 0x08, 0x20 },

    { 0x3F, 0xF6 },
    { 0x40, 0xC3 },
    { 0x41, 0x40 },

    { 0x71, 0xC1 },
    { 0x72, 0xEA },
    { 0x73, 0x03 },

    { 0x98, 0xC2 },
    { 0x99, 0x18 },
    //
);

// ******************************************************************
// * Get2DSurfaceDesc
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(Get2DSurfaceDesc,
                         3911)
OOVPA_SIG_MATCH(

    // Get2DSurfaceDesc+0x2B : sub esp, 8
    { 0x00, 0x83 },

    // Get2DSurfaceDesc+0x2B : movzx edx, byte ptr [edi+0x0D]
    { 0x2B, 0x0F },
    { 0x2C, 0xB6 },
    { 0x2D, 0x57 },
    { 0x2E, 0x0D },

    // Get2DSurfaceDesc+0x56 : cmp eax, [edx+0x2154]
    { 0x56, 0x3B },
    { 0x57, 0x82 },
    { 0x58, 0x54 },
    { 0x59, 0x21 },

    // Get2DSurfaceDesc+0xAE : retn 0x0C
    { 0xAE, 0xC2 },
    { 0xAF, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderSize
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderSize,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x08 },

    { 0x08, 0x8B },
    { 0x09, 0x4C },
    { 0x0A, 0x24 },
    { 0x0B, 0x04 },

    { 0x0C, 0x8B },
    { 0x0D, 0x51 },
    //{ 0x0E, 0x07 }, 0F vs 07

    { 0x11, 0xC2 },
    { 0x12, 0x08 },
    /*
        { 0x01, 0x44 },
        { 0x04, 0x85 },
        { 0x07, 0x09 },
        { 0x0A, 0x24 },
        { 0x0D, 0x51 },
        { 0x10, 0x10 },
        { 0x13, 0x00 },*/
    //
);

// ******************************************************************
// * D3DDevice_SetGammaRamp
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetGammaRamp,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetGammaRamp+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_SetGammaRamp+0x11 : and eax, 1; push ebx
    { 0x11, 0x83 },
    { 0x12, 0xE0 },
    { 0x13, 0x01 },
    { 0x14, 0x53 },

    // D3DDevice_SetGammaRamp+0x2F : rep movsd
    { 0x2F, 0xF3 },
    { 0x30, 0xA5 },

    // D3DDevice_SetGammaRamp+0x3E : push ebx; mov ecx, edx
    { 0x3E, 0x53 },
    { 0x3F, 0x8B },
    { 0x40, 0xCA },
    //
);

// ******************************************************************
// * D3DDevice_SetMaterial
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetMaterial,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetMaterial+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_SetMaterial+0x0B : lea edi, [eax+0xB18]
    { 0x0B, 0x8D },
    { 0x0C, 0xB8 },
    { 0x0D, 0x18 },
    { 0x0E, 0x0B },

    // D3DDevice_SetMaterial+0x11 : mov ecx, 0x11
    { 0x11, 0xB9 },
    { 0x12, 0x11 },

    // D3DDevice_SetMaterial+0x1C : or ecx, 0x20
    { 0x1B, 0x83 },
    { 0x1C, 0xC9 },
    { 0x1D, 0x20 },

    // D3DDevice_SetMaterial+0x23 : retn 0x04
    { 0x23, 0xC2 },
    { 0x24, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_AddRef
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_AddRef,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_AddRef+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_AddRef+0x05 : mov ecx, [eax+0x0408]
    { 0x05, 0x8B },
    { 0x06, 0x88 },
    { 0x07, 0x08 },
    { 0x08, 0x04 },

    // D3DDevice_AddRef+0x0B : inc ecx
    { 0x0B, 0x41 },

    // D3DDevice_AddRef+0x05 : mov [eax+0x0408], ecx
    { 0x0C, 0x89 },
    { 0x0D, 0x88 },
    { 0x0E, 0x08 },
    { 0x0F, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_GetViewport
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetViewport,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x0C, 0xB0 },

    { 0x0F, 0x00 },
    { 0x10, 0x00 },
    { 0x11, 0xB9 },
    { 0x12, 0x06 },
    { 0x13, 0x00 },
    { 0x14, 0x00 },
    { 0x15, 0x00 },
    { 0x16, 0xF3 },
    { 0x17, 0xA5 },
    { 0x18, 0x5F },
    { 0x19, 0x5E },
    { 0x1A, 0xC2 },
    { 0x1B, 0x04 },
    { 0x1C, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_GetDisplayFieldStatus
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetDisplayFieldStatus,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x09, 0x00 },
    { 0x0A, 0x00 },
    { 0x0B, 0x8B },
    { 0x0C, 0x4C },
    { 0x0D, 0x24 },
    { 0x0E, 0x04 },
    { 0x0F, 0x89 },
    { 0x10, 0x51 },
    { 0x11, 0x04 },
    { 0x12, 0xF7 },

    { 0x1C, 0x74 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_MultiSampleAntiAlias
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_MultiSampleAntiAlias,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_MultiSampleAntiAlias],eax
    XREF_ENTRY(0x0E, XREF_D3DRS_MultiSampleAntiAlias),

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x05, 0x8B, 0x35),

    // mov [D3DRS_MultiSampleAntiAlias],eax
    OV_MATCH(0x0D, 0xA3), // 4627 0x0E vs 0x0D
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_VertexBlend
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_VertexBlend,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_VertexBlend+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_VertexBlend+0x0A : or ecx, 2
    { 0x0A, 0x83 },
    { 0x0B, 0xC9 },
    { 0x0C, 0x02 },

    // D3DDevice_SetRenderState_VertexBlend+0x1A : mov dword ptr [eax], 0x40328
    { 0x1A, 0xC7 },
    { 0x1B, 0x00 },
    { 0x1C, 0x28 },
    { 0x1D, 0x03 },
    { 0x1E, 0x04 },

    // D3DDevice_SetRenderState_VertexBlend+0x23 : add eax, 8
    { 0x23, 0x83 },
    { 0x24, 0xC0 },
    { 0x25, 0x08 },

    // D3DDevice_SetRenderState_VertexBlend+0x2F : retn 0x04
    { 0x2F, 0xC2 },
    { 0x30, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_BackFillMode
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_BackFillMode,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,ptr [D3DRS_FillMode]
    XREF_ENTRY(0x07, XREF_D3DRS_FillMode),
    // mov [D3DRS_BackFillMode],eax
    XREF_ENTRY(0x14, XREF_D3DRS_BackFillMode),

    // mov eax, [esp+arg_0]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // mov esi,ptr [D3DRS_FillMode]
    OV_MATCH(0x05, 0x8B),

    // mov [D3DRS_BackFillMode],eax
    OV_MATCH(0x13, 0xA3),

    // add eax, 0x0C
    OV_MATCH(0x3B, 0x83, 0xC0, 0x0C),

    // retn 0x04
    OV_MATCH(0x48, 0xC2, 0x04),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_TwoSidedLighting
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_TwoSidedLighting,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov eax,[D3D_g_pDevice]
    XREF_ENTRY(0x01, XREF_D3D_g_pDevice),

    // mov [D3DRS_TwoSidedLighting],eax
    XREF_ENTRY(0x1D, XREF_D3DRS_TwoSidedLighting),

    // mov eax,[D3D_g_pDevice]
    OV_MATCH(0x00, 0xA1),

    // mov e??,[esp + param_1]
    OV_MATCH(0x0A, 0x8B),

    // mov e??,[D3DRS_FillMode]
    OV_MATCH(0x0E, 0x8B),

    // mov [D3DRS_TwoSidedLighting],eax
    OV_MATCH(0x1C, 0xA3),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_NormalizeNormals
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_NormalizeNormals,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_NormalizeNormals+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_NormalizeNormals+0x1D : mov [esi], eax
    { 0x1D, 0x89 },
    { 0x1E, 0x06 },

    // D3DDevice_SetRenderState_NormalizeNormals+0x1F : or dword ptr [esi+8], 2
    { 0x1F, 0x83 },
    { 0x20, 0x4E },
    { 0x21, 0x08 },
    { 0x22, 0x02 },

    // D3DDevice_SetRenderState_NormalizeNormals+0x2A : retn 0x04
    { 0x2A, 0xC2 },
    { 0x2B, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_FrontFace
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_FrontFace,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // mov [D3DRS_FrontFace],e??
    XREF_ENTRY(0x26, XREF_D3DRS_FrontFace),

    // push esi
    // mov esi,[D3D_g_pDevice]
    OV_MATCH(0x00, 0x56, 0x8B, 0x35),

    // add eax,0x08
    OV_MATCH(0x1A, 0x83, 0xC0, 0x08),

    // mov [D3DRS_FrontFace],e??
    OV_MATCH(0x24, 0x89),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_TextureFactor
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_TextureFactor,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_TextureFactor+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_TextureFactor+0x07 : mov eax, [esi+0x0414]
    { 0x07, 0x8B },
    { 0x08, 0x86 },
    { 0x09, 0x14 },
    { 0x0A, 0x04 },

    // D3DDevice_SetRenderState_TextureFactor+0x2E : rep stosd
    { 0x2E, 0xF3 },
    { 0x2F, 0xAB },

    // D3DDevice_SetRenderState_TextureFactor+0x3C : retn 0x04
    { 0x3C, 0xC2 },
    { 0x3D, 0x04 },

    // D3DDevice_SetRenderState_TextureFactor+0x49 : retn 0x04
    { 0x49, 0xC2 },
    { 0x4A, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_LogicOp
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_LogicOp,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),
    // mov [D3DRS_LogicOp],e??
    XREF_ENTRY(0x25, XREF_D3DRS_LogicOp),

    // push esi
    OV_MATCH(0x00, 0x56),

    // jnz +0x??
    OV_MATCH(0x13, 0x75),
    // unique
    // mov [eax],0x417bc
    OV_MATCH(0x15, 0xC7, 0x00, 0xBC, 0x17, 0x04, 0x00),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_EdgeAntiAlias
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_EdgeAntiAlias,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_EdgeAntiAlias+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_EdgeAntiAlias+0x17 : mov [eax+0x04], ecx
    { 0x17, 0x89 },
    { 0x18, 0x48 },
    { 0x19, 0x04 },

    // D3DDevice_SetRenderState_EdgeAntiAlias+0x1A : mov [eax+0x08], ecx
    { 0x1A, 0x89 },
    { 0x1B, 0x48 },
    { 0x1C, 0x08 },

    // D3DDevice_SetRenderState_EdgeAntiAlias+0x1D : add eax, 0x0C
    { 0x1D, 0x83 },
    { 0x1E, 0xC0 },
    { 0x1F, 0x0C },

    // D3DDevice_SetRenderState_EdgeAntiAlias+0x29 : retn 0x04
    { 0x29, 0xC2 },
    { 0x2A, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_MultiSampleMask
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_MultiSampleMask,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_MultiSampleMask],eax
    XREF_ENTRY(0x0E, XREF_D3DRS_MultiSampleMask),

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // esi,[D3D_g_pDevice]
    OV_MATCH(0x05, 0x8B, 0x35),

    // mov [D3DRS_MultiSampleMask],eax
    OV_MATCH(0x0D, 0xA3),
    //
);

// ******************************************************************
// * D3DDevice_PersistDisplay
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_PersistDisplay,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // D3DDevice_PersistDisplay+0x02 : mov ebx,[D3D_g_pDevice]
    XREF_ENTRY(0x04, XREF_D3D_g_pDevice),

    // D3DDevice_PersistDisplay+0x00 : push ecx
    OV_MATCH(0x00, 0x51),

    // D3DDevice_PersistDisplay+0x08 : call [AvGetSavedDataAddress]
    OV_MATCH(0x08, 0xFF, 0x15),

    // D3DDevice_PersistDisplay+0x17 : call [MmFreeContiguousMemory]
    OV_MATCH(0x17, 0xFF, 0x15),

    // D3DDevice_PersistDisplay+0x1F : call [AvSetSavedDataAddress]
    OV_MATCH(0x1F, 0xFF, 0x15),

    // D3DDevice_PersistDisplay+0x36 : ret
    OV_MATCH(0x36, 0xC3),

    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_ShadowFunc
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_ShadowFunc,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_ShadowFunc+0x00 : push esi
    { 0x00, 0x56 },

    // D3DDevice_SetRenderState_ShadowFunc+0x11 : mov dword ptr [eax], 0x41E6C
    { 0x11, 0xC7 },
    { 0x12, 0x00 },
    { 0x13, 0x6C },
    { 0x14, 0x1E },
    { 0x15, 0x04 },
    { 0x16, 0x00 },

    // D3DDevice_SetRenderState_ShadowFunc+0x17 : lea edx, [ecx-0x0200]
    { 0x17, 0x8D },
    { 0x18, 0x91 },
    { 0x19, 0x00 },
    { 0x1A, 0xFE },

    // D3DDevice_SetRenderState_ShadowFunc+0x20 : add eax, 0x08
    { 0x20, 0x83 },
    { 0x21, 0xC0 },
    { 0x22, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_LineWidth
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_LineWidth,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_LineWidth+0x00 : push ebx
    { 0x00, 0x53 },

    // D3DDevice_SetRenderState_LineWidth+0x15 : fmul dword ptr [esi+0x508]
    { 0x15, 0xD8 },
    { 0x16, 0x8E },
    { 0x17, 0x08 },
    { 0x18, 0x05 },

    // D3DDevice_SetRenderState_LineWidth+0x32 : cmp edi, 0x1FF
    { 0x32, 0x81 },
    { 0x33, 0xFF },

    // D3DDevice_SetRenderState_LineWidth+0x3A : mov edi, 0x1FF
    { 0x3A, 0xBF },
    { 0x3B, 0xFF },

    // D3DDevice_SetRenderState_LineWidth+0x5C : retn 0x04
    { 0x5C, 0xC2 },
    { 0x5D, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_YuvEnable
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_YuvEnable,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_YuvEnable],eax
    XREF_ENTRY(0x0D, XREF_D3DRS_YuvEnable),

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // mov e??,[D3D_g_pDevice]
    OV_MATCH(0x05, 0x8B),

    // mov [D3DRS_YuvEnable],eax
    OV_MATCH(0x0C, 0xA3),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_YuvEnable
// ******************************************************************
// Generic OOVPA as of 3911 (LTCG) / 4034 (non-LTCG) and newer.
// NOTE: This signature is used in LTCG titles first in 3911 then later
//       afterward become standard in non-LTCG titles since build 4034.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_YuvEnable,
                      1024,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_YuvEnable],eax
    XREF_ENTRY(0x0C, XREF_D3DRS_YuvEnable),

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // mov e??,[D3D_g_pDevice]
    OV_MATCH(0x05, 0x8B),

    // mov [D3DRS_YuvEnable],eax
    OV_MATCH(0x0B, 0xA3),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_OcclusionCullEnable
// ******************************************************************
// NOTE: asm codes are the same as D3DDevice_SetRenderState_StencilCullEnable
//       except for the offset references.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_OcclusionCullEnable,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_OcclusionCullEnable],eax
    XREF_ENTRY(0x0D, XREF_D3DRS_OcclusionCullEnable),

    // call XMETAL_StartPush
    //XREF_ENTRY(0x12, XREF_XMETAL_StartPush),

    // mov eax,[esp+arg_0]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // push esi
    OV_MATCH(0x04, 0x56),

    // mov [D3DRS_OcclusionCullEnable],eax
    OV_MATCH(0x0C, 0xA3)
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_OcclusionCullEnable
// ******************************************************************
// Generic OOVPA as of 3911 (LTCG) / 4034 (non-LTCG) and newer.
// NOTE: asm codes are the same as D3DDevice_SetRenderState_StencilCullEnable
//       except for the offset references.
// NOTE2: This signature is used in LTCG titles first in 3911 then later
//        afterward become standard in non-LTCG titles since build 4034.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_OcclusionCullEnable,
                      1024,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_OcclusionCullEnable],eax
    XREF_ENTRY(0x0C, XREF_D3DRS_OcclusionCullEnable),

    // mov eax,[esp+arg_0]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // push esi
    OV_MATCH(0x04, 0x56),

    // mov [D3DRS_OcclusionCullEnable],eax
    OV_MATCH(0x0B, 0xA3)
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_StencilCullEnable
// ******************************************************************
// NOTE: asm codes are the same as D3DDevice_SetRenderState_OcclusionCullEnable
//       except for the offset references.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_StencilCullEnable,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_StencilCullEnable],eax
    XREF_ENTRY(0x0D, XREF_D3DRS_StencilCullEnable),

    // call XMETAL_StartPush
    //XREF_ENTRY(0x12, XREF_XMETAL_StartPush),

    // mov eax, [esp+arg_0]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // push esi
    OV_MATCH(0x04, 0x56),

    // mov [D3DRS_StencilCullEnable],eax
    OV_MATCH(0x0C, 0xA3)
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_StencilCullEnable
// ******************************************************************
// Generic OOVPA as of 3911 (LTCG) / 4034 (non-LTCG) and newer.
// NOTE: asm codes are the same as D3DDevice_SetRenderState_OcclusionCullEnable
//       except for the offset references.
// NOTE2: This signature is used in LTCG titles first in 3911 then later
//        afterward become standard in non-LTCG titles since build 4034.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_StencilCullEnable,
                      1024,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov esi,[D3D_g_pDevice]
    XREF_ENTRY(0x07, XREF_D3D_g_pDevice),

    // mov [D3DRS_StencilCullEnable],eax
    XREF_ENTRY(0x0C, XREF_D3DRS_StencilCullEnable),

    // mov eax, [esp+arg_0]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // push esi
    OV_MATCH(0x04, 0x56),

    // mov [D3DRS_StencilCullEnable],eax
    OV_MATCH(0x0B, 0xA3)
    //
);

// ******************************************************************
// * D3DDevice_DrawVerticesUP
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_DrawVerticesUP,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov edi,[D3D_g_pDevice]
    XREF_ENTRY(0x0B, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateUP
    XREF_ENTRY(0x15, XREF_D3D_CDevice_SetStateUP),

    // push ebp
    OV_MATCH(0x00, 0x55),

    // sub esp,0x10
    OV_MATCH(0x03, 0x83, 0xEC, 0x10),

    // mov edi,[D3D_g_pDevice]
    OV_MATCH(0x09, 0x8B, 0x3D),

    // mov ecx,edi
    OV_MATCH(0x0F, 0x8B, 0xCF),

    // mov [ebp - 0x4],e??
    OV_MATCH(0x11, 0x89),
    OV_MATCH(0x13, 0xFC), // D3DDevice_DrawVerticesUP 0xFC vs D3DDevice_DrawIndexedVerticesUP 0xF8
    // call D3D::CDevice::SetStateUP
    OV_MATCH(0x14, 0xE8),
    //
);

// ******************************************************************
// * D3DDevice_DrawIndexedVerticesUP
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_DrawIndexedVerticesUP,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov edi,[D3D_g_pDevice]
    XREF_ENTRY(0x0B, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateUP
    XREF_ENTRY(0x15, XREF_D3D_CDevice_SetStateUP),

    // push ebp
    OV_MATCH(0x00, 0x55),

    // sub esp,0x14
    OV_MATCH(0x03, 0x83, 0xEC, 0x14),

    // mov edi,[D3D_g_pDevice]
    OV_MATCH(0x09, 0x8B, 0x3D),

    // mov ecx,edi
    OV_MATCH(0x0F, 0x8B, 0xCF),

    // mov [ebp - 0x8],e??
    OV_MATCH(0x11, 0x89),
    OV_MATCH(0x13, 0xF8), // D3DDevice_DrawIndexedVerticesUP 0xF8 vs D3DDevice_DrawVerticesUP 0xFC
    // call D3D::CDevice::SetStateUP
    OV_MATCH(0x14, 0xE8),
    //
);

// ******************************************************************
// * D3DDevice_DrawVertices
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_DrawVertices,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov ebx,[D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateVB
    XREF_ENTRY(0x0E, XREF_D3D_CDevice_SetStateVB),

    // push ebx
    // mov ebx,[D3D_g_pDevice]
    OV_MATCH(0x00, 0x53, 0x8B, 0x1D),

    // call D3D::CDevice::SetStateVB
    OV_MATCH(0x0D, 0xE8),
    // mov edi,[esp + param_3]
    OV_MATCH(0x12, 0x8B, 0x7C, 0x24, 0x18),
    // lea esi,[edi - 1]
    OV_MATCH(0x16, 0x8D, 0x77, 0xFF),
    // shr esi,0x8
    OV_MATCH(0x19, 0xC1, 0xEE, 0x08),
    // Do not use any offsets after 0x20
);

// ******************************************************************
// * D3DDevice_GetDisplayMode
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetDisplayMode,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x09, 0xB4 },
    { 0x14, 0x8B },
    { 0x1F, 0x10 },
    { 0x2A, 0x1B },
    { 0x35, 0x8B },
    { 0x41, 0x89 },
    { 0x4B, 0x89 },
    //
);

// ******************************************************************
// * D3DDevice_SetTextureState_BumpEnv
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetTextureState_BumpEnv,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x0E, 0x8B },
    { 0x16, 0x8B },
    { 0x22, 0x24 },
    { 0x2E, 0x24 },
    { 0x3A, 0x04 },
    { 0x46, 0x8B },
    { 0x52, 0xB5 },
    //
);

// ******************************************************************
// * D3DDevice_SetTextureState_ColorKeyColor
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetTextureState_ColorKeyColor,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x07, 0x56 },
    { 0x0D, 0x8B },
    { 0x13, 0x8D },
    { 0x1A, 0x8B },
    { 0x21, 0x83 },
    { 0x28, 0x07 },
    { 0x2F, 0x5E },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexData4s
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexData4s,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x07, 0x56 },
    { 0x10, 0x08 },
    { 0x19, 0xBF },
    { 0x22, 0x24 },
    { 0x2B, 0x54 },
    { 0x34, 0x24 },
    { 0x3D, 0x08 },
    { 0x46, 0x00 },
    //
);

// ******************************************************************
// * D3DResource_GetType
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DResource_GetType,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x13, 0x2A },
    { 0x28, 0x00 },
    { 0x3D, 0x00 },
    { 0x52, 0x74 },
    { 0x67, 0x00 },
    { 0x7C, 0x04 },
    { 0x91, 0x00 },
    //
);

// ******************************************************************
// * D3D_AllocContiguousMemory
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_AllocContiguousMemory,
                         3911)
OOVPA_SIG_MATCH(

    // D3D_AllocContiguousMemory+0x00 : mov eax,[esp+0x08]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x08),

    // D3D_AllocContiguousMemory+0x04 : mov ecx,[esp+0x04]
    OV_MATCH(0x04, 0x8B, 0x4C, 0x24, 0x04),

    // Unique offset
    // D3D_AllocContiguousMemory+0x08 : push 0x00000404
    OV_MATCH(0x08, 0x68, 0x04, 0x04, 0x00, 0x00),

    // D3D_AllocContiguousMemory+0x0D : push eax
    OV_MATCH(0x0D, 0x50),

    // Offset 0x0E and later has change over time.

    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_Deferred
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetRenderState_Deferred,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SetRenderState_Deferred+0x00 : mov eax, ds:(g_DirtyFromRenderState)-148[ecx*4]
    { 0x00, 0x8B },
    { 0x01, 0x04 },
    { 0x02, 0x8D },

    // D3DDevice_SetRenderState_Deferred+0x07 : or dword ptr ds:g_Device+8,eax
    { 0x07, 0x09 },
    { 0x08, 0x05 },

    // D3DDevice_SetRenderState_Deferred+0x0D : mov dword ptr ds:D3D_g_RenderState[ecx*4], edx
    { 0x0D, 0x89 },
    { 0x0E, 0x14 },
    { 0x0F, 0x8D },

    // D3DDevice_SetRenderState_Deferred+0x14 : retn
    { 0x14, 0xC3 },
    //
);

// ******************************************************************
// * D3DDevice_GetLight
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetLight,
                         3911)
OOVPA_SIG_MATCH(
    // Based on Dxbx patterns for 3911, 4361, 4627, 5344, 5558, 5659, 5788, 5849, 5933

    // D3DDevice_GetLight+0x00 : mov ecx, [addr]
    { 0x00, 0x8B },

    // D3DDevice_GetLight+0x0B : mov esi, [ecx+XXXh]
    { 0x0B, 0x8B },
    { 0x0C, 0xB1 },
    { 0x0F, 0x00 },
    { 0x10, 0x00 },

    // D3DDevice_GetLight+0x12 : mov edi, [esp+8+arg_4]
    { 0x12, 0x8B },
    { 0x13, 0x7C },
    { 0x14, 0x24 },
    { 0x15, 0x10 },

    // D3DDevice_GetLight+0x1F : mov ecx, 1Ah
    { 0x1E, 0xB9 },
    { 0x1F, 0x1A },
    //
);

// ******************************************************************
// * D3DDevice_SetLight
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetLight,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x15, 0x00 },
    { 0x16, 0x00 },
    { 0x17, 0x3B },
    { 0x18, 0xDF },
    { 0x19, 0x89 },
    { 0x1A, 0x7C },
    { 0x1B, 0x24 },
    { 0x1C, 0x14 },
    { 0x1D, 0x0F },
    { 0x1E, 0x82 },
    { 0x1F, 0xBF },

    { 0x3B, 0x8B },
    { 0x3C, 0xD8 },

    { 0x62, 0x8B },
    { 0x63, 0xF3 },
    //
);

// ******************************************************************
// * D3DDevice_GetProjectionViewportMatrix
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetProjectionViewportMatrix,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x02, 0x35 },
    { 0x07, 0x57 },
    { 0x0A, 0x24 },
    { 0x0E, 0xA0 },
    { 0x12, 0xB9 },
    { 0x16, 0x00 },
    { 0x1A, 0x5E },
    //
);

// ******************************************************************
// * D3DDevice_GetTile
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetTile,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },

    { 0x0A, 0x56 },
    { 0x0B, 0x57 },
    { 0x0C, 0x8B },
    { 0x0D, 0x7C },
    { 0x0E, 0x24 },
    { 0x0F, 0x10 },
    { 0x10, 0x8D },
    { 0x11, 0x04 },
    { 0x12, 0x40 },
    { 0x13, 0x8D },
    { 0x14, 0xB4 },
    { 0x15, 0xC1 },

    { 0x1F, 0xF3 },
    { 0x23, 0xC2 },
    { 0x24, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_ApplyStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_ApplyStateBlock,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x1D, 0x83 },
    { 0x40, 0x83 },
    { 0x5B, 0x16 },
    { 0x7A, 0x01 },
    { 0x99, 0x46 },
    { 0xB8, 0x06 },
    { 0xD7, 0x39 },
    { 0xF6, 0x51 },
    //
);

// ******************************************************************
// * D3DDevice_CaptureStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CaptureStateBlock,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x1E, 0x76 },
    { 0x3E, 0xE8 },
    { 0x5E, 0x06 },
    { 0x7E, 0x26 },
    { 0x9E, 0xFF },
    { 0xBE, 0x04 },
    { 0xDE, 0xF8 },
    //
);

// ******************************************************************
// * D3DDevice_DeleteStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DeleteStateBlock,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x11, 0x76 },
    { 0x24, 0x3B },
    { 0x37, 0xE8 },
    { 0x4A, 0x50 },
    { 0x5D, 0x74 },
    { 0x70, 0x06 },
    { 0x83, 0xEB },
    //
);

// ******************************************************************
// * D3DDevice_GetBackMaterial
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetBackMaterial,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x56 },
    { 0x06, 0x57 },
    { 0x0A, 0x0C },
    { 0x0D, 0x5C },
    { 0x0E, 0x0B },
    { 0x12, 0x11 },
    { 0x16, 0xF3 },
    { 0x1A, 0xC2 },
    //
);

// ******************************************************************
// * D3DDevice_CreateStateBlock
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateStateBlock,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x1E, 0x8B },
    { 0x3E, 0x89 },
    { 0x5E, 0x24 },
    { 0x7E, 0xF8 },
    { 0x9F, 0x01 },
    { 0xBE, 0xB6 },
    { 0xDE, 0xF8 },
    { 0xFE, 0x76 },
    //
);

// ******************************************************************
// * D3DDevice_DeletePixelShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DeletePixelShader,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0x24 },
    { 0x06, 0x75 },
    { 0x0A, 0x04 },
    { 0x0E, 0x09 },
    { 0x12, 0x04 },
    { 0x18, 0xC2 },
    { 0x1A, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_SetPixelShaderProgram
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetPixelShaderProgram,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x54 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x85 },
    { 0x05, 0xD2 },
    { 0x06, 0xA1 },

    { 0x11, 0x00 },
    { 0x12, 0x00 },
    { 0x13, 0xC7 },
    { 0x14, 0x01 },
    { 0x15, 0x01 },
    { 0x16, 0x00 },
    { 0x17, 0x00 },
    { 0x18, 0x00 },
    { 0x19, 0xC7 },
    { 0x1A, 0x80 },

    { 0x29, 0x89 },
    { 0x3A, 0xE9 },
    //
);

// ******************************************************************
// * D3D_KickOffAndWaitForIdle
// ******************************************************************
// * This is for the real D3D::KickOffAndWaitForIdle
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_KickOffAndWaitForIdle,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x8B },
    { 0x06, 0x48 },
    { 0x07, 0x1C },
    { 0x0A, 0x51 },
    { 0x10, 0xC3 },
    //
);

// ******************************************************************
// * D3DDevice_SetModelView
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetModelView,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x12, 0x08 },
    { 0x26, 0x53 },
    { 0x3A, 0x8B },
    { 0x4E, 0x80 },
    { 0x62, 0x00 },
    { 0x76, 0x00 },
    { 0x8A, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_FlushVertexCache
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_FlushVertexCache,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x07, 0x56 },
    { 0x08, 0xE8 },
    { 0x0D, 0xC7 },
    { 0x0F, 0x10 },
    { 0x12, 0x00 },
    { 0x17, 0x00 },
    { 0x1C, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetScissors
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetScissors,
                         3911) // Up to 5233
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x24 },
    { 0x03, 0x53 },
    { 0x04, 0x8B },
    { 0x05, 0x5C },
    { 0x06, 0x24 },
    { 0x07, 0x2C },
    { 0x08, 0x85 },
    { 0x09, 0xDB },
    { 0x0A, 0x55 },
    { 0x0B, 0x8B },
    { 0x0C, 0x2D },

    { 0x3E, 0x44 },
    { 0x3F, 0x24 },
    { 0x52, 0x44 },
    { 0x53, 0x24 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexShaderInput
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexShaderInput,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x51 },
    { 0x1E, 0x03 },
    { 0x3E, 0x8B },
    { 0x5E, 0xC7 },
    { 0x7E, 0xF8 },
    { 0x9E, 0xC6 },
    { 0xBE, 0x7F },
    { 0xDE, 0xCA },
    { 0xFE, 0x17 },
    //
);

// ******************************************************************
// * D3DDevice_PrimeVertexCache
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_PrimeVertexCache,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x0D, 0x00 },
    { 0x1C, 0x55 },
    { 0x2B, 0x00 },
    { 0x3A, 0x24 },
    { 0x49, 0xCB },
    { 0x58, 0x74 },
    { 0x67, 0x00 },
    { 0x76, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_SetVertexData4ub
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetVertexData4ub,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x07, 0x56 },
    { 0x10, 0x08 },
    { 0x19, 0xC9 },
    { 0x22, 0x54 },
    { 0x2B, 0x14 },
    { 0x34, 0x24 },
    { 0x3D, 0xFC },
    //
);

// ******************************************************************
// * D3DDevice_SetPixelShaderConstant
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetPixelShaderConstant,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x1E, 0x4C },
    { 0x3E, 0x11 },
    { 0x61, 0xDF },
    { 0x7E, 0xF6 },
    { 0x9E, 0x05 },
    { 0xC0, 0x51 },
    { 0xDE, 0xC4 },
    //
);

// ******************************************************************
// * D3DDevice_InsertCallback
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_InsertCallback,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x0D, 0x8B },
    { 0x18, 0x8B },
    { 0x25, 0x50 },
    { 0x32, 0x10 },
    { 0x3F, 0x00 },
    { 0x4C, 0x00 },
    { 0x59, 0x03 },
    //
);

// ******************************************************************
// * D3DDevice_BeginPushBuffer
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_BeginPushBuffer,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x0B, 0xCE },
    { 0x1B, 0x57 },
    { 0x25, 0x00 },
    { 0x32, 0x06 },
    { 0x3F, 0x03 },
    { 0x4C, 0x04 },
    { 0x59, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_EndPushBuffer
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_EndPushBuffer,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov e??,[D3D_g_pDevice]
    XREF_ENTRY(0x04, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateVB
    XREF_ENTRY(0x0D, XREF_D3D_CDevice_SetStateVB),

    // mov e??,[D3D_g_pDevice]
    OV_MATCH(0x02, 0x8B),

    // call D3D::CDevice::SetStateUP
    OV_MATCH(0x0C, 0xE8),

    // and [esi + 0x??],0xFFFFFF7B
    OV_MATCH(0x44, 0x81, 0x66),
    OV_MATCH(0x47, 0x7B, 0xFF, 0xFF, 0xFF),

    // test ecx,0x78FFFF
    OV_MATCH(0x5D, 0xF7, 0xC1, 0xFF, 0xFF, 0x78, 0x00),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_RopZCmpAlwaysRead
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_RopZCmpAlwaysRead,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // [D3DRS_RopZCmpAlwaysRead],eax
    XREF_ENTRY(0x05, XREF_D3DRS_RopZCmpAlwaysRead),
    // call D3D_CommonSetDebugRegisters
    XREF_ENTRY(0x0A, XREF_D3D_CommonSetDebugRegisters),

    // mov eax, [esp+0x04]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // call D3D_CommonSetDebugRegisters
    OV_MATCH(0x09, 0xE8),

    // retn 0x04
    OV_MATCH(0x0E, 0xC2, 0x04, 0x00),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_RopZRead
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_RopZRead,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov [D3DRS_RopZRead],eax
    XREF_ENTRY(0x05, XREF_D3DRS_RopZRead),
    // call D3D_CommonSetDebugRegisters
    XREF_ENTRY(0x0A, XREF_D3D_CommonSetDebugRegisters),

    // mov eax, [esp+0x04]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // call D3D_CommonSetDebugRegisters
    OV_MATCH(0x09, 0xE8),

    // retn 0x04
    OV_MATCH(0x0E, 0xC2, 0x04, 0x00),
    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_DoNotCullUncompressed
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_DoNotCullUncompressed,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov [D3DRS_DoNotCullUncompressed],eax
    XREF_ENTRY(0x05, XREF_D3DRS_DoNotCullUncompressed),
    // call D3D_CommonSetDebugRegisters
    XREF_ENTRY(0x0A, XREF_D3D_CommonSetDebugRegisters),

    // mov eax, [esp+0x04]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // call D3D_CommonSetDebugRegisters
    OV_MATCH(0x09, 0xE8),

    // retn 0x04
    OV_MATCH(0x0E, 0xC2, 0x04, 0x00),
    //
);

// ******************************************************************
// * XMETAL_StartPush
// ******************************************************************
// Generic OOVPA as of 3911; Removed in 4034??
OOVPA_SIG_HEADER_NO_XREF(XMETAL_StartPush,
                         3911)
OOVPA_SIG_MATCH(

    // XMETAL_StartPush+0x00 : mov ecx, [esp+0x4]
    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x02, 0x24 },
    { 0x03, 0x04 },

    // XMETAL_StartPush+0x04 : mov eax, [ecx]
    { 0x04, 0x8B },
    { 0x05, 0x01 },

    // XMETAL_StartPush+0x06 : cmp eax, [ecx+0x4]
    { 0x06, 0x3B },
    { 0x07, 0x41 },
    { 0x08, 0x04 },

    // XMETAL_StartPush+0x10 : retn 4
    { 0x10, 0xC2 },
    { 0x11, 0x04 },
    //
);

// ******************************************************************
// * D3D::SetFence
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_SetFence,
                         3911)
OOVPA_SIG_MATCH(

    // D3D::SetFence+0x00 : push ebx
    { 0x00, 0x53 },

    // D3D::SetFence+0x0F : mov edi, [esi+0x1C]
    { 0x0F, 0x8B },
    { 0x10, 0x7E },
    { 0x11, 0x1C },

    // D3D::SetFence+0x3D : and ecx, 0x3F
    { 0x3D, 0x83 },
    { 0x3E, 0xE1 },
    { 0x3F, 0x3F },

    // D3D::SetFence+0x77 : mov [esi*ebp*4], edi
    { 0x77, 0x89 },
    { 0x78, 0x3C },
    { 0x79, 0xAE },

    // D3D::SetFence+0x96 : retn 4
    { 0x96, 0xC2 },
    { 0x97, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_InsertFence
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_InsertFence,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x03, XREF_D3D_SetFence),

    { 0x00, 0x6A },
    { 0x01, 0x00 },
    { 0x02, 0xE8 },
    { 0x07, 0xC3 },
    //
);

// ******************************************************************
// * D3DDevice_LoadVertexShaderProgram
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_LoadVertexShaderProgram,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x53 },
    { 0x05, 0x0F },
    { 0x06, 0xB7 },
    { 0x07, 0x58 },
    { 0x08, 0x02 },
    { 0x09, 0x55 },
    { 0x0A, 0x8B },
    { 0x0B, 0x2D },

    { 0x14, 0xE3 },
    { 0x15, 0x02 },
    { 0x16, 0xF6 },
    { 0x17, 0xC1 },
    //
);

// ******************************************************************
// * D3DDevice_DeleteVertexShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DeleteVertexShader,
                         3911)
OOVPA_SIG_MATCH(

    // mov eax,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),
    // mov ecx,[eax + -0x1]
    OV_MATCH(0x04, 0x8B, 0x48, 0xFF),

    // mov [eax],ecx
    OV_MATCH(0x09, 0x89, 0x08),
    // JNZ +9
    OV_MATCH(0x0B, 0x75, 0x09),

    // retn 4
    OV_MATCH(0x16, 0xC2, 0x04)
    //
);

// ******************************************************************
// * D3DDevice_BlockOnFence
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_BlockOnFence,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x08, XREF_D3D_BlockOnTime),

    { 0x00, 0x8B },
    { 0x02, 0x24 },
    { 0x04, 0x6A },
    { 0x06, 0x50 },
    { 0x0C, 0xC2 },
    { 0x0D, 0x04 },
    { 0x0E, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_Reset
// ******************************************************************
// Generic OOVPA as of 3911 and newer
OOVPA_SIG_HEADER_XREF(D3DDevice_Reset,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(
    // call CDevice::FreeFrameBuffers
    XREF_ENTRY(0x23, XREF_D3D_CDevice_FreeFrameBuffers),

    // push ebx
    OV_MATCH(0x00, 0x53),

    // jnz +0xF5
    OV_MATCH(0x1E, 0x75, 0xF5),

    // call CDevice::FreeFrameBuffers
    OV_MATCH(0x22, 0xE8),
    // mov esi, [esp + param_1]
    OV_MATCH(0x27, 0x8B, 0x74, 0x24, 0x14),
    //
);

// ******************************************************************
// * D3D_GetAdapterIdentifier
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_GetAdapterIdentifier,
                         3911)
OOVPA_SIG_MATCH(

    { 0x04, 0x85 },
    { 0x0A, 0x08 },
    { 0x10, 0x56 },
    { 0x16, 0xB9 },
    { 0x20, 0xF3 },
    { 0x22, 0x5F },
    { 0x28, 0x00 },
    //
);

// ******************************************************************
// * D3D_GetDeviceCaps
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_GetDeviceCaps,
                         3911)
OOVPA_SIG_MATCH(

    { 0x04, 0x85 },
    { 0x0A, 0x08 },
    { 0x10, 0x83 },
    { 0x16, 0x08 },
    { 0x1C, 0xC2 },
    { 0x22, 0x0C },
    { 0x29, 0x33 },
    //
);

// ******************************************************************
// * D3D::CommonSetDebugRegisters
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3D_CommonSetDebugRegisters,
                      3911,
                      XRefFour)
OOVPA_SIG_MATCH(

    // mov esi, ptr [D3D_g_pDevice]
    XREF_ENTRY(0x03, XREF_D3D_g_pDevice), // derived
    // mov ecx, ptr [D3DRS_DoNotCullUncompressed]
    XREF_ENTRY(0x18, XREF_D3DRS_DoNotCullUncompressed), // derived
    // mov ecx, ptr [D3DRS_RopZCmpAlwaysRead]
    XREF_ENTRY(0x3F, XREF_D3DRS_RopZCmpAlwaysRead), // derived
    // mov eax, ptr [D3DRS_RopZRead]
    XREF_ENTRY(0x55, XREF_D3DRS_RopZRead), // derived

    // push esi
    OV_MATCH(0x00, 0x56),

    // and edx, -9
    OV_MATCH(0x0D, 0x83, 0xE2, 0xF7),

    // mov ecx, ptr [D3DRS_DoNotCullUncompressed]
    OV_MATCH(0x16, 0x8B),

    // Unique offset
    // and edx,0xE7EFFFFF
    OV_MATCH(0x31, 0x81, 0xE2, 0xFF, 0xFF, 0xEF, 0xE7),

    // mov ecx, ptr [D3DRS_RopZCmpAlwaysRead]
    OV_MATCH(0x3D, 0x8B),

    // mov eax, ptr [D3DRS_RopZRead]
    OV_MATCH(0x54, 0xA1),

    // offset from 0x67 and later are different across builds.
);

// ******************************************************************
// * D3DDevice_CreateImageSurface
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CreateImageSurface,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0x24 },
    { 0x06, 0x24 },
    { 0x0A, 0x24 },
    { 0x0E, 0x44 },
    { 0x12, 0x00 },
    { 0x16, 0xE8 },
    { 0x1B, 0xC2 },
    //
);

// ******************************************************************
// * D3D::BlockOnTime
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_BlockOnTime,
                         3911)
OOVPA_SIG_MATCH(

    // D3D::BlockOnFence+0x00 : push ebp
    { 0x00, 0x55 },

    // D3D::BlockOnFence+0x0A : push edi
    { 0x0A, 0x57 },

    // D3D::BlockOnFence+0x4E : cmp eax, 0x8000
    { 0x4E, 0x3D },
    { 0x4F, 0x00 },
    { 0x50, 0x80 },
    { 0x51, 0x00 },

    // D3D::BlockOnFence+0x6E : mov ebp, 0x40100
    { 0x6E, 0xBD },
    { 0x6F, 0x00 },
    { 0x70, 0x01 },
    { 0x71, 0x04 },
    //
);

// ******************************************************************
// * D3D::BlockOnResource
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_BlockOnResource,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x34, 0x8B }, // mov edx, [ecx+0x1C]
    { 0x35, 0x51 },
    { 0x36, 0x1C },
    { 0x41, 0xC2 }, // retn 4
    { 0x42, 0x04 },
    { 0x43, 0x00 },
    { 0x7E, 0xC2 }, // retn 4
    { 0x7F, 0x04 },
    { 0x80, 0x00 },
    //
);

// ******************************************************************
// * D3DResource_BlockUntilNotBusy
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DResource_BlockUntilNotBusy,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x01, XREF_D3D_BlockOnResource),

    { 0x00, 0xE9 },
    //
);

// ******************************************************************
// * D3DDevice_SetTile
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetTile,
                         3911)
OOVPA_SIG_MATCH(

    // mov edx, [D3D_g_pDevice]
    OV_MATCH(0x00, 0x8B, 0x15),

    // sub esp, 0x18
    OV_MATCH(0x06, 0x83, 0xEC, 0x18),

    // mov ecx,6
    OV_MATCH(0x1A, 0xB9, 0x06, 0x00 /*, 0x00, 0x00*/),

    // At offset 0x24 and later remain the same as 4034 and later.
    // Except sometime use different registers

    // mov ecx,6
    OV_MATCH(0x44, 0xB9, 0x06, 0x00 /*, 0x00, 0x00*/),

    // and e??,0x03FFFFFF
    OV_MATCH(0x68, 0x81),
    // OV_MATCH(0x69, 0xE1), // Sometimes changed over builds.
    OV_MATCH(0x6A, 0xFF, 0xFF, 0xFF, 0x03) // 0x03 vs 0x0F from D3D_SetTileNoWait
    //
);

// ******************************************************************
// * D3DDevice_SetBackMaterial
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SetBackMaterial,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x0A, 0x57 },
    { 0x0B, 0x8D },
    { 0x0C, 0xB8 },
    { 0x0D, 0x5C },
    { 0x0E, 0x0B },
    { 0x0F, 0x00 },
    { 0x14, 0x00 },
    { 0x18, 0x8B },
    { 0x1E, 0x5F },
    //
);

// ******************************************************************
// * D3DDevice_SwitchTexture
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_SwitchTexture,
                         3911)
OOVPA_SIG_MATCH(

    // D3DDevice_SwitchTexture+0x00 : mov eax, [addr]
    { 0x00, 0xA1 },

    // D3DDevice_SwitchTexture+0x05 : add eax, 0x0C
    { 0x05, 0x83 },
    { 0x06, 0xC0 },
    { 0x07, 0x0C },

    // D3DDevice_SwitchTexture+0x08 : cmp eax, ds:dword_XXXXX
    { 0x08, 0x3B },
    { 0x09, 0x05 },

    // D3DDevice_SwitchTexture+0x0E : jnb +0x15
    { 0x0E, 0x73 },
    { 0x0F, 0x15 },

    // D3DDevice_SwitchTexture+0x22 : retn 0x04
    { 0x22, 0xC2 },
    { 0x23, 0x04 },

    //
);

// ******************************************************************
// * D3DDevice_GetModelView
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetModelView,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x57 },
    { 0x0A, 0x85 },
    { 0x10, 0xB0 },
    { 0x11, 0xE0 },
    { 0x12, 0x05 },
    { 0x13, 0x00 },
    { 0x14, 0x00 },
    { 0x15, 0xB9 },
    { 0x16, 0x10 },
    { 0x1C, 0x5E },
    //
);

// ******************************************************************
// * D3DDevice_CopyRects
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_CopyRects,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x81 },
    { 0x10, 0x0F },
    { 0x11, 0xB6 },
    { 0x12, 0x75 },
    { 0x13, 0x0D },
    { 0x14, 0x8A },
    { 0x15, 0x9E },
    { 0x40, 0xF6 },
    { 0x4F, 0x84 },
    { 0x75, 0x15 },
    //
);

// ******************************************************************
// * D3DVertexBuffer_GetDesc
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DVertexBuffer_GetDesc,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0x24 },
    { 0x06, 0x74 },
    { 0x0A, 0xC7 },
    { 0x0E, 0x00 },
    { 0x15, 0x89 },
    { 0x16, 0x46 },
    { 0x1A, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_GetShaderConstantMode
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetShaderConstantMode,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x8B },
    { 0x06, 0x88 },
    { 0x07, 0x40 },
    { 0x08, 0x21 },
    { 0x09, 0x00 },
    { 0x0A, 0x00 },
    { 0x0B, 0x8B },
    { 0x0C, 0x54 },
    { 0x0D, 0x24 },
    { 0x0E, 0x04 },
    { 0x0F, 0x89 },
    { 0x10, 0x0A },
    { 0x11, 0xC2 },
    { 0x12, 0x04 },
    { 0x13, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShader,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x8B },
    { 0x06, 0x88 },
    { 0x07, 0x74 },
    { 0x08, 0x04 },
    { 0x09, 0x00 },
    { 0x0A, 0x00 },
    { 0x0B, 0x8B },
    { 0x0C, 0x54 },
    { 0x0D, 0x24 },
    { 0x0E, 0x04 },
    { 0x0F, 0x89 },
    { 0x10, 0x0A },
    { 0x11, 0xC2 },
    { 0x12, 0x04 },
    { 0x13, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderConstant
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderConstant,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x05, 0x8B },
    { 0x06, 0x74 },
    { 0x07, 0x24 },
    { 0x08, 0x08 },
    { 0x09, 0x57 },
    { 0x0A, 0x8B },
    { 0x0B, 0x3D },
    { 0x18, 0x00 },
    { 0x1F, 0xF7 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderInput
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderInput,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x05, 0xC9 },

    { 0x0B, 0x74 },
    { 0x11, 0x00 },
    { 0x12, 0x00 },
    { 0x13, 0x89 },
    { 0x14, 0x11 },
    { 0x15, 0x8B },
    { 0x16, 0x4C },
    { 0x17, 0x24 },
    { 0x18, 0x04 },
    { 0x19, 0x85 },
    { 0x1A, 0xC9 },
    { 0x1B, 0x74 },
    { 0x1C, 0x08 },
    { 0x1D, 0x8B },

    { 0x34, 0x8D },
    { 0x35, 0x0C },
    //
);

// ******************************************************************
// * D3DDevice_RunVertexStateShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_RunVertexStateShader,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x0D, 0x8B },
    { 0x10, 0x0C },
    { 0x11, 0x85 },
    { 0x12, 0xC9 },
    { 0x13, 0x74 },
    { 0x14, 0x21 },
    { 0x15, 0xD9 },
    { 0x16, 0x41 },
    { 0x1F, 0x41 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderType
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderType,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x04, 0x8B },
    { 0x0A, 0x07 },
    { 0x10, 0xEB },
    { 0x16, 0x00 },
    { 0x1C, 0x40 },
    { 0x22, 0xC9 },
    { 0x28, 0x08 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderDeclaration
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderDeclaration,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x04, 0x8A },

    { 0x13, 0xC7 },
    { 0x14, 0x01 },
    { 0x15, 0x00 },
    { 0x16, 0x00 },
    { 0x17, 0x00 },
    { 0x18, 0x00 },
    { 0x19, 0x33 },
    { 0x1A, 0xC0 },
    { 0x1B, 0x83 },
    { 0x1C, 0xC4 },

    { 0x1E, 0xC2 },
    { 0x1F, 0x0C },

    { 0x40, 0x33 },
    //
);

// ******************************************************************
// * D3DDevice_GetVertexShaderFunction
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetVertexShaderFunction,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x56 },
    { 0x16, 0xC0 },
    { 0x2E, 0x01 },
    { 0x46, 0x10 },
    { 0x5E, 0x07 },
    { 0x76, 0xC7 },
    { 0x8E, 0x00 },
    { 0xA6, 0xF8 },
    //
);

// ******************************************************************
// * D3DDevice_GetPixelShader
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetPixelShader,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x8B },
    { 0x06, 0x88 },
    { 0x07, 0x14 },
    { 0x08, 0x04 },
    { 0x09, 0x00 },
    { 0x0A, 0x00 },
    { 0x0B, 0x8B },
    { 0x0C, 0x54 },
    { 0x0D, 0x24 },
    { 0x0E, 0x04 },
    { 0x0F, 0x89 },
    { 0x10, 0x0A },
    { 0x11, 0xC2 },
    { 0x12, 0x04 },
    { 0x13, 0x00 },
    //
);

// ******************************************************************
// * D3DDevice_IsFencePending
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_IsFencePending,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },
    { 0x05, 0x8B },
    { 0x06, 0x88 },
    { 0x07, 0xF0 },
    { 0x08, 0x03 },
    { 0x09, 0x00 },
    { 0x0A, 0x00 },
    { 0x0B, 0x8B },
    { 0x0C, 0x40 },
    { 0x0D, 0x1C },
    { 0x1A, 0x1B },
    { 0x1F, 0x04 },
    //
);

// ******************************************************************
// * D3DDevice_GetPushBufferOffset
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_GetPushBufferOffset,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x14, 0xB8 },
    { 0x2A, 0x8B },
    { 0x40, 0x47 },
    { 0x56, 0x89 },
    { 0x6C, 0xAB },
    { 0x82, 0x04 },
    { 0x98, 0x89 },
    //
);

// ******************************************************************
// * D3D_GetAdapterDisplayMode
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_GetAdapterDisplayMode,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x85 },
    { 0x05, 0xC0 },
    { 0x06, 0x74 },
    { 0x07, 0x08 },
    { 0x08, 0xB8 },
    { 0x09, 0x6C },
    { 0x0A, 0x08 },
    { 0x0B, 0x76 },
    { 0x0C, 0x88 },
    { 0x0D, 0xC2 },
    { 0x0E, 0x08 },
    { 0x0F, 0x00 },
    { 0x10, 0x8B },
    //{ 0x11, 0x0D }, // 0D vs 15

    { 0x1E, 0x33 },
    { 0x1F, 0xC0 },

    { 0x30, 0x00 },
    { 0x31, 0x8B },
    //
);

// ******************************************************************
// * D3D_EnumAdapterModes
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3D_EnumAdapterModes,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x01, 0xEC },

    { 0x12, 0x57 },
    { 0x13, 0x89 },
    { 0x14, 0x44 },
    { 0x15, 0x24 },
    { 0x16, 0x14 },
    { 0x17, 0x89 },
    { 0x18, 0x4C },
    { 0x19, 0x24 },
    { 0x1A, 0x20 },
    { 0x1B, 0xE8 },

    { 0x50, 0x6C },
    { 0x51, 0x24 },
    //
);

// ******************************************************************
// * D3D_GetAdapterModeCount
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3D_GetAdapterModeCount,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x83 },
    { 0x01, 0xEC },
    { 0x02, 0x08 },
    { 0x03, 0x53 },
    { 0x04, 0x55 },
    { 0x05, 0x56 },
    { 0x06, 0x57 },
    { 0x07, 0xC7 },
    { 0x08, 0x44 },
    { 0x09, 0x24 },
    { 0x0A, 0x10 },
    { 0x0B, 0x00 },
    { 0x0C, 0x00 },
    { 0x0D, 0x00 },
    { 0x0E, 0x00 },
    { 0x0F, 0xE8 },

    { 0x1D, 0x8B },
    { 0x1E, 0xD1 },

    { 0x40, 0x14 },
    { 0x41, 0xEB },
    //
);

// ******************************************************************
// * D3DDevice_DeletePatch
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(D3DDevice_DeletePatch,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x05, 0x0D },
    { 0x0C, 0xA1 },

    { 0x11, 0x56 },
    { 0x12, 0x8B },
    { 0x13, 0x34 },
    { 0x14, 0x88 },
    { 0x15, 0x85 },
    { 0x16, 0xF6 },
    { 0x17, 0x74 },
    { 0x18, 0x17 },
    { 0x19, 0x8B },
    { 0x1A, 0x4E },
    { 0x1B, 0x04 },
    { 0x1C, 0xC7 },
    { 0x1D, 0x04 },
    { 0x1E, 0x88 },
    { 0x1F, 0x00 },

    { 0x25, 0xE8 },
    //
);

// ******************************************************************
// * D3DDevice_KickPushBuffer
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_KickPushBuffer,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x07, XREF_D3D_CDevice_KickOff),

    { 0x00, 0x8B },
    { 0x01, 0x0D },
    { 0x06, 0xE9 },
    //
);

// ******************************************************************
// * CMiniport_IsFlipPending
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CMiniport_IsFlipPending,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x81 },
    { 0x02, 0xDC },
    { 0x03, 0x01 },
    { 0x04, 0x00 },
    { 0x05, 0x00 },
    { 0x06, 0x8B },
    { 0x07, 0x84 },
    { 0x08, 0xC1 },
    { 0x09, 0xB4 },
    { 0x0A, 0x01 },
    { 0x0B, 0x00 },
    { 0x0C, 0x00 },
    { 0x0D, 0xC3 },
    //
);

// ******************************************************************
// * CDevice::MakeSpace_4
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CDevice_MakeSpace,
                         3911)
OOVPA_SIG_MATCH(

    // CDevice::MakeSpace_4+0x00 : sub esp,0x__
    OV_MATCH(0x00, 0x83, 0xEC),

    // CDevice::MakeSpace_4+0x06 : test [esi+0x0C],0x04
    OV_MATCH(0x06, 0xF6, 0x46, 0x0C, 0x04),

    // CDevice::MakeSpace_4+0x1E : sub ecx,edi; add edx,ecx
    OV_MATCH(0x1E, 0x2B, 0xCF, 0x03, 0xD1),

    // CDevice::MakeSpace_4+0x2F : add esp,0x__
    OV_MATCH(0x2F, 0x83, 0xC4),

    // CDevice::MakeSpace_4+0x32 : ret
    OV_MATCH(0x32, 0xC3),

    //
);

// ******************************************************************
// * D3DDevice::SetRenderStateNotInline
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderStateNotInline,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // call D3DDevice_SetRenderState_Simple
    XREF_ENTRY(0x19, XREF_D3DDevice_SetRenderState_Simple),
    XREF_ENTRY(0x20, XREF_D3D_g_RenderState),

    // push esi
    OV_MATCH(0x00, 0x56),

    // jge +0x?? (0x1F vs LTCG 0x21)
    OV_MATCH(0x08, 0x7D),

    // ecx,[esi * 0x4 + 0x????]
    OV_MATCH(0x0A, 0x8B, 0x0C, 0xB5),

    // call D3DDevice_SetRenderState_Simple
    OV_MATCH(0x18, 0xE8),

    // After offset 0x24 has various instruction changes

    //
);

// ******************************************************************
// * D3DDevice::SetRenderState
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF_DETECT(D3DDevice_SetRenderState,
                             3911,
                             XRefOne,
                             DetectFirst)
OOVPA_SIG_MATCH(

    // D3DDevice::SetRenderState+0x02 : call D3DDevice_SetRenderStateNotInline
    XREF_ENTRY(0x03, XREF_D3DDevice_SetRenderStateNotInline),

    // D3DDevice::SetRenderState+0x00 : push eax; push ecx
    OV_MATCH(0x00, 0x50, 0x51),

    // D3DDevice::SetRenderState+0x02 : call D3DDevice_SetRenderStateNotInline
    OV_MATCH(0x02, 0xE8),

    // D3DDevice::SetRenderState+0x07 : ret
    OV_MATCH(0x07, 0xC3),

    //
);

// ******************************************************************
// * D3DDevice::SetRenderState (duplicate)
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// TODO: Add another macro to accept duplicates.
OOVPA_SIG_HEADER_XREF_DETECT(D3DDevice_SetRenderState2,
                             3911,
                             XRefOne,
                             DetectSecond)
OOVPA_SIG_MATCH(

    // D3DDevice::SetRenderState+0x02 : call D3DDevice_SetRenderStateNotInline
    XREF_ENTRY(0x03, XREF_D3DDevice_SetRenderStateNotInline),

    // D3DDevice::SetRenderState+0x00 : push eax; push ecx
    OV_MATCH(0x00, 0x50, 0x51),

    // D3DDevice::SetRenderState+0x02 : call D3DDevice_SetRenderStateNotInline
    OV_MATCH(0x02, 0xE8),

    // D3DDevice::SetRenderState+0x07 : ret
    OV_MATCH(0x07, 0xC3),

    //
);

// ******************************************************************
// * D3DDevice_SetRenderState_MultiSampleType
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetRenderState_MultiSampleType,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov [D3DRS_MultiSampleType],e??
    XREF_ENTRY(0x0E, XREF_D3DRS_MultiSampleType),

    // call D3DDevice_SetViewport
    XREF_ENTRY(0x1F, XREF_D3DDevice_SetViewport),

    // mov ecx,[esp + param_1]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x04),

    // call D3DDevice_SetViewport
    OV_MATCH(0x1E, 0xE8),

    // retn 0x04
    OV_MATCH(0x2B, 0xC2, 0x04),
    //
);

// ******************************************************************
// * D3DDevice_SetTextureStageStateNotInline
// ******************************************************************
OOVPA_SIG_HEADER_XREF(D3DDevice_SetTextureStageStateNotInline,
                      3911,
                      XRefOne)
OOVPA_SIG_MATCH(

    // mov D3D_g_DeferredTextureState[e?? * 4],e??
    XREF_ENTRY(0x27, XREF_D3D_g_DeferredTextureState),

    // mov eax,[esp + param_2]
    OV_MATCH(0x00, 0x8B, 0x44, 0x24, 0x08),
    // cmp eax,0x??
    OV_MATCH(0x04, 0x83, 0xF8),

    // shl e??,0x05
    OV_MATCH(0x13, 0xC1),
    OV_MATCH(0x15, 0x05),

    // mov D3D_g_DeferredTextureState[e?? * 4],e??
    OV_MATCH(0x24, 0x89),

    // retn 0x0C
    OV_MATCH(0x2F, 0xC2, 0x0C),
    //
);

// ******************************************************************
// * D3D::CreateTexture
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(D3D_CreateTexture,
                         3911)
OOVPA_SIG_MATCH(

    // mov edx,[esp + 0x20]
    // push ebx
    OV_MATCH(0x00, 0x8B, 0x54, 0x24, 0x20, 0x53),

    // unique instruction
    // and [esp + 0x30],0xFFFFFFF7
    OV_MATCH(0x4F, 0x83, 0x64, 0x24, 0x30, 0xF7),
    // push 0x14
    OV_MATCH(0x54, 0x6A, 0x14),
    // push 0x40
    OV_MATCH(0x56, 0x6A, 0x40),
    //
);

// ******************************************************************
// * D3DDevice_Suspend
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(D3DDevice_Suspend,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(

    // mov ecx,[D3D_g_pDevice]
    XREF_ENTRY(0x02, XREF_D3D_g_pDevice),

    // call D3D::CDevice::SetStateVB
    XREF_ENTRY(0x09, XREF_D3D_CDevice_SetStateVB),

    // mov ecx,[D3D_g_pDevice]
    OV_MATCH(0x00, 0x8B, 0x0D),
    // push 0x0
    // call D3D::CDevice::SetStateVB
    OV_MATCH(0x06, 0x6A, 0x00, 0xE8),
    // ret
    OV_MATCH(0x0D, 0xC3),
    //
);

// ******************************************************************
// * D3D::CDevice::FreeFrameBuffers
// ******************************************************************
OOVPA_SIG_HEADER_XREF(CDevice_FreeFrameBuffers,
                      3911,
                      XRefTwo)
OOVPA_SIG_MATCH(
    // call [AvGetSavedDataAddress]
    XREF_ENTRY(0x08, XREF_KT_FUNC_AvGetSavedDataAddress),
    // call [AvSendTVEncoderOption]
    XREF_ENTRY(0x20, XREF_KT_FUNC_AvSendTVEncoderOption),

    // push ebx
    // push ebp
    // push esi
    // push edi
    OV_MATCH(0x00, 0x53, 0x55, 0x56, 0x57),
    // mov esi, ecx
    // call [AvGetSavedDataAddress]
    OV_MATCH(0x04, 0x8B, 0xF1, 0xFF, 0x15),

    // call [AvSendTVEncoderOption]
    OV_MATCH(0x1E, 0xFF, 0x15),

    // push edx
    // call ????
    OV_MATCH(0x6E, 0x52, 0xE8),
    // mov [esi + 0x????], ebp
    OV_MATCH(0x74, 0x89, 0xAE),

    // cmp [esi + 0x????], ebp
    OV_MATCH(0x7A, 0x39, 0xAE),
    //
);

// ******************************************************************
// * D3D::CDevice::InitializeFrameBuffers
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(CDevice_InitializeFrameBuffers,
                         3911)
OOVPA_SIG_MATCH(
    // sub esp, 0x??
    OV_MATCH(0x00, 0x83, 0xEC),

    // jc +4
    // mov [esp + 0x??], eax
    OV_MATCH(0x1B, 0x72, 0x04, 0x89, 0x44, 0x24),

    // push eax
    // call ????
    OV_MATCH(0x24, 0x50, 0xE8),

    // mov e??, [e?? + 0x24]
    OV_MATCH(0x2A, 0x8B),
    OV_MATCH(0x2C, 0x24),
    //
);
