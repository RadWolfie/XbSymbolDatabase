// ******************************************************************
// *
// *   OOVPADatabase->Xapi->3911.inl
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
// *
// *  All rights reserved
// *
// ******************************************************************

// ******************************************************************
// * GetExitCodeThread
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(GetExitCodeThread,
                         3911)
OOVPA_SIG_MATCH(

    // GetExitCodeThread+0x03 : lea eax, [ebp+0x08]
    OV_MATCH(0x03, 0x8D, 0x45, 0x08),

    // GetExitCodeThread+0x1A : mov ecx, dword ptr [ebp+0x08]
    OV_MATCH(0x1A, 0x8B, 0x4D, 0x08),

    // GetExitCodeThread+0x2B : mov eax, 0x0103
    OV_MATCH(0x2B, 0xB8, 0x03, 0x01),

    // GetExitCodeThread+0x49 : retn 0x08
    OV_MATCH(0x49, 0xC2, 0x08),
    //
);

// ******************************************************************
// * XInitDevices
// ******************************************************************
// * NOTE: We are actually intercepting USBD_Init, because
// *       XInitDevices Simply redirects to that function
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInitDevices,
                         3911)
OOVPA_SIG_MATCH(

    // XInitDevices+0x03 : push 0xB4
    OV_MATCH(0x03, 0x68, 0xB4),

    // XInitDevices+0x10 : jmp +0x13
    OV_MATCH(0x10, 0x74, 0x13),

    // XInitDevices+0x5B : movzx eax, byte ptr [esi+0xA1]
    OV_MATCH(0x5B, 0x0F, 0xB6, 0x86, 0xA1),

    // XInitDevices+0x8B : retn 8
    OV_MATCH(0x8B, 0xC2, 0x08),
    //
);

// ******************************************************************
// * CreateMutex
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CreateMutex,
                         3911)
OOVPA_SIG_MATCH(

    // CreateMutex+0x03 : sub esp, 0x14
    OV_MATCH(0x03, 0x83, 0xEC, 0x14),

    // CreateMutex+0x32 : cmp eax, 0x40000000
    OV_MATCH(0x32, 0x3D, 0x00, 0x00, 0x00, 0x40),

    // CreateMutex+0x39 : push 0xB7
    OV_MATCH(0x39, 0x68, 0xB7),

    // CreateMutex+0x47 : mov eax, [ebp+0x10]
    OV_MATCH(0x47, 0x8B, 0x45, 0x10),
    //
);

// ******************************************************************
// * CreateThread
// ******************************************************************
// TODO: Add XapiThreadStartup xref here to reduce the OVPs.
//       Most of it is not really necessary.
OOVPA_SIG_HEADER_NO_XREF(CreateThread,
                         3911)
OOVPA_SIG_MATCH(

    // CreateThread+0x00 : push ebp; mov ebp,esp
    OV_MATCH(0x00, 0x55, 0x8B, 0xEC),

    // CreateThread+0x03 : mov eax,[ebp+0x0C]
    OV_MATCH(0x03, 0x8B, 0x45, 0x0C),

    // CreateThread+0x06 : test eax,eax
    OV_MATCH(0x06, 0x85, 0xC0),

    // CreateThread+0x08 : jne +0x05
    OV_MATCH(0x08, 0x75, 0x05),

    // CreateThread+0x0A : mov eax,[0x00010130]
    OV_MATCH(0x0A, 0xA1, 0x30, 0x01, 0x01, 0x00),

    // CreateThread+0x0F : mov ecx,[ebp+0x18]
    OV_MATCH(0x0F, 0x8B, 0x4D, 0x18),

    // CreateThread+0x12 : push XapiThreadStartup
    OV_MATCH(0x12, 0x68),

    // CreateThread+0x32 : push eax; push _
    OV_MATCH(0x32, 0x50, 0x6A),
    //
);

// ******************************************************************
// * SetThreadPriority
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(SetThreadPriority,
                         3911)
OOVPA_SIG_MATCH(

    // SetThreadPriority+0x00 : push ebp
    OV_MATCH(0x00, 0x55),

    // SetThreadPriority+0x22 : push 0x10
    OV_MATCH(0x22, 0x6A, 0x10),

    // SetThreadPriority+0x26 : cmp eax, 0xFFFFFFF1
    OV_MATCH(0x26, 0x83, 0xF8, 0xF1),

    // SetThreadPriority+0x2B : push 0xFFFFFFF0
    OV_MATCH(0x2B, 0x6A, 0xF0),

    // SetThreadPriority+0x4F : ret 0x0008
    OV_MATCH(0x4F, 0xC2, 0x08),
    //
);

// ******************************************************************
// * OutputDebugStringA
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(OutputDebugStringA,
                      3911,

                      XREF_XAPI_OutputDebugStringA,
                      XRefZero)
OOVPA_SIG_MATCH(

    // push ebp
    OV_MATCH(0x00, 0x55),

    // mov dl,[eax]
    OV_MATCH(0x0E, 0x8A, 0x10),

    // test dl,dl
    OV_MATCH(0x11, 0x84, 0xD2),

    // Unique asm code for first Interrupt 0x2D.
    // Interrupt 0x2D, Interrupt 3
    OV_MATCH(0x2B, 0xCD, 0x2D, 0xCC),

    // leave; ret 0x0004
    OV_MATCH(0x2F, 0xC2, 0x04),
    //
);

