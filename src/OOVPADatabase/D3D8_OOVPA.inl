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
    REGISTER_OOVPAS_M(D3DDevice__m_VerticalBlankEvent__GenericFragment, 3911), // This OOVPA signature is not a symbol. Read its note for more details.
    REGISTER_OOVPAS_M(D3DRS_Stencils_and_Occlusion__GenericFragment, 3911), // This OOVPA signature is not a symbol. Read its note for more details.

    REGISTER_OOVPAS(D3D_UpdateProjectionViewportTransform, 3900, 3901), // Final generic OOVPA: 4034; Removed: 0 // NOTE: 3901 is 4034 signature, except LTCG title been detected in 3925.

    REGISTER_OOVPAS_D3D(CDevice_InitializeFrameBuffers, 3911), // Final generic OOVPA: 3911; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(CDevice_FreeFrameBuffers, 3911, 4034, 5455), // Final generic OOVPA: 5455; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(CDevice_SetStateUP, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0 // thiscall
    REGISTER_OOVPAS_D3D(CDevice_SetStateVB, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0 // thiscall

    REGISTER_OOVPAS(D3D_CreateTexture, 3911, 4034),
    REGISTER_OOVPAS_D3D(CDevice_MakeSpace, 3911), // NOTE: has multiple rets.
    REGISTER_OOVPAS_D3D(CMiniport_CreateCtxDmaObject, 3911, 4034),
    REGISTER_OOVPAS_D3D(CMiniport_InitHardware, 3911, 4034, 5455),
    REGISTER_OOVPAS_D3D(CMiniport_IsFlipPending, 3911, 4242, 4627, 4928),
    REGISTER_OOVPAS(D3DBaseTexture_GetLevelCount, 3911),
    REGISTER_OOVPAS(D3DCubeTexture_GetCubeMapSurface2, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DCubeTexture_GetCubeMapSurface, 3911, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DCubeTexture_LockRect, 3911), // Just calls Lock2DSurface (from 4134, 4432's comment)
    REGISTER_OOVPAS(D3DDevice_AddRef, 3911, 4039, 4134, 4242, 4627, 5028, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_ApplyStateBlock, 3911, 4627),
    REGISTER_OOVPAS(D3DDevice_Begin, 3911, 4039),
    REGISTER_OOVPAS_BIND_XREF(D3DDevice_BeginPush_8, D3DDevice_BeginPush, 4039),
    REGISTER_OOVPAS_BIND_XREF(D3DDevice_BeginPush_4, D3DDevice_BeginPush, 4531, 4627, 5028),
    REGISTER_OOVPAS(D3DDevice_BeginPushBuffer, 3911, 4039), // Not implemented yet. (from 5788's comment)
    REGISTER_OOVPAS(D3DDevice_BeginStateBig, 5028),
    REGISTER_OOVPAS(D3DDevice_BeginStateBlock, 3911, 4134),
    REGISTER_OOVPAS(D3DDevice_BeginVisibilityTest, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_BlockOnFence, 3911),
    REGISTER_OOVPAS(D3DDevice_BlockUntilVerticalBlank, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_CaptureStateBlock, 3911, 4134),
    REGISTER_OOVPAS(D3DDevice_Clear, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_CopyRects, 3911, 4034, 4627, 5120),
    REGISTER_OOVPAS(D3DDevice_CreateCubeTexture, 3911, 4627),
    REGISTER_OOVPAS(D3DDevice_CreateImageSurface, 3911, 4034, 4627), //TODO 4721,4928 (from 4627's comment)
    REGISTER_OOVPAS(D3DDevice_CreateIndexBuffer, 3911, 4627), // TODO: This needs to be verified on 4361
    REGISTER_OOVPAS(D3DDevice_CreateIndexBuffer2, 4627, 5344),
    REGISTER_OOVPAS(D3DDevice_CreatePalette, 3911, 4627), // Called D3DDevice_CreatePalette2 (from 4627's comment) NOTE: Use D3DDevice_CreatePalette2 for 4627 and above
    REGISTER_OOVPAS(D3DDevice_CreatePalette2, 4627, 5344, 5455),
    REGISTER_OOVPAS(D3DDevice_CreatePixelShader, 3911, 5344),
    REGISTER_OOVPAS(D3DDevice_CreateStateBlock, 3911),
    REGISTER_OOVPAS(D3DDevice_CreateTexture2, 4627, 4831), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_CreateTexture, 3911, 4627), // Called D3DDevice_CreateTexture2 (from 4627's comment) NOTE: Use D3DDevice_CreateTexture2 for 4627 and above
    REGISTER_OOVPAS(D3DDevice_CreateVertexBuffer, 3911, 4627),
    REGISTER_OOVPAS(D3DDevice_CreateVertexBuffer2, 4627, 5344, 5455),
    REGISTER_OOVPAS(D3DDevice_CreateVertexShader, 3911),
    REGISTER_OOVPAS(D3DDevice_CreateVolumeTexture, 3911, 4627),
    REGISTER_OOVPAS(D3DDevice_DeletePatch, 3911), // (TODO) (from 4034's comment)
    REGISTER_OOVPAS(D3DDevice_DeletePixelShader, 3911, 5344),
    REGISTER_OOVPAS(D3DDevice_DeleteStateBlock, 3911),
    REGISTER_OOVPAS(D3DDevice_DeleteVertexShader, 3911, 5344), // Final generic OOVPA: 5344; Removed: 0
    REGISTER_OOVPAS(D3DDevice_DrawIndexedVertices, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_DrawIndexedVerticesUP, 3911, 5028, 5344), // Final generic OOVPA: 5344; Removed: 0 // TODO: Need verify title with 4034 version.
    REGISTER_OOVPAS(D3DDevice_DrawRectPatch, 3911), // TODO: Unused? (from 4034's comment)
    REGISTER_OOVPAS(D3DDevice_DrawTriPatch, 3911),
    REGISTER_OOVPAS(D3DDevice_DrawVertices, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_DrawVerticesUP, 3911, 4039, 5344), // Final generic OOVPA: 5344; Removed: 0 // TODO: Need verify title with 4034 version.
    REGISTER_OOVPAS(D3DDevice_EnableOverlay, 3911, 4134),
    REGISTER_OOVPAS(D3DDevice_End, 3911, 4039, 5344),
    REGISTER_OOVPAS(D3DDevice_EndPush, 4039), // Was 4627 (from 5233's comment)
    REGISTER_OOVPAS(D3DDevice_EndPushBuffer, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_EndStateBlock, 3911, 4134),
    REGISTER_OOVPAS(D3DDevice_EndVisibilityTest, 3911),
    REGISTER_OOVPAS(D3DDevice_FlushVertexCache, 3911, 4134),
    REGISTER_OOVPAS(D3DDevice_GetBackBuffer, 3911, 4034, 4134, 4627), // Called D3DDevice_GetBackBuffer2 (from 4627's comment) NOTE: Use D3DDevice_GetBackBuffer2 for 4627 and above
    REGISTER_OOVPAS(D3DDevice_GetBackBuffer2, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DDevice_GetBackMaterial, 3911, 4039, 4134, 4627, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetCreationParameters, 3911),
    REGISTER_OOVPAS(D3DDevice_GetDepthStencilSurface, 3911, 4627), // Called D3DDevice_GetDepthStencilSurface2 (from 4627's comment) NOTE: Use D3DDevice_GetDepthStencilSurface2 for 4627 and above
    REGISTER_OOVPAS(D3DDevice_GetDepthStencilSurface2, 4627),
    REGISTER_OOVPAS(D3DDevice_GetDeviceCaps, 3911),
    REGISTER_OOVPAS(D3DDevice_GetDisplayFieldStatus, 3911),
    REGISTER_OOVPAS(D3DDevice_GetDisplayMode, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_GetGammaRamp, 3911),
    REGISTER_OOVPAS(D3DDevice_GetLight, 3911),
    REGISTER_OOVPAS(D3DDevice_GetLightEnable, 3911, 5344),
    REGISTER_OOVPAS(D3DDevice_GetMaterial, 3911, 4039, 4134, 4627, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetModelView, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_GetOverlayUpdateStatus, 3911),
    REGISTER_OOVPAS(D3DDevice_GetPersistedSurface2, 4928), // For only on Unreal Championship (from 4627's comment)
    REGISTER_OOVPAS(D3DDevice_GetPixelShader, 3911, 4039, 4134, 5028, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetProjectionViewportMatrix, 3911, 4134, 4627, 5344, 5558), // For 5455 (from 5558's comment)
    REGISTER_OOVPAS(D3DDevice_GetPushBufferOffset, 3911, 4627), //TODO 4831 (from 4627's comment)
    REGISTER_OOVPAS(D3DDevice_GetRenderTarget2, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DDevice_GetRenderTarget, 3911, 4627), // Final generic OOVPA: 4627; Removed: 0 // NOTE: Use D3DDevice_GetRenderTarget2 for 4627 and above
    REGISTER_OOVPAS(D3DDevice_GetScissors, 3911),
    REGISTER_OOVPAS(D3DDevice_GetShaderConstantMode, 3911, 4134, 4627, 5028, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetStreamSource2, 4627),
    REGISTER_OOVPAS(D3DDevice_GetTexture2, 3911, 4134, 4627, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetTile, 3911, 5455),
    REGISTER_OOVPAS(D3DDevice_GetTransform, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_GetVertexShader, 3911, 4039, 4134, 5028, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderConstant, 3911, 4039, 5028),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderDeclaration, 3911),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderFunction, 3911),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderInput, 3911),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderSize, 3911),
    REGISTER_OOVPAS(D3DDevice_GetVertexShaderType, 3911),
    REGISTER_OOVPAS(D3DDevice_GetViewport, 3911, 5455), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_GetViewportOffsetAndScale, 4432),
    REGISTER_OOVPAS(D3DDevice_GetVisibilityTestResult, 3911, 5233),
    REGISTER_OOVPAS(D3DDevice_InsertCallback, 3911, 4134, 5028),
    REGISTER_OOVPAS(D3DDevice_InsertFence, 3911),
    REGISTER_OOVPAS(D3DDevice_IsBusy, 3911, 5028),
    REGISTER_OOVPAS(D3DDevice_IsFencePending, 3911, 4039, 5028),
    REGISTER_OOVPAS_D3D(CDevice_KickOff, 3911, 4034, 4531, 5028, 5455), // Final generic OOVPA: 5455; Removed: 0 // thiscall
    REGISTER_OOVPAS(D3DDevice_KickPushBuffer, 3911),
    REGISTER_OOVPAS(D3DDevice_LightEnable, 3911, 5344), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_LoadVertexShader, 3911, 4034, 4627, 5028),
    REGISTER_OOVPAS(D3DDevice_LoadVertexShaderProgram, 3911),
    REGISTER_OOVPAS(D3DDevice_MakeSpace, 4034, 4134), // NOTE: LTCG has duplicate functions, need to find out how to resolve this issue with cross referencing.
    REGISTER_OOVPAS(D3DDevice_PersistDisplay, 3911, 4039, 4627, 4831),
    REGISTER_OOVPAS(D3DDevice_Present, 3911),
    REGISTER_OOVPAS(D3DDevice_PrimeVertexCache, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_Release, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_Reset, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_RunPushBuffer, 3911, 4039, 4627, 5120, 5558), // for 5455 (from 5558's comment)
    REGISTER_OOVPAS(D3DDevice_RunVertexStateShader, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SelectVertexShader, 3911, 4034, 5455),
    REGISTER_OOVPAS(D3DDevice_SelectVertexShaderDirect, 4361),
    REGISTER_OOVPAS(D3DDevice_SetBackBufferScale, 4039),
    REGISTER_OOVPAS(D3DDevice_SetBackMaterial, 3911, 4039, 4134, 4627, 5344, 5558, 5788),
    REGISTER_OOVPAS(D3DDevice_SetDepthClipPlanes, 4432),
    REGISTER_OOVPAS(D3DDevice_SetFlickerFilter, 3911, 4034, 4134),
    REGISTER_OOVPAS(D3DDevice_SetGammaRamp, 3911, 4627),
    REGISTER_OOVPAS(D3DDevice_SetIndices, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetLight, 3911, 5344),
    REGISTER_OOVPAS(D3DDevice_SetMaterial, 3911, 4034, 4134, 4627, 5344, 5558, 5788), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_SetModelView, 3911, 4039, 4627),
    REGISTER_OOVPAS(D3DDevice_SetPalette, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetPixelShader, 3911, 4034, 4627),
    REGISTER_OOVPAS(D3DDevice_SetPixelShaderConstant, 3911, 4831),
    REGISTER_OOVPAS(D3DDevice_SetPixelShaderProgram, 3911),
    REGISTER_OOVPAS_M(D3DDevice_SetRenderState_Simple, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS_M(D3DDevice_SetRenderStateNotInline, 3911), // Final generic OOVPA: 3911; Removed: 0 // NOTE: Must be after D3DDevice_SetRenderState_Simple.
    // NOTE: Some or most of render state signatures below must be after D3DDevice_SetRenderStateNotInline.
    REGISTER_OOVPAS(D3DDevice_SetRenderState, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState2, 3911), // Final generic OOVPA: 3911; Removed: 0 // NOTE: There is a verified duplicate function.
    REGISTER_OOVPAS(D3DDevice_SetRenderState_BackFillMode, 3911, 4034),
    REGISTER_OOVPAS_C(D3DDevice_SetRenderState_CullMode, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_Deferred, 3911),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_DoNotCullUncompressed, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_Dxt1NoiseEnable, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_EdgeAntiAlias, 3911, 4034),
    REGISTER_OOVPAS_M(D3DDevice_SetRenderState_FillMode, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_FogColor, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_FrontFace, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_LineWidth, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_LogicOp, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_MultiSampleAntiAlias, 3911, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_MultiSampleMask, 3911, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_MultiSampleMode, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_MultiSampleRenderTargetMode, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_MultiSampleType, 3911, 3925), // Final generic OOVPA: 3925 Removed: 4034
    REGISTER_OOVPAS(D3DDevice_SetRenderState_NormalizeNormals, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_OcclusionCullEnable, 3911, 1024), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_PSTextureModes, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_RopZCmpAlwaysRead, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_RopZRead, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_SampleAlpha, 4627), // Final generic OOVPA: 4627; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_ShadowFunc, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_StencilCullEnable, 3911, 1024), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_StencilEnable, 3911, 4034, 5849),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_StencilFail, 3911, 4034, 5849),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_TextureFactor, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_TwoSidedLighting, 3911, 4034, 5344), // Final generic OOVPA: 5344; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_VertexBlend, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetRenderState_YuvEnable, 3911, 1024), // Final generic OOVPA: 3911 (LTCG) / 4034 (non-LTCG); Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_ZBias, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderState_ZEnable, 3911, 4034, 4134, 4432),
    REGISTER_OOVPAS(D3DDevice_SetRenderTarget, 3911, 3947, 4034, 4039, 4627, 5344, 5455), // Final generic OOVPA: 5344/5455; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetRenderTargetFast, 5233),
    REGISTER_OOVPAS(D3DDevice_SetScissors, 3911, 5344, 5558), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_SetScreenSpaceOffset, 4034, 5455), // Final generic OOVPA: 5455; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetShaderConstantMode, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetSoftDisplayFilter, 3911, 4034, 4134),
    REGISTER_OOVPAS(D3DDevice_SetStipple, 4627),
    REGISTER_OOVPAS(D3DDevice_SetStreamSource, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetSwapCallback, 4039), // Final generic OOVPA: 4039; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetTexture, 3911, 4034, 4361, 4831),
    REGISTER_OOVPAS(D3DDevice_SetTextureStageStateNotInline, 3911, 4034), // Final generic OOVPA: 4034; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetTextureState_BorderColor, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetTextureState_BumpEnv, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_SetTextureState_ColorKeyColor, 3911, 4034),
    REGISTER_OOVPAS_C(D3DDevice_SetTextureState_TexCoordIndex, 3911, 4034, 4242, 4627),
    REGISTER_OOVPAS(D3DDevice_SetTile, 3911, 4034, 4627), // Then it has changed calls ?SetTileNoWait@D3D@@YGXKPBU_D3DTILE@@@Z in XDK 4627 and higher.
    REGISTER_OOVPAS(D3DDevice_SetTransform, 3911, 4034),
    REGISTER_OOVPAS(D3DDevice_MultiplyTransform, 3911, 4034), // TODO: Verify 4034 is correct
    REGISTER_OOVPAS(D3DDevice_SetVertexData2f, 3911, 4039), // Was 4627 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_SetVertexData2s, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexData4f, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexData4s, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexData4ub, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexDataColor, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexShader, 3911, 4034, 4134, 5028, 5455),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstant, 3911, 4034, 4627),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstant1, 4627),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstant1Fast, 4627),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstant4, 4627),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstantNotInline, 4627, 5028, 5558),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderConstantNotInlineFast, 4627),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderInput, 3911, 4039),
    REGISTER_OOVPAS(D3DDevice_SetVertexShaderInputDirect, 4361),
    REGISTER_OOVPAS(D3DDevice_SetVerticalBlankCallback, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_SetViewport, 3911, 4034, 5344, 5455), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS(D3DDevice_Suspend, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3DDevice_Swap, 4034, 4531, 4627),
    REGISTER_OOVPAS(D3DDevice_SwitchTexture, 3911),
    REGISTER_OOVPAS(D3DDevice_UpdateOverlay, 3911, 4531, 5233),
    REGISTER_OOVPAS(D3DPalette_Lock, 3911, 4531, 4627), // Called D3DPalette_Lock2 (from 4627's comment) NOTE: Use D3DPalette_Lock2 for 4627 and above
    REGISTER_OOVPAS(D3DPalette_Lock2, 4627),
    REGISTER_OOVPAS(D3DResource_AddRef, 3911),
    REGISTER_OOVPAS(D3DResource_BlockUntilNotBusy, 3911),
    REGISTER_OOVPAS(D3DResource_GetType, 3911, 4034), // Probably not even necessary... (from 3925's comment) // I forget why I had this in here... (from 5028's comment)
    REGISTER_OOVPAS(D3DResource_IsBusy, 3911, 4039),
    REGISTER_OOVPAS(D3DResource_Register, 3911),
    REGISTER_OOVPAS(D3DResource_Release, 3911),
    REGISTER_OOVPAS(D3DSurface_GetDesc, 3911),
    REGISTER_OOVPAS(D3DSurface_LockRect, 3911),
    REGISTER_OOVPAS(D3DTexture_GetSurfaceLevel, 3911, 4627),
    REGISTER_OOVPAS(D3DTexture_GetSurfaceLevel2, 4627),
    REGISTER_OOVPAS(D3DTexture_LockRect, 3911),
    REGISTER_OOVPAS(D3DVertexBuffer_GetDesc, 3911),
    REGISTER_OOVPAS(D3DVertexBuffer_Lock, 3911, 4034, 4627),
    REGISTER_OOVPAS(D3DVertexBuffer_Lock2, 4627),
    REGISTER_OOVPAS(D3DVolumeTexture_LockBox, 3911), // Just calls Lock3DSurface (from 4134, 4432's comment)
    REGISTER_OOVPAS(D3D_AllocContiguousMemory, 3911, 5455), // Final generic OOVPA: 5455; Removed: 0 // Just calls MmAllocateContiguousMemory.
    REGISTER_OOVPAS(D3D_BlockOnResource, 3911, 4034),
    REGISTER_OOVPAS(D3D_BlockOnTime, 3911, 4034, 4627, 5028, 5558),
    REGISTER_OOVPAS_D3D(CMiniport_GetDisplayCapabilities, 3911),
    REGISTER_OOVPAS(D3D_CheckDeviceFormat, 3911),
    REGISTER_OOVPAS(D3D_ClearStateBlockFlags, 3911),
    REGISTER_OOVPAS_M(D3D_CommonSetDebugRegisters, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(D3D_CommonSetRenderTarget, 4627, 5028), // Final generic OOVPA: 4627; Removed: 5344
    REGISTER_OOVPAS(D3D_CommonSetMultiSampleModeAndScale, 5344), // Final generic OOVPA: 5344; Removed: 0 // fastcall (2 params)
    REGISTER_OOVPAS(D3D_CreateStandAloneSurface, 4034),
    REGISTER_OOVPAS(D3D_DestroyResource, 3911),
    REGISTER_OOVPAS(D3D_EnumAdapterModes, 3911),
    REGISTER_OOVPAS(D3D_GetAdapterDisplayMode, 3911, 4627),
    REGISTER_OOVPAS(D3D_GetAdapterIdentifier, 3911),
    REGISTER_OOVPAS(D3D_GetAdapterModeCount, 3911),
    REGISTER_OOVPAS(D3D_GetDeviceCaps, 3911),
    REGISTER_OOVPAS(D3D_KickOffAndWaitForIdle, 3911, 4034, 4627, 5028),
    REGISTER_OOVPAS(D3D_LazySetPointParams, 3911, 4034),
    REGISTER_OOVPAS(D3D_RecordStateBlock, 3911),
    REGISTER_OOVPAS(D3D_SetFence, 3911, 4034, 4134, 5028, 5558),
    REGISTER_OOVPAS(D3D_SetPushBufferSize, 3911),
    REGISTER_OOVPAS(D3D_SetTileNoWait, 4627, 5455), // Final generic OOVPA: 5455; Removed: 0
    REGISTER_OOVPAS(Direct3D_CheckDeviceMultiSampleType, 3911),
    REGISTER_OOVPAS(Direct3D_CreateDevice, 3911, 5028),
    REGISTER_OOVPAS_D3D8(Get2DSurfaceDesc, 3911, 4034), // Was 5233 (from 5344's comment)
    REGISTER_OOVPAS_D3D8(Lock2DSurface, 3911),
    REGISTER_OOVPAS_D3D8(Lock3DSurface, 3911),
    REGISTER_OOVPAS_BIND_XREF(D3D_MakeRequestedSpace_4, D3D_MakeRequestedSpace, 4034), // Final generic OOVPA: 4034??; Removed: 4134 // NOTE: has multiple rets.
    REGISTER_OOVPAS_BIND_XREF(D3D_MakeRequestedSpace_8, D3D_MakeRequestedSpace, 4134, 5558), // Final generic OOVPA: 5558; Removed: 0 // NOTE: has multiple rets.
    REGISTER_OOVPAS(XMETAL_StartPush, 3911), // Final generic OOVPA: 3911; Removed: 4034??
    REGISTER_OOVPAS(IDirect3DVertexBuffer8_Lock, 4627),
};


// ******************************************************************
// * D3D8_OOVPA_COUNT
// ******************************************************************
#define D3D8_OOVPA_COUNT XBSDB_ARRAY_SIZE(D3D8_OOVPA)

#endif
