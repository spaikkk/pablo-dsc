#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include "frozen/unordered_map.h"
#include "frozen/string.h"
#include <windows.h>
#include <commdlg.h>
#include <vector>
#include <algorithm>

struct opStruct {
    frozen::string command;
    int len;
};

struct code_param{
    int opcode;
    int len;
};



//107 elementi
constexpr frozen::unordered_map<int, opStruct, 107> db = {
    {99, {frozen::string("TOON"), 3}},
    {98, {frozen::string("MAN_CAP"), 1}},
    {97, {frozen::string("AOTO_CAP"), 1}},
    {96, {frozen::string("CHARA_ALPHA"), 4}},
    {95, {frozen::string("DOF"), 3}},
    {94, {frozen::string("COLOR_COLLE"), 3}},
    {93, {frozen::string("BLOOM"), 2}},
    {92, {frozen::string("FOG"), 3}},
    {91, {frozen::string("EDIT_MOTION_F"), 6}},
    {90, {frozen::string("SHADOW_CAST"), 2}},
    {9, {frozen::string("EFFECT"), 6}},
    {89, {frozen::string("FACE_TYPE"), 1}},
    {88, {frozen::string("LIGHT_POS"), 4}},
    {87, {frozen::string("HAND_SCALE"), 3}},
    {86, {frozen::string("SHADOW_RANGE"), 1}},
    {85, {frozen::string("ITEM_ANIM_ATTACH"), 3}},
    {84, {frozen::string("TARGET_FLAG"), 1}},
    {83, {frozen::string("PV_END_FADEOUT"), 2}},
    {82, {frozen::string("EDIT_MODE_SELECT"), 1}},
    {81, {frozen::string("EDIT_CAMERA"), 24}},
    {80, {frozen::string("EDIT_MOUTH_ANIM"), 2}},
    {8, {frozen::string("SET_PLAYDATA"), 2}},
    {79, {frozen::string("EDIT_EYE_ANIM"), 3}},
    {78, {frozen::string("EDIT_EXPRESSION"), 2}},
    {77, {frozen::string("EDIT_MOTION_LOOP"), 4}},
    {76, {frozen::string("EDIT_INSTRUMENT_ITEM"), 2}},
    {75, {frozen::string("EDIT_EYELID_ANIM"), 3}},
    {74, {frozen::string("EDIT_MOVE_XYZ"), 9}},
    {73, {frozen::string("SE_EFFECT"), 1}},
    {72, {frozen::string("CHARA_COLOR"), 2}},
    {71, {frozen::string("OSAGE_MV_CCL"), 3}},
    {70, {frozen::string("OSAGE_STEP"), 3}},
    {7, {frozen::string("SET_MOTION"), 4}},
    {69, {frozen::string("WIND"), 3}},
    {68, {frozen::string("MOVIE_DISP"), 1}},
    {67, {frozen::string("MOVIE_PLAY"), 1}},
    {66, {frozen::string("DATA_CAMERA_START"), 2}},
    {65, {frozen::string("PV_BRANCH_MODE"), 1}},
    {64, {frozen::string("EDIT_MOT_SMOOTH_LEN"), 2}},
    {63, {frozen::string("SCENE_ROT"), 1}},
    {62, {frozen::string("CHARA_POS_ADJUST"), 4}},
    {61, {frozen::string("ITEM_ANIM"), 4}},
    {60, {frozen::string("CHARA_HEIGHT_ADJUST"), 2}},
    {6, {frozen::string("TARGET"), 7}},
    {59, {frozen::string("CHARA_SIZE"), 2}},
    {58, {frozen::string("TARGET_FLYING_TIME"), 1}},
    {57, {frozen::string("PARTS_DISP"), 3}},
    {56, {frozen::string("AUTO_BLINK"), 2}},
    {28, {frozen::string("BAR_TIME_SET"), 2}},
    {27, {frozen::string("EDIT_MOTION"), 4}},
    {26, {frozen::string("MODE_SELECT"), 2}},
    {25, {frozen::string("MUSIC_PLAY"), 0}},
    {24, {frozen::string("LYRIC"), 2}},
    {23, {frozen::string("LOOK_CAMERA"), 5}},
    {22, {frozen::string("EXPRESSION"), 4}},
    {21, {frozen::string("LOOK_ANIM"), 4}},
    {20, {frozen::string("HAND_ANIM"), 5}},
    {2, {frozen::string("MIKU_MOVE"), 4}},
    {0, {frozen::string("END"), 0}},
    {17, {frozen::string("FADEOUT_FIELD"), 2}},
    {104, {frozen::string("STAGE_LIGHT"), 3}},
    {45, {frozen::string("EDIT_HAND_ANIM"), 2}},
    {1, {frozen::string("TIME"), 1}},
    {18, {frozen::string("EYE_ANIM"), 3}},
    {105, {frozen::string("AGEAGE_CTRL"), 8}},
    {46, {frozen::string("AIM"), 3}},
    {10, {frozen::string("FADEIN_FIELD"), 2}},
    {14, {frozen::string("CHANGE_FIELD"), 1}},
    {101, {frozen::string("ITEM_ALPHA"), 4}},
    {42, {frozen::string("EDIT_ITEM"), 1}},
    {13, {frozen::string("DATA_CAMERA"), 2}},
    {100, {frozen::string("SHIMMER"), 3}},
    {41, {frozen::string("EDIT_EYE"), 2}},
    {15, {frozen::string("HIDE_FIELD"), 1}},
    {102, {frozen::string("MOVIE_CUT_CHG"), 2}},
    {43, {frozen::string("EDIT_EFFECT"), 2}},
    {11, {frozen::string("EFFECT_OFF"), 1}},
    {16, {frozen::string("MOVE_FIELD"), 3}},
    {103, {frozen::string("CHARA_LIGHT"), 3}},
    {44, {frozen::string("EDIT_DISP"), 1}},
    {12, {frozen::string("SET_CAMERA"), 6}},
    {19, {frozen::string("MOUTH_ANIM"), 5}},
    {106, {frozen::string("PSE"), 2}},
    {47, {frozen::string("HAND_ITEM"), 3}},
    {29, {frozen::string("SHADOWHEIGHT"), 2}},
    {3, {frozen::string("MIKU_ROT"), 2}},
    {30, {frozen::string("EDIT_FACE"), 1}},
    {31, {frozen::string("MOVE_CAMERA"), 21}},
    {32, {frozen::string("PV_END"), 0}},
    {33, {frozen::string("SHADOWPOS"), 3}},
    {34, {frozen::string("EDIT_LYRIC"), 2}},
    {35, {frozen::string("EDIT_TARGET"), 5}},
    {36, {frozen::string("EDIT_MOUTH"), 1}},
    {37, {frozen::string("SET_CHARA"), 1}},
    {38, {frozen::string("EDIT_MOVE"), 7}},
    {39, {frozen::string("EDIT_SHADOW"), 1}},
    {4, {frozen::string("MIKU_DISP"), 2}},
    {40, {frozen::string("EDIT_EYELID"), 1}},
    {48, {frozen::string("EDIT_BLUSH"), 1}},
    {49, {frozen::string("NEAR_CLIP"), 2}},
    {5, {frozen::string("MIKU_SHADOW"), 2}},
    {50, {frozen::string("CLOTH_WET"), 2}},
    {51, {frozen::string("LIGHT_ROT"), 3}},
    {52, {frozen::string("SCENE_FADE"), 6}},
    {53, {frozen::string("TONE_TRANS"), 6}},
    {54, {frozen::string("SATURATE"), 1}},
    {55, {frozen::string("FADE_MODE"), 1}}
};

int read_asint(std::vector<char>& data, int index);
int read();
int write();