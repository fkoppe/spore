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
    const char* what;
    const char* name;
    const char* info;
    const char* care;
} SPRX_Error;

#define SPRX_ERROR_UNKNOWN(name) (SPRX_Error[]){ "unknown", "<no information>", name, "must not occur", NULL }
#define SPRX_ERROR_UNDEFINED(name, info) (SPRX_Error[]){ "undefined", "<no information>", name, info }

#define SPRX_ERROR_ALLOCATION(name, info, care) (SPRX_Error[]){ "allocation", "m-/ca-/realloc failed", name, info, care }

#define SPRX_ERROR_RUNTIME(what, name, info, care) (SPRX_Error[]){ "runtime", what, name, info, care }
    #define SPRX_ERROR_OVERFLOW(name, info, care) SPRX_ERROR_RUNTIME("overflow", name, info, care)
    #define SPRX_ERROR_UNDERFLOW(name, info, care) SPRX_ERROR_RUNTIME("underflow", name, info ,care)
    #define SPRX_ERROR_PTR(name, info, care) SPRX_ERROR_RUNTIME("invalid pointer", name, info, care)
    #define SPRX_ERROR_BOUNDS(name, info, care) SPRX_ERROR_RUNTIME("invalid switch value", name, info, care)

#define SPRX_ERROR_LOGIC(what, name, info, care) (SPRX_Error[]){ "logic", what, name, info, care }
    #define SPRX_ERROR_ARGUMENT(name, info, care) SPRX_ERROR_LOGIC("invalid argument", name, info, care)
    #define SPRX_ERROR_NULL(name, info) SPRX_ERROR_LOGIC("unexpected null-pointer", name, info, "${info} has to be !=NULL")
    #define SPRX_ERROR_RANGE(name, info, care) SPRX_ERROR_LOGIC("out of range", name, info, care)
    #define SPRX_ERROR_ENUM(name, info, care) SPRX_ERROR_LOGIC("invalid enum value", name, info, care)

#endif // ___SPRX___ERROR_H