// ******************************************************************
// * OutputDebugStringW
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(OutputDebugStringW,
                      3911,

                      XRefNoSaveIndex,
                      XRefOne)
OOVPA_SIG_MATCH(

    // call [OutputDebugStringA]
    XREF_ENTRY(0x35, XREF_XAPI_OutputDebugStringA),

    // push ebp
    OV_MATCH(0x00, 0x55),

    // push 0x01
    OV_MATCH(0x14, 0x6A, 0x01),

    // push [ebp-0x04]
    OV_MATCH(0x31, 0xFF, 0x75, 0xFC),

    // leave; ret 0x0004
    OV_MATCH(0x49, 0xC2, 0x04),
    //
);

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XapiInitProcess,
                         3911)
OOVPA_SIG_MATCH(

    // XapiInitProcess+0x03 : sub esp, 30h
    { 0x05, 0x30 },

    // XapiInitProcess+0x0F : push 0x0C
    { 0x0F, 0x6A },
    { 0x10, 0x0C },

    // XapiInitProcess+0x17 : repe stosd
    { 0x17, 0xF3 },
    { 0x18, 0xAB },

    // XapiInitProcess+0x42 : jnz +0x0A
    { 0x42, 0x75 },
    { 0x43, 0x0A },
    //
);

// ******************************************************************
// * XapiBootDash
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XapiBootDash,
                         3911)
OOVPA_SIG_MATCH(

    // XapiBootDash+0x03 : sub esp, 0x0C00
    { 0x03, 0x81 },
    { 0x04, 0xEC },
    { 0x06, 0x0C },

    // XapiBootDash+0x09 : mov eax, ds:0x10118
    { 0x09, 0xA1 },
    { 0x0A, 0x18 },
    { 0x0B, 0x01 },
    { 0x0C, 0x01 },

    // XapiBootDash+0x25 : repe stosd
    { 0x25, 0xF3 },
    { 0x26, 0xAB },

    // XapiBootDash+0x59 : retn 0x0C
    { 0x59, 0xC2 },
    { 0x5A, 0x0C },
    //
);

// ******************************************************************
// * XRegisterThreadNotifyRoutine
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XRegisterThreadNotifyRoutine,
                         3911)
OOVPA_SIG_MATCH(

    // XRegisterThreadNotifyRoutine+0x0D : cmp [esp+0x0C], 0
    { 0x0D, 0x83 },
    { 0x0E, 0x7C },
    { 0x0F, 0x24 },
    { 0x10, 0x0C },

    // XRegisterThreadNotifyRoutine+0x12 : jz +0x1C
    { 0x12, 0x74 },
    { 0x13, 0x1C },

    // XRegisterThreadNotifyRoutine+0x24 : mov [eax+4], ecx
    { 0x24, 0x89 },
    { 0x25, 0x48 },
    { 0x26, 0x04 },

    // XRegisterThreadNotifyRoutine+0x46 : retn 0x08
    { 0x46, 0xC2 },
    { 0x47, 0x08 },
    //
);

// ******************************************************************
// * GetTimeZoneInformation
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(GetTimeZoneInformation,
                         3911)
OOVPA_SIG_MATCH(

    { 0x05, 0x28 },
    { 0x2E, 0x28 },
    { 0x4F, 0x59 },
    { 0x56, 0xAB },
    { 0x8C, 0xC0 },
    { 0xB9, 0x80 },
    { 0xF7, 0x99 },
    //
);

// not necessary?
// ******************************************************************
// * XCalculateSignatureBegin
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XCalculateSignatureBegin,
                         3911)
OOVPA_SIG_MATCH(

    // XCalculateSignatureBegin+0x01 : push 0x7C; push 0
    { 0x01, 0x6A },
    { 0x02, 0x7C },
    { 0x03, 0x6A },
    { 0x04, 0x00 },

    // XCalculateSignatureBegin+0x10 : push 0x08
    { 0x10, 0x6A },
    { 0x11, 0x08 },

    // XCalculateSignatureBegin+0x2E : push 0x10
    { 0x2E, 0x6A },
    { 0x2F, 0x10 },

    // XCalculateSignatureBegin+0x3B : retn 0x04
    { 0x3B, 0xC2 },
    { 0x3C, 0x04 },
    //
);

// ******************************************************************
// * XGetDevices
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XGetDevices,
                         3911)
OOVPA_SIG_MATCH(

    // XGetDevices+0x07 : mov edx, [esp+arg_0]
    { 0x07, 0x8B },
    { 0x08, 0x54 },
    { 0x09, 0x24 },
    { 0x0A, 0x08 },

    // XGetDevices+0x0D : and [edx+4], 0
    { 0x0D, 0x83 },
    { 0x0E, 0x62 },
    { 0x0F, 0x04 },
    { 0x10, 0x00 },

    // XGetDevices+0x11 : mov cl, al
    { 0x11, 0x8A },
    { 0x12, 0xC8 },

    // XGetDevices+0x16 : call KfLowerIrql
    { 0x16, 0xFF },
    { 0x17, 0x15 },

    // XGetDevices+0x1F : retn 4
    { 0x1F, 0xC2 },
    { 0x20, 0x04 },
    //
);

