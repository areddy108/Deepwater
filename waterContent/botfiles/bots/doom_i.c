//===========================================================================
//
// Name:			visor_i.c
// Function:		
// Programmer:		Mr Elusive (MrElusive@idsoftware.com)
// Last update:		1999-09-08
// Tab Size:		4 (real tabs)
//===========================================================================

#include "inv.h"

//initial health/armor states
#define FS_HEALTH			2
#define FS_ARMOR			3

//initial weapon weights
#define W_SHOTGUN				50
#define W_MACHINEGUN			70
#define W_GRENADELAUNCHER		0
#define W_ROCKETLAUNCHER		120
#define W_RAILGUN				450
#define W_BFG10K				130
#define W_LIGHTNING				50
#define W_PLASMAGUN				90

//the bot has the weapons, so the weights change a little bit
#define GWW_SHOTGUN				35
#define GWW_MACHINEGUN			50
#define GWW_GRENADELAUNCHER		0
#define GWW_ROCKETLAUNCHER		90
#define GWW_RAILGUN				250
#define GWW_BFG10K				110
#define GWW_LIGHTNING			40
#define GWW_PLASMAGUN			90

//initial powerup weights
#define W_TELEPORTER			40
#define W_MEDKIT				40
#define W_QUAD					400
#define W_ENVIRO				40
#define W_HASTE					40
#define W_INVISIBILITY			40
#define W_REGEN					40
#define W_FLIGHT				40

//flag weight
#define FLAG_WEIGHT				50

//
#include "fw_items.c"

