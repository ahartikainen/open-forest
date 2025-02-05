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
#ifndef BATB_FOREST_ITERATION_ITERATIONFOREST_HPP
#define BATB_FOREST_ITERATION_ITERATIONFOREST_HPP
#include "BATB/Forest/World.hpp"
#include "game.hpp"

namespace batb
{


class BATB;



namespace forest
{

// the type of stack for forest::Iteration
using IterationStack = game::IterationStack<World>;


// the type of iterations for forest::World
class IterationForest
{
public:
    IterationForest(BATB* b);

    // this handles each frame, delegating work to the subclass 
    // implementation of 'iterate_forest'
    virtual IterationStack iterate(World& ) final;

    // also, each subclass should typically create a non-virtual method:
    // void iterate_begin(World& );

    BATB* batb;

protected:
    // subclasses implements this:
    virtual IterationStack iterate_forest(World& ) = 0;


};

}

}

#endif