// ******************************************************************
// * XGetDeviceChanges
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XGetDeviceChanges,
                         3911)
OOVPA_SIG_MATCH(

    // XGetDeviceChanges+0x00 : push ebp
    OV_MATCH(0x00, 0x55),

    // XGetDeviceChanges+0x07 : xor eax, eax
    OV_MATCH(0x07, 0x33, 0xC0),

    // XGetDeviceChanges+0x33 : not edx
    OV_MATCH(0x33, 0xF7, 0xD2),

    // XGetDeviceChanges+0x42 : or edx, edi
    OV_MATCH(0x42, 0x0B, 0xD7),

    // XGetDeviceChanges+0x51 : mov cl, al
    OV_MATCH(0x51, 0x8A, 0xC8),
    //
);

// ******************************************************************
// * XInputOpen
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInputOpen,
                         3911)
OOVPA_SIG_MATCH(

    // XInputOpen+0x20 : jmp +0x0B
    { 0x20, 0xEB },
    { 0x21, 0x0B },

    // XInputOpen+0x29 : jnz +0x3D
    { 0x29, 0x75 },
    { 0x2A, 0x3D },

    // XInputOpen+0x4A : add edx, 0x10
    { 0x4A, 0x83 },
    { 0x4B, 0xC2 },
    { 0x4C, 0x10 },

    // XInputOpen+0x66 : jmp +0x09
    { 0x66, 0xEB },
    { 0x67, 0x09 },

    // XInputOpen+0x68 : push 0x57
    { 0x68, 0x6A },
    { 0x69, 0x57 },
    //
);

// ******************************************************************
// * XID_fCloseDevice
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XID_fCloseDevice,
                      3911,

                      XREF_XID_fCloseDevice,
                      XRefZero)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x14 },
    { 0x06, 0x53 },
    { 0x07, 0x56 },
    { 0x08, 0x8B },
    { 0x09, 0xF1 },
    { 0x0A, 0xFF },
    { 0x0B, 0x15 },

    { 0x3E, 0x8D },
    { 0x3F, 0x45 },

    { 0x44, 0x8D },
    { 0x45, 0x45 },
    //
);

// ******************************************************************
// * XInputClose
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XInputClose,
                      3911,

                      XRefNoSaveIndex,
                      XRefOne)
OOVPA_SIG_MATCH(

    // XInputClose+0x05 : call [fCloseDevice]
    XREF_ENTRY(0x05, XREF_XID_fCloseDevice),

    // XInputClose+0x00 : mov ecx, [esp+0x04]
    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x02, 0x24 },
    { 0x03, 0x04 },

    // XInputClose+0x04 : call [fCloseDevice]
    { 0x04, 0xE8 },

    // XInputClose+0x09 : retn 0x04
    { 0x09, 0xC2 },
    { 0x0A, 0x04 },
    //
);

// ******************************************************************
// * XInputGetCapabilities
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInputGetCapabilities,
                         3911)
OOVPA_SIG_MATCH(

    OV_MATCH(0x00, 0x55),

    OV_MATCH(0x0F, 0x15),

    OV_MATCH(0x1E, 0x0F, 0x84),

    // mov edi,edx; rep stos [edi]
    OV_MATCH(0x36, 0x8B, 0xFA, 0xF3, 0xAB),

    // stos [edi]; mov al,[esi+0x0B]
    OV_MATCH(0x3A, 0xAA, 0x8A, 0x46, 0x0B),

    OV_MATCH(0x3E, 0x88),
    //
);

// ******************************************************************
// * XInputGetState
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInputGetState,
                         3911)
OOVPA_SIG_MATCH(

    // XInputGetState+0x0E : cmp byte ptr [edx+0x0A3], 1
    { 0x0E, 0x80 },
    { 0x0F, 0xBA },
    { 0x10, 0xA3 },
    { 0x14, 0x01 },

    // XInputGetState+0x17 : push 0x57
    { 0x17, 0x6A },
    { 0x18, 0x57 },

    // XInputGetState+0x1A : jmp +0x46
    { 0x1A, 0xEB },
    { 0x1B, 0x46 },

    // XInputGetState+0x28 : mov ebx, 0x048F
    { 0x28, 0xBB },
    { 0x29, 0x8F },
    { 0x2A, 0x04 },

    // XInputGetState+0x6E : retn 8
    { 0x6E, 0xC2 },
    { 0x6F, 0x08 },
    //
);

// ******************************************************************
// * XInputSetState
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInputSetState,
                         3911)
OOVPA_SIG_MATCH(

    // XInputSetState+0x04 : lea eax, [ecx+0x0A3]
    { 0x04, 0x8D },
    { 0x05, 0x81 },
    { 0x06, 0xA3 },

    // XInputSetState+0x0F : push 0x57
    { 0x0F, 0x6A },
    { 0x10, 0x57 },

    // XInputSetState+0x12 : jmp +0x21
    { 0x12, 0xEB },
    { 0x13, 0x21 },

    // XInputSetState+0x2D : mov [edx+0x41], al
    { 0x2D, 0x88 },
    { 0x2E, 0x42 },
    { 0x2F, 0x41 },

    // XInputSetState+0x35 : retn 0x08
    { 0x35, 0xC2 },
    { 0x36, 0x08 },
    //
);

