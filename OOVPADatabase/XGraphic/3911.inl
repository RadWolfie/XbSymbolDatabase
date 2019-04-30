// ******************************************************************
// *
// *   OOVPADatabase->XGraphic->3911.inl
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
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *  (c) 2019 RadWolfie
// *
// *  All rights reserved
// *
// ******************************************************************

// ******************************************************************
// * XGIsSwizzledFormat
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGIsSwizzledFormat, 3911, 10)

        // XGIsSwizzledFormat+0x00 : mov eax[esp+0x04]
        OV_MATCH(0x00, 0x8B, 0x44),

        // XGIsSwizzledFormat+0x04 : cmp eax,0x2D
        OV_MATCH(0x04, 0x83, 0xF8, 0x2D),

        // XGIsSwizzledFormat+0x21 : cmp eax,0x1A
        OV_MATCH(0x21, 0x83, 0xF8, 0x1A),

        // XGIsSwizzledFormat+0x28 : ret 0x0004
        OV_MATCH(0x28, 0xC2, 0x04),
OOVPA_END;

// ******************************************************************
// * XGSwizzleRect
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSwizzleRect, 3911, 10)

        // XGSwizzleRect+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGSwizzleRect+0x11 : cmp edi,0x02
        OV_MATCH(0x11, 0x83, 0xFF, 0x02), // 0xFF vs XGUnswizzleRect 0xFB

        // XGSwizzleRect+0x14 : push 0x10
        OV_MATCH(0x14, 0x6A, 0x10),

        // XGSwizzleRect+0x1A : push 0x07
        OV_MATCH(0x1A, 0x6A, 0x07), // 0x07 vs XGUnswizzleRect 0x0F

        // XGSwizzleRect+0x1D : push 0x03
        OV_MATCH(0x1D, 0x6A, 0x03),
OOVPA_END;

// ******************************************************************
// * XGSwizzleBox
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
// NOTE: Offsets 0x57, 0x59, and 0x61 are changed from 3911 to 5849.
OOVPA_NO_XREF(XGSwizzleBox, 3911, 9)

        // XGSwizzleBox+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGSwizzleBox+0x11 : xor ecx,ecx
        OV_MATCH(0x11, 0x33, 0xC9), // 0xC9 vs XGUnswizzleBox 0xD2

        // XGSwizzleBox+0x16 : mov edi,[ebp+0x0C]
        OV_MATCH(0x16, 0x8B, 0x7D, 0x0C), // 0x0C vs XGUnswizzleBox 0x20

        // XGSwizzleBox+0x3A : imul esi,edx
        OV_MATCH(0x3A, 0x0F, 0xAF, 0xF2), // 0xF2 vs XGUnswizzleBox 0xF7
OOVPA_END;

// ******************************************************************
// * XGUnswizzleRect
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGUnswizzleRect, 3911, 10)

        // XGUnswizzleRect+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGUnswizzleRect+0x0F : cmp ebx, 0x02
        OV_MATCH(0x0F, 0x83, 0xFB, 0x02), // 0xFB vs XGSwizzleRect 0xFF

        // XGUnswizzleRect+0x14 : push 0x10
        OV_MATCH(0x14, 0x6A, 0x10),

        // XGUnswizzleRect+0x1A : push 0x0F
        OV_MATCH(0x1A, 0x6A, 0x0F), // 0x0F vs XGSwizzleRect 0x07

        // XGUnswizzleRect+0x1D : push 0x03
        OV_MATCH(0x1D, 0x6A, 0x03),
OOVPA_END;

