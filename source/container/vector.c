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

#include "sprx/container/vector.h"
#include "sprx/core/assert.h"
#include "sprx/core/core.h"

#include <memory.h>
#include <string.h>

#define SPRX_VECTOR_ERROR_ALLOCATION SPRX_ERROR_ALLOCATION("vector", NULL, NULL)
#define SPRX_VECTOR_ERROR_OVERFLOW SPRX_ERROR_OVERFLOW("vector", "exceeded maximal capacity", "dont exceed a capacity of SIZE_MAX")
#define SPRX_VECTOR_ERROR_UNDERFLOW SPRX_ERROR_UNDERFLOW("vector", "exceeded minimal capacity", "dont undercut a capacity of 0")
#define SPRX_VECTOR_ERROR_ARGUMENT(care) SPRX_ERROR_ARGUMENT("vector", NULL, care)
#define SPRX_VECTOR_ERROR_NULL(info) SPRX_ERROR_NULL("vector", info)

typedef struct SPRX_Vector_PRVATE
{
    size_t element_size;
    size_t capacity;
    size_t size;
    char* data;
} SPRX_Vector_PRVATE;

void* spore_vector_new(const size_t elements_size_)
{
    SPRX_ASSERT(elements_size_ > 0, SPRX_VECTOR_ERROR_ARGUMENT("element_size has to be >0"));

    SPRX_Vector_PRVATE* const vector = malloc(sizeof(*vector));
    SPRX_ASSERT(NULL != vector, SPRX_ERROR_ALLOCATION);

    vector->element_size = elements_size_;
    vector->capacity = 0;
    vector->size = 0;
    vector->data = NULL;

    return vector;
}

void* spore_vector_new_c(const size_t elements_size_, const size_t capacity_)
{
    SPRX_ASSERT(elements_size_ > 0, SPRX_VECTOR_ERROR_ARGUMENT("element_size has to be >0"));

    SPRX_Vector_PRVATE* const vector = malloc(sizeof(*vector));
    SPRX_ASSERT(NULL != vector, SPRX_VECTOR_ERROR_ALLOCATION);

    vector->element_size = elements_size_;
    vector->capacity = capacity_;
    vector->size = 0;

    if (vector->capacity > 0)
    {
        vector->data = malloc(vector->element_size * vector->capacity);
        SPRX_ASSERT(NULL != vector, SPRX_VECTOR_ERROR_ALLOCATION);
    }
    else
    {
        vector->data = NULL;
    }

    return vector;
}

void* spore_vector_new_s(const size_t elements_size_, const size_t capacity_, const size_t size_)
{
    SPRX_ASSERT(elements_size_ > 0, SPRX_VECTOR_ERROR_ARGUMENT("element_size has to be >0"));
    SPRX_ASSERT(capacity_ >= size_, SPRX_VECTOR_ERROR_ARGUMENT("capacity has to be >size"));

    SPRX_Vector_PRVATE* const vector = malloc(sizeof(*vector));
    SPRX_ASSERT(NULL != vector, SPRX_VECTOR_ERROR_ALLOCATION);

    vector->element_size = elements_size_;
    vector->capacity = capacity_;
    vector->size = size_;

    if (vector->capacity > 0)
    {
        vector->data = malloc(vector->element_size * vector->capacity);
        SPRX_ASSERT(NULL != vector, SPRX_VECTOR_ERROR_ALLOCATION);
    }
    else
    {
        vector->data = NULL;
    }

    return vector;
}

void spore_vector_delete(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->capacity > 0)
    {
        free(vector->data);
    }

    free(vector);
}

void* spore_vector_at(void* const vector_, const size_t index_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(index_ < vector->size, SPRX_VECTOR_ERROR_ARGUMENT("index has to be <size"));

    return vector->data + (vector->element_size * index_);
}

void* spore_vector_front(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->size > 0)
    {
        return vector->data;
    }
    else
    {
        return NULL;
    }
}

void* spore_vector_back(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->size > 0)
    {
        return vector->data + (vector->element_size * (vector->size - 1));
    }
    else
    {
        return NULL;
    }
}

void* spore_vector_data(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector<"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->size > 0)
    {
        return vector->data;
    }
    else
    {
        return NULL;
    }
}

void spore_vector_push_front(void* const vector_, void* const element_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != element_, SPRX_VECTOR_ERROR_NULL("element"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }

        memmove(vector->data + vector->element_size, vector->data, vector->element_size * (vector->size - 1));
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    memcpy(vector->data, element_, vector->element_size);
}

