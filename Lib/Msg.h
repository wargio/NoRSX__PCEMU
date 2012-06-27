/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 This program was created by Grazioli Giovanni Dante <wargio@libero.it>.
*/

#ifndef __NORSX_MSG_DIALOG_H__
#define __NORSX_MSG_DIALOG_H__
#include "Min.h"
#include "Font.h"
#include <SDL/SDL.h>
typedef uint32_t msgType;
//MSG Type
#define MSG_DIALOG_ERROR			0
#define MSG_DIALOG_NORMAL			1
#define MSG_DIALOG_MUTE_ON			2
#define MSG_DIALOG_BKG_INVISIBLE		4
#define MSG_DIALOG_BTN_TYPE_YESNO		16
#define MSG_DIALOG_BTN_TYPE_OK			32
#define MSG_DIALOG_DISABLE_CANCEL_ON		128
#define MSG_DIALOG_DEFAULT_CURSOR_NO		256
#define MSG_DIALOG_SINGLE_PROGRESSBAR		4096
#define MSG_DIALOG_DOUBLE_PROGRESSBAR		8192

//Buttons
#define MSG_DIALOG_BTN_NONE			1
#define MSG_DIALOG_BTN_INVALID			2
#define MSG_DIALOG_BTN_OK			3
#define MSG_DIALOG_BTN_YES			4
#define MSG_DIALOG_BTN_NO			5
#define MSG_DIALOG_BTN_ESCAPE			6


class MsgDialog{
public:
	 MsgDialog(Minimum *g);
	~MsgDialog();

	int Dialog(msgType md, const char *message);
	int GetResponse(s32 button);
protected:
	Minimum *G;
	void Draw_MSG_DIALOG();
	uint32_t *bitmap;
	Font *F;
};

#endif