// ******************************************************************
// * XGWriteSurfaceOrTextureToXPR
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGWriteSurfaceOrTextureToXPR, 3911, 12)

        // XGWriteSurfaceOrTextureToXPR+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGWriteSurfaceOrTextureToXPR+0x0F : and eax,0x00070000
        OV_MATCH(0x0F, 0x25),
        OV_MATCH(0x012, 0x07, 0x00),

        // XGWriteSurfaceOrTextureToXPR+0x14 : cmp eax,0x00040000
        OV_MATCH(0x14, 0x3D),
        OV_MATCH(0x17, 0x04, 0x00),

        // XGWriteSurfaceOrTextureToXPR+0x1E : cmp eax,0x00050000
        OV_MATCH(0x1E, 0x3D),
        OV_MATCH(0x21, 0x05, 0x00),

        // XGWriteSurfaceOrTextureToXPR+0x23 : je +0x0A
        OV_MATCH(0x23, 0x74, 0x0A),

        // Offset 0x2F and later are different.
OOVPA_END;

// ******************************************************************
// * XGSetTextureHeader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSetTextureHeader, 3911, 10)

        // XGSetTextureHeader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        OV_MATCH(0x05, 0x20),

        OV_MATCH(0x08, 0x24),

        // XGSetTextureHeader+0x09 : push 0x00, push 0x00
        OV_MATCH(0x09, 0x6A, 0x00, 0x6A, 0x00),

        // XGSetTextureHeader+0x27 : ret 0x0024
        OV_MATCH(0x27, 0xC2, 0x24, 0x00),
OOVPA_END;

// ******************************************************************
// * XGUnswizzleBox
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGUnswizzleBox, 3911, 9)

        // XGSwizzleBox+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGSwizzleBox+0x11 : xor edx,edx
        OV_MATCH(0x11, 0x33, 0xD2), // 0xD2 vs XGSwizzleBox 0xC9

        // XGSwizzleBox+0x16 : mov edi,[ebp+0x20]
        OV_MATCH(0x16, 0x8B, 0x7D, 0x20), // 0x20 vs XGSwizzleBox 0x0C

        // XGSwizzleBox+0x3A : imul esi,edi
        OV_MATCH(0x3A, 0x0F, 0xAF, 0xF7), // 0xF7 vs XGSwizzleBox 0xF2
OOVPA_END;

// ******************************************************************
// * XGCompressRect
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGCompressRect, 3911, 12)

        // XGCompressRect+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        OV_MATCH(0x01, 0x8D),

        // XGCompressRect+0x14 : cmp [ebp+0x6C],0
        OV_MATCH(0x14, 0x83, 0x7D, 0x6C, 0x00),

        // XGCompressRect+0x18 : push esi; push edi
        OV_MATCH(0x18, 0x56, 0x57),

        // XGCompressRect+0x1A : [ebp-0x24],0x________
        OV_MATCH(0x1A, 0xC7, 0x45),

        OV_MATCH(0xC0, 0x7E, 0x01),
OOVPA_END;

// ******************************************************************
// * XGSetIndexBufferHeader
// ******************************************************************
OOVPA_NO_XREF(XGSetIndexBufferHeader, 3911, 13)

        OV_MATCH(0x01, 0x44),
        OV_MATCH(0x04, 0x8B),

        OV_MATCH(0x06, 0x24, 0x18),

        // XGSetIndexBufferHeader+0x08 : mov [eax],0x00010001
        OV_MATCH(0x08, 0xC7, 0x00, 0x01, 0x00, 0x01, 0x00),

        OV_MATCH(0x10, 0x04),

        // XGSetIndexBufferHeader+0x11 : ret 0x0018
        OV_MATCH(0x11, 0xC2, 0x18),
OOVPA_END;

// ******************************************************************
// * XGSetVertexBufferHeader
// ******************************************************************
OOVPA_NO_XREF(XGSetVertexBufferHeader, 3911, 13)

        OV_MATCH(0x01, 0x44),
        OV_MATCH(0x04, 0x8B),

        OV_MATCH(0x07, 0x18),

        // XGSetVertexBufferHeader+0x08 : mov eax,0x00000001
        OV_MATCH(0x08, 0xC7, 0x00, 0x01, 0x00, 0x00, 0x00),

        OV_MATCH(0x0E, 0x89),

        OV_MATCH(0x10, 0x04),

        // XGSetVertexBufferHeader+0x11 : ret 0x0018
        OV_MATCH(0x11, 0xC2, 0x18),