// ******************************************************************
// * SetThreadPriorityBoost
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(SetThreadPriorityBoost,
                         3911) // generic version
OOVPA_SIG_MATCH(

    // SetThreadPriorityBoost+0x0D : push [ebp+0x08]
    { 0x0D, 0xFF },
    { 0x0E, 0x75 },
    { 0x0F, 0x08 },

    // SetThreadPriorityBoost+0x18 : jl +0x20
    { 0x18, 0x7C },
    { 0x19, 0x20 },

    // SetThreadPriorityBoost+0x1F : setnz al
    { 0x1F, 0x0F },
    { 0x20, 0x95 },
    { 0x21, 0xC0 },

    // SetThreadPriorityBoost+0x2C : mov ecx, [ebp+0x08]
    { 0x2C, 0x8B },
    { 0x2D, 0x4D },
    //
);

// ******************************************************************
// * GetThreadPriority
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(GetThreadPriority,
                         3911)
OOVPA_SIG_MATCH(

    // GetThreadPriority+0x0D : push [ebp+0x08]
    { 0x0D, 0xFF },
    { 0x0E, 0x75 },
    { 0x0F, 0x08 },

    // GetThreadPriority+0x18 : jl +0x2B
    { 0x18, 0x7C },
    { 0x19, 0x2B },

    // GetThreadPriority+0x2F : cmp esi, 0xFFFFFFF0
    { 0x2F, 0x83 },
    { 0x30, 0xFE },
    { 0x31, 0xF0 },

    // GetThreadPriority+0x37 : mov ecx, [ebp+0x08]
    { 0x37, 0x8B },
    { 0x38, 0x4D },
    //
);

// ******************************************************************
// * CreateFiber
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CreateFiber,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x56 },
    { 0x05, 0x57 },
    { 0x06, 0x33 },
    { 0x07, 0xFF },
    { 0x08, 0x3B },
    { 0x09, 0xC7 },
    { 0x0A, 0x75 },
    { 0x0B, 0x05 },
    { 0x0C, 0xA1 },
    { 0x0D, 0x30 },
    { 0x0E, 0x01 },
    { 0x0F, 0x01 },
    { 0x10, 0x00 },
    { 0x11, 0xB9 },
    { 0x12, 0x00 },
    { 0x13, 0x30 },
    { 0x14, 0x00 },
    { 0x15, 0x00 },
    { 0x16, 0x3B },
    { 0x17, 0xC1 },
    { 0x18, 0x73 },
    { 0x19, 0x02 },
    { 0x1A, 0x8B },
    { 0x1B, 0xC1 },
    { 0x1C, 0x8D },
    { 0x1D, 0xB0 },
    { 0x1E, 0xFF },
    { 0x1F, 0x0F },
    //
);

// ******************************************************************
// * DeleteFiber
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(DeleteFiber,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x44 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0xFF },
    { 0x05, 0x70 },
    { 0x06, 0x08 },
    { 0x07, 0xFF },
    { 0x08, 0x70 },
    { 0x09, 0x04 },
    { 0x0A, 0xFF },
    { 0x0B, 0x15 },

    { 0x10, 0xC2 },
    { 0x11, 0x04 },
    { 0x12, 0x00 },
    //
);

// ******************************************************************
// * SwitchToFiber
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(SwitchToFiber,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x01, 0x15 },

    { 0x06, 0x64 },
    { 0x07, 0x8B },
    { 0x08, 0x0D },
    { 0x09, 0x04 },
    { 0x0A, 0x00 },
    { 0x0B, 0x00 },
    { 0x0C, 0x00 },
    { 0x0D, 0x8B },
    { 0x0E, 0x44 },
    { 0x0F, 0x24 },
    { 0x10, 0x04 },
    { 0x11, 0x55 },
    { 0x12, 0x56 },
    { 0x13, 0x57 },
    { 0x14, 0x53 },
    { 0x15, 0x64 },
    { 0x16, 0xFF },
    { 0x17, 0x35 },
    { 0x18, 0x00 },
    { 0x19, 0x00 },
    { 0x1A, 0x00 },
    { 0x1B, 0x00 },
    { 0x1C, 0x8B },
    { 0x1D, 0x14 },
    { 0x1E, 0x91 },
    { 0x1F, 0x8B },
    //
);

// ******************************************************************
// * ConvertThreadToFiber
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(ConvertThreadToFiber,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xA1 },

    { 0x05, 0x64 },
    { 0x06, 0x8B },
    { 0x07, 0x0D },

    { 0x0C, 0x8B },
    { 0x0D, 0x14 },
    { 0x0E, 0x81 },
    { 0x0F, 0x8B },
    { 0x10, 0x44 },
    { 0x11, 0x24 },
    { 0x12, 0x04 },
    { 0x13, 0x8D },
    { 0x14, 0x8A },

    { 0x19, 0x89 },
    { 0x1A, 0x01 },
    { 0x1B, 0x64 },
    { 0x1C, 0xA1 },
    { 0x1D, 0x28 },
    { 0x1E, 0x00 },
    { 0x1F, 0x00 },
    //
);

// ******************************************************************
// * SignalObjectAndWait
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(SignalObjectAndWait,
                         3911) // generic version