void spore_vector_push_back(void* const vector_, void* const element_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != element_, SPRX_VECTOR_ERROR_NULL("element"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    memcpy(vector->data + (vector->element_size * (vector->size - 1)), element_, vector->element_size);
}

void spore_vector_pop_front(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size > 0, SPRX_VECTOR_ERROR_UNDERFLOW);

    vector->size--;

    memmove(vector->data, vector->data + vector->element_size, vector->element_size * vector->size);
}

void spore_vector_pop_back(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size > 0, SPRX_VECTOR_ERROR_UNDERFLOW);

    vector->size--;
}

void spore_vector_insert(void* const vector_, const size_t index_, void* const element_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("element"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);
    SPRX_ASSERT(index_ < vector->size, SPRX_VECTOR_ERROR_ARGUMENT("index has to be <size"));

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }

        memmove(vector->data + (vector->element_size * (index_ + 1)), vector->data + (vector->element_size * index_), vector->element_size * (vector->size - index_ - 1));
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    memcpy(vector->data + (vector->element_size * index_), element_, vector->element_size);
}

void spore_vector_erase(void* const vector_, const size_t index_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size > 0, SPRX_VECTOR_ERROR_UNDERFLOW);
    SPRX_ASSERT(index_ < vector->size, SPRX_VECTOR_ERROR_ARGUMENT("index has to be <size"));

    vector->size--;

    if (vector->size > 0)
    {
        if (index_ < vector->size)
        {
            memmove(vector->data + (vector->element_size * index_), vector->data + (vector->element_size * (index_ + 1)), vector->element_size * (vector->size - index_));
        }
    }
}

void spore_vector_emplace_front(void* const vector_, void(* const func_)(void* const dest, void* const arg), void* const arg_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("func"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }

        memmove(vector->data + vector->element_size, vector->data, vector->element_size * (vector->size - 1));
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    func_(vector->data, arg_);
}

void spore_vector_emplace_back(void* const vector_, void(* const func_)(void* const dest, void* const arg), void* const arg_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("func"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    func_(vector->data + (vector->element_size * (vector->size - 1)), arg_);
}

void spore_vector_emplace(void* const vector_, const size_t index_, void(* const func_)(void* const dest, void* const arg), void* const arg_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("func"));

    SPRX_Vector_PRVATE* const vector = vector_;

    SPRX_ASSERT(vector->size < SIZE_MAX, SPRX_VECTOR_ERROR_OVERFLOW);
    SPRX_ASSERT(index_ < vector->size, SPRX_VECTOR_ERROR_ARGUMENT("index has to be <size"));

    vector->size++;

    if (vector->capacity > 0)
    {
        if (vector->size > vector->capacity)
        {
            vector->capacity++;

            void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }

        memmove(vector->data + (vector->element_size * (index_ + 1)), vector->data + (vector->element_size * index_), vector->element_size * (vector->size - 1));
    }
    else
    {
        vector->capacity++;

        vector->data = malloc(vector->element_size);
        SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
    }

    func_(vector->data + (vector->element_size * index_), arg_);
}

size_t spore_vector_capacity(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    return vector->capacity;
}

void spore_vector_reserve(void* const vector_, const size_t capacity_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->capacity > 0)
    {
        if (capacity_ > 0)
        {
            void* const temp = realloc(vector->data, vector->element_size * capacity_);
            SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

            vector->data = temp;
        }
        else
        {
            free(vector->data);
        }

        vector->size = SPRX_MIN(vector->size, vector->capacity);
    }
    else
    {
        if (capacity_ > 0)
        {
            vector->data = malloc(vector->element_size * capacity_);
            SPRX_ASSERT(NULL != vector->data, SPRX_VECTOR_ERROR_ALLOCATION);
        }
    }

    vector->capacity = capacity_;
}

void spore_vector_shrink_to_fit(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    if (vector->capacity > vector->size)
    {
        vector->capacity = vector->size;

        void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
        SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

        vector->data = temp;
    }
}

size_t spore_vector_size(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    return vector->capacity;
}

void spore_vector_resize(void* const vector_, const size_t size_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    vector->size = size_;

    if (vector->size > vector->capacity)
    {
        vector->capacity = vector->size;

        void* const temp = realloc(vector->data, vector->element_size * vector->capacity);
        SPRX_ASSERT(NULL != temp, SPRX_VECTOR_ERROR_ALLOCATION);

        vector->data = temp;
    }
}

void spore_vector_clear(void* const vector_)
{
    SPRX_ASSERT(NULL != vector_, SPRX_VECTOR_ERROR_NULL("vector"));

    SPRX_Vector_PRVATE* const vector = vector_;

    vector->size = 0;
}
