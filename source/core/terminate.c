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

#include "sprx/core/printf.h"
#include "sprx/core/terminate.h"

#include <assert.h>
#include <string.h>

void spore_quick_exit(const char* const file_, const char* const func_, const int64_t line_, const char* const date_, const char* const time_, const int64_t code_, const SPRX_Error* error_)
{
    assert(NULL != file_);
    assert(NULL != func_);
    assert(0 != line_);
    assert(NULL != date_);
    assert(NULL != time_);

    if (NULL == error_)
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nquick_exit has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n<no error information>\n\n-------------------------\n", file_, func_, line_, date_, time_);
    }
    else
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nquick_exit has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n", file_, func_, line_, date_, time_);

        if (NULL != error_->type && 0 == strcmp("", error_->type))
        {
            SPRX_PRINTF_ERROR("type:\t%s error\n", error_->type);
        }

        if (error_->evil)
        {
            SPRX_PRINT("evil:\ttrue\n");
        }
        else
        {
            SPRX_PRINT("evil:\tfalse\n");
        }

        if (NULL != error_->what && 0 != strcmp("", error_->what))
        {
            SPRX_PRINTF_ERROR("what:\t%s\n", error_->what);
        }

        if (NULL != error_->name && 0 != strcmp("", error_->name))
        {
            SPRX_PRINTF_ERROR("name:\t%s\n", error_->name);
        }

        if (NULL != error_->info && 0 != strcmp("", error_->info))
        {
            SPRX_PRINTF_ERROR("info:\t%s\n", error_->info);
        }

        if (NULL != error_->care && 0 != strcmp("", error_->care))
        {
            SPRX_PRINTF_ERROR("care:\t%s\n", error_->care);
        }

        SPRX_PRINT_ERROR("\n-------------------------\n");
    }

    quick_exit(code_);
}

void spore_exit(const char* const file_, const char* const func_, const int64_t line_, const char* const date_, const char* const time_, const int64_t code_, const SPRX_Error* const error_)
{
    assert(NULL != file_);
    assert(NULL != func_);
    assert(0 != line_);
    assert(NULL != date_);
    assert(NULL != time_);

    if (NULL == error_)
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nexit has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n<no error information>\n\n-------------------------\n", file_, func_, line_, date_, time_);
    }
    else
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nexit has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n", file_, func_, line_, date_, time_);

        if (NULL != error_->type)
        {
            SPRX_PRINTF_ERROR("type:\t%s error\n", error_->type);
        }

        if (error_->evil)
        {
            SPRX_PRINT("evil:\ttrue\n");
        }
        else
        {
            SPRX_PRINT("evil:\tfalse\n");
        }

        if (NULL != error_->what)
        {
            SPRX_PRINTF_ERROR("what:\t%s\n", error_->what);
        }

        if (NULL != error_->name)
        {
            SPRX_PRINTF_ERROR("name:\t%s\n", error_->name);
        }

        if (NULL != error_->info)
        {
            SPRX_PRINTF_ERROR("info:\t%s\n", error_->info);
        }

        if (NULL != error_->care)
        {
            SPRX_PRINTF_ERROR("care:\t%s\n", error_->care);
        }

        SPRX_PRINT_ERROR("\n-------------------------\n");
    }

    exit(code_);
}

void spore_abort(const char* const file_, const char* const func_, const int64_t line_, const char* const date_, const char* const time_, const SPRX_Error* const error_)
{
    assert(NULL != file_);
    assert(NULL != func_);
    assert(0 != line_);
    assert(NULL != date_);
    assert(NULL != time_);

    if (NULL == error_)
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nabort has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n<no error information>\n\n-------------------------\n", file_, func_, line_, date_, time_);
    }
    else
    {
        SPRX_PRINTF_ERROR("-------------------------\n\nabort has been called\n\nfile:\t%s\nfunc:\t%s\nline:\t%lli\ndate:\t%s\ntime:\t%s\n\n", file_, func_, line_, date_, time_);

        if (NULL != error_->type)
        {
            SPRX_PRINTF_ERROR("type:\t%s error\n", error_->type);
        }

        if (error_->evil)
        {
            SPRX_PRINT("evil:\ttrue\n");
        }
        else
        {
            SPRX_PRINT("evil:\tfalse\n");
        }

        if (NULL != error_->what)
        {
            SPRX_PRINTF_ERROR("what:\t%s\n", error_->what);
        }

        if (NULL != error_->name)
        {
            SPRX_PRINTF_ERROR("name:\t%s\n", error_->name);
        }

        if (NULL != error_->info)
        {
            SPRX_PRINTF_ERROR("info:\t%s\n", error_->info);
        }

        if (NULL != error_->care)
        {
            SPRX_PRINTF_ERROR("care:\t%s\n", error_->care);
        }

        SPRX_PRINT_ERROR("\n-------------------------\n");
    }

    abort();
}
