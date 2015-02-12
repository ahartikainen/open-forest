//    open-forest: an orienteering game.
//    Copyright (C) 2014  carljsv@student.matnat.uio.no
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
#include "batb/ogre/GLContextGLFW.hpp"

namespace batb
{

namespace ogre
{


void GLContextGLFW::setCurrent()
{
    //
    // TODO: other platforms...
#ifdef GLFW_EXPOSE_NATIVE_GLX
    ::Display* display = glfwGetX11Display();
    ::Window drawable = glfwGetX11Window( env::screen_window() );
    ::GLXContext context = glfwGetGLXContext( env::screen_window() );
    glXMakeCurrent( display, drawable, context );
#endif
    
}

void GLContextGLFW::endCurrent()
{
    // do nothing
}

Ogre::GLContext* GLContextGLFW::clone() const
{
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
//
void begin(GLContextGLFW& context)
{
    // see the line with _oneTimeContextInitialization();
    // inside void GLRenderSystem::_switchContext(GLContext *context)
    context.setInitialized();   
}


void end(GLContextGLFW& )
{

}


} // namespace ogre

} // namespace batb


