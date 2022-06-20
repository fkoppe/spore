/************************************************************************************
*                                                                                   *
*   spore - https://github.com/fkoppe/spore                                         *
*   ************************************************************************        *
*                                                                                   *
*   Copyright (C) 2022 Felix Koppe <fkoppe@web.de>                                  *
*                                                                                   *
*   This program is free software: you can redistribute it and/or modify            *
*   it under the terms of the GNU Affero General Public License as published        *
*   by the Free Software Foundation, either version 3 of the License, or            *
*   (at your option) any later version.                                             *
*                                                                                   *
*   This program is distributed in the hope that it will be useful,                 *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   *
*   GNU Affero General Public License for more details.                             *
*                                                                                   *
*   You should have received a copy of the GNU Affero General Public License        *
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.          *
*                                                                                   *
************************************************************************************/

#ifndef ___SPRX___ERROR_H
#define ___SPRX___ERROR_H

#include "sprx/core/essentials.h"

typedef struct SPRX_Error
{
    const char* type;
    const bool evil;
    const char* what;
    const char* name;
    const char* info;
    const char* care;
} SPRX_Error;

#define SPRX_ERROR_UNDEFINED(name, info, care) (SPRX_Error[]){ "undefined", true, "<no information>", name, info, care }
#define SPRX_ERROR_RUNTIME(what, name, info, care) (SPRX_Error[]){ "runtime", true, what, name, info, care }
#define SPRX_ERROR_ALLOCATION(name, info, care) (SPRX_Error[]){ "allocation", true, "m-/ca-/realloc failed", name, info, care }
#define SPRX_ERROR_OVERFLOW(what, name, info, care) (SPRX_Error[]){ "overflow", true, what, name, info, care }
#define SPRX_ERROR_UNDERFLOW(what, name, info, care) (SPRX_Error[]){ "underflow", true, what, name, info, care }
#define SPRX_ERROR_PTR(name, info, care) (SPRX_Error[]){ "ptr", true, "invalid pointer", name, info, care }

#define SPRX_ERROR_UNKNOWN(name, info, care) (SPRX_Error[]){ "unknown", false, "<no information>", name, info, care }
#define SPRX_ERROR_NULL(name, info, care) (SPRX_Error[]){ "null", false, "unexpected null-pointer", name, info, care }
#define SPRX_ERROR_BOUNDS(name, care) (SPRX_Error[]){ "bounds", false, "invalid switch expression value", name, info, care }
#define SPRX_ERROR_ENUM(name, info, care) (SPRX_Error[]){ "enum", false, "invalid enum value", name, info, care }

#endif // ___SPRX___ERROR_H
