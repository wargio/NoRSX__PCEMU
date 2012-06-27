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

#include "Msg.h"

static vs32 dialog_action = 0;


static void dialog_handler(msgButton button, void *usrdata){
	dialog_action = button;
}

void sysutil_callback(u64 status, u64 param, void *usrdata){
}


MsgDialog::MsgDialog(Minimum *g){
	G=g;
	sysUtilRegisterCallback(SYSUTIL_EVENT_SLOT1, sysutil_callback, NULL);

}

MsgDialog::~MsgDialog(){
	sysUtilUnregisterCallback(SYSUTIL_EVENT_SLOT1);
}

void MsgDialog::Dialog(msgType md, const char *message){
	msgDialogOpen2(md, message, dialog_handler, NULL, NULL);
	
	dialog_action = 0;
	while(dialog_action == 0){
		sysUtilCheckCallback();
		flip(G->context, 1);
	}
	
	msgDialogAbort();
}

int MsgDialog::GetResponse(vs32 button){
	if(dialog_action == button){
		return 1;
	}
	return -1;
}