OOVPA_END;

// ******************************************************************
// * DisassembleVertexShader
// ******************************************************************
OOVPA_NO_XREF(DisassembleVertexShader, 3911, 11)

        // DisassembleVertexShader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // DisassembleVertexShader+0x03 : sub esp,0x________
        OV_MATCH(0x03, 0x81, 0xEC),

        // DisassembleVertexShader+0x3C : cmp eax,0x00007778
        OV_MATCH(0x3C, 0x3D, 0x78, 0x77, 0x00),

        OV_MATCH(0x46, 0x02, 0x00),

        OV_MATCH(0x4F, 0x03, 0x00),
OOVPA_END;

// ******************************************************************
// * DisassembleVertexShader
// ******************************************************************
// Generic OOVPA as of ____? and newer.
OOVPA_NO_XREF(DisassembleVertexShader, 4039, 11)

        // DisassembleVertexShader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // DisassembleVertexShader+0x03 : sub esp,0x________
        OV_MATCH(0x03, 0x81, 0xEC),

        // DisassembleVertexShader+0x3B : cmp eax,0x00007778
        OV_MATCH(0x3B, 0x3D, 0x78, 0x77, 0x00),

        OV_MATCH(0x45, 0x02, 0x00),

        OV_MATCH(0x4E, 0x03, 0x00),
OOVPA_END;

// ******************************************************************
// * SupportsSSE
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(SupportsSSE, 3911, 12)

        // SupportsSSE+0x00 : push 0x0C
        OV_MATCH(0x00, 0x6A, 0x0C),

        // SupportsSSE+0x12 : cpuid; or [ebp-0x04],0xFFFFFFFF
        OV_MATCH(0x10, 0x0F, 0xA2, 0x83, 0x4D, 0xFC, 0xFF),

        // SupportsSSE+0x3B : cpuid
        OV_MATCH(0x1B, 0x0F, 0xA2),

        // SupportsSSE+0x32 : ret
        OV_MATCH(0x32, 0xC3),

        // SupportsSSE+0x41 : ret
        OV_MATCH(0x41, 0xC3),
OOVPA_END;

// ******************************************************************
// * XGAssembleShader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGAssembleShader, 3911, 13)

        // XGAssembleShader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGAssembleShader+0x03 : sub esp, 0x10
        OV_MATCH(0x03, 0x83, 0xEC, 0x10),

        OV_MATCH(0x0E, 0x2C),
        OV_MATCH(0x11, 0x28),
        OV_MATCH(0x14, 0x24),
        OV_MATCH(0x23, 0x10),
        OV_MATCH(0x26, 0x0C),
        OV_MATCH(0x29, 0x08),

        OV_MATCH(0x2B, 0xE8),

        // XGAssembleShader+0x31 : ret 0x002C
        OV_MATCH(0x31, 0xC2, 0x2C),
OOVPA_END;

// ******************************************************************
// * XGBufferCreate
// ******************************************************************
OOVPA_NO_XREF(XGBufferCreate, 3911, 11)

        // XGBufferCreate+0x00 : push esi
        OV_MATCH(0x00, 0x56),

        // XGBufferCreate+0x15 : mov [esi],1
        OV_MATCH(0x15, 0xC7, 0x06, 0x01, 0x00),

        OV_MATCH(0x24, 0x7E, 0x08),

        OV_MATCH(0x27, 0x46, 0x04),

        // XGBufferCreate+0x43 : ret 0x0008
        OV_MATCH(0x43, 0xC2, 0x08),
OOVPA_END;

