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

#ifndef ___SPRX___TERMINATE_H
#define ___SPRX___TERMINATE_H

#include "sprx/core/error.h"
#include "sprx/core/essentials.h"

#ifdef ___SPRX_DEBUG
    #define SPRX_QUICK_EXIT(code) spore_quick_exit(__FILE__, __func__, __LINE__, __DATE__, __TIME__, code, SPRX_ERROR_UNDEFINED(NULL, NULL, NULL))
    #define SPRX_EXIT(code) spore_exit(__FILE__, __func__, __LINE__, __DATE__, __TIME__, code, SPRX_ERROR_UNDEFINED(NULL, NULL, NULL))
    #define SPRX_ABORT spore_abort(__FILE__, __func__, __LINE__, __DATE__, __TIME__, SPRX_ERROR_UNDEFINED(NULL, NULL, NULL))
    #define SPRX_QUICK_EXIT_ERROR(code, error) spore_quick_exit(__FILE__, __func__, __LINE__, __DATE__, __TIME__, code, error)
    #define SPRX_EXIT_ERROR(code, error) spore_exit(__FILE__, __func__, __LINE__, __DATE__, __TIME__, code, error)
    #define SPRX_ABORT_ERROR(error) spore_abort(__FILE__, __func__, __LINE__, __DATE__, __TIME__, error)
#else
    #define SPRX_QUICK_EXIT(code) quick_exit(code)
    #define SPRX_EXIT(code) exit(code)
    #define SPRX_ABORT abort()
    #define SPRX_QUICK_EXIT_ERROR(code, error) quick_exit(code)
    #define SPRX_EXIT_ERROR(code, error) exit(code)
    #define SPRX_ABORT_ERROR(error) abort()
#endif // !___SPRX_DEBUG

void spore_quick_exit(const char* const file, const char* const func, const int64_t line, const char* const date, const char* const time, const int64_t code, const SPRX_Error* const error);
void spore_exit(const char* const file, const char* const func, const int64_t line, const char* const date, const char* const time, const int64_t code, const SPRX_Error* const error);
void spore_abort(const char* const file, const char* const func, const int64_t line, const char* const date, const char* const time, const SPRX_Error* const error);

#endif // ___SPRX___TERMINATE_H
