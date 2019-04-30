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