OOVPA_SIG_MATCH(

    { 0x07, 0x75 },
    { 0x12, 0x8B },
    { 0x19, 0x01 },
    { 0x26, 0x85 },
    { 0x2B, 0x7D },
    { 0x34, 0x00 },
    { 0x3F, 0x83 },
    { 0x46, 0x00 },
    //
);

// ******************************************************************
// * QueueUserAPC
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(QueueUserAPC,
                         3911) // generic version
OOVPA_SIG_MATCH(

    { 0x03, 0x74 },
    { 0x08, 0x24 },
    { 0x0F, 0xFF },
    { 0x12, 0x18 },
    { 0x19, 0x33 },
    { 0x1C, 0xC0 },
    { 0x21, 0xC1 },
    //
);

// ******************************************************************
// * QueryPerformanceCounter
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(QueryPerformanceCounter,
                         3911) // generic version
OOVPA_SIG_MATCH(
    { 0x00, 0x8B },
    { 0x01, 0x4C },
    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x04, 0x0F },
    { 0x05, 0x31 },
    { 0x06, 0x89 },
    { 0x07, 0x01 },
    { 0x08, 0x89 },
    { 0x09, 0x51 },
    { 0x0A, 0x04 },
    { 0x0B, 0x33 },
    { 0x0C, 0xC0 },
    { 0x0D, 0x40 },
    { 0x0E, 0xC2 },
    { 0x0F, 0x04 },
    { 0x10, 0x00 },
    //
);

// ******************************************************************
// * lstrcmpiW
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(lstrcmpiW,
                         3911)
OOVPA_SIG_MATCH(

    { 0x07, 0x56 },
    { 0x0F, 0x01 },
    { 0x10, 0xE8 },
    { 0x19, 0x39 },
    { 0x22, 0x0E },
    { 0x2D, 0x59 },
    { 0x34, 0xEB },
    { 0x3D, 0x03 },
    //
);

// ******************************************************************
// * XMountAlternateTitleA
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XMountAlternateTitleA,
                         3911)
OOVPA_SIG_MATCH(

    { 0x04, 0xEC },

    { 0x0F, 0x18 },
    { 0x10, 0x01 },
    { 0x11, 0x01 },
    { 0x12, 0x00 },
    { 0x13, 0x53 },
    { 0x14, 0x8A },

    { 0x30, 0x39 },
    { 0x31, 0x55 },
    { 0x32, 0x0C },
    { 0x33, 0x74 },
    { 0x34, 0x09 },

    { 0x3D, 0xEC },
    //
);

// ******************************************************************
// * XUnmountAlternateTitleA
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XUnmountAlternateTitleA,
                      3911,

                      XREF_XUnmountAlternateTitleA,
                      XRefZero)
OOVPA_SIG_MATCH(

    { 0x0A, 0x65 },
    { 0x16, 0xFF },
    { 0x23, 0x83 },
    { 0x2E, 0x45 },
    { 0x3A, 0x50 },
    { 0x46, 0x0B },
    { 0x52, 0x50 },
    //
);

// ******************************************************************
// * XMountMUA
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XMountMUA,
                      3911,

                      XRefNoSaveIndex,
                      XRefTwo)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x2E, XREF_g_XapiMountedMUs), // derived
    XREF_ENTRY(0xCE, XREF_XapiMapLetterToDirectory),

    { 0x1E, 0x0C },
    { 0x3E, 0x66 },
    { 0x61, 0x85 },
    { 0x7E, 0x8D },
    { 0xA2, 0x0F },
    { 0xBE, 0x50 },
    { 0xDE, 0x74 },
    //
);

// ******************************************************************
// * CloseHandle
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(CloseHandle,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0x24 },
    { 0x03, 0x04 },
    { 0x0A, 0x85 },
    { 0x0B, 0xC0 },
    { 0x0E, 0x33 },
    { 0x12, 0x08 },
    { 0x19, 0x33 },
    { 0x1A, 0xC0 },
    //
);

// Generic OOVPA as of 3911 and newer.
// ******************************************************************
// * ExitThread
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(ExitThread,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x6A },
    { 0x01, 0x00 },
    { 0x02, 0xE8 },
    { 0x07, 0xFF },
    { 0x08, 0x74 },
    { 0x09, 0x24 },
    { 0x0A, 0x04 },
    { 0x0B, 0xFF },
    { 0x0C, 0x15 },
    { 0x11, 0xCC },
    //
);

// ******************************************************************
// * XLaunchNewImageA
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XLaunchNewImageA,
                         3911)
OOVPA_SIG_MATCH(

    { 0x1E, 0x80 },
    { 0x3E, 0xC0 },
    { 0x5E, 0xFF },
    { 0x7E, 0xFC },
    { 0x9E, 0x08 },
    { 0xBE, 0x50 },
    { 0xDE, 0x05 },
    { 0xFE, 0x85 },
    //
);

// ******************************************************************
// * XGetLaunchInfo
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XGetLaunchInfo,
                         3911)
OOVPA_SIG_MATCH(

    { 0x0B, 0x8B },
    { 0x18, 0x15 },
    { 0x25, 0x8B },
    { 0x32, 0x30 },
    { 0x3F, 0x00 },
    { 0x4C, 0x83 },
    { 0x59, 0x5E },
    //
);

