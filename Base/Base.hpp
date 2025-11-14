// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#include <cfloat>
#include <cstdint>
#include <cstdlib>

#ifndef USER_NAMESPACE
	#error "ModuleBase: Please define USER_NAMESPACE with a user namespace name."
#endif

#include "Context.hpp"
#include "Macros.hpp"

#include "Aliases.hpp"
#include "Limits.hpp"
#include "Cast.hpp"
#include "Utilities.hpp"
#include "Bit.hpp"
#include "Types/sequence.hpp"
#include "Types/view.hpp"

#if OPERATING_SYSTEM == OPERATING_SYSTEM_WINDOWS
	#include <Windows.h>
#endif