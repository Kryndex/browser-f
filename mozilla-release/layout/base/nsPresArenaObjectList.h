/* vim: set shiftwidth=2 tabstop=8 autoindent cindent expandtab: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* a list of all types that can be allocated in an nsPresArena, for
   preprocessing */

#ifdef STYLE_STRUCT
#error Sorry nsPresArenaObjectList.h needs to use STYLE_STRUCT!
#endif

#ifdef PRES_ARENA_OBJECT
#if defined(PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT) || \
    defined(PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT)
#error Must not define PRES_ARENA_OBJECT along with \
       PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT or \
       PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT.
#endif
#define PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(name_) PRES_ARENA_OBJECT(name_)
#define PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT(name_) PRES_ARENA_OBJECT(name_)
#define DEFINED_PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#define DEFINED_PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#endif

#ifndef PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#define PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(name_) /* nothing */
#define DEFINED_PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#endif

#ifndef PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#define PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT(name_) /* nothing */
#define DEFINED_PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#endif

// Use PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT to mention an nsPresArena-
// allocated object that does not support ArenaRefPtr, and use
// PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT to mention one that does.
//
// All PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT classes must be #included into
// nsPresArena.cpp.
//
// Files including nsPresArenaObjectList.h can either define one or both
// of PRES_ARENA_OBJECT_{WITH,WITHOUT}_ARENAREFPTR_SUPPORT to capture those
// classes separately, or PRES_ARENA_OBJECT to capture all nsPresArena-
// allocated classes.

PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsLineBox)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsRuleNode)
PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT(nsStyleContext)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsInheritedStyleData)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsResetStyleData)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsConditionalResetStyleData)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsConditionalResetStyleDataEntry)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsFrameList)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(CustomCounterStyle)
PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(DependentBuiltinCounterStyle)

#define STYLE_STRUCT(name_, checkdata_cb_) \
  PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT(nsStyle##name_)
#include "nsStyleStructList.h"
#undef STYLE_STRUCT

#ifdef DEFINED_PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#undef PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#undef DEFINED_PRES_ARENA_OBJECT_WITHOUT_ARENAREFPTR_SUPPORT
#endif

#ifdef DEFINED_PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#undef PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#undef DEFINED_PRES_ARENA_OBJECT_WITH_ARENAREFPTR_SUPPORT
#endif