// ******************************************************************
// * XGBufferCreate
// ******************************************************************
// Generic OOVPA as of ____? and newer.
OOVPA_NO_XREF(XGBufferCreate, 5455, 11)

        // XGBufferCreate+0x00 : push ebx
        OV_MATCH(0x00, 0x53),

        // XGBufferCreate+0x2B : mov [esi],1
        OV_MATCH(0x2B, 0xC7, 0x06, 0x01, 0x00),

        OV_MATCH(0x39, 0x46, 0x04),

        OV_MATCH(0x3C, 0x7E, 0x08),

        // XGBufferCreate+0x59 : ret 0x0008
        OV_MATCH(0x59, 0xC2, 0x08),
OOVPA_END;

// ******************************************************************
// * XGColorAdjustContrast
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGColorAdjustContrast, 3911, 11)

        // XGColorAdjustContrast+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGColorAdjustContrast+0x06 : fld [0x________]
        OV_MATCH(0x06, 0xD9, 0x05),

        // XGColorAdjustContrast+0x0C : fld [ecx]
        OV_MATCH(0x0C, 0xD9, 0x01),

        OV_MATCH(0x36, 0x0C),

        OV_MATCH(0x39, 0x0C),

        // XGColorAdjustContrast+0x3A : fstp st(0)
        OV_MATCH(0x3A, 0xDD, 0xD8),

        // XGColorAdjustContrast+0x3D : ret 0x000C
        OV_MATCH(0x3D, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGColorAdjustSaturation
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGColorAdjustSaturation, 3911, 9)

        // XGColorAdjustSaturation+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGColorAdjustSaturation+0x0C : fld [ecx]
        OV_MATCH(0x06, 0xD9, 0x01),

        OV_MATCH(0x4E, 0x0C),

        OV_MATCH(0x51, 0x0C),

        // XGColorAdjustSaturation+0x52 : fstp st(0)
        OV_MATCH(0x52, 0xDD, 0xD8),

        // XGColorAdjustSaturation+0x55 : ret 0x000C
        OV_MATCH(0x55, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGPlaneFromPointNormal
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGPlaneFromPointNormal, 3911, 10)

        // XGPlaneFromPointNormal+0x00 : mov eax,[esp+0x0C]
        OV_MATCH(0x00, 0x8B, 0x44),

        // XGPlaneFromPointNormal+0x0B : fld [esi]
        OV_MATCH(0x0B, 0xD9, 0x1E),

        OV_MATCH(0x1A, 0x08),

        OV_MATCH(0x1D, 0x08),

        // XGPlaneFromPointNormal+0x23 : fchs
        OV_MATCH(0x23, 0xD9, 0xE0),

        // XGPlaneFromPointNormal+0x2B : ret 0x000C
        OV_MATCH(0x2B, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGPlaneFromPoints
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGPlaneFromPoints, 3911, 10)

        // XGPlaneFromPoints+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGPlaneFromPoints+0x0D : fld [esi]
        OV_MATCH(0x0D, 0xD9, 0x06),

        // XGPlaneFromPoints+0x10 : fsub [eax]
        OV_MATCH(0x10, 0xD8, 0x20),

        // XGPlaneFromPoints+0x27 : fstp [ebp-0x14]
        OV_MATCH(0x27, 0x8B, 0x45, 0x14),

        // XGPlaneFromPoints+0x6C : ret 0x0010
        OV_MATCH(0x6C, 0xC2, 0x10),
OOVPA_END;

// ******************************************************************
// * XGPlaneIntersectLine
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGPlaneIntersectLine, 3911, 9)

        // XGPlaneIntersectLine+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGPlaneIntersectLine+0x0F : fstp [ebp-4]
        OV_MATCH(0x0F, 0xD9, 0x5D, 0xFC),

        // XGPlaneIntersectLine+0x1D : fsubr [ebp-4]
        OV_MATCH(0x1D, 0xD8, 0x6D, 0xFC),

        // XGPlaneIntersectLine+0x1D : fcomp [________]
        OV_MATCH(0x23, 0xD8, 0x1D),

        // Offset 0x29 and later are different.
OOVPA_END;

