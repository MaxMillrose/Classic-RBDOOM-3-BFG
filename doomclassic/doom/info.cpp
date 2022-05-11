/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").  

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "Precompiled.h"

#ifdef __GNUG__
#pragma implementation "info.h"
#endif
#include "info.h"

#include "globaldata.h"

// Data.
#include "sounds.h"
#include "m_fixed.h"

#include "p_mobj.h"
#include "i_system.h"

#include "../d3xp/Game.h"


// RB: sprnames must be NULL-terminated
//GK:NO CONSTANTS
/*const*/ std::vector <char *> /*const*/ sprnames {
    (char*) "TROO",(char*) "SHTG",(char*) "PUNG",(char*) "PISG",(char*) "PISF",(char*) "SHTF",(char*) "SHT2",(char*) "CHGG",(char*) "CHGF",(char*) "MISG",
    (char*) "MISF",(char*) "SAWG",(char*) "PLSG",(char*) "PLSF",(char*) "BFGG",(char*) "BFGF",(char*) "BLUD",(char*) "PUFF",(char*) "BAL1",(char*) "BAL2",
    (char*) "PLSS",(char*) "PLSE",(char*) "MISL",(char*) "BFS1",(char*) "BFE1",(char*) "BFE2",(char*) "TFOG",(char*) "IFOG",(char*) "PLAY",(char*) "POSS",
    (char*) "SPOS",(char*) "VILE",(char*) "FIRE",(char*) "FATB",(char*) "FBXP",(char*) "SKEL",(char*) "MANF",(char*) "FATT",(char*) "CPOS",(char*) "SARG",
    (char*) "HEAD",(char*) "BAL7",(char*) "BOSS",(char*) "BOS2",(char*) "SKUL",(char*) "SPID",(char*) "BSPI",(char*) "APLS",(char*) "APBX",(char*) "CYBR",
    (char*) "PAIN",(char*) "SSWV",(char*) "KEEN",(char*) "BBRN",(char*) "BOSF",(char*) "ARM1",(char*) "ARM2",(char*) "BAR1",(char*) "BEXP",(char*) "FCAN",
    (char*) "BON1",(char*) "BON2",(char*) "BKEY",(char*) "RKEY",(char*) "YKEY",(char*) "BSKU",(char*) "RSKU",(char*) "YSKU",(char*) "STIM",(char*) "MEDI",
    (char*) "SOUL",(char*) "PINV",(char*) "PSTR",(char*) "PINS",(char*) "MEGA",(char*) "SUIT",(char*) "PMAP",(char*) "PVIS",(char*) "CLIP",(char*) "AMMO",
    (char*) "ROCK",(char*) "BROK",(char*) "CELL",(char*) "CELP",(char*) "SHEL",(char*) "SBOX",(char*) "BPAK",(char*) "BFUG",(char*) "MGUN",(char*) "CSAW",
    (char*) "LAUN",(char*) "PLAS",(char*) "SHOT",(char*) "SGN2",(char*) "COLU",(char*) "SMT2",(char*) "GOR1",(char*) "POL2",(char*) "POL5",(char*) "POL4",
    (char*) "POL3",(char*) "POL1",(char*) "POL6",(char*) "GOR2",(char*) "GOR3",(char*) "GOR4",(char*) "GOR5",(char*) "SMIT",(char*) "COL1",(char*) "COL2",
    (char*) "COL3",(char*) "COL4",(char*) "CAND",(char*) "CBRA",(char*) "COL6",(char*) "TRE1",(char*) "TRE2",(char*) "ELEC",(char*) "CEYE",(char*) "FSKU",
    (char*) "COL5",(char*) "TBLU",(char*) "TGRN",(char*) "TRED",(char*) "SMBT",(char*) "SMGT",(char*) "SMRT",(char*) "HDB1",(char*) "HDB2",(char*) "HDB3",
    (char*) "HDB4",(char*) "HDB5",(char*) "HDB6",(char*) "POB1",(char*) "POB2",(char*) "BRS1",(char*) "TLMP",(char*) "TLP2",
  (char*) "TNT1" // invisible sprite                                 phares 3/9/98
  ,(char*) "DOGS",(char*) "PLS1",(char*) "PLS2",(char*) "BON3",(char*) "BON4",
	// [BH] blood splats, [crispy] unused
	(char*) "BLD2",
	//// [BH] 100 extra sprite names to use in dehacked patches
  (char*)NULL
};
// RB end
void resetSprnames() {
	std::vector <char *> tsprnames {
		(char*) "TROO",(char*) "SHTG",(char*) "PUNG",(char*) "PISG",(char*) "PISF",(char*) "SHTF",(char*) "SHT2",(char*) "CHGG",(char*) "CHGF",(char*) "MISG",
		(char*) "MISF",(char*) "SAWG",(char*) "PLSG",(char*) "PLSF",(char*) "BFGG",(char*) "BFGF",(char*) "BLUD",(char*) "PUFF",(char*) "BAL1",(char*) "BAL2",
		(char*) "PLSS",(char*) "PLSE",(char*) "MISL",(char*) "BFS1",(char*) "BFE1",(char*) "BFE2",(char*) "TFOG",(char*) "IFOG",(char*) "PLAY",(char*) "POSS",
		(char*) "SPOS",(char*) "VILE",(char*) "FIRE",(char*) "FATB",(char*) "FBXP",(char*) "SKEL",(char*) "MANF",(char*) "FATT",(char*) "CPOS",(char*) "SARG",
		(char*) "HEAD",(char*) "BAL7",(char*) "BOSS",(char*) "BOS2",(char*) "SKUL",(char*) "SPID",(char*) "BSPI",(char*) "APLS",(char*) "APBX",(char*) "CYBR",
		(char*) "PAIN",(char*) "SSWV",(char*) "KEEN",(char*) "BBRN",(char*) "BOSF",(char*) "ARM1",(char*) "ARM2",(char*) "BAR1",(char*) "BEXP",(char*) "FCAN",
		(char*) "BON1",(char*) "BON2",(char*) "BKEY",(char*) "RKEY",(char*) "YKEY",(char*) "BSKU",(char*) "RSKU",(char*) "YSKU",(char*) "STIM",(char*) "MEDI",
		(char*) "SOUL",(char*) "PINV",(char*) "PSTR",(char*) "PINS",(char*) "MEGA",(char*) "SUIT",(char*) "PMAP",(char*) "PVIS",(char*) "CLIP",(char*) "AMMO",
		(char*) "ROCK",(char*) "BROK",(char*) "CELL",(char*) "CELP",(char*) "SHEL",(char*) "SBOX",(char*) "BPAK",(char*) "BFUG",(char*) "MGUN",(char*) "CSAW",
		(char*) "LAUN",(char*) "PLAS",(char*) "SHOT",(char*) "SGN2",(char*) "COLU",(char*) "SMT2",(char*) "GOR1",(char*) "POL2",(char*) "POL5",(char*) "POL4",
		(char*) "POL3",(char*) "POL1",(char*) "POL6",(char*) "GOR2",(char*) "GOR3",(char*) "GOR4",(char*) "GOR5",(char*) "SMIT",(char*) "COL1",(char*) "COL2",
		(char*) "COL3",(char*) "COL4",(char*) "CAND",(char*) "CBRA",(char*) "COL6",(char*) "TRE1",(char*) "TRE2",(char*) "ELEC",(char*) "CEYE",(char*) "FSKU",
		(char*) "COL5",(char*) "TBLU",(char*) "TGRN",(char*) "TRED",(char*) "SMBT",(char*) "SMGT",(char*) "SMRT",(char*) "HDB1",(char*) "HDB2",(char*) "HDB3",
		(char*) "HDB4",(char*) "HDB5",(char*) "HDB6",(char*) "POB1",(char*) "POB2",(char*) "BRS1",(char*) "TLMP",(char*) "TLP2",
  (char*) "TNT1" // invisible sprite                                 phares 3/9/98
  ,(char*) "DOGS",(char*) "PLS1",(char*) "PLS2",(char*) "BON3",(char*) "BON4",
		// [BH] blood splats, [crispy] unused
		(char*) "BLD2",
		//// [BH] 100 extra sprite names to use in dehacked patches
	  (char*)NULL
	};
	//memcpy(sprnames, tsprnames, sizeof(tsprnames));
	sprnames = tsprnames;
}

extern "C"
{
	// Doesn't work with g++, needs actionf_p1
	void  A_Light0(void *p1, void *p2);
	void A_WeaponReady(void *p1, void *p2);
	void A_Lower(void *p1, void *p2);
	void A_Raise(void *p1, void *p2);
	void A_Punch(void *p1, void *p2);
	void A_ReFire(void *p1, void *p2);
	void A_FirePistol(void *p1, void *p2);
	void A_Light1(void *p1, void *p2);
	void A_FireShotgun(void *p1, void *p2);
	void A_Light2(void *p1, void *p2);
	void A_FireShotgun2(void *p1, void *p2);
	void A_CheckReload(void *p1, void *p2);
	void A_OpenShotgun2(void *p1, void *p2);
	void A_LoadShotgun2(void *p1, void *p2);
	void A_CloseShotgun2(void *p1, void *p2);
	void A_FireCGun(void *p1, void *p2);
	void A_GunFlash(void *p1, void *p2);
	void A_FireMissile(void *p1, void *p2);
	void A_Saw(void *p1, void *p2);
	void A_FirePlasma(void *p1, void *p2);
	void A_BFGsound(void *p1, void *p2);
	void A_FireBFG(void *p1, void *p2);
	void A_BFGSpray(void *p1, void *p2);
	void A_Explode(void *p1, void *p2);
	void A_Pain(void *p1, void *p2);
	void A_PlayerScream(void *p1, void *p2);
	void A_Fall(void *p1, void *p2);
	void A_XScream(void *p1, void *p2);
	void A_Look(void *p1, void *p2);
	void A_Chase(void *p1, void *p2);
	void A_FaceTarget(void *p1, void *p2);
	void A_PosAttack(void *p1, void *p2);
	void A_Scream(void *p1, void *p2);
	void A_SPosAttack(void *p1, void *p2);
	void A_VileChase(void *p1, void *p2);
	void A_VileStart(void *p1, void *p2);
	void A_VileTarget(void *p1, void *p2);
	void A_VileAttack(void *p1, void *p2);
	void A_StartFire(void *p1, void *p2);
	void A_Fire(void *p1, void *p2);
	void A_FireCrackle(void *p1, void *p2);
	void A_Tracer(void *p1, void *p2);
	void A_SkelWhoosh(void *p1, void *p2);
	void A_SkelFist(void *p1, void *p2);
	void A_SkelMissile(void *p1, void *p2);
	void A_FatRaise(void *p1, void *p2);
	void A_FatAttack1(void *p1, void *p2);
	void A_FatAttack2(void *p1, void *p2);
	void A_FatAttack3(void *p1, void *p2);
	void A_BossDeath(void *p1, void *p2);
	void A_CPosAttack(void *p1, void *p2);
	void A_CPosRefire(void *p1, void *p2);
	void A_TroopAttack(void *p1, void *p2);
	void A_SargAttack(void *p1, void *p2);
	void A_HeadAttack(void *p1, void *p2);
	void A_BruisAttack(void *p1, void *p2);
	void A_SkullAttack(void *p1, void *p2);
	void A_Metal(void *p1, void *p2);
	void A_SpidRefire(void *p1, void *p2);
	void A_BabyMetal(void *p1, void *p2);
	void A_BspiAttack(void *p1, void *p2);
	void A_Hoof(void *p1, void *p2);
	void A_CyberAttack(void *p1, void *p2);
	void A_PainAttack(void *p1, void *p2);
	void A_PainDie(void *p1, void *p2);
	void A_KeenDie(void *p1, void *p2);
	void A_BrainPain(void *p1, void *p2);
	void A_BrainScream(void *p1, void *p2);
	void A_BrainDie(void *p1, void *p2);
	void A_BrainAwake(void *p1, void *p2);
	void A_BrainSpit(void *p1, void *p2);
	void A_SpawnSound(void *p1, void *p2);
	void A_SpawnFly(void *p1, void *p2);
	void A_BrainExplode(void *p1, void *p2);
	void A_RandomJump(void* p1, void* p2);
	void A_Spawn(void* p1, void* p2);
};


