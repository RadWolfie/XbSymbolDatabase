// ******************************************************************
// *
// *   OOVPADatabase->XGraphic_OOVPA.inl
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

// TODO: Library table below need a clean list. Should only list a full library
//   or at least have all of symbols detected. Plus using two titles with same
//   version to make a full library inspected are better than nothing.
// Titles which did compiled with full library
//   [LibV] Title Name                       |  Verify   |  Comments
//-------------------------------------------------------------------
// * [3911] Cel Damage                       |   100%    | Contain full library.
// * [4034] Dark Summit                      |   100%    | have 3/10 library.
// * [4039] New Legends                      |   100%    | have 6/10 library.
// * [4134] Double-S.T.E.A.L                 |   100%    | have 9/10 library.
// * [4242] Legends of Wrestling             |   100%    | have 4/10 library.
// * [4361] Umezawa Yukari no Igo Seminar    |   100%    | have 6/11 library.
// * [4432] Sega Soccer Slam                 |   100%    | have 9/11 library.
// * [4531] NHL HITZ 2003                    |   100%    | have 9/11 library.
// * [4627] Rayman Arena                     |   100%    | have 6/11 library.
// * [4721] Terminator - Dawn of Fate        |   100%    | have 10/11 library.
// * [4831] Whacked                          |   100%    | have 9/11 library.
// * [4928] Drihoo                           |   100%    | have 8/11 library.
// * [5028] Shikigami no Shiro Evolution     |   100%    | have 5/11 library.
// * [5120] N.U.D.E.@                        |   100%    | have 8/11 library.
// * [5233] Rayman 3                         |   100%    | have 8/11 library.
// * [5344] Starsky & Hutch                  |   100%    | have 8/11 library.
// * [5455] Dinosaur Hunting                 |   100%    | have 10/11 library.
// * [5558] XIII                             |   100%    | have 9/11 library.
// * [5659] LMA Manager 2004                 |   100%    | have 9/11 library.
// * [5788] All-Star Baseball 2005           |   100%    | have 9/11 library.
// * [5849] Nickelodeon Tak 2                |   100%    | have 9/11 library.

