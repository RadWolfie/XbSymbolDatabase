// SPDX-License-Identifier: ODbL-1.0

#include "unittest.hpp"

static const library_list database_full = {
    REGISTER_SYMBOL_INLINE(CXo_XOnlineLogon, VER_RANGE(4361, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineLogon, VER_RANGE(4361, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(CXo_XOnlineMatchSearch, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineMatchSearch, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(CXo_XOnlineMatchSearchResultsLen, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineMatchSearchResultsLen, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(CXo_XOnlineMatchSearchGetResults, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineMatchSearchGetResults, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(CXo_XOnlineMatchSessionUpdate, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineMatchSessionUpdate, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(CXo_XOnlineMatchSessionCreate, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XOnlineMatchSessionCreate, VER_RANGE(4831, VER_MAX, VER_NONE, VER_NONE)),
    REGISTER_SYMBOL_INLINE(XoUpdateLaunchNewImageInternal, VER_RANGE(4627, VER_MAX, VER_NONE, VER_NONE)),
};

enum LOCAL_XREFS {
#undef XREF_SYMBOL
#define XREF_SYMBOL(e) e,
#include <xref/xonline.def>
#undef XREF_SYMBOL
    LOCAL_COUNT
};

// Verify if symbol name is at start of offset.
#define XREF_SYMBOL_GET(e) e
#define XREF_OFFSET XREF_SYMBOL_GET(CXo_XOnlineLogon)
static_assert(XREF_OFFSET == 0);
// Then get symbol's actual offset.
#undef XREF_SYMBOL_GET
#define XREF_SYMBOL_GET(e) XREF_##e

static const subcategory_db xonline_db = {
    .name = "general",
    .optional = nullptr,
    .min = nullptr, //&database_min,
    .full = &database_full,
};

void getLibraryXONLINE(library_db& lib_db)
{
    lib_db.subcategories = { &xonline_db };
    lib_db.xref_offset = XREF_OFFSET;
    lib_db.xref_total = LOCAL_COUNT;
    lib_db.xref_exclude = 0;
}
