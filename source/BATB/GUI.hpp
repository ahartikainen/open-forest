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
#ifndef BATB_GUI_HPP
#define BATB_GUI_HPP
#include "BATB/ModuleBATB.hpp"
#include <GLFW/glfw3.h>

#include "tb/tb_system.h"
#include "tb/tb_language.h"
#include "tb/tb_bitmap_fragment.h"
#include "tb/animation/tb_widget_animation.h"
#include "tb/tb_node_tree.h"
#include "tb/tb_tempbuffer.h"
#include "tb/tb_font_renderer.h"
#include "tb/image/tb_image_manager.h"
#include "tb/utf8/utf8.h"
#include "tb/tb_renderer.h"
#include "tb/tb_widgets_reader.h"
#include "tb/renderers/tb_renderer_gl.h"
#include "tb/tb_msg.h"
#include "tb/tb_window.h"
#include "tb/tb_editfield.h"


namespace batb
{

class Scene;

namespace keys  { class Keys; }

namespace gui
{

////////////////////////////////////////////////////////////////////////////////
//


class GUI : public ModuleBATB
{
public:
    GUI(BATB* b) : ModuleBATB( b )        { }

    // setup
    void begin(const std::string& );
    void end();

    // output GUI
    void output(const Scene& );

    // step GUI
    void step(tick_t );

    // bind keys to this GUI object
    void bind(keys::Keys* );

    // ensure input only for GUI (except non-disable keys)
    void lockKeys(bool );

    // root TB widget
    tb::TBWidget root;

    void addWidget(tb::TBWidget* w);
    // add as top widget and keep it there until removed or new top
    void addWidgetTop(tb::TBWidget* w);
    void removeWidget(tb::TBWidget* w);


private:
    uint wth_ = 0;
    uint hth_ = 0;

    // TB
    tb::TBWidget* tb_top_ = nullptr;
    tb::TBRenderer* tb_renderer_ = nullptr;
    
    // callbacks
    static tb::TBWidget* callback_widget;

    static void glfw_callback_char(GLFWwindow *window, unsigned int character);
    static void glfw_callback_key(GLFWwindow *window, int key, int scancode, int action, int glfwmod);
    static void glfw_callback_mouse_button(GLFWwindow *window, int button, int action, int glfwmod);
    static void glfw_callback_cursor_pos(GLFWwindow *window, double x, double y);
    static void glfw_callback_scroll(GLFWwindow *window, double x, double y);
    static void glfw_callback_window_size(GLFWwindow *window, int w, int h);


};


} // namespace gui


} // namespace batb

#endif

