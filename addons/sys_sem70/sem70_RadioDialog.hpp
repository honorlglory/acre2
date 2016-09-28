#include "script_component.hpp"

#define CODE_SPACING    0.0245

#define CONTROL_SetRelativePos(xpos,ypos) x = H_OFFSET + (xpos * 0.001); y = H_OFFSET + (ypos * 0.001);
#define CONTROL_SetDimensions(width, height) w = width * 0.001; h = height * 0.001;

#define BEGIN_CONTROL(name, parent, idval) class name : parent { idc = idval;
#define END_CONTROL        };

#define NEW_SCALE 1.8963
#define SCALE (NEW_SCALE*1.8963)


class SEM70_RadioDialog {
    idd = 31532;
    MovingEnable = 0;
    onUnload = QUOTE(['closeGui'] call GUI_INTERACT_EVENT);
    onLoad = QUOTE(_this call FUNC(render));
    controlsBackground[] = {/*SEM70Background*/};
    objects[] = {};
    /*class SEM70Background
    {
        type = CT_STATIC;
        idc = 99999;
        style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = FontM;
        sizeEx = 0.04;

        x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
        y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
        w=NEW_SCALE * SafeZoneH;
        h=NEW_SCALE * SafeZoneH;

        text = QUOTE(PATHTOF(data\ui\sem70ui_ca.paa));
    };*/
    class controls {

        BEGIN_CONTROL(RadioBackground, SEM70_RscPicture, 300)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(data\ui\sem70ui_ca.paa));
        END_CONTROL

        BEGIN_CONTROL(Backlight, SEM70_RscPicture, 109)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL

        BEGIN_CONTROL(Display1, SEM70_RscPicture, 301)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL

        BEGIN_CONTROL(Display2, SEM70_RscPicture, 302)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL

        BEGIN_CONTROL(Display3, SEM70_RscPicture, 303)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL

        BEGIN_CONTROL(Display4, SEM70_RscPicture, 304)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL

        BEGIN_CONTROL(Display5, SEM70_RscPicture, 305)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = "";
        END_CONTROL


        BEGIN_CONTROL(VolumeKnob, SEM70_RscPicture, 106)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(data\knobs\volume\vol_100.paa));
        END_CONTROL

        BEGIN_CONTROL(MainKnob, SEM70_RscPicture, 107)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(Data\knobs\main\lstg_gr.paa));
        END_CONTROL

        BEGIN_CONTROL(FunctionKnob, SEM70_RscPicture, 108)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(Data\knobs\function\bs_hw.paa));
        END_CONTROL

        BEGIN_CONTROL(ChannelStepKnob, SEM70_RscPicture, 109)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(Data\knobs\cs\ka_25mhz.paa));
        END_CONTROL

        BEGIN_CONTROL(khzKnob, SEM70_RscPicture, 110)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(Data\knobs\khz\khz_0.paa));
        END_CONTROL

        BEGIN_CONTROL(mhzKnob, SEM70_RscPicture, 111)
            x=safeZoneX + safeZoneW - NEW_SCALE * SafeZoneH - 1/16 * safeZoneW;
            y=SafeZoneY + SafeZoneH - NEW_SCALE * SafeZoneH + 2/8 * safeZoneW;
            w=NEW_SCALE * SafeZoneH;
            h=NEW_SCALE * SafeZoneH;
            text = QUOTE(PATHTOF(Data\knobs\mhz\mhz_0.paa));
        END_CONTROL
        // Do the buttons last so they come on top.
        BEGIN_CONTROL(VolumeButton, SEM70_RscButton, 201)
            x=((((0.416-0.543)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            y=((((0.595-0.5)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            w=(1.15/0.8)*0.050*SafeZoneH;
            h=(1.15/0.8)*0.050*SafeZoneH;
            colorBackground[] = {1, 0, 0, 1};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onChannelKnobPress));
            toolTip = QUOTE(Change channel);
        END_CONTROL

        BEGIN_CONTROL(MainButton, SEM70_RscButton, 202)
            x=(((((0.416+0.087)-0.5)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            y=((((0.595-0.5)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            w=(1.15/0.8)*0.050*SafeZoneH;
            h=(1.15/0.8)*0.050*SafeZoneH;
            colorBackground[] = {0, 1, 0, 1};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onVolumeKnobPress));
            toolTip = QUOTE(Change volume);
        END_CONTROL

        BEGIN_CONTROL(FunctionButton, SEM70_RscButton, 203)
            x=((((0.416-0.487)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            y=((((0.595-0.5)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            w=(1.15/0.8)*0.050*SafeZoneH * 4/3;
            h=(1.15/0.8)*0.050*SafeZoneH;
            colorBackground[] = {0, 0, 1, 1};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onPTTButtonPress));
            toolTip = QUOTE(PTT);
        END_CONTROL

        BEGIN_CONTROL(ChannelStepButton, SEM70_RscButton, 204)
            x=((((0.416-0.615)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            y=((((0.595-0.6)*(1.15/0.8))+0.5) * SafeZoneH) + SafeZoneY;
            w=(1.15/0.8)*0.050*SafeZoneH * 4/3;
            h=(1.15/0.8)*0.050*SafeZoneH;
            colorBackground[] = {1, 0, 1, 1};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onAudioSocketPress));
            toolTip = QUOTE(Plug/Unplug headset);
        END_CONTROL

    };
};

//class RscTitles
//{
//    class GVAR(volumeKnobPicture)
//    {
//        idd = 19008;
//        MovingEnable = 0;
//        name = QUOTE(GVAR(volumeKnobPicture));
//        duration = 2;
//        fadein = 0;
//        onLoad = QUOTE([(_this select 0)] call FUNC(_showVolumeKnob));
//        class controls
//        {
//            BEGIN_CONTROL(volumeKnobPictureControl, SEM70_RscPicture, 1071)
//                x = (((((0.416+0.057)-0.5)*SCALE)+0.5) * SafeZoneH) + SafeZoneY;
//                y = ((((0.15-0.5)*SCALE)+0.5) * SafeZoneH) + SafeZoneY;
//                w = SCALE*0.1*SafeZoneH;
//                h = SCALE*0.1*SafeZoneH;
//                text = QUOTE(PATHTOF(Data\knobs\volume\vol_0000.paa));
//                colorText[]= {1,1,1,1};
//            END_CONTROL
//        };
//    };
//};