// ******************************************************************
// * XGetSectionHandleA
//   558BEC83EC10538B1D........5657FF75088D45F050FFD38B351C0101008B3D
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XGetSectionHandleA,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x10 },
    { 0x06, 0x53 },
    { 0x07, 0x8B },
    { 0x08, 0x1D },

    { 0x0D, 0x56 },
    { 0x0E, 0x57 },
    { 0x0F, 0xFF },
    //
);

// ******************************************************************
// * XLoadSectionByHandle
//  568B74240856FF15........85C07D0A50E8........33C0EB038B46045EC204
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XLoadSectionByHandle,
                         3911)
OOVPA_SIG_MATCH(

    // XLoadSectionByHandle+0x01 : mov esi, [esp+4+arg_0]
    { 0x01, 0x8B },
    { 0x02, 0x74 },
    { 0x03, 0x24 },
    { 0x04, 0x08 },

    // XLoadSectionByHandle+0x0C : test eax, eax
    { 0x0C, 0x85 },
    { 0x0D, 0xC0 },

    // XLoadSectionByHandle+0x1A : mov eax, [esi+4]
    { 0x1A, 0x8B },
    { 0x1B, 0x46 },
    { 0x1C, 0x04 },

    // XLoadSectionByHandle+0x1E : retn 4
    { 0x1E, 0xC2 },
    { 0x1F, 0x04 },
    //
);

// ******************************************************************
// * XFreeSectionByHandle
// FF742404FF15........85C07D0A50E8........33C0EB0333C040C20400....
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XFreeSectionByHandle,
                         3911)
OOVPA_SIG_MATCH(

    // XFreeSectionByHandle+0x00 : push esp
    { 0x00, 0xFF },
    { 0x01, 0x74 },
    { 0x02, 0x24 },
    { 0x03, 0x04 },

    // XFreeSectionByHandle+0x0A : test eax, eax
    { 0x0A, 0x85 },
    { 0x0B, 0xC0 },

    // XFreeSectionByHandle+0x18 : xor eax, eax
    { 0x18, 0x33 },
    { 0x19, 0xC0 },

    // XFreeSectionByHandle+0x1A : inc eax
    { 0x1A, 0x40 },

    // XFreeSectionByHandle+0x1B : retn 4
    { 0x1B, 0xC2 },
    { 0x1C, 0x04 },
    //
);

// ******************************************************************
// * XAutoPowerDownResetTimer
// ******************************************************************
// Assembly line at 0x00 and 0x09 are unique. It will prevent any false detection it might find in the future.
OOVPA_SIG_HEADER_NO_XREF(XAutoPowerDownResetTimer,
                         3911)
OOVPA_SIG_MATCH(

    //XAutoPowerDownResetTimer+0x00 : push 0FFFFFFCDh
    { 0x00, 0x6A },
    { 0x01, 0xCD },

    //XAutoPowerDownResetTimer+0x02 : pop ecx
    { 0x02, 0x59 },

    //XAutoPowerDownResetTimer+0x08 : push ecx
    { 0x08, 0x51 },

    //XAutoPowerDownResetTimer+0x09 : mov eax, 0B5659000h
    { 0x09, 0xB8 },
    { 0x0A, 0x00 },
    { 0x0B, 0x90 },
    { 0x0C, 0x65 },
    { 0x0D, 0xB5 },

    //XAutoPowerDownResetTimer+0x0E : push eax
    { 0x0E, 0x50 },

    { 0x14, 0xFF },

    //XAutoPowerDownResetTimer+0x1A : ret
    { 0x1A, 0xC3 },
    //
);

// ******************************************************************
// * XMountMURootA
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XMountMURootA,
                      3911,

                      XRefNoSaveIndex,
                      XRefOne)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x2D, XREF_g_XapiMountedMUs), // derived

    { 0x1E, 0x0C },
    { 0x3E, 0x00 },
    { 0x61, 0x8B },
    { 0x7E, 0x00 },
    { 0x9E, 0x00 },
    { 0xBE, 0xFF },
    { 0xDE, 0xFF },
    //
);

// ******************************************************************
// * XMountUtilityDrive
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XMountUtilityDrive,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x81 },
    { 0x04, 0xEC },
    { 0x05, 0x14 },
    { 0x06, 0x01 },
    { 0x07, 0x00 },
    { 0x08, 0x00 },
    { 0x09, 0x53 },
    { 0x0A, 0x56 },
    { 0x0B, 0x57 },
    { 0x0C, 0x8D },
    { 0x0D, 0x45 },
    { 0x0E, 0xF4 },
    { 0x0F, 0x50 },
    { 0x10, 0x8D },
    { 0x11, 0x45 },
    { 0x12, 0xFC },
    { 0x13, 0x50 },
    { 0x14, 0xFF },
    { 0x15, 0x75 },
    { 0x16, 0x08 },
    { 0x17, 0xE8 },

    { 0x56, 0x83 },
    { 0x57, 0xC4 },
    //
);

// ******************************************************************
// * ReadFileEx@20
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(ReadFileEx,
                         3911)
OOVPA_SIG_MATCH(

    { 0x09, 0x48 },
    { 0x14, 0x8D },
    { 0x1F, 0xFF },
    { 0x2A, 0xFF },
    { 0x2F, 0x00 },
    { 0x35, 0x00 },
    { 0x40, 0x50 },
    { 0x4B, 0xC0 },
    //
);

