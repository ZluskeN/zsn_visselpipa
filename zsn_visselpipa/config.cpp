#define _ARMA_

class CfgPatches
{
	class zsn_visselpipa
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"ace_common"};
	};
};
class Extended_PostInit_EventHandlers
{
	class zsn_functions
	{
		init = "nul = [] execVM 'zsn_visselpipa\functions\fn_whistleInit.sqf'";
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class ACE_Equipment
			{
				class zsn_blowwhistle
				{
					displayName = "Blow Whistle";
					condition = "'ZSN_Whistle' in (items _player)";
					statement = "[_player] spawn zsn_whistleblow";
					showDisabled = 0;
					exceptions[] = {"isNotInside","isNotSitting"};
					icon = "zsn_visselpipa\blowwhistle.paa";
				};
				class zsn_blastwhistle
				{
					displayName = "Blast Whistle";
					condition = "'ZSN_Whistle' in (items _player)";
					statement = "[_player] spawn zsn_whistleblast";
					showDisabled = 0;
					exceptions[] = {"isNotInside","isNotSitting"};
					icon = "zsn_visselpipa\blowwhistle.paa";
				};
			};
		};
	};
    	class Item_Base_F;
    	class zsn_whistleItem: Item_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Whistle";
		author = "ZluskeN";
        	vehicleClass = "Items";
		class TransportItems
		{
			class ZSN_Whistle
			{
				name = "ZSN_Whistle";
				count = 1;
			};
		};
	};
};
class CfgWeapons
{
	class ACE_ItemCore;
    	class CBA_MiscItem_ItemInfo;
	class ZSN_Whistle: ACE_ItemCore
	{
		scope = 2;
		author = "ZluskeN";
		displayName = "Whistle";
		descriptionShort = "Invented in 1884, the Acme Thunderer and its variations has become the world's best-selling whistle.";
		picture = "\zsn_visselpipa\visselpipa.paa";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass = 1;
		};
	};
};
class CfgSounds
{
	sounds[] = {};
	class zsn_whistledash1
	{
		name = "zsn_whistledash";
		sound[] = {"\zsn_visselpipa\Thunderer580dash.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistledot1
	{
		name = "zsn_whistledot";
		sound[] = {"\zsn_visselpipa\Thunderer580dot.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblow2
	{
		name = "zsn_whistleblow";
		sound[] = {"\zsn_visselpipa\thunderer585.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblow3
	{
		name = "zsn_whistleblow";
		sound[] = {"\zsn_visselpipa\thunderer595.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblow4
	{
		name = "zsn_whistleblow";
		sound[] = {"\zsn_visselpipa\thunderer605.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblast2
	{
		name = "zsn_whistleblast";
		sound[] = {"\zsn_visselpipa\thunderer585blast.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblast3
	{
		name = "zsn_whistleblast";
		sound[] = {"\zsn_visselpipa\thunderer595blast.ogg",1,1,1600};
		titles[] = {};
	};
	class zsn_whistleblast4
	{
		name = "zsn_whistleblast";
		sound[] = {"\zsn_visselpipa\thunderer605blast.ogg",1,1,1600};
		titles[] = {};
	};
};
class CfgFunctions
{
	class ZSN
	{
		class Functions
		{
			class whistleInit
			{
				file = "zsn_visselpipa\functions\fn_whistleInit.sqf";
				postInit = 1;
			};
		};
	};
};