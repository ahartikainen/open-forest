// 
// this file overrides turbobadger tb_config.h
// 
// here, we configure turbobadger according to BATB needs
//
// 
// 
// 
// 
#ifndef TB_CONFIG_H
#define TB_CONFIG_H

/** Enable for some handy runtime debugging, enabled by modifying
	the various settings in g_tb_debug. A settings window can be
	shown by calling ShowDebugInfoSettingsWindow. */
#ifndef NDEBUG
//#define TB_RUNTIME_DEBUG_INFO
#endif

#ifndef NDEBUG
/** Enable compilation of unit tests. */
//#define TB_UNIT_TESTING
#endif

/** Enable if the focus state should automatically be set on edit fields even
	when using the pointer. It is normally set only while moving focus by keyboard. */
//#define TB_ALWAYS_SHOW_EDIT_FOCUS

/** Enable to use premultiplied alpha. Warning: This is not handled everywhere in
	the default backends, so consider it an experimental and unfinished feature! */
//#define TB_PREMULTIPLIED_ALPHA

/** Enable to support TBBF fonts (Turbo Badger Bitmap Fonts) */
#define TB_FONT_RENDERER_TBBF

/** Enable to support truetype fonts using freetype. */
//#define TB_FONT_RENDERER_FREETYPE

/** Enable to support truetype fonts using stb_truetype.h (http://nothings.org/).
	It's a *very unsafe* font library. Use only with fonts distributed with your
	app, that you know work! Freetype generates much prettier glyphs (using
	hinting) but is a lot larger. This implementation is kept here as alternative
	as long as it compiles. */
//#define TB_FONT_RENDERER_STB

/** Enable to support image loading using stb_image.c (http://nothings.org/).
	It's a *very unsafe* image library. Use only with images distributed with
	your app, that you know work! */
#define TB_IMAGE_LOADER_STB

/** Enable to get TBRendererBatcher, an helper class for renderers that
	implements batching of draw operations. Subclasses of TBRendererBatcher
	can be done super easily, and still do batching. */
#define TB_RENDERER_BATCHER

/** Enable renderer using OpenGL. This renderer depends on TB_RENDERER_BATCHER.
	It is using GL version 1.1, */
//#define TB_RENDERER_GL
// use custom renderer with GL3.2 support (and GL ES), defined in open-forest source,
// and taken & modified from here: https://github.com/tesch1/turbobadger/blob/50859e14bd8c923be65ccc8dfab237d30af19a23/src/tb/renderers/tb_renderer_gl.cpp
#define TB_RENDERER_GL_PLUS
#ifdef TB_RENDERER_GL_PLUS
#define TB_RENDERER_GL3 // desktop (OpenGL GL3+, not OpenGL ES)
#endif


/** Enable renderer using OpenGL ES. This renderer depends on TB_RENDERER_GL.
	It is using GL ES version 1. */
//#define TB_RENDERER_GLES_1

/** The width of the font glyph cache. Must be a power of two. */
#define TB_GLYPH_CACHE_WIDTH 512

/** The height of the font glyph cache. Must be a power of two. */
#define TB_GLYPH_CACHE_HEIGHT 512

// == Optional features ===========================================================

/** Enable support for TBImage, TBImageManager, TBImageWidget. */
#define TB_IMAGE

// == Additional configuration of platform implementations ========================

/** Defines for implementations of TBClipboard. */
// in BATB, there is currently no clipboard
//#define TB_CLIPBOARD_DUMMY // Cross platform. Not integrating with the OS.
//#define TB_CLIPBOARD_GLFW // Cross platform using glfw API.
//#define TB_CLIPBOARD_WINDOWS

/** Defines for implementations of TBSystem. */
// in BATB, we have our own implementation of TBSystem!
//#define TB_SYSTEM_LINUX
//#define TB_SYSTEM_WINDOWS
//#define TB_SYSTEM_ANDROID

/** Defines for additional platform specific issues. */
// NOTE: currently only used in tb_style_edit.cpp
//#define TB_TARGET_WINDOWS
//#define TB_TARGET_MACOSX
//#define TB_TARGET_LINUX

// == Setting some defaults for platform implementations ==========================
// in BATB, no platform implementations are used (we have our own!)

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
//#define TB_FILE_POSIX
//#define TB_TARGET_WINDOWS
//#define TB_CLIPBOARD_WINDOWS
//#define TB_SYSTEM_WINDOWS
#endif

#if defined(__linux) || defined(__linux__)
//#define TB_FILE_POSIX
//#define TB_TARGET_LINUX
//#define TB_SYSTEM_LINUX
//#define TB_CLIPBOARD_GLFW
#endif

#ifdef MACOSX
//#define TB_FILE_POSIX
//#define TB_TARGET_MACOSX
//#define TB_SYSTEM_LINUX
//#define TB_CLIPBOARD_GLFW
#endif

#if defined(ANDROID) || defined(__ANDROID__)
//#define TB_SYSTEM_ANDROID
//#define TB_CLIPBOARD_DUMMY
#endif

#endif // TB_CONFIG_H