// ******************************************************************
// * WriteFileEx
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(WriteFileEx,
                         3911)
OOVPA_SIG_MATCH(

    { 0x09, 0x48 },
    { 0x14, 0x8D },
    { 0x1F, 0xFF },
    { 0x2A, 0xFF },
    { 0x2F, 0xFC },
    { 0x35, 0x00 },
    { 0x40, 0x50 },
    { 0x4B, 0xC0 },
    //
);

// ******************************************************************
// * XInputPoll
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(XInputPoll,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x53 },
    { 0x01, 0x56 },
    { 0x02, 0x33 },
    { 0x03, 0xF6 },
    { 0x04, 0xFF },
    { 0x05, 0x15 },

    { 0x18, 0x04 },
    { 0x19, 0x02 },
    { 0x1A, 0x75 },
    { 0x1B, 0x29 },
    { 0x1C, 0xF6 },
    { 0x1D, 0x80 },
    { 0x1E, 0xA2 },
    { 0x1F, 0x00 },
    //
);

// ******************************************************************
// * timeSetEvent
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(timeSetEvent,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x14 },
    { 0x06, 0x53 },
    { 0x07, 0x68 },

    { 0x1B, 0xCB },
    { 0x1C, 0x75 },

    { 0x2A, 0x45 },
    { 0x55, 0x53 },
    //
);

// ******************************************************************
// * timeKillEvent
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(timeKillEvent,
                         3911)
OOVPA_SIG_MATCH(

    { 0x02, 0xBF },
    { 0x13, 0x0D },

    { 0x18, 0x0F },
    { 0x19, 0xB7 },
    { 0x1A, 0xC2 },
    { 0x1B, 0x48 },
    { 0x1C, 0x85 },
    { 0x1D, 0xC9 },
    { 0x1E, 0x74 },
    { 0x1F, 0x3E },

    { 0x4A, 0x6A },
    { 0x55, 0x15 },
    //
);

// ******************************************************************
// * GetOverlappedResult
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(GetOverlappedResult,
                         3911)
OOVPA_SIG_MATCH(

    { 0x0B, 0x75 },
    { 0x18, 0xC0 },
    { 0x27, 0xEB },
    { 0x32, 0x00 },
    { 0x3F, 0xEB },
    { 0x4C, 0x89 },
    { 0x59, 0x56 },
    //
);

// ******************************************************************
// * RaiseException
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(RaiseException,
                         3911)
OOVPA_SIG_MATCH(

    { 0x09, 0x83 },
    { 0x14, 0x8B },
    { 0x1F, 0xC7 },
    { 0x2A, 0x10 },
    { 0x35, 0x89 },
    { 0x40, 0x5F },
    { 0x4B, 0xFF },
    //
);

// Generic OOVPA as of 3911 and newer.
// ******************************************************************
// * SwitchToThread
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(SwitchToThread,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0xFF },
    { 0x01, 0x15 },
    { 0x06, 0x33 },
    { 0x07, 0xC9 },
    { 0x08, 0x3D },
    { 0x09, 0x24 },
    { 0x0A, 0x00 },
    { 0x0B, 0x00 },
    { 0x0C, 0x40 },
    { 0x0D, 0x0F },
    { 0x0E, 0x95 },
    { 0x0F, 0xC1 },
    { 0x10, 0x8B },
    { 0x11, 0xC1 },
    { 0x12, 0xC3 },
    //
);

// ******************************************************************
// * XapiThreadStartup
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(XapiThreadStartup,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x6A },
    { 0x01, 0x18 },
    { 0x02, 0x68 },
    { 0x07, 0xE8 },
    { 0x0C, 0x83 },
    { 0x0D, 0x65 },
    { 0x0E, 0xFC },
    { 0x0F, 0x00 },
    { 0x10, 0x64 },
    { 0x11, 0xA1 },
    { 0x12, 0x28 },
    { 0x13, 0x00 },
    { 0x14, 0x00 },
    { 0x15, 0x00 },
    { 0x16, 0x89 },
    { 0x17, 0x45 },
    //{ 0x18, 0xE4 }, 3911 0xE4 vs 5558 0xE0

    { 0x1F, 0x89 },
    //
);

// Generic OOVPA as of 3911 and newer.
// ******************************************************************
// * MoveFileA
// ******************************************************************
OOVPA_SIG_HEADER_NO_XREF(MoveFileA,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x55 },
    { 0x01, 0x8B },
    { 0x02, 0xEC },
    { 0x03, 0x83 },
    { 0x04, 0xEC },
    { 0x05, 0x2C },
    { 0x06, 0x56 },
    { 0x07, 0x8B },
    { 0x08, 0x35 },

    { 0x1F, 0x8D },
    { 0x93, 0xC2 },
    { 0x94, 0x08 },
    //
);

// ******************************************************************
// * XapiFiberStartup
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_NO_XREF(XapiFiberStartup,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x6A },
    { 0x01, 0x08 },

    { 0x25, 0xFF },
    { 0x26, 0x30 },
    { 0x27, 0xFF },
    { 0x28, 0x55 },
    { 0x29, 0x08 },
    { 0x2A, 0xEB },
    { 0x2B, 0x0C },
    { 0x2C, 0xFF },
    { 0x2D, 0x75 },
    { 0x2E, 0xEC },
    { 0x2F, 0xE8 },

    { 0x44, 0xCC },
    //
);

