// ******************************************************************
// *
// *   OOVPADatabase->D3D8_OOVPA.inl
// *
// *  XbSymbolDatabase is free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// *
// *  (c) 2017 jarupxx
// *
// *  All rights reserved
// *
// ******************************************************************

// Titles which did compiled with full library version
//   [LibV] Title Name                       |  Verify   |   Comments
//-----------------------------------------------------------------------
// * [3925] Azurik                           |   100%    | Missing D3D_SetPushBufferSize due locate in BINK section, have 182/196 library.
// * [3948] Shikigami no Shiro               |   100%    | have 178/196 library.
// * [4034] Dark Summit                      |   100%    | have 113/195 library.
// * [4039] New Legends                      |   100%    | have 117/195 library.
// * [4134] Double-S.T.E.A.L                 |   100%    | have 195/202 library.
// * [4242] NFL Blitz 2002                   |   100%    | have 180/202 library.
// * [4361] Hunter The Reckoning             |   100%    | have 117/204 library.
// * [4432] RedCard 2003                     |   100%    | have 184/206 library.
// * [4531] NHL HITZ 2003                    |   100%    | have 196/206 library.
// * [4627] MLB SlugFest 2003                |   100%    | have 216/227 library.
// * [4721] Terminator - Dawn of Fate        |   100%    | have 202/227 library.
// * [4831] Frogger Beyond                   |   100%    | have 200/227 library.
// * [4928] Drihoo                           |   100%    | have 201/228 library.
// * [5028] Shikigami no Shiro Evolution     |   100%    | have 201/229 library.
// * [5120] N.U.D.E.@                        |   100%    | have 211/229 library.
// * [5233] Evil Dead                        |   100%    | have 208/230 library.
// * [5344] Gladius DEMO                     |   100%    | have 202/229 library.
// * [5455] Dinosaur Hunting                 |   100%    | have 207/229 library.
// * [5558] NHL HITZ Pro 2004                |   100%    | have 218/230 library.
// * [5558] XIII                             |   100%    | With Intergrated Hotfixes. have 209/230 library.
// * [5659] NFL Blitz Pro                    |   100%    | have 208/230 library.
// * [5659] Midway Arcade Treasures Paperboy |   100%    | With Intergrated Hotfixes. have 212/230 library.
// * [5788] Digimon Battle Chronicle         |   100%    | have 210/230 library.
// * [5849] Nickelodeon Tak 2                |   100%    | have 210/229 library.

