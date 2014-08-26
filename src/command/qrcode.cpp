/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include <sx/command/qrcode.hpp>

#include <iostream>
#include <sx/define.hpp>

using namespace sx;
using namespace sx::extension;

console_result qrcode::invoke(std::ostream& output, std::ostream& error)
{
    // Bound parameters.
    const auto& path = get_file_option();
    const auto& address = get_bitcoin_address_argument();

    // TODO:
    // Create qrcode as binary data.
    //const auto qrcode = 42;

    //if (path.empty() || path == SX_STDIO_PATH_SENTINEL)
    //    output << qrcode;
    //else
    //{
    //    std::ofstream outfile(path, std::ofstream::binary);
    //    outfile << qrcode;
    //}

    error << SX_QRCODE_NOT_IMPLEMENTED << std::endl;
    return console_result::failure;
}

//#!/bin/bash
//if [ $# -ne 2 ]; then
//    echo "Usage: qrcode ADDRESS FILENAME"
//    exit 1
//fi
//command -v qrencode >/dev/null 2>&1 || { echo >&2 "Please install 'qrencode'."; exit 1; }
//ADDR=$1
//FILE=$2
//qrencode bitcoin:$ADDR -o $FILE -s 10
//