// ******************************************************************
// * XGPlaneNormalize
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGPlaneNormalize, 3911, 9)

        // XGPlaneNormalize+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGPlaneNormalize+0x0F : [edi],[esi] x4
        OV_MATCH(0x49, 0xA5, 0xA5, 0xA5, 0xA5),

        // XGPlaneNormalize+0x66 : fsqrt
        OV_MATCH(0x66, 0xD9, 0xFA),

        // XGPlaneNormalize+0x9E : ret 0x0008
        OV_MATCH(0x9E, 0xC2, 0x08),

OOVPA_END;

// ******************************************************************
// * XGPlaneTransform
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGPlaneTransform, 3911, 11)

        // XGPlaneTransform+0x00 : push ebp, mov ebp,esp
        OV_MATCH(0x00, 0x55, 0x8B, 0xEC),

        // XGPlaneTransform+0x0C : sub esp,0x1C
        OV_MATCH(0x03, 0x83, 0xEC, 0x1C),

        // XGPlaneTransform+0x1C : lea eax,[ebp-0x0C]
        OV_MATCH(0x1C, 0x8D, 0x45, 0xF4),

        // XGPlaneTransform+0x20 : fchs
        OV_MATCH(0x20, 0xD9, 0xE0),

        // Offset 0x22 and later are different.
OOVPA_END;

// ******************************************************************
// * XGSetCubeTextureHeader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSetCubeTextureHeader, 3911, 10)

        // XGSetCubeTextureHeader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        OV_MATCH(0x05, 0x1C),

        OV_MATCH(0x08, 0x20),

        // XGSetCubeTextureHeader+0x09 : push 0x00, push 0x01
        OV_MATCH(0x09, 0x6A, 0x00, 0x6A, 0x01),

        // XGSetCubeTextureHeader+0x27 : ret 0x0020
        OV_MATCH(0x27, 0xC2, 0x20, 0x00),
OOVPA_END;