// TODO: Known Xgraphics OOVPA issue list
// * 3911 XGCompressRect is XREF in v1 database, any reason for this?
// * Verification needed: Function Name ( Revision )
//   Need to refresh this list.
//   * XFONT_OpenBitmapFontFromMemory (4432, 4531, 4831, 5120)
//   * XGCompressRect (4034, 4242, 4721, 5028, 5120)
//   * XGIsSwizzledFormat (4034)
//   * XGSetIndexBufferHeader (4034)
//   * XGSetTextureHeader (4034)
//   * XGSetVertexBufferHeader (4034)
//   * XGSwizzleBox (4242)
//   * XGUnswizzleBox (4034, 4134, 4242)
//   * XGWriteSurfaceOrTextureToXPR (4034, 4242, 5028)
// * Need to move OOVPAs does not belong in 3911 to their specific version.
// NOTE: Known Xgraphics OOVPA not included in initial revision.
//   * XFONT_OpenBitmapFontFromMemory (4361)
// * List of known Symbols (3911)
//   * XGBuffer_AddRef
//   * XGBuffer_GetBufferPointer
//   * XGBuffer_GetBufferSize
//   * XGBuffer_Release
//   * XGBytesPerPixelFromFormat
//   * XGCompileDrawIndexedVertices
//   * XGMatrixAffineTransformation
//   * XGMatrixfDeterminant
//   * XGMatrixInverse
//   * XGMatrixLookAtLH
//   * XGMatrixLookAtRH
//   * XGMatrixMultiply
//   * XGMatrixOrthoLH
//   * XGMatrixOrthoOffCenterLH
//   * XGMatrixOrthoOffCenterRH
//   * XGMatrixOrthoRH
//   * XGMatrixPerspectiveFovLH
//   * XGMatrixPerspectiveFovRH
//   * XGMatrixPerspectiveLH
//   * XGMatrixPerspectiveOffCenterLH
//   * XGMatrixPerspectiveOffCenterRH
//   * XGMatrixPerspectiveRH
//   * XGMatrixReflect
//   * XGMatrixRotationAxis
//   * XGMatrixRotationQuaternion
//   * XGMatrixRotationX
//   * XGMatrixRotationY
//   * XGMatrixRotationYawPitchRoll
//   * XGMatrixRotationZ
//   * XGMatrixScaling
//   * XGMatrixShadow
//   * XGMatrixTransformation
//   * XGMatrixTranslation
//   * XGMatrixTranspose
//   * XGOptimizeVertexShader
//   * XGQuaternionBaryCentric
//   * XGQuaternionExp
//   * XGQuaternionInverse
//   * XGQuaternionLn
//   * XGQuaternionMultiply
//   * XGQuaternionNormalize
//   * XGQuaternionRotationAxis
//   * XGQuaternionRotationMatrix
//   * XGQuaternionRotationYawPitchRoll
//   * XGQuaternionSlerp
//   * XGQuaternionSquad
//   * XGQuaternionToAxisAngle
//   * XGraphicsBuildVersion (has variable reference for build version)
//   * XGSpliceVertexShaders
//   * XGSUCode_CompareVertexShaders
//   * XGSUCode_GetVertexShaderLength
//   * XGSUCode_GetVertexShaderType
//   * XGVec2BaryCentric
//   * XGVec2CatmullRom
//   * XGVec2Hermite
//   * XGVec2Normalize
//   * XGVec2Transform
//   * XGVec2TransformCoord
//   * XGVec2TransformNormal
//   * XGVec3BaryCentric
//   * XGVec3Hermite
//   * XGVec3Normalize
//   * XGVec3Project
//   * XGVec3Transform
//   * XGVec3TransformCoord
//   * XGVec3TransformNormal
//   * XGVec3Unproject
//   * XGVec4BaryCentric
//   * XGVec4CatmullRom
//   * XGVec4Cross
//   * XGVec4Hermite
//   * XGVec4Normalize
//   * XGVec4Transform

#ifndef XGRAPHC_OOVPA_INL
#define XGRAPHC_OOVPA_INL

#include "../OOVPA.h"

#include "XGraphic/3911.inl"
#include "XGraphic/4134.inl"
#include "XGraphic/4361.inl"

// ******************************************************************
// * XGRAPHC_OOVPA
// ******************************************************************
OOVPATable XGRAPHC_OOVPA[] = {

    REGISTER_OOVPAS(DisassembleVertexShader, 3911, 4039), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(SupportsSSE, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XFONT_OpenBitmapFontFromMemory, 4361), // Final generic OOVPA: ____; Removed: 0 (introduced in ____)
    REGISTER_OOVPAS(XGAssembleShader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGBufferCreate, 3911, 5455), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(XGColorAdjustContrast, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGColorAdjustSaturation, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGCompressRect, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGIsSwizzledFormat, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGPlaneFromPointNormal, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGPlaneFromPoints, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGPlaneIntersectLine, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGPlaneNormalize, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGPlaneTransform, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSetCubeTextureHeader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSetFixupHeader, 3911, 4242), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(XGSetIndexBufferHeader, 3911, 4134), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(XGSetPaletteHeader, 3911, 4242), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(XGSetPushBufferHeader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSetSurfaceHeader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSetTextureHeader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSetVertexBufferHeader, 3911, 4134), // Final generic OOVPA: ____; Removed: 0
    REGISTER_OOVPAS(XGSetVolumeTextureHeader, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSwizzleBox, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGSwizzleRect, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGUnswizzleBox, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGUnswizzleRect, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGWriteSurfaceOrTextureToXPR, 3911), // Final generic OOVPA: 3911; Removed: 0
    REGISTER_OOVPAS(XGWriteSurfaceToFile, 3911), // Final generic OOVPA: 3911; Removed: 0
};

// ******************************************************************
// * XGRAPHC_OOVPA_COUNT
// ******************************************************************
#define XGRAPHC_OOVPA_COUNT XBSDB_ARRAY_SIZE(XGRAPHC_OOVPA)

#endif
