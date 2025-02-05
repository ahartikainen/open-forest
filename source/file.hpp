//    open-forest: an orientering game.
//    Copyright (C) 2018  karamellpelle@hotmail.com
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#ifndef FILE_HPP
#define FILE_HPP
#include "include.hpp"

namespace file
{



// full path to read-only application data
// example: image, 
std::string static_data(const std::string& path);

// full path to read-write application data
// example: configuration file, 
std::string dynamic_data(const std::string& path);

// full path to user files (reachable outside application)
// example: screenshot, 
std::string user(const std::string& path);

// full path to temporary files (files that can be removed after application)
// example: log file, 
std::string tmp(const std::string& path);


////////////////////////////////////////////////////////////////////////////////
// working with files

// get containing directory of path
// this is typically used for files, not directories
// if path is a directory, then the path should typically
// not have a trailing slash, otherwise the path will be 
// regarded as a path to a file with empty filename. for
// example:
//    /a/b/c    => /a/b         
//    /a/b/c/   => /a/b/c     (empty file in the c directory)
//
// INVARIANT: paths to directories shall not have a trailing 
//            slash.
std::string directory(const std::string& path);



} // namespace file

#endif