/*const*/ std::vector<state_t> tempStates {
	{SPR_TROO,0,-1,{NULL},S_NULL,0,0},	// S_NULL
	{SPR_SHTG,4,0,{(actionf_p2)A_Light0},S_NULL,0,0},	// S_LIGHTDONE
	{SPR_PUNG,0,1,{(actionf_p2)A_WeaponReady},S_PUNCH,0,0},	// S_PUNCH
	{SPR_PUNG,0,1,{(actionf_p2)A_Lower},S_PUNCHDOWN,0,0},	// S_PUNCHDOWN
	{SPR_PUNG,0,1,{(actionf_p2)A_Raise},S_PUNCHUP,0,0},	// S_PUNCHUP
	{SPR_PUNG,1,4,{NULL},S_PUNCH2,0,0},		// S_PUNCH1
	{SPR_PUNG,2,4,{(actionf_p2)A_Punch},S_PUNCH3,0,0},	// S_PUNCH2
	{SPR_PUNG,3,5,{NULL},S_PUNCH4,0,0},		// S_PUNCH3
	{SPR_PUNG,2,4,{NULL},S_PUNCH5,0,0},		// S_PUNCH4
	{SPR_PUNG,1,5,{(actionf_p2)A_ReFire},S_PUNCH,0,0},	// S_PUNCH5
	{SPR_PISG,0,1,{(actionf_p2)A_WeaponReady},S_PISTOL,0,0},// S_PISTOL
	{SPR_PISG,0,1,{(actionf_p2)A_Lower},S_PISTOLDOWN,0,0},	// S_PISTOLDOWN
	{SPR_PISG,0,1,{(actionf_p2)A_Raise},S_PISTOLUP,0,0},	// S_PISTOLUP
	{SPR_PISG,0,4,{NULL},S_PISTOL2,0,0},	// S_PISTOL1
	{SPR_PISG,1,6,{(actionf_p2)A_FirePistol},S_PISTOL3,0,0},// S_PISTOL2
	{SPR_PISG,2,4,{NULL},S_PISTOL4,0,0},	// S_PISTOL3
	{SPR_PISG,1,5,{(actionf_p2)A_ReFire},S_PISTOL,0,0},	// S_PISTOL4
	{SPR_PISF,32768,7,{(actionf_p2)A_Light1},S_LIGHTDONE,0,0},	// S_PISTOLFLASH
	{SPR_SHTG,0,1,{(actionf_p2)A_WeaponReady},S_SGUN,0,0},	// S_SGUN
	{SPR_SHTG,0,1,{(actionf_p2)A_Lower},S_SGUNDOWN,0,0},	// S_SGUNDOWN
	{SPR_SHTG,0,1,{(actionf_p2)A_Raise},S_SGUNUP,0,0},	// S_SGUNUP
	{SPR_SHTG,0,3,{NULL},S_SGUN2,0,0},	// S_SGUN1
	{SPR_SHTG,0,7,{(actionf_p2)A_FireShotgun},S_SGUN3,0,0},	// S_SGUN2
	{SPR_SHTG,1,5,{NULL},S_SGUN4,0,0},	// S_SGUN3
	{SPR_SHTG,2,5,{NULL},S_SGUN5,0,0},	// S_SGUN4
	{SPR_SHTG,3,4,{NULL},S_SGUN6,0,0},	// S_SGUN5
	{SPR_SHTG,2,5,{NULL},S_SGUN7,0,0},	// S_SGUN6
	{SPR_SHTG,1,5,{NULL},S_SGUN8,0,0},	// S_SGUN7
	{SPR_SHTG,0,3,{NULL},S_SGUN9,0,0},	// S_SGUN8
	{SPR_SHTG,0,7,{(actionf_p2)A_ReFire},S_SGUN,0,0},	// S_SGUN9
	{SPR_SHTF,32768,4,{(actionf_p2)A_Light1},S_SGUNFLASH2,0,0},	// S_SGUNFLASH1
	{SPR_SHTF,32769,3,{(actionf_p2)A_Light2},S_LIGHTDONE,0,0},	// S_SGUNFLASH2
    {SPR_SHT2,0,1,{(actionf_p2)A_WeaponReady},S_DSGUN,0,0},	// S_DSGUN
	{SPR_SHT2,0,1,{(actionf_p2)A_Lower},S_DSGUNDOWN,0,0},	// S_DSGUNDOWN
	{SPR_SHT2,0,1,{(actionf_p2)A_Raise},S_DSGUNUP,0,0},	// S_DSGUNUP
	{SPR_SHT2,0,3,{NULL},S_DSGUN2,0,0},	// S_DSGUN1
	{SPR_SHT2,0,7,{(actionf_p2)A_FireShotgun2},S_DSGUN3,0,0},	// S_DSGUN2
	{SPR_SHT2,1,7,{NULL},S_DSGUN4,0,0},	// S_DSGUN3
	{SPR_SHT2,2,7,{(actionf_p2)A_CheckReload},S_DSGUN5,0,0},	// S_DSGUN4
	{SPR_SHT2,3,7,{(actionf_p2)A_OpenShotgun2},S_DSGUN6,0,0},	// S_DSGUN5
	{SPR_SHT2,4,7,{NULL},S_DSGUN7,0,0},	// S_DSGUN6
	{SPR_SHT2,5,7,{(actionf_p2)A_LoadShotgun2},S_DSGUN8,0,0},	// S_DSGUN7
	{SPR_SHT2,6,6,{NULL},S_DSGUN9,0,0},	// S_DSGUN8
	{SPR_SHT2,7,6,{(actionf_p2)A_CloseShotgun2},S_DSGUN10,0,0},	// S_DSGUN9
	{SPR_SHT2,0,5,{(actionf_p2)A_ReFire},S_DSGUN,0,0},	// S_DSGUN10
	{SPR_SHT2,1,7,{NULL},S_DSNR2,0,0},	// S_DSNR1
	{SPR_SHT2,0,3,{NULL},S_DSGUNDOWN,0,0},	// S_DSNR2
	{SPR_SHT2,32776,5,{(actionf_p2)A_Light1},S_DSGUNFLASH2,0,0},	// S_DSGUNFLASH1
	{SPR_SHT2,32777,4,{(actionf_p2)A_Light2},S_LIGHTDONE,0,0},	// S_DSGUNFLASH2
	{SPR_CHGG,0,1,{(actionf_p2)A_WeaponReady},S_CHAIN,0,0},	// S_CHAIN
	{SPR_CHGG,0,1,{(actionf_p2)A_Lower},S_CHAINDOWN,0,0},	// S_CHAINDOWN
	{SPR_CHGG,0,1,{(actionf_p2)A_Raise},S_CHAINUP,0,0},	// S_CHAINUP
	{SPR_CHGG,0,4,{(actionf_p2)A_FireCGun},S_CHAIN2,0,0},	// S_CHAIN1
	{SPR_CHGG,1,4,{(actionf_p2)A_FireCGun},S_CHAIN3,0,0},	// S_CHAIN2
	{SPR_CHGG,1,0,{(actionf_p2)A_ReFire},S_CHAIN,0,0},	// S_CHAIN3
    {SPR_CHGF,32768,5,{(actionf_p2)A_Light1},S_LIGHTDONE,0,0},	// S_CHAINFLASH1
    {SPR_CHGF,32769,5,{(actionf_p2)A_Light2},S_LIGHTDONE,0,0},	// S_CHAINFLASH2
    {SPR_MISG,0,1,{(actionf_p2)A_WeaponReady},S_MISSILE,0,0},	// S_MISSILE
    {SPR_MISG,0,1,{(actionf_p2)A_Lower},S_MISSILEDOWN,0,0},	// S_MISSILEDOWN
    {SPR_MISG,0,1,{(actionf_p2)A_Raise},S_MISSILEUP,0,0},	// S_MISSILEUP
    {SPR_MISG,1,8,{(actionf_p2)A_GunFlash},S_MISSILE2,0,0},	// S_MISSILE1
    {SPR_MISG,1,12,{(actionf_p2)A_FireMissile},S_MISSILE3,0,0},	// S_MISSILE2
    {SPR_MISG,1,0,{(actionf_p2)A_ReFire},S_MISSILE,0,0},	// S_MISSILE3
    {SPR_MISF,32768,3,{(actionf_p2)A_Light1},S_MISSILEFLASH2,0,0},	// S_MISSILEFLASH1
    {SPR_MISF,32769,4,{NULL},S_MISSILEFLASH3,0,0},	// S_MISSILEFLASH2
    {SPR_MISF,32770,4,{(actionf_p2)A_Light2},S_MISSILEFLASH4,0,0},	// S_MISSILEFLASH3
    {SPR_MISF,32771,4,{(actionf_p2)A_Light2},S_LIGHTDONE,0,0},	// S_MISSILEFLASH4
    {SPR_SAWG,2,4,{(actionf_p2)A_WeaponReady},S_SAWB,0,0},	// S_SAW
    {SPR_SAWG,3,4,{(actionf_p2)A_WeaponReady},S_SAW,0,0},	// S_SAWB
    {SPR_SAWG,2,1,{(actionf_p2)A_Lower},S_SAWDOWN,0,0},	// S_SAWDOWN
    {SPR_SAWG,2,1,{(actionf_p2)A_Raise},S_SAWUP,0,0},	// S_SAWUP
    {SPR_SAWG,0,4,{(actionf_p2)A_Saw},S_SAW2,0,0},	// S_SAW1
    {SPR_SAWG,1,4,{(actionf_p2)A_Saw},S_SAW3,0,0},	// S_SAW2
    {SPR_SAWG,1,0,{(actionf_p2)A_ReFire},S_SAW,0,0},	// S_SAW3
    {SPR_PLSG,0,1,{(actionf_p2)A_WeaponReady},S_PLASMA,0,0},	// S_PLASMA
    {SPR_PLSG,0,1,{(actionf_p2)A_Lower},S_PLASMADOWN,0,0},	// S_PLASMADOWN
    {SPR_PLSG,0,1,{(actionf_p2)A_Raise},S_PLASMAUP,0,0},	// S_PLASMAUP
    {SPR_PLSG,0,3,{(actionf_p2)A_FirePlasma},S_PLASMA2,0,0},	// S_PLASMA1
    {SPR_PLSG,1,20,{(actionf_p2)A_ReFire},S_PLASMA,0,0},	// S_PLASMA2
    {SPR_PLSF,32768,4,{(actionf_p2)A_Light1},S_LIGHTDONE,0,0},	// S_PLASMAFLASH1
    {SPR_PLSF,32769,4,{(actionf_p2)A_Light1},S_LIGHTDONE,0,0},	// S_PLASMAFLASH2
    {SPR_BFGG,0,1,{(actionf_p2)A_WeaponReady},S_BFG,0,0},	// S_BFG
    {SPR_BFGG,0,1,{(actionf_p2)A_Lower},S_BFGDOWN,0,0},	// S_BFGDOWN
    {SPR_BFGG,0,1,{(actionf_p2)A_Raise},S_BFGUP,0,0},	// S_BFGUP
    {SPR_BFGG,0,20,{(actionf_p2)A_BFGsound},S_BFG2,0,0},	// S_BFG1
    {SPR_BFGG,1,10,{(actionf_p2)A_GunFlash},S_BFG3,0,0},	// S_BFG2
    {SPR_BFGG,1,10,{(actionf_p2)A_FireBFG},S_BFG4,0,0},	// S_BFG3
    {SPR_BFGG,1,20,{(actionf_p2)A_ReFire},S_BFG,0,0},	// S_BFG4
    {SPR_BFGF,32768,11,{(actionf_p2)A_Light1},S_BFGFLASH2,0,0},	// S_BFGFLASH1
    {SPR_BFGF,32769,6,{(actionf_p2)A_Light2},S_LIGHTDONE,0,0},	// S_BFGFLASH2
    {SPR_BLUD,2,8,{NULL},S_BLOOD2,0,0},	// S_BLOOD1
    {SPR_BLUD,1,8,{NULL},S_BLOOD3,0,0},	// S_BLOOD2
    {SPR_BLUD,0,8,{NULL},S_NULL,0,0},	// S_BLOOD3
    {SPR_PUFF,32768,4,{NULL},S_PUFF2,0,0},	// S_PUFF1
    {SPR_PUFF,1,4,{NULL},S_PUFF3,0,0},	// S_PUFF2
    {SPR_PUFF,2,4,{NULL},S_PUFF4,0,0},	// S_PUFF3
    {SPR_PUFF,3,4,{NULL},S_NULL,0,0},	// S_PUFF4
    {SPR_BAL1,32768,4,{NULL},S_TBALL2,0,0},	// S_TBALL1
    {SPR_BAL1,32769,4,{NULL},S_TBALL1,0,0},	// S_TBALL2
    {SPR_BAL1,32770,6,{NULL},S_TBALLX2,0,0},	// S_TBALLX1
    {SPR_BAL1,32771,6,{NULL},S_TBALLX3,0,0},	// S_TBALLX2
    {SPR_BAL1,32772,6,{NULL},S_NULL,0,0},	// S_TBALLX3
    {SPR_BAL2,32768,4,{NULL},S_RBALL2,0,0},	// S_RBALL1
    {SPR_BAL2,32769,4,{NULL},S_RBALL1,0,0},	// S_RBALL2
    {SPR_BAL2,32770,6,{NULL},S_RBALLX2,0,0},	// S_RBALLX1
    {SPR_BAL2,32771,6,{NULL},S_RBALLX3,0,0},	// S_RBALLX2
    {SPR_BAL2,32772,6,{NULL},S_NULL,0,0},	// S_RBALLX3
    {SPR_PLSS,32768,6,{NULL},S_PLASBALL2,0,0},	// S_PLASBALL
    {SPR_PLSS,32769,6,{NULL},S_PLASBALL,0,0},	// S_PLASBALL2
    {SPR_PLSE,32768,4,{NULL},S_PLASEXP2,0,0},	// S_PLASEXP
    {SPR_PLSE,32769,4,{NULL},S_PLASEXP3,0,0},	// S_PLASEXP2
    {SPR_PLSE,32770,4,{NULL},S_PLASEXP4,0,0},	// S_PLASEXP3
    {SPR_PLSE,32771,4,{NULL},S_PLASEXP5,0,0},	// S_PLASEXP4
    {SPR_PLSE,32772,4,{NULL},S_NULL,0,0},	// S_PLASEXP5
    {SPR_MISL,32768,1,{NULL},S_ROCKET,0,0},	// S_ROCKET
    {SPR_BFS1,32768,4,{NULL},S_BFGSHOT2,0,0},	// S_BFGSHOT
    {SPR_BFS1,32769,4,{NULL},S_BFGSHOT,0,0},	// S_BFGSHOT2
    {SPR_BFE1,32768,8,{NULL},S_BFGLAND2,0,0},	// S_BFGLAND
    {SPR_BFE1,32769,8,{NULL},S_BFGLAND3,0,0},	// S_BFGLAND2
    {SPR_BFE1,32770,8,{(actionf_p2)A_BFGSpray},S_BFGLAND4,0,0},	// S_BFGLAND3
    {SPR_BFE1,32771,8,{NULL},S_BFGLAND5,0,0},	// S_BFGLAND4
    {SPR_BFE1,32772,8,{NULL},S_BFGLAND6,0,0},	// S_BFGLAND5
    {SPR_BFE1,32773,8,{NULL},S_NULL,0,0},	// S_BFGLAND6
    {SPR_BFE2,32768,8,{NULL},S_BFGEXP2,0,0},	// S_BFGEXP
    {SPR_BFE2,32769,8,{NULL},S_BFGEXP3,0,0},	// S_BFGEXP2
    {SPR_BFE2,32770,8,{NULL},S_BFGEXP4,0,0},	// S_BFGEXP3
    {SPR_BFE2,32771,8,{NULL},S_NULL,0,0},	// S_BFGEXP4
    {SPR_MISL,32769,8,{(actionf_p2)A_Explode},S_EXPLODE2,0,0},	// S_EXPLODE1
    {SPR_MISL,32770,6,{NULL},S_EXPLODE3,0,0},	// S_EXPLODE2
    {SPR_MISL,32771,4,{NULL},S_NULL,0,0},	// S_EXPLODE3
    {SPR_TFOG,32768,6,{NULL},S_TFOG01,0,0},	// S_TFOG
    {SPR_TFOG,32769,6,{NULL},S_TFOG02,0,0},	// S_TFOG01
    {SPR_TFOG,32768,6,{NULL},S_TFOG2,0,0},	// S_TFOG02
    {SPR_TFOG,32769,6,{NULL},S_TFOG3,0,0},	// S_TFOG2
    {SPR_TFOG,32770,6,{NULL},S_TFOG4,0,0},	// S_TFOG3
    {SPR_TFOG,32771,6,{NULL},S_TFOG5,0,0},	// S_TFOG4
    {SPR_TFOG,32772,6,{NULL},S_TFOG6,0,0},	// S_TFOG5
    {SPR_TFOG,32773,6,{NULL},S_TFOG7,0,0},	// S_TFOG6
    {SPR_TFOG,32774,6,{NULL},S_TFOG8,0,0},	// S_TFOG7
    {SPR_TFOG,32775,6,{NULL},S_TFOG9,0,0},	// S_TFOG8
    {SPR_TFOG,32776,6,{NULL},S_TFOG10,0,0},	// S_TFOG9
    {SPR_TFOG,32777,6,{NULL},S_NULL,0,0},	// S_TFOG10
    {SPR_IFOG,32768,6,{NULL},S_IFOG01,0,0},	// S_IFOG
    {SPR_IFOG,32769,6,{NULL},S_IFOG02,0,0},	// S_IFOG01
    {SPR_IFOG,32768,6,{NULL},S_IFOG2,0,0},	// S_IFOG02
    {SPR_IFOG,32769,6,{NULL},S_IFOG3,0,0},	// S_IFOG2
    {SPR_IFOG,32770,6,{NULL},S_IFOG4,0,0},	// S_IFOG3
    {SPR_IFOG,32771,6,{NULL},S_IFOG5,0,0},	// S_IFOG4
    {SPR_IFOG,32772,6,{NULL},S_NULL,0,0},	// S_IFOG5
    {SPR_PLAY,0,-1,{NULL},S_NULL,0,0},	// S_PLAY
    {SPR_PLAY,0,4,{NULL},S_PLAY_RUN2,0,0},	// S_PLAY_RUN1
    {SPR_PLAY,1,4,{NULL},S_PLAY_RUN3,0,0},	// S_PLAY_RUN2
    {SPR_PLAY,2,4,{NULL},S_PLAY_RUN4,0,0},	// S_PLAY_RUN3
    {SPR_PLAY,3,4,{NULL},S_PLAY_RUN1,0,0},	// S_PLAY_RUN4
    {SPR_PLAY,4,12,{NULL},S_PLAY,0,0},	// S_PLAY_ATK1
    {SPR_PLAY,32773,6,{NULL},S_PLAY_ATK1,0,0},	// S_PLAY_ATK2
    {SPR_PLAY,6,4,{NULL},S_PLAY_PAIN2,0,0},	// S_PLAY_PAIN
    {SPR_PLAY,6,4,{(actionf_p2)A_Pain},S_PLAY,0,0},	// S_PLAY_PAIN2
    {SPR_PLAY,7,10,{NULL},S_PLAY_DIE2,0,0},	// S_PLAY_DIE1
    {SPR_PLAY,8,10,{(actionf_p2)A_PlayerScream},S_PLAY_DIE3,0,0},	// S_PLAY_DIE2
    {SPR_PLAY,9,10,{(actionf_p2)A_Fall},S_PLAY_DIE4,0,0},	// S_PLAY_DIE3
    {SPR_PLAY,10,10,{NULL},S_PLAY_DIE5,0,0},	// S_PLAY_DIE4
    {SPR_PLAY,11,10,{NULL},S_PLAY_DIE6,0,0},	// S_PLAY_DIE5
    {SPR_PLAY,12,10,{NULL},S_PLAY_DIE7,0,0},	// S_PLAY_DIE6
    {SPR_PLAY,13,-1,{NULL},S_NULL,0,0},	// S_PLAY_DIE7
    {SPR_PLAY,14,5,{NULL},S_PLAY_XDIE2,0,0},	// S_PLAY_XDIE1
    {SPR_PLAY,15,5,{(actionf_p2)A_XScream},S_PLAY_XDIE3,0,0},	// S_PLAY_XDIE2
    {SPR_PLAY,16,5,{(actionf_p2)A_Fall},S_PLAY_XDIE4,0,0},	// S_PLAY_XDIE3
    {SPR_PLAY,17,5,{NULL},S_PLAY_XDIE5,0,0},	// S_PLAY_XDIE4
    {SPR_PLAY,18,5,{NULL},S_PLAY_XDIE6,0,0},	// S_PLAY_XDIE5
    {SPR_PLAY,19,5,{NULL},S_PLAY_XDIE7,0,0},	// S_PLAY_XDIE6
    {SPR_PLAY,20,5,{NULL},S_PLAY_XDIE8,0,0},	// S_PLAY_XDIE7
    {SPR_PLAY,21,5,{NULL},S_PLAY_XDIE9,0,0},	// S_PLAY_XDIE8
    {SPR_PLAY,22,-1,{NULL},S_NULL,0,0},	// S_PLAY_XDIE9
    {SPR_POSS,0,10,{(actionf_p2)A_Look},S_POSS_STND2,0,0},	// S_POSS_STND
    {SPR_POSS,1,10,{(actionf_p2)A_Look},S_POSS_STND,0,0},	// S_POSS_STND2
    {SPR_POSS,0,4,{(actionf_p2)A_Chase},S_POSS_RUN2,0,0},	// S_POSS_RUN1
    {SPR_POSS,0,4,{(actionf_p2)A_Chase},S_POSS_RUN3,0,0},	// S_POSS_RUN2
    {SPR_POSS,1,4,{(actionf_p2)A_Chase},S_POSS_RUN4,0,0},	// S_POSS_RUN3
    {SPR_POSS,1,4,{(actionf_p2)A_Chase},S_POSS_RUN5,0,0},	// S_POSS_RUN4
    {SPR_POSS,2,4,{(actionf_p2)A_Chase},S_POSS_RUN6,0,0},	// S_POSS_RUN5
    {SPR_POSS,2,4,{(actionf_p2)A_Chase},S_POSS_RUN7,0,0},	// S_POSS_RUN6
    {SPR_POSS,3,4,{(actionf_p2)A_Chase},S_POSS_RUN8,0,0},	// S_POSS_RUN7
    {SPR_POSS,3,4,{(actionf_p2)A_Chase},S_POSS_RUN1,0,0},	// S_POSS_RUN8
    {SPR_POSS,4,10,{(actionf_p2)A_FaceTarget},S_POSS_ATK2,0,0},	// S_POSS_ATK1
    {SPR_POSS,5,8,{(actionf_p2)A_PosAttack},S_POSS_ATK3,0,0},	// S_POSS_ATK2
    {SPR_POSS,4,8,{NULL},S_POSS_RUN1,0,0},	// S_POSS_ATK3
    {SPR_POSS,6,3,{NULL},S_POSS_PAIN2,0,0},	// S_POSS_PAIN
    {SPR_POSS,6,3,{(actionf_p2)A_Pain},S_POSS_RUN1,0,0},	// S_POSS_PAIN2
    {SPR_POSS,7,5,{NULL},S_POSS_DIE2,0,0},	// S_POSS_DIE1
    {SPR_POSS,8,5,{(actionf_p2)A_Scream},S_POSS_DIE3,0,0},	// S_POSS_DIE2
    {SPR_POSS,9,5,{(actionf_p2)A_Fall},S_POSS_DIE4,0,0},	// S_POSS_DIE3
    {SPR_POSS,10,5,{NULL},S_POSS_DIE5,0,0},	// S_POSS_DIE4
    {SPR_POSS,11,-1,{NULL},S_NULL,0,0},	// S_POSS_DIE5
    {SPR_POSS,12,5,{NULL},S_POSS_XDIE2,0,0},	// S_POSS_XDIE1
    {SPR_POSS,13,5,{(actionf_p2)A_XScream},S_POSS_XDIE3,0,0},	// S_POSS_XDIE2
    {SPR_POSS,14,5,{(actionf_p2)A_Fall},S_POSS_XDIE4,0,0},	// S_POSS_XDIE3
    {SPR_POSS,15,5,{NULL},S_POSS_XDIE5,0,0},	// S_POSS_XDIE4
    {SPR_POSS,16,5,{NULL},S_POSS_XDIE6,0,0},	// S_POSS_XDIE5
    {SPR_POSS,17,5,{NULL},S_POSS_XDIE7,0,0},	// S_POSS_XDIE6
    {SPR_POSS,18,5,{NULL},S_POSS_XDIE8,0,0},	// S_POSS_XDIE7
    {SPR_POSS,19,5,{NULL},S_POSS_XDIE9,0,0},	// S_POSS_XDIE8
    {SPR_POSS,20,-1,{NULL},S_NULL,0,0},	// S_POSS_XDIE9
    {SPR_POSS,10,5,{NULL},S_POSS_RAISE2,0,0},	// S_POSS_RAISE1
    {SPR_POSS,9,5,{NULL},S_POSS_RAISE3,0,0},	// S_POSS_RAISE2
    {SPR_POSS,8,5,{NULL},S_POSS_RAISE4,0,0},	// S_POSS_RAISE3
    {SPR_POSS,7,5,{NULL},S_POSS_RUN1,0,0},	// S_POSS_RAISE4
    {SPR_SPOS,0,10,{(actionf_p2)A_Look},S_SPOS_STND2,0,0},	// S_SPOS_STND
    {SPR_SPOS,1,10,{(actionf_p2)A_Look},S_SPOS_STND,0,0},	// S_SPOS_STND2
    {SPR_SPOS,0,3,{(actionf_p2)A_Chase},S_SPOS_RUN2,0,0},	// S_SPOS_RUN1
    {SPR_SPOS,0,3,{(actionf_p2)A_Chase},S_SPOS_RUN3,0,0},	// S_SPOS_RUN2
    {SPR_SPOS,1,3,{(actionf_p2)A_Chase},S_SPOS_RUN4,0,0},	// S_SPOS_RUN3
    {SPR_SPOS,1,3,{(actionf_p2)A_Chase},S_SPOS_RUN5,0,0},	// S_SPOS_RUN4
    {SPR_SPOS,2,3,{(actionf_p2)A_Chase},S_SPOS_RUN6,0,0},	// S_SPOS_RUN5
    {SPR_SPOS,2,3,{(actionf_p2)A_Chase},S_SPOS_RUN7,0,0},	// S_SPOS_RUN6
    {SPR_SPOS,3,3,{(actionf_p2)A_Chase},S_SPOS_RUN8,0,0},	// S_SPOS_RUN7
    {SPR_SPOS,3,3,{(actionf_p2)A_Chase},S_SPOS_RUN1,0,0},	// S_SPOS_RUN8
    {SPR_SPOS,4,10,{(actionf_p2)A_FaceTarget},S_SPOS_ATK2,0,0},	// S_SPOS_ATK1
    {SPR_SPOS,32773,10,{(actionf_p2)A_SPosAttack},S_SPOS_ATK3,0,0},	// S_SPOS_ATK2
    {SPR_SPOS,4,10,{NULL},S_SPOS_RUN1,0,0},	// S_SPOS_ATK3
    {SPR_SPOS,6,3,{NULL},S_SPOS_PAIN2,0,0},	// S_SPOS_PAIN
    {SPR_SPOS,6,3,{(actionf_p2)A_Pain},S_SPOS_RUN1,0,0},	// S_SPOS_PAIN2
    {SPR_SPOS,7,5,{NULL},S_SPOS_DIE2,0,0},	// S_SPOS_DIE1
    {SPR_SPOS,8,5,{(actionf_p2)A_Scream},S_SPOS_DIE3,0,0},	// S_SPOS_DIE2
    {SPR_SPOS,9,5,{(actionf_p2)A_Fall},S_SPOS_DIE4,0,0},	// S_SPOS_DIE3
    {SPR_SPOS,10,5,{NULL},S_SPOS_DIE5,0,0},	// S_SPOS_DIE4
    {SPR_SPOS,11,-1,{NULL},S_NULL,0,0},	// S_SPOS_DIE5
    {SPR_SPOS,12,5,{NULL},S_SPOS_XDIE2,0,0},	// S_SPOS_XDIE1
    {SPR_SPOS,13,5,{(actionf_p2)A_XScream},S_SPOS_XDIE3,0,0},	// S_SPOS_XDIE2
    {SPR_SPOS,14,5,{(actionf_p2)A_Fall},S_SPOS_XDIE4,0,0},	// S_SPOS_XDIE3
    {SPR_SPOS,15,5,{NULL},S_SPOS_XDIE5,0,0},	// S_SPOS_XDIE4
    {SPR_SPOS,16,5,{NULL},S_SPOS_XDIE6,0,0},	// S_SPOS_XDIE5
    {SPR_SPOS,17,5,{NULL},S_SPOS_XDIE7,0,0},	// S_SPOS_XDIE6
    {SPR_SPOS,18,5,{NULL},S_SPOS_XDIE8,0,0},	// S_SPOS_XDIE7
    {SPR_SPOS,19,5,{NULL},S_SPOS_XDIE9,0,0},	// S_SPOS_XDIE8
    {SPR_SPOS,20,-1,{NULL},S_NULL,0,0},	// S_SPOS_XDIE9
    {SPR_SPOS,11,5,{NULL},S_SPOS_RAISE2,0,0},	// S_SPOS_RAISE1
    {SPR_SPOS,10,5,{NULL},S_SPOS_RAISE3,0,0},	// S_SPOS_RAISE2
    {SPR_SPOS,9,5,{NULL},S_SPOS_RAISE4,0,0},	// S_SPOS_RAISE3
    {SPR_SPOS,8,5,{NULL},S_SPOS_RAISE5,0,0},	// S_SPOS_RAISE4
    {SPR_SPOS,7,5,{NULL},S_SPOS_RUN1,0,0},	// S_SPOS_RAISE5
    {SPR_VILE,0,10,{(actionf_p2)A_Look},S_VILE_STND2,0,0},	// S_VILE_STND
    {SPR_VILE,1,10,{(actionf_p2)A_Look},S_VILE_STND,0,0},	// S_VILE_STND2
    {SPR_VILE,0,2,{(actionf_p2)A_VileChase},S_VILE_RUN2,0,0},	// S_VILE_RUN1
    {SPR_VILE,0,2,{(actionf_p2)A_VileChase},S_VILE_RUN3,0,0},	// S_VILE_RUN2
    {SPR_VILE,1,2,{(actionf_p2)A_VileChase},S_VILE_RUN4,0,0},	// S_VILE_RUN3
    {SPR_VILE,1,2,{(actionf_p2)A_VileChase},S_VILE_RUN5,0,0},	// S_VILE_RUN4
    {SPR_VILE,2,2,{(actionf_p2)A_VileChase},S_VILE_RUN6,0,0},	// S_VILE_RUN5
    {SPR_VILE,2,2,{(actionf_p2)A_VileChase},S_VILE_RUN7,0,0},	// S_VILE_RUN6
    {SPR_VILE,3,2,{(actionf_p2)A_VileChase},S_VILE_RUN8,0,0},	// S_VILE_RUN7
    {SPR_VILE,3,2,{(actionf_p2)A_VileChase},S_VILE_RUN9,0,0},	// S_VILE_RUN8
    {SPR_VILE,4,2,{(actionf_p2)A_VileChase},S_VILE_RUN10,0,0},	// S_VILE_RUN9
    {SPR_VILE,4,2,{(actionf_p2)A_VileChase},S_VILE_RUN11,0,0},	// S_VILE_RUN10
    {SPR_VILE,5,2,{(actionf_p2)A_VileChase},S_VILE_RUN12,0,0},	// S_VILE_RUN11
    {SPR_VILE,5,2,{(actionf_p2)A_VileChase},S_VILE_RUN1,0,0},	// S_VILE_RUN12
    {SPR_VILE,32774,0,{(actionf_p2)A_VileStart},S_VILE_ATK2,0,0},	// S_VILE_ATK1
    {SPR_VILE,32774,10,{(actionf_p2)A_FaceTarget},S_VILE_ATK3,0,0},	// S_VILE_ATK2
    {SPR_VILE,32775,8,{(actionf_p2)A_VileTarget},S_VILE_ATK4,0,0},	// S_VILE_ATK3
    {SPR_VILE,32776,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK5,0,0},	// S_VILE_ATK4
    {SPR_VILE,32777,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK6,0,0},	// S_VILE_ATK5
    {SPR_VILE,32778,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK7,0,0},	// S_VILE_ATK6
    {SPR_VILE,32779,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK8,0,0},	// S_VILE_ATK7
    {SPR_VILE,32780,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK9,0,0},	// S_VILE_ATK8
    {SPR_VILE,32781,8,{(actionf_p2)A_FaceTarget},S_VILE_ATK10,0,0},	// S_VILE_ATK9
    {SPR_VILE,32782,8,{(actionf_p2)A_VileAttack},S_VILE_ATK11,0,0},	// S_VILE_ATK10
    {SPR_VILE,32783,20,{NULL},S_VILE_RUN1,0,0},	// S_VILE_ATK11
    {SPR_VILE,32794,10,{NULL},S_VILE_HEAL2,0,0},	// S_VILE_HEAL1
    {SPR_VILE,32795,10,{NULL},S_VILE_HEAL3,0,0},	// S_VILE_HEAL2
    {SPR_VILE,32796,10,{NULL},S_VILE_RUN1,0,0},	// S_VILE_HEAL3
    {SPR_VILE,16,5,{NULL},S_VILE_PAIN2,0,0},	// S_VILE_PAIN
    {SPR_VILE,16,5,{(actionf_p2)A_Pain},S_VILE_RUN1,0,0},	// S_VILE_PAIN2
    {SPR_VILE,16,7,{NULL},S_VILE_DIE2,0,0},	// S_VILE_DIE1
    {SPR_VILE,17,7,{(actionf_p2)A_Scream},S_VILE_DIE3,0,0},	// S_VILE_DIE2
    {SPR_VILE,18,7,{(actionf_p2)A_Fall},S_VILE_DIE4,0,0},	// S_VILE_DIE3
    {SPR_VILE,19,7,{NULL},S_VILE_DIE5,0,0},	// S_VILE_DIE4
    {SPR_VILE,20,7,{NULL},S_VILE_DIE6,0,0},	// S_VILE_DIE5
    {SPR_VILE,21,7,{NULL},S_VILE_DIE7,0,0},	// S_VILE_DIE6
    {SPR_VILE,22,7,{NULL},S_VILE_DIE8,0,0},	// S_VILE_DIE7
    {SPR_VILE,23,5,{NULL},S_VILE_DIE9,0,0},	// S_VILE_DIE8
    {SPR_VILE,24,5,{NULL},S_VILE_DIE10,0,0},	// S_VILE_DIE9
    {SPR_VILE,25,-1,{NULL},S_NULL,0,0},	// S_VILE_DIE10
    {SPR_FIRE,32768,2,{(actionf_p2)A_StartFire},S_FIRE2,0,0},	// S_FIRE1
    {SPR_FIRE,32769,2,{(actionf_p2)A_Fire},S_FIRE3,0,0},	// S_FIRE2
    {SPR_FIRE,32768,2,{(actionf_p2)A_Fire},S_FIRE4,0,0},	// S_FIRE3
    {SPR_FIRE,32769,2,{(actionf_p2)A_Fire},S_FIRE5,0,0},	// S_FIRE4
    {SPR_FIRE,32770,2,{(actionf_p2)A_FireCrackle},S_FIRE6,0,0},	// S_FIRE5
    {SPR_FIRE,32769,2,{(actionf_p2)A_Fire},S_FIRE7,0,0},	// S_FIRE6
    {SPR_FIRE,32770,2,{(actionf_p2)A_Fire},S_FIRE8,0,0},	// S_FIRE7
    {SPR_FIRE,32769,2,{(actionf_p2)A_Fire},S_FIRE9,0,0},	// S_FIRE8
    {SPR_FIRE,32770,2,{(actionf_p2)A_Fire},S_FIRE10,0,0},	// S_FIRE9
    {SPR_FIRE,32771,2,{(actionf_p2)A_Fire},S_FIRE11,0,0},	// S_FIRE10
    {SPR_FIRE,32770,2,{(actionf_p2)A_Fire},S_FIRE12,0,0},	// S_FIRE11
    {SPR_FIRE,32771,2,{(actionf_p2)A_Fire},S_FIRE13,0,0},	// S_FIRE12
    {SPR_FIRE,32770,2,{(actionf_p2)A_Fire},S_FIRE14,0,0},	// S_FIRE13
    {SPR_FIRE,32771,2,{(actionf_p2)A_Fire},S_FIRE15,0,0},	// S_FIRE14
    {SPR_FIRE,32772,2,{(actionf_p2)A_Fire},S_FIRE16,0,0},	// S_FIRE15
    {SPR_FIRE,32771,2,{(actionf_p2)A_Fire},S_FIRE17,0,0},	// S_FIRE16
    {SPR_FIRE,32772,2,{(actionf_p2)A_Fire},S_FIRE18,0,0},	// S_FIRE17
    {SPR_FIRE,32771,2,{(actionf_p2)A_Fire},S_FIRE19,0,0},	// S_FIRE18
    {SPR_FIRE,32772,2,{(actionf_p2)A_FireCrackle},S_FIRE20,0,0},	// S_FIRE19
    {SPR_FIRE,32773,2,{(actionf_p2)A_Fire},S_FIRE21,0,0},	// S_FIRE20
    {SPR_FIRE,32772,2,{(actionf_p2)A_Fire},S_FIRE22,0,0},	// S_FIRE21
    {SPR_FIRE,32773,2,{(actionf_p2)A_Fire},S_FIRE23,0,0},	// S_FIRE22
    {SPR_FIRE,32772,2,{(actionf_p2)A_Fire},S_FIRE24,0,0},	// S_FIRE23
    {SPR_FIRE,32773,2,{(actionf_p2)A_Fire},S_FIRE25,0,0},	// S_FIRE24
    {SPR_FIRE,32774,2,{(actionf_p2)A_Fire},S_FIRE26,0,0},	// S_FIRE25
    {SPR_FIRE,32775,2,{(actionf_p2)A_Fire},S_FIRE27,0,0},	// S_FIRE26
    {SPR_FIRE,32774,2,{(actionf_p2)A_Fire},S_FIRE28,0,0},	// S_FIRE27
    {SPR_FIRE,32775,2,{(actionf_p2)A_Fire},S_FIRE29,0,0},	// S_FIRE28
    {SPR_FIRE,32774,2,{(actionf_p2)A_Fire},S_FIRE30,0,0},	// S_FIRE29
    {SPR_FIRE,32775,2,{(actionf_p2)A_Fire},S_NULL,0,0},	// S_FIRE30
    {SPR_PUFF,1,4,{NULL},S_SMOKE2,0,0},	// S_SMOKE1
    {SPR_PUFF,2,4,{NULL},S_SMOKE3,0,0},	// S_SMOKE2
    {SPR_PUFF,1,4,{NULL},S_SMOKE4,0,0},	// S_SMOKE3
    {SPR_PUFF,2,4,{NULL},S_SMOKE5,0,0},	// S_SMOKE4
    {SPR_PUFF,3,4,{NULL},S_NULL,0,0},	// S_SMOKE5
    {SPR_FATB,32768,2,{(actionf_p2)A_Tracer},S_TRACER2,0,0},	// S_TRACER
    {SPR_FATB,32769,2,{(actionf_p2)A_Tracer},S_TRACER,0,0},	// S_TRACER2
    {SPR_FBXP,32768,8,{NULL},S_TRACEEXP2,0,0},	// S_TRACEEXP1
    {SPR_FBXP,32769,6,{NULL},S_TRACEEXP3,0,0},	// S_TRACEEXP2
    {SPR_FBXP,32770,4,{NULL},S_NULL,0,0},	// S_TRACEEXP3
    {SPR_SKEL,0,10,{(actionf_p2)A_Look},S_SKEL_STND2,0,0},	// S_SKEL_STND
    {SPR_SKEL,1,10,{(actionf_p2)A_Look},S_SKEL_STND,0,0},	// S_SKEL_STND2
    {SPR_SKEL,0,2,{(actionf_p2)A_Chase},S_SKEL_RUN2,0,0},	// S_SKEL_RUN1
    {SPR_SKEL,0,2,{(actionf_p2)A_Chase},S_SKEL_RUN3,0,0},	// S_SKEL_RUN2
    {SPR_SKEL,1,2,{(actionf_p2)A_Chase},S_SKEL_RUN4,0,0},	// S_SKEL_RUN3
    {SPR_SKEL,1,2,{(actionf_p2)A_Chase},S_SKEL_RUN5,0,0},	// S_SKEL_RUN4
    {SPR_SKEL,2,2,{(actionf_p2)A_Chase},S_SKEL_RUN6,0,0},	// S_SKEL_RUN5
    {SPR_SKEL,2,2,{(actionf_p2)A_Chase},S_SKEL_RUN7,0,0},	// S_SKEL_RUN6
    {SPR_SKEL,3,2,{(actionf_p2)A_Chase},S_SKEL_RUN8,0,0},	// S_SKEL_RUN7
    {SPR_SKEL,3,2,{(actionf_p2)A_Chase},S_SKEL_RUN9,0,0},	// S_SKEL_RUN8
    {SPR_SKEL,4,2,{(actionf_p2)A_Chase},S_SKEL_RUN10,0,0},	// S_SKEL_RUN9
    {SPR_SKEL,4,2,{(actionf_p2)A_Chase},S_SKEL_RUN11,0,0},	// S_SKEL_RUN10
    {SPR_SKEL,5,2,{(actionf_p2)A_Chase},S_SKEL_RUN12,0,0},	// S_SKEL_RUN11
    {SPR_SKEL,5,2,{(actionf_p2)A_Chase},S_SKEL_RUN1,0,0},	// S_SKEL_RUN12
    {SPR_SKEL,6,0,{(actionf_p2)A_FaceTarget},S_SKEL_FIST2,0,0},	// S_SKEL_FIST1
    {SPR_SKEL,6,6,{(actionf_p2)A_SkelWhoosh},S_SKEL_FIST3,0,0},	// S_SKEL_FIST2
    {SPR_SKEL,7,6,{(actionf_p2)A_FaceTarget},S_SKEL_FIST4,0,0},	// S_SKEL_FIST3
    {SPR_SKEL,8,6,{(actionf_p2)A_SkelFist},S_SKEL_RUN1,0,0},	// S_SKEL_FIST4
    {SPR_SKEL,32777,0,{(actionf_p2)A_FaceTarget},S_SKEL_MISS2,0,0},	// S_SKEL_MISS1
    {SPR_SKEL,32777,10,{(actionf_p2)A_FaceTarget},S_SKEL_MISS3,0,0},	// S_SKEL_MISS2
    {SPR_SKEL,10,10,{(actionf_p2)A_SkelMissile},S_SKEL_MISS4,0,0},	// S_SKEL_MISS3
    {SPR_SKEL,10,10,{(actionf_p2)A_FaceTarget},S_SKEL_RUN1,0,0},	// S_SKEL_MISS4
    {SPR_SKEL,11,5,{NULL},S_SKEL_PAIN2,0,0},	// S_SKEL_PAIN
    {SPR_SKEL,11,5,{(actionf_p2)A_Pain},S_SKEL_RUN1,0,0},	// S_SKEL_PAIN2
    {SPR_SKEL,11,7,{NULL},S_SKEL_DIE2,0,0},	// S_SKEL_DIE1
    {SPR_SKEL,12,7,{NULL},S_SKEL_DIE3,0,0},	// S_SKEL_DIE2
    {SPR_SKEL,13,7,{(actionf_p2)A_Scream},S_SKEL_DIE4,0,0},	// S_SKEL_DIE3
    {SPR_SKEL,14,7,{(actionf_p2)A_Fall},S_SKEL_DIE5,0,0},	// S_SKEL_DIE4
    {SPR_SKEL,15,7,{NULL},S_SKEL_DIE6,0,0},	// S_SKEL_DIE5
    {SPR_SKEL,16,-1,{NULL},S_NULL,0,0},	// S_SKEL_DIE6
    {SPR_SKEL,16,5,{NULL},S_SKEL_RAISE2,0,0},	// S_SKEL_RAISE1
    {SPR_SKEL,15,5,{NULL},S_SKEL_RAISE3,0,0},	// S_SKEL_RAISE2
    {SPR_SKEL,14,5,{NULL},S_SKEL_RAISE4,0,0},	// S_SKEL_RAISE3
    {SPR_SKEL,13,5,{NULL},S_SKEL_RAISE5,0,0},	// S_SKEL_RAISE4
    {SPR_SKEL,12,5,{NULL},S_SKEL_RAISE6,0,0},	// S_SKEL_RAISE5
    {SPR_SKEL,11,5,{NULL},S_SKEL_RUN1,0,0},	// S_SKEL_RAISE6
    {SPR_MANF,32768,4,{NULL},S_FATSHOT2,0,0},	// S_FATSHOT1
    {SPR_MANF,32769,4,{NULL},S_FATSHOT1,0,0},	// S_FATSHOT2
    {SPR_MISL,32769,8,{NULL},S_FATSHOTX2,0,0},	// S_FATSHOTX1
    {SPR_MISL,32770,6,{NULL},S_FATSHOTX3,0,0},	// S_FATSHOTX2
    {SPR_MISL,32771,4,{NULL},S_NULL,0,0},	// S_FATSHOTX3
    {SPR_FATT,0,15,{(actionf_p2)A_Look},S_FATT_STND2,0,0},	// S_FATT_STND
    {SPR_FATT,1,15,{(actionf_p2)A_Look},S_FATT_STND,0,0},	// S_FATT_STND2
    {SPR_FATT,0,4,{(actionf_p2)A_Chase},S_FATT_RUN2,0,0},	// S_FATT_RUN1
    {SPR_FATT,0,4,{(actionf_p2)A_Chase},S_FATT_RUN3,0,0},	// S_FATT_RUN2
    {SPR_FATT,1,4,{(actionf_p2)A_Chase},S_FATT_RUN4,0,0},	// S_FATT_RUN3
    {SPR_FATT,1,4,{(actionf_p2)A_Chase},S_FATT_RUN5,0,0},	// S_FATT_RUN4
    {SPR_FATT,2,4,{(actionf_p2)A_Chase},S_FATT_RUN6,0,0},	// S_FATT_RUN5
    {SPR_FATT,2,4,{(actionf_p2)A_Chase},S_FATT_RUN7,0,0},	// S_FATT_RUN6
    {SPR_FATT,3,4,{(actionf_p2)A_Chase},S_FATT_RUN8,0,0},	// S_FATT_RUN7
    {SPR_FATT,3,4,{(actionf_p2)A_Chase},S_FATT_RUN9,0,0},	// S_FATT_RUN8
    {SPR_FATT,4,4,{(actionf_p2)A_Chase},S_FATT_RUN10,0,0},	// S_FATT_RUN9
    {SPR_FATT,4,4,{(actionf_p2)A_Chase},S_FATT_RUN11,0,0},	// S_FATT_RUN10
    {SPR_FATT,5,4,{(actionf_p2)A_Chase},S_FATT_RUN12,0,0},	// S_FATT_RUN11
    {SPR_FATT,5,4,{(actionf_p2)A_Chase},S_FATT_RUN1,0,0},	// S_FATT_RUN12
    {SPR_FATT,6,20,{(actionf_p2)A_FatRaise},S_FATT_ATK2,0,0},	// S_FATT_ATK1
    {SPR_FATT,32775,10,{(actionf_p2)A_FatAttack1},S_FATT_ATK3,0,0},	// S_FATT_ATK2
    {SPR_FATT,8,5,{(actionf_p2)A_FaceTarget},S_FATT_ATK4,0,0},	// S_FATT_ATK3
    {SPR_FATT,6,5,{(actionf_p2)A_FaceTarget},S_FATT_ATK5,0,0},	// S_FATT_ATK4
    {SPR_FATT,32775,10,{(actionf_p2)A_FatAttack2},S_FATT_ATK6,0,0},	// S_FATT_ATK5
    {SPR_FATT,8,5,{(actionf_p2)A_FaceTarget},S_FATT_ATK7,0,0},	// S_FATT_ATK6
    {SPR_FATT,6,5,{(actionf_p2)A_FaceTarget},S_FATT_ATK8,0,0},	// S_FATT_ATK7
    {SPR_FATT,32775,10,{(actionf_p2)A_FatAttack3},S_FATT_ATK9,0,0},	// S_FATT_ATK8
    {SPR_FATT,8,5,{(actionf_p2)A_FaceTarget},S_FATT_ATK10,0,0},	// S_FATT_ATK9
    {SPR_FATT,6,5,{(actionf_p2)A_FaceTarget},S_FATT_RUN1,0,0},	// S_FATT_ATK10
    {SPR_FATT,9,3,{NULL},S_FATT_PAIN2,0,0},	// S_FATT_PAIN
    {SPR_FATT,9,3,{(actionf_p2)A_Pain},S_FATT_RUN1,0,0},	// S_FATT_PAIN2
    {SPR_FATT,10,6,{NULL},S_FATT_DIE2,0,0},	// S_FATT_DIE1
    {SPR_FATT,11,6,{(actionf_p2)A_Scream},S_FATT_DIE3,0,0},	// S_FATT_DIE2
    {SPR_FATT,12,6,{(actionf_p2)A_Fall},S_FATT_DIE4,0,0},	// S_FATT_DIE3
    {SPR_FATT,13,6,{NULL},S_FATT_DIE5,0,0},	// S_FATT_DIE4
    {SPR_FATT,14,6,{NULL},S_FATT_DIE6,0,0},	// S_FATT_DIE5
    {SPR_FATT,15,6,{NULL},S_FATT_DIE7,0,0},	// S_FATT_DIE6
    {SPR_FATT,16,6,{NULL},S_FATT_DIE8,0,0},	// S_FATT_DIE7
    {SPR_FATT,17,6,{NULL},S_FATT_DIE9,0,0},	// S_FATT_DIE8
    {SPR_FATT,18,6,{NULL},S_FATT_DIE10,0,0},	// S_FATT_DIE9
    {SPR_FATT,19,-1,{(actionf_p2)A_BossDeath},S_NULL,0,0},	// S_FATT_DIE10
    {SPR_FATT,17,5,{NULL},S_FATT_RAISE2,0,0},	// S_FATT_RAISE1
    {SPR_FATT,16,5,{NULL},S_FATT_RAISE3,0,0},	// S_FATT_RAISE2
    {SPR_FATT,15,5,{NULL},S_FATT_RAISE4,0,0},	// S_FATT_RAISE3
    {SPR_FATT,14,5,{NULL},S_FATT_RAISE5,0,0},	// S_FATT_RAISE4
    {SPR_FATT,13,5,{NULL},S_FATT_RAISE6,0,0},	// S_FATT_RAISE5
    {SPR_FATT,12,5,{NULL},S_FATT_RAISE7,0,0},	// S_FATT_RAISE6
    {SPR_FATT,11,5,{NULL},S_FATT_RAISE8,0,0},	// S_FATT_RAISE7
    {SPR_FATT,10,5,{NULL},S_FATT_RUN1,0,0},	// S_FATT_RAISE8
    {SPR_CPOS,0,10,{(actionf_p2)A_Look},S_CPOS_STND2,0,0},	// S_CPOS_STND
    {SPR_CPOS,1,10,{(actionf_p2)A_Look},S_CPOS_STND,0,0},	// S_CPOS_STND2
    {SPR_CPOS,0,3,{(actionf_p2)A_Chase},S_CPOS_RUN2,0,0},	// S_CPOS_RUN1
    {SPR_CPOS,0,3,{(actionf_p2)A_Chase},S_CPOS_RUN3,0,0},	// S_CPOS_RUN2
    {SPR_CPOS,1,3,{(actionf_p2)A_Chase},S_CPOS_RUN4,0,0},	// S_CPOS_RUN3
    {SPR_CPOS,1,3,{(actionf_p2)A_Chase},S_CPOS_RUN5,0,0},	// S_CPOS_RUN4
    {SPR_CPOS,2,3,{(actionf_p2)A_Chase},S_CPOS_RUN6,0,0},	// S_CPOS_RUN5
    {SPR_CPOS,2,3,{(actionf_p2)A_Chase},S_CPOS_RUN7,0,0},	// S_CPOS_RUN6
    {SPR_CPOS,3,3,{(actionf_p2)A_Chase},S_CPOS_RUN8,0,0},	// S_CPOS_RUN7
    {SPR_CPOS,3,3,{(actionf_p2)A_Chase},S_CPOS_RUN1,0,0},	// S_CPOS_RUN8
    {SPR_CPOS,4,10,{(actionf_p2)A_FaceTarget},S_CPOS_ATK2,0,0},	// S_CPOS_ATK1
    {SPR_CPOS,32773,4,{(actionf_p2)A_CPosAttack},S_CPOS_ATK3,0,0},	// S_CPOS_ATK2
    {SPR_CPOS,32772,4,{(actionf_p2)A_CPosAttack},S_CPOS_ATK4,0,0},	// S_CPOS_ATK3
    {SPR_CPOS,5,1,{(actionf_p2)A_CPosRefire},S_CPOS_ATK2,0,0},	// S_CPOS_ATK4
    {SPR_CPOS,6,3,{NULL},S_CPOS_PAIN2,0,0},	// S_CPOS_PAIN
    {SPR_CPOS,6,3,{(actionf_p2)A_Pain},S_CPOS_RUN1,0,0},	// S_CPOS_PAIN2
    {SPR_CPOS,7,5,{NULL},S_CPOS_DIE2,0,0},	// S_CPOS_DIE1
    {SPR_CPOS,8,5,{(actionf_p2)A_Scream},S_CPOS_DIE3,0,0},	// S_CPOS_DIE2
    {SPR_CPOS,9,5,{(actionf_p2)A_Fall},S_CPOS_DIE4,0,0},	// S_CPOS_DIE3
    {SPR_CPOS,10,5,{NULL},S_CPOS_DIE5,0,0},	// S_CPOS_DIE4
    {SPR_CPOS,11,5,{NULL},S_CPOS_DIE6,0,0},	// S_CPOS_DIE5
    {SPR_CPOS,12,5,{NULL},S_CPOS_DIE7,0,0},	// S_CPOS_DIE6
    {SPR_CPOS,13,-1,{NULL},S_NULL,0,0},	// S_CPOS_DIE7
    {SPR_CPOS,14,5,{NULL},S_CPOS_XDIE2,0,0},	// S_CPOS_XDIE1
    {SPR_CPOS,15,5,{(actionf_p2)A_XScream},S_CPOS_XDIE3,0,0},	// S_CPOS_XDIE2
    {SPR_CPOS,16,5,{(actionf_p2)A_Fall},S_CPOS_XDIE4,0,0},	// S_CPOS_XDIE3
    {SPR_CPOS,17,5,{NULL},S_CPOS_XDIE5,0,0},	// S_CPOS_XDIE4
    {SPR_CPOS,18,5,{NULL},S_CPOS_XDIE6,0,0},	// S_CPOS_XDIE5
    {SPR_CPOS,19,-1,{NULL},S_NULL,0,0},	// S_CPOS_XDIE6
    {SPR_CPOS,13,5,{NULL},S_CPOS_RAISE2,0,0},	// S_CPOS_RAISE1
    {SPR_CPOS,12,5,{NULL},S_CPOS_RAISE3,0,0},	// S_CPOS_RAISE2
    {SPR_CPOS,11,5,{NULL},S_CPOS_RAISE4,0,0},	// S_CPOS_RAISE3
    {SPR_CPOS,10,5,{NULL},S_CPOS_RAISE5,0,0},	// S_CPOS_RAISE4
    {SPR_CPOS,9,5,{NULL},S_CPOS_RAISE6,0,0},	// S_CPOS_RAISE5
    {SPR_CPOS,8,5,{NULL},S_CPOS_RAISE7,0,0},	// S_CPOS_RAISE6
    {SPR_CPOS,7,5,{NULL},S_CPOS_RUN1,0,0},	// S_CPOS_RAISE7
    {SPR_TROO,0,10,{(actionf_p2)A_Look},S_TROO_STND2,0,0},	// S_TROO_STND
    {SPR_TROO,1,10,{(actionf_p2)A_Look},S_TROO_STND,0,0},	// S_TROO_STND2
    {SPR_TROO,0,3,{(actionf_p2)A_Chase},S_TROO_RUN2,0,0},	// S_TROO_RUN1
    {SPR_TROO,0,3,{(actionf_p2)A_Chase},S_TROO_RUN3,0,0},	// S_TROO_RUN2
    {SPR_TROO,1,3,{(actionf_p2)A_Chase},S_TROO_RUN4,0,0},	// S_TROO_RUN3
    {SPR_TROO,1,3,{(actionf_p2)A_Chase},S_TROO_RUN5,0,0},	// S_TROO_RUN4
    {SPR_TROO,2,3,{(actionf_p2)A_Chase},S_TROO_RUN6,0,0},	// S_TROO_RUN5
    {SPR_TROO,2,3,{(actionf_p2)A_Chase},S_TROO_RUN7,0,0},	// S_TROO_RUN6
    {SPR_TROO,3,3,{(actionf_p2)A_Chase},S_TROO_RUN8,0,0},	// S_TROO_RUN7
    {SPR_TROO,3,3,{(actionf_p2)A_Chase},S_TROO_RUN1,0,0},	// S_TROO_RUN8
    {SPR_TROO,4,8,{(actionf_p2)A_FaceTarget},S_TROO_ATK2,0,0},	// S_TROO_ATK1
    {SPR_TROO,5,8,{(actionf_p2)A_FaceTarget},S_TROO_ATK3,0,0},	// S_TROO_ATK2
    {SPR_TROO,6,6,{(actionf_p2)A_TroopAttack},S_TROO_RUN1,0,0},	// S_TROO_ATK3
    {SPR_TROO,7,2,{NULL},S_TROO_PAIN2,0,0},	// S_TROO_PAIN
    {SPR_TROO,7,2,{(actionf_p2)A_Pain},S_TROO_RUN1,0,0},	// S_TROO_PAIN2
    {SPR_TROO,8,8,{NULL},S_TROO_DIE2,0,0},	// S_TROO_DIE1
    {SPR_TROO,9,8,{(actionf_p2)A_Scream},S_TROO_DIE3,0,0},	// S_TROO_DIE2
    {SPR_TROO,10,6,{NULL},S_TROO_DIE4,0,0},	// S_TROO_DIE3
    {SPR_TROO,11,6,{(actionf_p2)A_Fall},S_TROO_DIE5,0,0},	// S_TROO_DIE4
    {SPR_TROO,12,-1,{NULL},S_NULL,0,0},	// S_TROO_DIE5
    {SPR_TROO,13,5,{NULL},S_TROO_XDIE2,0,0},	// S_TROO_XDIE1
    {SPR_TROO,14,5,{(actionf_p2)A_XScream},S_TROO_XDIE3,0,0},	// S_TROO_XDIE2
    {SPR_TROO,15,5,{NULL},S_TROO_XDIE4,0,0},	// S_TROO_XDIE3
    {SPR_TROO,16,5,{(actionf_p2)A_Fall},S_TROO_XDIE5,0,0},	// S_TROO_XDIE4
    {SPR_TROO,17,5,{NULL},S_TROO_XDIE6,0,0},	// S_TROO_XDIE5
    {SPR_TROO,18,5,{NULL},S_TROO_XDIE7,0,0},	// S_TROO_XDIE6
    {SPR_TROO,19,5,{NULL},S_TROO_XDIE8,0,0},	// S_TROO_XDIE7
    {SPR_TROO,20,-1,{NULL},S_NULL,0,0},	// S_TROO_XDIE8
    {SPR_TROO,12,8,{NULL},S_TROO_RAISE2,0,0},	// S_TROO_RAISE1
    {SPR_TROO,11,8,{NULL},S_TROO_RAISE3,0,0},	// S_TROO_RAISE2
    {SPR_TROO,10,6,{NULL},S_TROO_RAISE4,0,0},	// S_TROO_RAISE3
    {SPR_TROO,9,6,{NULL},S_TROO_RAISE5,0,0},	// S_TROO_RAISE4
    {SPR_TROO,8,6,{NULL},S_TROO_RUN1,0,0},	// S_TROO_RAISE5
    {SPR_SARG,0,10,{(actionf_p2)A_Look},S_SARG_STND2,0,0},	// S_SARG_STND
    {SPR_SARG,1,10,{(actionf_p2)A_Look},S_SARG_STND,0,0},	// S_SARG_STND2
    {SPR_SARG,0,2,{(actionf_p2)A_Chase},S_SARG_RUN2,0,0},	// S_SARG_RUN1
    {SPR_SARG,0,2,{(actionf_p2)A_Chase},S_SARG_RUN3,0,0},	// S_SARG_RUN2
    {SPR_SARG,1,2,{(actionf_p2)A_Chase},S_SARG_RUN4,0,0},	// S_SARG_RUN3
    {SPR_SARG,1,2,{(actionf_p2)A_Chase},S_SARG_RUN5,0,0},	// S_SARG_RUN4
    {SPR_SARG,2,2,{(actionf_p2)A_Chase},S_SARG_RUN6,0,0},	// S_SARG_RUN5
    {SPR_SARG,2,2,{(actionf_p2)A_Chase},S_SARG_RUN7,0,0},	// S_SARG_RUN6
    {SPR_SARG,3,2,{(actionf_p2)A_Chase},S_SARG_RUN8,0,0},	// S_SARG_RUN7
    {SPR_SARG,3,2,{(actionf_p2)A_Chase},S_SARG_RUN1,0,0},	// S_SARG_RUN8
    {SPR_SARG,4,8,{(actionf_p2)A_FaceTarget},S_SARG_ATK2,0,0},	// S_SARG_ATK1
    {SPR_SARG,5,8,{(actionf_p2)A_FaceTarget},S_SARG_ATK3,0,0},	// S_SARG_ATK2
    {SPR_SARG,6,8,{(actionf_p2)A_SargAttack},S_SARG_RUN1,0,0},	// S_SARG_ATK3
    {SPR_SARG,7,2,{NULL},S_SARG_PAIN2,0,0},	// S_SARG_PAIN
    {SPR_SARG,7,2,{(actionf_p2)A_Pain},S_SARG_RUN1,0,0},	// S_SARG_PAIN2
    {SPR_SARG,8,8,{NULL},S_SARG_DIE2,0,0},	// S_SARG_DIE1
    {SPR_SARG,9,8,{(actionf_p2)A_Scream},S_SARG_DIE3,0,0},	// S_SARG_DIE2
    {SPR_SARG,10,4,{NULL},S_SARG_DIE4,0,0},	// S_SARG_DIE3
    {SPR_SARG,11,4,{(actionf_p2)A_Fall},S_SARG_DIE5,0,0},	// S_SARG_DIE4
    {SPR_SARG,12,4,{NULL},S_SARG_DIE6,0,0},	// S_SARG_DIE5
    {SPR_SARG,13,-1,{NULL},S_NULL,0,0},	// S_SARG_DIE6
    {SPR_SARG,13,5,{NULL},S_SARG_RAISE2,0,0},	// S_SARG_RAISE1
    {SPR_SARG,12,5,{NULL},S_SARG_RAISE3,0,0},	// S_SARG_RAISE2
    {SPR_SARG,11,5,{NULL},S_SARG_RAISE4,0,0},	// S_SARG_RAISE3
    {SPR_SARG,10,5,{NULL},S_SARG_RAISE5,0,0},	// S_SARG_RAISE4
    {SPR_SARG,9,5,{NULL},S_SARG_RAISE6,0,0},	// S_SARG_RAISE5
    {SPR_SARG,8,5,{NULL},S_SARG_RUN1,0,0},	// S_SARG_RAISE6
    {SPR_HEAD,0,10,{(actionf_p2)A_Look},S_HEAD_STND,0,0},	// S_HEAD_STND
    {SPR_HEAD,0,3,{(actionf_p2)A_Chase},S_HEAD_RUN1,0,0},	// S_HEAD_RUN1
    {SPR_HEAD,1,5,{(actionf_p2)A_FaceTarget},S_HEAD_ATK2,0,0},	// S_HEAD_ATK1
    {SPR_HEAD,2,5,{(actionf_p2)A_FaceTarget},S_HEAD_ATK3,0,0},	// S_HEAD_ATK2
    {SPR_HEAD,32771,5,{(actionf_p2)A_HeadAttack},S_HEAD_RUN1,0,0},	// S_HEAD_ATK3
    {SPR_HEAD,4,3,{NULL},S_HEAD_PAIN2,0,0},	// S_HEAD_PAIN
    {SPR_HEAD,4,3,{(actionf_p2)A_Pain},S_HEAD_PAIN3,0,0},	// S_HEAD_PAIN2
    {SPR_HEAD,5,6,{NULL},S_HEAD_RUN1,0,0},	// S_HEAD_PAIN3
    {SPR_HEAD,6,8,{NULL},S_HEAD_DIE2,0,0},	// S_HEAD_DIE1
    {SPR_HEAD,7,8,{(actionf_p2)A_Scream},S_HEAD_DIE3,0,0},	// S_HEAD_DIE2
    {SPR_HEAD,8,8,{NULL},S_HEAD_DIE4,0,0},	// S_HEAD_DIE3
    {SPR_HEAD,9,8,{NULL},S_HEAD_DIE5,0,0},	// S_HEAD_DIE4
    {SPR_HEAD,10,8,{(actionf_p2)A_Fall},S_HEAD_DIE6,0,0},	// S_HEAD_DIE5
    {SPR_HEAD,11,-1,{NULL},S_NULL,0,0},	// S_HEAD_DIE6
    {SPR_HEAD,11,8,{NULL},S_HEAD_RAISE2,0,0},	// S_HEAD_RAISE1
    {SPR_HEAD,10,8,{NULL},S_HEAD_RAISE3,0,0},	// S_HEAD_RAISE2
    {SPR_HEAD,9,8,{NULL},S_HEAD_RAISE4,0,0},	// S_HEAD_RAISE3
    {SPR_HEAD,8,8,{NULL},S_HEAD_RAISE5,0,0},	// S_HEAD_RAISE4
    {SPR_HEAD,7,8,{NULL},S_HEAD_RAISE6,0,0},	// S_HEAD_RAISE5
    {SPR_HEAD,6,8,{NULL},S_HEAD_RUN1,0,0},	// S_HEAD_RAISE6
    {SPR_BAL7,32768,4,{NULL},S_BRBALL2,0,0},	// S_BRBALL1
    {SPR_BAL7,32769,4,{NULL},S_BRBALL1,0,0},	// S_BRBALL2
    {SPR_BAL7,32770,6,{NULL},S_BRBALLX2,0,0},	// S_BRBALLX1
    {SPR_BAL7,32771,6,{NULL},S_BRBALLX3,0,0},	// S_BRBALLX2
    {SPR_BAL7,32772,6,{NULL},S_NULL,0,0},	// S_BRBALLX3
    {SPR_BOSS,0,10,{(actionf_p2)A_Look},S_BOSS_STND2,0,0},	// S_BOSS_STND
    {SPR_BOSS,1,10,{(actionf_p2)A_Look},S_BOSS_STND,0,0},	// S_BOSS_STND2
    {SPR_BOSS,0,3,{(actionf_p2)A_Chase},S_BOSS_RUN2,0,0},	// S_BOSS_RUN1
    {SPR_BOSS,0,3,{(actionf_p2)A_Chase},S_BOSS_RUN3,0,0},	// S_BOSS_RUN2
    {SPR_BOSS,1,3,{(actionf_p2)A_Chase},S_BOSS_RUN4,0,0},	// S_BOSS_RUN3
    {SPR_BOSS,1,3,{(actionf_p2)A_Chase},S_BOSS_RUN5,0,0},	// S_BOSS_RUN4
    {SPR_BOSS,2,3,{(actionf_p2)A_Chase},S_BOSS_RUN6,0,0},	// S_BOSS_RUN5
    {SPR_BOSS,2,3,{(actionf_p2)A_Chase},S_BOSS_RUN7,0,0},	// S_BOSS_RUN6
    {SPR_BOSS,3,3,{(actionf_p2)A_Chase},S_BOSS_RUN8,0,0},	// S_BOSS_RUN7
    {SPR_BOSS,3,3,{(actionf_p2)A_Chase},S_BOSS_RUN1,0,0},	// S_BOSS_RUN8
    {SPR_BOSS,4,8,{(actionf_p2)A_FaceTarget},S_BOSS_ATK2,0,0},	// S_BOSS_ATK1
    {SPR_BOSS,5,8,{(actionf_p2)A_FaceTarget},S_BOSS_ATK3,0,0},	// S_BOSS_ATK2
    {SPR_BOSS,6,8,{(actionf_p2)A_BruisAttack},S_BOSS_RUN1,0,0},	// S_BOSS_ATK3
    {SPR_BOSS,7,2,{NULL},S_BOSS_PAIN2,0,0},	// S_BOSS_PAIN
    {SPR_BOSS,7,2,{(actionf_p2)A_Pain},S_BOSS_RUN1,0,0},	// S_BOSS_PAIN2
    {SPR_BOSS,8,8,{NULL},S_BOSS_DIE2,0,0},	// S_BOSS_DIE1
    {SPR_BOSS,9,8,{(actionf_p2)A_Scream},S_BOSS_DIE3,0,0},	// S_BOSS_DIE2
    {SPR_BOSS,10,8,{NULL},S_BOSS_DIE4,0,0},	// S_BOSS_DIE3
    {SPR_BOSS,11,8,{(actionf_p2)A_Fall},S_BOSS_DIE5,0,0},	// S_BOSS_DIE4
    {SPR_BOSS,12,8,{NULL},S_BOSS_DIE6,0,0},	// S_BOSS_DIE5
    {SPR_BOSS,13,8,{NULL},S_BOSS_DIE7,0,0},	// S_BOSS_DIE6
    {SPR_BOSS,14,-1,{(actionf_p2)A_BossDeath},S_NULL,0,0},	// S_BOSS_DIE7
    {SPR_BOSS,14,8,{NULL},S_BOSS_RAISE2,0,0},	// S_BOSS_RAISE1
    {SPR_BOSS,13,8,{NULL},S_BOSS_RAISE3,0,0},	// S_BOSS_RAISE2
    {SPR_BOSS,12,8,{NULL},S_BOSS_RAISE4,0,0},	// S_BOSS_RAISE3
    {SPR_BOSS,11,8,{NULL},S_BOSS_RAISE5,0,0},	// S_BOSS_RAISE4
    {SPR_BOSS,10,8,{NULL},S_BOSS_RAISE6,0,0},	// S_BOSS_RAISE5
    {SPR_BOSS,9,8,{NULL},S_BOSS_RAISE7,0,0},	// S_BOSS_RAISE6
    {SPR_BOSS,8,8,{NULL},S_BOSS_RUN1,0,0},	// S_BOSS_RAISE7
    {SPR_BOS2,0,10,{(actionf_p2)A_Look},S_BOS2_STND2,0,0},	// S_BOS2_STND
    {SPR_BOS2,1,10,{(actionf_p2)A_Look},S_BOS2_STND,0,0},	// S_BOS2_STND2
    {SPR_BOS2,0,3,{(actionf_p2)A_Chase},S_BOS2_RUN2,0,0},	// S_BOS2_RUN1
    {SPR_BOS2,0,3,{(actionf_p2)A_Chase},S_BOS2_RUN3,0,0},	// S_BOS2_RUN2
    {SPR_BOS2,1,3,{(actionf_p2)A_Chase},S_BOS2_RUN4,0,0},	// S_BOS2_RUN3
    {SPR_BOS2,1,3,{(actionf_p2)A_Chase},S_BOS2_RUN5,0,0},	// S_BOS2_RUN4
    {SPR_BOS2,2,3,{(actionf_p2)A_Chase},S_BOS2_RUN6,0,0},	// S_BOS2_RUN5
    {SPR_BOS2,2,3,{(actionf_p2)A_Chase},S_BOS2_RUN7,0,0},	// S_BOS2_RUN6
    {SPR_BOS2,3,3,{(actionf_p2)A_Chase},S_BOS2_RUN8,0,0},	// S_BOS2_RUN7
    {SPR_BOS2,3,3,{(actionf_p2)A_Chase},S_BOS2_RUN1,0,0},	// S_BOS2_RUN8
    {SPR_BOS2,4,8,{(actionf_p2)A_FaceTarget},S_BOS2_ATK2,0,0},	// S_BOS2_ATK1
    {SPR_BOS2,5,8,{(actionf_p2)A_FaceTarget},S_BOS2_ATK3,0,0},	// S_BOS2_ATK2
    {SPR_BOS2,6,8,{(actionf_p2)A_BruisAttack},S_BOS2_RUN1,0,0},	// S_BOS2_ATK3
    {SPR_BOS2,7,2,{NULL},S_BOS2_PAIN2,0,0},	// S_BOS2_PAIN
    {SPR_BOS2,7,2,{(actionf_p2)A_Pain},S_BOS2_RUN1,0,0},	// S_BOS2_PAIN2
    {SPR_BOS2,8,8,{NULL},S_BOS2_DIE2,0,0},	// S_BOS2_DIE1
    {SPR_BOS2,9,8,{(actionf_p2)A_Scream},S_BOS2_DIE3,0,0},	// S_BOS2_DIE2
    {SPR_BOS2,10,8,{NULL},S_BOS2_DIE4,0,0},	// S_BOS2_DIE3
    {SPR_BOS2,11,8,{(actionf_p2)A_Fall},S_BOS2_DIE5,0,0},	// S_BOS2_DIE4
    {SPR_BOS2,12,8,{NULL},S_BOS2_DIE6,0,0},	// S_BOS2_DIE5
    {SPR_BOS2,13,8,{NULL},S_BOS2_DIE7,0,0},	// S_BOS2_DIE6
    {SPR_BOS2,14,-1,{NULL},S_NULL,0,0},	// S_BOS2_DIE7
    {SPR_BOS2,14,8,{NULL},S_BOS2_RAISE2,0,0},	// S_BOS2_RAISE1
    {SPR_BOS2,13,8,{NULL},S_BOS2_RAISE3,0,0},	// S_BOS2_RAISE2
    {SPR_BOS2,12,8,{NULL},S_BOS2_RAISE4,0,0},	// S_BOS2_RAISE3
    {SPR_BOS2,11,8,{NULL},S_BOS2_RAISE5,0,0},	// S_BOS2_RAISE4
    {SPR_BOS2,10,8,{NULL},S_BOS2_RAISE6,0,0},	// S_BOS2_RAISE5
    {SPR_BOS2,9,8,{NULL},S_BOS2_RAISE7,0,0},	// S_BOS2_RAISE6
    {SPR_BOS2,8,8,{NULL},S_BOS2_RUN1,0,0},	// S_BOS2_RAISE7
    {SPR_SKUL,32768,10,{(actionf_p2)A_Look},S_SKULL_STND2,0,0},	// S_SKULL_STND
    {SPR_SKUL,32769,10,{(actionf_p2)A_Look},S_SKULL_STND,0,0},	// S_SKULL_STND2
    {SPR_SKUL,32768,6,{(actionf_p2)A_Chase},S_SKULL_RUN2,0,0},	// S_SKULL_RUN1
    {SPR_SKUL,32769,6,{(actionf_p2)A_Chase},S_SKULL_RUN1,0,0},	// S_SKULL_RUN2
    {SPR_SKUL,32770,10,{(actionf_p2)A_FaceTarget},S_SKULL_ATK2,0,0},	// S_SKULL_ATK1
    {SPR_SKUL,32771,4,{(actionf_p2)A_SkullAttack},S_SKULL_ATK3,0,0},	// S_SKULL_ATK2
    {SPR_SKUL,32770,4,{NULL},S_SKULL_ATK4,0,0},	// S_SKULL_ATK3
    {SPR_SKUL,32771,4,{NULL},S_SKULL_ATK3,0,0},	// S_SKULL_ATK4
    {SPR_SKUL,32772,3,{NULL},S_SKULL_PAIN2,0,0},	// S_SKULL_PAIN
    {SPR_SKUL,32772,3,{(actionf_p2)A_Pain},S_SKULL_RUN1,0,0},	// S_SKULL_PAIN2
    {SPR_SKUL,32773,6,{NULL},S_SKULL_DIE2,0,0},	// S_SKULL_DIE1
    {SPR_SKUL,32774,6,{(actionf_p2)A_Scream},S_SKULL_DIE3,0,0},	// S_SKULL_DIE2
    {SPR_SKUL,32775,6,{NULL},S_SKULL_DIE4,0,0},	// S_SKULL_DIE3
    {SPR_SKUL,32776,6,{(actionf_p2)A_Fall},S_SKULL_DIE5,0,0},	// S_SKULL_DIE4
    {SPR_SKUL,9,6,{NULL},S_SKULL_DIE6,0,0},	// S_SKULL_DIE5
    {SPR_SKUL,10,6,{NULL},S_NULL,0,0},	// S_SKULL_DIE6
    {SPR_SPID,0,10,{(actionf_p2)A_Look},S_SPID_STND2,0,0},	// S_SPID_STND
    {SPR_SPID,1,10,{(actionf_p2)A_Look},S_SPID_STND,0,0},	// S_SPID_STND2
    {SPR_SPID,0,3,{(actionf_p2)A_Metal},S_SPID_RUN2,0,0},	// S_SPID_RUN1
    {SPR_SPID,0,3,{(actionf_p2)A_Chase},S_SPID_RUN3,0,0},	// S_SPID_RUN2
    {SPR_SPID,1,3,{(actionf_p2)A_Chase},S_SPID_RUN4,0,0},	// S_SPID_RUN3
    {SPR_SPID,1,3,{(actionf_p2)A_Chase},S_SPID_RUN5,0,0},	// S_SPID_RUN4
    {SPR_SPID,2,3,{(actionf_p2)A_Metal},S_SPID_RUN6,0,0},	// S_SPID_RUN5
    {SPR_SPID,2,3,{(actionf_p2)A_Chase},S_SPID_RUN7,0,0},	// S_SPID_RUN6
    {SPR_SPID,3,3,{(actionf_p2)A_Chase},S_SPID_RUN8,0,0},	// S_SPID_RUN7
    {SPR_SPID,3,3,{(actionf_p2)A_Chase},S_SPID_RUN9,0,0},	// S_SPID_RUN8
    {SPR_SPID,4,3,{(actionf_p2)A_Metal},S_SPID_RUN10,0,0},	// S_SPID_RUN9
    {SPR_SPID,4,3,{(actionf_p2)A_Chase},S_SPID_RUN11,0,0},	// S_SPID_RUN10
    {SPR_SPID,5,3,{(actionf_p2)A_Chase},S_SPID_RUN12,0,0},	// S_SPID_RUN11
    {SPR_SPID,5,3,{(actionf_p2)A_Chase},S_SPID_RUN1,0,0},	// S_SPID_RUN12
    {SPR_SPID,32768,20,{(actionf_p2)A_FaceTarget},S_SPID_ATK2,0,0},	// S_SPID_ATK1
    {SPR_SPID,32774,4,{(actionf_p2)A_SPosAttack},S_SPID_ATK3,0,0},	// S_SPID_ATK2
    {SPR_SPID,32775,4,{(actionf_p2)A_SPosAttack},S_SPID_ATK4,0,0},	// S_SPID_ATK3
    {SPR_SPID,32775,1,{(actionf_p2)A_SpidRefire},S_SPID_ATK2,0,0},	// S_SPID_ATK4
    {SPR_SPID,8,3,{NULL},S_SPID_PAIN2,0,0},	// S_SPID_PAIN
    {SPR_SPID,8,3,{(actionf_p2)A_Pain},S_SPID_RUN1,0,0},	// S_SPID_PAIN2
    {SPR_SPID,9,20,{(actionf_p2)A_Scream},S_SPID_DIE2,0,0},	// S_SPID_DIE1
    {SPR_SPID,10,10,{(actionf_p2)A_Fall},S_SPID_DIE3,0,0},	// S_SPID_DIE2
    {SPR_SPID,11,10,{NULL},S_SPID_DIE4,0,0},	// S_SPID_DIE3
    {SPR_SPID,12,10,{NULL},S_SPID_DIE5,0,0},	// S_SPID_DIE4
    {SPR_SPID,13,10,{NULL},S_SPID_DIE6,0,0},	// S_SPID_DIE5
    {SPR_SPID,14,10,{NULL},S_SPID_DIE7,0,0},	// S_SPID_DIE6
    {SPR_SPID,15,10,{NULL},S_SPID_DIE8,0,0},	// S_SPID_DIE7
    {SPR_SPID,16,10,{NULL},S_SPID_DIE9,0,0},	// S_SPID_DIE8
    {SPR_SPID,17,10,{NULL},S_SPID_DIE10,0,0},	// S_SPID_DIE9
    {SPR_SPID,18,30,{NULL},S_SPID_DIE11,0,0},	// S_SPID_DIE10
    {SPR_SPID,18,-1,{(actionf_p2)A_BossDeath},S_NULL,0,0},	// S_SPID_DIE11
    {SPR_BSPI,0,10,{(actionf_p2)A_Look},S_BSPI_STND2,0,0},	// S_BSPI_STND
    {SPR_BSPI,1,10,{(actionf_p2)A_Look},S_BSPI_STND,0,0},	// S_BSPI_STND2
    {SPR_BSPI,0,20,{NULL},S_BSPI_RUN1,0,0},	// S_BSPI_SIGHT
    {SPR_BSPI,0,3,{(actionf_p2)A_BabyMetal},S_BSPI_RUN2,0,0},	// S_BSPI_RUN1
    {SPR_BSPI,0,3,{(actionf_p2)A_Chase},S_BSPI_RUN3,0,0},	// S_BSPI_RUN2
    {SPR_BSPI,1,3,{(actionf_p2)A_Chase},S_BSPI_RUN4,0,0},	// S_BSPI_RUN3
    {SPR_BSPI,1,3,{(actionf_p2)A_Chase},S_BSPI_RUN5,0,0},	// S_BSPI_RUN4
    {SPR_BSPI,2,3,{(actionf_p2)A_Chase},S_BSPI_RUN6,0,0},	// S_BSPI_RUN5
    {SPR_BSPI,2,3,{(actionf_p2)A_Chase},S_BSPI_RUN7,0,0},	// S_BSPI_RUN6
    {SPR_BSPI,3,3,{(actionf_p2)A_BabyMetal},S_BSPI_RUN8,0,0},	// S_BSPI_RUN7
    {SPR_BSPI,3,3,{(actionf_p2)A_Chase},S_BSPI_RUN9,0,0},	// S_BSPI_RUN8
    {SPR_BSPI,4,3,{(actionf_p2)A_Chase},S_BSPI_RUN10,0,0},	// S_BSPI_RUN9
    {SPR_BSPI,4,3,{(actionf_p2)A_Chase},S_BSPI_RUN11,0,0},	// S_BSPI_RUN10
    {SPR_BSPI,5,3,{(actionf_p2)A_Chase},S_BSPI_RUN12,0,0},	// S_BSPI_RUN11
    {SPR_BSPI,5,3,{(actionf_p2)A_Chase},S_BSPI_RUN1,0,0},	// S_BSPI_RUN12
    {SPR_BSPI,32768,20,{(actionf_p2)A_FaceTarget},S_BSPI_ATK2,0,0},	// S_BSPI_ATK1
    {SPR_BSPI,32774,4,{(actionf_p2)A_BspiAttack},S_BSPI_ATK3,0,0},	// S_BSPI_ATK2
    {SPR_BSPI,32775,4,{NULL},S_BSPI_ATK4,0,0},	// S_BSPI_ATK3
    {SPR_BSPI,32775,1,{(actionf_p2)A_SpidRefire},S_BSPI_ATK2,0,0},	// S_BSPI_ATK4
    {SPR_BSPI,8,3,{NULL},S_BSPI_PAIN2,0,0},	// S_BSPI_PAIN
    {SPR_BSPI,8,3,{(actionf_p2)A_Pain},S_BSPI_RUN1,0,0},	// S_BSPI_PAIN2
    {SPR_BSPI,9,20,{(actionf_p2)A_Scream},S_BSPI_DIE2,0,0},	// S_BSPI_DIE1
    {SPR_BSPI,10,7,{(actionf_p2)A_Fall},S_BSPI_DIE3,0,0},	// S_BSPI_DIE2
    {SPR_BSPI,11,7,{NULL},S_BSPI_DIE4,0,0},	// S_BSPI_DIE3
    {SPR_BSPI,12,7,{NULL},S_BSPI_DIE5,0,0},	// S_BSPI_DIE4
    {SPR_BSPI,13,7,{NULL},S_BSPI_DIE6,0,0},	// S_BSPI_DIE5
    {SPR_BSPI,14,7,{NULL},S_BSPI_DIE7,0,0},	// S_BSPI_DIE6
    {SPR_BSPI,15,-1,{(actionf_p2)A_BossDeath},S_NULL,0,0},	// S_BSPI_DIE7
    {SPR_BSPI,15,5,{NULL},S_BSPI_RAISE2,0,0},	// S_BSPI_RAISE1
    {SPR_BSPI,14,5,{NULL},S_BSPI_RAISE3,0,0},	// S_BSPI_RAISE2
    {SPR_BSPI,13,5,{NULL},S_BSPI_RAISE4,0,0},	// S_BSPI_RAISE3
    {SPR_BSPI,12,5,{NULL},S_BSPI_RAISE5,0,0},	// S_BSPI_RAISE4
    {SPR_BSPI,11,5,{NULL},S_BSPI_RAISE6,0,0},	// S_BSPI_RAISE5
    {SPR_BSPI,10,5,{NULL},S_BSPI_RAISE7,0,0},	// S_BSPI_RAISE6
    {SPR_BSPI,9,5,{NULL},S_BSPI_RUN1,0,0},	// S_BSPI_RAISE7
    {SPR_APLS,32768,5,{NULL},S_ARACH_PLAZ2,0,0},	// S_ARACH_PLAZ
    {SPR_APLS,32769,5,{NULL},S_ARACH_PLAZ,0,0},	// S_ARACH_PLAZ2
    {SPR_APBX,32768,5,{NULL},S_ARACH_PLEX2,0,0},	// S_ARACH_PLEX
    {SPR_APBX,32769,5,{NULL},S_ARACH_PLEX3,0,0},	// S_ARACH_PLEX2
    {SPR_APBX,32770,5,{NULL},S_ARACH_PLEX4,0,0},	// S_ARACH_PLEX3
    {SPR_APBX,32771,5,{NULL},S_ARACH_PLEX5,0,0},	// S_ARACH_PLEX4
    {SPR_APBX,32772,5,{NULL},S_NULL,0,0},	// S_ARACH_PLEX5
    {SPR_CYBR,0,10,{(actionf_p2)A_Look},S_CYBER_STND2,0,0},	// S_CYBER_STND
    {SPR_CYBR,1,10,{(actionf_p2)A_Look},S_CYBER_STND,0,0},	// S_CYBER_STND2
    {SPR_CYBR,0,3,{(actionf_p2)A_Hoof},S_CYBER_RUN2,0,0},	// S_CYBER_RUN1
    {SPR_CYBR,0,3,{(actionf_p2)A_Chase},S_CYBER_RUN3,0,0},	// S_CYBER_RUN2
    {SPR_CYBR,1,3,{(actionf_p2)A_Chase},S_CYBER_RUN4,0,0},	// S_CYBER_RUN3
    {SPR_CYBR,1,3,{(actionf_p2)A_Chase},S_CYBER_RUN5,0,0},	// S_CYBER_RUN4
    {SPR_CYBR,2,3,{(actionf_p2)A_Chase},S_CYBER_RUN6,0,0},	// S_CYBER_RUN5
    {SPR_CYBR,2,3,{(actionf_p2)A_Chase},S_CYBER_RUN7,0,0},	// S_CYBER_RUN6
    {SPR_CYBR,3,3,{(actionf_p2)A_Metal},S_CYBER_RUN8,0,0},	// S_CYBER_RUN7
    {SPR_CYBR,3,3,{(actionf_p2)A_Chase},S_CYBER_RUN1,0,0},	// S_CYBER_RUN8
    {SPR_CYBR,4,6,{(actionf_p2)A_FaceTarget},S_CYBER_ATK2,0,0},	// S_CYBER_ATK1
    {SPR_CYBR,5,12,{(actionf_p2)A_CyberAttack},S_CYBER_ATK3,0,0},	// S_CYBER_ATK2
    {SPR_CYBR,4,12,{(actionf_p2)A_FaceTarget},S_CYBER_ATK4,0,0},	// S_CYBER_ATK3
    {SPR_CYBR,5,12,{(actionf_p2)A_CyberAttack},S_CYBER_ATK5,0,0},	// S_CYBER_ATK4
    {SPR_CYBR,4,12,{(actionf_p2)A_FaceTarget},S_CYBER_ATK6,0,0},	// S_CYBER_ATK5
    {SPR_CYBR,5,12,{(actionf_p2)A_CyberAttack},S_CYBER_RUN1,0,0},	// S_CYBER_ATK6
    {SPR_CYBR,6,10,{(actionf_p2)A_Pain},S_CYBER_RUN1,0,0},	// S_CYBER_PAIN
    {SPR_CYBR,7,10,{NULL},S_CYBER_DIE2,0,0},	// S_CYBER_DIE1
    {SPR_CYBR,8,10,{(actionf_p2)A_Scream},S_CYBER_DIE3,0,0},	// S_CYBER_DIE2
    {SPR_CYBR,9,10,{NULL},S_CYBER_DIE4,0,0},	// S_CYBER_DIE3
    {SPR_CYBR,10,10,{NULL},S_CYBER_DIE5,0,0},	// S_CYBER_DIE4
    {SPR_CYBR,11,10,{NULL},S_CYBER_DIE6,0,0},	// S_CYBER_DIE5
    {SPR_CYBR,12,10,{(actionf_p2)A_Fall},S_CYBER_DIE7,0,0},	// S_CYBER_DIE6
    {SPR_CYBR,13,10,{NULL},S_CYBER_DIE8,0,0},	// S_CYBER_DIE7
    {SPR_CYBR,14,10,{NULL},S_CYBER_DIE9,0,0},	// S_CYBER_DIE8
    {SPR_CYBR,15,30,{NULL},S_CYBER_DIE10,0,0},	// S_CYBER_DIE9
    {SPR_CYBR,15,-1,{(actionf_p2)A_BossDeath},S_NULL,0,0},	// S_CYBER_DIE10
    {SPR_PAIN,0,10,{(actionf_p2)A_Look},S_PAIN_STND,0,0},	// S_PAIN_STND
    {SPR_PAIN,0,3,{(actionf_p2)A_Chase},S_PAIN_RUN2,0,0},	// S_PAIN_RUN1
    {SPR_PAIN,0,3,{(actionf_p2)A_Chase},S_PAIN_RUN3,0,0},	// S_PAIN_RUN2
    {SPR_PAIN,1,3,{(actionf_p2)A_Chase},S_PAIN_RUN4,0,0},	// S_PAIN_RUN3
    {SPR_PAIN,1,3,{(actionf_p2)A_Chase},S_PAIN_RUN5,0,0},	// S_PAIN_RUN4
    {SPR_PAIN,2,3,{(actionf_p2)A_Chase},S_PAIN_RUN6,0,0},	// S_PAIN_RUN5
    {SPR_PAIN,2,3,{(actionf_p2)A_Chase},S_PAIN_RUN1,0,0},	// S_PAIN_RUN6
    {SPR_PAIN,3,5,{(actionf_p2)A_FaceTarget},S_PAIN_ATK2,0,0},	// S_PAIN_ATK1
    {SPR_PAIN,4,5,{(actionf_p2)A_FaceTarget},S_PAIN_ATK3,0,0},	// S_PAIN_ATK2
    {SPR_PAIN,32773,5,{(actionf_p2)A_FaceTarget},S_PAIN_ATK4,0,0},	// S_PAIN_ATK3
    {SPR_PAIN,32773,0,{(actionf_p2)A_PainAttack},S_PAIN_RUN1,0,0},	// S_PAIN_ATK4
    {SPR_PAIN,6,6,{NULL},S_PAIN_PAIN2,0,0},	// S_PAIN_PAIN
    {SPR_PAIN,6,6,{(actionf_p2)A_Pain},S_PAIN_RUN1,0,0},	// S_PAIN_PAIN2
    {SPR_PAIN,32775,8,{NULL},S_PAIN_DIE2,0,0},	// S_PAIN_DIE1
    {SPR_PAIN,32776,8,{(actionf_p2)A_Scream},S_PAIN_DIE3,0,0},	// S_PAIN_DIE2
    {SPR_PAIN,32777,8,{NULL},S_PAIN_DIE4,0,0},	// S_PAIN_DIE3
    {SPR_PAIN,32778,8,{NULL},S_PAIN_DIE5,0,0},	// S_PAIN_DIE4
    {SPR_PAIN,32779,8,{(actionf_p2)A_PainDie},S_PAIN_DIE6,0,0},	// S_PAIN_DIE5
    {SPR_PAIN,32780,8,{NULL},S_NULL,0,0},	// S_PAIN_DIE6
    {SPR_PAIN,12,8,{NULL},S_PAIN_RAISE2,0,0},	// S_PAIN_RAISE1
    {SPR_PAIN,11,8,{NULL},S_PAIN_RAISE3,0,0},	// S_PAIN_RAISE2
    {SPR_PAIN,10,8,{NULL},S_PAIN_RAISE4,0,0},	// S_PAIN_RAISE3
    {SPR_PAIN,9,8,{NULL},S_PAIN_RAISE5,0,0},	// S_PAIN_RAISE4
    {SPR_PAIN,8,8,{NULL},S_PAIN_RAISE6,0,0},	// S_PAIN_RAISE5
    {SPR_PAIN,7,8,{NULL},S_PAIN_RUN1,0,0},	// S_PAIN_RAISE6
    {SPR_SSWV,0,10,{(actionf_p2)A_Look},S_SSWV_STND2,0,0},	// S_SSWV_STND
    {SPR_SSWV,1,10,{(actionf_p2)A_Look},S_SSWV_STND,0,0},	// S_SSWV_STND2
    {SPR_SSWV,0,3,{(actionf_p2)A_Chase},S_SSWV_RUN2,0,0},	// S_SSWV_RUN1
    {SPR_SSWV,0,3,{(actionf_p2)A_Chase},S_SSWV_RUN3,0,0},	// S_SSWV_RUN2
    {SPR_SSWV,1,3,{(actionf_p2)A_Chase},S_SSWV_RUN4,0,0},	// S_SSWV_RUN3
    {SPR_SSWV,1,3,{(actionf_p2)A_Chase},S_SSWV_RUN5,0,0},	// S_SSWV_RUN4
    {SPR_SSWV,2,3,{(actionf_p2)A_Chase},S_SSWV_RUN6,0,0},	// S_SSWV_RUN5
    {SPR_SSWV,2,3,{(actionf_p2)A_Chase},S_SSWV_RUN7,0,0},	// S_SSWV_RUN6
    {SPR_SSWV,3,3,{(actionf_p2)A_Chase},S_SSWV_RUN8,0,0},	// S_SSWV_RUN7
    {SPR_SSWV,3,3,{(actionf_p2)A_Chase},S_SSWV_RUN1,0,0},	// S_SSWV_RUN8
    {SPR_SSWV,4,10,{(actionf_p2)A_FaceTarget},S_SSWV_ATK2,0,0},	// S_SSWV_ATK1
    {SPR_SSWV,5,10,{(actionf_p2)A_FaceTarget},S_SSWV_ATK3,0,0},	// S_SSWV_ATK2
    {SPR_SSWV,32774,4,{(actionf_p2)A_CPosAttack},S_SSWV_ATK4,0,0},	// S_SSWV_ATK3
    {SPR_SSWV,5,6,{(actionf_p2)A_FaceTarget},S_SSWV_ATK5,0,0},	// S_SSWV_ATK4
    {SPR_SSWV,32774,4,{(actionf_p2)A_CPosAttack},S_SSWV_ATK6,0,0},	// S_SSWV_ATK5
    {SPR_SSWV,5,1,{(actionf_p2)A_CPosRefire},S_SSWV_ATK2,0,0},	// S_SSWV_ATK6
    {SPR_SSWV,7,3,{NULL},S_SSWV_PAIN2,0,0},	// S_SSWV_PAIN
    {SPR_SSWV,7,3,{(actionf_p2)A_Pain},S_SSWV_RUN1,0,0},	// S_SSWV_PAIN2
    {SPR_SSWV,8,5,{NULL},S_SSWV_DIE2,0,0},	// S_SSWV_DIE1
    {SPR_SSWV,9,5,{(actionf_p2)A_Scream},S_SSWV_DIE3,0,0},	// S_SSWV_DIE2
    {SPR_SSWV,10,5,{(actionf_p2)A_Fall},S_SSWV_DIE4,0,0},	// S_SSWV_DIE3
    {SPR_SSWV,11,5,{NULL},S_SSWV_DIE5,0,0},	// S_SSWV_DIE4
    {SPR_SSWV,12,-1,{NULL},S_NULL,0,0},	// S_SSWV_DIE5
    {SPR_SSWV,13,5,{NULL},S_SSWV_XDIE2,0,0},	// S_SSWV_XDIE1
    {SPR_SSWV,14,5,{(actionf_p2)A_XScream},S_SSWV_XDIE3,0,0},	// S_SSWV_XDIE2
    {SPR_SSWV,15,5,{(actionf_p2)A_Fall},S_SSWV_XDIE4,0,0},	// S_SSWV_XDIE3
    {SPR_SSWV,16,5,{NULL},S_SSWV_XDIE5,0,0},	// S_SSWV_XDIE4
    {SPR_SSWV,17,5,{NULL},S_SSWV_XDIE6,0,0},	// S_SSWV_XDIE5
    {SPR_SSWV,18,5,{NULL},S_SSWV_XDIE7,0,0},	// S_SSWV_XDIE6
    {SPR_SSWV,19,5,{NULL},S_SSWV_XDIE8,0,0},	// S_SSWV_XDIE7
    {SPR_SSWV,20,5,{NULL},S_SSWV_XDIE9,0,0},	// S_SSWV_XDIE8
    {SPR_SSWV,21,-1,{NULL},S_NULL,0,0},	// S_SSWV_XDIE9
    {SPR_SSWV,12,5,{NULL},S_SSWV_RAISE2,0,0},	// S_SSWV_RAISE1
    {SPR_SSWV,11,5,{NULL},S_SSWV_RAISE3,0,0},	// S_SSWV_RAISE2
    {SPR_SSWV,10,5,{NULL},S_SSWV_RAISE4,0,0},	// S_SSWV_RAISE3
    {SPR_SSWV,9,5,{NULL},S_SSWV_RAISE5,0,0},	// S_SSWV_RAISE4
    {SPR_SSWV,8,5,{NULL},S_SSWV_RUN1,0,0},	// S_SSWV_RAISE5
    {SPR_KEEN,0,-1,{NULL},S_KEENSTND,0,0},	// S_KEENSTND
    {SPR_KEEN,0,6,{NULL},S_COMMKEEN2,0,0},	// S_COMMKEEN
    {SPR_KEEN,1,6,{NULL},S_COMMKEEN3,0,0},	// S_COMMKEEN2
    {SPR_KEEN,2,6,{(actionf_p2)A_Scream},S_COMMKEEN4,0,0},	// S_COMMKEEN3
    {SPR_KEEN,3,6,{NULL},S_COMMKEEN5,0,0},	// S_COMMKEEN4
    {SPR_KEEN,4,6,{NULL},S_COMMKEEN6,0,0},	// S_COMMKEEN5
    {SPR_KEEN,5,6,{NULL},S_COMMKEEN7,0,0},	// S_COMMKEEN6
    {SPR_KEEN,6,6,{NULL},S_COMMKEEN8,0,0},	// S_COMMKEEN7
    {SPR_KEEN,7,6,{NULL},S_COMMKEEN9,0,0},	// S_COMMKEEN8
    {SPR_KEEN,8,6,{NULL},S_COMMKEEN10,0,0},	// S_COMMKEEN9
    {SPR_KEEN,9,6,{NULL},S_COMMKEEN11,0,0},	// S_COMMKEEN10
    {SPR_KEEN,10,6,{(actionf_p2)A_KeenDie},S_COMMKEEN12,0,0},// S_COMMKEEN11
    {SPR_KEEN,11,-1,{NULL},S_NULL,0,0},		// S_COMMKEEN12
    {SPR_KEEN,12,4,{NULL},S_KEENPAIN2,0,0},	// S_KEENPAIN
    {SPR_KEEN,12,8,{(actionf_p2)A_Pain},S_KEENSTND,0,0},	// S_KEENPAIN2
    {SPR_BBRN,0,-1,{NULL},S_NULL,0,0},		// S_BRAIN
    {SPR_BBRN,1,36,{(actionf_p2)A_BrainPain},S_BRAIN,0,0},	// S_BRAIN_PAIN
    {SPR_BBRN,0,100,{(actionf_p2)A_BrainScream},S_BRAIN_DIE2,0,0},	// S_BRAIN_DIE1
    {SPR_BBRN,0,10,{NULL},S_BRAIN_DIE3,0,0},	// S_BRAIN_DIE2
    {SPR_BBRN,0,10,{NULL},S_BRAIN_DIE4,0,0},	// S_BRAIN_DIE3
    {SPR_BBRN,0,-1,{(actionf_p2)A_BrainDie},S_NULL,0,0},	// S_BRAIN_DIE4
    {SPR_SSWV,0,10,{(actionf_p2)A_Look},S_BRAINEYE,0,0},	// S_BRAINEYE
    {SPR_SSWV,0,181,{(actionf_p2)A_BrainAwake},S_BRAINEYE1,0,0},	// S_BRAINEYESEE
    {SPR_SSWV,0,150,{(actionf_p2)A_BrainSpit},S_BRAINEYE1,0,0},	// S_BRAINEYE1
    {SPR_BOSF,32768,3,{(actionf_p2)A_SpawnSound},S_SPAWN2,0,0},	// S_SPAWN1
    {SPR_BOSF,32769,3,{(actionf_p2)A_SpawnFly},S_SPAWN3,0,0},	// S_SPAWN2
    {SPR_BOSF,32770,3,{(actionf_p2)A_SpawnFly},S_SPAWN4,0,0},	// S_SPAWN3
    {SPR_BOSF,32771,3,{(actionf_p2)A_SpawnFly},S_SPAWN1,0,0},	// S_SPAWN4
    {SPR_FIRE,32768,4,{(actionf_p2)A_Fire},S_SPAWNFIRE2,0,0},	// S_SPAWNFIRE1
    {SPR_FIRE,32769,4,{(actionf_p2)A_Fire},S_SPAWNFIRE3,0,0},	// S_SPAWNFIRE2
    {SPR_FIRE,32770,4,{(actionf_p2)A_Fire},S_SPAWNFIRE4,0,0},	// S_SPAWNFIRE3
    {SPR_FIRE,32771,4,{(actionf_p2)A_Fire},S_SPAWNFIRE5,0,0},	// S_SPAWNFIRE4
    {SPR_FIRE,32772,4,{(actionf_p2)A_Fire},S_SPAWNFIRE6,0,0},	// S_SPAWNFIRE5
    {SPR_FIRE,32773,4,{(actionf_p2)A_Fire},S_SPAWNFIRE7,0,0},	// S_SPAWNFIRE6
    {SPR_FIRE,32774,4,{(actionf_p2)A_Fire},S_SPAWNFIRE8,0,0},	// S_SPAWNFIRE7
    {SPR_FIRE,32775,4,{(actionf_p2)A_Fire},S_NULL,0,0},		// S_SPAWNFIRE8
    {SPR_MISL,32769,10,{NULL},S_BRAINEXPLODE2,0,0},	// S_BRAINEXPLODE1
    {SPR_MISL,32770,10,{NULL},S_BRAINEXPLODE3,0,0},	// S_BRAINEXPLODE2
    {SPR_MISL,32771,10,{(actionf_p2)A_BrainExplode},S_NULL,0,0},	// S_BRAINEXPLODE3
    {SPR_ARM1,0,6,{NULL},S_ARM1A,0,0},	// S_ARM1
    {SPR_ARM1,32769,7,{NULL},S_ARM1,0,0},	// S_ARM1A
    {SPR_ARM2,0,6,{NULL},S_ARM2A,0,0},	// S_ARM2
    {SPR_ARM2,32769,6,{NULL},S_ARM2,0,0},	// S_ARM2A
    {SPR_BAR1,0,6,{NULL},S_BAR2,0,0},	// S_BAR1
    {SPR_BAR1,1,6,{NULL},S_BAR1,0,0},	// S_BAR2
    {SPR_BEXP,32768,5,{NULL},S_BEXP2,0,0},	// S_BEXP
    {SPR_BEXP,32769,5,{(actionf_p2)A_Scream},S_BEXP3,0,0},	// S_BEXP2
    {SPR_BEXP,32770,5,{NULL},S_BEXP4,0,0},	// S_BEXP3
    {SPR_BEXP,32771,10,{(actionf_p2)A_Explode},S_BEXP5,0,0},	// S_BEXP4
    {SPR_BEXP,32772,10,{NULL},S_NULL,0,0},	// S_BEXP5
    {SPR_FCAN,32768,4,{NULL},S_BBAR2,0,0},	// S_BBAR1
    {SPR_FCAN,32769,4,{NULL},S_BBAR3,0,0},	// S_BBAR2
    {SPR_FCAN,32770,4,{NULL},S_BBAR1,0,0},	// S_BBAR3
    {SPR_BON1,0,6,{NULL},S_BON1A,0,0},	// S_BON1
    {SPR_BON1,1,6,{NULL},S_BON1B,0,0},	// S_BON1A
    {SPR_BON1,2,6,{NULL},S_BON1C,0,0},	// S_BON1B
    {SPR_BON1,3,6,{NULL},S_BON1D,0,0},	// S_BON1C
    {SPR_BON1,2,6,{NULL},S_BON1E,0,0},	// S_BON1D
    {SPR_BON1,1,6,{NULL},S_BON1,0,0},	// S_BON1E
    {SPR_BON2,0,6,{NULL},S_BON2A,0,0},	// S_BON2
    {SPR_BON2,1,6,{NULL},S_BON2B,0,0},	// S_BON2A
    {SPR_BON2,2,6,{NULL},S_BON2C,0,0},	// S_BON2B
    {SPR_BON2,3,6,{NULL},S_BON2D,0,0},	// S_BON2C
    {SPR_BON2,2,6,{NULL},S_BON2E,0,0},	// S_BON2D
    {SPR_BON2,1,6,{NULL},S_BON2,0,0},	// S_BON2E
    {SPR_BKEY,0,10,{NULL},S_BKEY2,0,0},	// S_BKEY
    {SPR_BKEY,32769,10,{NULL},S_BKEY,0,0},	// S_BKEY2
    {SPR_RKEY,0,10,{NULL},S_RKEY2,0,0},	// S_RKEY
    {SPR_RKEY,32769,10,{NULL},S_RKEY,0,0},	// S_RKEY2
    {SPR_YKEY,0,10,{NULL},S_YKEY2,0,0},	// S_YKEY
    {SPR_YKEY,32769,10,{NULL},S_YKEY,0,0},	// S_YKEY2
    {SPR_BSKU,0,10,{NULL},S_BSKULL2,0,0},	// S_BSKULL
    {SPR_BSKU,32769,10,{NULL},S_BSKULL,0,0},	// S_BSKULL2
    {SPR_RSKU,0,10,{NULL},S_RSKULL2,0,0},	// S_RSKULL
    {SPR_RSKU,32769,10,{NULL},S_RSKULL,0,0},	// S_RSKULL2
    {SPR_YSKU,0,10,{NULL},S_YSKULL2,0,0},	// S_YSKULL
    {SPR_YSKU,32769,10,{NULL},S_YSKULL,0,0},	// S_YSKULL2
    {SPR_STIM,0,-1,{NULL},S_NULL,0,0},	// S_STIM
    {SPR_MEDI,0,-1,{NULL},S_NULL,0,0},	// S_MEDI
    {SPR_SOUL,32768,6,{NULL},S_SOUL2,0,0},	// S_SOUL
    {SPR_SOUL,32769,6,{NULL},S_SOUL3,0,0},	// S_SOUL2
    {SPR_SOUL,32770,6,{NULL},S_SOUL4,0,0},	// S_SOUL3
    {SPR_SOUL,32771,6,{NULL},S_SOUL5,0,0},	// S_SOUL4
    {SPR_SOUL,32770,6,{NULL},S_SOUL6,0,0},	// S_SOUL5
    {SPR_SOUL,32769,6,{NULL},S_SOUL,0,0},	// S_SOUL6
    {SPR_PINV,32768,6,{NULL},S_PINV2,0,0},	// S_PINV
    {SPR_PINV,32769,6,{NULL},S_PINV3,0,0},	// S_PINV2
    {SPR_PINV,32770,6,{NULL},S_PINV4,0,0},	// S_PINV3
    {SPR_PINV,32771,6,{NULL},S_PINV,0,0},	// S_PINV4
    {SPR_PSTR,32768,-1,{NULL},S_NULL,0,0},	// S_PSTR
    {SPR_PINS,32768,6,{NULL},S_PINS2,0,0},	// S_PINS
    {SPR_PINS,32769,6,{NULL},S_PINS3,0,0},	// S_PINS2
    {SPR_PINS,32770,6,{NULL},S_PINS4,0,0},	// S_PINS3
    {SPR_PINS,32771,6,{NULL},S_PINS,0,0},	// S_PINS4
    {SPR_MEGA,32768,6,{NULL},S_MEGA2,0,0},	// S_MEGA
    {SPR_MEGA,32769,6,{NULL},S_MEGA3,0,0},	// S_MEGA2
    {SPR_MEGA,32770,6,{NULL},S_MEGA4,0,0},	// S_MEGA3
    {SPR_MEGA,32771,6,{NULL},S_MEGA,0,0},	// S_MEGA4
    {SPR_SUIT,32768,-1,{NULL},S_NULL,0,0},	// S_SUIT
    {SPR_PMAP,32768,6,{NULL},S_PMAP2,0,0},	// S_PMAP
    {SPR_PMAP,32769,6,{NULL},S_PMAP3,0,0},	// S_PMAP2
    {SPR_PMAP,32770,6,{NULL},S_PMAP4,0,0},	// S_PMAP3
    {SPR_PMAP,32771,6,{NULL},S_PMAP5,0,0},	// S_PMAP4
    {SPR_PMAP,32770,6,{NULL},S_PMAP6,0,0},	// S_PMAP5
    {SPR_PMAP,32769,6,{NULL},S_PMAP,0,0},	// S_PMAP6
    {SPR_PVIS,32768,6,{NULL},S_PVIS2,0,0},	// S_PVIS
    {SPR_PVIS,1,6,{NULL},S_PVIS,0,0},	// S_PVIS2
    {SPR_CLIP,0,-1,{NULL},S_NULL,0,0},	// S_CLIP
    {SPR_AMMO,0,-1,{NULL},S_NULL,0,0},	// S_AMMO
    {SPR_ROCK,0,-1,{NULL},S_NULL,0,0},	// S_ROCK
    {SPR_BROK,0,-1,{NULL},S_NULL,0,0},	// S_BROK
    {SPR_CELL,0,-1,{NULL},S_NULL,0,0},	// S_CELL
    {SPR_CELP,0,-1,{NULL},S_NULL,0,0},	// S_CELP
    {SPR_SHEL,0,-1,{NULL},S_NULL,0,0},	// S_SHEL
    {SPR_SBOX,0,-1,{NULL},S_NULL,0,0},	// S_SBOX
    {SPR_BPAK,0,-1,{NULL},S_NULL,0,0},	// S_BPAK
    {SPR_BFUG,0,-1,{NULL},S_NULL,0,0},	// S_BFUG
    {SPR_MGUN,0,-1,{NULL},S_NULL,0,0},	// S_MGUN
    {SPR_CSAW,0,-1,{NULL},S_NULL,0,0},	// S_CSAW
    {SPR_LAUN,0,-1,{NULL},S_NULL,0,0},	// S_LAUN
    {SPR_PLAS,0,-1,{NULL},S_NULL,0,0},	// S_PLAS
    {SPR_SHOT,0,-1,{NULL},S_NULL,0,0},	// S_SHOT
    {SPR_SGN2,0,-1,{NULL},S_NULL,0,0},	// S_SHOT2
    {SPR_COLU,32768,-1,{NULL},S_NULL,0,0},	// S_COLU
    {SPR_SMT2,0,-1,{NULL},S_NULL,0,0},	// S_STALAG
    {SPR_GOR1,0,10,{NULL},S_BLOODYTWITCH2,0,0},	// S_BLOODYTWITCH
    {SPR_GOR1,1,15,{NULL},S_BLOODYTWITCH3,0,0},	// S_BLOODYTWITCH2
    {SPR_GOR1,2,8,{NULL},S_BLOODYTWITCH4,0,0},	// S_BLOODYTWITCH3
    {SPR_GOR1,1,6,{NULL},S_BLOODYTWITCH,0,0},	// S_BLOODYTWITCH4
    {SPR_PLAY,13,-1,{NULL},S_NULL,0,0},	// S_DEADTORSO
    {SPR_PLAY,18,-1,{NULL},S_NULL,0,0},	// S_DEADBOTTOM
    {SPR_POL2,0,-1,{NULL},S_NULL,0,0},	// S_HEADSONSTICK
    {SPR_POL5,0,-1,{NULL},S_NULL,0,0},	// S_GIBS
    {SPR_POL4,0,-1,{NULL},S_NULL,0,0},	// S_HEADONASTICK
    {SPR_POL3,32768,6,{NULL},S_HEADCANDLES2,0,0},	// S_HEADCANDLES
    {SPR_POL3,32769,6,{NULL},S_HEADCANDLES,0,0},	// S_HEADCANDLES2
    {SPR_POL1,0,-1,{NULL},S_NULL,0,0},	// S_DEADSTICK
    {SPR_POL6,0,6,{NULL},S_LIVESTICK2,0,0},	// S_LIVESTICK
    {SPR_POL6,1,8,{NULL},S_LIVESTICK,0,0},	// S_LIVESTICK2
    {SPR_GOR2,0,-1,{NULL},S_NULL,0,0},	// S_MEAT2
    {SPR_GOR3,0,-1,{NULL},S_NULL,0,0},	// S_MEAT3
    {SPR_GOR4,0,-1,{NULL},S_NULL,0,0},	// S_MEAT4
    {SPR_GOR5,0,-1,{NULL},S_NULL,0,0},	// S_MEAT5
    {SPR_SMIT,0,-1,{NULL},S_NULL,0,0},	// S_STALAGTITE
    {SPR_COL1,0,-1,{NULL},S_NULL,0,0},	// S_TALLGRNCOL
    {SPR_COL2,0,-1,{NULL},S_NULL,0,0},	// S_SHRTGRNCOL
    {SPR_COL3,0,-1,{NULL},S_NULL,0,0},	// S_TALLREDCOL
    {SPR_COL4,0,-1,{NULL},S_NULL,0,0},	// S_SHRTREDCOL
    {SPR_CAND,32768,-1,{NULL},S_NULL,0,0},	// S_CANDLESTIK
    {SPR_CBRA,32768,-1,{NULL},S_NULL,0,0},	// S_CANDELABRA
    {SPR_COL6,0,-1,{NULL},S_NULL,0,0},	// S_SKULLCOL
    {SPR_TRE1,0,-1,{NULL},S_NULL,0,0},	// S_TORCHTREE
    {SPR_TRE2,0,-1,{NULL},S_NULL,0,0},	// S_BIGTREE
    {SPR_ELEC,0,-1,{NULL},S_NULL,0,0},	// S_TECHPILLAR
    {SPR_CEYE,32768,6,{NULL},S_EVILEYE2,0,0},	// S_EVILEYE
    {SPR_CEYE,32769,6,{NULL},S_EVILEYE3,0,0},	// S_EVILEYE2
    {SPR_CEYE,32770,6,{NULL},S_EVILEYE4,0,0},	// S_EVILEYE3
    {SPR_CEYE,32769,6,{NULL},S_EVILEYE,0,0},	// S_EVILEYE4
    {SPR_FSKU,32768,6,{NULL},S_FLOATSKULL2,0,0},	// S_FLOATSKULL
    {SPR_FSKU,32769,6,{NULL},S_FLOATSKULL3,0,0},	// S_FLOATSKULL2
    {SPR_FSKU,32770,6,{NULL},S_FLOATSKULL,0,0},	// S_FLOATSKULL3
    {SPR_COL5,0,14,{NULL},S_HEARTCOL2,0,0},	// S_HEARTCOL
    {SPR_COL5,1,14,{NULL},S_HEARTCOL,0,0},	// S_HEARTCOL2
    {SPR_TBLU,32768,4,{NULL},S_BLUETORCH2,0,0},	// S_BLUETORCH
    {SPR_TBLU,32769,4,{NULL},S_BLUETORCH3,0,0},	// S_BLUETORCH2
    {SPR_TBLU,32770,4,{NULL},S_BLUETORCH4,0,0},	// S_BLUETORCH3
    {SPR_TBLU,32771,4,{NULL},S_BLUETORCH,0,0},	// S_BLUETORCH4
    {SPR_TGRN,32768,4,{NULL},S_GREENTORCH2,0,0},	// S_GREENTORCH
    {SPR_TGRN,32769,4,{NULL},S_GREENTORCH3,0,0},	// S_GREENTORCH2
    {SPR_TGRN,32770,4,{NULL},S_GREENTORCH4,0,0},	// S_GREENTORCH3
    {SPR_TGRN,32771,4,{NULL},S_GREENTORCH,0,0},	// S_GREENTORCH4
    {SPR_TRED,32768,4,{NULL},S_REDTORCH2,0,0},	// S_REDTORCH
    {SPR_TRED,32769,4,{NULL},S_REDTORCH3,0,0},	// S_REDTORCH2
    {SPR_TRED,32770,4,{NULL},S_REDTORCH4,0,0},	// S_REDTORCH3
    {SPR_TRED,32771,4,{NULL},S_REDTORCH,0,0},	// S_REDTORCH4
    {SPR_SMBT,32768,4,{NULL},S_BTORCHSHRT2,0,0},	// S_BTORCHSHRT
    {SPR_SMBT,32769,4,{NULL},S_BTORCHSHRT3,0,0},	// S_BTORCHSHRT2
    {SPR_SMBT,32770,4,{NULL},S_BTORCHSHRT4,0,0},	// S_BTORCHSHRT3
    {SPR_SMBT,32771,4,{NULL},S_BTORCHSHRT,0,0},	// S_BTORCHSHRT4
    {SPR_SMGT,32768,4,{NULL},S_GTORCHSHRT2,0,0},	// S_GTORCHSHRT
    {SPR_SMGT,32769,4,{NULL},S_GTORCHSHRT3,0,0},	// S_GTORCHSHRT2
    {SPR_SMGT,32770,4,{NULL},S_GTORCHSHRT4,0,0},	// S_GTORCHSHRT3
    {SPR_SMGT,32771,4,{NULL},S_GTORCHSHRT,0,0},	// S_GTORCHSHRT4
    {SPR_SMRT,32768,4,{NULL},S_RTORCHSHRT2,0,0},	// S_RTORCHSHRT
    {SPR_SMRT,32769,4,{NULL},S_RTORCHSHRT3,0,0},	// S_RTORCHSHRT2
    {SPR_SMRT,32770,4,{NULL},S_RTORCHSHRT4,0,0},	// S_RTORCHSHRT3
    {SPR_SMRT,32771,4,{NULL},S_RTORCHSHRT,0,0},	// S_RTORCHSHRT4
    {SPR_HDB1,0,-1,{NULL},S_NULL,0,0},	// S_HANGNOGUTS
    {SPR_HDB2,0,-1,{NULL},S_NULL,0,0},	// S_HANGBNOBRAIN
    {SPR_HDB3,0,-1,{NULL},S_NULL,0,0},	// S_HANGTLOOKDN
    {SPR_HDB4,0,-1,{NULL},S_NULL,0,0},	// S_HANGTSKULL
    {SPR_HDB5,0,-1,{NULL},S_NULL,0,0},	// S_HANGTLOOKUP
    {SPR_HDB6,0,-1,{NULL},S_NULL,0,0},	// S_HANGTNOBRAIN
    {SPR_POB1,0,-1,{NULL},S_NULL,0,0},	// S_COLONGIBS
    {SPR_POB2,0,-1,{NULL},S_NULL,0,0},	// S_SMALLPOOL
    {SPR_BRS1,0,-1,{NULL},S_NULL,0,0},		// S_BRAINSTEM
    {SPR_TLMP,32768,4,{NULL},S_TECHLAMP2,0,0},	// S_TECHLAMP
    {SPR_TLMP,32769,4,{NULL},S_TECHLAMP3,0,0},	// S_TECHLAMP2
    {SPR_TLMP,32770,4,{NULL},S_TECHLAMP4,0,0},	// S_TECHLAMP3
    {SPR_TLMP,32771,4,{NULL},S_TECHLAMP,0,0},	// S_TECHLAMP4
    {SPR_TLP2,32768,4,{NULL},S_TECH2LAMP2,0,0},	// S_TECH2LAMP
    {SPR_TLP2,32769,4,{NULL},S_TECH2LAMP3,0,0},	// S_TECH2LAMP2
    {SPR_TLP2,32770,4,{NULL},S_TECH2LAMP4,0,0},	// S_TECH2LAMP3
    {SPR_TLP2,32771,4,{NULL},S_TECH2LAMP,0,0},	// S_TECH2LAMP4
	{ SPR_TNT1,0,-1,{NULL},S_TNT1,0,0 },          // S_TNT1    // phares 3/8/98
};

