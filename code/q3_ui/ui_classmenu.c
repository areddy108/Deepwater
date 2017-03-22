/**
 * Deepwater - Class selection menu
 * by Kelvin Peng - Class of 2018
 * with Abhinav Reddy ('18) and Hunter Vaccaro ('18)
 * under the divide guidance of Rev. Dr. Oberle
 * code based on AvM and CvM classmenu.c
 *
 * We is C noobsicle, so maybe try to not learn from us :)
 */
 
#include "ui_local.h"

#define MENU_FRAME "menu/art/cut_frame"

#define ID_FRAGMAN            200   //Basic shooter guy
#define ID_CORPSMAN           201   //Medic
#define ID_SONARTECH          202   //Listen for wabbits
#define ID_MINEMAN            203   //Boom boom
#define ID_GUNNER             204   //Heavy
   
qboolean teamFlag; //false = red team, true = blue team

typedef 
   struct
   {
      menuframework_s menuFramework;
      menubitmap_s menuFrame;
      menutext_s chooseFragman;
      menutext_s chooseCorpsman;
      menutext_s chooseSonartech;
      menutext_s chooseMineman;
      menutext_s chooseGunner;
   }classSelector;

static classSelector menu;

/*
====================
When menu is clicked
====================
*/
static void Deepwater_MenuEvent (void* ptr, int event){
   if(event != QM_ACTIVATED){
      return;
   }

   switch(((menucommon_s*)ptr)->id){
      case ID_FRAGMAN:

		  trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team fragman\n" );
         UI_ForceMenuOff();
         break;
   
      case ID_CORPSMAN:
		  
		  trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team corpsman\n" );
         UI_ForceMenuOff();
         break;
   
      case ID_SONARTECH:
		  
		  trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team sonartech\n" );
         UI_ForceMenuOff();
         break;
   
      case ID_MINEMAN:
		  
		  trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team mineman\n" );
         UI_ForceMenuOff();
         break;
   
      case ID_GUNNER:
		  
		  trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team gunner\n" );
         UI_ForceMenuOff();
         break;
   }
}

/*
===============================
Initialize menu text and values
===============================
*/
void Deepwater_InitializeMenu(void){
   int x = 320;
   int y = 149;//Vertical position of each button on screen
   int gamemode;//Type of game mode to be played
   char info[MAX_INFO_STRING];//Configuration of game
   
   memset(&menu, 0, sizeof(menu));//Allocate memory
   
   menu.menuFramework.wrapAround = qtrue;
   menu.menuFramework.fullscreen = qfalse;
   
   menu.chooseFragman.generic.type     = MTYPE_PTEXT;
   menu.chooseFragman.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
   menu.chooseFragman.generic.id       = ID_FRAGMAN;
   menu.chooseFragman.generic.callback = Deepwater_MenuEvent;
   menu.chooseFragman.generic.x        = x;
   menu.chooseFragman.generic.y        = y;
   menu.chooseFragman.string           = "Fragman";
   menu.chooseFragman.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
   menu.chooseFragman.color            = colorBlue;
   y += 30;
   
   menu.chooseCorpsman.generic.type     = MTYPE_PTEXT;
   menu.chooseCorpsman.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
   menu.chooseCorpsman.generic.id       = ID_CORPSMAN;
   menu.chooseCorpsman.generic.callback = Deepwater_MenuEvent;
   menu.chooseCorpsman.generic.x        = x;
   menu.chooseCorpsman.generic.y        = y;
   menu.chooseCorpsman.string           = "Corpsman";
   menu.chooseCorpsman.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
   menu.chooseCorpsman.color            = colorBlue;
   y += 30;
   
   menu.chooseSonartech.generic.type     = MTYPE_PTEXT;
   menu.chooseSonartech.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
   menu.chooseSonartech.generic.id       = ID_SONARTECH;
   menu.chooseSonartech.generic.callback = Deepwater_MenuEvent;
   menu.chooseSonartech.generic.x        = x;
   menu.chooseSonartech.generic.y        = y;
   menu.chooseSonartech.string           = "Sonar Tech";
   menu.chooseSonartech.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
   menu.chooseSonartech.color            = colorBlue;
   y += 30;
   
   menu.chooseMineman.generic.type     = MTYPE_PTEXT;
   menu.chooseMineman.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
   menu.chooseMineman.generic.id       = ID_MINEMAN;
   menu.chooseMineman.generic.callback = Deepwater_MenuEvent;
   menu.chooseMineman.generic.x        = x;
   menu.chooseMineman.generic.y        = y;
   menu.chooseMineman.string           = "Mineman";
   menu.chooseMineman.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
   menu.chooseMineman.color            = colorBlue;
   y += 30;
	
   menu.chooseGunner.generic.type     = MTYPE_PTEXT;
   menu.chooseGunner.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
   menu.chooseGunner.generic.id       = ID_GUNNER;
   menu.chooseGunner.generic.callback = Deepwater_MenuEvent;
   menu.chooseGunner.generic.x        = x;
   menu.chooseGunner.generic.y        = y;
   menu.chooseGunner.string           = "Gunner";
   menu.chooseGunner.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
   menu.chooseGunner.color            = colorBlue;
   y += 30;

   trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);
   gamemode = atoi(Info_ValueForKey(info, "g_gametype"));

   Menu_AddItem(&menu.menuFramework, (void*) &menu.chooseFragman);
   Menu_AddItem(&menu.menuFramework, (void*) &menu.chooseCorpsman);
   Menu_AddItem(&menu.menuFramework, (void*) &menu.chooseSonartech);
   Menu_AddItem(&menu.menuFramework, (void*) &menu.chooseMineman);
   Menu_AddItem(&menu.menuFramework, (void*) &menu.chooseGunner);
}

void DeepwaterMenu_Cache(void){
	trap_R_RegisterShaderNoMip(MENU_FRAME);
}

void UI_DeepwaterMenu(void){
	Deepwater_InitializeMenu();
	UI_PushMenu(&menu.menuFramework);
}
