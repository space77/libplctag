/***************************************************************************
 *   Copyright (C) 2024 by Kyle Hayes                                      *
 *   Author Kyle Hayes  kyle.hayes@gmail.com                               *
 *                                                                         *
 * This software is available under either the Mozilla Public License      *
 * version 2.0 or the GNU LGPL version 2 (or later) license, whichever     *
 * you choose.                                                             *
 *                                                                         *
 * MPL 2.0:                                                                *
 *                                                                         *
 *   This Source Code Form is subject to the terms of the Mozilla Public   *
 *   License, v. 2.0. If a copy of the MPL was not distributed with this   *
 *   file, You can obtain one at http://mozilla.org/MPL/2.0/.              *
 *                                                                         *
 *                                                                         *
 * LGPL 2:                                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#pragma once

#include <omron/defs.h>
#include <lib/libplctag.h>
#include <lib/tag.h>
#include <util/vector.h>

typedef struct omron_tag_t *omron_tag_p;
#define OMRON_TAG_NULL ((omron_tag_p)NULL)

typedef struct omron_conn_t *omron_conn_p;
#define OMRON_CONN_NULL ((omron_conn_p)NULL)

typedef struct omron_request_t *omron_request_p;
#define OMRON_REQUEST_NULL ((omron_request_p)NULL)


extern int omron_tag_abort(omron_tag_p tag);
extern int omron_tag_status(omron_tag_p tag);


extern int omron_get_int_attrib(plc_tag_p tag, const char *attrib_name, int default_value);
extern int omron_set_int_attrib(plc_tag_p tag, const char *attrib_name, int new_value);

extern int omron_get_byte_array_attrib(plc_tag_p tag, const char *attrib_name, uint8_t *buffer, int buffer_length);

// extern int omron_get_bit(plc_tag_p tag, int offset_bit);
// extern int omron_set_bit(plc_tag_p tag, int offset_bit, int val);

// extern uint64_t omron_get_uint64(plc_tag_p tag, int offset);
// extern int omron_set_uint64(plc_tag_p tag, int offset, uint64_t val);

// extern int64_t omron_get_int64(plc_tag_p tag, int offset);
// extern int omron_set_int64(plc_tag_p tag, int offset, int64_t val);


// extern uint32_t omron_get_uint32(plc_tag_p tag, int offset);
// extern int omron_set_uint32(plc_tag_p tag, int offset, uint32_t val);

// extern int32_t omron_get_int32(plc_tag_p tag, int offset);
// extern int omron_set_int32(plc_tag_p tag, int offset, int32_t val);


// extern uint16_t omron_get_uint16(plc_tag_p tag, int offset);
// extern int omron_set_uint16(plc_tag_p tag, int offset, uint16_t val);

// extern int16_t omron_get_int16(plc_tag_p tag, int offset);
// extern int omron_set_int16(plc_tag_p tag, int offset, int16_t val);


// extern uint8_t omron_get_uint8(plc_tag_p tag, int offset);
// extern int omron_set_uint8(plc_tag_p tag, int offset, uint8_t val);

// extern int8_t omron_get_int8(plc_tag_p tag, int offset);
// extern int omron_set_int8(plc_tag_p tag, int offset, int8_t val);


// extern double omron_get_float64(plc_tag_p tag, int offset);
// extern int omron_set_float64(plc_tag_p tag, int offset, double val);

// extern float omron_get_float32(plc_tag_p tag, int offset);
// extern int omron_set_float32(plc_tag_p tag, int offset, float val);


//int omron_tag_destroy(omron_tag_p p_tag);
// extern plc_type_t get_plc_type(attr attribs);
// extern int check_cpu(omron_tag_p tag, attr attribs);
// extern int check_tag_name(omron_tag_p tag, const char *name);
// extern int check_mutex(int debug);
// extern vector_p find_read_group_tags(omron_tag_p tag);

THREAD_FUNC(request_handler_func);

/* helpers for checking request status. */
extern int omron_check_read_reqest_status(omron_tag_p tag, omron_request_p request);
extern int omron_check_write_request_status(omron_tag_p tag, omron_request_p request);

#define rc_is_error(rc) (rc < PLCTAG_STATUS_OK)