/*const*/ std::vector <mobjinfo_t> mobjinfo{

	{		// MT_PLAYER
	-1,		// doomednum
	S_PLAY,		// spawnstate
	100,		// spawnhealth
	S_PLAY_RUN1,		// seestate
	sfx_None,		// seesound
	0,		// reactiontime
	sfx_None,		// attacksound
	S_PLAY_PAIN,		// painstate
	255,		// painchance
	sfx_plpain,		// painsound
	S_NULL,		// meleestate
	S_PLAY_ATK1,		// missilestate
	S_PLAY_DIE1,		// deathstate
	S_PLAY_XDIE1,		// xdeathstate
	sfx_pldeth,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_DROPOFF | MF_PICKUP | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_POSSESSED
	3004,		// doomednum
	S_POSS_STND,		// spawnstate
	20,		// spawnhealth
	S_POSS_RUN1,		// seestate
	sfx_posit1,		// seesound
	8,		// reactiontime
	sfx_pistol,		// attacksound
	S_POSS_PAIN,		// painstate
	200,		// painchance
	sfx_popain,		// painsound
	0,		// meleestate
	S_POSS_ATK1,		// missilestate
	S_POSS_DIE1,		// deathstate
	S_POSS_XDIE1,		// xdeathstate
	sfx_podth1,		// deathsound
	8,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_posact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_POSS_RAISE1		// raisestate
	},

	{		// MT_SHOTGUY
	9,		// doomednum
	S_SPOS_STND,		// spawnstate
	30,		// spawnhealth
	S_SPOS_RUN1,		// seestate
	sfx_posit2,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_SPOS_PAIN,		// painstate
	170,		// painchance
	sfx_popain,		// painsound
	0,		// meleestate
	S_SPOS_ATK1,		// missilestate
	S_SPOS_DIE1,		// deathstate
	S_SPOS_XDIE1,		// xdeathstate
	sfx_podth2,		// deathsound
	8,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_posact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_SPOS_RAISE1		// raisestate
	},

	{		// MT_VILE
	64,		// doomednum
	S_VILE_STND,		// spawnstate
	700,		// spawnhealth
	S_VILE_RUN1,		// seestate
	sfx_vilsit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_VILE_PAIN,		// painstate
	10,		// painchance
	sfx_vipain,		// painsound
	0,		// meleestate
	S_VILE_ATK1,		// missilestate
	S_VILE_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_vildth,		// deathsound
	15,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	500,		// mass
	0,		// damage
	sfx_vilact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_FIRE
	-1,		// doomednum
	S_FIRE1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_UNDEAD
	66,		// doomednum
	S_SKEL_STND,		// spawnstate
	300,		// spawnhealth
	S_SKEL_RUN1,		// seestate
	sfx_skesit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_SKEL_PAIN,		// painstate
	100,		// painchance
	sfx_popain,		// painsound
	S_SKEL_FIST1,		// meleestate
	S_SKEL_MISS1,		// missilestate
	S_SKEL_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_skedth,		// deathsound
	10,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	500,		// mass
	0,		// damage
	sfx_skeact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_SKEL_RAISE1		// raisestate
	},

	{		// MT_TRACER
	-1,		// doomednum
	S_TRACER,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_skeatk,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_TRACEEXP1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_barexp,		// deathsound
	10 * FRACUNIT,		// speed
	11 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	10,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SMOKE
	-1,		// doomednum
	S_SMOKE1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_FATSO
	67,		// doomednum
	S_FATT_STND,		// spawnstate
	600,		// spawnhealth
	S_FATT_RUN1,		// seestate
	sfx_mansit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_FATT_PAIN,		// painstate
	80,		// painchance
	sfx_mnpain,		// painsound
	0,		// meleestate
	S_FATT_ATK1,		// missilestate
	S_FATT_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_mandth,		// deathsound
	8,		// speed
	48 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	1000,		// mass
	0,		// damage
	sfx_posact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_FATT_RAISE1		// raisestate
	},

	{		// MT_FATSHOT
	-1,		// doomednum
	S_FATSHOT1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_firsht,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_FATSHOTX1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	20 * FRACUNIT,		// speed
	6 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	8,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_CHAINGUY
	65,		// doomednum
	S_CPOS_STND,		// spawnstate
	70,		// spawnhealth
	S_CPOS_RUN1,		// seestate
	sfx_posit2,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_CPOS_PAIN,		// painstate
	170,		// painchance
	sfx_popain,		// painsound
	0,		// meleestate
	S_CPOS_ATK1,		// missilestate
	S_CPOS_DIE1,		// deathstate
	S_CPOS_XDIE1,		// xdeathstate
	sfx_podth2,		// deathsound
	8,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_posact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_CPOS_RAISE1		// raisestate
	},

	{		// MT_TROOP
	3001,		// doomednum
	S_TROO_STND,		// spawnstate
	60,		// spawnhealth
	S_TROO_RUN1,		// seestate
	sfx_bgsit1,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_TROO_PAIN,		// painstate
	200,		// painchance
	sfx_popain,		// painsound
	S_TROO_ATK1,		// meleestate
	S_TROO_ATK1,		// missilestate
	S_TROO_DIE1,		// deathstate
	S_TROO_XDIE1,		// xdeathstate
	sfx_bgdth1,		// deathsound
	8,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_bgact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_TROO_RAISE1		// raisestate
	},

	{		// MT_SERGEANT
	3002,		// doomednum
	S_SARG_STND,		// spawnstate
	150,		// spawnhealth
	S_SARG_RUN1,		// seestate
	sfx_sgtsit,		// seesound
	8,		// reactiontime
	sfx_sgtatk,		// attacksound
	S_SARG_PAIN,		// painstate
	180,		// painchance
	sfx_dmpain,		// painsound
	S_SARG_ATK1,		// meleestate
	0,		// missilestate
	S_SARG_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_sgtdth,		// deathsound
	10,		// speed
	30 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	400,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_SARG_RAISE1		// raisestate
	},

	{		// MT_SHADOWS
	58,		// doomednum
	S_SARG_STND,		// spawnstate
	150,		// spawnhealth
	S_SARG_RUN1,		// seestate
	sfx_sgtsit,		// seesound
	8,		// reactiontime
	sfx_sgtatk,		// attacksound
	S_SARG_PAIN,		// painstate
	180,		// painchance
	sfx_dmpain,		// painsound
	S_SARG_ATK1,		// meleestate
	0,		// missilestate
	S_SARG_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_sgtdth,		// deathsound
	10,		// speed
	30 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	400,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_SHADOW | MF_COUNTKILL,		// flags
	S_SARG_RAISE1		// raisestate
	},

	{		// MT_HEAD
	3005,		// doomednum
	S_HEAD_STND,		// spawnstate
	400,		// spawnhealth
	S_HEAD_RUN1,		// seestate
	sfx_cacsit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_HEAD_PAIN,		// painstate
	128,		// painchance
	sfx_dmpain,		// painsound
	0,		// meleestate
	S_HEAD_ATK1,		// missilestate
	S_HEAD_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_cacdth,		// deathsound
	8,		// speed
	31 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	400,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_FLOAT | MF_NOGRAVITY | MF_COUNTKILL,		// flags
	S_HEAD_RAISE1		// raisestate
	},

	{		// MT_BRUISER
	3003,		// doomednum
	S_BOSS_STND,		// spawnstate
	1000,		// spawnhealth
	S_BOSS_RUN1,		// seestate
	sfx_brssit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_BOSS_PAIN,		// painstate
	50,		// painchance
	sfx_dmpain,		// painsound
	S_BOSS_ATK1,		// meleestate
	S_BOSS_ATK1,		// missilestate
	S_BOSS_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_brsdth,		// deathsound
	8,		// speed
	24 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	1000,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_BOSS_RAISE1		// raisestate
	},

	{		// MT_BRUISERSHOT
	-1,		// doomednum
	S_BRBALL1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_firsht,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_BRBALLX1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	15 * FRACUNIT,		// speed
	6 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	8,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_KNIGHT
	69,		// doomednum
	S_BOS2_STND,		// spawnstate
	500,		// spawnhealth
	S_BOS2_RUN1,		// seestate
	sfx_kntsit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_BOS2_PAIN,		// painstate
	50,		// painchance
	sfx_dmpain,		// painsound
	S_BOS2_ATK1,		// meleestate
	S_BOS2_ATK1,		// missilestate
	S_BOS2_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_kntdth,		// deathsound
	8,		// speed
	24 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	1000,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_BOS2_RAISE1		// raisestate
	},

	{		// MT_SKULL
	3006,		// doomednum
	S_SKULL_STND,		// spawnstate
	100,		// spawnhealth
	S_SKULL_RUN1,		// seestate
	0,		// seesound
	8,		// reactiontime
	sfx_sklatk,		// attacksound
	S_SKULL_PAIN,		// painstate
	256,		// painchance
	sfx_dmpain,		// painsound
	0,		// meleestate
	S_SKULL_ATK1,		// missilestate
	S_SKULL_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	8,		// speed
	16 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	50,		// mass
	3,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_FLOAT | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SPIDER
	7,		// doomednum
	S_SPID_STND,		// spawnstate
	3000,		// spawnhealth
	S_SPID_RUN1,		// seestate
	sfx_spisit,		// seesound
	8,		// reactiontime
	sfx_shotgn,		// attacksound
	S_SPID_PAIN,		// painstate
	40,		// painchance
	sfx_dmpain,		// painsound
	0,		// meleestate
	S_SPID_ATK1,		// missilestate
	S_SPID_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_spidth,		// deathsound
	12,		// speed
	128 * FRACUNIT,		// radius
	100 * FRACUNIT,		// height
	1000,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BABY
	68,		// doomednum
	S_BSPI_STND,		// spawnstate
	500,		// spawnhealth
	S_BSPI_SIGHT,		// seestate
	sfx_bspsit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_BSPI_PAIN,		// painstate
	128,		// painchance
	sfx_dmpain,		// painsound
	0,		// meleestate
	S_BSPI_ATK1,		// missilestate
	S_BSPI_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_bspdth,		// deathsound
	12,		// speed
	64 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	600,		// mass
	0,		// damage
	sfx_bspact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_BSPI_RAISE1		// raisestate
	},

	{		// MT_CYBORG
	16,		// doomednum
	S_CYBER_STND,		// spawnstate
	4000,		// spawnhealth
	S_CYBER_RUN1,		// seestate
	sfx_cybsit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_CYBER_PAIN,		// painstate
	20,		// painchance
	sfx_dmpain,		// painsound
	0,		// meleestate
	S_CYBER_ATK1,		// missilestate
	S_CYBER_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_cybdth,		// deathsound
	16,		// speed
	40 * FRACUNIT,		// radius
	110 * FRACUNIT,		// height
	1000,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_PAIN
	71,		// doomednum
	S_PAIN_STND,		// spawnstate
	400,		// spawnhealth
	S_PAIN_RUN1,		// seestate
	sfx_pesit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_PAIN_PAIN,		// painstate
	128,		// painchance
	sfx_pepain,		// painsound
	0,		// meleestate
	S_PAIN_ATK1,		// missilestate
	S_PAIN_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_pedth,		// deathsound
	8,		// speed
	31 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	400,		// mass
	0,		// damage
	sfx_dmact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_FLOAT | MF_NOGRAVITY | MF_COUNTKILL,		// flags
	S_PAIN_RAISE1		// raisestate
	},

	{		// MT_WOLFSS
	84,		// doomednum
	S_SSWV_STND,		// spawnstate
	50,		// spawnhealth
	S_SSWV_RUN1,		// seestate
	sfx_sssit,		// seesound
	8,		// reactiontime
	0,		// attacksound
	S_SSWV_PAIN,		// painstate
	170,		// painchance
	sfx_popain,		// painsound
	0,		// meleestate
	S_SSWV_ATK1,		// missilestate
	S_SSWV_DIE1,		// deathstate
	S_SSWV_XDIE1,		// xdeathstate
	sfx_ssdth,		// deathsound
	8,		// speed
	20 * FRACUNIT,		// radius
	56 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_posact,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_SSWV_RAISE1		// raisestate
	},

	{		// MT_KEEN
	72,		// doomednum
	S_KEENSTND,		// spawnstate
	100,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_KEENPAIN,		// painstate
	256,		// painchance
	sfx_keenpn,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_COMMKEEN,		// deathstate
	S_NULL,		// xdeathstate
	sfx_keendt,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	72 * FRACUNIT,		// height
	10000000,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY | MF_SHOOTABLE | MF_COUNTKILL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BOSSBRAIN
	88,		// doomednum
	S_BRAIN,		// spawnstate
	250,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_BRAIN_PAIN,		// painstate
	255,		// painchance
	sfx_bospn,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_BRAIN_DIE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_bosdth,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	10000000,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SHOOTABLE,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BOSSSPIT
	89,		// doomednum
	S_BRAINEYE,		// spawnstate
	1000,		// spawnhealth
	S_BRAINEYESEE,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	32 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOSECTOR,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BOSSTARGET
	87,		// doomednum
	S_NULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	32 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOSECTOR,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SPAWNSHOT
	-1,		// doomednum
	S_SPAWN1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_bospit,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	10 * FRACUNIT,		// speed
	6 * FRACUNIT,		// radius
	32 * FRACUNIT,		// height
	100,		// mass
	3,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY | MF_NOCLIP,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SPAWNFIRE
	-1,		// doomednum
	S_SPAWNFIRE1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BARREL
	2035,		// doomednum
	S_BAR1,		// spawnstate
	20,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_BEXP,		// deathstate
	S_NULL,		// xdeathstate
	sfx_barexp,		// deathsound
	0,		// speed
	10 * FRACUNIT,		// radius
	42 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SHOOTABLE | MF_NOBLOOD,		// flags
	S_NULL		// raisestate
	},

	{		// MT_TROOPSHOT
	-1,		// doomednum
	S_TBALL1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_firsht,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_TBALLX1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	10 * FRACUNIT,		// speed
	6 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	3,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_HEADSHOT
	-1,		// doomednum
	S_RBALL1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_firsht,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_RBALLX1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	10 * FRACUNIT,		// speed
	6 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	5,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_ROCKET
	-1,		// doomednum
	S_ROCKET,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_rlaunc,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_EXPLODE1,		// deathstate
	S_NULL,		// xdeathstate
	sfx_barexp,		// deathsound
	20 * FRACUNIT,		// speed
	11 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	20,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_PLASMA
	-1,		// doomednum
	S_PLASBALL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_plasma,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_PLASEXP,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	25 * FRACUNIT,		// speed
	13 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	5,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BFG
	-1,		// doomednum
	S_BFGSHOT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	0,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_BFGLAND,		// deathstate
	S_NULL,		// xdeathstate
	sfx_rxplod,		// deathsound
	25 * FRACUNIT,		// speed
	13 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	100,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_ARACHPLAZ
	-1,		// doomednum
	S_ARACH_PLAZ,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_plasma,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_ARACH_PLEX,		// deathstate
	S_NULL,		// xdeathstate
	sfx_firxpl,		// deathsound
	25 * FRACUNIT,		// speed
	13 * FRACUNIT,		// radius
	8 * FRACUNIT,		// height
	100,		// mass
	5,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_MISSILE | MF_DROPOFF | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_PUFF
	-1,		// doomednum
	S_PUFF1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_BLOOD
	-1,		// doomednum
	S_BLOOD1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP,		// flags
	S_NULL		// raisestate
	},

	{		// MT_TFOG
	-1,		// doomednum
	S_TFOG,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_IFOG
	-1,		// doomednum
	S_IFOG,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_TELEPORTMAN
	14,		// doomednum
	S_NULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOSECTOR,		// flags
	S_NULL		// raisestate
	},

	{		// MT_EXTRABFG
	-1,		// doomednum
	S_BFGEXP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC0
	2018,		// doomednum
	S_ARM1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC1
	2019,		// doomednum
	S_ARM2,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC2
	2014,		// doomednum
	S_BON1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC3
	2015,		// doomednum
	S_BON2,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC4
	5,		// doomednum
	S_BKEY,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC5
	13,		// doomednum
	S_RKEY,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC6
	6,		// doomednum
	S_YKEY,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC7
	39,		// doomednum
	S_YSKULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC8
	38,		// doomednum
	S_RSKULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC9
	40,		// doomednum
	S_BSKULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_NOTDMATCH,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC10
	2011,		// doomednum
	S_STIM,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC11
	2012,		// doomednum
	S_MEDI,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC12
	2013,		// doomednum
	S_SOUL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_INV
	2022,		// doomednum
	S_PINV,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC13
	2023,		// doomednum
	S_PSTR,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_INS
	2024,		// doomednum
	S_PINS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC14
	2025,		// doomednum
	S_SUIT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC15
	2026,		// doomednum
	S_PMAP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC16
	2045,		// doomednum
	S_PVIS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MEGA
	83,		// doomednum
	S_MEGA,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL | MF_COUNTITEM,		// flags
	S_NULL		// raisestate
	},

	{		// MT_CLIP
	2007,		// doomednum
	S_CLIP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC17
	2048,		// doomednum
	S_AMMO,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC18
	2010,		// doomednum
	S_ROCK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC19
	2046,		// doomednum
	S_BROK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC20
	2047,		// doomednum
	S_CELL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC21
	17,		// doomednum
	S_CELP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC22
	2008,		// doomednum
	S_SHEL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC23
	2049,		// doomednum
	S_SBOX,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC24
	8,		// doomednum
	S_BPAK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC25
	2006,		// doomednum
	S_BFUG,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_CHAINGUN
	2002,		// doomednum
	S_MGUN,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC26
	2005,		// doomednum
	S_CSAW,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC27
	2003,		// doomednum
	S_LAUN,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC28
	2004,		// doomednum
	S_PLAS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SHOTGUN
	2001,		// doomednum
	S_SHOT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_SUPERSHOTGUN
	82,		// doomednum
	S_SHOT2,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPECIAL,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC29
	85,		// doomednum
	S_TECHLAMP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC30
	86,		// doomednum
	S_TECH2LAMP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC31
	2028,		// doomednum
	S_COLU,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC32
	30,		// doomednum
	S_TALLGRNCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC33
	31,		// doomednum
	S_SHRTGRNCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC34
	32,		// doomednum
	S_TALLREDCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC35
	33,		// doomednum
	S_SHRTREDCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC36
	37,		// doomednum
	S_SKULLCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC37
	36,		// doomednum
	S_HEARTCOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC38
	41,		// doomednum
	S_EVILEYE,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC39
	42,		// doomednum
	S_FLOATSKULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC40
	43,		// doomednum
	S_TORCHTREE,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC41
	44,		// doomednum
	S_BLUETORCH,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC42
	45,		// doomednum
	S_GREENTORCH,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC43
	46,		// doomednum
	S_REDTORCH,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC44
	55,		// doomednum
	S_BTORCHSHRT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC45
	56,		// doomednum
	S_GTORCHSHRT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC46
	57,		// doomednum
	S_RTORCHSHRT,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC47
	47,		// doomednum
	S_STALAGTITE,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC48
	48,		// doomednum
	S_TECHPILLAR,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC49
	34,		// doomednum
	S_CANDLESTIK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC50
	35,		// doomednum
	S_CANDELABRA,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC51
	49,		// doomednum
	S_BLOODYTWITCH,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	68 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC52
	50,		// doomednum
	S_MEAT2,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	84 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC53
	51,		// doomednum
	S_MEAT3,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	84 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC54
	52,		// doomednum
	S_MEAT4,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	68 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC55
	53,		// doomednum
	S_MEAT5,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	52 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC56
	59,		// doomednum
	S_MEAT2,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	84 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC57
	60,		// doomednum
	S_MEAT4,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	68 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC58
	61,		// doomednum
	S_MEAT3,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	52 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC59
	62,		// doomednum
	S_MEAT5,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	52 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC60
	63,		// doomednum
	S_BLOODYTWITCH,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	68 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC61
	22,		// doomednum
	S_HEAD_DIE6,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC62
	15,		// doomednum
	S_PLAY_DIE7,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC63
	18,		// doomednum
	S_POSS_DIE5,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC64
	21,		// doomednum
	S_SARG_DIE6,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC65
	23,		// doomednum
	S_SKULL_DIE6,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC66
	20,		// doomednum
	S_TROO_DIE5,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC67
	19,		// doomednum
	S_SPOS_DIE5,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC68
	10,		// doomednum
	S_PLAY_XDIE9,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC69
	12,		// doomednum
	S_PLAY_XDIE9,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC70
	28,		// doomednum
	S_HEADSONSTICK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC71
	24,		// doomednum
	S_GIBS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	0,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC72
	27,		// doomednum
	S_HEADONASTICK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC73
	29,		// doomednum
	S_HEADCANDLES,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC74
	25,		// doomednum
	S_DEADSTICK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC75
	26,		// doomednum
	S_LIVESTICK,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC76
	54,		// doomednum
	S_BIGTREE,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	32 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC77
	70,		// doomednum
	S_BBAR1,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC78
	73,		// doomednum
	S_HANGNOGUTS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	88 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC79
	74,		// doomednum
	S_HANGBNOBRAIN,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	88 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC80
	75,		// doomednum
	S_HANGTLOOKDN,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC81
	76,		// doomednum
	S_HANGTSKULL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC82
	77,		// doomednum
	S_HANGTLOOKUP,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC83
	78,		// doomednum
	S_HANGTNOBRAIN,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	16 * FRACUNIT,		// radius
	64 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_SOLID | MF_SPAWNCEILING | MF_NOGRAVITY,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC84
	79,		// doomednum
	S_COLONGIBS,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC85
	80,		// doomednum
	S_SMALLPOOL,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP,		// flags
	S_NULL		// raisestate
	},

	{		// MT_MISC86
	81,		// doomednum
	S_BRAINSTEM,		// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_None,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_None,		// deathsound
	0,		// speed
	20 * FRACUNIT,		// radius
	16 * FRACUNIT,		// height
	100,		// mass
	0,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP,		// flags
	S_NULL		// raisestate
	}
		,

	// For use with wind and current effects
{   // MT_PUSH                       // phares
  5001,           // doomednum       //   |      //jff 5/11/98 deconflict
  S_TNT1,         // spawnstate      //   V      // with DOSDoom        
  1000,           // spawnhealth                              
  S_NULL,         // seestate                                 
  sfx_None,       // seesound                                 
  8,              // reactiontime                             
  sfx_None,       // attacksound                              
  S_NULL,         // painstate                                
  0,              // painchance                               
  sfx_None,       // painsound                                
  S_NULL,         // meleestate                               
  S_NULL,         // missilestate                             
  S_NULL,         // deathstate                               
  S_NULL,         // xdeathstate                              
  sfx_None,       // deathsound                               
  0,              // speed                                    
  8,              // radius                                   
  8,              // height                                   
  10,             // mass                                     
  0,              // damage                                   
  sfx_None,       // activesound                              
  MF_NOBLOCKMAP,  // flags
  S_NULL          // raisestate                                   
},

// For use with wind and current effects
{   // MT_PULL
  5002,           // doomednum                   //jff 5/11/98 deconflict            
  S_TNT1,         // spawnstate                  // with DOSDoom        
  1000,           // spawnhealth                              
  S_NULL,         // seestate                                 
  sfx_None,       // seesound                                 
  8,              // reactiontime                             
  sfx_None,       // attacksound                              
  S_NULL,         // painstate                                
  0,              // painchance                               
  sfx_None,       // painsound                                
  S_NULL,         // meleestate                               
  S_NULL,         // missilestate                             
  S_NULL,         // deathstate                               
  S_NULL,         // xdeathstate                              
  sfx_None,       // deathsound                               
  0,              // speed                                    
  8,              // radius                                   
  8,              // height                                   
  10,             // mass                                     
  0,              // damage                                   
  sfx_None,       // activesound                              
  MF_NOBLOCKMAP,  // flags
  S_NULL          // raisestate                                   
}
};
//std::vector<state_t> tempStates(arrStates, arrStates + NUMSTATES);
std::vector<state_t> origStates(NUMSTATES);
std::vector<mobjinfo_t> origMobjinfo(NUMMOBJTYPES);
bool inited = false;
void init_info() {
	if (!inited) {
		//memcpy(origStates, tempStates, sizeof(tempStates));
		origStates = tempStates;
		origMobjinfo = mobjinfo;
		inited = true;
	}
	if (::g->gamemission == doom) {
		mobjinfo[MT_SKULL].flags |= MF_COUNTKILL;
	}
}