// TODO: Known D3D8 OOVPA issue list
//   * CMiniport_IsFlipPending is XREF in v1 database, any reason for this?
// * Verification needed: Function Name ( Revision )
//   * D3D_AllocContiguousMemory (4034, 4242)
//   * D3D_ClearStateBlockFlags (4034, 4039, 4721, 5028, 5120)
//   * D3D_GetAdapterIdentifier (4034)
//   * D3D_RecordStateBlock (4034, 4039, 4721, 5028, 5120)
//   * D3D_SetPushBufferSize (4034)
//   * D3DBaseTexture_GetLevelCount (4034)
//   * D3DCubeTexture_GetCubeMapSurface (5233)
//   * D3DDevice_AddRef (4034)
//   * D3DDevice_ApplyStateBlock (4034, 4039, 4721, 4831, 5028, 5120)
//   * D3DDevice_Begin (4034)
//   * D3DDevice_BeginPushBuffer (3950, 4034, 4242, 4831, 5028)
//   * D3DDevice_BeginStateBlock (3950, 4034, 4039, 4721, 4831, 5028, 5120)
//   * D3DDevice_BlockOnFence (4034)
//   * D3DDevice_CaptureStateBlock (4034, 4039, 4432, 4721, 4831, 5028, 5120)
//   * D3DDevice_CreateCubeTexture (4721, 5028, 5233)
//   * D3DDevice_CreateImageSurface (4721, 5028, 5120)
//   * D3DDevice_CreateIndexBuffer (4721, 4928)
//   * D3DDevice_CreatePalette (4721, 4831, 4928, 5120, 5233, 5455)
//   * D3DDevice_CreateStateBlock (4034, 4039, 4242, 4432, 4721, 4928, 5028, 5120)
//   * D3DDevice_CreateVolumeTexture (5028, 5120, 5233, 5455)
//   * D3DDevice_DeletePatch (3950, 4134, 4242, 4432, 4721, 4928, 5028, 5120, 5233, 5455)
//   * D3DDevice_DeleteStateBlock (3950, 4034, 4039, 4721, 4831, 5028, 5120)
//   * D3DDevice_DeleteVertexShader (4034)
//   * D3DDevice_DrawIndexedVerticesUP (4034)
//   * D3DDevice_DrawRectPatch (3950, 4242, 4432, 4721, 4928, 5028, 5120, 5233, 5455)
//   * D3DDevice_DrawTriPatch (3950, 4034, 4039, 4242, 4432, 4721, 4831, 4928, 5028, 5120, 5233, 5455)
//   * D3DDevice_DrawVerticesUP (4034)
//   * D3DDevice_EnableOverlay (3950, 4034, 4039)
//   * D3DDevice_End (4034)
//   * D3DDevice_EndPushBuffer (3950, 4034, 4242, 4831, 5028)
//   * D3DDevice_EndStateBlock (3950, 4034, 4039, 4721, 4831, 5028, 5120)
//   * D3DDevice_FlushVertexCache (4034, 4039)
//   * D3DDevice_GetBackBuffer (4721, 4831, 4928, 5028, 5120, 5233, 5455)
//   * D3DDevice_GetBackMaterial (4034)
//   * D3DDevice_GetDepthStencilSurface (4034)
//   * D3DDevice_GetDisplayFieldStatus (4034)
//   * D3DDevice_GetDisplayMode (4034)
//   * D3DDevice_GetLightEnable (4034)
//   * D3DDevice_GetMaterial (4034)
//   * D3DDevice_GetModelView (4034)
//   * D3DDevice_GetOverlayUpdateStatus (3950, 4034, 4039, 4134, 4242, 4432, 4531)
//   * D3DDevice_GetPixelShader (4034)
//   * D3DDevice_GetProjectionViewportMatrix (4034, 4039)
//   * D3DDevice_GetPushBufferOffset (3950, 4034, 4242, 4831, 5028)
//   * D3DDevice_GetRenderTarget (4034, 5028)
//   * D3DDevice_GetScissors (4034)
//   * D3DDevice_GetShaderConstantMode (4034, 4039)
//   * D3DDevice_GetTexture2 (4034, 4039)
//   * D3DDevice_GetTile (4034)
//   * D3DDevice_GetVertexShader (4034)
//   * D3DDevice_GetVertexShaderConstant (4034)
//   * D3DDevice_GetVertexShaderDeclaration (4034)
//   * D3DDevice_GetVertexShaderFunction (4034)
//   * D3DDevice_GetVertexShaderInput (4034)
//   * D3DDevice_GetVertexShaderSize (4034)
//   * D3DDevice_GetVertexShaderType (4034)
//   * D3DDevice_InsertCallback (4034, 4039)
//   * D3DDevice_InsertFence (4034)
//   * D3DDevice_IsFencePending (4034)
//   * D3D_CDevice_KickOff (5455,5849)
//   * D3DDevice_KickPushBuffer (4034)
//   * D3DDevice_LoadVertexShaderProgram (4034)
//   * D3DDevice_PersistDisplay (4034)
//   * D3DDevice_PrimeVertexCache (4034)
//   * D3DDevice_RunPushBuffer (4034, 4831, 5028)
//   * D3DDevice_RunVertexStateShader (4034)
//   * D3DDevice_SetBackMaterial (4034)
//   * D3DDevice_SetModelView (4034)
//   * D3DDevice_SetPixelShaderConstant (4034)
//   * D3DDevice_SetPixelShaderProgram (4034)
//   * D3DDevice_SetVertexData2f (4034)
//   * D3DDevice_SetVertexData2s (4034)
//   * D3DDevice_SetVertexData4f (4034)
//   * D3DDevice_SetVertexData4s (4034)
//   * D3DDevice_SetVertexData4ub (4034)
//   * D3DDevice_SetVertexDataColor (4034)
//   * D3DDevice_SetVertexShaderInput (4034)
//   * D3DDevice_SetVerticalBlankCallback (4034)
//   * D3DDevice_SwitchTexture (4034)
//   * D3DDevice_UpdateOverlay (3950, 4034, 4039)
//   * D3DPalette_Lock (4721, 4831, 4928, 5120)
//   * D3DResource_BlockUntilNotBusy (4034)
//   * D3DResource_IsBusy (4034)
//   * D3DResource_Register (4034)
//   * D3DVertexBuffer_GetDesc (4034)
//   * D3DVertexBuffer_Lock (4721, 4831, 4928, 5120, 5233, 5455)
//   * Direct3D_CheckDeviceMultiSampleType (4034)
//   * CMiniport_IsFlipPending (4034, 4039, 4134, 4928, 5028, 5120, 5233, 5455)
//   * D3D_EnumAdapterModes (4034)
//   * D3D_GetAdapterDisplayMode (4034)
//   * D3D_GetAdapterModeCount (4034)
//   * IDirect3DVertexBuffer8_Lock (4721, 5028, 5120, 5233)
// * List of functions might be D3D8LTCG library: (Verifying with Sega GT 2002 title)
//   * D3D_CreateDeviceX (4627)
//   * D3D_KickOffAndWaitForIdle2 (4627)
//   * D3D_CommonSetRenderTargetB (4627)

#ifndef D3D8_OOVPA_INL
#define D3D8_OOVPA_INL

#include "OOVPA.h"

