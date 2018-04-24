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
#include "BATB/Run/KeySet.hpp"


namespace batb
{


namespace run
{

KeySet::KeySet(BATB* b) : keys::KeySet( b->keys.get() ), batb( b )
{

}

void KeySet::load(YAML::Node& keyset)
{
    // TODO: release current pointers back to Keys!

    batb->log << "console:    ";
    if ( auto key = createKey( keyset["console"] ) ) console = createKeyClicker( key );
    batb->log << "" << std::endl;

    batb->log << "escape:     ";
    if ( auto key = createKey( keyset["escape"] ) ) escape = createKeyClicker( key );
    batb->log << "" << std::endl;

    batb->log << "fullscreen: ";
    if ( auto key = createKey( keyset["fullscreen"] ) ) fullscreen = createKeyClicker( key );
    batb->log << "" << std::endl;



}


void KeySet::reset()
{
    console->reset();
    escape->reset();
}

} // namespace run

} // namespace batb