//GK: Reset values just in case dehacked is used
void resetValues() {
	mobjinfo = origMobjinfo;
	
	tempStates = origStates;
}



std::vector<dehcptr> tempcptrval {
	{ "NULL",NULL },
{ "Light0",(actionf_p2)A_Light0 },
{ "WeaponReady",(actionf_p2)A_WeaponReady },
{ "Lower",(actionf_p2)A_Lower },
{ "Raise",(actionf_p2)A_Raise },
{ "Punch",(actionf_p2)A_Punch },
{ "ReFire",(actionf_p2)A_ReFire },
{ "FirePistol",(actionf_p2)A_FirePistol },
{ "Light1",(actionf_p2)A_Light1 },
{ "FireShotgun",(actionf_p2)A_FireShotgun },
{ "Light2",(actionf_p2)A_Light2 },
{ "FireShotgun2",(actionf_p2)A_FireShotgun2 },
{ "CheckReload",(actionf_p2)A_CheckReload },
{ "OpenShotgun2",(actionf_p2)A_OpenShotgun2 },
{ "LoadShotgun2",(actionf_p2)A_LoadShotgun2 },
{ "CloseShotgun2",(actionf_p2)A_CloseShotgun2 },
{ "FireCGun",(actionf_p2)A_FireCGun },
{ "GunFlash",(actionf_p2)A_GunFlash },
{ "FireMissile",(actionf_p2)A_FireMissile },
{ "Saw",(actionf_p2)A_Saw },
{ "FirePlasma",(actionf_p2)A_FirePlasma },
{ "BFGsound",(actionf_p2)A_BFGsound },
{ "FireBFG",(actionf_p2)A_FireBFG },
{ "BFGSpray",(actionf_p2)A_BFGSpray },
{ "Explode",(actionf_p2)A_Explode },
{ "Pain",(actionf_p2)A_Pain },
{ "PlayerScream",(actionf_p2)A_PlayerScream },
{ "Fall",(actionf_p2)A_Fall },
{ "XScream",(actionf_p2)A_XScream },
{ "Look",(actionf_p2)A_Look },
{ "Chase",(actionf_p2)A_Chase },
{ "FaceTarget",(actionf_p2)A_FaceTarget },
{ "PosAttack",(actionf_p2)A_PosAttack },
{ "Scream",(actionf_p2)A_Scream },
{ "VileChase",(actionf_p2)A_VileChase },
{ "VileStart",(actionf_p2)A_VileStart },
{ "VileTarget",(actionf_p2)A_VileTarget },
{ "VileAttack",(actionf_p2)A_VileAttack },
{ "StartFire",(actionf_p2)A_StartFire },
{ "Fire",(actionf_p2)A_Fire },
{ "FireCrackle",(actionf_p2)A_FireCrackle },
{ "Tracer",(actionf_p2)A_Tracer },
{ "SkelWhoosh",(actionf_p2)A_SkelWhoosh },
{ "SkelFist",(actionf_p2)A_SkelFist },
{ "SkelMissile",(actionf_p2)A_SkelMissile },
{ "FatRaise",(actionf_p2)A_FatRaise },
{ "FatAttack1",(actionf_p2)A_FatAttack1 },
{ "FatAttack2",(actionf_p2)A_FatAttack2 },
{ "FatAttack3",(actionf_p2)A_FatAttack3 },
{ "BossDeath",(actionf_p2)A_BossDeath },
{ "CPosAttack",(actionf_p2)A_CPosAttack },
{ "CPosRefire",(actionf_p2)A_CPosRefire },
{ "TroopAttack",(actionf_p2)A_TroopAttack },
{ "SargAttack",(actionf_p2)A_SargAttack },
{ "HeadAttack",(actionf_p2)A_HeadAttack },
{ "BruisAttack",(actionf_p2)A_BruisAttack },
{ "SkullAttack",(actionf_p2)A_SkullAttack },
{ "Metal",(actionf_p2)A_Metal },
{ "SPosAttack",(actionf_p2)A_SPosAttack },
{ "SpidRefire",(actionf_p2)A_SpidRefire },
{ "BabyMetal",(actionf_p2)A_BabyMetal },
{ "BspiAttack",(actionf_p2)A_BspiAttack },
{ "Hoof",(actionf_p2)A_Hoof },
{ "CyberAttack",(actionf_p2)A_CyberAttack },
{ "PainAttack",(actionf_p2)A_PainAttack },
{ "PainDie",(actionf_p2)A_PainDie },
{ "KeenDie",(actionf_p2)A_KeenDie },
{ "BrainPain",(actionf_p2)A_BrainPain },
{ "BrainScream",(actionf_p2)A_BrainScream },
{ "BrainDie",(actionf_p2)A_BrainDie },
{ "BrainAwake",(actionf_p2)A_BrainAwake },
{ "BrainSpit",(actionf_p2)A_BrainSpit },
{ "SpawnSound",(actionf_p2)A_SpawnSound },
{ "SpawnFly",(actionf_p2)A_SpawnFly },
{ "BrainExplode",(actionf_p2)A_BrainExplode },
{ "RandomJump", (actionf_p2)A_RandomJump },
{ "Spawn", (actionf_p2)A_Spawn }
};

void init_cptrs() {
	::g->cptrval = tempcptrval;
	//tempcptrval.clear();
	game->SetupClassicCodePointers();
	::g->cptrvalInitialized = 1;
}

actionf_p2 getFunc(char* func) {
	for (int i = 0; i < ::g->cptrval.size(); i++) {
		if (!idStr::Icmp(func, ::g->cptrval[i].name)) {
			return ::g->cptrval[i].func;
		}
	}
	I_Printf("Code Pointer: %s is not supported.\n", func);
	return NULL;
}