#include "D3D8/3911.inl"
#include "D3D8/3925.inl"
#include "D3D8/3947.inl"
#include "D3D8/4034.inl"
#include "D3D8/4039.inl"
#include "D3D8/4134.inl"
#include "D3D8/4242.inl"
#include "D3D8/4361.inl"
#include "D3D8/4432.inl"
#include "D3D8/4531.inl"
#include "D3D8/4627.inl"
#include "D3D8/4831.inl"
#include "D3D8/4928.inl"
#include "D3D8/5028.inl"
#include "D3D8/5120.inl"
#include "D3D8/5233.inl"
#include "D3D8/5344.inl"
#include "D3D8/5455.inl"
#include "D3D8/5558.inl"
#include "D3D8/5788.inl"
#include "D3D8/5849.inl"

#define REGISTER_OOVPAS_D3D(Symbol, ...)  REGISTER_OOVPAS_PREFIX(D3D, Symbol, __VA_ARGS__)
#define REGISTER_OOVPAS_D3D8(Symbol, ...) REGISTER_OOVPAS_PREFIX(D3D8, Symbol, __VA_ARGS__)

// ******************************************************************
// * D3D8_OOVPA
// ******************************************************************
OOVPATable D3D8_OOVPA[] = {
    // Custom manual search by reverse engineering team (which will not be public to the user)
    REGISTER_OOVPAS_M(SYM_INT(D3DDevice__m_VerticalBlankEvent__GenericFragment),
                      SYM_SIG(3911)), // This OOVPA signature is not a symbol. Read its note for more details.
    REGISTER_OOVPAS_M(SYM_INT(D3DRS_Stencils_and_Occlusion__GenericFragment),
                      SYM_SIG(3911)), // This OOVPA signature is not a symbol. Read its note for more details.

    // Variables
    REGISTER_OOVPAS_M(SYM_VAR(D3D_g_pDevice),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_PixelShader_OFFSET),
                      SYM_SIG(0)),
#if 0 // Unused
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_Textures_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_Palettes_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_RenderTarget_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_DepthStencil_OFFSET),
                      SYM_SIG(0)),