// ******************************************************************
// * XUnmountMU
// ******************************************************************
OOVPA_SIG_HEADER_XREF(XUnmountMU,
                      3911,

                      XRefNoSaveIndex,
                      XRefTwo)
OOVPA_SIG_MATCH(

    XREF_ENTRY(0x1F, XREF_g_XapiMountedMUs), // derived
    XREF_ENTRY(0x38, XREF_XUnmountAlternateTitleA),

    // push EBP
    // mov EBP, ESP
    OV_MATCH(0x00, 0x55, 0x8B, 0xEC),

    // push 0x20
    // push 0x01
    // xor edi, edi
    OV_MATCH(0x5D, 0x6A, 0x20, 0x6A, 0x01, 0x33, 0xFF),

    //
);

// ******************************************************************
// * MU_Init
// ******************************************************************
OOVPA_SIG_HEADER_XREF(MU_Init,
                      3911,

                      XREF_MU_Init,
                      XRefZero)
OOVPA_SIG_MATCH(

    // push ebp
    // mov ebp, esp
    // sub esp, 0x10
    OV_MATCH(0x00, 0x55, 0x8B, 0xEC, 0x83, 0xEC, 0x10),

    // push eax
    // push 0x00
    // push 0x3A
    // lea eax, [ebp-0x10]
    OV_MATCH(0x95, 0x50, 0x6A, 0x00, 0x6A, 0x3A, 0x8D, 0x45, 0xF0),

    //
);

// ******************************************************************
// * XapiMapLetterToDirectory
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(XapiMapLetterToDirectory,
                      3911,

                      XREF_XapiMapLetterToDirectory,
                      XRefZero)
OOVPA_SIG_MATCH(

    // push ebp
    // mov ebp, esp
    // sub esp, 0x284
    OV_MATCH(0x00, 0x55, 0x8B, 0xEC, 0x81, 0xEC, 0x84, 0x02, 0x00),

    // push 0x03
    // push 0x03
    // mov edi, 0x80
    OV_MATCH(0x14, 0x6A, 0x03, 0x6A, 0x03, 0xBF, 0x80, 0x00 /*, 0x00, 0x00*/),

    //
);

// ******************************************************************
// * IUsbInit::GetMaxDeviceTypeCount
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(IUsbInit_GetMaxDeviceTypeCount,
                      3911,

                      XREF_IUsbInit_GetMaxDeviceTypeCount,
                      XRefZero)
OOVPA_SIG_MATCH(

    // mov edx, [ecx + 0x9C]
    OV_MATCH(0x00, 0x8B, 0x91, 0x9C, 0x00, 0x00 /*, 0x00*/),

    // mov ecx, [ecx + 0x98]
    OV_MATCH(0x0C, 0x8B, 0x89, 0x98, 0x00, 0x00 /*, 0x00*/),

    // ret 0x4
    OV_MATCH(0x2E, 0xC2, 0x04 /*, 0x00*/)

    //
);

// ******************************************************************
// * XGetSectionSize
// ******************************************************************
// TODO: Need verify with Def Jam Fight For NY (5849)
//   * Reason: duplicate symbol detection + very weak method
//     as it is very short function.
//   * Actually, Splinter Cell Pandora Tomorrow (5788) has same issue
//     except has a lot more duplicated symbols.
OOVPA_SIG_HEADER_NO_XREF(XGetSectionSize,
                         3911)
OOVPA_SIG_MATCH(

    { 0x00, 0x8B },
    { 0x02, 0x24 },
    { 0x04, 0x8B },
    { 0x06, 0x08 },
    { 0x08, 0x04 },
    //
);

// ******************************************************************
// * _cinit
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(_cinit,
                      3911,

                      XREF_XAPI__cinit,
                      XRefZero)
OOVPA_SIG_MATCH(

    // mov eax,[...]
    OV_MATCH(0x00, 0xA1),

    // mov eax,...
    OV_MATCH(0x0D, 0xB8),
    // mov edi,...
    OV_MATCH(0x12, 0xBF),

    // cmp eax,0xFF
    OV_MATCH(0x23, 0x83, 0xF8, 0xFF),

    // cmp eax,0xFF
    OV_MATCH(0x47, 0x83, 0xF8, 0xFF),

    // call eax
    OV_MATCH(0x4C, 0xFF, 0xD0),

    // ret
    OV_MATCH(0x57, 0xC3),
    //
);

// ******************************************************************
// * _rtinit
// ******************************************************************
// Generic OOVPA as of 3911 and newer.
OOVPA_SIG_HEADER_XREF(_rtinit,
                      3911,

                      XREF_XAPI__rtinit,
                      XRefZero)
OOVPA_SIG_MATCH(

    // push esi; push edi
    OV_MATCH(0x00, 0x56, 0x57),

    // mov eax,...
    OV_MATCH(0x02, 0xB8),
    // mov edi,...
    OV_MATCH(0x07, 0xBF),

    // cmp eax,0xFF
    OV_MATCH(0x18, 0x83, 0xF8, 0xFF),

    // call eax
    OV_MATCH(0x1D, 0xFF, 0xD0),

    // ret
    OV_MATCH(0x28, 0xC3),
    //
);
