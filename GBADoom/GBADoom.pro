QT += gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

CONFIG += force_debug_info

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += RANGECHECK

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "include"

INCLUDEPATH += "C:\devkitPro\libgba\include"

SOURCES += \
        source/am_map.c \
        source/d_client.c \
        source/d_items.c \
        source/d_main.c \
        source/doom_iwad.c \
        source/f_finale.c \
        source/f_wipe.c \
        source/g_game.c \
        source/global_data.c \
        source/hu_lib.c \
        source/hu_stuff.c \
        source/i_audio.c \
        source/i_main.c \
        source/i_system.c \
        source/i_system_e32.cpp \
        source/i_system_gba.cpp \
        source/i_video.c \
        source/info.c \
        source/lprintf.c \
        source/m_bbox.c \
        source/m_cheat.c \
        source/m_menu.c \
        source/m_random.c \
        source/m_recip.c \
        source/p_ceilng.c \
        source/p_doors.c \
        source/p_enemy.c \
        source/p_floor.c \
        source/p_genlin.c \
        source/p_inter.c \
        source/p_lights.c \
        source/p_map.c \
        source/p_maputl.c \
        source/p_mobj.c \
        source/p_plats.c \
        source/p_pspr.c \
        source/p_setup.c \
        source/p_sight.c \
        source/p_spec.c \
        source/p_switch.c \
        source/p_telept.c \
        source/p_tick.c \
        source/p_user.c \
        source/r_data.c \
        source/r_draw.c \
        source/r_hotpath.iwram.c \
        source/r_main.c \
        source/r_patch.c \
        source/r_plane.c \
        source/r_things.c \
        source/s_sound.c \
        source/sounds.c \
        source/st_gfx.c \
        source/st_lib.c \
        source/st_stuff.c \
        source/tables.c \
        source/v_video.c \
        source/version.c \
        source/w_wad.c \
        source/wi_stuff.c \
        source/z_bmalloc.c \
        source/z_zone.c


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/am_map.h \
    include/config.h \
    include/d_englsh.h \
    include/d_event.h \
    include/d_items.h \
    include/d_main.h \
    include/d_net.h \
    include/d_player.h \
    include/d_think.h \
    include/d_ticcmd.h \
    include/doom_iwad.h \
    include/doomdata.h \
    include/doomdef.h \
    include/doomstat.h \
    include/doomtype.h \
    include/dstrings.h \
    include/f_finale.h \
    include/f_wipe.h \
    include/g_game.h \
    include/gba_functions.h \
    include/global_data.h \
    include/global_init.h \
    include/hu_lib.h \
    include/hu_stuff.h \
    include/i_main.h \
    include/i_network.h \
    include/i_sound.h \
    include/i_system.h \
    include/i_system_e32.h \
    include/i_system_win.h \
    include/i_video.h \
    include/info.h \
    include/lprintf.h \
    include/m_bbox.h \
    include/m_cheat.h \
    include/m_fixed.h \
    include/m_menu.h \
    include/m_misc.h \
    include/m_random.h \
    include/m_recip.h \
    include/m_swap.h \
    include/p_enemy.h \
    include/p_inter.h \
    include/p_map.h \
    include/p_maputl.h \
    include/p_mobj.h \
    include/p_pspr.h \
    include/p_setup.h \
    include/p_spec.h \
    include/p_tick.h \
    include/p_user.h \
    include/protocol.h \
    include/r_data.h \
    include/r_defs.h \
    include/r_draw.h \
    include/r_main.h \
    include/r_patch.h \
    include/r_plane.h \
    include/r_segs.h \
    include/r_sky.h \
    include/r_state.h \
    include/r_things.h \
    include/s_sound.h \
    include/sounds.h \
    include/st_gfx.h \
    include/st_lib.h \
    include/st_stuff.h \
    include/tables.h \
    include/v_video.h \
    include/version.h \
    include/w_wad.h \
    include/wi_stuff.h \
    include/z_bmalloc.h \
    include/z_zone.h

DISTFILES += \
    Makefile \
    source/fixeddiv.s


win32-msvc* {
#    LIBS += $$PWD/codeprophet.lib
#    QMAKE_CXXFLAGS += /GH /Gh
#    QMAKE_CFLAGS += /GH /Gh
     QMAKE_CFLAGS += /fsanitize=address
     QMAKE_CXXFLAGS += /fsanitize=address
}