#endif
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_VerticalBlankEvent_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_SwapCallback_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_VBlankCallback_OFFSET),
                      SYM_SIG(0)),
    REGISTER_OOVPAS_M(SYM_VAR(D3DDevice__m_VertexShader_OFFSET),
                      SYM_SIG(0)),

    REGISTER_OOVPAS(SYM_FUN(D3D_UpdateProjectionViewportTransform, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3900, 3901)), // Final generic OOVPA: 4034; Removed: 0 // NOTE: 3901 is 4034 signature, except LTCG title been detected in 3925.

    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_InitializeFrameBuffers, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_FreeFrameBuffers, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this), PARAM(stk, pPresentationParams))),
                        SYM_SIG(3911, 4034, 5455)), // Final generic OOVPA: 5455; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_SetStateUP, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_SetStateVB, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this), PARAM(stk, unknown2))), // TODO: Update unknown parameter name(s) if able.
                        SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0 // thiscall

    REGISTER_OOVPAS(SYM_FUN(D3D_CreateTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Width), PARAM(stk, Height), PARAM(stk, Depth), PARAM(stk, Levels), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, isCube), PARAM(stk, isVolume), PARAM(stk, ppTexture))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_MakeSpace, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911)), // thiscall // NOTE: has multiple rets.
    REGISTER_OOVPAS_D3D(SYM_FUN(CMiniport_CreateCtxDmaObject, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this), PARAM(stk, unknown1), PARAM(stk, unknown2), PARAM(stk, unknown3), PARAM(stk, unknown4), PARAM(stk, unknown5))), // TODO: Update unknown parameter name(s) if able.
                        SYM_SIG(3911, 4034)), // thiscall
    REGISTER_OOVPAS_D3D(SYM_FUN(CMiniport_InitHardware, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911, 4034, 5455)), // thiscall
    REGISTER_OOVPAS_D3D(SYM_FUN(CMiniport_IsFlipPending, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911, 4242, 4627, 4928)), // thiscall
    REGISTER_OOVPAS(SYM_FUN(D3DBaseTexture_GetLevelCount, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DCubeTexture_GetCubeMapSurface2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, FaceType), PARAM(stk, Level))),
                    SYM_SIG(4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DCubeTexture_GetCubeMapSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, FaceType), PARAM(stk, Level), PARAM(stk, ppCubeMapSurface))),
                    SYM_SIG(3911, 4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DCubeTexture_LockRect, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, FaceType), PARAM(stk, Level), PARAM(stk, pLockedBox), PARAM(stk, pRect), PARAM(stk, Flags))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_AddRef, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4039, 4134, 4242, 4627, 5028, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_ApplyStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Token))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Begin, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PrimitiveType))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginPush, CALL(unk), STACK(8), PARAMS(PARAM(stk, Count), PARAM(stk, ppPush))),
                    SYM_SIG(4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginPush, CALL(unk), STACK(4), PARAMS(PARAM(stk, Count))),
                    SYM_SIG(4531, 4627, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginPushBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPushBuffer))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginStateBig, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, unknown1))), // TODO: Update unknown parameter name(s) if able.
                    SYM_SIG(5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BeginVisibilityTest, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BlockOnFence, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Fence))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_BlockUntilVerticalBlank, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CaptureStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Token))),
                    SYM_SIG(3911, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Clear, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Count), PARAM(stk, pRects), PARAM(stk, Flags), PARAM(stk, Color), PARAM(stk, Z), PARAM(stk, Stencil))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CopyRects, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pSourceSurface), PARAM(stk, pSourceRectsArray), PARAM(stk, cRects), PARAM(stk, pDestinationSurface), PARAM(stk, pDestPointsArray))),
                    SYM_SIG(3911, 4034, 4627, 5120)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateCubeTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, EdgeLength), PARAM(stk, Levels), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, Pool), PARAM(stk, ppCubeTexture))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateImageSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Width), PARAM(stk, Height), PARAM(stk, Format), PARAM(stk, ppBackBuffer))),
                    SYM_SIG(3911, 4034, 4627)), // TODO 4721,4928 (from 4627's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateIndexBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Length), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, Pool), PARAM(stk, ppIndexBuffer))),
                    SYM_SIG(3911, 4627)), // TODO: This needs to be verified on 4361
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateIndexBuffer2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Length))),
                    SYM_SIG(4627, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreatePalette, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Size), PARAM(stk, ppPalette))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreatePalette2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Size))),
                    SYM_SIG(4627, 5344, 5455)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreatePixelShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPSDef), PARAM(stk, pHandle))),
                    SYM_SIG(3911, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Type), PARAM(stk, pToken))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateTexture2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Width), PARAM(stk, Height), PARAM(stk, Depth), PARAM(stk, Levels), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, D3DResource))),
                    SYM_SIG(4627, 4831)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Width), PARAM(stk, Height), PARAM(stk, Levels), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, Pool), PARAM(stk, ppTexture))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateVertexBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Length), PARAM(stk, Usage), PARAM(stk, FVF), PARAM(stk, Pool), PARAM(stk, ppVertexBuffer))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateVertexBuffer2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Length))),
                    SYM_SIG(4627, 5344, 5455)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pDeclaration), PARAM(stk, pFunction), PARAM(stk, pHandle), PARAM(stk, Usage))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_CreateVolumeTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Width), PARAM(stk, Height), PARAM(stk, Depth), PARAM(stk, Levels), PARAM(stk, Usage), PARAM(stk, Format), PARAM(stk, Pool), PARAM(stk, ppVolumeTexture))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DeletePatch, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DeletePixelShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle))),
                    SYM_SIG(3911, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DeleteStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Token))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DeleteVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle))),
                    SYM_SIG(3911, 5344)), // Final generic OOVPA: 5344; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawIndexedVertices, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PrimitiveType), PARAM(stk, VertexCount), PARAM(stk, pIndexData))),
                    SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawIndexedVerticesUP, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PrimitiveType), PARAM(stk, VertexCount), PARAM(stk, pIndexData), PARAM(stk, pVertexStreamZeroData), PARAM(stk, VertexStreamZeroStride))),
                    SYM_SIG(3911, 5028, 5344)), // Final generic OOVPA: 5344; Removed: 0 // TODO: Need verify title with 4034 version.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawRectPatch, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pNumSegs), PARAM(stk, pRectPatchInfo))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawTriPatch, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pNumSegs), PARAM(stk, pTriPatchInfo))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawVertices, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PrimitiveType), PARAM(stk, StartVertex), PARAM(stk, VertexCount))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_DrawVerticesUP, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PrimitiveType), PARAM(stk, VertexCount), PARAM(stk, pVertexStreamZeroData), PARAM(stk, VertexStreamZeroStride))),
                    SYM_SIG(3911, 4039, 5344)), // Final generic OOVPA: 5344; Removed: 0 // TODO: Need verify title with 4034 version.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_EnableOverlay, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Enable))),
                    SYM_SIG(3911, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_End, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4039, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_EndPush, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPush))),
                    SYM_SIG(4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_EndPushBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_EndStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pToken))),
                    SYM_SIG(3911, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_EndVisibilityTest, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_FlushVertexCache, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetBackBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, BackBuffer), PARAM(stk, Type), PARAM(stk, ppBackBuffer))),
                    SYM_SIG(3911, 4034, 4134, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetBackBuffer2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, BackBuffer))),
                    SYM_SIG(4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetBackMaterial, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pMaterial))),
                    SYM_SIG(3911, 4039, 4134, 4627, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetCreationParameters, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pParameters))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetDepthStencilSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, ppZStencilSurface))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetDepthStencilSurface2, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetDeviceCaps, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pCaps))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetDisplayFieldStatus, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pFieldStatus))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetDisplayMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pModes))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetGammaRamp, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pRamp))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetLight, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pLight))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetLightEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pEnable))),
                    SYM_SIG(3911, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetMaterial, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pMaterial))),
                    SYM_SIG(3911, 4039, 4134, 4627, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetModelView, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pModelView))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetOverlayUpdateStatus, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetPersistedSurface2, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(4928)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetPixelShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Name), PARAM(stk, pHandle))),
                    SYM_SIG(3911, 4039, 4134, 5028, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetProjectionViewportMatrix, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pProjectionViewport))),
                    SYM_SIG(3911, 4134, 4627, 5344, 5558)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetPushBufferOffset, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pOffset))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetRenderTarget2, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetRenderTarget, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, ppRenderTarget))),
                    SYM_SIG(3911, 4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetScissors, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pCount), PARAM(stk, pExclusive), PARAM(stk, pRects))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetShaderConstantMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pMode))),
                    SYM_SIG(3911, 4134, 4627, 5028, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetStreamSource2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, StreamNumber), PARAM(stk, pStride))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetTexture2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage))),
                    SYM_SIG(3911, 4134, 4627, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetTile, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pTile))),
                    SYM_SIG(3911, 5455)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetTransform, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, pMatrix))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pHandle))),
                    SYM_SIG(3911, 4039, 4134, 5028, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderConstant, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, pConstantData), PARAM(stk, ConstantCount))),
                    SYM_SIG(3911, 4039, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderDeclaration, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pData), PARAM(stk, pSizeOfData))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderFunction, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pData), PARAM(stk, pSizeOfData))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderInput, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pHandle), PARAM(stk, pStreamCount), PARAM(stk, pStreamInputs))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderSize, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pSize))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVertexShaderType, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, pType))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetViewport, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pViewport))),
                    SYM_SIG(3911, 5455)), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetViewportOffsetAndScale, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pOffset), PARAM(stk, pScale))),
                    SYM_SIG(4432)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_GetVisibilityTestResult, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pResult), PARAM(stk, pTimeStamp))),
                    SYM_SIG(3911, 5233)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_InsertCallback, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Type), PARAM(stk, pCallback), PARAM(stk, Context))),
                    SYM_SIG(3911, 4134, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_InsertFence, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_IsBusy, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_IsFencePending, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Fence))),
                    SYM_SIG(3911, 4039, 5028)),
    REGISTER_OOVPAS_D3D(SYM_FUN(CDevice_KickOff, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this))),
                        SYM_SIG(3911, 4034, 4531, 5028, 5455)), // Final generic OOVPA: 5455; Removed: 0 // thiscall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_KickPushBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_LightEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, bEnable))),
                    SYM_SIG(3911, 5344)), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_LoadVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, Address))),
                    SYM_SIG(3911, 4034, 4627, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_LoadVertexShaderProgram, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pFunction), PARAM(stk, Address))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_MakeSpace, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(4034, 4134)), // NOTE: LTCG has duplicate functions, need to find out how to resolve this issue with cross referencing.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_PersistDisplay, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4039, 4627, 4831)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Present, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pSourceRect), PARAM(stk, pDestRect), PARAM(stk, pUnused3), PARAM(stk, pUnused4))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_PrimeVertexCache, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, VertexCount), PARAM(stk, pIndexData))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Release, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Reset, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPresentationParameters))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_RunPushBuffer, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPushBuffer), PARAM(stk, pFixup))),
                    SYM_SIG(3911, 4039, 4627, 5120, 5558)), // for 5455 (from 5558's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_RunVertexStateShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Address), PARAM(stk, pData))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SelectVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, Address))),
                    SYM_SIG(3911, 4034, 5455)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SelectVertexShaderDirect, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pVAF), PARAM(stk, Address))),
                    SYM_SIG(4361)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetBackBufferScale, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, x), PARAM(stk, y))),
                    SYM_SIG(4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetBackMaterial, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pMaterial))),
                    SYM_SIG(3911, 4039, 4134, 4627, 5344, 5558, 5788)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetDepthClipPlanes, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Near), PARAM(stk, Far), PARAM(stk, Flags))),
                    SYM_SIG(4432)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetFlickerFilter, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Filter))),
                    SYM_SIG(3911, 4034, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetGammaRamp, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, dwFlags), PARAM(stk, pRamp))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetIndices, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pIndexData), PARAM(stk, BaseVertexIndex))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetLight, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pLight))),
                    SYM_SIG(3911, 5344)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetMaterial, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pMaterial))),
                    SYM_SIG(3911, 4034, 4134, 4627, 5344, 5558, 5788)), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetModelView, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pModelView), PARAM(stk, pInverseModelView), PARAM(stk, pComposite))),
                    SYM_SIG(3911, 4039, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetPalette, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, pPalette))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetPixelShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle))),
                    SYM_SIG(3911, 4034, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetPixelShaderConstant, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, pConstantData), PARAM(stk, ConstantCount))),
                    SYM_SIG(3911, 4831)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetPixelShaderProgram, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPSDef))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS_M(SYM_FUN(D3DDevice_SetRenderState_Simple, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Method), PARAM(edx, Value))),
                      SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0 // fastcall
    REGISTER_OOVPAS_M(SYM_FUN(D3DDevice_SetRenderStateNotInline, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, Value))),
                      SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0 // NOTE: Must be after D3DDevice_SetRenderState_Simple.
    // NOTE: Some or most of render state signatures below must be after D3DDevice_SetRenderStateNotInline.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0 // NOTE: There is a verified duplicate function.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_BackFillMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS_C(SYM_FUN(D3DDevice_SetRenderState_CullMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                      SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_Deferred, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, State), PARAM(edx, Value))),
                    SYM_SIG(3911)), // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_DoNotCullUncompressed, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_Dxt1NoiseEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_EdgeAntiAlias, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS_M(SYM_FUN(D3DDevice_SetRenderState_FillMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                      SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_FogColor, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_FrontFace, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_LineWidth, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_LogicOp, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_MultiSampleAntiAlias, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_MultiSampleMask, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_MultiSampleMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_MultiSampleRenderTargetMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_MultiSampleType, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 3925)), // Final generic OOVPA: 3925 Removed: 4034
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_NormalizeNormals, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_OcclusionCullEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 1024)), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_PSTextureModes, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_RopZCmpAlwaysRead, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_RopZRead, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_SampleAlpha, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(4627)), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_ShadowFunc, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_StencilCullEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 1024)), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_StencilEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034, 5849)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_StencilFail, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034, 5849)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_TextureFactor, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_TwoSidedLighting, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034, 5344)), // Final generic OOVPA: 5344; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_VertexBlend, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_YuvEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 1024)), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_ZBias, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderState_ZEnable, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Value))),
                    SYM_SIG(3911, 4034, 4134, 4432)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderTarget, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pRenderTarget), PARAM(stk, pNewZStencil))),
                    SYM_SIG(3911, 3947, 4034, 4039, 4627, 5344, 5455)), // Final generic OOVPA: 5344/5455; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetRenderTargetFast, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pRenderTarget), PARAM(stk, pNewZStencil), PARAM(stk, Flags))),
                    SYM_SIG(5233)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetScissors, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Count), PARAM(stk, Exclusive), PARAM(stk, pRects))),
                    SYM_SIG(3911, 5344, 5558)), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetScreenSpaceOffset, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, x), PARAM(stk, y))),
                    SYM_SIG(4034, 5455)), // Final generic OOVPA: 5455; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetShaderConstantMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Mode))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetSoftDisplayFilter, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Enable))),
                    SYM_SIG(3911, 4034, 4134)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetStipple, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPattern))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetStreamSource, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, StreamNumber), PARAM(stk, pStreamData), PARAM(stk, Stride))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetSwapCallback, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pCallback))),
                    SYM_SIG(4039)), // Final generic OOVPA: 4039; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, pTexture))),
                    SYM_SIG(3911, 4034, 4361, 4831)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTextureStageStateNotInline, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, Type), PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTextureState_BorderColor, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTextureState_BumpEnv, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, Type), PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTextureState_ColorKeyColor, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, Value))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS_C(SYM_FUN(D3DDevice_SetTextureState_TexCoordIndex, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Stage), PARAM(stk, Value))),
                      SYM_SIG(3911, 4034, 4242, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTile, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pTile))),
                    SYM_SIG(3911, 4034, 4627)), // Then it has changed calls ?SetTileNoWait@D3D@@YGXKPBU_D3DTILE@@@Z in XDK 4627 and higher.
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetTransform, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, pMatrix))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_MultiplyTransform, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, State), PARAM(stk, pMatrix))),
                    SYM_SIG(3911, 4034)), // TODO: Verify 4034 is correct
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexData2f, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, a), PARAM(stk, b))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexData2s, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, a), PARAM(stk, b))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexData4f, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, a), PARAM(stk, b), PARAM(stk, c), PARAM(stk, d))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexData4s, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, a), PARAM(stk, b), PARAM(stk, c), PARAM(stk, d))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexData4ub, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, a), PARAM(stk, b), PARAM(stk, c), PARAM(stk, d))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexDataColor, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, Color))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShader, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle))),
                    SYM_SIG(3911, 4034, 4134, 5028, 5455)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstant, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Register), PARAM(stk, pConstantData), PARAM(stk, ConstantCount))),
                    SYM_SIG(3911, 4034, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstant1, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Register), PARAM(edx, pConstantData))),
                    SYM_SIG(4627)), // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstant1Fast, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Register), PARAM(edx, pConstantData))),
                    SYM_SIG(4627)), // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstant4, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Register), PARAM(edx, pConstantData))),
                    SYM_SIG(4627)), // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstantNotInline, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Register), PARAM(edi, pConstantData), PARAM(stk, ConstantCount))),
                    SYM_SIG(4627, 5028, 5558)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderConstantNotInlineFast, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Register), PARAM(edi, pConstantData), PARAM(stk, ConstantCount))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderInput, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Handle), PARAM(stk, StreamCount), PARAM(stk, pStreamInputs))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVertexShaderInputDirect, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pVAF), PARAM(stk, StreamCount), PARAM(stk, pStreamInputs))),
                    SYM_SIG(4361)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetVerticalBlankCallback, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pCallback))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SetViewport, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pViewport))),
                    SYM_SIG(3911, 4034, 5344, 5455)), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Suspend, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_Swap, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Flags))),
                    SYM_SIG(4034, 4531, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_SwitchTexture, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, Method), PARAM(edx, Data), PARAM(stk, Format))),
                    SYM_SIG(3911)), // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3DDevice_UpdateOverlay, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pSurface), PARAM(stk, SrcRect), PARAM(stk, DstRect), PARAM(stk, EnableColorKey), PARAM(stk, ColorKey))),
                    SYM_SIG(3911, 4531, 5233)),
    REGISTER_OOVPAS(SYM_FUN(D3DPalette_Lock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, ppColors), PARAM(stk, Flags))),
                    SYM_SIG(3911, 4531, 4627)), // Called D3DPalette_Lock2 (from 4627's comment) NOTE: Use D3DPalette_Lock2 for 4627 and above
    REGISTER_OOVPAS(SYM_FUN(D3DPalette_Lock2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, Flags))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DResource_AddRef, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DResource_BlockUntilNotBusy, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DResource_GetType, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911, 4034)), // Probably not even necessary... (from 3925's comment) // I forget why I had this in here... (from 5028's comment)
    REGISTER_OOVPAS(SYM_FUN(D3DResource_IsBusy, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911, 4039)),
    REGISTER_OOVPAS(SYM_FUN(D3DResource_Register, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, pBase))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DResource_Release, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DSurface_GetDesc, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, pDesc))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DSurface_LockRect, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, pLockedRect), PARAM(stk, pRect), PARAM(stk, Flags))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DTexture_GetSurfaceLevel, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, Level), PARAM(stk, ppSurfaceLevel))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DTexture_GetSurfaceLevel2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, Level))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DTexture_LockRect, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, Level), PARAM(stk, pLockedRect), PARAM(stk, pRect), PARAM(stk, Flags))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DVertexBuffer_GetDesc, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, pDesc))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3DVertexBuffer_Lock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pVertexBuffer), PARAM(stk, OffsetToLock), PARAM(stk, SizeToLock), PARAM(stk, ppbData), PARAM(stk, Flags))),
                    SYM_SIG(3911, 4034, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DVertexBuffer_Lock2, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pVertexBuffer), PARAM(stk, Flags))),
                    SYM_SIG(4627)),
    REGISTER_OOVPAS(SYM_FUN(D3DVolumeTexture_LockBox, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pThis), PARAM(stk, Level), PARAM(stk, pLockedVolume), PARAM(stk, pBox), PARAM(stk, Flags))),
                    SYM_SIG(3911)), // Just calls Lock3DSurface (from 4134, 4432's comment)
    REGISTER_OOVPAS(SYM_FUN(D3D_AllocContiguousMemory, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, dwSize), PARAM(stk, dwAllocAttributes))),
                    SYM_SIG(3911, 5455)), // Final generic OOVPA: 5455; Removed: 0 // Just calls MmAllocateContiguousMemory.
    REGISTER_OOVPAS(SYM_FUN(D3D_BlockOnResource, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pResource))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3D_BlockOnTime, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, unknown1), PARAM(stk, unknown2))), // TODO: Update unknown parameter name(s) if able. Both parameters do change over time. Likely may need a separate group...
                    SYM_SIG(3911, 4034, 4627, 5028, 5558)), // NOTE: unknown2 parameter can be different value from same caller function over time.
    REGISTER_OOVPAS_D3D(SYM_FUN(CMiniport_GetDisplayCapabilities, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                        SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_CheckDeviceFormat, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, DeviceType), PARAM(stk, AdapterFormat), PARAM(stk, Usage), PARAM(stk, RType), PARAM(stk, CheckFormat))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_ClearStateBlockFlags, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS_M(SYM_FUN(D3D_CommonSetDebugRegisters, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                      SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(D3D_CommonSetRenderTarget, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pRenderTarget), PARAM(stk, pNewZStencil), PARAM(stk, pUnknown3))),
                    SYM_SIG(4627, 5028)), // Final generic OOVPA: 4627; Removed: 5344
    REGISTER_OOVPAS(SYM_FUN(D3D_CommonSetMultiSampleModeAndScale, CALL(unk), STACK(/*default*/), PARAMS(PARAM(ecx, this), PARAM(edx, pViewport))),
                    SYM_SIG(5344)), // Final generic OOVPA: 5344; Removed: 0 // fastcall
    REGISTER_OOVPAS(SYM_FUN(D3D_CreateStandAloneSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, unknown1), PARAM(stk, unknown2), PARAM(stk, unknown3), PARAM(stk, unknown4))), // TODO: Update unknown parameter name(s) if able.
                    SYM_SIG(4034)),
    REGISTER_OOVPAS(SYM_FUN(D3D_DestroyResource, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pResource))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_EnumAdapterModes, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, Mode), PARAM(stk, pMode))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_GetAdapterDisplayMode, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, pMode))),
                    SYM_SIG(3911, 4627)),
    REGISTER_OOVPAS(SYM_FUN(D3D_GetAdapterIdentifier, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, Flags), PARAM(stk, pIdentifier))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_GetAdapterModeCount, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, Format))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_GetDeviceCaps, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, DeviceType), PARAM(stk, pCaps))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_KickOffAndWaitForIdle, CALL(unk), STACK(/*default*/), PARAMS(PARAM1(void))),
                    SYM_SIG(3911, 4034, 4627, 5028)),
    REGISTER_OOVPAS(SYM_FUN(D3D_LazySetPointParams, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Device))),
                    SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS(SYM_FUN(D3D_RecordStateBlock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pToken))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_SetFence, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Flags))),
                    SYM_SIG(3911, 4034, 4134, 5028, 5558)),
    REGISTER_OOVPAS(SYM_FUN(D3D_SetPushBufferSize, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, PushBufferSize), PARAM(stk, KickOffSize))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_SetTileNoWait, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Index), PARAM(stk, pTile))),
                    SYM_SIG(4627, 5455)), // Final generic OOVPA: 5455; Removed: 0
    REGISTER_OOVPAS(SYM_FUN(Direct3D_CheckDeviceMultiSampleType, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, DeviceType), PARAM(stk, SurfaceFormat), PARAM(stk, Windowed), PARAM(stk, MultiSampleType))),
                    SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(Direct3D_CreateDevice, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, Adapter), PARAM(stk, DeviceType), PARAM(stk, hFocusWindow), PARAM(stk, BehaviorFlags), PARAM(stk, pPresentationParameters), PARAM(stk, ppReturnedDeviceInterface))),
                    SYM_SIG(3911, 5028)),
    REGISTER_OOVPAS_D3D8(SYM_FUN(Get2DSurfaceDesc, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPixelContainer), PARAM(stk, dwLevel), PARAM(stk, pDesc))),
                         SYM_SIG(3911, 4034)),
    REGISTER_OOVPAS_D3D8(SYM_FUN(Lock2DSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPixelContainer), PARAM(stk, FaceType), PARAM(stk, Level), PARAM(stk, pLockedRect), PARAM(stk, pRect), PARAM(stk, Flags))),
                         SYM_SIG(3911)),
    REGISTER_OOVPAS_D3D8(SYM_FUN(Lock3DSurface, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pPixelContainer), PARAM(stk, Level), PARAM(stk, pLockedVolume), PARAM(stk, pBox), PARAM(stk, Flags))),
                         SYM_SIG(3911)),
    REGISTER_OOVPAS(SYM_FUN(D3D_MakeRequestedSpace, CALL(unk), STACK(4), PARAMS(PARAM(stk, RequestedSpace))),
                    SYM_SIG(4034)), // Final generic OOVPA: 4034??; Removed: 4134 // NOTE: has multiple rets.
    REGISTER_OOVPAS(SYM_FUN(D3D_MakeRequestedSpace, CALL(unk), STACK(8), PARAMS(PARAM(stk, MinimumSpace), PARAM(stk, RequestedSpace))),
                    SYM_SIG(4134, 5558)), // Final generic OOVPA: 5558; Removed: 0 // NOTE: has multiple rets.
    REGISTER_OOVPAS(SYM_FUN(XMETAL_StartPush, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pDevice))),
                    SYM_SIG(3911)), // Final generic OOVPA: 3911; Removed: 4034??
    REGISTER_OOVPAS(SYM_FUN(IDirect3DVertexBuffer8_Lock, CALL(unk), STACK(/*default*/), PARAMS(PARAM(stk, pVertexBuffer), PARAM(stk, OffsetToLock), PARAM(stk, SizeToLock), PARAM(stk, ppbData), PARAM(stk, Flags))),
                    SYM_SIG(4627)),
};


// ******************************************************************
// * D3D8_OOVPA_COUNT
// ******************************************************************
#define D3D8_OOVPA_COUNT XBSDB_ARRAY_SIZE(D3D8_OOVPA)

#endif
