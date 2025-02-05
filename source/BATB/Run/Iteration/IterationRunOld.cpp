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
#include "BATB/old/old.hpp"
#include "BATB/Run.hpp"
#include "BATB/Run/Iteration.hpp"
#include "BATB/Run/Notify.hpp"

namespace batb
{

namespace run
{


IterationRunOld::IterationRunOld(BATB* b) : IterationRun( b )
{

}

////////////////////////////////////////////////////////////////////////////////
//

void IterationRunOld::begin()
{
}

void IterationRunOld::end()
{
    
}


void IterationRunOld::iterate_begin(World& world)
{
#ifdef BATB_BUILD_OLD
    old::begin();
#else
    // notify message
    std::ostringstream msg; msg << "feature not in build: BATB_BUILD_OLD";
    batb->run->notify->message( msg.str(), 3.0 );

    batb->log << "could not start old: code is not built into open-forest (BATB_BUILD_OLD)" << std::endl;
#endif

}


IterationStack IterationRunOld::iterate_run(World& world)
{
#ifdef BATB_BUILD_OLD
    if ( old::is_exit() )
    {
        old::end();
        return _emptylist_;
    }
    else
    {
        // do
        old::iterate();

        // think
        if ( batb.run.keyset.escape->released() )
        {
            batb << "IterationRunOld -> " << std::endl;
            old::end();

            return _emptylist_;
        }
        else
        {
            return { this };
        }
    }
#else
    return _emptylist_;
#endif




}



} // namespace run

} // namespace batb









