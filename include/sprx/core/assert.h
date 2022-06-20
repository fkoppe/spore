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

#ifndef ___SPRX___ASSERT_H
#define ___SPRX___ASSERT_H

#include "sprx/core/error.h"
#include "sprx/core/essentials.h"

#include <stdarg.h>

#ifndef ___SFCX_NOASSERT
    #ifdef ___SFCX_DEBUG
        #define SPRX_ASSERT(condition, error) if(!(condition)) spore_assert(__FILE__, __func__, __LINE__, __DATE__, __TIME__, #condition, error)
    #else
        #define SPRX_ASSERT(condition, error) if(!(condition)) abort()
    #endif // ___SFCX_DEBUG
#else
    #define SPRX_ASSERT(condition, error)
#endif // !___SFCX_NOASSERT

void spore_assert(const char* const file, const char* const func, const int line, const char* const date, const char* const time, const char* const condition, const SPRX_Error* const error);

#endif // ___SPRX___ASSERT_H
