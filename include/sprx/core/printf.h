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

#ifndef ___SPRX___PRINTF_H
#define ___SPRX___PRINTF_H

#include "sprx/core/essentials.h"

#include <stdarg.h>

#ifdef ___SPRX_DEBUG
    #define SPRX_PRINT(data) spore_print(data)
    #define SPRX_PRINT_ERROR(data) spore_print_error(data)
    #define SPRX_PRINTF(...) spore_printf(__VA_ARGS__)
    #define SPRX_PRINTF_ERROR(...) spore_printf_error(__VA_ARGS__)
    #define SPRX_VPRINTF(format, args) spore_vprintf(format, args)
    #define SPRX_VPRINTF_ERROR(format, args) spore_vprintf_error(format, args)
#else
    #define SPRX_PRINT(data)
    #define SPRX_PRINT_ERROR(data)
    #define SPRX_PRINTF(...)
    #define SPRX_PRINTF_ERROR(...)
    #define SPRX_VPRINTF(format, args)
    #define SPRX_VPRINTF_ERROR(format, args)
#endif // !___SPRX_DEBUG

int spore_print(const char* const data);
int spore_print_error(const char* const data);
int spore_printf(const char* const format, ...);
int spore_printf_error(const char* const format, ...);
int spore_vprintf(const char* const format, const va_list args);
int spore_vprintf_error(const char* const format, const va_list args);

#endif // ___SPRX___PRINTF_H