// ******************************************************************
// * XGSetFixupHeader
// ******************************************************************
OOVPA_NO_XREF(XGSetFixupHeader, 3911, 12)

        // XGSetFixupHeader+0x00 : mov eax, [esp+0x08]
        OV_MATCH(0x00, 0x8B, 0x44),

        OV_MATCH(0x07, 0x0C),

        OV_MATCH(0x0E, 0x04),

        // XGSetFixupHeader+0x0F : mov [eax], 0x00060001
        OV_MATCH(0x0F, 0xC7, 0x00, 0x01, 0x00, 0x06, 0x00),

        // XGSetFixupHeader+0x18 : ret 0x000C
        OV_MATCH(0x18, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGSetFixupHeader
// ******************************************************************
// Generic OOVPA as of ____? and newer.
// Lowest found is NFL Blitz 2002 (4242)
OOVPA_NO_XREF(XGSetFixupHeader, 4242, 12)

        // XGSetFixupHeader+0x00 : mov eax, [esp+0x08]
        OV_MATCH(0x00, 0x8B, 0x44),

        OV_MATCH(0x07, 0x0C),

        OV_MATCH(0x0E, 0x04),

        // XGSetFixupHeader+0x0F : mov [eax], 0x00060001
        OV_MATCH(0x13, 0xC7, 0x00, 0x01, 0x00, 0x06, 0x00),

        // XGSetFixupHeader+0x1C : ret 0x000C
        OV_MATCH(0x1C, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGSetPaletteHeader
// ******************************************************************
OOVPA_NO_XREF(XGSetPaletteHeader, 3911, 13)

        // XGSetPaletteHeader+0x00 : mov ecx, [esp+0x08], 0
        OV_MATCH(0x00, 0x8B, 0x4C),

        // XGSetPaletteHeader+0x08 : shl ecx, 0x1E
        OV_MATCH(0x08, 0xC1, 0xE1, 0x1E),

        // XGSetPaletteHeader+0x0B : or ecx, 0x00030001
        OV_MATCH(0x0B, 0x81, 0xC9, 0x01, 0x00, 0x03, 0x00),

        // XGSetPaletteHeader+0x1A : ret 0x000C
        OV_MATCH(0x1A, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGSetPaletteHeader
// ******************************************************************
// Generic OOVPA as of ____? and newer.
// Lowest found is NFL Blitz 2002 (4242)
OOVPA_NO_XREF(XGSetPaletteHeader, 4242, 13)

        // XGSetPaletteHeader+0x00 : mov ecx, [esp+0x08], 0
        OV_MATCH(0x00, 0x8B, 0x4C),

        // XGSetPaletteHeader+0x0C : shl ecx, 0x1E
        OV_MATCH(0x0C, 0xC1, 0xE1, 0x1E),

        // XGSetPaletteHeader+0x0F : or ecx, 0x00030001
        OV_MATCH(0x0F, 0x81, 0xC9, 0x01, 0x00, 0x03, 0x00),

        // XGSetPaletteHeader+0x1E : ret 0x000C
        OV_MATCH(0x1E, 0xC2, 0x0C),
OOVPA_END;

// ******************************************************************
// * XGSetPushBufferHeader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSetPushBufferHeader, 3911, 12)

        // XGSetPushBufferHeader+0x00 : cmp eax, [esp+0x08], 0
        OV_MATCH(0x00, 0x83, 0x7C),

        OV_MATCH(0x08, 0x0C),

        // XGSetPushBufferHeader+0x09 : mov [eax], 0x80020001
        OV_MATCH(0x09, 0xC7),
        OV_MATCH(0x0B, 0x01),
        OV_MATCH(0x0D, 0x02),

        // XGSetPushBufferHeader+0x11 : mov [eax], 0x80020001
        OV_MATCH(0x11, 0xC7, 0x00, 0x01, 0x00, 0x02, 0x80),

        // Anything after offset 0x1A are different.
OOVPA_END;

// ******************************************************************
// * XGSetSurfaceHeader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSetSurfaceHeader, 3911, 9)

        // XGSetSurfaceHeader+0x00 : push ebp, mov ebp,esp
        OV_MATCH(0x00, 0x55, 0x8B, 0xEC),

        OV_MATCH(0x06, 0x14),

        OV_MATCH(0x09, 0x10),

        // XGSetSurfaceHeader+0x0F : push 0x00, push 0x00
        OV_MATCH(0x0F, 0x6A, 0x00, 0x6A, 0x00),
OOVPA_END;

// ******************************************************************
// * XGSetVolumeTextureHeader
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGSetVolumeTextureHeader, 3911, 10)

        // XGSetVolumeTextureHeader+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        OV_MATCH(0x05, 0x24),

        OV_MATCH(0x08, 0x28),

        // XGSetVolumeTextureHeader+0x09 : push 0x01, push 0x00
        OV_MATCH(0x09, 0x6A, 0x01, 0x6A, 0x00),

        // XGSetVolumeTextureHeader+0x28 : ret 0x0028
        OV_MATCH(0x28, 0xC2, 0x28, 0x00),
OOVPA_END;

// ******************************************************************
// * XGWriteSurfaceToFile
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(XGWriteSurfaceToFile, 3911, 12)

        // XGWriteSurfaceToFile+0x00 : push ebp
        OV_MATCH(0x00, 0x55),

        // XGWriteSurfaceToFile+0x03 : sub esp,0x0000036C
        OV_MATCH(0x03, 0x81, 0xEC, 0x6C, 0x03),

        // XGWriteSurfaceToFile+0x46 : push 0x28
        OV_MATCH(0x46, 0x6A, 0x28),

        // XGWriteSurfaceToFile+0x4B : push 0x02
        OV_MATCH(0x4B, 0x6A, 0x02),

        // XGWriteSurfaceToFile+0x4F : push 0x40000000
        OV_MATCH(0x4F, 0x68),
        OV_MATCH(0x52, 0x00, 0x40),
OOVPA_END;
